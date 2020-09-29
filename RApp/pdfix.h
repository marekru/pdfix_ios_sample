////////////////////////////////////////////////////////////////////////////////////////////////////
// pdfix.h
// Copyright (c) 2016 Pdfix. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////
/*!
*  \brief     Pdfix SDK.
*  \details   Pdfix.
*  \author    pdfix.net
*  \copyright (c) 2016 Pdfix. All Rights Reserved.
*/

#ifndef pdfix_h
#define pdfix_h

/*INSTRUCIONS

@LANG [!JAVA !CSHARP] - exclude object/method for listed
@LANG [JAVA] - exclude object/method for JAVA language - applicable if JAVA is currently excluded
@LANG [] - reset language flag (object/method for all languages)
options: JAVA CSHARP CPP C OBJ-C

@DEFINE_SECTION - marks macro definition section. Ends with another @DEFINE_SECTION mark. 
All macros from inside this section are copied as constants based on the language.

@OBJ_CONSRTUCT <ObjectName> <identification_method>;
object contruct configuration - an identification methods is called on the object to identify
the right class name for when creating object. this is useful in languages which do now allow
direct object handling, but the original object is packed into another object as pointer
(i.e. java, c#)

@API

#if .. #endif
Macro #if conditions are supported to put some macro conditions for whole structure or virtual 
function. The only supported format is (no #else, no #ifdef):
#if <macros>
...
#endif

##START## - begin wathing the code
##END## - end wathing the code 
Any line outside START..END are ignored

=========================
variable types
=========================
int   
c/c++:  int

Name                      | c/c++                 | Java      | c#        |
=========================================================================================
bynary data in            | const uint8_t*, int   | byte[]    |           |
bynary data out           | uint8_t*, int         | byte[]    |           |
utf8 string in            | const char*           | String    | string    |
utf8 string out           | const char*           | String    | string    |

*/

/* Doxygen group definition 
all enums should have defined \ingroup mark
*/

/*! \defgroup Pdfix_PDFix_SDK PDFix SDK
PDFix SDK Object.
*/

/*! \defgroup Pdf_PDFix_SDK Pdf Layer
The Pdf layer is a collection of object methods enabling PDFix SDK users to access and manipulate data in a PDF file.
Many Pdf layer objects are based on PDF objects.
*/

/*! \defgroup Pde_PDFix_SDK Pde Layer
The Pde layer provides easy access to PDF content logical elements.
*/

/*! \defgroup Pds_PDFix_SDK Pds Layer
The Pds layer provides access to the low-level object types used in PDF files.
PDF documents are trees of objects. Objects represent document components such as bookmarks, pages, fonts, and annotations.
*/

/*! \defgroup Ps_PDFix_SDK Ps Layer
The Ps layer provides a variety of utility objects and methods.
*/

/*! \defgroup Config_PDFix_SDK Config
Document template configuration that modifies logical content detection algorithm thresholds.
NOTE: Be careful when you change these thresholds because it can lead to unpredictable results!
*/

/*! \defgroup Enumerations_PDFix_SDK Enumerations
  PDFix SDK enumeration types.
*/

/*! \defgroup Errors_PDFix_SDK Error Codes
  PDFix SDK Error Types.
*/

/*! \defgroup Structures_PDFix_SDK Structures
PDFix SDK structures.
*/

/*! \defgroup Callback_PDFix_SDK Callbacks
PDFix SDK Callbacks.
*/

/*! _out_ macro specifies a parameter that is filled by the method.
it can be one of the following types:
struct - a pointer to structure (e.g. PdfRect), parameter must be last parameter of the method
wchar_t* - a string value, must be followed by int which is length of the string
char* - a utf8 string, must be followed by int which is length of the string
uint8_t* - byte array, must be followed by int which is length of data
*/
#define _out_
#define _in_
#define _callback_

#ifdef _DLL // shared library .dll, .dylib, .so
#define PDFIXEXPORT extern "C"
#else // static library .lib, .a
#define PDFIXEXPORT
#endif

/*##START##*/

// Configuration 
// prefix - the prefix used for definiing exported method. The macro is [PREFIX]EXPORT. 
//          example: PDFIXEXPORT
// name   - module name. The main module identifier. 
// 

/*@CONFIG 
[prefix PDFIX]
[namespace_name PDFixSDK]
[class_name Pdfix]
[package_name net.pdfix.pdfixlib]
[dll_name pdfix]
[exception true]
*/
  
// macro definitions. in case of languages which do not allow macros these
// macros are written as constants (i.e. java, c#)
/*@DEFINE_SECTION*/
#define PDFIX_VERSION_MAJOR 6
#define PDFIX_VERSION_MINOR 1
#define PDFIX_VERSION_PATCH 0
#define MAX_INT 2147483647
#define MIN_INT -2147483647
/*@DEFINE_SECTION*/

/*@OBJ_CONSTRUCT PdeElement GetType PdfElementType;
kPdeText:PdeText;
kPdeTextLine:PdeTextLine;
kPdeWord:PdeWord;
kPdeImage:PdeImage;
kPdeContainer:PdeContainer;
kPdeList:PdeList;
kPdeLine:PdeLine;
kPdeRect:PdeRect;
kPdeHeader:PdeHeader;
kPdeFooter:PdeFooter;
kPdeTable:PdeTable;
kPdeCell:PdeCell;
kPdeFormField:PdeFormField;
kPdeToc:PdeToc;
*/

/*@OBJ_CONSTRUCT PdfAnnot GetSubtype PdfAnnotSubtype;
kAnnotText:PdfTextAnnot;
kAnnotLink:PdfLinkAnnot;
kAnnotFreeText:PdfAnnot;
kAnnotLine:PdfAnnot;
kAnnotSquare:PdfAnnot;
kAnnotCircle:PdfAnnot;
kAnnotPolygon:PdfAnnot;
kAnnotPolyLine:PdfAnnot;
kAnnotHighlight:PdfTextMarkupAnnot;
kAnnotUnderline:PdfTextMarkupAnnot;
kAnnotSquiggly:PdfAnnot;
kAnnotStrikeOut:PdfAnnot;
kAnnotStamp:PdfAnnot;
kAnnotCaret:PdfAnnot;
kAnnotInk:PdfAnnot;
kAnnotPopup:PdfAnnot;
kAnnotFileAttachment:PdfAnnot;
kAnnotSound:PdfAnnot;
kAnnotMovie:PdfAnnot;
kAnnotWidget:PdfWidgetAnnot;
kAnnotScreen:PdfAnnot;
kAnnotPrinterMark:PdfAnnot;
kAnnotTrapNet:PdfAnnot;
kAnnotWatermark:PdfAnnot;
kAnnot3D:PdfAnnot;
kAnnotRedact:PdfAnnot;
*/

/*@OBJ_CONSTRUCT PdsObject GetObjectType PdfObjectType;
 kPdsBoolean:PdsBoolean;
 kPdsNumber:PdsNumber;
 kPdsString:PdsString;
 kPdsName:PdsName;
 kPdsArray:PdsArray;
 kPdsDictionary:PdsDictionary;
 kPdsStream:PdsStream;
 */

/*@OBJ_CONSTRUCT PdsPageObject GetObjectType PdfPageObjectType;
 kPdsPageText:PdsText;
 kPdsPagePath:PdsPath;
 kPdsPageImage:PdsImage;
 kPdsPageShading:PdsShading;
 kPdsPageForm:PdsForm;
 */

////////////////////////////////////////////////////////////////////////////////////////////////////
// Typedefs
////////////////////////////////////////////////////////////////////////////////////////////////////
// all class used in the header file
/*@OBJECT_LIST*/
struct PdeFormField;
struct PdeElement;
struct PdeImage;
struct PdeTable;
struct PdeTextRun;
struct PdeWord;
struct PdeTextLine;
struct PdeText;
struct PdfAction;
struct PdfAnnot;
struct PdfTextAnnot;
struct PdfLinkAnnot;
struct PdfMarkupAnnot;
struct PdfTextMarkupAnnot;
struct PdfWidgetAnnot;
struct PdfDigSig;
struct PdfDoc;
struct PdfAlternate;
struct PdfHtmlAlternate;
struct PdfFont;
struct PdfFormField;
struct PdfPage;
struct PdePageMap;
struct PdfPageView;
struct PdfBookmark;
struct PdfFileSpec;
struct PsRegex;
struct PsImage;
struct PsStream;
struct PdsStructElement;
struct Pdfix;
struct PdfixPlugin;
struct PdsObject;
struct PdsArray;
struct PdsDictionary;
struct PdsName;
struct PdsNumber;
struct PdsBoolean;
struct PdsString;
struct PdsStream;
struct PdfDocPreflight;
struct PsMetadata;
struct PdsStructTree;
struct PdsPageObject;
struct PdsContentMark;
struct PsEvent;
struct PsAuthorization;
struct PsStandardAuthorization;
struct PsAccountAuthorization;
struct PdfViewDestination;
struct PdfNameTree;
struct PdfPagePreflight;
struct PsCommand;
struct PdsPath;
struct PdsPathPoint;
struct PdsImage;
struct PdsShading;
struct PdsText;
struct PdsForm;

/*@OBJECT_LIST*/

////////////////////////////////////////////////////////////////////////////////////////////////////
// Enums
////////////////////////////////////////////////////////////////////////////////////////////////////
typedef int PdfErrorType;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfAuthPlatform
/*! Platform type. */
typedef enum {
  kAuthPlatformWin = 0,         /*!< PDFix WIN. */
  kAuthPlatformMac,             /*!< PDFix MAC platform. */
  kAuthPlatformLinux,           /*!< PDFix Linux platform. */
  kAuthPlatformAndroid,         /*!< PDFix Android platform. */
  kAuthPlatformiOS,             /*!< PDFix iOS platform. */
  kAuthPlatformServer           /*!< PDFix Server. */
} PdfAuthPlatform;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfAuthOption
/*! Authorization option. */
typedef enum {
  kAuthOptionBasic = 0,       /*!< PDFix SDK Basic. */
  kAuthOptionProfessional,    /*!< PDFix SDK Professional. */
  kAuthOptionEnterprise,      /*!< PDFix SDK Enterprise. */
  kAuthOptionDeveloper,       /*!< PDFix SDK Developer. */
  kAuthOptionTrial,           /*!< PDFix SDK Trial. */
} PdfAuthOption;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfEventType
/*! The event type. */
typedef enum {
  kEventUnknown = 0,             /*!< Unknown. */
  kEventDocWillSave,             /*!< A document will be saved. */
  kEventDocWillClose,            /*!< A document will be closed. */
  kEventDocDidOpen,              /*!< A document was opened. */
  kEventDocDidSave,              /*!< A document has been saved. */
  kEventDocWillChangePages,      /*!< Pages will be inserted, deleted, moved, or modified. */
  kEventDocDidChangePages,       /*!< Pages have been inserted, deleted, moved, or modified. */
  kEventDocWillDeletePages,      /*!< One or more pages will be deleted. */
  kEventDocDidDeletePages,       /*!< One or more pages were deleted. */
  kEventDocWillInsertPages,      /*!< One or more pages will be inserted. */
  kEventDocDidInsertPages,       /*!< One or more pages have been inserted. */
  kEventDocWillMovePages,        /*!< One or more pages will be moved. */
  kEventDocDidMovePages,         /*!< One or more pages were moved. */
  kEventDocWillReplacePages,     /*!< One or more pages will be replaced. */
  kEventDocDidReplacePages,      /*!< One or more pages have been replaced. */
  kEventAnnotWillChange,         /*!< An annotation will change in the specified way. */
  kEventAnnotDidChange,          /*!< An annotation changed in the specified way. */
  kEventPageWillAddAnnot,        /*!< An annotation will be added to a page. */
  kEventPageWillRemoveAnnot,     /*!< An annotation will be removed from a page. */
  kEventPageDidAddAnnot,         /*!< An annotation was added to a page. */
  kEventPageDidRemoveAnnot,      /*!< An annotation has been removed from a page. */
  kEventPageContentsDidChange,   /*!< The contents of a page have changed. */
  
} PdfEventType;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfSaveFlags
/*! Flags for PdfDoc::Save flags parameter. */
enum {
  kSaveIncremental = 0x00,      /*!< Save only those portions of the document that have changed. */
  kSaveFull = 0x01,             /*!< Save the entire document. */
  kSaveUncompressed = 0x02,     /*!< Do not compress objects when saving document to make the result compatible with all PDF versions. This flag is ignored if kSaveFull is off.*/
  kSaveCompressedStructureOnly = 0x04,       /*!< Compress only objects, related to logical structure of tagged PDF. Compatible only with PDF 1.5 or later. This flag is ignored if kSaveFull is off.*/
};
typedef int PdfSaveFlags;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfDigSigValidState
/*! Digital signature validate state. */
typedef enum {
  kDigSigBlank = 0,           /*!< Signature field is unsigned. */
  kDigSigUnknown,             /*!< Signature field is signed but not validated. */
  kDigSigInvalid,             /*!< Signature field is signed but failed validation. */
  kDigSigValid,               /*!< Signature field is signed and valid. */
  kDigSigDoubleChecked,       /*!< Signature field is signed and double - checked valid. */
  kDigSigValidStateEnumSize   /*!< A validity state constant for a signature field resulting 
                              from verification. */
} PdfDigSigValidState;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfAlignment
/*! Alignment. */
typedef enum {
  kAlignmentNone = 0,     /*!< No alignment. */
  kAlignmentLeft,         /*!< Top alignment. */
  kAlignmentRight,        /*!< Bottom alignment. */
  kAlignmentJustify,      /*!< Justify alignment. */
  kAlignmentTop,          /*!< Left alignment. */
  kAlignmentBottom,       /*!< Right alignment. */
  kAlignmentCenter,       /*!< Center alignment. */
} PdfAlignment;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfRotate
/*! Specifies page rotation, in degrees. */
typedef enum {
  kRotate0 = 0,           /*!< 0 degrees. */
  kRotate90 = 90,         /*!< 90 degrees. */
  kRotate180 = 180,       /*!< 180 degrees. */
  kRotate270 = 270        /*!< 270 degrees. */
} PdfRotate;

// NOTE: leave enumeration numbers order because they follow pdfium CPDF_Object::Type
/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfObjectType
/*! Specifies PdsObject type. */
typedef enum {
  kPdsUnknown = 0,        /*!< Unknown object. */
  kPdsBoolean = 1,        /*!< Boolean object. */
  kPdsNumber,             /*!< Number object. */
  kPdsString,             /*!< String object. */
  kPdsName,               /*!< Name object. */
  kPdsArray,              /*!< Array object. */
  kPdsDictionary,         /*!< Dictionary object. */
  kPdsStream,             /*!< Stream object. */
  kPdsNull,               /*!< Null object. */
  kPdsReference           /*!< Reference object. */
} PdfObjectType;

// NOTE: leave enumeration numbers order because they follow pdfium CPDF_PageObject::Type
/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfPageObjectType
/*! Specifies PdsPageObject type. */
typedef enum {
  kPdsPageUnknown = 0,        /*!< Unknown object. */
  kPdsPageText = 1,           /*!< Text object. */
  kPdsPagePath,               /*!< Path object. */
  kPdsPageImage,              /*!< Image object. */
  kPdsPageShading,            /*!< Shading object. */
  kPdsPageForm,               /*!< Form object. */
} PdfPageObjectType;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfElementType
/*! Specifies element type. */
typedef enum {
  kPdeUnknown = 0,        /*!< Unknown element. */
  kPdeText,               /*!< PdeText element. */
  kPdeTextLine,           /*!< PdeTextLine element. */
  kPdeWord,               /*!< PdeWord element. */
  kPdeTextRun,            /*!< PdeTextRun element. Not exported yet. */
  kPdeImage,              /*!< PdeImage element. */
  kPdeContainer,          /*!< PdeContainer element. */
  kPdeList,               /*!< PdeList element. */
  kPdeLine,               /*!< PdeLine element. */
  kPdeRect,               /*!< PdeRect element. */
  kPdeTable,              /*!< PdeTable element. */
  kPdeCell,               /*!< PdeCell element. */
  kPdeToc,                /*!< PdeToc element. */
  kPdeFormField,          /*!< PdeFormField element. */
  kPdeHeader,             /*!< PdeHeader element. */
  kPdeFooter,             /*!< PdeFooter element. */
  kPdeAnnot,              /*!< PdeAnnot element. */
} PdfElementType;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfContainerType
/*! Specifies container type. */
typedef enum {
  kPdeContainerUnknown = 0,      /*!< Unknown container. */
  kPdeContainerPage,             /*!< Main page container. */
  kPdeContainerArt,              /*!< Article container. */
  kPdeContainerCol,              /*!< Column container. */
  kPdeContainerRow,              /*!< Row container. */
  kPdeContainerSplitter,         /*!< Splitter divided. */
} PdfContainerType;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfTagType
/*! Specifies tag type. */
typedef enum {
  kTagUnknown = 0,    /*!< Unknown tag. */
  kTagSect,           /*!< Section. */
  kTagArt,            /*!< Article. */
} PdfTagType;

/*! \ingroup Enumerations_PDFix_SDK*/
//! Line Cap Style
/*! The line cap style specifies the shape to be used at the ends of open subpaths (and
dashes, if any) when they are stroked. */
typedef enum {
  kPdfLineCapButt = 0,  /*!< Butt cap. The stroke is squared off at the endpoint of the path. 
                        There is no projection beyond the end of the path. */
  kPdfLineCapRound,     /*!< Round cap. A semicircular arc with a diameter equal to the line 
                        width is drawn around the endpoint and filled in. */
  kPdfLineCapSquare     /*!< Projecting square cap. The stroke continues beyond the endpoint 
                        of the path for a distance equal to half the line width and is squared off. */
} PdfLineCap;

/*! \ingroup Enumerations_PDFix_SDK*/
//! Line Join Style
/*! The line join style specifies the shape to be used at the corners of paths that are
stroked. */
typedef enum {
  kPdfLineJoinMiter = 0, /*!< Miter join. The outer edges of the strokes for the two segments 
                         are extended until they meet at an angle, as in a picture frame. 
                         If the segments meet at too sharp an anglea, a bevel join is used instead. */
  kPdfLineJoinRound,     /*!< Round join. An arc of a circle with a diameter equal to the line width 
                         is drawn around the point where the two segments meet, 
                         connecting the outer edges of the strokes for the two segments. 
                         This pieslice-shaped figure is filled in, producing a rounded corner. */
  kPdfLineJoinBevel,     /*!< . */
} PdfLineJoin;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfFillType
/*! Fill type. */
typedef enum {
  kFillTypeNone = 0,               /*!< Undefined fill type. */
  kFillTypeSolid,                  /*!< Solid fill type. */
  kFillTypePattern                 /*!< Pattern fill type. */
} PdfFillType;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfTextAlignment
/*! Text alignment. */
typedef enum {
  kTextAlignmentNone = 0,          /*!< Undefined alignment. */
  kTextAlignmentLeft,              /*!< Left alignment. */
  kTextAlignmentRight,             /*!< Right alignment. */
  kTextAlignmentCenter,            /*!< Center alignment. */
  kTextAlignmentJustify            /*!< Justify alignment. */
} PdfTextAlignment;

