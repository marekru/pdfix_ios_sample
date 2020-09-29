//
//  ViewController.m
//  RApp
//
//  Created by Marek K on 22/09/2020.
//

#import "ViewController.h"

@interface ViewController ()

@end

NSString* ToNSString(const char* Str)
{
  NSString* pString = [NSString stringWithUTF8String:Str];
  return pString;
}

bool Authorize(Pdfix* pdfix) {
  const wchar_t* email = L"info@pdfix.net";
  const wchar_t* key = L"2CVtMoT6aHNtyrhMx";

  PsAccountAuthorization* auth = pdfix->GetAccountAuthorization();
  return auth && auth->Authorize(email, key) && auth->IsAuthorized();
}

@implementation ViewController

- (void)viewDidLoad {
  [super viewDidLoad];
  // Do any additional setup after loading the view.

  // TODO: path to the pdf document you want to show
  const wchar_t* filePath = L"/Users/marekkru/Repos/RApp/RApp/sample.pdf";

  [self initPdfix];
  if (_pdfix) {
    _pdfDocument = _pdfix->OpenDoc(filePath, L"");
  }

  if (_pdfDocument) {
    [self renderDocument:_pdfDocument forPage:0];
  }

  [self updateStatusLabel];

  // TODO:
  _pagePicker.dataSource = self;
  _pagePicker.delegate = self;
}


- (bool)renderDocument:(PdfDoc*)doc forPage:(int)pageNumber {
  assert(_pdfix != nil);

  bool result = false;

  // render first page to jpg image
  PdfPage* page = doc->AcquirePage(pageNumber);
  if (page) {
    double zoom = 1.0; // TODO:
    PdfRotate rotate = PdfRotate::kRotate0;
    PdfPageView* pageView = page->AcquirePageView(zoom, rotate);
    if (pageView) {
      int width = pageView->GetDeviceWidth();
      int height = pageView->GetDeviceHeight();

      //PdfRect clip_box;
      //if (!(clip_rect.left == 0 && clip_rect.right == 0 &&
      //    clip_rect.top == 0 && clip_rect.bottom == 0)) {
      //  width = clip_rect.right - clip_rect.left;
      //  height = clip_rect.bottom - clip_rect.top;
      //  page_view->RectToPage(&clip_rect, &clip_box);
      //}

      PsImage* image = _pdfix->CreateImage(width, height, kImageDIBFormatArgb);
      PsMemoryStream* memStream = _pdfix->CreateMemStream();
      if (image && memStream) {
        PdfRect clipBox;
        PdfPageRenderParams params;
        params.image = image;
        params.clip_box = clipBox;
        pageView->GetDeviceMatrix(&params.matrix);
        params.render_flags = kRenderAnnot;
        if (page->DrawContent(&params, nullptr, nullptr)) {
          PdfImageParams imgParams;
          if (image->SaveToStream(memStream, &imgParams)) {
            int imgSize = memStream->GetSize();
            unsigned char* buffer = new unsigned char[imgSize];
            if (memStream->Read(0, buffer, imgSize)) {
              NSData *data = [NSData dataWithBytesNoCopy:buffer length:imgSize freeWhenDone:YES];
              if (data) {
                _imageCanvas.image = [UIImage imageWithData:data];
                result = true;
              }
            }
          }
        }
        memStream->Destroy();
        image->Destroy();
      }
      pageView->Release();
    }
    page->Release();
  }

  return result;
}

- (void)initPdfix {
  if (!_pdfix) {
    _pdfix = GetPdfix();
    if (_pdfix) {
      Authorize(_pdfix);
    }
  }
}


- (void)updateStatusLabel {

  bool error = false;
  NSString* errorText = @"_";
  if (!_pdfix) {
    errorText = @"Couldn't load PdfixSDK!";
    error = true;
  } else {
    int errType = _pdfix->GetErrorType();
    if (errType != 0) {
      errorText = ToNSString(_pdfix->GetError());
      error = true;
    }
  }

  NSString* statusText = (!error) ? @"Success" : [NSString stringWithFormat:@"ERROR: %@", errorText];

  _statusLabel.text = statusText;
  _statusLabel.textColor = (!error) ? UIColor.systemGreenColor : UIColor.systemRedColor;
}

- (NSInteger)numberOfComponentsInPickerView:(nonnull UIPickerView *)pickerView {
  return 1;
}

- (NSInteger)pickerView:(nonnull UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component {
  if (_pdfDocument) {
    return _pdfDocument->GetNumPages();
  }
  return 0;
}

- (NSString*)pickerView:(UIPickerView *)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component {
  return [NSString stringWithFormat:@"Page %li", (long)row + 1];
}

- (void)pickerView:(UIPickerView *)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component {
  [self renderDocument:_pdfDocument forPage:(int)row];
  [self updateStatusLabel];
}


@end
