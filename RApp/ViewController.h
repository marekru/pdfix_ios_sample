//
//  ViewController.h
//  RApp
//
//  Created by Marek K on 22/09/2020.
//

#import <UIKit/UIKit.h>
#include <string>
#import "pdfix.h"

@interface ViewController : UIViewController<UIPickerViewDelegate, UIPickerViewDataSource>

@property (weak, nonatomic) IBOutlet UILabel *statusLabel;

@property (weak, nonatomic) IBOutlet UIImageView *imageCanvas;

@property (weak, nonatomic) IBOutlet UIPickerView *pagePicker;

// TODO: destroy these objects in controller destructor
@property Pdfix *pdfix;
@property PdfDoc *pdfDocument;

- (bool)renderDocument:(PdfDoc*)doc forPage:(int)pageNumber;

- (void)initPdfix;

- (void)updateStatusLabel;



@end