/*! \ingroup Enumerations_PDFix_SDK*/
//! Annotation Types
/*! An annotation associates an object such as a note, sound, or movie with a location
on a page of a PDF document, or provides a way to interact with the user by
means of the mouse and keyboard. PDF includes a wide variety of standard annotation types. */
typedef enum {
  kAnnotUnknown = 0,         /*!< Unknown type. */
  kAnnotText,                /*!< Text annotation. */
  kAnnotLink,                /*!< Link annotation. */
  kAnnotFreeText,            /*!< Free text annotation. */
  kAnnotLine,                /*!< Line annotation. */
  kAnnotSquare,              /*!< Square annotation. */
  kAnnotCircle,              /*!< Circle annotation. */
  kAnnotPolygon,             /*!< Polygon annotation. */
  kAnnotPolyLine,            /*!< Polyline annotation. */
  kAnnotHighlight,           /*!< Highlight annotation. */
  kAnnotUnderline,           /*!< Underline annotation. */
  kAnnotSquiggly,            /*!< Squiggly-underline annotation. */
  kAnnotStrikeOut,           /*!< Strikeout annotation. */
  kAnnotStamp,               /*!< Rubber stamp annotation. */
  kAnnotCaret,               /*!< Caret annotation. */
  kAnnotInk,                 /*!< Ink annotation. */
  kAnnotPopup,               /*!< Pop-up annotation. */
  kAnnotFileAttachment,      /*!< File attachment annotation. */
  kAnnotSound,               /*!< Sound annotation. */
  kAnnotMovie,               /*!< Movie annotation. */
  kAnnotWidget,              /*!< Widget annotation. */
  kAnnotScreen,              /*!< Screen annotation. */
  kAnnotPrinterMark,         /*!< Printer's mark annotation. */
  kAnnotTrapNet,             /*!< Trap network annotation. */
  kAnnotWatermark,           /*!< Watermark annotation. */
  kAnnot3D,                  /*!< 3D annotation. */
  kAnnotRedact               /*!< Redact annotation. */
} PdfAnnotSubtype;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfAnnotFlags
/*! Annotation flags. */
enum {
  kAnnotFlagNone = 0x0000,            /*!< Default value. */
  kAnnotFlagInvisible = 0x0001,       /*!< If there is no annotation handler, the annotation is invisible. */
  kAnnotFlagHidden = 0x0002,          /*!< The annotation is not visible and does not print. */
  kAnnotFlagPrint = 0x0004,           /*!< The annotation prints. */
  kAnnotFlagNoZoom = 0x0008,          /*!< The annotation does not zoom with the view. */
  kAnnotFlagNoRotate = 0x0010,        /*!< The annotation does not rotate with the page. */
  kAnnotFlagNoView = 0x0020,          /*!< The annotation does not view but can print. */
  kAnnotFlagReadOnly = 0x0040,        /*!< The annotation does not interact with the user. */
  kAnnotFlagLocked = 0x0080,          /*!< The annotation does not move or resize with the view. 
                                      Currently only form fields respect this flag. 
                                      If the annotation is locked, the user cannot delete, 
                                      move or change its associated form field's properties. */
  kAnnotFlagToggleNoView = 0x0100,    /*!< A mouse-over or selection causes the kAnnotFlagNoView bit to toggle. */
  kAnnotFlagLockedContents = 0x0200,  /*!< If the annotation is content-locked, the user can not change 
                                      its content key. */
} ;
typedef int PdfAnnotFlags;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfRemoveAnnotFlags
/*! Remove annotation flags. */
enum {
  kRemoveAnnotSingle = 0x0000,        /*!</ Remove only annotation specified by the annotation index. */
  kRemoveAnnotPopup = 0x0001,         /*!</ Remove popup connected to the markup annotation. */
  kRemoveAnnotReply = 0x0002,         /*!</ Remove all replies connected to the markup annotation. */
};
typedef int PdfRemoveAnnotFlags;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfBorderStyle
/*! Border style. */
typedef enum {
  kBorderSolid = 0,                /*!< Solid border. */
  kBorderDashed,                   /*!< Dashed border. */
  kBorderBeveled,                  /*!< Beveled border. */
  kBorderInset,                    /*!< Inset border. */
  kBorderUnderline                 /*!< Underline border. */
} PdfBorderStyle;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfTextStateFlag
/*! Character state. */
enum {
  kTextFlagNone = 0x000,           /*!< No decorations on text. */
  kTextFlagUnderline = 0x001,      /*!< Text is underline. */
  kTextFlagStrikeout = 0x002,      /*!< Text is strikeout. */
  kTextFlagHighlight = 0x004,      /*!< Text is highlight. */
  kTextFlagSubscript = 0x008,      /*!< Is subscript. */
  kTextFlagSuperscript = 0x010,    /*!< Is superscript. */
  kTextFlagNoUnicode = 0x020,      /*!< Text with no unicode representation. */
  kTextFlagPatternFill = 0x040,    /*!< Text is filled with pattern. */
  kTextFlagPatternStroke = 0x080,  /*!< Text is stroked with pattern. */
  kTextFlagWhiteSpace = 0x100,     /*!< Text is whitespace. */
  kTextFlagUnicode = 0x200,        /*!< Text has unicode representation. */
};
typedef int PdfTextStateFlag;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfFieldFlags
/*! Field flags. */
enum {
  kFieldFlagNone = 0x00000000,                   /*!< Ignore. */
  kFieldFlagReadOnly = 0x00000001,               /*!< Read only. */
  kFieldFlagRequired = 0x00000002,               /*!< Required. */
  kFieldFlagNoExport = 0x00000004,               /*!< No export. */
  kFieldFlagMultiline = 0x00001000,              /*!< Multiline. */
  kFieldFlagPassword = 0x00002000,               /*!< Password. */
  kFieldFlagNoToggleToOff = 0x00004000,          /*!< No toggle. */
  kFieldFlagRadio = 0x00008000,                  /*!< Radion. */
  kFieldFlagPushButton = 0x00010000,             /*!< Push button. */
  kFieldFlagCombo = 0x00200000,                  /*!< Combo. */
  kFieldFlagEdit = 0x00400000,                   /*!< Edit. */
  kFieldFlagSort = 0x00800000,                   /*!< Sort. */
  kFieldFlagMultiSelect = 0x00200000,            /*!< Multiselect. */
  kFieldFlagDoNotSpellCheck = 0x00400000,        /*!< No spell check. */
  kFieldFlagDCommitOnSelChange = 0x04000000,     /*!< Flag FileSelect. */
  kFieldFlagFileSelect = 0x00100000,             /*!< Flag ignore. */
  kFieldFlagDoNotScroll = 0x00800000,            /*!< Flag DoNotScroll. */
  kFieldFlagComb = 0x01000000,                   /*!< Flag Comb. */
  kFieldFlagRichText = 0x02000000,               /*!< Flag RichText. */
  kFieldFlagRadiosInUnison = 0x02000000          /*!< Flag adiosInUnison. */
};
typedef int PdfFieldFlags;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfFieldType
/*! Field type. */
typedef enum {
  kFieldUnknown = 0,               /*!< Unknown field. */
  kFieldButton,                    /*!< Button. */
  kFieldRadio,                     /*!< Radio button. */
  kFieldCheck,                     /*!< Check box. */
  kFieldText,                      /*!< Text field. */
  kFieldCombo,                     /*!< Combo box. */
  kFieldList,                      /*!< List. */
  kFieldSignature,                 /*!< Signature. */
} PdfFieldType;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfActionEventType
/*! Event types. */
//order of enum must be the same as order of AActionType
typedef enum {
  kActionEventAnnotEnter = 0,      /*!< An action to be performed when the cursor enters 
                                   the annotation's active area. */
  kActionEventAnnotExit,           /*!< An action to be performed when the cursor exits
                                   the annotation's active area. */
  kActionEventAnnotMouseDown,      /*!< An action to be performed when the mouse button
                                   is pressed inside the annotation's active area. */
  kActionEventAnnotMouseUp,        /*!< An action to be performed when the mouse button
                                   is released inside the annotation's active area. */
  kActionEventAnnotFocus,          /*!< An action to be performed when the annotation
                                   receives the input focus. */
  kActionEventAnnotBlur,           /*!< An action to be performed when the annotation
                                   loses the input focus. */
  kActionEventAnnotPageOpen,       /*!< An action to be performed when the page containing
                                   the annotation is opened (for example, when the user navigates 
                                   to it from the next or previous page or by means of a link 
                                   annotation or outline item). */
  kActionEventAnnotPageClose,      /*!< An action to be performed when the page containing
                                   the annotation is closed (for example, when the user navigates 
                                   to the next or previous page, or follows 
                                   a link annotation or outline item). */
  kActionEventAnnotPageVisible,    /*!< An action to be performed when the page containing
                                   the annotation becomes visible in the viewer 
                                   application's user interface. */
  kActionEventAnnotPageInvisible,  /*!< An action to be performed when the page containing
                                   the annotation is no longer visible in the viewer 
                                   application's user interface. */
  kActionEventPageOpen,            /*!< An action to be performed when the page is opened
                                   (for example, when the user navigates to it from the next or 
                                   previous page or by means of a link annotation or outline item). */
  kActionEventPageClose,           /*!< An action to be performed when the page is closed (for example,
                                   when the user navigates to the next or previous page or 
                                   follows a link annotation or an outline item). */
  kActionEventFieldKeystroke,      /*!< A JavaScript action to be performed when the user types
                                   a keystroke into a text field or combo box or modifies the 
                                   selection in a scrollable list box. This action can check 
                                   the keystroke for validity and reject or modify it. */
  kActionEventFieldFormat,         /*!< A JavaScript action to be performed before the field is
                                   formatted to display its current value. 
                                   This action can modify the field's value before formatting. */
  kActionEventFieldValidate,       /*!< JavaScript action to be performed when the field's value is changed.
                                   This action can check the new value for validity. */
  kActionEventFieldCalculate,      /*!< A JavaScript action to be performed to recalculate the value
                                   of this field when that of another field changes. */
  kActionEventDocWillClose,        /*!< A JavaScript action to be performed before closing a document. */
  kActionEventDocWillSave,         /*!< A JavaScript action to be performed before saving a document. */
  kActionEventDocDidSave,          /*!< A JavaScript action to be performed after saving a document. */
  kActionEventDocWillPrint,        /*!< A JavaScript action to be performed before printing a document. */
  kActionEventDocDidPrint,         /*!< A JavaScript action to be performed after printing a document. */
} PdfActionEventType;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfActionType
/*! Instead of simply jumping to a destination in the document, an annotation or
outline item can specify an action(PDF 1.1) for the viewer application to perform,
such as launching an application, playing a sound, or changing an annotation's
appearance state. */
typedef enum {
  kActionUnknown = 0,         /*!< Unknown action. */
  kActionGoTo,                /*!< Go to a destination in the current document. */
  kActionGoToR,               /*!< ('Go-to remote') Go to a destination in another document. */
  kActionGoToE,               /*!< ('Go-to embedded') Go to a destination in an embedded file. */
  kActionLaunch,              /*!< Launch an application, usually to open a file. */
  kActionThread,              /*!< Begin reading an article thread. */
  kActionURI,                 /*!< Resolve a uniform resource identifier. */
  kActionSound,               /*!< Play a sound. */
  kActionMovie,               /*!< Play a movie. */
  kActionHide,                /*!< Set an annotation's Hidden flag. */
  kActionNamed,               /*!< Execute an action predefined by the viewer application. */
  kActionSubmitForm,          /*!< Send data to a uniform resource locator. */
  kActionResetForm,           /*!< Set fields to their default values. */
  kActionImportData,          /*!< Import field values from a file. */
  kActionJavaScript,          /*!< Execute a JavaScript script. */
  kActionSetOCGState,         /*!< Set the states of optional content groups. */
  kActionRendition,           /*!< Controls the playing of multimedia content. */
  kActionTrans,               /*!< Updates the display of a document, using a transition dictionary. */
  kActionGoTo3DView           /*!< Set the current view of a 3D annotation. */
} PdfActionType;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfRenderFlags
/*! Page rendering flags. */
enum {
  kRenderAnnot = 0x001,			    /*!< Set if annotations are to be rendered. */
  kRenderLCDText = 0x002,		    /*!< Set if using text rendering optimized for LCD display. */
  kRenderNoNativeText = 0x004,	/*!< Don't use the native text output available on some platforms */
  kRenderGrayscale = 0x008,		  /*!< Grayscale output. */
  kRenderLimitedCache = 0x010,  /*!< Limit image cache size. */
  kRenderForceHalftone = 0x020, /*!< Always use halftone for image stretching. */
  kRenderPrinting = 0x040,		  /*!< Render for printing. */
  kRenderNoText = 0x080,	      /*!< Set to disable text rendering. */
  kRenderNoBackground = 0x100   /*!< Set to use transparent background. */
};
typedef int PdfRenderFlags;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfImageFormat
/*! Import/Export image format. */
typedef enum {
  kImageFormatPng = 0,         /*!< *.png */
  kImageFormatJpg,             /*!< *.jpg */
  kImageFormatBmp,             /*!< *.bmp */
  kImageFormatEmf,             /*!< *.emf */
} PdfImageFormat;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfFontFlags
/*! Specifies a various characteristics of the font. */
enum {
  kFontFixedPitch = 0x00001,  /*!< All glyphs have the same width. */
  kFontSerif = 0x00002,       /*!< Glyphs have serifs, which are short strokes drawn at an angle 
                              on the top and bottom of glyph stems.
                              Sans serif fonts do not have serifs. */
  kFontSymbolic = 0x00004,    /*!< Font contains glyphs outside the Adobe standard Latin character set. 
                              This flag and the kFontNotSymbolic flag cannot both be set or both be clear. */
  kFontScript = 0x00008,      /*!< Glyphs resemble cursive handwriting. */
  kFontNotSymbolic = 0x00020, /*!< Font uses the Adobe standard Latin character set or a subset of it. */
  kFontItalic = 0x00040,      /*!< Glyphs have dominant vertical strokes that are slanted. */
  kFontAllCap = 0x10000,      /*!< Font contains no lowercase letters; typically used for display purposes, 
                              such as for titles or headlines. */
  kFontSmallCap = 0x20000,    /*!< Font contains both uppercase and lowercase letters. 
                              The uppercase letters are similar to those in the regular version 
                              of the same typeface family. The glyphs for the lowercase letters 
                              have the same shapes as the corresponding uppercase letters, 
                              but they are sized and their proportions adjusted so that they have the 
                              same size and stroke weight as lowercase glyphs in the same typeface family. */
  kFontForceBold = 0x40000    /*!< The kFontForceBold flag determines whether bold glyphs are painted 
                              with extra pixels even at very small text sizes. */
};
typedef int PdfFontFlags;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfPageContentFlags
/*! Specifies various flags for specific object types in the page content. */
enum {
  kContentImage = 0x00001,      /*!< ImageObject. */
  kContentText = 0x00002,       /*!< Text object. */
  kContentPath = 0x00004,       /*!< Path objects. */
  kContentForm = 0x00008,       /*!< Form object. */
  kContentShading = 0x00020,    /*!< Shading object . */
  kContentTextTransparent = 0x00040,    /*!< Text object with rendering mode 3 - transparent text. */
  kContentTextFill = 0x00080,   /*!< Text object with rendering mode 0, 2 or 4. - fill */
  kContentTextStroke = 0x00100, /*!< Text object with rendering mode 1, 2 or 5. - stroke */
};
typedef int PdfPageContentFlags;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfFontCharset
/*! Supported character sets. */
typedef enum {
  kFontAnsiCharset = 0,           /*!< ANSI Charset. */
  kFontDefaultCharset = 1,        /*!< System Default Charset. */
  kFontSymbolCharset = 2,         /*!< Symbol Charset. */
  kFontUnknownCharset = 3,        /*!< Invalid Charset. */
  kFontMacintoshCharset = 77,     /*!< Macintosh Charset. */
  kFontShiftJISCharset = 128,     /*!< Japanese (Shift-JIS) Charset. */
  kFontHangeulCharset = 129,      /*!< Korean (Hangul, Wansung) Charset. */
  kFontKoreanCharset = 130,       /*!< Korean(Johab) Charset. */
  kFontGB2312Charset = 134,       /*!< Simple Chinese (GB2312) Charset. */
  kFontCHineseBig5Charset = 136,  /*!< Traditinoal Chinese (Big5) Charset. */
  kFontGreekCharset = 161,        /*!< Greek Charset. */
  kFontTurkishCharset = 162,      /*!< Turkish Charset. */
  kFontVietnameseCharset = 163,   /*!< Vietnamese Charset. */
  kFontHebrewCharset = 177,       /*!< Hebrew Charset. */
  kFontArabicCharset = 178,       /*!< Arabic Charset. */
  kFontArabicTCharset = 179,      /*!< Arabic Traditional Charset. */
  kFontArabicUCharset = 180,      /*!< Arabic user Charset. */
  kFontHebrewUCharset = 181,      /*!< Hebrew user Charset. */
  kFontBalticCharset = 186,       /*!< Baltic Charset. */
  kFontRussianCharset = 204,      /*!< Russian Charset. */
  kFontThaiCharset = 222,         /*!< Thai Charset. */
  kFontEastEuropeCharset = 238,   /*!< Eastern European Charset. */
  //254	PC 437 Charset.
  //255	OEM Charset.
} PdfFontCharset;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfPageRangeType
/*! Page range type. */
typedef enum {
  kAllPages = 0,       /*!< All pages. */
  kEvenPagesOnly,      /*!< Even pages. */
  kOddPagesOnly        /*!< Odd pages. */
} PdfPageRangeType;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfFontType
/*! Font types */
typedef enum {
  kFontUnknownType = 0,
  kFontType1,           /*!< A font that defines glyph shapes using Type 1 font technology. */
  kFontTrueType,        /*!< A font based on the TrueType font format. */
  kFontType3,           /*!< A font that defines glyphs with streams of PDF graphics operators. */
  kFontCIDFont          /*!< A CIDFont program contains glyph descriptions that are accessed using 
                        a CID as the character selector. */
} PdfFontType;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfFontFormat
/*! Import/Export font format. */
typedef enum {
  kFontFormatTtf = 0,   /*!< TTF font format*/
  kFontFormatWoff       /*!< WOFF font format */
} PdfFontFormat;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfDestZoomType
/*! Font types */
typedef enum {
  kPdfZoomXYZ = 1,      /*!< Display the page with the coordinates (left, top) positioned
                        at the upper-left corner of the window and the contents of the page
                        magnified by the factor zoom. */
  kPdfZoomFitPage,      /*!< Fit the entire page within the window both horizontally and vertically. */
  kPdfZoomFitHorz,      /*!< Fit the entire width of the page within the window. */
  kPdfZoomFitVert,      /*!< Fit the entire height of the page within the window. */
  kPdfZoomFitRect,      /*!< Fit the rectangle specified by the coordinate. */
  kPdfZoomFitBbox,      /*!< Fit the page content bounding box entirely within the window both 
                        horizontally and vertically. */
  kPdfZoomFitBHorz,     /*!< Fit the entire width of the page content within the window. */
  kPdfZoomFitBVert,     /*!< Fit the entire height of the page content within the window. */
} PdfDestZoomType;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfDigSigType
/*! Digital signature type. */
typedef enum {
  kDigSigOpenSSL,       /*!< Use a pfx file to sign a document. */
  kDigSigCert,          /*!< Use a certificate file to sign a document. */
  kDigSigCustom         /*!< Use callbacks to sign a document. */
} PdfDigSigType;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfImageType
/*! Type of PdeImage. */
typedef enum {
  kImageFigure,         /*!< PdeImage consists of different elements types. */
  kImageImage,          /*!< PdeImage consists of images. */
  kImagePath,           /*!< PdeImage consists of paths. */
  kImageRect,           /*!< PdeImage is a simple rect. */
  kImageShading,        /*!< PdeImage is shading. */
  kImageForm            /*!< PdeImage was created from form xobject. */
} PdfImageType;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfTableType
/*! Type of PdeTable. */
enum {
  kTableUnknown = 0x00,        /*!< Unknown table. */
  kTableGraphic = 0x01,        /*!< Graphic table. */
  kTableIsolated = 0x02,       /*!< Isolated table. */
  kTableIsolatedCol = 0x04,    /*!< Col table. */
  kTableIsolatedRow = 0x08,    /*!< Row table. */
  kTableForm = 0x10,           /*!< Form table. */
  kTableElement = 0x20,        /*!< Element table. */
};
typedef int PdfTableType;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfListType
/*! Type of PdeList. */
typedef enum {
  kListNone,            /*!< No numbering system; Lbl elements(if present) contain arbitrary text not subject to any numbering scheme. */
  kListUnordered,       /*!< Unordered list with unspecified bullets. */
  kListOrdered,         /*!< Ordered Ordered lists with unspecified numbering. */
  kListDecimal,         /*!< Decimal Decimal Arabic numerals(1-9, 10-99, ...) */
  kListRomanUpper,      /*!< UpperRoman Uppercase Roman numerals(I, II, III, IV, ...) */
  kListRomanLower,      /*!< LowerRoman Lowercase Roman numerals(i, ii, iii, iv, ...) */
  kListLetterUpper,     /*!< UpperAlpha Uppercase letters(A, B, C, ...) */
  kListLetterLower,     /*!< LowerAlpha Lowercase letters(a, b, c, ...) */
} PdfListType;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfWordFlags
/*! PdeWord flags. */
enum {
  kWordFlagHyphen = 0x0001,               /*!< Hyphen.*/
  kWordFlagBullet = 0x0002,               /*!< Bullet.*/
  kWordFlagColon = 0x0004,                /*!< Word ends with a colon character.*/
  kWordFlagNumber = 0x008,                /*!< Any number.*/
  kWordFlagSubscript = 0x0010,            /*!< Subscript.*/
  kWordFlagSupercript = 0x0020,           /*!< Superscript.*/
  kWordFlagTerminal = 0x0040,             /*!< Terminal word in a sentence.*/
  kWordFlagFirstCap = 0x0080,             /*!< First char is capital.*/
  kWordFlagImage = 0x00100,               /*!< Image, not text representation.*/
  kWordFlagNumberingDecimal = 0x0200,     /*!< Decimal numbering.*/
  kWordFlagNumberingRoman = 0x0400,       /*!< Roman numbering.*/
  kWordFlagNumberingLetter = 0x0800,      /*!< Letter numbering.*/
  kWordFlagPageNumber = 0x1000,           /*!< Page number e.g roman numeral.*/
  kWordFlagFilling = 0x2000,              /*!< Word is filling..*/
  kWordFlagAllCaps = 0x4000,              /*!< All chars are capitals.*/
  kWordFlagComma = 0x8000,                /*!< Word ends with a comma character.*/
  kWordFlagNoUnicode = 0x10000,           /*!< Word has no unicode representation.*/
  kWordFlagLetter = 0x20000               /*!< Word contains a single letter character.*/
};
typedef int PdfWordFlags;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfTextLineFlags
/*! PdeLine flags. */
enum {
  kTextLineFlagHyphen = 0x0001,          /*!< Hyphen.*/
  kTextLineFlagNewLine = 0x0002,         /*!< New line.*/
  kTextLineFlagIndent = 0x0004,          /*!< Line has indenation. The value is held by the parent text.*/
  kTextLineFlagTerminal = 0x0008,        /*!< Line ended with terminal character.*/
  kTextLineFlagDropCap = 0x0010,         /*!< First char on the line is drop cap.*/
  kTextLineFlagFilling = 0x0020,         /*!< Line is filling only.*/
  kTextLineFlagAllCaps = 0x0040,         /*!< All uppercase.*/
};
typedef int PdfTextLineFlags;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfTextStyle
/*! Style of PdeText. */
typedef enum {
  kTextNormal,      /*!< Text is a main text. */
  kTextH1,          /*!< Text is a header H1. */
  kTextH2,          /*!< Text is a header H2. */
  kTextH3,          /*!< Text is a header H3. */
  kTextH4,          /*!< Text is a header H4. */
  kTextH5,          /*!< Text is a header H5. */
  kTextH6,          /*!< Text is a header H6. */
  kTextH7,          /*!< Text is a header H7. */
  kTextH8,          /*!< Text is a header H8. */
  kTextNote,        /*!< Text is a note. */
  kTextTitle,       /*!< Text is a title. */
} PdfTextStyle;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfTextFlags
/*! PdeText flags. */
enum {
  kTextFlagTableCaption = 0x0001,         /*!< Table caption.*/
  kTextFlagImageCaption = 0x0002,         /*!< Image caption.*/
  kTextFlagChartCaption = 0x0004,         /*!< Chart caption.*/
  kTextFlagNoteCaption = 0x0008,         /*!< Note caption.*/
  kTextFlagFilling = 0x010,               /*!< Text filling only.*/
  kTextFlagAllCaps = 0x020,               /*!< Upercase.*/
};
typedef int PdfTextFlags;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfElementFlags
/*! PdeElement flags. */
enum {
  kElemNoJoin = 0x01,     // don't join with other element, but accept in page map output
  kElemNoSplit = 0x02,    // mark element/text as locked not to split it anymore
  kElemArtifact = 0x04,   // always needs to stay as artifact, e.g underline lines
  kElemHeader = 0x08,     // header
  kElemFooter = 0x10,     // footer
  kElemSplitter = 0x20,   // splitter
  kElemNoTable = 0x40,    // don't add element into table
  kElemTable = 0x80,      // create table from element
};
typedef int PdfElementFlags;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PsFileMode
/*! File access modes used to specify how a file can be used when it is open. */
typedef enum {
  kPsWrite = 0,         /*!< Open the file for writing. */
  kPsReadOnly = 1,      /*!< Open the file for reading. */
  kPsTruncate = 2,      /*!< Truncate file. */
} PsFileMode;
//#define FX_FILEMODE_Write 0 - pdfium
//#define FX_FILEMODE_ReadOnly 1 - pdfium
//#define FX_FILEMODE_Truncate 2 - pdfium

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfAlternateType
/*! Alternate representation. */
typedef enum {
  kAlternatePdf = 0,    /*!< PDF alternate. */
  kAlternateHtml,       /*!< HTML alternate. */
} PdfAlternateType;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfMediaType
/*! An optional media type. */
typedef enum {
  kCSSMediaTypeAll = 0,       /*!< Used for all media type devices. */
  kCSSMediaTypePrint,         /*!< Used for printers. */
  kCSSMediaTypeScreen,        /*!< Used for computer screens, tablets, smart-phones etc.. */
  kCSSMediaTypeSpeech         /*!< Used for screenreaders that "reads" the page out loud. */
} PdfMediaType;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PsImageDIBFormat
/*! Image format type. */
typedef enum {
  kImageDIBFormatArgb = 0x220         /*!< ARGB format. */
} PsImageDIBFormat;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PsDataFormat
/*! Data file format. */
typedef enum {
  kDataFormatJson = 0,     /*!< JSON format. */
  kDataFormatXml,          /*!< XML format. */
  kDataFormatTxt           /*!< TXT format. */
} PsDataFormat;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfStreamType
/*! Specifies stream type. */
typedef enum {
  kFileStream = 0,         /*!< File stream. */
  kMemoryStream,           /*!< Memory stream. */
  kProcStream              /*!< Custom Stream. */
} PdfStreamType;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfStructElementType
/*! Representing the kid�s Type value : Invalid, Element, PageContent, StreamContent, Object. */
typedef enum {
  kPdsStructKidInvalid = 0,    /*!< Invalid type. */
  kPdsStructKidElement,        /*!< Struct element type. */
  kPdsStructKidPageContent,    /*!< Marked content ID type. */
  kPdsStructKidStreamContent,  /*!< Stream content type. */
  kPdsStructKidObject          /*!< Object reference type. */
} PdfStructElementType;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfPageInsertFlags
/*! Flags that determine what additional information is copied while inserting pages. */
enum {
  kPageInsertNone = 0x0000,
  kPageInsertBookmarks = 0x001,   /*!</ Inserts bookmarks as well as pages. The bookmark tree of doc
                                  is merged into the bookmark tree by copying it as a new first-level
                                  subtree of doc's bookmark tree root, of which it becomes the last child.
                                  If current doc has no bookmark tree, it acquires one identical to
                                  the bookmark tree from doc. */
  kPageInsertAll = 0x0002,        /*!</ Inserts document data from pages. */
};
typedef int PdfPageInsertFlags;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfAuthorizationType
/*! Specifies authorization type. */
typedef enum {
  kAuthorizationStandard = 0,     /*!< Standard authorization type. */
  kAuthorizationAccount           /*!< Account-based authorization type. */
} PdfAuthorizationType;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfDestFitType
/*! Specifies the fit type of the designated page into the display. */
typedef enum {
  kDestFitUnknown = 0,            /*!< Unknown fit type. */
  kDestFitXYZ,                    /*!< Fit to the coordinates (left, top) positioned in the top left corner and factor zoom. */
  kDestFit,                       /*!< Fit to page width and height. */
  kDestFitH,                      /*!< Fit to page width. */
  kDestFitV,                      /*!< Fit to page height. */
  kDestFitR,                      /*!< Fit to rectangle. */
  kDestFitB,                      /*!< Fit to page content width and height. */
  kDestFitBH,                     /*!< Fit to page content width. */
  kDestFitBV                      /*!< Fit to page content height. */
} PdfDestFitType;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfLabelType
/*! Label type. */
typedef enum {
  kLabelNo = -1,
  kLabelNone = 0,        /*!< No label. */
  kLabel = 1,            /*!< Label. */
  kLabelLevel1,          /*!< List label on 1th level. */
  kLabelLevel2,          /*!< List label on 2th level. */
  kLabelLevel3,          /*!< List lbel on 3th level. */
  kLabelLevel4,          /*!< List lbel on 4th level. */
} PdfLabelType;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PsCommandStatus
/*! An enumerated list of status codes that can be returned by various PsCommand methods. */
typedef enum {
  kAVCommandReady = 0,   /*!< Not working, but ready to. */
  kAVCommandWorking,     /*!< Still working. */
  kAVCommandDone,        /*!< Done working. */
  kAVCommandCanceled,    /*!< Canceled.. */
  kAVCommandInError,     /*!< In error. */
} PsCommandStatus;

/*! \ingroup Enumerations_PDFix_SDK*/
//! Annotation Appearance Modes
/*! An annotation may define three separate appearances:
- The normal appearance shall be used when the annotation is not interacting with the user.
- The rollover appearance shall be used when the user moves the cursor into the annotation’s area.
- The down appearance shall be used when the mouse button is down within the annotation’s area.
*/
typedef enum {
  kAppearanceNormal = 0,  /*!< Normal annotation appearance. */
  kAppearanceRollover,    /*!< Rollover annotation appearance. */
  kAppearanceDown         /*!< Down annotation appearance. */
} PdfAnnotAppearanceMode;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdsPathPointType
/*! Specifies the type of path point */
typedef enum {
  kPathLineTo = 0,   /*!< (l) Append a straight line segment from the current point to the point (x, y). */
  kPathBezierTo,     /*!< (c) Append a cubic Bézier curve to the current path. */
  kPathMoveTo,       /*!< (m) Begin a new subpath by moving the current point to coordinates (x, y). */
} PdsPathPointType;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfBlendMode
/*! Specifies the blend mode */
typedef enum {
  kBlendModeNormal = 0,   /*!< Selects the source colour, ignoring the backdrop. */
  kBlendModeMultiply,     /*!< Multiplies the backdrop and source colour values. */
  kBlendModeScreen,       /*!< Multiplies the complements of the backdrop and source colour values, then complements the result. */
  kBlendModeOverlay,      /*!< Selects the darker of the backdrop and source colours. */
  kBlendModeDarken,       /*!< Selects the lighter of the backdrop and source colours. */
  kBlendModeLighten,      /*!< Brightens the backdrop colour to reflect the source colour. */
  kBlendModeColorDodge,   /*!< Darkens the backdrop colour to reflect the source colour. */
  kBlendModeColorBurn,    /*!< Multiplies or screens the colours, depending on the source colour value. */
  kBlendModeHardLight,    /*!< Darkens or lightens the colours, depending on the source colour value. */
  kBlendModeSoftLight,    /*!< Multiplies or screens the colours, depending on the backdrop colourvalue. */
  kBlendModeDifference,   /*!< Subtracts the darker of the two constituent colours from the lightercolour. */
  kBlendModeExclusion,    /*!< Produces an effect similar to that of the Difference mode but lower in contrast. */
  kBlendModeHue = 21,     /*!< Creates a colour with the hue of the source colour and the saturation and luminosity of the backdrop colour. */
  kBlendModeSaturation,   /*!< Creates a colour with the saturation of the source colour and the hue and luminosity of the backdrop colour. */
  kBlendModeColor,        /*!< Creates a colour with the hue and saturation of the source colour and the luminosity of the backdrop colour. */
  kBlendModeLuminosity,   /*!< Creates a colour with the luminosity of the source colour and thehue and saturation of the backdrop colour. */
} PdfBlendMode;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdfFillRule
/*! Fill rule for paths. */
typedef enum {
  kFillRuleNone = 0,               /*!< No fill. */
  kFillRuleEvenOdd,                /*!< Fill the path, using the even-odd rule. */
  kFillRuleWinding                 /*!< Fill the path, using the non-zero winding number rule. */
} PdfFillRule;

/*! \ingroup Enumerations_PDFix_SDK*/
//! PdsContentFlags
/*! A bit field for the PDEContent::ToObject method, indicating the type of object to create and how it is created. */
enum {
  kContentToPage = 0x01,          /*!< Create page contents. */
  kContentToForm = 0x02,          /*!< Create form. */
  kContentToCharproc = 0x04       /*!< Create charproc. */
};
typedef int PdsContentFlags;

////////////////////////////////////////////////////////////////////////////////////////////////////
// Structures
////////////////////////////////////////////////////////////////////////////////////////////////////

/*! \ingroup Structures_PDFix_SDK*/
//! PdfPageRangeParams.
/*! Specifies a range of pages in a document. Page numbers begin with 0. */
typedef struct _PdfPageRangeParams {
  int start_page;
  int end_page;
  PdfPageRangeType page_range_spec;
  _PdfPageRangeParams() {
    start_page = 0;               /*!< The starting page number. */
    end_page = -1;                /*!< The ending page number. Set to -1 if it's the last page of 
                                  the document. */
    page_range_spec = kAllPages;  /*!< The pages in the range to print. It must be one of: 
                                  kAllPages, kEvenPagesOnly, or kOddPagesOnly. */
  }
} PdfPageRangeParams;

/*! \ingroup Structures_PDFix_SDK*/
//! PdfWatermarkParams.
/*! Page rendering flags. */
typedef struct _PdfWatermarkParams {
  PdfPageRangeParams page_range;  /*!< The page range of the document to which the watermark should be added. */
  int order_top;                  /*!< An integer specifying where in the page z-order the watermark should be added. 
                                  If it is 1, the watermark is added to the front of the page; 
                                  if it is 0, it is added as a background. */
  PdfAlignment h_align;           /*!< The horizontal alignment to be used when adding the watermark to a page. */
  PdfAlignment v_align;           /*!< The vertical alignment to be used when adding the watermark to a page. */
  int percentage_vals;            /*!< An integer specifying the units of horizValue and vertValue. 
                                  If it is 1, horizValue and vertValue represent percentages of the page dimensions. 
                                  If it is 0, horizValue and vertValue are in user units. */
  double h_value;                 /*!< The horizontal offset value to be used when adding the watermark on a page.
                                  If percentageVals is 1, this value is a percentage of the page width, 
                                  with 1.0 meaning 100 % .
                                  If percentageVals is 0, this value is in user units. */
  double v_value;                 /*!< The vertical offset value to be used when adding the watermark on a page.
                                  If percentageVals is 1, this value is a percentage of the page height, 
                                  with 1.0 meaning 100 % .
                                  If percentageVals is 0, this value is in user units. */
  double scale;                   /*!< The scale factor to be used when adding the watermark, with 1.0 meaning 100%. */
  double rotation;                /*!< The counter-clockwise rotation, in degrees, to be used when adding the watermark. */
  double opacity;                 /*!< The opacity to be used when adding the watermark, 
                                  with 0.0 meaning fully transparent and 1.0 meaning fully opaque. */
  _PdfWatermarkParams() {
    order_top = 1;
    percentage_vals = 0;
    h_align = kAlignmentLeft;
    v_align = kAlignmentTop;
    h_value = 0;
    v_value = 0;
    scale = 1;
    rotation = 0;
    opacity = 1;
  }
} PdfWatermarkParams;

/*! \ingroup Structures_PDFix_SDK*/
//! PdfPoint.
/*! A data structure representing a point in the user space.
To avoid the device-dependent effects of specifying objects in device space, PDF
defines a device-independent coordinate system that always bears the same relationship
to the current page, regardless of the output device on which printing or
displaying occurs. This device-independent coordinate system is called user space.
The origin of the user space(0, 0) represents the bottom-left corner of the PDF page.
PDF files specify 72 points to 1 physical inch. */
typedef struct _PdfPoint {
  double x;          /*!< The x coordinate of the point in user space. */
  double y;          /*!< The y coordinate of the point in user space. */
} PdfPoint;

/*! \ingroup Structures_PDFix_SDK*/
//! PdfDevPoint.
/*! A data structure representing a point in the page view's device space. */
typedef struct _PdfDevPoint {
  int x;             /*!< The x coordinate of the point in device space. */
  int y;             /*!< The y coordinate of the point  in device space. */
} PdfDevPoint;

/*! \ingroup Structures_PDFix_SDK*/
//! PdfRect.
/*! A data structure representing a rectangle in a user space 
(a quadrilateral having only horizontal and vertical sides)
The coordinate system is defined so that (0,0) is at the top, 
x increases to the right, and y increases down. A PdfRect is defined so that 
its top is above its bottom, but this means that 0 < top < bottom. */
typedef struct _PdfRect {
  double left;       /*!< The x-coordinate of the upper-left corner of the rectangle. */
  double top;        /*!< The y-coordinate of the upper-left corner of the rectangle. */
  double right;      /*!< The x-coordinate of the lower-right corner of the rectangle. */
  double bottom;     /*!< The y-coordinate of the lower-right corner of the rectangle. */
  _PdfRect() {
    left = 0.;
    top = 0.;
    right = 0.;
    bottom = 0.;
  }
} PdfRect;

/*! \ingroup Structures_PDFix_SDK*/
//! PdfDevRect.
/*! A data structure representing a rectangle in a device space. */
typedef struct _PdfDevRect {
  int left;          /*!< The x-coordinate of the upper-left corner of the rectangle. */
  int top;           /*!< The y-coordinate of the upper-left corner of the rectangle. */
  int right;         /*!< The x-coordinate of the lower-right corner of the rectangle. */
  int bottom;        /*!< The y-coordinate of the lower-right corner of the rectangle. */
  _PdfDevRect() {
    left = 0;
    top = 0;
    right = 0;
    bottom = 0;
  }
} PdfDevRect;

/*! \ingroup Structures_PDFix_SDK*/
//! PdfQuad.
/*! A quadrilateral represented by four points (one at each corner) in 
user space coordinates. A quadrilateral differs from a rectangle in that a rectangle 
must always have horizontal and vertical sides, and opposite sides must be parallel. */
typedef struct _PdfQuad {
  PdfPoint tl;                    /*!< Top left point. */
  PdfPoint tr;                    /*!< Top right point. */
  PdfPoint bl;                    /*!< Bottom left point. */
  PdfPoint br;                    /*!< Bottom right point. */
} PdfQuad;

/*! \ingroup Structures_PDFix_SDK*/
//! PdfDevQuad.
/*! A quadrilateral represented by four points (one at each corner) in
device space coordinates. A quadrilateral differs from a rectangle in that a rectangle
must always have horizontal and vertical sides, and opposite sides must be parallel. */
typedef struct _PdfDevQuad {
  PdfDevPoint tl;                 /*!< Top left point. */
  PdfDevPoint tr;                 /*!< Top right point. */
  PdfDevPoint bl;                 /*!< Bottom left point. */
  PdfDevPoint br;                 /*!< Bottom right point. */
} PdfDevQuad;

/*! \ingroup Structures_PDFix_SDK*/
//! PdfMatrix
/*! Matrix containing six double numbers. */
typedef struct _PdfMatrix {
  double a;     /*!< a value of the transformation matrix represented as the six-element array [ a b c d e f ]. */
  double b;     /*!< b value of the transformation matrix represented as the six-element array [ a b c d e f ]. */
  double c;     /*!< g value of the transformation matrix represented as the six-element array [ a b c d e f ]. */
  double d;     /*!< d value of the transformation matrix represented as the six-element array [ a b c d e f ]. */
  double e;     /*!< e value of the transformation matrix represented as the six-element array [ a b c d e f ]. */
  double f;     /*!< f value of the transformation matrix represented as the six-element array [ a b c d e f ]. */
  _PdfMatrix() {
    a = 1;
    b = 0;
    c = 0;
    d = 1;
    e = 0;
    f = 0;
  }
} PdfMatrix;

/*! \ingroup Structures_PDFix_SDK*/
//! PdfRGB.
/*! RGB color representation. */
typedef struct _PdfRGB {
  int r;                      /*!< Red component from 0 to 255. */
  int g;                      /*!< Green component from 0 to 255. */
  int b;                      /*!< Blue component from 0 to 255. */
  _PdfRGB() {
    r = 0;
    g = 0;
    b = 0;
  }
  /*##END##*/
  bool operator == (const _PdfRGB& other) const {
    return ((r == other.r) &&
            (g == other.g) &&
            (b == other.b));
  }
  bool operator < (const _PdfRGB& other) const {
    return ((r < other.r) ||
            (g < other.g) ||
            (b < other.b));
  }
  /*##START##*/
} PdfRGB;

/*! \ingroup Structures_PDFix_SDK*/
//! PdfColorState.
/*! Color state. */
typedef struct _PdfColorState {
  PdfFillType fill_type;       /*!< Fill type. */
  PdfFillType stroke_type;     /*!< Stroke type. */
  PdfRGB fill_color;           /*!< Fill color. */
  PdfRGB stroke_color;         /*!< Stroke color. */
  int fill_opacity;            /*!< Fill opacity from 0 to 255. */
  int stroke_opacity;          /*!< Strok opacity from 0 to 255. */
  _PdfColorState() {
    fill_type = kFillTypeNone;
    stroke_type = kFillTypeNone;
    fill_opacity = 255;
    stroke_opacity = 255;
  }  
  /*##END##*/
  bool operator == (const _PdfColorState& other) const { 
    return ((fill_type == other.fill_type) && 
            (stroke_type == other.stroke_type) && 
            (fill_color == other.fill_color) && 
            (stroke_color == other.stroke_color) && 
            (fill_opacity == other.fill_opacity) && 
            (stroke_opacity == other.stroke_opacity)); }
  bool operator < (const _PdfColorState& other) const { 
    return ((fill_type < other.fill_type) ||
            (stroke_type < other.stroke_type) || 
            (fill_color < other.fill_color) || 
            (stroke_color < other.stroke_color) || 
            (fill_opacity < other.fill_opacity) || 
            (stroke_opacity < other.stroke_opacity)); }
  /*##START##*/
} PdfColorState;

/*! \ingroup Structures_PDFix_SDK*/
//! PdfTextState.
/*! PdfTextState structure containing the text state information. */
typedef struct _PdfTextState {
  PdfColorState color_state;    /*!< Fill and stroke color properties. */
  PdfFont* font;                /*!< Text font. */
  double font_size;             /*!< Text font size. */
  double char_spacing;          /*!< Character spacing. */
  double word_spacing;          /*!< Word spacing. */
  PdfTextStateFlag flags;       /*!< Test state flag. */
  _PdfTextState() {
    font = nullptr;
    font_size = 0;
    char_spacing = 0;
    word_spacing = 0;
    flags = 0;
  }
} PdfTextState;

/*! \ingroup Structures_PDFix_SDK*/
//! PdfGraphicState.
/*! Graphics state. */
typedef struct _PdfGraphicState {
  //double dash_phase;
  //int dash_len;
  //double dashes[11];
  PdfColorState color_state;    /*!< Fill and stroke color properties in PdfColorState. */
  double line_width;            /*!< Line width in user space coordinates (PDF). */
  double miter_limit;           /*!< The miter limit. */
  PdfLineCap line_cap;          /*!< The line cap style. */
  PdfLineJoin line_join;        /*!< The line join style. */
  PdfBlendMode blend_mode;
  PdfMatrix matrix;				   
  _PdfGraphicState() {
    line_width = 1;
    miter_limit = 0;
    line_cap = kPdfLineCapButt;
    line_join = kPdfLineJoinMiter;
	blend_mode = kBlendModeNormal;	
  }
} PdfGraphicState;

/*! \ingroup Structures_PDFix_SDK*/
//! PdfFontState.
/*! Font state. */
typedef struct _PdfFontState {
  PdfFontType type;       /*!< Font type. */
  PdfFontFlags flags;     /*!< Font flags. */
  PdfRect bbox;           /*!< Font bounding box. */
  int ascent;             /*!< Ascent. */
  int descent;            /*!< Descent. */
  int italic;             /*!< Italic angle, 0 if horizontal. */
  int bold;               /*!< 1 - true, 0 - false. */
  int fixed_width;        /*!< 1 - true, 0 - false. */
  int vertical;           /*!< 1 - true, 0 - false. */
  int embedded;           /*!< 1 - true, 0 - false. */
  int height;             /*!< Font height. */
  _PdfFontState() {
    type = kFontUnknownType;
    flags = 0;
    ascent = 0;
    descent = 0;
    italic = 0;
    bold = 0;
    fixed_width = 0;
    vertical = 0;
    embedded = 0;
    height = 0;
  }
} PdfFontState;

/*! \ingroup Structures_PDFix_SDK*/
//! PdfPageRenderParams.
/*! Handles page rendering. The page is rendered on either platform device context or an image. 
    If the device context is not null the image parameter is ignored.    
*/
typedef struct _PdfPageRenderParams {
  void* device;                  /*!< Platform dependent device context on which the page should be rendered. (HDC on Windows)*/
  PsImage* image;                /*!< PsImage into which the page will be rendered. */
  PdfMatrix matrix;              /*!< PdfMatrix used to define page rendering scale and rotation. */
  PdfRect clip_box;              /*!< Clipping rectangle in device space coordinates. */
  PdfRenderFlags render_flags;   /*!< PdfRenderFlags */
  _PdfPageRenderParams() {
    device = 0;
    image = nullptr;
    clip_box.left = 0;
    clip_box.right = 0;
    clip_box.top = 0;
    clip_box.bottom = 0;
    render_flags = kRenderAnnot;
  }
} PdfPageRenderParams;

/*! \ingroup Structures_PDFix_SDK*/
//! PdfAnnotAppearance.
/*! Annot appearance. */
typedef struct _PdfAnnotAppearance {
  PdfRGB fill_color;            /*!< The fill color. */
  PdfFillType fill_type;        /*!< The fill type. */
  PdfRGB border_color;          /*!< The border color. */
  double border_width;          /*!< The border width in points. If this value is 0, no border is drawn.
                                Default value: 1. */
  PdfBorderStyle border;        /*!< The border style. */
  double opacity;               /*!< The constant opacity value to be used in painting the annotation. */
  double font_size;             /*!< The default appearance font size to be used in formatting the text. */
  PdfTextAlignment text_align;  /*!< The text alignment. Valid only for Widget annotations. */
  _PdfAnnotAppearance() {
    fill_type = kFillTypeNone;
    border_width = 1;
    border = kBorderSolid;
    opacity = 1;
    font_size = 0;
    text_align = kTextAlignmentLeft;
  }
} PdfAnnotAppearance;

/*! \ingroup Structures_PDFix_SDK*/
//! PdfBookmarkAppearance.
/*! Bookmark appearance. */
typedef struct _PdfBookmarkAppearance {
  PdfRGB color;    /*!< The fill color. */
  int italic;      /*!< 1 - true, 0 - false. */
  int bold;        /*!< 1 - true, 0 - false. */
  _PdfBookmarkAppearance() {
    italic = 0;
    bold = 0;
  }
} PdfBookmarkAppearance;

/*! \ingroup Structures_PDFix_SDK*/
//! PdfWhitespaceParams.
/*! Whitespace Cover parameters. */
typedef struct _PdfWhitespaceParams {
  double width;    /*!< Minimum with of whitespace area on the page. */
  double height;   /*!< Minimum height of whitespace area on the page. */
  _PdfWhitespaceParams() {
    width = 0;
    height = 0;
  }
} PdfWhitespaceParams;

/*! \ingroup Structures_PDFix_SDK*/
//! PdfFlattenAnnotsParams
/*! Flatten annotations params. */
typedef struct _PdfFlattenAnnotsParams {
  PdfPageRangeParams page_range;            /*!< The page range of the document to which flatten annots should apply. */
  PdfAnnotSubtype subtype;                  /*!< Subtype of annotations to flatten. When kAnnotUnknown is used all annotations are flattened and removed. */
  _PdfFlattenAnnotsParams() {
    subtype = kAnnotUnknown;
  }
} PdfFlattenAnnotsParams;

/*! \ingroup Structures_PDFix_SDK*/
//! PdfMediaQueryParams.
/*! Define different style rules for different media types/devices. */
typedef struct _PdfMediaQueryParams {
  PdfMediaType type;         /*!< CSS Media type. */
  int min_width;             /*!< The minimum width of the display area, such as a browser window. */
  _PdfMediaQueryParams() {
    type = kCSSMediaTypeAll;
    min_width = 1200;
  }
} PdfMediaQueryParams;

/*! \ingroup Structures_PDFix_SDK*/
//! PdfImageParams
/*! Define image format and quality. */
typedef struct _PdfImageParams {
  PdfImageFormat format;    /*!< Image format. */
  int quality;              /*!< Image quality. For JPEG format specifies compression level othervise ignored. */
  _PdfImageParams() {
    format = kImageFormatPng;
    quality = 100;
  }
} PdfImageParams;

/*! \ingroup Structures_PDFix_SDK*/
//! PdfAccessibleParams.
/*! Define parameters how to make document accessible. */
typedef struct _PdfAccessibleParams {
  int accept_tags;         /*!< If document already contain tags, use them. */
  int embed_fonts;         /*!< Embed all fonts. */
  int subset_fonts;        /*!< Subset all fonts. */
  int create_bookmarks;    /*!< Create bookmarks from heading structure. */
  _PdfAccessibleParams() {
    accept_tags = 0;
    embed_fonts = 0;
    subset_fonts = 0;
    create_bookmarks = 0;
  }
} PdfAccessibleParams;

/*! \ingroup Structures_PDFix_SDK*/
//! PdsContentParams.
/*! Define parameters that describe PdsCotnent object. */
typedef struct _PdsContentParams {
  PdsContentFlags flags;    /*!< Flags specifying the type of object to create (page contents, form, or charproc) and how it is created. Must be one or more of PdsContentFlags. */
  int form_type;            /*!< Corresponds to the FormType key in the XObject Form attributes dictionary. */
  PdfRect bbox;             /*!< Bounding box of the PDEContent object. Corresponds to the BBox key in the XObject Form attributes dictionary. */
  PdfMatrix matrix;         /*!< Transformation matrix for the PDEContent object. Corresponds to the Matrix key in the XObject Form attributes dictionary. */
  _PdsContentParams() {
    flags = 0;
    form_type = 0;
  }
} PdsContentParams;
////////////////////////////////////////////////////////////////////////////////////////////////////
// Callbacks
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Callback_PDFix_SDK*/
//! PdfCancelProc.
/*!
\param data Pointer to user-supplied data to pass to PdfCancelProc each time it is called.
\return true if process should be cancelled, false otherwise.
*/
typedef _callback_ int (*PdfCancelProc) (void* data);

/*! \ingroup Callback_PDFix_SDK*/
//! PdfEventProc.
/*!
\param data Pointer to user-supplied data to pass to PdfEventProc each time it is called.
\sa Pdfix::RegisterEvent
*/
typedef _callback_ void (*PdfEventProc) (void* data);

/*! \ingroup Callback_PDFix_SDK*/
//! PdfDigestDataProc.
/*!
\param buffer_count
\param buffer_to_sign
\param buffer_size
\param sign_buff (filled by method) If the buffer is null function returns required length of the buffer.
\param sign_buff_size Length of a signed buffer.
\param data Pointer to user-supplied data to pass to PdfDigestDataProc each time it is called.
\return Required lenght.
\sa PdfCustomDigSig::RegisterDigestDataLenProc
*/
/*@LANG [!CSHARP !JAVA]*/
typedef _callback_ unsigned long (*PdfDigestDataProc) (int buffer_count,
  const unsigned char* buffer_to_sign[],
  unsigned long buffer_size[],
  unsigned char* sign_buff,
  unsigned long sign_buff_size,
  void* data);
/*@LANG []*/

/*! \ingroup Callback_PDFix_SDK*/
//! Called by the PsStream object for Read operation.
//! This procedure must return the number of bytes specified by size, 
//! obtaining them in any way it wishes. If your procedure reads data from a file, 
//! it is generally quite inefficient to open the file, read the bytes, 
//! then close the file each time bytes are requested. Instead, consider opening the
//! file the first time bytes are requested from it, reading the entire file 
//! into a secondary buffer, and closing the file.When subsequent requests for data 
//! from the file are received, simply copy data from the secondary buffer, 
//! rather than re - opening the file.
/*!
\param buffer Buffer into which your procedure must place the number 
of bytes specified by size.
\param offset The seek position.
\param size The size of data in bytes.
\param data User-supplied data that was passed.
\return The number of bytes actually read or written.
*/
typedef _callback_ int (*PsStreamReadProc)(uint8_t* buffer, int offset, int size,
  void* data);

/*! \ingroup Callback_PDFix_SDK*/
//! Called by the PsStream object for Write operation.
//! This procedure must return the number of bytes specified by size,
//! obtaining them in any way it wishes. If your procedure reads data from a file,
//! it is generally quite inefficient to open the file, read the bytes,
//! then close the file each time bytes are requested. Instead, consider opening the
//! file the first time bytes are requested from it, reading the entire file
//! into a secondary buffer, and closing the file.When subsequent requests for data
//! from the file are received, simply copy data from the secondary buffer,
//! rather than re - opening the file.
/*!
 \param buffer Buffer which your procedure must place the number
 of bytes specified by size.
 \param offset The seek position.
 \param size The size of data in bytes.
 \param data User-supplied data that was passed.
 \return The number of bytes actually read or written.
 */
typedef _callback_ int (*PsStreamWriteProc)(const uint8_t* buffer, int offset, int size,
                                       void* data);
/*! \ingroup Callback_PDFix_SDK*/
//! Called at end of stream so you can do clean up and free allocated memory.
/*!
\param data User-supplied data that was passed.
*/
typedef _callback_ void (*PsStreamDestroyProc)(void* data);

/*! \ingroup Callback_PDFix_SDK*/
//! This is called to get the length of the stream, 
//! which may be NULL if the stream cannot be set to a new position.
//! PsStreamSeekProc() and PsStreamGetLength() must be provided together.
/*!
\param data User-supplied data that was passed.
\return The size of the stream in bytes.
*/
typedef _callback_ int (*PsStreamGetSizeProc)(void* data);

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdsObject
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pds_PDFix_SDK*/
//!  PdsObject class. 
/*!
A PdsObject is a general object in a PDF file, which may be of any PdsObject object type.
The Object layer provides several methods that are not specific to any particular object. 
*/
struct PdsObject {
  //! Gets the type of an object.
  /*!
  \return Object type, kObjectUnknown otherwise.
  */
  virtual PdfObjectType GetObjectType() = 0;
  
  //! Gets the object number.
  /*!
   \return Object number in orzero in case of a direct object
   */
  virtual int GetId() = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdsBoolean
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pds_PDFix_SDK*/
//!  PdsBoolean class. 
/*!
PdsBoolean objects can have a value of true or false.
*/
struct PdsBoolean : public PdsObject {
  //! Gets the value of the boolean object.
  /*!
  \return The value of the object.
  */
  virtual bool GetValue() = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdsNumber
////////////////////////////////////////////////////////////////////////////////////////////////////
//!  PdsNumber class. 
/*! \ingroup Pds_PDFix_SDK*/
/*!
PdsNumber objects can have any number value.
*/
struct PdsNumber : public PdsObject {

  //! Get information if the object is integer or a number object.
  /*!
  \return true if the object is integer, false othervise.
  */
  virtual bool IsIntegerValue() = 0;

  //! Get the integer value of an object.
  /*!
  \return The integer value of object.
  */
  virtual int GetIntegerValue() = 0;

  //! Gets the value of object as a real number.
  /*!
  \return The numeric value of object.
  */
  virtual double GetValue() = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdsString
////////////////////////////////////////////////////////////////////////////////////////////////////
//!  PdsString class. 
/*! \ingroup Pds_PDFix_SDK*/
/*!
*/
struct PdsString : public PdsObject {
  //! Gets the value of string object, and the string�s length.
  /*!
  \param buffer (filled by method) If the buffer is null function returns required length of string data.
  \param len Length of a buffer to be filled in.
  \return Number of characters written into buffer of required length.
  \sa PdeWord::GetNumChars
  */
  virtual int GetValue(_out_ char* buffer, int len) = 0;

  //! Gets the unicode value of string object
  /*!
   \param buffer (filled by method) If the buffer is null function returns required length of string
   \param len Length of a buffer to be filled in.
   \return Number of characters written into buffer of required length.
  \sa PdeWord::GetValue
  */
  virtual int GetText(_out_ wchar_t* buffer, int len) = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdsName
////////////////////////////////////////////////////////////////////////////////////////////////////
//!  PdsName class. 
/*! \ingroup Pds_PDFix_SDK*/
/*!
*/
struct PdsName : public PdsObject {
  //! Gets the unicode value of name object, and the string�s length.
  /*!
  \param buffer (filled by method) If the buffer is null function returns required length of string data.
  \param len Length of a buffer to be filled in.
  \return Number of characters written into buffer of required length.
  */
  virtual int GetValue(_out_ char* buffer, int len) = 0;

  //! Gets the unicode value of name object
  /*!
   \param buffer (filled by method) If the buffer is null function returns required length of string
   \param len Length of a buffer to be filled in.
   \return Number of characters written into buffer of required length.
   \sa PdeWord::GetValue
   */
  virtual int GetText(_out_ wchar_t* buffer, int len) = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdsArray
////////////////////////////////////////////////////////////////////////////////////////////////////
//!  PdsArray class. 
/*! \ingroup Pds_PDFix_SDK*/
/*!
*/
struct PdsArray : public PdsObject {
  //! Gets the number of objects in the array.
  /*!
  \return Number of objects in the array
  */
  virtual int GetNumObjects() = 0;

  //! Gets the PdsObject from array by index
  /*!
   \param index The index of object to be retrieved.
   \return The object in the array under specified index or null
  */
  virtual PdsObject* Get(int index) = 0;
  
  //! Method puts object to specified position in the array. The array is extended
  //! and null objects are stored in empty slots
  /*!
   \param index The index of a new position of an object.
   \return true if object was added successfully, false othervise
   */
  virtual bool Put(int index, PdsObject* value) = 0;

  //! Method puts number to specified position in the array. The array is extended
  //! and null objects are stored in empty slots
  /*!
   \param index The index of a new position of an object.
   \return true if object was added successfully, false othervise
   */
  virtual bool PutNumber(int index, double value) = 0;

  //! Method puts text to specified position in the array. The array is extended
  //! and null objects are stored in empty slots
  /*!
   \param index The index of a new position of an object.
   \return true if object was added successfully, false othervise
   */
  virtual bool PutName(int index, const wchar_t* value) = 0;

  //! Method inserts object before specified position in the array. If the index is larger
  // then the array length new object is appended and the size of array is increased by 1.
  /*!
   \param index The index of a new position of an object.
   \return true if object was added successfully, false othervise
   */
  virtual bool Insert(int index, PdsObject* value) = 0;
  
  //! Method inserts new dictionary before specified position in the array. If the index is larger
  // then the array length new object is appended and the size of array is increased by 1.
  /*!
   \param index The index of a new position of an dictionary.
   \return The new dictionary or null
   */
  virtual PdsDictionary* InsertDict(int index) = 0;

  //! Method inserts new array before specified position in the array. If the index is larger
  // then the array length new object is appended and the size of array is increased by 1.
  /*!
   \param index The index of a new position of an array.
   \return The new array or null
   */
  virtual PdsArray* InsertArray(int index) = 0;

  //! Method Removes an object from the array.
  /*!
   \param index The index of the object to remove from the Array.
   \return true if object was removed successfully, false othervise
   */
  virtual bool RemoveNth(int index) = 0;

  //! Gets the PdsDictionary object from array by index or null if the objecs does not exist or
  //! it's an object of the different type.
  /*!
   \param index The index of object to be retrieved.
   \return The object in the array under specified index or null
   */
  virtual PdsDictionary* GetDictionary(int index) = 0;

  //! Gets the PdsArray object from array by index or null if the objecs does not exist or
  //! it's an object of the different type.
  /*!
   \param index The index of object to be retrieved.
   \return The object in the array under specified index or null
   */
  virtual PdsArray* GetArray(int index) = 0;

  //! Gets the PdsStream object from array by index or null if the objecs does not exist or
  //! it's an object of the different type.
  /*!
   \param index The index of object to be retrieved.
   \return The object in the array under specified index or null
   */
  virtual PdsStream* GetStream(int index) = 0;

  //! Gets the string value of the PdsString or PdsName object from array by index. Method returns 0
  //! if the objecs does not exist or it's an object of the different type.
  /*!
   \param index The index of object to be retrieved.
   \param buffer (filled by method) If the buffer is null function returns required length of string data.
   \param len Length of a buffer to be filled in.
   \return Number of characters written into buffer of required length.
   */
  virtual int GetString(int index, _out_ char* buffer, int len) = 0;
  
  //! Gets the unicode value of the PdsString or PdsName object from array by index. Method returns 0
  //! if the objecs does not exist or it's an object of the different type.
  /*!
   \param buffer (filled by method) If the buffer is null function returns required length of string
   \param len Length of a buffer to be filled in.
   \return Number of characters written into buffer of required length.
   \sa PdeWord::GetValue
   */
  virtual int GetText(int index, _out_ wchar_t* buffer, int len) = 0;

  //! Gets the float value of the PdsNumber object from array by index. Method returns default value
  //! if the objecs does not exist or it's an object of the different type.
  /*!
   \param index The index of object to be retrieved.
   \return The object in the array under specified index or 0
   */
  virtual double GetNumber(int index) = 0;

  //! Gets the integer value of the PdsNumber object from array by index. Method returns 0
  //! if the objecs does not exist or it's an object of the different type.
  /*!
   \param index The index of object to be retrieved.
   \return The object in the array under specified index or 0
   */
  virtual int GetInteger(int index) = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdsDictionary
////////////////////////////////////////////////////////////////////////////////////////////////////
//!  PdsDictionary class. 
/*! \ingroup Pds_PDFix_SDK*/
/*!
A PdsDictionary is an associative table whose elements are pairs of objects:
- The first element of a pair is the key, which is always a name object, 
a sequence of characters beginning with the forward slash (/) character.
- The second element is the PdsObject representing the value.
*/
struct PdsDictionary : public PdsObject {
  //! Tests whether a specific key is found in the specified dictionary. Calling this method is
  //! equivalent to checking if the value returned from GetObject is a null object.
  /*!
  \param key The key to find.
  \return true if the value of a key is known (exists and is not null) in dict; false otherwise.
  */
  virtual bool Known(const wchar_t* key) = 0;

  //! Gets the number of keys in the dictionary.
  /*!
  \return Number of objects in the dictionary
  */
  virtual int GetNumKeys() = 0;

  //! Gets the key in the dictionary by index.
  /*!
   \param index The index of key whose value is obtained.
   \param buffer (filled by method) If the buffer is null function returns required length of string
   \param len Length of a buffer to be filled in.
   \return Number of characters written into buffer of required length.
  */
  virtual int GetKey(int index, _out_ wchar_t* buffer, int len) = 0;

  //! Gets the value of the specified key in the specified dictionary. 
  /*!
  \param key The key whose value is obtained.
  \return The object associated with the specified key. If key is not present or 
  if its value is null, returns an object of type kPdsNull.
  */
  virtual PdsObject* Get(const wchar_t* key) = 0;
  
  //! Method puts object to specified key in the dictionary.
  /*!
   \param key The name of the key under which the object is stored.
   \return true if object was added successfully, false othervise
   */
  virtual bool Put(const wchar_t* key, PdsObject* value) = 0;

  //! Method puts Boolean to specified key in the dictionary.
  /*!
  \param key The name of the key under which the object is stored.
  \param value boolean.
  \return true if object was added successfully, false othervise
  */
  virtual bool PutBool(const wchar_t* key, bool value) = 0;

  //! Method puts Name to specified key in the dictionary.
  /*!
  \param key The name of the key under which the object is stored.
  \param value Name.
  \return true if object was added successfully, false othervise
  */
  virtual bool PutName(const wchar_t* key, const wchar_t* value) = 0;

  //! Method puts string to specified key in the dictionary.
  /*!
  \param key The name of the key under which the object is stored.
  \param value string.
  \return true if object was added successfully, false othervise
  */
  virtual bool PutString(const wchar_t* key, const wchar_t* value) = 0;

  //! Method puts number to specified key in the dictionary.
  /*!
   \param key The name of the key under which the object is stored.
   \param value Double number.
   \return true if object was added successfully, false othervise
   */
  virtual bool PutNumber(const wchar_t* key, double value) = 0;

  //! Method puts rectangle to specified key in the dictionary.
  /*!
   \param key The name of the key under which the object is stored.
   \param rect Pointer to a rectangle specified in user space coordinates.
   \return true if object was added successfully, false othervise
   */
  virtual bool PutRect(const wchar_t* key, PdfRect* rect) = 0;

  //! Method puts matrix to specified key in the dictionary.
  /*!
   \param key The name of the key under which the object is stored.
   \param matrix Pointer to matrix.
   \return true if object was added successfully, false othervise
   */
  virtual bool PutMatrix(const wchar_t* key, PdfMatrix* matrix) = 0;

  //! Method puts new dictionary to specified key in the dictionary.
  /*!
   \param key The name of the key under which the object is stored.
   \return A newly created dictionary or null.
   */
  virtual PdsDictionary* PutDict(const wchar_t* key) = 0;

  //! Method puts new array to specified key in the dictionary.
  /*!
   \param key The name of the key under which the object is stored.
   \return A newly created array or null.
   */
  virtual PdsArray* PutArray(const wchar_t* key) = 0;

  //! Gets the PdsDictionary object from dictionary by key or null if the objecs does not exist or
  //! it's an object of the different type.
  /*!
   \param key The key under which the object is to be retrieved.
   \return The object in the dictionary under specified key or null
   */
  virtual PdsDictionary* GetDictionary(const wchar_t* key) = 0;
  
  //! Gets the PdsArray object from dictionary by key or null if the objecs does not exist or
  //! it's an object of the different type.
  /*!
   \param key The key under which the object is to be retrieved.
   \return The object in the dictionary under specified key or null
   */
  virtual PdsArray* GetArray(const wchar_t* key) = 0;
  
  //! Gets the PdsStream object from dictionary by key or null if the objecs does not exist or
  //! it's an object of the different type.
  /*!
   \param key The key under which the object is to be retrieved.
   \return The object in the dictionary under specified key or null
   */
  virtual PdsStream* GetStream(const wchar_t* key) = 0;
  
  //! Gets the string value of the PdsString or PdsName object from dictionary by key. Method returns 0
  //! if the objecs does not exist or it's an object of the different type.
  /*!
   \param key The key under which the object is to be retrieved.
   \param buffer (filled by method) If the buffer is null function returns required length of string data.
   \param len Length of a buffer to be filled in.
   \return Number of characters written into buffer of required length.
   */
  virtual int GetString(const wchar_t* key, _out_ char* buffer, int len) = 0;
  
  //! Gets the unicode value of the PdsString or PdsName object from dictionary by key. Method returns 0
  //! if the objecs does not exist or it's an object of the different type.
  /*!
   \param key The key under which the object is to be retrieved.
   \param buffer (filled by method) If the buffer is null function returns required length of string
   \param len Length of a buffer to be filled in.
   \return Number of characters written into buffer of required length.
   \sa PdeWord::GetValue
   */
  virtual int GetText(const wchar_t* key, _out_ wchar_t* buffer, int len) = 0;
  
  //! Gets the float value of the PdsNumber object from dictionary by key. Method returns 0
  //! if the objecs does not exist or it's an object of the different type.
  /*!
   \param key The key under which the object is to be retrieved.
   \return The object in the array under specified key or 0.
   */
  virtual double GetNumber(const wchar_t* key) = 0;
  
  //! Gets the integer value of the PdsNumber object from array by index. Method returns default value
  //! if the objecs does not exist or it's an object of the different type.
  /*!
   \param key The key under which the object is to be retrieved.
   \param default_value The default value to be returned if the value cannot be retrieved
   \return The object in the array under specified index or the default value.
   */
  virtual int GetInteger(const wchar_t* key, int default_value) = 0;
  
  //! Gets the value of PdsBoolean object from array by index. Method returns default value
  //! if the objecs does not exist or it's an object of the different type.
  /*!
   \param key The key under which the object is to be retrieved.
   \param default_value The default value to be returned if the value cannot be retrieved
   \return The object in the array under specified index or the default value
   */
  virtual bool GetBoolean(const wchar_t* key, bool default_value) = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdsStream
////////////////////////////////////////////////////////////////////////////////////////////////////
//!  PdsStream class. 
/*! \ingroup Pds_PDFix_SDK*/
/*!
*/
struct PdsStream : public PdsObject {

  //! Gets the stream dictionary object. 
  /*!
  \return The stream's dictionary
  */
  virtual PdsDictionary* GetStreamDict() = 0;

  //! Gets the stream raw data size. 
  /*!
  \return The stream's dictionary
  */
  virtual int GetRawDataSize() = 0;
  
  //! Checks if the current position is end of stream.
  /*!
   \return The size of the stream.
   \sa PsStream::Read
   */
  virtual bool IsEof() = 0;
  
  //! Gets the current size of a stream.
  /*!
   \return The size of the stream.
   */
  virtual int GetSize() = 0;
  
  //! Reads data from PsStream into memory.
  /*!
   \param buffer (Filled by the method) A buffer into which data is written.
   \param offset The position to start read from.
   \param size The number of bytes to read.
   \return true if the operation was successful, false otherwise.
   */
  virtual bool Read(int offset, _out_ uint8_t* buffer, int size) = 0;
  
  //! Gets the current seek position in a stream.
  //! This is the position at which the next read or write will begin.
  /*!
   \return The current seek position.
   */
  virtual int GetPos() = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdsNull
////////////////////////////////////////////////////////////////////////////////////////////////////
//!  PdsNull class. 
/*! \ingroup Pds_PDFix_SDK*/
/*!
*/
struct PdsNull : public PdsObject {
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdsContent
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pds_PDFix_SDK*/
//!  PdsContent class. 
/*!
The PdsContent object is contains the modifiable contents of a PdfPage.

A PdsContent is a general object in a PDF page content, which may be of any PdsPageObject object
type. The Object layer provides several methods that are not specific to any particular object.
*/
struct PdsContent {

  //! Inserts an object into a PdsContent.
  /*!
  \return true if the operation was successful, false otherwise.
  */
  //virtual bool AddObject(PdsPageObject* object) = 0;

  //! Removes an object from a PdsContent.
  /*!
  \return true if the operation was successful, false otherwise.
  */ 
  //virtual bool RemoveObject(PdsPageObject* object) = 0;

  //! Gets the number of objects.
  /*!
  \return Number of page objects in the content.
  */
  virtual int GetNumObjects() = 0;

  //! Gets the requested page object from a content.
  //! NOTE: This method does not copy the page object.
  /*!
  \param index Index of page object to obtain.
  \return The requested page objects.
  */
  virtual PdsPageObject* GetObject(int index) = 0;

  //virtual PdsPath* AddNewPath() = 0;

  //virtual PdsImage* AddNewImage() = 0;

  //virtual PdsShading* AddNewShading() = 0;

  //virtual PdsText* AddNewText() = 0;

  //virtual PdsForm* AddNewForm() = 0;

  //! This is the main method for converting a PdsContent into PDF contents and resources.
  /*!
  \return PdsStream for the resulting contents in PdsContent.
  */
  //virtual PdsStream* ToObject(PdfDoc* doc, PdsContentParams* content_params) = 0;

  //! Destroys PdsContent resources.
  /*!
  \sa PdfDoc::CreateContent, PdfDoc::CreateFormFromObject
  */
  virtual void Release() = 0;



};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdsPageObject
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pds_PDFix_SDK*/
//!  PdsPageObject class. 
/*!
A PdsPageObject is a general object in a PDF page content, which may be of any PdsPageObject object 
type. The Object layer provides several methods that are not specific to any particular object.
*/
struct PdsPageObject {
  //! Gets the type of an object.
  /*!
  \return Object type, kObjectUnknown otherwise.
  */
  virtual PdfPageObjectType GetObjectType() = 0;

  //! Gets the bounding box for an element in user space coordinates.
  //! To avoid the device-dependent effects of specifying objects in device space, PDF
  //! defines a device-independent coordinate system that always bears the same relationship
  //! to the current page, regardless of the output device on which printing or
  //! displaying occurs. This device-independent coordinate system is called user space.
  //! The origin of the user space(0, 0) represents the bottom-left corner of the PDF page.
  //! PDF files specify 72 points to 1 physical inch.
  //! The returned bounding box is guaranteed to encompass the element. 
  /*!
  \param bbox (Filled by the method) A pointer to a PdfRect structure specifying the bounding
  box of an element, specified in user space coordinates.
  */
  virtual void GetBBox(_out_ PdfRect* bbox) = 0;
  
  //! Gets the ordinal number of a page object.
  /*!
  \return Object identifier.
  */
  virtual int GetId() = 0;
  
  //! Set page object element to draw or not while rendering page content.
  /*!
   \param render True if the object should be rendered. False othervise.
   */
  virtual void SetRender(bool render) = 0;
  
  //! Gets the corresponding struct element object from the document structure tree.
  //! Iterates hierarchy of objects from the structure tree. If there is a reference
  //! to the current page object, a structure element object with this reference is returned.
  /*!
  \param struct_parent If set to true, ParentTree is used in finding the structure element to which the page object belongs.
  \return PdsObject object corresponding to the found structure element, otherwise nullptr.
  \sa PdsStructTree::AcquireStructElement
  */
  virtual PdsObject* GetStructObject(bool struct_parent) = 0;

  //! Gets content mark for this object. It always return a content mark object
  //! even it's empty an has no tags.
  /*!
  \return PdsContentMark object corresponding to this object.
  \sa PdsContentMark::GetNumTags
  */
  virtual PdsContentMark* GetContentMark() = 0;
  
  //! Gets a reference to the page on which the object is present
  /*!
   \return PdfPage object.
   */
  virtual PdfPage* GetPage() = 0;
  
  //! Gets the graphic state of the page object.
  /*!
  \param g_state (filled by method) A pointer to a PdfGraphicState structure specifying
  the graphic state of the page object.
  \return true if the text state was successfully retrieved. false othervise
  */
  virtual bool GetGState(_out_ PdfGraphicState* g_state) = 0;
  //TODO
  //virtual bool SetGState(PdfGraphicState* g_state) = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdsText
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pds_PDFix_SDK*/
//!  PdsText class. 
/*!
A PdsText is a text object in a PDF page content.
*/
struct PdsText : public PdsPageObject {
  //! Gets the text of the page text element.
  /*!
   \param buffer (filled by method) If the buffer is null function returns required length of string
   \param len Length of a buffer to be filled in.
   \return Number of characters written into buffer of required length.
   */
  virtual int GetText(_out_ wchar_t* buffer, int len) = 0;

  //! Gets the text state of the text element.
  /*!
  \param doc reference to a document in which the text thate should be obtained
  \param text_state (filled by method) A pointer to a PdfTextState structure specifying the text
  state of a text object.
  \return true if the text state was successfully retrieved. false othervise
  */
  virtual bool GetTextState(PdfDoc* doc, _out_ PdfTextState* text_state) = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdsForm
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pds_PDFix_SDK*/
//!  PdsForm class. 
/*!
A PdsForm is a form object in a PDF page content.
*/
struct PdsForm : public PdsPageObject {

  //! Gets a PdsContent from the PdsForm object's contents and resources.
  /*!
  \return A PdsContent representing the page's contents.
  this method does increment the reference count of the returned PDEContent.
  */
  virtual PdsContent* AcquireContent() = 0;

};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdsPath
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pds_PDFix_SDK*/
//!  PdsPath class. 
/*!
A PdsPath is a path object in a PDF page content.
*/
struct PdsPath : public PdsPageObject {
	
  //! Gets the number of path points.
  /*!
  \return Number of path points in the path construction.
  */
  virtual int GetNumPathPoints() = 0;

  //! Gets the requested path point.
  /*!
  \param index Index of path point to obtain.
  \return The requested path point.
  */
  virtual PdsPathPoint* GetPathPoint(int index) = 0;

  //virtual bool SetStroke(bool stroke) = 0;

  //virtual bool SetFillType(PdfFillRule fill) = 0;

  //virtual bool MoveTo(PdfPoint* point) = 0;

  //virtual bool LineTo(PdfPoint* point) = 0;

  //virtual bool CurveTo(PdfPoint* control_p_1, PdfPoint* control_p_2, PdfPoint* point) = 0;

  //virtual bool ArcTo(PdfPoint* end_p, PdfPoint* radius_p, double angle, bool is_large, bool sweep) = 0;

  //virtual  bool ClosePath() = 0;

};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdsPathPoint
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pds_PDFix_SDK*/
//!  PdsPathPoint class. 
/*!
A PdsPathPoint is an object that represents one point in PdsPath .
*/
struct PdsPathPoint {

  //! Gets the type of the segment.
  /*!
  \return Type of path segment.
  */
  virtual PdsPathPointType GetType() = 0;

  //! Gets the point.
  /*!
  \return The point.
  */
  virtual bool GetPoint(_out_ PdfPoint* point) = 0;

  //! Returns true if the segment is closed.
  /*!
  \return True if the segment is closed, false otherwise.
  */
  virtual bool IsClosed() = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdsImage
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pds_PDFix_SDK*/
//!  PdsImage class. 
/*!
A PdsImage is a image object in a PDF page content.
*/
struct PdsImage : public PdsPageObject {
	
  //! Gets a data stream for an image.
  /*!
  \return The stream for the image.
  */
  virtual PdsStream* GetDataStm() = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdsShading
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pds_PDFix_SDK*/
//!  PdsShading class. 
/*!
A PdsShading is a text object in a PDF page content.
*/
struct PdsShading : public PdsPageObject {
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdsContentMark
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pds_PDFix_SDK*/
//!  PdsContentMark class.
/*!
A PdsContentMark represents marked content for a page objects. It holds page objects with the same
marked content. Any changes with mark content are applied for each page object from it's container.
*/
struct PdsContentMark {

  //! Gets the number of tags in the marked content.
  /*!
  \return Number of tags in the marked content.
  */
  virtual int GetNumTags() = 0;

  //! Gets the tag name by index.
  /*!
  \param index The index of tag whose value is obtained.
  \param buffer (filled by method) If the buffer is null function returns required length of string
  \param len Length of a buffer to be filled in.
  \return Number of characters written into buffer of required length.
  */
  virtual int GetTagName(int index, _out_ wchar_t* buffer, int len) = 0;

  //! Gets the tag dictionary by index.
  /*!
  \param index The index of tag whose value is obtained.
  \return Tag object if exists, nullptr otherwise.
  */
  virtual PdsDictionary* GetTagObject(int index) = 0;

  //! Gets the marked-content identifier of the marked-content sequence within its content stream.
  /*!
  \return MCID if exists, -1 otherwise.
  */
  virtual int GetTagMcid() = 0;

  //! Returns true if the marked content is an Artifact.
  /*!
  \return True if the marked-content is an artifact, false otherwise.
  */
  virtual bool GetTagArtifact() = 0;
  
  //! Adds a new tag into the marked content.
  //! NOTE: Be carefull when using this method because it can lead to PDF tagged structure failure!
  /*!
  \param name The tag name.
  \param object The dictionary containing the property list or nullptr.
  \param indirect If true, creates the object as an indirect object.
  If false, creates the object as a direct object.
  \return true if tag was added successfully, false otherwise.
  */
  virtual bool AddTag(const char* name, PdsDictionary* object, bool indirect) = 0;
  
  //! Removes the specified tag from the marked content.
  /*!
  \param index The index of the tag to remove.
  */
  virtual bool RemoveTag(int index) = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdeElement
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pde_PDFix_SDK*/
//!  PdeElement class. 
/*!
PdeElement is the base class for elements of a pagemap (PdePageMap).
The general PdeElement methods allow you to get and set general element properties.
PdeElement is an abstract superclass from which the PdeText, PdeTextLine, PdeWord, PdeTable, 
PdeImage, PdeContainer, PdeLine, PdeRect, PdeTableCell, PdeFormField, PdeHeader, PdeFooter classes 
are derived. 
Use PdeElement::GetType method to find the type of an element.
*/
struct PdeElement {
  //! Gets the type of an element.
  /*!
  \return Element type, kElementUnknown otherwise.
  */
  virtual PdfElementType GetType() = 0;

  //! Gets the bounding box for an element in user space coordinates.
  //! To avoid the device-dependent effects of specifying objects in device space, PDF
  //! defines a device-independent coordinate system that always bears the same relationship
  //! to the current page, regardless of the output device on which printing or
  //! displaying occurs. This device-independent coordinate system is called user space.
  //! The origin of the user space(0, 0) represents the bottom-left corner of the PDF page.
  //! PDF files specify 72 points to 1 physical inch.
  //! The returned bounding box is guaranteed to encompass the element. 
  /*!
  \param bbox (Filled by the method) A pointer to a PdfRect structure specifying the bounding
  box of an element, specified in user space coordinates.
  */
  virtual void GetBBox(_out_ PdfRect* bbox) = 0;
  
  //! Gets the bounding box for an element in user space coordinates.
  //! To avoid the device-dependent effects of specifying objects in device space, PDF
  //! defines a device-independent coordinate system that always bears the same relationship
  //! to the current page, regardless of the output device on which printing or
  //! displaying occurs. This device-independent coordinate system is called user space.
  //! The origin of the user space(0, 0) represents the bottom-left corner of the PDF page.
  //! PDF files specify 72 points to 1 physical inch.
  //! The returned bounding box is guaranteed to encompass the element.
  /*!
   \param bbox A pointer to a PdfRect structure specifying the bounding
   box of an element, specified in user space coordinates.
   */
  virtual bool SetBBox(const PdfRect* bbox) = 0;

  //! Gets the id of an element. The id is unique number on a page.
  /*!
  \return Unique number for the element.
  */
  virtual int GetId() = 0;

  //! Gets the graphics state information for an element.
  /*!
  \param g_state (Filled by the method) Pointer to a PdfGraphicState structure that contains
  graphics state information for pdeElement.
  */
  virtual void GetGraphicState(_out_ PdfGraphicState* g_state) = 0;

  //! Gets the number of child elements in an element object.
  /*!
  \return The number of children.
  \sa PdeElement::GetChild
  */
  virtual int GetNumChildren() = 0;

  //! Gets the requested child element from an element.
  /*!
  \param index The index of element to obtain.
  \return Requested element.
  \sa PdeElement::GetNumChildren
  */
  virtual PdeElement* GetChild(int index) = 0;

  //! Gets the element alignment within the content column.
  /*!
  \return Requested element alignment.
  */
  virtual PdfAlignment GetAlignment() = 0;

  //! Gets the element angle.
  /*!
  \return Requested element angle.
  */
  virtual double GetAngle() = 0;

  //! Sets render mode of the element. This mode is used, when element is saved
  /*!
  \param mode Render mode.
  */
  virtual void SetRender(bool render) = 0;
  
  //! Sets user-supplied data to pass to the element.
  /*!
  \param data User-supplied data to pass to element.
  */
  virtual void SetData(void* data) = 0;
  
  //! Gets user-supplied data to pass to the element.
  /*!
  \return User-supplied data from the element.
  */
  virtual void* GetData() = 0;
  
  //! Sets the alternate description of the element.
  /*!
  \param alt The alternate decsription to be set.
  \return true if the description was set, false otherwise.
  */
  virtual bool SetAlt(const wchar_t* alt) = 0;

  //! Sets the actual text of the element.
  /*!
  \param alt The actual text to be set.
  \return true if the actual text was set, false otherwise.
  */
  virtual bool SetActualText(const wchar_t* text) = 0;
  
  //! Get the element state flags
  /*!
   \return the element flags as PdfElementStateFlags.
   */
  virtual int GetFlags() = 0;

  //! Set the element state flags
  /*!
   \param flags the PdfElementFlags flags to be set
   \return true if the element flags was set false othervise
   */
  virtual bool SetFlags(int flags) = 0;
  
  //! Get the the number pf page object in the element
  /*!
   \return The number of page objects.
   */
  virtual int GetNumPageObjects() = 0;

  //! Get the the page object of the element by index
  /*!
   \return The page object.
   */
  virtual PdsPageObject* GetPageObject(int index) = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdeContainer
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pde_PDFix_SDK*/
//!  PdeContainer class. 
/*!
A PdeContainer class is an in-memory representation of objects on a page.
A group of PdeElements on a page in a PDF file. In the PDF file, containers are delimited by Marked
Content pairs. Every PDEContainer has a Marked Content tag associated with it.
*/
struct PdeContainer : public PdeElement {
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdeList
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pde_PDFix_SDK*/
//!  PdeList class. 
/*!
*/
struct PdeList : public PdeElement {
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdeToc
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pde_PDFix_SDK*/
//!  PdeToc class. 
/*!
*/
struct PdeToc : public PdeContainer {
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdeAnnot
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pde_PDFix_SDK*/
//!  PdeAnnot class. 
/*!
A PdeAnnot class is a page content element containing a reference to annotation object.
*/
struct PdeAnnot : public PdeElement {
  //! Gets the annotation object from an annotation element.
  /*!
  \return PdfAnnot object.
  */
  virtual PdfAnnot* GetAnnot() = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdeFormField
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pde_PDFix_SDK*/
//!  PdeFormField class. 
/*!
A PdeFormField class is a page content element containing an interactive form.
*/
struct PdeFormField : public PdeAnnot {
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdeImage
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pde_PDFix_SDK*/
//!  PdeImage class. 
/*!
A PdeImage class is a page content element containing an image graphics.
*/
struct PdeImage : public PdeContainer {
  //! Gets the type of an image.
  /*!
  \return PdfImageType type.
  */
  virtual PdfImageType GetImageType() = 0;

  //! Gets the caption of the image. Iterate it's children if the element is PdeContainer.
  /*!
  \return The caption element.
  */
  virtual PdeElement* GetCaption() = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdeLine
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pde_PDFix_SDK*/
//!  PdeLine class. 
/*!
A PdeLine class is a pagemap element containing a vector graphics in form of a line.
It contains only horizontal and vertical lines.
*/
struct PdeLine : public PdeElement {
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdeRect
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pde_PDFix_SDK*/
//!  PdeRect class. 
/*!
A PdeRect class is a page content element containing a vector graphics with rectangular shape.
*/
struct PdeRect : public PdeContainer {
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdeHeader
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pde_PDFix_SDK*/
//!  PdeHeader class. 
/*!
A PdeHeader class is a page content element that represents a page header
*/
struct PdeHeader : public PdeContainer {
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdeFooter
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pde_PDFix_SDK*/
//!  PdeFooter class. 
/*!
A PdeFooter class is a page content element that represents a page footer
*/
struct PdeFooter : public PdeContainer {
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdeCell
///////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pde_PDFix_SDK*/
//!  PdeCell class. 
/*!
A PdeCell class represents a single cell of PdeTable element.
*/
struct PdeCell : public PdeContainer {
  //! Returns the number of rows spanned by the cell.
  //! The default value is 0, which indicates that this cell is merged.
  //! NOTE: Ignore such cells in further processing.
  /*!
  \return Cell rowspan, 0 if the cell is merged with another cell.
  \sa PdeTable::GetCell
  */
  virtual int GetRowSpan() = 0;

  //! Returns the number of columns spanned by the cell.
  /*!
  \return Cell colspan, 0 if the cell is merged with another cell.
  \sa PdeTable::GetCell
  */
  virtual int GetColSpan() = 0;

  //! Returns true if the border with requested index has a stoke border.
  /*!
  \param index The border index from 0(top) to 3(left).
  \return True if the stroke border exist, false otherwise.
  */
  virtual bool HasBorderGraphicState(int index) = 0;

  //! Returns the parent cell.
  /*!
  \return A requested span parent cell.
  */
  virtual PdeCell* GetSpanCell() = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdeTable
///////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pde_PDFix_SDK*/
//!  PdeTable class. 
/*!
PdeTable class represents tables extracted from PDF document. PdePageMap recognizes and decomposes 
tables in PDF documents and store the extracted data in a PdeTable class for easier reuse.
*/
struct PdeTable : public PdeContainer {
  //! Returns the number of table rows.
  /*!
  \return A number of table rows.
  \sa PdeTable::PdeTableGetNumCols, PdeTable::PdeTableGetCell
  */
  virtual int GetNumRows() = 0;

  //! Returns the number of table columns.
  /*!
  \return A number of table columns.
  \sa PdeTable::PdeTableGetNumRows, PdeTable::PdeTableGetCell
  */
  virtual int GetNumCols() = 0;

  //! Returns the cell object of table columns.
  /*!
  \param row The row number of the requested cell.
  \param col The col number of the requested cell.
  \return A requested cell.
  \sa PdeTable::PdeTableGetNumRows, PdeTable::PdeTableGetNumCols
  */
  virtual PdeCell* GetCell(int row, int col) = 0;

  //! Returns the row alignment.
  /*!
  \param row The row number of the requested cell.
  \return Row alignment.
  */
  virtual PdfAlignment GetRowAlignment(int row) = 0;

  //! Returns the cell alignment.
  /*!
  \param col The col number of the requested cell.
  \return Cell alignment.
  */
  virtual PdfAlignment GetColAlignment(int col) = 0;

  //! Gets the caption of the table. Iterate it's children if the element is PdeContainer.
  /*!
  \return The caption element.
  */
  virtual PdeElement* GetCaption() = 0;

  //! Gets the type of the table.
  /*!
  \return PdfTableType type.
  */
  virtual PdfTableType GetTableType() = 0; 
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdeWord
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pde_PDFix_SDK*/
//!  PdeWord class. 
/*!
A PdeWord object represents a word in a PDF file. Each word contains a sequence of characters in one
or more styles.
*/
struct PdeWord : public PdeElement {
  //! Gets the text of the word element
  /*!
   \param buffer (filled by method) If the buffer is null function returns required length of string
   \param len Length of a buffer to be filled in.
   \return Number of characters written into buffer of required length.
   \sa PdeTextLine::GetText, PdeText::GetText
  */
  virtual int GetText(_out_ wchar_t* buffer, int len) = 0;

  //! Checks whether the text state can be obtained. It means that an each character
  //! of the word has the same text state.
  /*!
  \return true if the text state is the same for the whole word, false otherwise. 
  In that case use PdeWord::GetCharTextState to obtain correct values. 
  \sa PdeWord::GetTextState, PdeWord::GetCharTextState
  */
  virtual bool HasTextState() = 0;

  //! Gets the text state of the word element.
  /*!
  \param text_state (filled by method) A pointer to a PdfTextState structure specifying the text
  state of a word first character.
  \sa PdeWord::HasTextState
  */
  virtual void GetTextState(_out_ PdfTextState* text_state) = 0;

  //! Gets the number of characters in word element.
  /*!
  \return Number of characters.
  */
  virtual int GetNumChars() = 0;

  //! Gets the text of one character of the word.
  /*!
   \param index The index of a character.
   \return Charcode of the characted
   \sa PdeWord::GetNumChars
   \sa PdeWord::GetCharText
   */
  virtual int GetCharCode(int index) = 0;

  //! Gets the text of one character of the word.
  /*!
   \param index The index of a character.
   \param buffer (filled by method) If the buffer is null function returns required length of string
   \param len Length of a buffer to be filled in.
   \return Number of characters written into buffer of required length.
  \sa PdeWord::GetNumChars
  \sa PdeWord::GetCharCode
  */
  virtual int GetCharText(int index, _out_ wchar_t* buffer, int len) = 0;

  //! Gets the text state information of the word character.
  /*!
  \param index The index of a character.
  \param text_state (filled by method) A pointer to a PdfTextState structure specifying the text
  state of a character.
  */
  virtual void GetCharTextState(int index, _out_ PdfTextState* text_state) = 0;

  //! Gets the bounding box of one character in user space coordinates.
  /*!
  \param index The index of a character.
  \param bbox (Filled by the method) A pointer to a PdfRect structure specifying the bounding
  box of a character, specified in user space coordinates.
  */
  virtual void GetCharBBox(int index, _out_ PdfRect* bbox) = 0;
  
  //! Gets the word flags like filling, etc.
  /*!
  \return The combination of PdfWordFlags.
  */
  virtual int GetWordFlags() = 0;

  //! Gets the background element. Iterate it's children to get background images.
  /*!
  \return The background element.
  */
  virtual PdeElement* GetBackground() = 0;

  //! Gets the origin position of the word.
  /*!
  \param point (Filled by the method) An origin position of the word.
  */
  virtual void GetOrigin(_out_ PdfPoint* point) = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdeTextLine
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pde_PDFix_SDK*/
//!  PdeTextLine class. 
/*!
A PdeTextLine object represents a line of text in a PDF file. Each text line contains an array of
PdeWord objects with in one or more styles.
*/
struct PdeTextLine : public PdeElement {
  //! Gets the text of the text line element.
  /*!
   \param buffer (filled by method) If the buffer is null function returns required length of string
   \param len Length of a buffer to be filled in.
   \return Number of characters written into buffer of required length.
  \sa PdeWord::GetText, PdeText::GetText
  */
  virtual int GetText(_out_ wchar_t* buffer, int len) = 0;

  //! Checks whether the text state can be obtained. It means that an each word
  //! of the text line has the same text state.
  /*!
  \return true if the text state is the same for the whole line, false otherwise.
  In that case use PdeWord::GetTextState to obtain correct values.
  \sa PdeTextLine::GetTextState, PdeWord::GetTextState
  */
  virtual bool HasTextState() = 0;

  //! Gets the text state of the text line element.
  /*!
  \param text_state (filled by method) A pointer to a PdfTextState structure specifying the text
  state of a first line character.
  \sa PdeTextLine::HasTextState
  */
  virtual void GetTextState(_out_ PdfTextState* text_state) = 0;

  //! Gets the number of word elements in the text line element.
  /*!
  \return Number of word elements within the text line element.
  */
  virtual int GetNumWords() = 0;

  //! Gets the word element from the text line element.
  /*!
  \param index The index of word element to obtain.
  \return PdeWord element.
  */
  virtual PdeWord* GetWord(int index) = 0;

  //! Gets the text line flags like bullet, list etc.
  /*!
  \return The combination of PdfTextLineFlags.
  */
  virtual int GetTextLineFlags() = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdeText
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pde_PDFix_SDK*/
//!  PdeText class. 
/*!
A PdeText object represents a group of text line objects which forms a paragraph in a PDF file.
*/
struct PdeText : public PdeElement {
  //! Gets the text of the text element.
  /*!
   \param buffer (filled by method) If the buffer is null function returns required length of string
   \param len Length of a buffer to be filled in.
   \return Number of characters written into buffer of required length.
  \sa PdeTextLine::GetText, PdeWord::GetText
  */
  virtual int GetText(_out_ wchar_t* buffer, int len) = 0;

  //! Checks whether the text state can be obtained. It means that an each text line
  //! of the text element has the same text state.
  /*!
  \return true if the text state is the same for the whole text, false otherwise.
  In that case use PdeTextLine::GetTextState to obtain correct values.
  \sa PdeText::GetTextState, PdeTextLine::GetTextState
  */
  virtual bool HasTextState() = 0;

  //! Gets the text state of the text element.
  /*!
  \param text_state (filled by method) A pointer to a PdfTextState structure specifying the text
  state of a first text character.
  \sa PdeText::HasTextState
  */
  virtual void GetTextState(_out_ PdfTextState* text_state) = 0;

  //! Gets the number of lines of text in text element.
  /*!
  \return Number of lines.
  \sa PdeText::GetTextLine
  */
  virtual int GetNumTextLines() = 0;

  //! Gets the text line element from the text element.
  /*!
  \param index The index of line to get.
  \return PdeTextLine element.
  \sa PdeText::GetNumTextLines
  */
  virtual PdeTextLine* GetTextLine(int index) = 0;

  //! Gets the number of words of text in text element.
  /*!
  \return Number of words.
  \sa PdeText::GetWord
  */
  virtual int GetNumWords() = 0;
  
  //! Gets the word from the text element.
  /*!
  \param index The index of word to get.
  \return PdeWord element.
  \sa PdeText::GetNumWords
  */
  virtual PdeWord* GetWord(int index) = 0;

  //! Gets the text element line spacing.
  /*!
  \return The text element line spacing.
  */
  virtual double GetLineSpacing() = 0;

  //! Gets the text element indent.
  /*!
  \return The text element indent.
  */
  virtual double GetIndent() = 0;

  //! Gets the text element type.
  /*!
  \return The text element type.
  */
  virtual PdfTextStyle GetTextStyle() = 0;
  
  //! Gets the text element flags.
  /*!
  \return The text element flags.
  */
  virtual PdfTextFlags GetTextFlags() = 0;
  
  //! Gets the text element label level.
  /*!
  \return The text element label level if exists. Otherwise returns -1.
  */
  virtual int GetLabelLevel() = 0;
  
  //! Sets the text element label level.
  /*!
  \param level Element label level zero based. To remove label flag, set label level to -1.
  \return true if text label level was set, false otherwise.
  */
  virtual bool SetLabelLevel(int level) = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdfAction
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pdf_PDFix_SDK*/
//!  PdfAction class. 
/*!
The PdfAction are tasks that pdf viewer performs when a user clicks on a link or a bookmark.
*/
struct PdfAction {
  //! Gets an action's subtype.
  /*!
  \return The PdfActionType corresponding to the action's subtype.
  */
  virtual PdfActionType GetSubtype() = 0;

  //! Gets the string buffer from the JavaScript action.
  /*!
   \param buffer (filled by method) If the buffer is null function returns required length of string
   \param len Length of a buffer to be filled in.
   \return Number of characters written into buffer of required length.
  */
  virtual int GetJavaScript(_out_ wchar_t* buffer, int len) = 0;

  //! Gets the string buffer from the action representing external resource.
  //! For URI action it's the uniform resource identifier (URI) typically a file that is the destination
  //! of a hypertext link.
  //! For Launch action it's a file specification of the application that shall be launched or the document
  //! that shall beopened or printed.
  //! For GoToE action it's a file specification of an external root document of the source.
  /*!
   \param buffer (filled by method) If the buffer is null function returns required length of string
   \param len Length of a buffer to be filled in.
   \return Number of characters written into buffer of required length.
  */
  virtual int GetDestFile(_out_ wchar_t* buffer, int len) = 0;
  
  //! Gets the view destination of the GoTo or GoToR action. The objects can bee represented by an array
  //! or a string object
  /*!
   \return the view destination.
  */
  virtual PdfViewDestination* GetViewDestination() = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdfAnnot
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pdf_PDFix_SDK*/
//!  PdfAnnot class. 
/*!
An annotation associates an object such as a note, sound, or movie with a location
on a page of a PDF document, or provides a way to interact with the user by
means of the mouse and keyboard.
*/
struct PdfAnnot {
  //! Gets an annotation's subtype.
  /*!
  \return The PdfAnnotSubtype corresponding to the annot's subtype.
  */
  virtual PdfAnnotSubtype GetSubtype() = 0;

  //! Gets an annotation's flags.
  /*!
  \return The flags, or 0 if the annotation does not have a flags key.
  */
  virtual PdfAnnotFlags GetFlags() = 0;

  //! Gets an annotation's appearance
  /*!
  \param appearance (filled by method) Pointer to a PdfAnnotAppearance structure.
  */
  virtual void GetAppearance(_out_ PdfAnnotAppearance* appearance) = 0;

  //! Gets an annotation's appearance stream
  /*!
  \param mode The apearance mode.
  \return PdsStream object corresponding to the appearance stream.
  */
  virtual PdsStream* GetAppearanceXObject(PdfAnnotAppearanceMode mode) = 0;

  //! Set an annotation's appearance from an XObject
  /*!
  \param image_obj Pointer to a image XObject created with PdfDoc::CreateXObjectFromImage.
  \return true is the appearance was successfully set, false otherwise
  \sa PdfDoc::CreateXObjectFromImage
  */
  virtual bool SetAppearanceFromXObject(PdsStream* xobj, PdfAnnotAppearanceMode mode) = 0;

  //! Gets the annotation bounding box.
  /*!
  \param bbox (Filled by the method) Pointer to PdfRect structure to fill.
  */
  virtual void GetBBox(_out_ PdfRect* bbox) = 0;

  //! Tests whether the specified point is within an annotation.
  //! If an annotation consists of more quads, it tests each quad individually.
  /*!
  \param point The point to test.
  \return true if the point is within an annotation, false otherwise.
  */
  virtual bool PointInAnnot(PdfPoint* point) = 0;

  //! Tests whether the specified rect is within an annotation.
  //! If an annotation consists of more quads, it tests each quad individually.
  /*!
  \param rect The rectangle to test.
  \return true if the the whole rectangle is within an annotation, false otherwise.
  */
  virtual bool RectInAnnot(PdfRect* rect) = 0;
  
  //! Gets the corresponding struct element object from the document structure tree.
  //! Iterates hierarchy of objects from the structure tree. If there is a reference
  //! to the current annotation, a structure element object with this reference is returned.
  /*!
  \param struct_parent If set to true, ParentTree is used in finding the structure element to which the annotation belongs.
  \return PdsObject object corresponding to the found structure element, otherwise nullptr.
  \sa PdsStructTree::AcquireStructElement
  */
  virtual PdsObject* GetStructObject(bool struct_parent) = 0;

  //! Gets the annotation object dictionary.
  /*!
  \return an annotation dictionary.
  */
  virtual PdsDictionary* GetObject() = 0;

  //! Broadcasts a PDAnnotWillChange() notification. Clients must call this method before making any change to a custom annotation.
  /*!
  \param key The name of the key in the annotation's dictionary that is changing.
  */
  virtual void NotifyWillChange(const wchar_t* key) = 0;
  
  //! Broadcasts a PDAnnotDidChange() notification. Clients must call this method after making any change to a custom annotation.
  /*!
  \param key The name of the key in the annotation's dictionary that is changing.
  \param err An error code to pass to any method registered to receive the PDAnnotDidChange() notification. 
             Pass zero if the annotation was changed successfully. 
             Pass a nonzero value if an error occurred while changing the annotation.
  */
  virtual void NotifyDidChange(const wchar_t* key, int err) = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdfLinkAnnot
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pdf_PDFix_SDK*/
//!  PdfLinkAnnot class. 
/*!
A link annotation represents either a hypertext link to a destination elsewhere in
the document or an action to be performed.
*/
struct PdfLinkAnnot : public PdfAnnot {
  //! Gets the number of quads for the link.
  /*!
  \return Number of quads.
  \sa PdfLinkAnnot::GetQuad
  */
  virtual int GetNumQuads() = 0;

  //! Gets the requested quad.
  //! The coordinates of the quadrilaterals are in default user space that comprise the region 
  //! in which the link should be activated.
  /*!
  \param index Index of an link quad to retrieve.
  \param quad (Filled by the method) Pointer to PdfQuad structure to fill.
  \sa PdfLinkAnnot::GetNumQuads
  */
  virtual void GetQuad(int index, _out_ PdfQuad* quad) = 0;

  //! Adds a new quad to the link annot.
  /*!
  \param quad Pointer to PdfQuad to add.
  \return true if quad was added sucessfully, false otherwise.
  \sa PdfLinkAnnot::GetNumQuads
  */
  virtual bool AddQuad(PdfQuad* quad) = 0;

  //! Removes a quad with the specified index.
  /*!
  \param index The index of the quad to remove.
  \return true if quad was removed, false otherwise.
  \sa PdfLinkAnnot::GetNumQuads
  */
  virtual bool RemoveQuad(int index) = 0;

  //! Gets an link's action object.
  /*!
  \return The link's action object or nullptr if link does not have an action.
  */
  virtual PdfAction* GetAction() = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdfMarkupAnnot
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pdf_PDFix_SDK*/
//!  PdfMarkupAnnot class. 
/*!
Markup annotations represent a markup annotation in a pdf document.
*/
struct PdfMarkupAnnot : public PdfAnnot {
  //! Gets the contents of the markup annotation.
  //! It's a text to be displayed for the annotation or, if this type of annotation
  //! does not display text, an alternate description of the annotation's contents
  //! in human - readable form. In either case, this text is useful when
  //! extracting the document's contents in support of accessibility to users with
  //! disabilities or for other purposes.
  /*!
   \param buffer (filled by method) If the buffer is null function returns required length of string
   \param len Length of a buffer to be filled in.
   \return Number of characters written into buffer of required length.
  \sa PdfMarkupAnnot::GetContents
  */
  virtual int GetContents(_out_ wchar_t* buffer, int len) = 0;

  //! Sets the contents of the markup annotation.
  //! It's a text to be displayed for the annotation or, if this type of annotation
  //! does not display text, an alternate description of the annotation's contents
  //! in human - readable form. In either case, this text is useful when
  //! extracting the document's contents in support of accessibility to users with
  //! disabilities or for other purposes.
  /*!
  \param contens The content string to be set.
  \return true if the content was set, false otherwise.
  \sa PdfMarkupAnnot::SetContents
  */
  virtual bool SetContents(const wchar_t* contents) = 0;

  //! Gets the author of the markup annotation.
  /*!
   \param buffer (filled by method) If the buffer is null function returns required length of string
   \param len Length of a buffer to be filled in.
   \return Number of characters written into buffer of required length.
  \sa PdfMarkupAnnot::GetAuthor
  */
  virtual int GetAuthor(_out_ wchar_t* buffer, int len) = 0;

  //! Sets the author of the markup annotation.
  /*!
  \param author The content string to be set.
  \return true if the author was set, false otherwise.
  \sa PdfMarkupAnnot::SetAuthor
  */
  virtual bool SetAuthor(const wchar_t* author) = 0;

  //! Gets the requested reply.
  //! Reply is a reference to another PdfAnnot object that was created 
  // as a reply to the current annotation.
  //! Both annotations must be on the same page of the document.
  /*!
  \return Number of replies.
  \sa PdfMarkupAnnot::GetNumReplies
  */
  virtual int GetNumReplies() = 0;

  //! Gets the requested reply.
  //! Reply is a reference to another PdfAnnot object that was created 
  // as a reply to the current annotation.
  //! Both annotations must be on the same page of the document.
  /*!
  \return Requested PdfAnnot that is reply to the current annotation.
  \sa PdfMarkupAnnot::GetReply
  */
  virtual PdfAnnot* GetReply(int index) = 0;

  //! Adds a new reply to the markup annotation.
  /*!
  \param author The author of the reply.
  \param text The content of the reply to add.
  \return Requested PdfAnnot that is reply to the current annotation or nullptr in case of error.
  \sa PdfMarkupAnnot::AddReply
  \ref\n Sample AddComment
  */
  virtual PdfAnnot* AddReply(const wchar_t* author, const wchar_t* text) = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdfTextAnnot
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pdf_PDFix_SDK*/
//!  PdfTextAnnot class. 
/*!
A text annotation represents a 'sticky note' attached to a point in the PDF document.
When closed, the annotation appears as an icon; when open, it displays a
pop-up window containing the text of the note in a font and size chosen by the
viewer application. Text annotations do not scale and rotate with the page.
*/
struct PdfTextAnnot : public PdfMarkupAnnot {
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdfTextMarkupAnnot
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pdf_PDFix_SDK*/
//!  PdfTextMarkupAnnot class. 
/*! 
Text markup annotations appear as highlights, underlines, strikeouts, or jagged ('squiggly') 
underlines in the text of a document.
*/
struct PdfTextMarkupAnnot : public PdfMarkupAnnot {
  //! Gets the number of quads for the annotation.
  /*!
  \return Number of quads.
  \sa PdfTextMarkupAnnot::GetQuad
  */
  virtual int GetNumQuads() = 0;

  //! Gets the requested quad.
  //! The coordinates of the quadrilaterals are in default user space that comprise the region 
  //! in which the annotation should be activated.
  /*!
  \param index Index of an annotation quad to retrieve.
  \param quad (Filled by the method) Pointer to PdfQuad structure to fill.
  \sa PdfTextMarkupAnnot::GetNumQuads
  */
  virtual void GetQuad(int index, _out_ PdfQuad* quad) = 0;

  //! Adds a new quad to the text markup annot.
  /*!
  \param quad Pointer to PdfQuad to add.
  \return true if quad was added sucessfully, false otherwise.
  \sa PdfTextMarkupAnnot::GetNumQuads
  */
  virtual bool AddQuad(PdfQuad* quad) = 0;

  //! Removes a quad with the specified index.
  /*!
  \param index The index of the quad to remove.
  \return true if quad was removed, false otherwise.
  \sa PdfTextMarkupAnnot::GetNumQuads
  */
  virtual bool RemoveQuad(int index) = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdfWidgetAnnot
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pdf_PDFix_SDK*/
//!  PdfWidgetAnnot class. 
/*!
Interactive forms use widget annotations to represent the appearance of fields and 
to manage user interactions.
*/
struct PdfWidgetAnnot : public PdfAnnot {
  //! Gets an annotation's caption.
  /*!
   \param buffer (filled by method) If the buffer is null function returns required length of string
   \param len Length of a buffer to be filled in.
   \return Number of characters written into buffer of required length.
  */
  virtual int GetCaption(_out_ wchar_t* buffer, int len) = 0;

  //! Gets an annotation's font name used for the annotation's appearance.
  /*!
   \param buffer (filled by method) If the buffer is null function returns required length of string
   \param len Length of a buffer to be filled in.
   \return Number of characters written into buffer of required length.
  */
  virtual int GetFontName(_out_ wchar_t* buffer, int len) = 0;

  //! Gets an annotation's action object.
  /*!
  \return The annotation's action object or nullptr if annotation does not have an action.
  \sa PdfWidgetAnnot::GetAAction
  */
  virtual PdfAction* GetAction() = 0;

  //! Gets an annotation's additional action object.
  /*!
  \param event The eventwhich additional action to get.
  \return The annotation's additional action object or nullptr if annotation does
  not have an action for specified event type.
  \sa PdfWidgetAnnot::GetAction
  */
  virtual PdfAction* GetAAction(PdfActionEventType event) = 0;

  //! Gets a PdfFormField object related to the annotation. Valid only for Widget annotation.
  /*!
  \return The PdfFormField object or nullptr if no such form field field object exists.
  */
  virtual PdfFormField* GetFormField() = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdfViewDestination
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pdf_PDFix_SDK*/
//!  PdfViewDestination class.
/*!
A PdfViewDestination represents a particular view of a page in a document. It contains a reference
to a page, a rectangle on that page, and information specifying how to adjust the view to fit the
window's size and shape. It corresponds to a PDF Dest array (see Named Destinations in Section 8.2,
Document-Level Navigation, in the PDF Reference) and can be considered a special form of
a PdfAction.
PDViewDest provides a number of methods to get or set the attributes describing the location and
size of the view, including the page, rectangle, and fit style.
*/
struct PdfViewDestination {
  //! Get the destination page number.
  /*!
  \param doc Target document in which the page number will be resolved.
  \return the destination page number
  */
  virtual int GetPageNum(PdfDoc* doc) = 0;

  //! Get the destination fit type
  /*!
  \return one of the PdfDestFitType values
  */
  virtual PdfDestFitType GetFitType() = 0;

  //! Returns the destination page number.
  /*!
  \param reason Reason for the signing.
  \return true if was set successfully, false otherwise.
  */
  virtual void GetBBox(_out_ PdfRect* bbox) = 0;

  //! Returns the destination page number.
  /*!
  \param reason Reason for the signing.
  \return true if was set successfully, false otherwise.
  */
  virtual double GetZoom() = 0;

  //! Resolve the named destionation to the actual destination position in a document. The method
  //! returns the same object if the destination is resolved already or nullptr when the named destionation
  //! with specific name does not exist in the target document.
  /*!
  \param doc Target document in which the destination will be resolved.
  \return true if was set successfully, false otherwise.
  */
  virtual PdfViewDestination* Resolve(PdfDoc* doc) = 0;

  //! Determine if the destination it's a Named Destination. To access explicit values of the
  //! destination call Resolve mathod
  /*!
   \return true if view destination is Named Destination
  */
  virtual bool IsNamed() = 0;

  //! Gets the string buffer representing the destination name "Named Destination". Method raises
  //! an exception invalid object whene the destionation is not string object.
  /*!
   \param buffer (filled by method) If the buffer is null function returns required length of string
   \param len Length of a buffer to be filled in.
   \return Number of characters written into buffer of required length.
  */
  virtual int GetName(_out_ wchar_t* buffer, int len) = 0;

  //! Returns the destination page number.
  /*!
  \param reason Reason for the signing.
  \return true if was set successfully, false otherwise.
  */
  virtual PdsObject* GetObject() = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdfBaseDigSig
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pdf_PDFix_SDK*/
//!  PdfBaseDigSig class. 
/*!
A digital signature can be used to authenticate the identity of a user and
the document's contents. It stores information about the signer and the state of
the document when it was signed.
*/
struct PdfBaseDigSig {
  //! Destroys digital signature's resources.
  /*!
  \sa CreatePdfDigSig
  */
  virtual void Destroy() = 0;

  //! Sets the reason for the signing.
  /*!
  \param reason Reason for the signing.
  \return true if was set successfully, false otherwise.
  */
  virtual bool SetReason(const wchar_t* reason) = 0;

  //! Sets the location of signing.
  /*!
  \param location The CPU host name or physical location of the signing.
  \return true if was set successfully, false otherwise.
  */
  virtual bool SetLocation(const wchar_t* location) = 0;

  //! Sets the contact information of the signer.
  /*!
  \param contact Information provided by the signer to enable a recipient to 
  contact the signer to verify the signature, for example, a phone number, etc.
  \return true if was set successfully, false otherwise.
  */
  virtual bool SetContactInfo(const wchar_t* contact) = 0;

  //! Sets the name of the person or authority signing the document.
  //! This value is be used when it is not possible to extract the name 
  //! from the signature; for example, from the certificate of the signer or
  //! when PdfCustomDigSig is used.
  /*!
  \param name Name for signing.
  \return true if was set successfully, false otherwise.
  \sa PdfCustomDigSig
  */
  virtual bool SetName(const wchar_t* name) = 0;

  //! Sets the timestamp server url and accesses credentials to apply the timestamp.
  /*!
  \param url The url of the timesramp server .
  \param user_name The user name for accessing the timestamp server.
  \param password	The password for accessing the timestamp server.
  \return true if time stamp was set, false otherwise.
  */
  virtual bool SetTimeStampServer(const wchar_t* url,
    const wchar_t* user_name,
    const wchar_t* password) = 0;

  //! Applies the digital signature and saves document to specified path.
  /*!
  \param doc The document to be signed.
  \param path	The path where the signed document will be saved.
  \return true if document was signed, false otherwise.
  */
  virtual bool SignDoc(PdfDoc* doc, const wchar_t* path) = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class CPdfDigSig
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pdf_PDFix_SDK*/
//! PdfDigSig class. 
/*! 
Uses OpenSSL to handle certificates.
*/
struct PdfDigSig : public PdfBaseDigSig {
  //! Sets the pfx file for signing the document with digital signature.
  /*!
  \param pfx_file	The path of the PFX signature file.
  \param pfx_password	The password to open the PFX file.
  \return true if was set successfully, false otherwise.
  \ref\n Sample DigitalSignature
  */
  virtual bool SetPfxFile(const wchar_t* pfx_file, const wchar_t* pfx_password) = 0;
};

#if defined _WIN32 && defined _MSC_VER
////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdfCertDigSig
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pdf_PDFix_SDK*/
//! PdfCertDigSig class. 
/*! 
Platform specific digital signature object. It uses Windows CryptoAPI to manage certificates.
*/
struct PdfCertDigSig : public PdfBaseDigSig {
  //! Sets the pfx file for signing the document with digital signature.
  /*!
  \param pfx_file	The path of the PFX signature file.
  \param pfx_password	The password to open the PFX file.
  \return true if was set successfully, false otherwise.
  */
  virtual bool SetPfxFile(const wchar_t* pfx_file, const wchar_t* pfx_password) = 0;

  //! Sets the pointer to certificate from a certificate store.
  //! Certificate is a digitally signed statement that contains information about 
  //! an entity and the entity's public key, thus binding these two pieces of information 
  //! together. A certificate is issued by a trusted organization(or entity) 
  //! called a certification authority(CA).
  //! NOTE: Platform specific. Only for Windows.
  //! NOTE: Caller is responsible for de-allocating any resources associated 
  //! with the certificate.
  /*!
  \param cert_context	Pointer to a CERT_CONTEXT structure. A CERT_CONTEXT structure contains 
  a handle to a certificate store, a pointer to the original encoded certificate BLOB, 
  a pointer to a CERT_INFO structure, and an encoding type member. 
  The CERT_INFO structure that contains most of the certificate information.
  \return true if was set successfully, false otherwise.
  \ref\n Sample CertDigitalSignature
  */
  /*@LANG [!JAVA]*/
  virtual bool SetCertContext(void* cert_context) = 0;
  /*@LANG []*/
};
#endif

//Mac OS X - Keychain Access program, which is able to perform various certificate-elated services.

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdfCustomDigSig
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pdf_PDFix_SDK*/
//!  PdfCustomDigSig class. 
/*!
Platfor independent digital signature object. Caller can handle signing process with callbacks.
*/
/*@LANG [!JAVA !CSHARP]*/
struct PdfCustomDigSig : public PdfBaseDigSig {
  //! Registers a user-supplied procedure to call when PdfCustomDigSig::SignDoc is called.
  /*!
  \param proc A user-supplied callback to call when the digital signature requests
  signed digests data.
  \param data A pointer to user-supplied data to pass to proc each time it is called.
  \return true if callback was registered, false otherwise.
  \sa PdfCustomDigSig::RegisterDigestDataLenProc
  */
  virtual bool RegisterDigestDataProc(_callback_ PdfDigestDataProc proc, void* data) = 0;
};
/*@LANG []*/

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdfDoc
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pdf_PDFix_SDK*/
//!  PdfDoc class. 
/*!
A PdfDoc object represents a PDF document.
*/
struct PdfDoc {
  //! Saves a document to the file. 
  //! NOTE: You must call PdfDoc::Close to release resources.
  /*!
  \param path Absolute file path where the document should be saved.
  \param flags A bit field combination PdfSaveFlags values. If kSaveIncremental is specified in flags,
  then path should be NULL. If kSaveFull is specified and path is the same as the file's original path,
  the new file is saved to a file system-determined temporary path, then the old file is deleted and
  the new file is renamed to path.
  \return true if document was saved succsessfully, false otherwise.
  \sa PdfDoc::Close
  */
  virtual bool Save(const wchar_t* path, PdfSaveFlags save_flags) = 0;

  //! Saves a document to the stream. 
  //! NOTE: You must call PdfDoc::Close to release resources.
  /*!
  \param stream The stream to which the file is saved.
  \param flags A PdfSaveFlags value. If kSaveIncremental is specified in flags, then path should
  be NULL. If kSaveFull is specified and path is the same as the file's original path, the new file is
  saved to a file system-determined temporary path, then the old file is deleted and the new file is
  renamed to path.
  \return true if document was saved succsessfully, false otherwise.
  \sa PdfDoc::Close
  */
  virtual bool SaveToStream(PsStream* stream, PdfSaveFlags flags) = 0;

  //! Closes a document and releases its resources. Changes are not saved.
  /*!
  \return true if document was closed succsessfully, false otherwise.
  \sa PdfDoc::Save
  */
  virtual bool Close() = 0;

  //! Adds an image-based watermark to a page range in the given document.
  /*!
  \param params Structure specifying how the watermark should be added to the document.
  \param image_xobj The image XObject created with CreateXObjectFromImage.
  \return true if the watermark was added succsessfully, false otherwise.
  \sa PdfDoc::CreateXObjectFromImage
  \ref\n Sample AddWatermark
  */
  virtual bool AddWatermarkFromImage(PdfWatermarkParams* params, PdsStream* image_obj) = 0;

  //! Gets the number of pages in a document.
  /*!
  \return Number of pages in the document.
  */
  virtual int GetNumPages() = 0;

  //! Gets a PdfPage from a document. The page is cached, so that subsequent calls on the same PDPage 
  //! return The same PdfPage and increments the reference count. The page remains in the cache
  //! as long as document exists or PdfPage::Release was not called.
  //! AcquirePage increments a page�s reference count. The page will not be released until the
  //! reference count is zero, or the application terminates.
  //! NOTE: After you are done using the page, release it using PdfPage::Release to release resources.
  /*!
  \param page_num The page number of the page to get. The first page is 0.
  \return The requested page.
  \sa PdfPage::Release
  */
  virtual PdfPage* AcquirePage(int page_num) = 0;
  
  //! Creates and acquires a new page. The page is inserted into the document at the specified location.
  //! NOTE: After you are done using the page, release it using PdfPage::Release to release resources.
  /*!
  \param index Where to add the page. Passing a value of -1 adds the page to the end.
  Passing a value of 0 adds the page to the beginning of the document.
  \param mediaBox Rectangle specifying the page's media box.
  \return The newly created page.
  \sa PdfPage::Release
  */
  virtual PdfPage* CreatePage(int index, const PdfRect* media_box) = 0;

  //! Deletes the specified pages.
  /*!
  \param index_from The page number of the first page to delete. The first page is 0.
  \param index_to The page number of the last page to delete.
  \param cancel_proc Callback to check for canceling operations.
  \param cancel_data Pointer to client data for the cancel procedure.
  \return true if pages were deleted succsessfully, false otherwise.
  */
  virtual bool DeletePages(int index_from, int index_to, _callback_ PdfCancelProc cancel_proc, void* cancel_data) = 0;
  
  //! Inserts pages from input doc into the current doc. All annotations, and anything else associated with the
  //! page (such as a thumbnail image) are copied from the doc pages to the new pages in doc.
  //! The insertFlags control whether data are inserted along with the specified pages.
  /*!
  \param index The page number in the current doc after where pages from doc are inserted.
  \param doc The document containing the pages that are inserted into the current doc.
  \param index_from The page number of the first page of doc to insert.
  \param index_to The page number of the last page of doc to insert.
  \param insert_flags Flags that determine what additional information is copied from doc.
  \param cancel_proc Callback to check for canceling operations.
  \param cancel_data Pointer to client data for the cancel procedure.
  \return true if pages were inserted succsessfully, false otherwise.
  */
  virtual bool InsertPages(int index, const PdfDoc* doc, int index_from, int index_to,
    PdfPageInsertFlags insert_flags, _callback_ PdfCancelProc cancel_proc, void* cancel_data) = 0;
  
  //! Moves one page in a document.
  /*!
  \param index_to The new location of the page to move.
  \param index_from The page number of the page to move.
  \return true if page was moved succsessfully, false otherwise.
  */
  virtual bool MovePage(int index_to, int index_from) = 0;

  //! Gets the number of document JavaScript name/action pairs in the document JavaScript name tree
  /*!
  \return Number document name/action pairs in the document's JavaScript name tree.
  \sa PdfDoc::GetDocumentJavaScript
  \sa PdfDoc::GetDocumentJavaScriptName
  */
  virtual int GetNumDocumentJavaScripts() = 0;

  //! Gets the document JavaScript action by it's index in th documente JavaScript name tree
  /*!
  \param index The index of a JavaScript action name to retrieve
  \param buffer (filled by method) If the buffer is null function returns required length of string
  \param len Length of a buffer to be filled in.
  \return Number of characters written into buffer of required length.
  \sa PdfDoc::GetNumDocumentJavaScripts
  \sa PdfDoc::GetDocumentJavaScriptName
  */
  virtual int GetDocumentJavaScript(int index, _out_ wchar_t* buffer, int len) = 0;

  //! Gets the document JavaScript action name by it's index in th documente JavaScript name tree
  /*!
  \param index The index of a JavaScript action name to retrieve
  \param buffer (filled by method) If the buffer is null function returns required length of string
  \param len Length of a buffer to be filled in.
  \return Number of characters written into buffer of required length.
  \sa PdfDoc::GetNumDocumentJavaScripts
  \sa PdfDoc::GetDocumentJavaScript
  */
  virtual int GetDocumentJavaScriptName(int index, _out_ wchar_t* buffer, int len) = 0;

  //! Gets the number of calculated form fields in AcroForm calculated order (CO) which is an array 
  //of indirect references to field dictionaries with calculation actions, defining the calculation 
  //order in which their values will be recalculated when the value of any field changes
  /*!
  \return Number of calculated form fields in the document.
  \sa PdfDoc::GetCalculatedFormField
  \sa PdfDoc::GetNumFormFieldCounts
  \sa PdfDoc:GetFormField
  */
  virtual int GetNumCalculatedFormFields() = 0;

  //! Gets the calculated form field from AcroForm calculation order array (CO) by index.
  /*!
  \param index The index of a form field to retrieve.
  \return The PdfFormField object or nullptr in case of error.
  \sa PdfDoc::GetNumCalculatedFormFields
  \sa PdfDoc::GetNumFormFieldCounts
  \sa PdfDoc:GetFormField
  */
  virtual PdfFormField* GetCalculatedFormField(int index) = 0;

  //! Gets the total number of form fields in document's AcroForm Fields tree.
  /*!
  \return Number of form fields in the document.
  \sa PdfDoc::GetNumCalculatedFormFields
  \sa PdfDoc::GetCalculatedFormField
  \sa PdfDoc:GetFormField
  */
  virtual int GetNumFormFields() = 0;

  //! Gets the form field in document's AcroForm Fields tree by index.
  /*!
  \return The PdfFormField object or nullptr in case of error.
  \sa PdfDoc::GetNumCalculatedFormFields
  \sa PdfDoc::GetCalculatedFormField
  \sa PdfDoc::GetNumFormFieldCounts
  */
  virtual PdfFormField* GetFormField(int index) = 0;

  //! Gets the form field in document's AcroForm Fields tree by name.
  /*!
  \return The PdfFormField object or nullptr in case of error.
  \sa PdfDoc::GetNumCalculatedFormFields
  \sa PdfDoc::GetCalculatedFormField
  \sa PdfDoc::GetNumFormFieldCounts
  */
  virtual PdfFormField* GetFormFieldByName(const wchar_t* buffer) = 0;

  //! Gets the value of a key in a document's Info dictionary.
  /*!
  \param key The name of the Info dictionary key whose value is obtained.
   \param buffer (filled by method) If the buffer is null function returns required length of string
   \param len Length of a buffer to be filled in.
   \return Number of characters written into buffer of required length.
  */
  virtual int GetInfo(const wchar_t* key, _out_ wchar_t* buffer, int len) = 0;

  //! Sets the value of a key in a document's Info dictionary.
  /*!
  \param key The name of the Info dictionary key whose value is obtained.
  \param buffer String value to be set for the specific Info dictionary entry.
  \return true if optaining the font state was succsessfull, false otherwise.
  */
  virtual bool SetInfo(const wchar_t* key, const wchar_t* info) = 0;

  //! Gets the abstract root of the document's bookmark tree. This bookmark has 
  //! no representation in PDF, it only holds top level of document's bookmarks. 
  //! NOTE: Call only PdfBookmark::GetNumChildren and PdfBookmark::GetChild methods
  //! for this bookmark. Other methods return false.
  /*!
  \return The document's root bookmark.
  \ref\n Sample GetBookmarks
  */
  virtual PdfBookmark* GetBookmarkRoot() = 0;

  //! Flatten annotation appearances to the document content and removes flattened 
  //! annotation from the page
  /*!
  \return true if annotation flattening was successfull, false otherwise.
  */
  virtual bool FlattenAnnots(PdfFlattenAnnotsParams* params) = 0;

  //! Apply redaction annotations to the document content
  /*!
  \return true if doument redaction was successfull, false otherwise.

  // TODO: PdfRedactionParams* params
  */
  virtual bool ApplyRedaction() = 0;

  //! Gets the number of PDF alternate in the document.
  /*!
  \return The number of alternates.
  */
  virtual int GetNumAlternates() = 0;

  //! Gets the PDF alternate based on it's index.
  /*!
  \param index The index of an alternate.
  */
  virtual PdfAlternate* AcquireAlternate(int index) = 0;

  //! Creates a new PdsObject associated with the specified document.
  /*!
  \param type The type of a new object.
  \param indirect If true, creates the object as an indirect object. 
  If false, creates the object as a direct object.
  \return The newly created object.
  */
  virtual PdsObject* CreatePdsObject(PdfObjectType type, bool indirect) = 0;

  //! Add tags into document.
  /*!
  \param cancel_proc Callback to check for canceling operations. A CancelProc is typically passed
  to some method that takes a long time to complete. At frequent intervals,
  the method calls the CancelProc. If it returns true, then the method cancels its operation; if
  false, it continues.
  \param cancel_data Pointer to client data for the cancel procedure.
  \return true if tags were added successfuly, false otherwise.
  */
  virtual bool AddTags(_callback_ PdfCancelProc cancel_proc, void* cancel_data) = 0;

  //! Remove tags and all structural elements from the document. This method is internally
  //! called in CPdfDoc::AddTags method to be sure that all previous tags were removed.
  /*!
  \param cancel_proc Callback to check for canceling operations.
  \param cancel_data Pointer to client data for the cancel procedure.
  */
  virtual bool RemoveTags(_callback_ PdfCancelProc cancel_proc, void* cancel_data) = 0;

  //! Accesses document template.
  /*!
  \param cancel_proc Callback to check for canceling operations.
  \param cancel_data Pointer to client data for the cancel procedure.
  \return true if successfull, false otherwise.
  */
  virtual PdfDocPreflight* GetDocPreflight() = 0;

  //! Gets documnent metadata.
  /*!
  \return PsMetadata object if metadata was successfully loaded, nullptr otherwise.
  */
  virtual PsMetadata* GetMetadata() = 0;

  //! Gets documnent primary language. 
  /*!
  A language identifier that shall specify the natural language for all text in the document
  except where overridden by language specifications for structure elements or marked content.
   \param buffer (filled by method) If the buffer is null function returns required length of string
   \param len Length of a buffer to be filled in.
   \return Number of characters written into buffer of required length.
  \sa PdfDoc::SetLang
  */
  virtual int GetLang(_out_ wchar_t* buffer, int len) = 0;

  //! Sets documnent primary language.
  /*!
  \param buffer The buffer containing document primary buffer
  \return true if the language was successfully set
  \sa PdfDoc::GetLang
  */
  virtual bool SetLang(const wchar_t* lang) = 0;

  //! Embeds or subsets fonts used in the document
  /*!
  \param subset If true, embeds each font inside doc with creating a subset.
  \param cancel_proc Callback to check for canceling operations.
  \param cancel_data Pointer to client data for the cancel procedure.
  \return true if the was embedded successfully
   \sa PdfDoc::AddFontMissingUnicode
  */
  virtual bool EmbedFonts(bool subset, _callback_ PdfCancelProc cancel_proc, void* cancel_data) = 0;

  //! Makes a PDF document accessible.
  /*!
  \param params PdfAccessibleParams parameters that control process of making PDF accessible.
  \param cancel_proc Callback to check for canceling operations.
  \param cancel_data Pointer to client data for the cancel procedure.
  \return true if successfull, false otherwise.
  */
  virtual bool MakeAccessible(PdfAccessibleParams* params, _callback_ PdfCancelProc cancel_proc, void* cancel_data) = 0;

  //! Gets the document trailer dictionary.
  /*!
  \return PdsObject that represents document trailer.
  */
  virtual PdsDictionary* GetTrailerObject() = 0;

  //! Gets the document catalog dictionary which is a Root entry.
  /*!
  \return PdsObject that represents document root.
  */
  virtual PdsDictionary* GetRootObject() = 0;

  //! Gets the Info dictionary of the document.
  /*!
  \return PdsObject that represents document root.
  */
  virtual PdsDictionary* GetInfoObject() = 0;
  
  //! Create new PdsDictionary object
  /*!
   \param indirect if true the method creates indorect object othervise a direct object.
   \return newly created PdsDictionary object.
  */
  virtual PdsDictionary* CreateDictObject(bool indirect) = 0;

  //! Create new PdsArray object
  /*!
   \param indirect if true the method creates indorect object othervise a direct object.
   \return newly created PdsArray object.
   */
  virtual PdsArray* CreateArrayObject(bool indirect) = 0;

  //! Create new PdsName object
  /*!
   \param indirect if true the methods indorect object othervise a direct object.
   \param value the value to be set to an object.
   \return newly created PdsName object.
   */
  virtual PdsName* CreateNameObject(bool indirect, const wchar_t* value) = 0;

  //! Create new PdsString object
  /*!
   \param indirect if true the method creates indorect object othervise a direct object.
   \param value the value to be set to an object.
   \return newly created PdsString object.
   */
  virtual PdsString* CreateStringObject(bool indirect, const wchar_t* value, bool hex) = 0;

  //! Create new PdsNumber (integer) object
  /*!
   \param indirect if true the method creates indorect object othervise a direct object.
   \param value the value to be set to an object.
   \return newly created PdsNumber object.
   */
  virtual PdsNumber* CreateIntObject(bool indirect, int value) = 0;

  //! Create new PdsNumber (float) object
  /*!
   \param indirect if true the method creates indorect object othervise a direct object.
   \param value the value to be set to an object.
   \return newly created PdsNumber object.
   */
  virtual PdsNumber* CreateNumberObject(bool indirect, double value) = 0;

  //! Create new PdsStream object
  /*!
   \param indirect if true the method creates indorect object othervise a direct object.
   \param dict the stream dictionary object.
   \param buffer data to be set a a stream value.
   \param size the size of the buffer in bytes.
   \return newly created PdsStream object.
   */
  virtual PdsStream* CreateStreamObject(bool indirect, PdsDictionary* dict,
    _in_ const uint8_t* buffer, int size) = 0;

  //! Create new XObject of the type Image from an image data. Supported image types are
  //! JPEG and PNG
  /*!
   \param image_data The image data
   \param format The format of the he image
   \return Newly created PdsStream object of the XObject.
   */
  virtual PdsStream* CreateXObjectFromImage(PsStream* image_data, PdfImageFormat format) = 0;

  //! Get the document object by number.
  /*!
   \param obj_id The number of the object to retrieve
   \return Corresponding object or null if no such object exists in the document
   */
  virtual PdsObject* GetObjectById(int obj_id) = 0;
  
  //! Creates the Struct Tree root object of the document.
  //! If PdfDoc already has a StructTree it returns the existing structure tree.
  /*!
  \return PdsStructTree object that represents document struct tree root.
  */
  virtual PdsStructTree* CreateStructTree() = 0;
  
  //! Gets the Struct Tree root object of the document.
  /*!
  \return PdsStructTree object that represents document struct tree root.
  */
  virtual PdsStructTree* GetStructTree() = 0;
  
  //! Removes and destroy the StructTreeRoot element from the specified PdfDoc.
  //! This methods doesn't remove marked-content from pages. To do that each page needs
  //! to be acquired with CPdfDoc::AcquirePage and marked-content needs to be removed.
  //! To be sure that all structural elements were removed, rather call PdfDoc::RemoveTags.
  /*!
  \sa PdfDoc::RemoveTags
  */
  virtual void RemoveStructTree() = 0;
  
  //! Removes all bookmarks from the document.
  /*!
   \sa PdfDoc::CreateBookmarks
   */
  virtual void RemoveBookmarks() = 0;

  //! Create bookmark tree from the document's structure tree headings.
  /*!
   \param cancel_proc Callback to check for canceling operations.
   \param cancel_data Pointer to client data for the cancel procedure.
   \return true if successfull. false othervise
   \sa PdfDoc::RemoveBookmarks
   */
  virtual bool CreateBookmarks(_callback_ PdfCancelProc cancel_proc, void* cancel_data) = 0;
  
  //! Search used font's characters and add appropriate unicode character if not present.
  /*!
   \param cancel_proc Callback to check for canceling operations.
   \param cancel_data Pointer to client data for the cancel procedure.
   \return true if successfull. false othervise
   \sa PdfDoc::EmbedFonts
   */
  virtual bool AddFontMissingUnicode(_callback_ PdfCancelProc cancel_proc, void* cancel_data) = 0;
  
  //! Get a name tree, with the key name specified in the tree, from the Names dictionary of the PdfDoc
  /*!
   \param name The name of requested tree.
   \param create Create the tree if the tree with requested name does not exist.
   */
  virtual PdfNameTree* GetNameTree(const wchar_t* name, bool create) = 0;

  //! Removes the name tree in the Names dictionary with the specified key name it that name exists.
  /*!
   \param name The name of requested tree to remove.
   */
  virtual void RemoveNameTree(const wchar_t* name) = 0;
  
  //! Gets the page number of the page specified by a page dictionary
  /*!
   \param page_dict The page dictionary object whose number is obtained.
   \return the page number in the document.
   \sa PdfDoc::AcquirePage
   */
  virtual int GetPageNumFromObject(PdsObject* page_dict) = 0;
  
  //! Gets the PdfAnnot object from a PdsObject
  /*!
   \param annot_dict The annotation dictionary object from which the annotation will be obtained.
   */
  virtual PdfAnnot* GetAnnotFromObject(PdsObject* annot_dict) = 0;

  //! Gets the PdfAction object from a PdsObject
  /*!
   \param action_obj The action object from which the action will be obtained.
   */
  virtual PdfAction* GetActionFromObject(PdsObject* action_obj) = 0;
  
  //! Gets the PdfViewDestination object from a PdsObject
  /*!
   \param dest_obj The view destination object from which the object will be obtained.
   */
  virtual PdfViewDestination* GetViewDestinationFromObject(PdsObject* dest_obj) = 0;

  //! Create the PdsForm object from a PdsStream
  /*!
   \param stream The PdsObject from which the content will be obtained.
   \return PdsForm.
   */
  virtual PdsForm* CreateFormFromObject(PdsStream* stream) = 0;
  
  //! Create new PdsContent object 
  /*!
  \return PdsContent.
   */
  //virtual PdsContent* CreateContent() = 0;

};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdfDocPreflight
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pdf_PDFix_SDK*/
//!  PdfDocPreflight class.
/*!
PdfDocPreflight is used to customize a logical content detection algorithm based on document set.
\sa tag-alternate
*/
struct PdfDocPreflight {
  //! \ Preflights the document and initializes the document template based on the content.
  /*!
  \param cancel_proc Callback to check for canceling operations.
  \param cancel_data Pointer to client data for the cancel procedure.
  \return true if the style was set successfuly
  */
  virtual bool PreflightDoc(_callback_ PdfCancelProc cancel_proc, void* cancel_data) = 0;

  //! Imports a document template configuration from a stream. Only JSON and XML formats are supported.
  /*!
  \param stream Source stream of the document template.
  \param format Format of the source stream. Only JSON format is supported.
  \return true if the document templated was loaded successfuly
  */
  virtual bool LoadFromStream(PsStream* stream, PsDataFormat format) = 0;

  //! Exports document template configuration into a stream. Only JSON and XML formats are supported.
  /*!
  \param stream Source stream of the document template.
  \param format Format of the source stream. Only JSON format is supported.
  \return true if the the document template was exported successfuly
  */
  virtual bool SaveToStream(PsStream* stream, PsDataFormat format) = 0;

  //! Resets document template to default values.
  /*!
  */
  virtual bool SetDefaults() = 0;
  
  //! Gets the value of the property by name.
  /*!
  \param name Name of the propety.
  \return Value of the property.
  \sa PdfDocPreflight::SetRegex
  */
  virtual double GetProperty(const wchar_t* name) = 0;

  //! Supply the name of the property and the value as a double, just as you would in a config file.
  /*!
  \param name Name of the propety.
  \param value New value of the property.
  \return true if value was set, false otherwise.
  \sa PdfDocPreflight::GetProperty
  */
  virtual bool SetProperty(const wchar_t* name, double value) = 0;
  
  //! Gets the pattern of the regex by name.
  /*!
  \param name Name of the regex.
  \param buffer (filled by method) If the buffer is null function returns required length of string
  \param len Length of a buffer to be filled in.
  \return Number of characters written into buffer of required length.
  \sa PdfDocPreflight::SetRegex
  */
  virtual int GetRegex(const wchar_t* name, _out_ wchar_t* buffer, int len) = 0;

  //! Supply the name of the regex and the pattern as a wstring, just as you would in a config file.
  /*!
  \param name Name of the regex.
  \param pattern New pattern of the regex.
  \return true if pattern was set, false otherwise.
  \sa PdfDocPreflight::GetRegex
  */
  virtual bool SetRegex(const wchar_t* name, const wchar_t* pattern) = 0;
  
  //! Preprocess the page before the document preflight. Methods parses the page and collects information
  //! for document preflight.
  /*!
  \param page_num The page number to preprocess.
  \return true if successfull, false otherwise.
  */
  virtual bool PreflightPage(int page_num) = 0;

  //! Get the object reffering the document template related to the page
  /*!
  \param page_num The page number for which the information is to be retrieved.
  \return The PdfPagePreflight object or null in the case of error.
  */
  virtual PdfPagePreflight* GetPagePreflight(int page_num) = 0;

  //! Save the preflight data into a stream in a JSON or XML format
  /*!
  \param stream Source stream of the document template.
  \param format Format of the source stream. Only JSON format is supported.
  \return true if the the document template was exported successfuly
  */
  virtual bool SavePreflightToStream(PsStream* stream, PsDataFormat format) = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdfPagePreflight
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pdf_PDFix_SDK*/
//!  PdfPagePreflight class.
/*!
PdfPagePreflight class.
*/
struct PdfPagePreflight {
  //! Get the preflighted page number
  /*!
  \return the number of page from preflight
  */
  virtual int GetPageNum() = 0;

  //! Get the logical rotation of the preflighted page
  /*!
  \return the logical page rotation
  */
  virtual PdfRotate GetLogicalRotate() = 0;

  //! Get the number of found columns on the page
  /*!
  \return the number of columns
  */
  virtual int GetNumColumns() = 0;

  //! Get the bounding box of a page header
  /*!
  \param crop_box (Filled by the method) Pointer to a rectangle specifying the page's crop box,
  specified in user space coordinates.
  \return true if the header bounding box was identified
  */
  virtual bool GetHeaderBBox(_out_ PdfRect* bbox) = 0;

  //! Save the preflight data into a stream in a JSON or XML format
  /*!
  \param crop_box (Filled by the method) Pointer to a rectangle specifying the page's crop box,
  specified in user space coordinates.
  \return true if the header bounding box was identified
  */
  virtual bool GetFooterBBox(_out_ PdfRect* bbox) = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdfAlternate
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pdf_PDFix_SDK*/
//!  PdfAlternate class. 
/*!
PdfAlternate class.
*/
struct PdfAlternate {
  //! Gets the subtype of the PDF alternate
  /*!
  \return the PDF alternate subtype
  */
  virtual PdfAlternateType GetSubtype() = 0;

  //! Gets a buffer containing the name of an alternate, otherwise it returns 0.
  /*!
  \param buffer (filled by method) If the buffer is null function returns required length of string
  \param len Length of a buffer to be filled in.
  \return Number of characters written into buffer of required length.
  */
  virtual int GetName(_out_ wchar_t* buffer, int len) = 0;

  //! Gets a buffer containing the description of an alternate, otherwise it returns 0.
  /*!
  \param buffer (filled by method) If the buffer is null function returns required length of string
  \param len Length of a buffer to be filled in.
  \return Number of characters written into buffer of required length.
  */
  virtual int GetDescription(_out_ wchar_t* buffer, int len) = 0;

  //! Gets a buffer containing the file name of the main alternate file. 
  /*!
  \param buffer (filled by method) If the buffer is null function returns required length of string
  \param len Length of a buffer to be filled in.
  \return Number of characters written into buffer of required length.
  */
  virtual int GetFileName(_out_ wchar_t* buffer, int len) = 0;

  //! Saves the alternate content to the folder specified by path and fileSys. The path is 
  //! a base path and saved content cause creation of additional subfolders based on the 
  //! relative path specified in the embedded file spec.
  /*!
  \return True if the content was saved successfully
  \sa PdfAlternate::GetFileName
  \sa PdfAlternate::Release
  */
  virtual bool SaveContent(const wchar_t* path) = 0;

  //! Closes the PDF alternate and release any loaded content
  /*!
  */
  virtual void Release() = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdfHtmlAlternate
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pdf_PDFix_SDK*/
//!  PdfHtmlAlternate class. 
/*!
PdfHtmlAlternate class.
*/
struct PdfHtmlAlternate : public PdfAlternate {
  //! Saves the resource content by name to specified location.
  /*!
  \param path Path where the file should be saved
  \param reource_naem The name of the resource
  \return True if file was saved. False othervise.
  */
  virtual bool SaveResource(const wchar_t* resource_name, const wchar_t* path) = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdfFont
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pdf_PDFix_SDK*/
//!  PdfFont class. 
/*!
PdfFont class.
*/
struct PdfFont {
  //! Gets the name of a font.
  /*!
  \param buffer (filled by method) If the buffer is null function returns required length of string
  \param len Length of a buffer to be filled in.
  \return Number of characters written into buffer of required length.
  */
  virtual int GetFontName(_out_ wchar_t* buffer, int len) = 0;

  //! Gets the face of a font.
  /*!
  \param buffer (filled by method) If the buffer is null function returns required length of string
  \param len Length of a buffer to be filled in.
  \return Number of characters written into buffer of required length.
  */
  virtual int GetFaceName(_out_ wchar_t* buffer, int len) = 0;

  //! Gets the font state of a font.
  /*!
  \param font_state (filled by method) Pointer to font state structure to be filled in.
  \return true if optaining the font state was succsessfull, false otherwise.
  */
  virtual void GetFontState(_out_ PdfFontState* font_state) = 0;

  //! Gets the name of a font which is a system replacement for the font.
  /*!
   \param buffer (filled by method) If the buffer is null function returns required length of string
   \param len Length of a buffer to be filled in.
   \return Number of characters written into buffer of required length.
  */
  virtual int GetSystemFontName(_out_ wchar_t* buffer, int len) = 0;

  //! Gets the charset of a font which is a system replacement for the font.
  /*!
  \return Number of charset of a font.
  */
  virtual PdfFontCharset GetSystemFontCharset() = 0;

  //! Gets the the system font bold flag.
  /*!
  \return true is font is bold, false otherwise.
  */
  virtual bool GetSystemFontBold() = 0;

  //! Gets the the system font italic flag.
  /*!
  \return true is font is italic, false otherwise.
  */
  virtual bool GetSystemFontItalic() = 0;

  //! Saves the font into a font file. 
  /*!
  \param PsStream in which to save font data in requested format.
  \param format PdfFontFormat.
  \return true if succeeded, false otherwise.
  */
  virtual bool SaveToStream(PsStream* stream, PdfFontFormat format) = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdfFormField
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pdf_PDFix_SDK*/
//! PdfFormField class 
/*!
PdfFormField object represents interactive form dictionary that shall be referenced from the AcroForm 
entry in the document catalogue
*/
struct PdfFormField {
  //!  Gets the type of field.
  /*!
  \return The form field type.
  */
  virtual PdfFieldType GetType() = 0;

  //!  Gets the form field's flags.
  /*!
  \return The form field's flags.
  */
  virtual PdfFieldFlags GetFlags() = 0;

  //!  Sets the form field's flags.
  /*!
  \return true if the FormField's flags was set successfully.
  */
  virtual bool SetFlags(PdfFieldFlags flags) = 0;

  //! Gets the field's value as string. 
  /*!
   \param buffer (filled by method) If the buffer is null function returns required length of string
   \param len Length of a buffer to be filled in.
   \return Number of characters written into buffer of required length.
  */
  virtual int GetValue(_out_ wchar_t* buffer, int len) = 0;

  //! Sets the field's value as string. Multiple values should be comma-separated. 
  /*!
  \param buffer The new form field string value
  \return true if succeeded, false otherwise.
  \ref\n Sample SetFormFieldValue
  */
  virtual bool SetValue(const wchar_t* value) = 0;

  //! Gets the field's default value as string. 
  /*!
   \param buffer (filled by method) If the buffer is null function returns required length of string
   \param len Length of a buffer to be filled in.
   \return Number of characters written into buffer of required length.
  */
  virtual int GetDefaultValue(_out_ wchar_t* buffer, int len) = 0;

  //! Gets the field's full name within the document AcroForm field tree.
  /*!
   \param buffer (filled by method) If the buffer is null function returns required length of string
   \param len Length of a buffer to be filled in.
   \return Number of characters written into buffer of required length.
  */
  virtual int GetFullName(_out_ wchar_t* buffer, int len) = 0;

  //! Gets the field's tooltip. 
  /*!
   \param buffer (filled by method) If the buffer is null function returns required length of string
   \param len Length of a buffer to be filled in.
   \return Number of characters written into buffer of required length.
  */
  virtual int GetTooltip(_out_ wchar_t* buffer, int len) = 0;

  //! Gets the number of elements in the Opt array. 
  /*!
  \return Number of field's options.
  */
  virtual int GetNumOptions() = 0;

  //! Gets the field's option value. 
  /*!
  \param index The index of option to retrieve.
   \param buffer (filled by method) If the buffer is null function returns required length of string
   \param len Length of a buffer to be filled in.
   \return Number of characters written into buffer of required length.
  */
  virtual int GetOptionValue(int index, _out_ wchar_t* buffer, int len) = 0;

  //! Gets the field's option caption. 
  /*!
  \param index The index of option to retrieve.
   \param buffer (filled by method) If the buffer is null function returns required length of string
   \param len Length of a buffer to be filled in.
   \return Number of characters written into buffer of required length.
  */
  virtual int GetOptionCaption(int index, _out_ wchar_t* buffer, int len) = 0;

  //! Gets a field's action object.
  /*!
  \return The annotation's action object or nullptr if annotation does not have an action.
  \sa GetAAction
  */
  virtual PdfAction* GetAction() = 0;

  //! Gets a field's additional action object.
  /*!
  \param event The event which additional action to get.
  \return The annotation's additional action object or nullptr if annotation does
  not have an action for specified event type.
  \sa GetAction
  */
  virtual PdfAction* GetAAction(PdfActionEventType event) = 0;

  //! Gets maximum length of the field's text, in characters.
  /*! 
  \return The maximum number of characters.
  */
  virtual int GetMaxLength() = 0;

  //! Gets the field's widget export value.
  /*!
   \param annot The widget annotation that holds the export value
   \param buffer (filled by method) If the buffer is null function returns required length of string
   \param len Length of a buffer to be filled in.
   \return Number of characters written into buffer of required length.
  */
  virtual int GetWidgetExportValue(PdfAnnot* annot, _out_ wchar_t* buffer, int len) = 0;
  
  //! Gets the field's dictionary object.
  /*!
   \return The requested field object.
  */
  virtual PdsDictionary* GetObject() = 0;
  
  //! Gets the number of field's export values of the radio button and check box field.
  /*!
   \return The number of the export values of the form field.
   \sa GetExportValue
  */
  virtual int GetNumExportValues() = 0;

  //! Gets the field's export value for n-th widget of the form field.
  /*!
   \param index the index of the widget in the form field
   \param buffer (filled by method) If the buffer is null function returns required length of string
   \param len Length of a buffer to be filled in.
   \return Number of characters written into buffer of required length.
   \sa GetNumExportValues
  */
  virtual int GetExportValue(int index, _out_ wchar_t* buffer, int len) = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdfPage
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pdf_PDFix_SDK*/
//!  PdfPage class. 
/*!
A PdfPage is a page in a document.
Among other associated objects, a page contains PdePageMap, that represents the page content.
*/
struct PdfPage {
  //! Releases page's resources. Decrements a page�s reference count. The document will not be released
  //! until the reference count is zero, or the application terminates.
  /*!
  \param page The page to release.
  \sa PdfPage::AcquirePage
  */
  virtual void Release() = 0;

  //! Gets the crop box for a page. The crop box is the region of the page to display and print.
  /*!
  \param crop_box (Filled by the method) Pointer to a rectangle specifying the page's crop box,
  specified in user space coordinates.
  */
  virtual void GetCropBox(_out_ PdfRect* crop_box) = 0;

  //! Gets the media box for a page. The media box is the 'natural size' of the page, 
  //! for example, the dimensions of an A4 sheet of paper.
  /*!
  \param media_box (Filled by the method) Pointer to a rectangle specifying the page's media box,
  specified in user space coordinates.
  */
  virtual void GetMediaBox(_out_ PdfRect* media_box) = 0;

  //! Gets the rotation value for a page.
  /*!
  \return Rotation value for the given page. Must be one of the PdfRotate values.
  \sa PdfRotate
  */
  virtual PdfRotate GetRotate() = 0;

  //! Sets the rotation value for a page.
  /*!
  \param rotate Rotation value to be set for a given page. It must be one of the PdfRotate values.
  \return true if succeeded, false otherwise.
  */
  virtual bool SetRotate(PdfRotate rotate) = 0;

  //! Gets the rotation value of elements(texts) on a page.
  /*!
  \return Rotation value of elements on the page. Must be one of the PdfRotate values.
  \sa PdfRotate
  */
  virtual PdfRotate GetLogicalRotate() = 0;
  
  //! Gets the matrix that transforms user space coordinates to rotated and cropped coordinates.
  //! The origin of this space is the bottom - left of the rotated, cropped page. Y is increasing.
  /*!
  \param matrix (Filled by the method) Pointer to the default transformation matrix.
  */
  virtual void GetDefaultMatrix(_out_ PdfMatrix* matrix) = 0;

  //! Gets the page number for the specified page.
  /*!
  \return The page within the document. The first page is 0.
  */
  virtual int GetNumber() = 0;

  //! Creates a PdePageMap from the PdfPage's elements.and increments the reference count.
  //! Call PdePageMap::AcquireElements to parse page objects.
  //! The PdePageMap remains in the cache as long as page exists or PdePageMap::Release was not called.
  //! Call PdePageMap::Release to release pagemap resources if necessary.
  /*!
  \return PdePageMap for the current page.
  \sa PdePageMap::Release, PdePageMap::AcquireElements
  */
  virtual PdePageMap* CreatePageMap() = 0;

  //! Generates a PdePageMap from the PdfPage's elements. The PdePageMap is cached, so that
  //! subsequent calls on the same PDPage return the same PdePageMap and increments the reference count.
  //! The PdePageMap remains in the cache as long as page exists or PdePageMap::Release was not called.
  //! Call PdePageMap::Release to release pagemap resources if necessary.
  /*!
  \param cancel_proc Callback to check for canceling operations.
  \param cancel_data Pointer to client data for the cancel procedure.
  \return PdePageMap for the current page.
  \sa PdePageMap::Release
  */
  virtual PdePageMap* AcquirePageMap(_callback_ PdfCancelProc cancel_proc, void* cancel_data) = 0;

  //! Generates a PdfPageView from the PdfPage's elements. The PdfPageView is cached, so that
  //! subsequent calls on the same PDPage and same input parameters return the same PdfPageView
  //! and increments the reference count.
  //! The PdePageMap remains in the cache as long as page exists or PdfPageView::Release was not called.
  //! Call PdfPageView::Release to release pagemap resources if necessary.
  /*!
  \param zoom Expected zoom of the page view.
  \param rotate Expected rotation of the page view.
  \return An acquired page view or null.
  \sa PdfPageView::Release
  */
  virtual PdfPageView* AcquirePageView(double zoom, PdfRotate rotate) = 0;

  //! Gets the number of annotations on a page. 
  //! Annotations associated with pop-up windows (such as strikeouts) are counted as two annotations.
  //! Widget annotations(form fields) are included in the count.
  /*!
  \return The number of annotations on a page.
  \sa PdfPage::GetAnnot
  */
  virtual int GetNumAnnots() = 0;

  //! Gets the requested annotation on the page.
  /*!
  \param index The index of annotation to obtain.
  \return Requested annotation object.
  \sa PdfPage::GetNumAnnots
  */
  virtual PdfAnnot* GetAnnot(int index) = 0;

  //! Removes an annotation from the specified page. Annotations are stored in arrays, which are
  //! automatically compressed when an annotation is removed. For this reason, if you use a loop 
  //! in which you remove annotations, structure the code so the loop processes from the
  //! highest to the lowest index. 
  /*!
  \param index The index of annotation to remove.
  \param flags PdfRemoveAnnotFlags to specify what other connected annotations will be removed.
  \return true if annotation was removed, false otherwise.
  \sa PdfPage::GetNumAnnots
  \ref\n Sample RemoveComments
  */
  virtual bool RemoveAnnot(int index, PdfRemoveAnnotFlags flags) = 0;

  //! Add an annotation to the page at specified position.
  /*!
  \param index Where to add the annotation in the page's annotation array.
  \param annot The annotation to add.
  \return true if annotation was added, false otherwise.
  */
  virtual bool AddAnnot(int index, PdfAnnot* annot) = 0;

  //! Creates a new annotation, associated with the specified page, but not added to the page.
  //! Use AddAnnot() to add the annotation to the page.
  /*!
  \param subtype Define a subtype of the annotation.
  \param rect Pointer to a rectangle specifying the annotation's bounds, specified in user space coordinates.
  \return The newly created annotation..
  */
  virtual PdfAnnot* CreateAnnot(PdfAnnotSubtype subtype, PdfRect* rect) = 0;

  //! Creates a new text annotation, associated with the specified page, but not added to the page. 
  //! Use AddAnnot() to add the annotation to the page.
  /*!
  \param subtype Define a subtype of the annotation.
  \param rect Pointer to a rectangle specifying the annotation's bounds, specified in user space coordinates.
  \return The newly created annotation..
  */
  virtual PdfTextAnnot* CreateTextAnnot(PdfRect* rect) = 0;

  //! Creates a new textmarkup annotation, associated with the specified page, but not added to the page. 
  //! Use AddAnnot() to add the annotation to the page.
  /*!
  \param subtype Define a subtype of the annotation.
  \param rect Pointer to a rectangle specifying the annotation's bounds, specified in user space coordinates.
  \return The newly created annotation..
  */
  virtual PdfTextMarkupAnnot* CreateTextMarkupAnnot(PdfAnnotSubtype subtype, PdfRect* rect) = 0;

  //! Create and add new text annotation to the page.
  /*!
  \param index Where to add the annotation in the page's annotation array.
  Passing a value of -1 adds the annotation to the end of the array (this is generally 
  what you should do unless you have a need to place the annotation at a special location in
  the array). Passing a value of 0 adds the annotation to the beginning of the array.
  \param rect Pointer to a rectangle specifying the annotation's bounds, specified in user space coordinates.
  \return The newly created PdfTextAnnot.
  \sa PdfPage::GetNumAnnots
  \ref\n Sample AddComment
  */
  virtual PdfTextAnnot* AddNewTextAnnot(int index, PdfRect* rect) = 0;

  //! Create and add new link annotation to the page.
  /*!
  \param index Where to add the annotation in the page's annotation array.
  \param rect Pointer to a rectangle specifying the annotation's bounds, specified in user 
  space coordinates. If it's null, use PdfLinkAnnot::AddQuad to specify the size 
  and location of an annotation on its page.
  \return The newly created PdfLinkAnnot.
  \sa PdfPage::AddNewTextAnnot, PdfLinkAnnot::AddQuad
  */
  virtual PdfLinkAnnot* AddNewLinkAnnot(int index, PdfRect* rect) = 0;

  //! Create and add new text markup annotation to the page.
  /*!
  \param subtype Define a subtype of the text markup annotation. Must be one of 
  kAnnotHighlight, kAnnotUnderline, kAnnotSquiggly, kAnnotStrikeOut.
  \param index Where to add the annotation in the page's annotation array.
  \param rect Pointer to a rectangle specifying the annotation's bounds, specified in user
  space coordinates. If it's null, use PdfTextMarkupAnnot::AddQuad to specify the size 
  and location of an annotation on its page.
  \return The newly created PdfTextMarkupAnnot.
  \sa PdfPage::AddNewTextAnnot, PdfTextMarkupAnnot::AddQuad
  */
  virtual PdfTextMarkupAnnot* AddNewTextMarkupAnnot(int index,
    PdfRect* rect,
    PdfAnnotSubtype subtype) = 0;

  //! Create and add new annotation to the page at specified position.
  /*!
  \param index Where to add the annotation in the page's annotation array.
  \param rect Pointer to a rectangle specifying the annotation's bounds, specified in user
  space coordinates. If it's null, use PdfTextMarkupAnnot::AddQuad to specify the size
  and location of an annotation on its page.
  \return The newly created PdfAnnot.
  */
  virtual PdfAnnot* AddNewAnnot(int index, PdfRect* rect, PdfAnnotSubtype subtype) = 0;

  //! Gets the number of annotations that reside under the given point. 
  /*!
  \param point The point to test.
  \return Number of annotations under the given point.
  \sa PdfPage::GetAnnotAtPoint
  */
  virtual int GetNumAnnotsAtPoint(PdfPoint* point) = 0;

  //! Gets the requested annotation that resides under the given point.
  /*!
  \param point The point to test.
  \param index (Filled by the method) Index of annotation to obtain.
  \return Pointer to the requested annotation, nullptr in a case of error.
  \sa PdfPage::GetAnnotAtRect
  */
  virtual PdfAnnot* GetAnnotAtPoint(PdfPoint* point, int index) = 0;

  //! Gets the number of annotations that reside under the given rectangle. 
  //! It returns each annotation that have intersection the given rectangle.
  /*!
  \param rect The rectangle to test.
  \return Number of annotations under the given rectangle.
  \sa PdfPage::GetAnnotAtPoint
  */
  virtual int GetNumAnnotsAtRect(PdfRect* rect) = 0;

  //! Gets the requested annotation that resides under the given rectangle.
  /*!
  \param rect The rectangle to test.
  \param index (Filled by the method) Index of annotation to obtain.
  \return Pointer to the requested annotation, nullptr in a case of error.
  \sa PdfPage::GetAnnotAtRect
  */
  virtual PdfAnnot* GetAnnotAtRect(PdfRect* rect, int index) = 0;

  //! Draws the contents of a page into the page view PsImage. This method just draws a bitmap.
  //! Provides control over the rendering with respect to PdfPageRenderParams.
  //! The PsImage remains in the cache as the page view class exists or next PdfPageViewDrawPage
  //! method is called.
  /*!
  \param params Rendering parameters.
  \param cancel_proc Callback to check for canceling operations.
  \param cancel_data Pointer to client data for the cancel procedure.
  \return true if page was rendered, false otherwise.
  \sa PdfPageView::GetImage
  \ref\n Sample RenderPage
  */
  virtual bool DrawContent(PdfPageRenderParams* params,
    _callback_ PdfCancelProc cancel_proc, 
    void* cancel_data) = 0;
    
  //! Gets a PdsContent from the PdfPage object's contents and resources.
  /*!
  \return A PdsContent representing the page's contents.
  */
  virtual PdsContent* GetContent() = 0;
  
  //! Gets the page resources dictionary. It can be either directly in the page object or
  //! it may be in the page tree stared with multiple pages.
  /*!
   \param res_type Name of the resource type (ExtGState, ColorSpace, Pattern, Shading, XObject, Font, and Properties).
   \param create The page resources objects is created if does not exists.
   \return The requested page resources objects.
   */
  virtual PdsDictionary* GetResources(const wchar_t* res_type, bool create) = 0;
  
  //! Gets the dictionary object associated with the page.
  /*!
   \return The requested page object.
   */
  virtual PdsDictionary* GetObject() = 0;
  
  //! Flatten all Form XObjects on the page into main page content.
  /*!
   \return True if operation was successfull. False otherwise.
   */
  virtual bool FlattenFormXObjects() = 0;
  
  //! Checks for various content objects in the page content.
  /*!
   \return A combination of the page content flags
   */
  virtual PdfPageContentFlags GetContentFlags() = 0;
  
  //! Write modified page content to the content stream.
  /*!
   \return True if operation was successfull. False otherwise.
   */
  virtual bool SetContent() = 0;
  
  
  //! Gets a reference to a document object
  /*!
   \return PdfDoc object.
   */
  virtual PdfDoc* GetDoc() = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdePageMap
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pde_PDFix_SDK*/
//!  PdePageMap class. 
/*!
The PdePageMap object is a storage of all PdeElements whose were recognized on the page.
A PdePageMap may be obtained from an existing page with the PdfPage::GetPageMap method.
Once your application has the page's PdePageMap, it can get each logical element with GetElement method.
*/
struct PdePageMap {
  //! Releases the pagemap resources at the current page.
  //! NOTE: The caller can call PdePageMap::Release to optimize a memory handling.
  //! Otherwise the page is responsible for freeing PdePageMap resources.
  /*!
  \return true if succeeded, false otherwise.
  \sa PdfPage::AcquirePageMap
  */
  virtual void Release() = 0;
  
  //! Gets the requested element from a pagemap.
  //! You should never depend on these objects lasting the lifetime of the pagemap.
  //! You should extract the information you need from he object immediately and 
  //! refer to it no further in your code.
  //! NOTE: This method does not copy the element, so do not destroy it.
  /*!
  \param index Index of element to obtain.
  \return The requested element.
  \sa PdePageMap::GetNumElements
  */
  virtual PdeElement* GetElement() = 0;

  //! Searches for whitespaces at the page. They are sorted from biggest to smallest.
  /*!
  \param params Whitespace parameters that specify which whitespace should be obtained.
  \param index Index of whitespace to obtain. Set to zero for the first call. 
  Update the index with each consecutive call of the method while result is true.
  \param bbox (Filled by the method) A PdfRect specifying requested whitespace.
  \return This method returns true if whitespace with requested params exists,
  otherwise it returns false.
  \ref\n Sample GetWhitespace
  */
  virtual bool GetWhitespace(PdfWhitespaceParams* params, int index, _out_ PdfRect* bbox) = 0;

  //! Gets the bounding box for a pagemap. The bounding box is the rectangle 
  //! that encloses all text, graphics, and images on the page.
  /*!
  \param bbox (Filled by the method) A PdfRect specifying the page's box.
  \sa PdePageMap::GetWhitespace
  */
  virtual void GetBBox(PdfRect* bbox) = 0;

  //! Recreates a PdePageMap from the PdfPage's elements.
  /*!
  \param cancel_proc Callback to check for canceling operations.
  \param cancel_data Pointer to client data for the cancel procedure.
  \return true if pagemap was generated successfuly, false otherwise.
  */
	virtual bool AcquireElements(_callback_ PdfCancelProc cancel_proc, void* cancel_data) = 0;

  //! Creates an empty element of specific type.
  /*!
  \param params Parameters of the newly created element.
  \return true Pointer to the newly created PDEElement.
  */
  virtual PdeElement* CreateElement(PdfElementType type, PdeElement* parent) = 0;
  
  //! Adds tags.
  /*!
  \param element Parent structure element.
  \param cancel_proc Callback to check for canceling operations.
  \param cancel_data Pointer to client data for the cancel procedure.
  \return true if tags were added successfuly, false otherwise.
  */
  virtual bool AddTags(PdsStructElement* element, _callback_ PdfCancelProc cancel_proc, void* cancel_data) = 0;
 };

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdfPageView
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pdf_PDFix_SDK*/
//!  PdfPageView class. 
/*!
A PdfPageView has methods to display the contents of a document page.
*/
struct PdfPageView {
  //! Releases the page view resources.
  //! NOTE: The caller can call PdfPageView::Release to optimize a memory handling.
  //! Otherwise the page is responsible for freeing PdfPageViews resources.
  /*!
  \param page_view The page view to delete.
  \sa PdfPage::AcquirePageView
  */
  virtual void Release() = 0;

  //! Returns a width of the page view in device space coordinates.
  /*!
  \return A page view width.
  \sa PdfPageView::GetDeviceHeight
  */
  virtual int GetDeviceWidth() = 0;

  //! Returns a height of the page view in device space coordinates.
  /*!
  \return A page view height.
  \sa PdfPageView::GetDeviceWidth
  */
  virtual int GetDeviceHeight() = 0;

  //! Gets the matrix that transforms user space coordinates to pageview coordinates.
  /*!
  \param matrix (Filled by the method) Pointer to the pageview matrix.
  */
  virtual void GetDeviceMatrix(_out_ PdfMatrix* matrix) = 0;

  //! Draws the contents of a page into the page view PsImage. This method just draws a bitmap.
  //! Provides control over the rendering with respect to PdfPageRenderParams.
  //! The PsImage remains in the cache as the page view class exists or next PdfPageViewDrawPage
  //! method is called.
  /*!
  \param params Rendering parameters. 
  \param cancel_proc Callback to check for canceling operations.
  \param cancel_data Pointer to client data for the cancel procedure.
  \return true if page was rendered, false otherwise.
  \sa PdfPageView::GetImage
  */
  //virtual bool DrawPage(PdfPageRenderParams* params, 
  //  _callback_ PdfCancelProc cancel_proc, 
  //  void* cancel_data) = 0;

  //! Gets the image data for a page view. 
  //! You should never depend on these objects lasting the lifetime of the document.
  //! You should extract the information you need from the object immediately and 
  //! refer to it no further in your code.
  //! NOTE: Do not destroy the returned PsImage when done with it.
  /*!
  \return Acquired Image data for page view. Returns null if there are no image data.
  \sa PdfPageView::DrawPage
  */
  //virtual PsImage* GetImage() = 0;

  //! Transforms a rectangle's coordinates from user space to device space. 
  //! The resulting PdfDevRect will be normalized, that is, left < right and top < bottom.
  /*!
  \param rect Pointer to the rectangle whose coordinates are transformed, specified
  in user space coordinates.
  \param dev_rect (Filled by the method) Pointer to a rectangle containing the device
  space coordinates corresponding to rect.
  \sa PdfPageView::PointToDevice
  */
  virtual void RectToDevice(PdfRect* rect, _out_ PdfDevRect* dev_rect) = 0;

  //! Transforms a point's coordinates from user space to device space.
  /*!
  \param point Pointer to the point whose coordinates are transformed, specified in user
  space coordinates.
  \param dev_point (Filled by the method) Pointer to a point containing the device space coordinates
  corresponding to point.
  \sa PdfPageView::RectToDevice
  */
  virtual void PointToDevice(PdfPoint* point, _out_ PdfDevPoint* dev_point) = 0;

  //! Transforms a rectangle's coordinates from device space to user space. 
  //! The resulting PdfDevRect will be normalized, that is, left < right and top < bottom.
  /*!
  \param rect Pointer to the rectangle whose coordinates are transformed, specified
  in device space coordinates.
  \param dev_rect (Filled by the method) Pointer to a rectangle containing the page
  space coordinates corresponding to rect.
  \sa PdfPageView::PointToPage
  */
  virtual void RectToPage(PdfDevRect* dev_rect, _out_ PdfRect* rect) = 0;

  //! Transforms a point's coordinates from device space to user space.
  /*!
  \param dev_point Pointer to the point whose coordinates are transformed, specified in device
  space coordinates.
  \param point (Filled by the method) Pointer to a point containing the user space coordinates
  corresponding to point.
  \sa PdfPageView::RectToPage
  */
  virtual void PointToPage(PdfDevPoint* dev_point, _out_ PdfPoint* point) = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdfBookmark
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pdf_PDFix_SDK*/
//!  PdfBookmark class. 
/*!
A bookmark corresponds to an outline object in a PDF document. A document outline allows the user 
to navigate interactively from one part of the document to another. 
An outline consists of a tree-structured hierarchy of bookmarks, which display the document's 
structure to the user. Each bookmark has:
A title that appears on screen.
An action that specifies what happens when the user clicks on the bookmark.
*/
struct PdfBookmark {
  //! Gets a bookmark's title.
  /*!
   \param buffer (filled by method) If the buffer is null function returns required length of string
   \param len Length of a buffer to be filled in.
   \return Number of characters written into buffer of required length.
  */
  virtual int GetTitle(_out_ wchar_t* buffer, int len) = 0;

  //! Gets a bookmark's appearance
  /*!
  \param appearance (filled by method) Pointer to a PdfBookmarkAppearance structure.
  */
  virtual void GetAppearance(PdfBookmarkAppearance* appearance) = 0;
  
  //! Gets a bookmark's action object.
  /*!
  \return The bookmark's action object or nullptr if bookmark does not have an action.
  */
  virtual PdfAction* GetAction() = 0;

  //! Gets the number of child bookmark in a parent bookmark object.
  /*!
  \return The number of children.
  \sa PdfBookmark::GetChild
  */
  virtual int GetNumChildren() = 0;

  //! Gets the requested child bookmark from a parent bookmark.
  /*!
  \param index The index of bookmark to obtain.
  \return Requested bookmark.
  \sa PdfBookmark::GetNumChildren
  */
  virtual PdfBookmark* GetChild(int index) = 0;

  //! Gets a bookmark's parent bookmark.
  /*!
  \return Parent bookmark, or null if is the root bookmark of a document.
  NOTE: If parent is null, call only PdfBookmark::GetNumChildren and PdfBookmark::GetChild methods.
  Other methods return false.
  */
  virtual PdfBookmark* GetParent() = 0;
};


////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdfNameTree
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Ps_PDFix_SDK*/
//!  PdfNameTree class.
/*!
A PdfNameTree is used to map strings to PdsObjects, just as a dictionary is used to map PdsNames
to PdsObjects. A PdfNameTree is used to store the named destination information.
*/
struct PdfNameTree {
  //! Gets the object of the name tree.
  /*!
  \return The PdsDictionary of the name tree.
  */
  virtual PdsObject* GetObject() = 0;

  //! Gets the name tree value object with the specified name.
  /*!
  \return The PdsObject value for the value.
  */
  virtual PdsObject* Lookup(const wchar_t* name) = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PsRegex
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Ps_PDFix_SDK*/
//!  PsRegex class. 
/*!
A regular expression is an object that describes a pattern of characters.
Regular expressions are used to perform pattern-matching functions on text.
It helps to recognize a logical structure in a document.
NOTE: Use Perl Regular Expression Syntax to create a new pattern.
*/
struct PsRegex {
  //! Destroys PsRegex resources.
  /*!
  \sa Pdfix::CreateRegex
  */
  virtual void Destroy() = 0;

  //! Sets a regular expression to search for.
  /*!
  \param pattern The Regular expression.
  \return true if pattern was set, false otherwise.
  \sa CPsRegex::AddPatternType, CPsRegex::Search
  \ref\n Sample RegexSetPattern
  */
  virtual bool SetPattern(const wchar_t* pattern) = 0;

  //! Searches for a match in a string. Use positions parameter to find more patterns.
  /*!
  \param text The string to be searched.
  \param position A position in the text where to start search.
  \return This method returns true if it finds a match, otherwise it returns false.
  \ref\n Sample RegexSearch
  */
  virtual bool Search(const wchar_t* text, int position) = 0;

  //! Gets a buffer containing the matched text if it finds a match, otherwise it returns 0.
  /*!
   \param buffer (filled by method) If the buffer is null function returns required length of string
   \param len Length of a buffer to be filled in.
   \return Number of characters written into buffer of required length.
  */
  virtual int GetText(_out_ wchar_t* buffer, int len) = 0;

  //! Gets a position of the matched text from the start position defined in PsRegex::Search method.
  //! NOTE: It's not a position from text buffer beginning.
  /*!
  \return Position of the matched text, otherwise it returns -1.
  */
  virtual int GetPosition() = 0;

  //! Gets a length of the matched text.
  /*!
  \return Length of the matched text, otherwise it returns 0.
  */
  virtual int GetLength() = 0;

  //! Gets the number of matched text in pattern.
  /*!
  \return Length the number of matches.
  */
  virtual int GetNumMatches() = 0;

  //! Gets the matched text by index.
  /*!
  \param index The match index to get.
   \param buffer (filled by method) If the buffer is null function returns required length of string
   \param len Length of a buffer to be filled in.
   \return Number of characters written into buffer of required length.
  */
  virtual int GetMatchText(int index, _out_ wchar_t* buffer, int len) = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PsStream
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Ps_PDFix_SDK*/
//!  PsStream class. 
/*!
A PsStream is a data stream that may be a buffer in memory, a file, or an arbitrary user-written
procedure. You typically would use an PsStream to import/export data to/from/ a PDF file.
PsStream methods allow you to open and close streams, and to read and write data.
*/
struct PsStream {
  //! Destroys PsStream resources.
  /*!
  \sa Pdfix::CreateStream
  */
  virtual void Destroy() = 0;

  //! Checks if the current position is end of stream.
  /*!
  \return The size of the stream.
  \sa PsStream::Read
  */
  virtual bool IsEof() = 0;

  //! Gets the current size of a stream.
  /*!
  \return The size of the stream.
  */
  virtual int GetSize() = 0;

  //! Reads data from PsStream into memory.     
  /*!
  \param buffer (Filled by the method) A buffer into which data is written.
  \param offset The position to start read from.
  \param size The number of bytes to read.
  \return true if the operation was successful, false otherwise.
  */
  virtual bool Read(int offset, _out_ uint8_t* buffer, int size) = 0;

  //! Writes data from a memory buffer into a stream, beginning at the offset position.
  /*!
  \param buffer A buffer holding the data that is to be written.
  The buffer must be able to hold at least count bytes.
  \param offset The position to seek.
  \param size The number of bytes to write.
  \return true if the operation was successful, false otherwise.
  */
  virtual bool Write(int offset, _in_ const uint8_t* buffer, int size) = 0;

  //! Gets the current seek position in a stream. 
  //! This is the position at which the next read or write will begin.
  /*!
  \return The current seek position.
  */
  virtual int GetPos() = 0;

  //! Flush stream data. 
  //! Synchronize the stream buffer with its controlled output sequence.
  /*!
  \return true if sucessfull. false otherwise.
  */
  virtual bool Flush() = 0;
  /*@LANG [!JAVA !CSHARP]*/
  virtual void* GetStream() = 0;
  /*@LANG []*/

  //! Gets the type of a stream.
  /*!
  \return stream type.
  */
  virtual PdfStreamType GetType() = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PsFileStream
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Ps_PDFix_SDK*/
//!  PsFileStream class. 
/*!
*/
struct PsFileStream : public PsStream {
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PsMemoryStream
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Ps_PDFix_SDK*/
//!  PsMemoryStream class. 
/*!
*/
struct PsMemoryStream : public PsStream {
  //! Expands the current size of a memory stream. 
  /*!
  \param size A new size of the stream.
  \return true if the operation was successful, false otherwise.
  */
  virtual bool Resize(int size) = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PsProcStream
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Ps_PDFix_SDK*/
//!  PsProcStream class. 
/*!
*/
struct PsCustomStream : public PsStream {
  //! Sets a user-supplied procedure to call when the read event occurs.
  /*!
  \param proc A user-supplied callback to call when the read event occurs.
  \param data A pointer to user-supplied data to pass to proc each time it is called.
  \return true if callback was set, false otherwise.
  */
  /*@LANG [!JAVA]*/
  virtual void SetReadProc(_callback_ PsStreamReadProc proc) = 0;
  /*@LANG []*/

  //! Sets a user-supplied procedure to call when the write event occurs.
  /*!
  \param proc A user-supplied callback to call when the write event occurs.
  \param data A pointer to user-supplied data to pass to proc each time it is called.
  \return true if callback was set, false otherwise.
  */
  /*@LANG [!JAVA]*/
  virtual void SetWriteProc(_callback_ PsStreamWriteProc proc) = 0;
  /*@LANG []*/

  //! Sets a user-supplied procedure to call when the the stream is destroyed.
  /*!
  \param proc A user-supplied callback to call when the stream is destroyed.
  \param data A pointer to user-supplied data to pass to proc each time it is called.
  \return true if callback was set, false otherwise.
  */
  /*@LANG [!JAVA]*/
  virtual void SetDestroyProc(_callback_ PsStreamDestroyProc proc) = 0;
  /*@LANG []*/

  //! Sets a user-supplied procedure to call when the the stream is destroyed.
  /*!
  \param proc A user-supplied callback to call when the stream is destroyed.
  \param data A pointer to user-supplied data to pass to proc each time it is called.
  \return true if callback was set, false otherwise.
  */
  /*@LANG [!JAVA]*/
  virtual void SetGetSizeProc(_callback_ PsStreamGetSizeProc proc) = 0;
  /*@LANG []*/
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdsStructElement
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pds_PDFix_SDK*/
//!  PdsStructElement class. 
/*!
PdsStructElement is the basic building block of the structure tree. It represents PDF structural
elements, which are nodes in a tree, defining a PDF document�s logical structure.
*/
struct PdsStructElement {
  //! Releases structure element's resources.
  /*!
  \param element The structure element to release.
  \sa PdsStructTree::AcquireStructElement
  */
  virtual void Release() = 0;

  //! Gets the element's structural element type. It maps an element type to another element type 
  //! if the specified element type has role mapping.
  /*!
   \param buffer (filled by method) If the buffer is null function returns required length of string
   \param len Length of a buffer to be filled in.
   \return Number of characters written into buffer of required length.
  */
  virtual int GetType(bool mapped, _out_ wchar_t* buffer, int len) = 0;

  //! Gets the actual text associated with the specified PDSElement. Returns the number of bytes 
  //! in the text or 0 if the element has no actual text or has an empty string. To check for 
  //! the existence of alternate text, check for a non-zero return value.
  /*!
   \param buffer (filled by method) If the buffer is null function returns required length of string
   \param len Length of a buffer to be filled in.
   \return Number of characters written into buffer of required length.
  */
  virtual int GetActualText(_out_ wchar_t* buffer, int len) = 0;

  //! Gets the alternate text associated with an element. 
  //! NOTE: The Alt text can be legally defined as an empty string. To differentiate between an
  //! Alt text string of zero length and no Alt text being defined, call HasAlt first.
  /*!
   \param buffer (filled by method) If the buffer is null function returns required length of string
   \param len Length of a buffer to be filled in.
   \return Number of characters written into buffer of required length.
  */
  virtual int GetAlt(_out_ wchar_t* buffer, int len) = 0;

  //! Sets the alternate text associated with an element.
  //! NOTE: The Alt text can be legally defined as an empty string. To differentiate between an
  //! Alt text string of zero length and no Alt text being defined, call HasAlt first.
  /*!
   \param buffer (filled by method) If the buffer is null function returns required length of string.
   \param len Length of a buffer to be filled in.
   \return Number of characters written into buffer of required length or 0 if the alt text is empty.
   */
  virtual bool SetAlt(const wchar_t* alt) = 0;

  //! Sets the title associated with an element.
  /*!
   \param buffer (filled by method) If the buffer is null function returns required length of string.
   \param len Length of a buffer to be filled in.
   \return Number of characters written into buffer of required length or 0 if the alt text is empty.
   */
  virtual bool SetTitle(const wchar_t* title) = 0;

  //! Gets the expanded form of an abbreviation. 
  /*!
   \param buffer (filled by method) If the buffer is null function returns required length of string
   \param len Length of a buffer to be filled in.
   \return Number of characters written into buffer of required length.
  */
  virtual int GetAbbreviation(_out_ wchar_t* buffer, int len) = 0;

  //! Returns a page number representing a page on which some or all of the content items 
  //! designated by the K entry are rendered
  /*!
  \return The page number if presented, -1 otherwise.
  */
  virtual int GetPageNumber() = 0;

  //! Gets the attribute object at a specified array index in the specified element.
  //! If there is only one attribute object(that is, there is no array of attributes), and index is
  //! zero, that attribute object is obtained.
  /*!
  \param index Index of the attribute object to obtain.
  \return Attribute object at index.
  */
  virtual PdsObject* GetAttrObject(int index) = 0;
  
  //! Associates the specified attribute object with an element.
  /*!
  \param object Attribute object to associate with element.
  */
  virtual bool AddAttrObj(PdsObject* object) = 0;

  //! Removes the specified attribute object from an element. If element does not have an
  //! attrObj attribute, this method does nothing.
  /*!
  */
  virtual void RemoveAttrObj() = 0;

  //! Gets the object corresponding to the specified element object. This method does not
  //! copy the object, but is instead the logical equivalent of a type cast
  /*!
  \return The dictionary object for the element object.
  */
  virtual PdsObject* GetElementObject() = 0;

  //! Gets the kid's object at an array index for the structure element.
  //! A PDF structural elements unlike the structure tree root�can have several different kinds
  //! of children : marked content ID, another structural element, or an object reference.   
  /*!
  \param index The index of the kid.
  \return The kid's object being accessed.
  \sa PdsStructTree::AcquireStructElement
  */
  virtual PdsObject* GetKidObject(int index) = 0;

  //! Gets the kid's type at an array index for the structure element.
  //! A PDF structural elements unlike the structure tree root can have several different kinds
  //! of children : marked content ID, another structure element, or an object object reference dictionary 
  //! denoting a PdsObject.
  /*!
  \param index The index of the kid.
  \return The type of the kid.
  */
  virtual PdfStructElementType GetKidType(int index) = 0;

  //! Returns a page number representing a page on which the kid is rendered.
  /*!
  \param index The index of the kid.
  \return The page number if presented, -1 otherwise.
  */
  virtual int GetKidPageNumber(int index) = 0;

  //! Returns a kid's MCID.
  //! Note: Call this method only in a case that PdfStructElement::GetKidType returns
  //! kPdsStructKidPageContent type. Otherwise this method it returns -1.
  /*!
  \param index The index of the kid.
  \return The kid's MCID if presented, -1 otherwise.
  */
  virtual int GetKidMcid(int index) = 0;

  //! Gets the number of attribute objects directly attached to the specified element.
  /*!
  \return Number of attribute objects directly attached to element.
  */
  virtual int GetNumAttrObjects() = 0;

  //! Gets the number of kids of the specified element.
  /*!
  \return Number of direct kids of element.
  */
  virtual int GetNumKids() = 0;

  //! Gets the immediate ancestor element of the specified element in the tree.
  //! If the element�s parent is another element, parent is set to that parent's object.
  /*!
  \param parent (filled by method) The element parent's object.
  \return Element's parent object. If the element�s parent is the structure tree root,
  return value is nullptr.
  */
  virtual PdsObject* GetParentObject() = 0;

  //! Gets the title of the specified element, returning the number of bytes in the title.
  /*!
   \param buffer (filled by method) If the buffer is null function returns required length of string
   \param len Length of a buffer to be filled in.
   \return Number of characters written into buffer of required length.
  */
  virtual int GetTitle(_out_ wchar_t* buffer, int len) = 0;

  //! Gets the ID of an element.
  //! The element identifier, a string designating this structure element.
  //! The string must be unique among all elements in the document�s structure hierarchy.
  //! The IDTree entry in the structure tree root defines the correspondence between 
  //! element identifiers and the structure elements they denote.
  /*!
   \param buffer (filled by method) If the buffer is null function returns required length of string
   \param len Length of a buffer to be filled in.
   \return Number of characters written into buffer of required length.
  */
  virtual int GetId(_out_ wchar_t* buffer, int len) = 0;
  
  //! Removes the specified kid from an element.
  /*!
  \param index The index of the kid.
  \return True if successfull, falsw othervise.
  */
  virtual bool RemoveKid(int index) = 0;
  
  //! Creates a new (but empty) PdsStructElement of specific type.
  //! CreateStructElement increments an element�s reference count. The element will not be released
  //! until the reference count is zero, or the application terminates.
  //! NOTE: After you are done using the element, release it using PdsStructElement::Release
  //! to release resources.
  /*!
  \param type The name representing the element�s type.
  \param parent The parent structure element.
  \param index Position where the kid is inserted to parents kids.
    If element currently has no kids, index is ignored.
  \return Acquired PdsStructElement.
  \sa PdsStructElement::Release
  */
  virtual PdsStructElement* CreateStructElement(const wchar_t* type, PdsStructElement* parent, int index) = 0;
  
  //! Moves the current structure element.
  /*!
  \param parent A new parent of the structure element.
  \param index Position where the element is inserted into parents kids.
    If parent element currently has no kids, index is ignored.
  \return true if element was successfully moved, false otherwise.
  */
  virtual bool SetParent(PdsStructElement* parent, int index) = 0;

  //! Inserts a reference to the specified page object as a kid into the specified element.
  //! This method automatically creates MCR objects if needed.
  /*!
  \param object The page object to insert.
  \param index Position where the page object is inserted.
  */
  virtual void AddPageObject(PdsPageObject* object, int index) = 0;

  //! Inserts a reference to the specified annotation as a kid into the specified element.
  //! This method automatically creates OBJR object.
  /*!
  \param object The annotation to insert.
  \param index Position where the annotation object is inserted.
  */
  virtual void AddAnnot(PdfAnnot* annot, int index) = 0;
  
  //! Get pointer to  the parent struct tree object.
  /*!
   */
  virtual PdsStructTree* GetStructTree() = 0;

  //! Sets the struct element type.
  /*!
   \param type The name representing the element�s type.
   */
  virtual bool SetType(const wchar_t* type) = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdsClassMap
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pds_PDFix_SDK*/
//!  PdsClassMap class. 
/*!
Associates class identifiers, which are names, with objects of type PdsAttrObject. Structural
elements maintain a list of names identifying classes to which they belong. The associated
attributes are thus shared by all structural elements belonging to a given class. There is one
class map per document, associated with the PdsStructTree.
*/
struct PdsClassMap {
  //! Gets the attribute object associated with the specified class name at an index in the class.
  //! If there is only one object and index is zero, that object is retrieved.
  /*!
  \param class_name The string of a class name for which an associated attribute objects
  is found.
  \param index Index of the desired attribute object in the class.
  \return Attribute object at index. Set to Null if
  there is no attribute object at the specified location.
  */
  virtual PdsObject* GetAttrObject(const wchar_t* class_name, int index) = 0;

  //! Gets the number of attribute objects associated with a class name.
  /*!
  \param class_name The string of a class name for which the number of associated
  attribute objects is found.
  \return Number of attribute objects associated with the class in class_name.
  */
  virtual int GetNumAttrObjects(const wchar_t* class_name) = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdsRoleMap
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pds_PDFix_SDK*/
//!  PdsRoleMap class. 
/*!
Represents mappings of structural element types present in a PDF document to standard
element types having similar uses. There is one PdsClassMap per document, associated
with the PdsStructTree.
*/
struct PdsRoleMap {
  //! Determines whether the specified PdsRoleMap provides any mapping path for two given
  //! element types.
  /*!
  \param class_name The string of a class name for which an associated attribute objects
  is found.
  \param src The string for an element type whose mapping is tested.
  \param dst The string for an element type.
  \return true if an mapping path was found, false otherwise.
  */
  virtual bool DoesMap(const wchar_t* src, const wchar_t* dst) = 0;

  //! Gets the type, if any, directly mapped in the specified PdsRoleMap for the given element
  //! type.
  /*!
   \param type The string for an element type whose mapping is found
   \param buffer (filled by method) If the buffer is null function returns required length of string
   \param len Length of a buffer to be filled in.
   \return Number of characters written into buffer of required length.
  */
  virtual int GetDirectMap(const wchar_t* type, _out_ wchar_t* buffer, int len) = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdsStructTree
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pds_PDFix_SDK*/
//!  PdsStructTree class. 
/*!
The root of the structure tree, which is a central repository for information related to a PDF
document�s logical structure. There is at most one PDSTreeRoot in each document.
*/
struct PdsStructTree {
  //! Gets the dictionary object corresponding to the structure tree.
  /*!
  \return The requested dictionary.
  */
  virtual PdsDictionary* GetObject() = 0;
  
  //! Gets the PdsClassMap object for the specified structure tree root.
  /*!
  \return The class map, if one exists, nullptr otherwise.
  */
  virtual PdsClassMap* GetClassMap() = 0;

  //! Gets the kid's object at an array index in the specified structure tree root.
  //! The immediate children of the structure tree root shall be structure elements only.
  /*!
  \param index Index of the kid to obtain.
  \return Pointer to the kid's object at index. 
  \sa PdsStructTree::AcquireStructElement
  */
  virtual PdsObject* GetKidObject(int index) = 0;

  //! Gets the number of kids of the structure tree root.
  /*!
  \param class_name The string of a class name for which an associated attribute objects
  is found.
  \return The number of kids of the structure tree root.
  */
  virtual int GetNumKids() = 0;

  //! Gets the PdsRoleMap object for the specified structure tree root.
  /*!
  \return The role map, if one exists, nullptr otherwise.
  */
  virtual PdsRoleMap* GetRoleMap() = 0;

  //! Gets a PdsStructElement from a Pds object. The struct elements is cached, 
  //! so that subsequent calls on the same object return The same PdsStructElement. 
  //! The PdsStructElement remains in the cache as long as PdsStructTree exists or
  //! PdsStructElement::Release was not called.
  //! NOTE: After you are done using the structure element, 
  //! release it using PdsStructElement::Release to release resources.
  /*!
  \param page_num The page number of the page to get. The first page is 0.
  \return The requested page.
  \sa PdsStructElement::Release
  */
  virtual PdsStructElement* AcquireStructElement(PdsObject* object) = 0;
  
  //! Removes the specified kid from the specified structure tree root.
  /*!
  \param index The index of the kid.
  \return True if successfull, false othervise.
  */
  virtual bool RemoveKid(int index) = 0;
  
  //! Creates a new (but empty) PdsStructElement of specific type.
  //! CreateStructElement increments an element�s reference count. The element will not be released
  //!  until the reference count is zero, or the application terminates.
  //! NOTE: After you are done using the element, release it using PdsStructElement::Release
  //! to release resources.
  /*!
  \param type The name representing the element�s type.
  \param index Position where the kid is inserted. If element currently has no kids, index is ignored.
  \return Acquired PdsStructElement.
  \sa PdsStructElement::Release
  */
  virtual PdsStructElement* CreateStructElement(const wchar_t* type, int index) = 0;
  
  //! Return parent PdfDoc object.
  /*!
   \sa PdfDoc::GetStructTree
   \sa PdfDoc::CreateStructTree
   */
  virtual PdfDoc* GetDoc() = 0;
  
  //! Create parent tree based on the struct tree.
  /*!
   \return True if successfull, false othervise.
   */
  virtual bool UpdateParentTree() = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PsMetadata
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Ps_PDFix_SDK*/
//!  PsMetadata class. 
/*!
PsMetadata represents metadata sctream in the pdf document.
*/
struct PsMetadata {
  //! Loads metadata from stream
  /*!
  \param stream Source stream of the metadata.
  \param format Format of the source stream. Only JSON format is supported.
  \return true if metadata was loaded successfuly
  */
  virtual bool LoadFromStream(PsStream* stream) = 0;

  //! Saves metadata to stream
  /*!
  \param stream Source stream of the metadata.
  \param format Format of the source stream. Only JSON format is supported.
  \return true if metadata was saved successfuly
  \sa PsMetadata::LoadFromStream
  */
  virtual bool SaveToStream(PsStream* stream) = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PsEvent
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pdfix_PDFix_SDK*/
//! PsEvent Class.
/*! A class to handle registers a user-supplied procedures to call when the specified event occurs. */
struct PsEvent {
  //! Get the event type.
  /*!
   \sa Pdfix::CreatePdfix
   \return The event type
   */
  virtual PdfEventType GetType() = 0;     /*!< Event type. */
  
  //! Get the document associated with the event.
  /*!
   \return The PdfDoc object or null if no document is accociated with the event
   */
  virtual PdfDoc* GetDoc() = 0;

  //! Get the page associated with the event.
  /*!
   \return The PdfPage object or null if no page is accociated with the event
   */
  virtual PdfPage* GetPage() = 0;
  
  //! Get the annotation associated with the event.
  /*!
   \return The PdfAnnot object or null if no annotation is accociated with the event
   */
  virtual PdfAnnot* GetAnnot() = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PsAuthorization
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pdfix_PDFix_SDK*/
//!  PsAuthorization class.
/*!
PsAuthorization controls the authorization state of the library.
*/
struct PsAuthorization {
  //! Save the current autorization state into a data file. .
  /*!
  \param stream PsStream where to save license data in requested format.
  \param format Format of the source stream. JSON and XML format is supported.
  \return true if succeeded, false otherwise.
  */
  virtual bool SaveToStream(PsStream* stream, PsDataFormat format) = 0;
  
  //! Returns authorization state.
  /*!
  \return true if PDFix was authorized, false othervise.
  */
  virtual bool IsAuthorized() = 0;
  
  //! Returns authorization state of the platform.
  /*!
  \return true if PDFix was authorized for this platform, false othervise.
  */
  virtual bool IsAuthorizedPlatform(PdfAuthPlatform platform)  = 0;

  //! Returns authorization state of the version.
  /*!
  \return true if PDFix was authorized for this option, false othervise.
  */
  virtual bool IsAuthorizedOption(PdfAuthOption option) = 0;
  
  //! Returns authorization type.
  /*!
  \return authorization type.
  */
  virtual PdfAuthorizationType GetType() = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PsAccountAuthorization
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pdfix_PDFix_SDK*/
//!  PsAccountAuthorization class.
/*!
PsAccountAuthorization controls the authorization of the library using a name and serial key.
*/
struct PsAccountAuthorization : PsAuthorization {
  //! Authorizes Pdfix using an email and the license key.
  /*!
  \return true if Pdfix was authorized successfuly, false otherwise.
  */
  virtual bool Authorize(const wchar_t* email, const wchar_t* serial_number) = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PsStandardAuthorization
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pdfix_PDFix_SDK*/
//!  PsStandardAuthorization class.
/*!
PsStandardAuthorization controls the authorization of the library using an activation code.
*/
struct PsStandardAuthorization : PsAuthorization {
  //! Activates the library using the activation license key. The method requires internet access.
  /*!
  \param serial_number The license key.
  \return true if the library was activated successfuly, false otherwise.
  */
  virtual bool Activate(const wchar_t* serial_number) = 0;

  //! Deactivates the library. The method requires internet access.
  /*!
  \return true if the library was deactivated successfuly, false otherwise.
  */
  virtual bool Deactivate() = 0;

  //! Updates the autorization state. The method requires internet access .
  /*!
  \return true if the authorization state was updated successfuly, false otherwise.
  */
  virtual bool Update() = 0;

  //! Reset the autorization and delete all local data.
  /*!
  \return true if the authorization was reset successfuly, false otherwise.
  */
  virtual bool Reset() = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PsCommand
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pdfix_PDFix_SDK*/
//!  PsCommand class.
/*!
A PsCommand represents an action that the user can perform on the current document.
Specifically, a PsCommand represents a command which can be added to a command sequence and executed
either interactively or via batch processing.
*/
struct PsCommand {
  //! Destroys the specified command and its associated resources.
  /*!
  \sa Pdfix::CreateCommand
  */
  virtual void Destroy() = 0;

  //! Destroys the specified command and its associated resources.
  /*!
  \param cancel_proc Callback to check for canceling operations.
  \param cancel_data Pointer to client data for the cancel procedure.
  \return The current status of cmd.
  */
  virtual PsCommandStatus Execute(_callback_ PdfCancelProc cancel_proc, void* cancel_data) = 0;

  //! Imports a command configuration from a stream. The configuration settings will not be updated
  //! if the command is not in a ready state.Only JSON format is supported.
  /*!
  \param stream Source stream of the metadata.
  \param format Format of the source stream. Only JSON format is supported./
  \return true if the command configuration was loaded successfuly.
  */
  virtual bool LoadFromStream(PsStream* stream, PsDataFormat format) = 0;

  //! Exports command configuration into a stream. Only JSON format is supported.
  /*!
  \param stream Source stream of the metadata.
  \param format Format of the source stream. Only JSON format is supported.
  \return true if the the command configuration was exported successfuly.
  */
  virtual bool SaveToStream(PsStream* stream, PsDataFormat format) = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PsImage
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Ps_PDFix_SDK*/
//!  PsImage class.
/*!
PsImage contains an image data in an internal format.
*/
struct PsImage {
  //! Destroys PsImage resources.
  /*!
  \sa Pdfix::CreateImage
  */
  virtual void Destroy() = 0;

  //! Saves the image into a file.
  /*!
  \param path Absolute file path where the image should be saved.
  \param params PdfImageParams specifying the image format and quality.
  \return true if succeeded, false otherwise.
  \sa PdfImageFormat
  */
  virtual bool Save(const wchar_t* path, PdfImageParams* params) = 0;

  //! Saves a clip of the image into a file.
  /*!
  \param path Absolute file path where the image should be saved.
  \param params PdfImageParams specifying the image format and quality.
  \param dev_rect Clip area of the image that needs to be saved.
  \return true if succeeded, false otherwise.
  \sa PdfImageFormat
  */
  virtual bool SaveRect(const wchar_t* path, PdfImageParams* params, PdfDevRect* dev_rect) = 0;

  //! Saves the image into a stream.
  /*!
  \param stream PsStream where to save image data in requested format.
  \param params PdfImageParams specifying the image format and quality.
  \return true if succeeded, false otherwise.
  \sa PdfImageFormat
  */
  virtual bool SaveToStream(PsStream* stream, PdfImageParams* params) = 0;

  //! Saves a clip of the image into a stream.
  /*!
  \param stream PsStream where to save image data in requested format.
  \param params PdfImageParams specifying the image format and quality.
  \param dev_rect Clip area of the image that needs to be saved.
  \return true if succeeded, false otherwise.
  \sa PdfImageFormat
  */
  virtual bool SaveRectToStream(PsStream* stream, PdfImageParams* params, PdfDevRect* dev_rect) = 0;

  //! Gets a color of the image point.
  /*!
  \param point A point which color is requested.
  \param color(filled by method) RGB color of the image point.
  */
  virtual void GetPointColor(PdfDevPoint* point, _out_ PdfRGB* color) = 0;

  //! Saves the image data in the format of an image into a stream.
  /*!
  \param stream PsStream where to save image data in requested format.
  \return true if succeeded, false otherwise.
  */
  virtual bool SaveDataToStream(PsStream* stream) = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class Pdfix
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pdfix_PDFix_SDK*/
//!  Pdfix class. 
 /*!
Pdfix loads and unloads library. It initialized all necessary resources and also takes care
about releasing it.
*/
struct Pdfix {
  //! Destroys Pdfix resources.
  /*!
  \sa Pdfix::CreatePdfix
  */
  virtual void Destroy() = 0;
  
  //! Gets the current PsAuthorization object.
  /*!
  \return the PsAuthorization object.
  */
  virtual PsAuthorization* GetAuthorization() = 0;

  //! Gets the PsStandardAuthorization object.
  /*!
  \return the PsStandardAuthorization object.
  */
  virtual PsStandardAuthorization* GetStandardAuthorization() = 0;

  //! Gets the PsAccountAuthorization object.
  /*!
  \return the PsAuthorization object.
  */
  virtual PsAccountAuthorization* GetAccountAuthorization() = 0;

  //! Returns the latest error type from the library. The error type is set each time,
  //! when any library method fails.
  /*!
  \return The last error type.
  */
  virtual int GetErrorType() = 0;

  //! Returns the latest error message from the library. The error message is set each time,
  //! when any library method fails.
  /*!
  \return The last error, empty string otherwise.
  */
  virtual const char* GetError() = 0;

  //! Sets the latest error message to the library.
  /*!
  \param type The last error type.
  \param error The last error.
  */
  virtual void SetError(int type, const char* error) = 0;

  //! Returns the major version. This is the first integer in a version number
  //! and is increased whenever significant changes are made.
  /*!
  \return The major version number.
  */
  virtual int GetVersionMajor() = 0;

  //! Returns the minor version. This is the second integer in a compound version number.
  //! This is normally set to 0 after each major release and increased whenever 
  //! smaller features or significant bug fixes have been added.
  /*!
  \return The minor version number.
  */
  virtual int GetVersionMinor() = 0;

  //! Returns the patch version. The (optional) third integer is the patch number, 
  //! sometimes also called the revision number.
  //! Changes in patch number should imply no change to the actual API interface, 
  //! only changes to the behavior of the API.
  /*!
  \return The patch version number.
  */
  virtual int GetVersionPatch() = 0;

  //! Creates a new document. The only object in the document will be a Catalog.
  //! After the document is created, at least one page must be added using
  //! PdfDoc::CreatePage or PdfDoc::InsertPages.
  //! NOTE: You must call PdfDoc::Close once for every successful create.
  /*!
  \return The newly created document or null.
  \sa PdfDoc::Close
  */
  virtual PdfDoc* CreateDoc() = 0;

  //! Opens the specified document. If the document is already open, 
  //! returns a reference to the already opened PdfDoc.
  //! NOTE: You must call PdfDoc::Close once for every successful open. 
  /*!
  \param path Path to the file.
  \param password File password.
  \return The newly created document or null.
  \sa PdfDoc::Close
  */
  virtual PdfDoc* OpenDoc(const wchar_t* path, const wchar_t* password) = 0;

  //! Opens the specified document from memory. If the document is already open, 
  //! returns a reference to the already opened PdfDoc.
  //! You must call PdfDoc::Close once for every successful open. 
  /*!
  \param stream PsStream object.
  \param password File password.
  \return The newly created document or null.
  \sa PdfDoc::Close
  */
  virtual PdfDoc* OpenDocFromStream(PsStream* stream, const wchar_t* password) = 0;

  //! Creates a new PdfDigSig object.
  //! Call PdfDigSig::Destroy method to release resources. 
  /*!
  \return Initialized PdfDigSig object.
  \sa PdfDigSig::Destroy
  */
  virtual PdfDigSig* CreateDigSig() = 0;

#if defined _WIN32 && defined _MSC_VER
  //! Creates a new PdfCertDigSig object.
  //! Call PdfDigSig::Destroy method to release resources. 
  /*!
  \return Initialized PdfCertDigSig object.
  \sa PdfDigSig::Destroy
  */
  virtual PdfCertDigSig* CreateCertDigSig() = 0;
#endif

  //! Creates a new PdfCustomDigSig object.
  //! Call PdfDigSig::Destroy method to release resources. 
  /*!
  \return Initialized PdfCustomDigSig object.
  \sa PdfDigSig::Destroy
  */
  /*@LANG [!JAVA !CSHARP]*/
  virtual PdfCustomDigSig* CreateCustomDigSig() = 0;
  /*@LANG []*/

  //! Creates a new PsRegex object. 
  //! Call PsRegex::Destroy to release all regex resources. 
  /*!
  \return Initialized PsRegex object.
  \sa PsRegex::Destroy
  */
  virtual PsRegex* CreateRegex() = 0;

  //! Creates a new read-only or write PsStream from PsFile. 
  //! Call PsStream::Destroy to release all stream resources. 
  /*!
  \param path Path to the file that PsStream needs to be created from.
  \param mode File open mode. 
  \return Initialized PsStream object.
  \sa PsStream::Destroy
  */
  virtual PsFileStream* CreateFileStream(const wchar_t* path, PsFileMode mode) = 0;

  //! Creates a new mempry operating PsStream. 
  //! Call PsStream::Destroy to release all stream resources. 
  /*!
  \return Initialized PsStream object.
  \sa PsStream::Destroy
  */
  virtual PsMemoryStream* CreateMemStream() = 0;

  //! Creates a new read-only PsStream with arbitrary data-producing procedure. 
  //! Call PsStream::Destroy to release all stream resources. 
  /*!
  \param read_proc Data producing procedure
  \param proc_stm Pointer to user object which is provided to provided PsStreamProc
  \return Initialized PsStream object.
  \sa PsStream::Destroy
  */
  /*@LANG [!JAVA]*/
  virtual PsCustomStream* CreateCustomStream(_callback_ PsStreamReadProc read_proc, void* client_data) = 0;
  /*@LANG []*/

  //! Registers a user-supplied procedure to call when the specified event occurs.
  /*!
  \param type The event type.
  \param proc A user-supplied callback to call when the event occurs.
  \param data A pointer to user-supplied data to pass to proc each time it is called.
  \return true if event was registered, false otherwise.
  \ref\n Sample RegisterEvent
  */
  /*@LANG [!JAVA]*/
  virtual bool RegisterEvent(PdfEventType type, _callback_ PdfEventProc proc, void* data) = 0;
  /*@LANG []*/
  //! Unregisters a user-supplied procedure to call when the specified event occurs.
  //! To un-register, you must use same type, proc and data that were used when 
  //! the event was registered using Pdfix::RegisterEvent.
  /*!
  \param type The registered event type.
  \param proc A registered user-supplied callback.
  \param data A pointer to registered user-supplied data.
  \return true if event was registered, false otherwise.
  */
  /*@LANG [!JAVA]*/
  virtual bool UnregisterEvent(PdfEventType type, PdfEventProc proc, void* data) = 0;
  /*@LANG []*/

  //! Creates a new PsImage object. 
  //! Call PsImage::Destroy to release image resources. 
  /*!
  \param width Requested image width.
  \param height Requested image heught.
  \param format Requested image DIB format.
  \return Initialized PsImage object.
  \sa PsImage::Destroy
  */
  virtual PsImage* CreateImage(int width, int height, PsImageDIBFormat format) = 0;
  
  //! Register plugin by name.
  //! Method to register plugin by name to allow other plugins to access it's functionality
  /*!
   \param plugin The PdfixPlugin object.
   \param name Plugin registration name.
   \sa Pdfix::GetPluginByName
   \reeturn truee if the plugin registration was successfull, false othrewise
  */
  virtual bool RegisterPlugin(PdfixPlugin* plugin, const wchar_t* name) = 0;
  
  //! Get plugin by name.
  //! Method to retrieve the plugin by name.
  /*!
   \param name Plugin registration name
   \sa Pdfix::GetPluginByName
  */
  virtual PdfixPlugin* GetPluginByName(const wchar_t* name) = 0;
  
  //! Get the object of current event.
  //! Method to retrieve the event object related with the notification.
  /*!
   \return Initialized PsEvent object
   */
  virtual PsEvent* GetEvent() = 0;
  
  //! Creates a new command of the specified type.
  //! Call PsCommand::Destroy to destroy the specified command and its associated resources.
  /*!
  \param name The new command's type name.
  \return Initialized PsCommand object.
  \sa PsCommand::Destroy
  */
  virtual PsCommand* CreateCommand(const wchar_t* name) = 0;
};

/*! \ingroup Pdfix_PDFix_SDK*/
//! Gets a Pdfix object. You virtual  call GetPdfix to initialize Pdfix library. 
//! Call Pdfix::Destroy to release all library resources. 
/*!
\return Initialized Pdfix object.
\sa Pdfix::Destroy
\ref\n Sample InitializePdfix
*/
PDFIXEXPORT
Pdfix* GetPdfix();

////////////////////////////////////////////////////////////////////////////////////////////////////
// Class PdfixPlugin
////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \ingroup Pdfix_PDFix_SDK*/
//!  PdfixPlugin virtual class. 
/*!
PdfixPlugin loads and unloads Pdfix plugin. It initialized all necessary resources and
also takes care about releasing it.
*/
struct PdfixPlugin {
  //! Destroys Pdfix plugin resources.
  /*!
  \sa Pdfix::CreatePdfix
  */
  virtual void Destroy() = 0;

  //! Authorizes Pdfix.
  /*!
  \return true if Pdfix was authorized successfuly, false otherwise.
  */
  virtual bool Initialize(Pdfix* pdfix) = 0;

  //! Returns the major version of the plugin. This is the first integer in a version number
  //! and is increased whenever significant changes are made.
  /*!
  \return The major version number.
  */
  virtual int GetVersionMajor() = 0;

  //! Returns the minor version of the plugin. This is the second integer in a compound version number.
  //! This is normally set to 0 after each major release and increased whenever 
  //! smaller features or significant bug fixes have been added.
  /*!
  \return The minor version number.
  */
  virtual int GetVersionMinor() = 0;

  //! Returns the patch version of the plugin. The (optional) thirdinteger is the patch number,
  //! sometimes also called the revision number.
  //! Changes in patch number should imply no change to the actual API interface, 
  //! only changes to the behavior of the API.
  /*!
  \return The patch version number.
  */
  virtual int GetVersionPatch() = 0;
  
  //! Returns the major version of the Pdfix SDK with which the plugin was built.
  /*!
   \return The major version number.
   */
  virtual int GetPdfixVersionMajor() = 0;
  
  //! Returns the minor version of the Pdfix SDK with which the plugin was built.
  //! Method should return the number defined as PDFIX_VERSION_MINOR
  /*!
   \return The minor version number.
   */
  virtual int GetPdfixVersionMinor() = 0;
  
  //! Returns the patch version of the Pdfix SDK with which the plugin was built.
  //! Method should return the number defined as PDFIX_VERSION_MAJOR
  /*!
   \return The patch version number.
   */
  virtual int GetPdfixVersionPatch() = 0;

  //! Returns the Pdfix instance.
  //! Method should return the number defined as PDFIX_VERSION_PATCH
  /*!
  \return The Pdfix instance.
  */
  virtual Pdfix* GetPdfix() = 0;
};

/*##END##*/

#endif
