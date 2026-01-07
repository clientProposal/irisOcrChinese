/**
 * \file EnumDefinitions.h
 * \brief Source file grouping enum definitions for iDRS SDK.
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _EnumDefinitions_h_
#define _EnumDefinitions_h_

#include <idrskrn.h>


namespace IDRS
{
  /*
   * Generic Enums
   */

  /**
   * \brief Position to which offset is added when performing a Seek operation on a IByteStream.
   */
  enum class SeekPosition
  {
    /**
     * \brief Seek from the beginning. (The origin is the beginning of the stream)
     *
     * \internal
     * c_api_name SeekPositionBegin
     * \endinternal
     */
    Begin = 0,
    /**
     * \brief Seek from the current position. (The origin is the current position in the stream)
     *
     * \internal
     * c_api_name SeekPositionCurrent
     * \endinternal
     */
    Current = 1,
    /**
     * \brief Seek from the end. (The origin is the end of the stream)
     *
     * \internal
     * c_api_name SeekPositionEnd
     * \endinternal
     */
    End = 2,
  };
  /**
   * \brief Filestream open modes
   */
  enum class FileStreamMode
  {
    /**
     * \brief Read mode
     *
     * \internal
     * c_api_name FileStreamModeRead
     * \endinternal
     */
    Read,
    /**
     * \brief Write mode
     *
     * \internal
     * c_api_name FileStreamModeWrite
     * \endinternal
     */
    Write,
    /**
     * \brief Append mode
     *
     * \internal
     * c_api_name FileStreamModeAppend
     * \endinternal
     */
    Append,
    /**
     * \brief Read and Write mode. Allows read, write and seek.
     *
     * \internal
     * c_api_name FileStreamModeReadWrite
     * \endinternal
     */
    ReadWrite,
  };
  /**
   * \brief The SeverityLevel defines the severity level of the events
   * that are logged and can be received by an integrator, via registration of an implementation of the ILogger interface either
   * on a CIDRS instance (for instance-based operations) or CIDRSSetup (for static operations).
   */
  enum class SeverityLevel
  {
    /**
     * \brief This level describes events that will be logged from iDRS as info messages,
     * giving information to user about the progress and the status of an operation
     *
     * \internal
     * c_api_name SeverityLevelInfo
     * \endinternal
     */
    Info,
    /**
     * \brief This level describes events that will be logged from iDRS as warning messages,
     * giving more information to user when a warning occurs during an operation
     *
     * \internal
     * c_api_name SeverityLevelWarning
     * \endinternal
     */
    Warning,
    /**
     * \brief This level describes events that will be logged from iDRS as error messages,
     * giving more information to user when an error occurs during an operation
     *
     * \internal
     * c_api_name SeverityLevelError
     * \endinternal
     */
    Error
  };

  /*
   * Enums related to Page Content representation
   */

  /**
   * \brief GraphicShapeType contains the types of graphic shapes handled by iDRS
   */
  enum class GraphicShapeType
  {
    /**
     * \brief Line shape type (i.e. segment)
     *
     * \internal
     * c_api_name GraphicShapeTypeLine
     * \endinternal
     */
    Line,
  };

  /**
   * \brief Enumeration allowing to specify a bookmark's display mode.
   *
   * \see CPageBookmark::SetDisplayMode() for more information.
   *
   * \remarks Bookmarks display mode is taken into account only for PDF output.
   */
  enum class BookmarkDisplayMode : int
  {
    /**
     * \brief The whole page will be fit to the view.
     *
     * \internal
     * c_api_name BookmarkDisplayModePage
     * \endinternal
     */
    Page,
    /**
     * \brief The page width will be fit to the view, and the top of the view set to the destination's top.
     *
     * \internal
     * c_api_name BookmarkDisplayModePageWidth
     * \endinternal
     */
    PageWidth,
    /**
     * \brief The page height will be fit to the view, and the left of the view set to the destination's left.
     *
     * \internal
     * c_api_name BookmarkDisplayModePageHeight
     * \endinternal
     */
    PageHeight,
    /**
     * \brief The page's content will be fit to the view.
     *
     * \internal
     * c_api_name BookmarkDisplayModeContent
     * \endinternal
     */
    Content,
    /**
     * \brief The page's content width will be fit to the view, and the top of the view set to the destination's top.
     *
     * \internal
     * c_api_name BookmarkDisplayModeContentWidth
     * \endinternal
     */
    ContentWidth,
    /**
     * \brief The page's content height will be fit to the view, and the left of the view set to the destination's left.
     *
     * \internal
     * c_api_name BookmarkDisplayModeContentHeight
     * \endinternal
     */
    ContentHeight,
    /**
     * \brief The destination's rectangle will be fit to the view.
     *
     * \internal
     * c_api_name BookmarkDisplayModeRectangle
     * \endinternal
     */
    Rectangle,
    /**
     * \brief The view will be positioned according to the destination's top and left coordinates, and the magnification
     * level set to the bookmark's ZoomFactor property.
     *
     * \internal
     * c_api_name BookmarkDisplayModeZoom
     * \endinternal
     */
    Zoom,
  };
  /**
   * \brief Flags for describing a Pdf Metadata Resource type
   */
  enum class PdfCustomMetadataResourceType
  {
    /**
     * \brief Container type
     *
     * \internal
     * c_api_name PdfCustomMetadataResourceTypeContainer
     * \endinternal
     */
    Container = 0,
    /**
     * \brief Property list type
     *
     * \internal
     * c_api_name PdfCustomMetadataResourceTypePropertyList
     * \endinternal
     */
    PropertyList = 1
  };

  /*
   * Enums related to Imaging and Compression
   */

   /**
    * \brief The image color modes handles by iDRS.
    *
    * The iDRS is able to process three different color modes:
    * <ul>
    *   <li> black and white,
    *   <li> greyscale,
    *   <li> color.
    * </ul>
    *
    */
  enum class ColorMode : int
  {
    /**
     * \brief Color mode is not known yet
     *
     * This color mode is an indication that the image is not yet initialized or some error has occured.
     * Please check the documentation of the method retrieving this value as color mode
     *
     * \internal
     * c_api_name ColorModeUnknown
     * \endinternal
     */
    Unknown,
    /**
     * \brief Black and white images.
     *
     * In iDRS, black and white images are 1 bit per pixels, the lines are aligned on 32 bits.
     *
     * In other words, for a black and white image, the number of bytes per lines is a multiple of 4.
     *
     * \internal
     * c_api_name ColorModeBlackAndWhite
     * \endinternal
     */
    BlackAndWhite,
    /**
     * \brief Greyscale images.
     *
     * In iDRS, greyscale images are 8 bits per pixels, lines are not aligned.
     *
     * This means that for a greyscale image, the number of bytes per lines is equal to the width in pixels of the image.
     *
     * \internal
     * c_api_name ColorModeGreyscale
     * \endinternal
     */
    Greyscale,
    /**
     * \brief Color images.
     *
     * In iDRS, color images are 24 bits per pixels, lines are not aligned.
     *
     * This means that for a color image, the number of bytes per lines is equal to 3 times the width in pixels of the image.
     *
     * \internal
     * c_api_name ColorModeColor
     * \endinternal
     */
    Color
  };

  /**
   * \brief Enumeration allowing to choose the target ratio between output size and image compression quality.
   */
  enum class CompressionQuality
  {
    /**
     * \brief Minimal size
     *
     * \internal
     * c_api_name CompressionQualityMinimalSize
     * \endinternal
     */
    MinimalSize = 0,
    /**
     * \brief Very small size
     *
     * \internal
     * c_api_name CompressionQualityVerySmallSize
     * \endinternal
     */
    VerySmallSize = 1,
    /**
     * \brief Small size
     *
     * \internal
     * c_api_name CompressionQualitySmallSize
     * \endinternal
     */
    SmallSize = 2,
    /**
     * \brief Favor size over quality
     *
     * \internal
     * c_api_name CompressionQualityFavorSizeOverQuality
     * \endinternal
     */
    FavorSizeOverQuality = 3,
    /**
     * \brief Medium
     *
     * \internal
     * c_api_name CompressionQualityMedium
     * \endinternal
     */
    Medium = 4,
    /**
     * \brief Favor quality over size
     *
     * \internal
     * c_api_name CompressionQualityFavorQualityOverSize
     * \endinternal
     */
    FavorQualityOverSize = 5,
    /**
     * \brief High quality
     *
     * \internal
     * c_api_name CompressionQualityHighQuality
     * \endinternal
     */
    HighQuality = 6,
    /**
     * \brief Very high quality
     *
     * \internal
     * c_api_name CompressionQualityVeryHighQuality
     * \endinternal
     */
    VeryHighQuality = 7,
    /**
     * \brief Maximal quality
     *
     * \internal
     * c_api_name CompressionQualityMaximalQuality
     * \endinternal
     */
    MaximalQuality = 8,
  };
  /**
   * \brief Enumeration allowing to choose the target ratio between compression performance and output size.
   */
  enum class CompressionLevel
  {
    /**
     * \brief Performs compression with maximum focus on speed.
     *
     * \remarks For PNG output, it corresponds to deflate level 1.
     *
     * \internal
     * c_api_name CompressionLevelMaximumPerformance
     * \endinternal
     */
    MaximumPerformance = 1,
    /**
     * \brief Performs compression with very high focus on speed.
     *
     * \remarks For PNG output, it corresponds to deflate level 2.
     *
     * \internal
     * c_api_name CompressionLevelVeryHighPerformance
     * \endinternal
     */
    VeryHighPerformance = 2,
    /**
     * \brief Performs compression with high focus on speed.
     *
     * \remarks For PNG output, it corresponds to deflate level 3.
     *
     * \internal
     * c_api_name CompressionLevelHighPerformance
     * \endinternal
     */
    HighPerformance = 3,
    /**
     * \brief Performs compression favoring speed.
     *
     * \remarks For PNG output, it corresponds to deflate level 4.
     *
     * \internal
     * c_api_name CompressionLevelFavorPerformance
     * \endinternal
     */
    FavorPerformance = 4,
    /**
     * \brief Performs compression favoring size.
     *
     * \remarks For PNG output, it corresponds to deflate level 5.
     *
     * \internal
     * c_api_name CompressionLevelMedium
     * \endinternal
     */
    Medium = 5,
    /**
     * \brief Performs compression with balance between size and speed.
     *
     * \remarks For PNG output, it corresponds to deflate level 6. This is the default value.
     *
     * \internal
     * c_api_name CompressionLevelFavorCompression
     * \endinternal
     */
    FavorCompression = 6,
    /**
     * \brief Performs compression with high focus on size.
     *
     * \remarks For PNG output, it corresponds to deflate level 7.
     *
     * \internal
     * c_api_name CompressionLevelHighCompression
     * \endinternal
     */
    HighCompression = 7,
    /**
     * \brief Performs compression with very high focus on size.
     *
     * \remarks For PNG output, it corresponds to deflate level 8.
     *
     * \internal
     * c_api_name CompressionLevelVeryHighCompression
     * \endinternal
     */
    VeryHighCompression = 8,
    /**
     * \brief Performs compression with maximum focus on size.
     *
     * \remarks For PNG output, it corresponds to deflate level 9.
     *
     * \warning Note that compression level may have very low impact on size, for significant processing time increase.
     *
     * \internal
     * c_api_name CompressionLevelMaximumCompression
     * \endinternal
     */
    MaximumCompression = 9,
  };
  /**
   * \brief Detection mode for loading PDF black and white pages.
   *
   * When rasterizing a PDF page, black and white pages will become greyscale due to image smoothing (which improves image quality).
   * In order to avoid this, extra computation can be performed in order to detect original black and white pages and restore
   * original color mode.
   */
  enum class PdfInputBlackAndWhiteDetection
  {
    /**
     * \brief No detection
     *
     * Black and white pages will be loaded in greyscale; image visual aspect will be better and OCR generally better, but
     * will generate larger output files.
     *
     * \internal
     * c_api_name PdfInputBlackAndWhiteDetectionDisabled
     * \endinternal
     */
    Disabled = 0,
    /**
     * \brief Fast detection
     *
     * The PDF page will be inspected and loaded as black and white if containing only BW images. Any other cases will
     * generate a greyscale image.
     *
     * \internal
     * c_api_name PdfInputBlackAndWhiteDetectionFast
     * \endinternal
     */
    Fast = 1,
    /**
     * \brief Complete detection
     *
     * The PDF page raster will be analyzed in details to detect black and white content. This mode is the slowest but the most accurate.
     *
     * \internal
     * c_api_name PdfInputBlackAndWhiteDetectionAccurate
     * \endinternal
     */
    Accurate = 2,
  };

  /*
   * Enums related to Preprocessing
   */

  /**
   * \brief The types of binarization available.
   */
  enum class BinarizationType
  {
    /**
     * \brief Threshold binarization using a global threshold value provided by the integrator.
     *
     * \internal
     * c_api_name BinarizationTypeFixedThreshold
     * \endinternal
     */
    FixedThreshold,
    /**
     * \brief Threshold binarization using a global threshold value automatically computed based on the processed image.
     *
     * \internal
     * c_api_name BinarizationTypeAutomaticThreshold
     * \endinternal
     */
    AutomaticThreshold,
    /**
     * \brief Adaptive binarization using varying thresholds for different regions of the image.
     * 
     * \remarks iDRS adaptive binarization is specifically fine-tuned to produce images suitable for OCR afterwards, which may not be the case of other algorithms
     * (for instance binarizations embedded in MFPs).
     *
     * \remarks This binarization algorithm is slower than FixedThreshold and AutomaticThreshold, but gives the best output in most scenarios.
     *
     * \internal
     * c_api_name BinarizationTypeAdaptive
     * \endinternal
     */
    Adaptive,
  };

  /**
   * \brief The despeckling type.
   */
  enum class DespeckleType
  {
    /**
     * \brief Remove black speckles.
     *
     * \internal
     * c_api_name DespeckleTypeBlack
     * \endinternal
     */
    Black,
    /**
     * \brief Remove white speckles.
     *
     * \internal
     * c_api_name DespeckleTypeWhite
     * \endinternal
     */
    White,
    /**
     * \brief Remove both black and white speckles.
     *
     * \internal
     * c_api_name DespeckleTypeAll
     * \endinternal
     */
    All,
  };

  /**
   * The blank image detection modes.
   */
  enum class BlankImageDetectionMode
  {
    /**
     * \brief Fast
     *
     * The blank iame detection Fast mode uses basic detection algorithm,
     * which will result in a near-immediate answer, at the cost of possible
     * incorrect answer for some specific border cases.
     *
     * This detection mode can be used when processing speed is crucial, and
     * image differentiation is clear ("blank" pages are full white, and "non-blank"
     * images contains several lines of text).
     *
     * This is the default mode when instantiating a CBlankImageDetection object.
     *
     * \internal
     * c_api_name BlankImageDetectionModeFast
     * \endinternal
     */
    Fast,
    /**
     * \brief Advanced
     *
     * The blank image detection Advanced mode performs extra preprocessing and enhancement
     * steps on the provided images, in order to get reliable results according to the provided
     * sensitivity. This mode will take more processing time than the Fast mode, but can
     * more successfully categorize difficult cases, like damaged blank paper or pages with very
     * few characters.
     *
     * This detection mode can be used when detection accuracy is more important than
     * processing speed.
     *
     * \internal
     * c_api_name BlankImageDetectionModeAdvanced
     * \endinternal
     */
     Advanced,
  };
  /**
   * The blank image detection sensitivity.
   */
  enum class BlankImageDetectionSensitivity
  {
    /**
     * \brief Strongly favor blank sensitivity will try to consider as much as possible images as blank.
     *
     * It can be interesting in cases where it is better to not miss any blank images, even if that can lead to some misdetection of
     * images with actual content still considered as blank.
     * 
     * \internal
     * c_api_name BlankImageDetectionSensitivityStronglyFavorBlank
     * \endinternal     
     */
    StronglyFavorBlank,
    /**
     * \brief Favor blank sensitivity will tend to detect more blank pages when processing border cases like damaged paper.
     *
     * \internal
     * c_api_name BlankImageDetectionSensitivityFavorBlank
     * \endinternal
     */
    FavorBlank,
    /**
     * \brief The Balanced sensitivity will neither favor blank, nor not-blank detections.
     *
     * It is the mode which is expected to reach the highest accuracy overall.
     *
     * \remarks This is the default value.
     *
     * \internal
     * c_api_name BlankImageDetectionSensitivityBalanced
     * \endinternal
     */
    Balanced,
    /**
     * \brief Favor not-blank sensitivity will tend to detect less blank images when processing border cases like pages with very little content (for instance just a page number).
     *
     * \internal
     * c_api_name BlankImageDetectionSensitivityFavorNotBlank
     * \endinternal
     */
    FavorNotBlank,
    /**
     * \brief Strongly favor not-blank sensitivity will try to consider as much as possible images as not-blank.
     *
     * It can be interesting in cases where it is crucial not to falsely detect blank images, for instance if blank pimages are discarded afterwards.
     *
     * \internal
     * c_api_name BlankImageDetectionSensitivityStronglyFavorNotBlank
     * \endinternal
     */
    StronglyFavorNotBlank,
  };

  /**
   * \brief The image source types iDRS can identify.
   */
  enum class ImageSource
  {
    /**
     * \brief The source of the image could not be identified.
     *
     * \internal
     * c_api_name ImageSourceUnknown
     * \endinternal
     */
    Unknown,
    /**
     * \brief The image is likely to have been created by a scanner device.
     *
     * \internal
     * c_api_name ImageSourceScanner
     * \endinternal
     */
    Scanner,
    /**
     * \brief The image is likely to have been created by a camera device.
     *
     * \internal
     * c_api_name ImageSourceCamera
     * \endinternal
     */
    Camera,
  };

  /*
   * Enums related to Document Output
   */

  /**
   * \brief Definition of all output formats supported by the iDRS.
   */
  enum class OutputFormat
  {
    /**
     * \brief Text output format
     *
     * \internal
     * c_api_name OutputFormatText
     * \endinternal
     */
    Text,
    /**
     * \brief HTML output format
     *
     * \internal
     * c_api_name OutputFormatHtml
     * \endinternal
     */
    Html,
    /**
     * \brief RTF output format
     *
     * \internal
     * c_api_name OutputFormatRtf
     * \endinternal
     */
    Rtf,
    /**
     * \brief PDF output format
     *
     * \internal
     * c_api_name OutputFormatPdf
     * \endinternal
     */
    Pdf,
    /**
     * \brief Open document Text output format
     *
     * \internal
     * c_api_name OutputFormatOdt
     * \endinternal
     */
    Odt,
    /**
     * \brief DOCX output format
     *
     * \internal
     * c_api_name OutputFormatDocx
     * \endinternal
     */
    Docx,
    /**
     * \brief XLSX output format
     *
     * \internal
     * c_api_name OutputFormatXlsx
     * \endinternal
     */
    Xlsx,
    /**
     * \brief EPUB output format
     *
     * \internal
     * c_api_name OutputFormatEpub
     * \endinternal
     */
    Epub,
    /**
     * \brief Powerpoint presentation output format
     *
     * \internal
     * c_api_name OutputFormatPptx
     * \endinternal
     */
    Pptx,
    /**
     * \brief XML output format
     *
     * \internal
     * c_api_name OutputFormatXml
     * \endinternal
     */
    Xml,
  };
  /**
   * \brief Definition of page layouts available for word processor and HTML outputs.
   */
  enum class PageLayout
  {
    /**
     * \brief Layout of the input pages is not retained, and all elements
     *        are written as body text in reading order.
     *
     * \internal
     * c_api_name PageLayoutNoLayout
     * \endinternal
     */
    NoLayout,
    /**
     * \brief Layout of the input pages will be reproduced as closely as
     *        possible with body text and page columns, using frames only
     *        for elements outside of the text body.
     *
     * \internal
     * c_api_name PageLayoutFlowing
     * \endinternal
     */
    Flowing,
    /**
     * \brief Detected elements will be placed in frames to ensure reproducing
     *        exactly the input document's layout; graphic elements will also be
     *        created so that the layout of the page could be easily modified.
     *
     * \internal
     * c_api_name PageLayoutEditable
     * \endinternal
     */
    Editable,
    /**
     * \brief Detected text will be placed in frames to ensure reproducing exactly
     *        the input document's layout, and the whole input image will be placed
     *        as page background to ensure maximum similarity to the input, at the
     *        cost of a document less easy to modify.
     *
     * \internal
     * c_api_name PageLayoutExact
     * \endinternal
     */
    Exact,
  };
  /**
   * \brief Definition of spreadsheet layouts available.
   */
  enum class SpreadsheetLayout
  {
    /**
     * \brief Create one worksheet for each table detected and link them in a summary sheet.
     *        Text outside tables and graphics will not be written.
     *
     * \internal
     * c_api_name SpreadsheetLayoutTablesOnly
     * \endinternal
     */
    TablesOnly,
    /**
     * \brief Write detected tables and text outside tables in reading order,
     *        without trying to keep the original image's layout.
     *
     * \internal
     * c_api_name SpreadsheetLayoutTablesAndText
     * \endinternal
     */
    TablesAndText,
    /**
     * \brief Reproduce the input document's layout as faithfully as possible,
     *        using frames for graphics and text outside tables, to ensure exact positioning.
     *
     * \internal
     * c_api_name SpreadsheetLayoutRecreateInput
     * \endinternal
     */
    RecreateInput,
  };
  /**
   * \brief Definition of presentation slide sizes available.
   */
  enum class SlideSize
  {
    /**
     * \brief Standard 4:3 presentation layout. Each slide in the presentation will have the following
     *        dimensions: 10in x 7.5in (25.4cm x 19.05cm)
     *
     * \internal
     * c_api_name SlideSizeStandard
     * \endinternal
     */
    Standard,
    /**
     * \brief Widescreen 16:9 presentation layout. Each slide in the presentation will have the following
     *        dimensions: 10in x 5.625in (25.4cm x 14.2875cm)
     *
     * \internal
     * c_api_name SlideSizeWideScreen
     * \endinternal
     */
    WideScreen,
    /**
     * \brief Custom slide size. The presentation slides dimension will be computed based on the size
     *        of the images added to the document.
     *        The following restrictions apply:
     *        - Minimum presentation dimension: 1in (2.54cm)
     *        - Maximum presentation dimension: 56in (142.24cm)
     *
     * \remarks Please note that the above restrictions will be applied even if larger or smaller images are provided.
     * That means that, providing an image 32000px x 1000px at 300 dpi will still output a vaild pptx file.
     *
     * \internal
     * c_api_name SlideSizeCustom
     * \endinternal
     */
    Custom,
  };
  /**
   * \brief Definition of how a PDF page content will be displayed.
   */
  enum class PageDisplay
  {
    /**
     * \brief Detected zones (text, table, and graphics) will be positioned separately on the canvas of the PDF.
     *
     * \internal
     * c_api_name PageDisplayTextAndGraphics
     * \endinternal
     */
    TextAndGraphics,
    /**
     * \brief For each page of the document, the detected text will be removed from the input image, and both will be added to the output page.
     *        The detected text will therefore be visible above the background image.
     *
     * \internal
     * c_api_name PageDisplayTextOverImage
     * \endinternal
     */
    TextOverImage,
    /**
     * \brief For each page of the document, the input image will be added entirely on the output page, without any modification, and the detected text will
     *        be added under the image. This page display is also commonly called "Searchable PDF".
     *
     * \internal
     * c_api_name PageDisplayImageOverText
     * \endinternal
     */
    ImageOverText,
    /**
     * \brief Applies IRIS Hyper Compression to the output pages.
     *
     * IRIS iHQC (standing for "intelligent High Quality Compression") is a proprietary implementation of mixed raster content compression method (MRC).
     * It relies on image segmentation to fine-tune compression rate applied to input images, which are separated between foreground, mask and background images.
     *
     * When generating the PDF, the detected text is also added under the image, which makes PDFs generated with iHQC compression
     * searchable (similarly to ImageOverText page display).
     *
     * \internal
     * c_api_name PageDisplayHyperCompression
     * \endinternal
     */
    HyperCompression,
  };
  /**
   * \brief Enumeration allowing to select bookmarks modes.
   */
  enum class BookmarksMode
  {
    /**
     * \brief Do not create bookmarks in output file, even if document metadata defines some.
     *
     * \internal
     * c_api_name BookmarksModeDisabled
     * \endinternal
     */
    Disabled,
    /**
     * \brief Create bookmarks in output file, according to what is specified in document metadata.
     *
     * \remarks This is the default behavior.
     *
     * \internal
     * c_api_name BookmarksModeEnabled
     * \endinternal
     */
    Enabled,
  };
  /**
   * \brief Definition of word processor page sizes.
   */
  enum class PageSize
  {
    /**
     * \brief A3 page size.
     *
     * \internal
     * c_api_name PageSizeA3
     * \endinternal
     */
    A3,
    /**
     * \brief A4 page size.
     *
     * \internal
     * c_api_name PageSizeA4
     * \endinternal
     */
    A4,
    /**
     * \brief A5 page size.
     *
     * \internal
     * c_api_name PageSizeA5
     * \endinternal
     */
    A5,
    /**
     * \brief A6 page size.
     *
     * \internal
     * c_api_name PageSizeA6
     * \endinternal
     */
    A6,
    /**
     * \brief B4 page size.
     *
     * \internal
     * c_api_name PageSizeB4
     * \endinternal
     */
    B4,
    /**
     * \brief B5 page size.
     *
     * \internal
     * c_api_name PageSizeB5
     * \endinternal
     */
    B5,
    /**
     * \brief Letter page size.
     *
     * \internal
     * c_api_name PageSizeLetter
     * \endinternal
     */
    Letter,
    /**
     * \brief Legal page size.
     *
     * \internal
     * c_api_name PageSizeLegal
     * \endinternal
     */
    Legal,
    /**
     * \brief Tabloid page size.
     *
     * \internal
     * c_api_name PageSizeTabloid
     * \endinternal
     */
    Tabloid,
    /**
     * \brief Executive page size.
     *
     * \internal
     * c_api_name PageSizeExecutive
     * \endinternal
     */
    Executive,
  };
  /**
   * \brief Definition of word processor paper orientations.
   */
  enum class PaperOrientation
  {
    /**
     * \brief Portrait orientation.
     *
     * \internal
     * c_api_name PaperOrientationPortrait
     * \endinternal
     */
    Portrait,
    /**
     * \brief Landscape orientation.
     *
     * \internal
     * c_api_name PaperOrientationLandscape
     * \endinternal
     */
    Landscape,
  };
  /**
   * \brief Definition of possible page orientations.
   */
  enum class PageOrientation
  {
    /**
     * \brief Represents a straight page
     * 
     * \internal
     * c_api_name PageOrientationStraight
     * \endinternal
     */
    Straight = 0,
    /**
     * \brief Represents a page rotated 90 degrees counterclockwise.
     * 
     * \internal
     * c_api_name PageOrientationRotatedLeft
     * \endinternal
     */
    RotatedLeft = 90,
    /**
     * \brief Represents a page rotated at 180 degrees (upside down).
     * 
     * \internal
     * c_api_name PageOrientationUpsideDown
     * \endinternal
     */
    UpsideDown = 180,
    /**
     * \brief Represents a page rotated 270 degrees counterclockwise (90 degrees clockwise).
     * 
     * \internal
     * c_api_name PageOrientationRotatedRight
     * \endinternal
     */
    RotatedRight = 270
  };
  /**
   * \brief The PDF versions.
   */
  enum class PdfVersion
  {
    /**
     * \brief PDF 1.4
     *
     * PDF 1.4 - 2001 - Acrobat 5.0 + JBIG2; RC4 encryption key lengths greater than 40bits (128bits); Extensible Metadata Platform (XMP); Tagged PDF
     *
     * \internal
     * c_api_name PdfVersionPdf14
     * \endinternal
     */
    Pdf14,
    /**
     * \brief PDF 1.4 A-1b
     *
     * Part 1 of the PDF/A ISO standard [ISO 19005-1:2005] - PDF for Long-term Preservation, Use of PDF 1.4, Level B Conformance
     *
     * \internal
     * c_api_name PdfVersionPdfA1b
     * \endinternal
     */
    PdfA1b,
    /**
     * \brief PDF 1.4 A-1a
     *
     * Part 1 of the PDF/A ISO standard [ISO 19005-1:2005] - PDF for Long-term Preservation, Use of PDF 1.4, Level A Conformance
     *
     * \internal
     * c_api_name PdfVersionPdfA1a
     * \endinternal
     */
    PdfA1a,
    /**
     * \brief PDF 1.5
     *
     * PDF 1.5 - 2003 - Acrobat 6.0 + JPEG 2000
     *
     * \internal
     * c_api_name PdfVersionPdf15
     * \endinternal
     */
    Pdf15,
    /**
     * \brief PDF 1.6
     *
     * PDF 1.6 - 2005 - Acrobat 7.0 +  AES encryption
     *
     * \internal
     * c_api_name PdfVersionPdf16
     * \endinternal
     */
    Pdf16,
    /**
     * \brief PDF 1.7
     *
     * PDF 1.7 - 2006 - Acrobat 8.0 -> 2008 - ISO 32000-1:2008
     *
     * \internal
     * c_api_name PdfVersionPdf17
     * \endinternal
     */
    Pdf17,
    /**
     * \brief PDF 1.7 A-2b
     *
     * Part 2 of the PDF/A ISO standard [ISO 19005-2] - PDF for Long-term Preservation, Use of ISO 32000-1 (PDF 1.7), Level B Conformance
     *
     * \internal
     * c_api_name PdfVersionPdfA2b
     * \endinternal
     */
    PdfA2b,
    /**
     * \brief PDF 1.7 A-2a
     *
     * Part 2 of the PDF/A ISO standard [ISO 19005-2] - PDF for Long-term Preservation, Use of ISO 32000-1 (PDF 1.7), Level A Conformance
     *
     * \internal
     * c_api_name PdfVersionPdfA2a
     * \endinternal
     */
    PdfA2a,
    /**
     * \brief PDF 1.7 A-3b
     *
     * Part 3 of the PDF/A ISO standard [ISO 19005-3] - PDF for Long-term Preservation, Use of ISO 32000-1 (PDF 1.7) with support for embedded files, Level B Conformance
     *
     * \internal
     * c_api_name PdfVersionPdfA3b
     * \endinternal
     */
    PdfA3b,
    /**
     * \brief PDF 1.7 A-3a
     *
     * Part 3 of the PDF/A ISO standard [ISO 19005-3] - PDF for Long-term Preservation, Use of ISO 32000-1 (PDF 1.7) with support for embedded files, Level A Conformance
     *
     * \internal
     * c_api_name PdfVersionPdfA3a
     * \endinternal
     */
    PdfA3a,
    /**
     * \brief PDF 1.7
     *
     * PDF 1.7 - 2008 - Adobe Extension Level 3 / Acrobat 9.0 + 256-bit AES encryption
     *
     * \internal
     * c_api_name PdfVersionPdf17Extension3
     * \endinternal
     */
    Pdf17Extension3,
    /**
     * \brief PDF 1.7
     *
     * PDF 1.7 - 2009 - Adobe Extension Level 5 / Acrobat 9.1
     *
     * \internal
     * c_api_name PdfVersionPdf17Extension5
     * \endinternal
     */
    Pdf17Extension5,
    /**
     * \brief PDF 1.7
     *
     * PDF 1.7 - 2011 - Adobe Extension Level 8 / Acrobat X
     *
     * \internal
     * c_api_name PdfVersionPdf17Extension8
     * \endinternal
     */
    Pdf17Extension8,
    /**
     * \brief PDF 1.7 A-2u
     *
     * PDF/A-2u, PDF for Long-term Preservation, ISO 32000-1 (PDF 1.7), Level U Conformance
     *
     * \internal
     * c_api_name PdfVersionPdfA2u
     * \endinternal
     */
    PdfA2u,
    /**
     * \brief PDF 1.7 A-3u
     *
     * PDF/A-3u, PDF for Long-term Preservation, ISO 32000-1 (PDF 1.7), Level U Conformance
     *
     * \internal
     * c_api_name PdfVersionPdfA3u
     * \endinternal
     */
    PdfA3u,
  };
  /**
   * \brief Definition of character encodings available for text outputs.
   */
  enum class CharacterEncoding
  {
    /**
     * \brief Utf8 encoding
     *
     * \internal
     * c_api_name CharacterEncodingUtf8
     * \endinternal
     */
    Utf8,
    /**
     * \brief Utf16 encoding
     *
     * \internal
     * c_api_name CharacterEncodingUtf16
     * \endinternal
     */
    Utf16,
  };
  /**
   * \brief The ZoneType data type defines the type of a zone.
   *
   * The iDRS manages different types of zone:
   * - text,
   * - graphic,
   * - table,
   */
  enum class ZoneType
  {
    /**
     *\brief Text: The zone contains some text.
     *
     * \internal
     * c_api_name ZoneTypeText
     * \endinternal
     */
    Text = 0,
    /**
     * \brief Graphic: The zone contains an illustration, a photo, etc.
     *
     * \internal
     * c_api_name ZoneTypeGraphic
     * \endinternal
     */
    Graphic = 1,
    /**
     *\brief Table: The zone contains a table.
     *
     * \internal
     * c_api_name ZoneTypeTable
     * \endinternal
     */
    Table = 2
  };
  /**
   * \brief The TextType data type defines the type text type.
   */
  enum class TextType
  {
    /**
     *\brief Normal text
     *
     * \internal
     * c_api_name TextTypePrinted
     * \endinternal
     */
    Printed = 0,
    /**
     *\brief Spaced handprinting.
     *
     * \internal
     * c_api_name TextTypeBlockLettersHandwriting
     * \endinternal
     */
    BlockLettersHandwriting = 1,
    /**
     *\brief Handprint text that may be near one another or even touching (Contiguous handprinting)
     *
     * \internal
     * c_api_name TextTypeCursiveHandwriting
     * \endinternal
     */
    CursiveHandwriting = 2
  };
  /**
   * \brief The TextDirection data type defines the text direction.
   * \enum TextDirection
   *
   */
  enum class TextDirection
  {
    /**
     * \brief The text runs from left to right.
     *
     * \internal
     * c_api_name TextDirectionLeftToRight
     * \endinternal
     */
    LeftToRight = 1,
    /**
     *\brief Text goes top to bottom.
     *
     * \internal
     * c_api_name TextDirectionTopToBottom
     * \endinternal
     */
    TopToBottom = 2,
    /**
     * \brief Text goes right to left.
     *
     * \internal
     * c_api_name TextDirectionRightToLeft
     * \endinternal
     */
    RightToLeft = 3
  };
  /**
   * \brief FontFamilyType contains the types of font families available in iDRS SDK
   */
  enum class FontFamilyType
  {
    /**
     * \brief SansSerif family type.
     *
     * \internal
     * c_api_name FontFamilyTypeSansSerif
     * \endinternal
     */
    SansSerif = 1,
    /**
     * \brief Serif family type.
     *
     * \internal
     * c_api_name FontFamilyTypeSerif
     * \endinternal
     */
    Serif = 2,
    /**
     * \brief Monotype family type.
     *
     * \internal
     * c_api_name FontFamilyTypeMonotype
     * \endinternal
     */
    Monotype = 3
  };
  /**
   * \brief HorizontalAlignment defines all possible horizontal alignments in iDRS
   * \enum HorizontalAlignment
   */
  enum class HorizontalAlignment
  {
    /**
     * \brief Left
     *
     * \internal
     * c_api_name HorizontalAlignmentLeft
     * \endinternal
     */
    Left = 0x01,
    /**
     * \brief Right
     *
     * \internal
     * c_api_name HorizontalAlignmentRight
     * \endinternal
     */
    Right = 0x02,
    /**
     * \brief Justify
     *
     * \internal
     * c_api_name HorizontalAlignmentJustify
     * \endinternal
     */
    Justify = 0x03,
    /**
     * \brief Center
     *
     * \internal
     * c_api_name HorizontalAlignmentCenter
     * \endinternal
     */
    Center = 0x04,
    /**
     * \brief Center
     *
     * \internal
     * c_api_name HorizontalAlignmentChar
     * \endinternal
     */
    Char = 0x05
  };
  /**
   * \brief VerticalAlignment defines all possible vertical alignments in iDRS
   * \enum VerticalAlignment
   */
  enum class VerticalAlignment
  {
    /**
     * \brief Top.
     *
     * \internal
     * c_api_name VerticalAlignmentTop
     * \endinternal
     */
    Top = 0x01,
    /**
     * \brief Middle.
     *
     * \internal
     * c_api_name VerticalAlignmentMiddle
     * \endinternal
     */
    Middle = 0x02,
    /**
     * \brief Bottom.
     *
     * \internal
     * c_api_name VerticalAlignmentBottom
     * \endinternal
     */
    Bottom = 0x03,
    /**
     * \brief Baseline.
     *
     * \internal
     * c_api_name VerticalAlignmentBaseline
     * \endinternal
     */
    Baseline = 0x04
  };
  /**
   * \brief iDRS tabulation leader.
   */
  enum class TabulationLeader
  {
    /**
     * \brief None.
     *
     * \internal
     * c_api_name TabulationLeaderTypeNone
     * \endinternal
     */
    None = 0x00,
    /**
     * \brief Dots.
     *
     * \internal
     * c_api_name TabulationLeaderTypeDots
     * \endinternal
     */
    Dotted = 0x01,
    /**
     * \brief Hyphen.
     *
     * \internal
     * c_api_name TabulationLeaderTypeHyphen
     * \endinternal
     */
    Hyphen = 0x02,
    /**
     * \brief Underscore.
     *
     * \internal
     * c_api_name TabulationLeaderTypeUnderscore
     * \endinternal
     */
    Underscore = 0x03
  };
  /**
   * \brief iDRS list types.
   */
  enum class ListType
  {
    /**
     * \brief Unordered list.
     *
     * \internal
     * c_api_name ListTypeUnordered
     * \endinternal
     */
    Unordered = 1,
    /**
     * \brief Ordered list.
     *
     * \internal
     * c_api_name ListTypeOrdered
     * \endinternal
     */
    Ordered = 2,
  };
  /**
   * \brief Hyperlink contains the hyperlink states for elements in iDRS SDK
   */
  enum class Hyperlink
  {
    /**
     * \brief No hyperlink.
     *
     * \internal
     * c_api_name HyperlinkTypeNone
     * \endinternal
     */
    None = 0x00,
    /**
     * \brief The following words are in an hyperlink for an e-mail
     *
     * \internal
     * c_api_name HyperlinkTypeEmail
     * \endinternal
     */
    Email = 0x01,
    /**
     * \brief The following words are in an hyperlink for an URL
     *
     * \internal
     * c_api_name HyperlinkTypeUrl
     * \endinternal
     */
    Url = 0x02
  };
  /**
   * \brief iDRS paragraph types.
   */
  enum class ParagraphType
  {
    /**
     * \brief Body type.
     *
     * \internal
     * c_api_name ParagraphTypeBody
     * \endinternal
     */
    Body = 0x00,
    /**
     * \brief Title.
     *
     * \internal
     * c_api_name ParagraphTypeTitle
     * \endinternal
     */
    Title = 0x01,
    /**
     * \brief List.
     *
     * \internal
     * c_api_name ParagraphTypeList
     * \endinternal
     */
    List = 0x02
  };
  /**
   * \brief iDRS list styles.
   */
  enum class ListStyle
  {
    /**
     * \brief None
     *
     * \internal
     * c_api_name ListStyleNone
     * \endinternal
     */
    None = 0,
    /**
     * \brief Disc
     *
     * \internal
     * c_api_name ListStyleDisc
     * \endinternal
     */
    Disc = 1,
    /**
     * \brief Circle
     *
     * \internal
     * c_api_name ListStyleCircle
     * \endinternal
     */
    Circle = 2,
    /**
     * \brief Square
     *
     * \internal
     * c_api_name ListStyleSquare
     * \endinternal
     */
    Square = 3,
    /**
     * \brief Decimal
     *
     * \internal
     * c_api_name ListStyleDecimal
     * \endinternal
     */
    Decimal = 4,
    /**
     * \brief Decimal with leading zero
     *
     * \internal
     * c_api_name ListStyleDecimalLeadingZero
     * \endinternal
     */
    DecimalWithLeadingZero = 5,
    /**
     * \brief Lower roman
     *
     * \internal
     * c_api_name ListStyleLowerRoman
     * \endinternal
     */
    RomanLowercase = 6,
    /**
     * \brief Upper roman
     *
     * \internal
     * c_api_name ListStyleUpperRoman
     * \endinternal
     */
    RomanUppercase = 7,
    /**
     * \brief Lower greek
     *
     * \internal
     * c_api_name ListStyleLowerGreek
     * \endinternal
     */
    GreekLowercase = 10,
    /**
     * \brief Lower latin
     *
     * \internal
     * c_api_name ListStyleLowerLatin
     * \endinternal
     */
    LatinLowercase = 11,
    /**
     * \brief Upper latin
     *
     * \internal
     * c_api_name ListStyleUpperLatin
     * \endinternal
     */
    LatinUppercase = 12
  };
  /**
   * \brief Contains all sets of fonts that iDRS is able to recognize
   */
  enum class FontInfoComputation
  {
    /**
     * \brief No formatting information computed.
     * 
     * Please note that using this mode the OCR engine will not extract any formatting information from the input image. 
     * Information like color, fonts, etc will NOT be computed
     * 
     * \internal
     * c_api_name FontInfoComputationNone
     * \endinternal
     */
    None,
    /**
     * \brief Represents an standard set of fonts used for OCR.
     *
     * In includes the following fonts:
     * - Arial
     * - Times New Roman
     * - Courier New
     * - Tahoma
     * - Verdana
     * - Georgia
     * - Trebuchet MS
     * - Batang (windows, linux)
     * - MS-PMincho (windows, linux)
     * - SimSun (windows, linux)
     * - PMingLiU (windows, linux)
     * - AppleMyungjo (osx)
     * - HiraMinPro-W3 (osx)
     * - Kai (osx)
     * - BiauKai (osx)
     *
     * \internal
     * c_api_name FontInfoComputationStandard
     * \endinternal
     */
    Standard,
    /**
     * \brief Contains a set of fonts usually included in Microsoft Office.
     *
     * This font set includes the following fonts:
     * - Arial
     * - Times New Roman
     * - Courier New
     * - Tahoma
     * - Calibri
     * - Cambria
     * - Candara
     * - Consolas
     * - Constantia
     * - Corbel
     * - Bookman Old Style
     * - Gill Sans MT
     * - Trebuchet MS
     * - Franklin Gothic
     * - Tw Cen MT
     * - Century Schoolbook
     * - Century Gothic
     * - Garamond
     * - Batang (windows, linux)
     * - MS-PMincho (windows, linux)
     * - SimSun (windows, linux)
     * - PMingLiU (windows, linux)
     * - AppleMyungjo (osx)
     * - HiraMinPro-W3 (osx)
     * - Kai (osx)
     * - BiauKai (osx)
     *
     * \internal
     * c_api_name FontInfoComputationOffice
     * \endinternal
     */
    Office,
    /**
     * \brief Represents a value that is expected to be used by integrators when defining custom fonts for the results in iDRS SDK
     *
     * \internal
     * c_api_name FontInfoComputationCustom
     * \endinternal
     */
    Custom,
  };
  /**
   * \brief Types of behaviors for skew detection & correction algorithm
   */
  enum class SkewDetection
  {
    /**
     * \brief No skew detection & correction
     *
     * \internal
     * c_api_name SkewDetectionNone
     * \endinternal
     */
    None, 
    /**
     * \brief Skew detection is performed, but correction is not done if the page does not contain any text.
     * 
     * This feature is especially useful for documents where there are pages without text
     *
     * \remarks This mode relies on a part of the language and orientation detection algorithm; therefore if neither of them are activated, processing
     * speed will be slower than if using skew detection modes None or Always.
     *
     * \internal
     * c_api_name SkewDetectionIfText
     * \endinternal
     */
    IfText,
    /**
     * \brief Skew detection & correction is always performed
     *
     * \internal
     * c_api_name SkewDetectionAlways
     * \endinternal
     */
    Always
  };
  /**
   * \brief Type recognitions
   */
  enum class RecognitionType
  {
    /**
     * \brief Full page recognition
     *
     * \internal
     * c_api_name RecognitionTypeFullPage
     * \endinternal
     */
    FullPage,
    /**
     * \brief Zonal recognition
     *
     * \internal
     * c_api_name RecognitionTypeZonal
     * \endinternal
     */
    Zonal
  };
  /**
   * \brief Enumerates the possible values for the work depth applied to the ocr engine
   */
  enum class Workdepth
  {
    /**
     * \brief Favor speed over accuracy
     *
     * \internal
     * c_api_name WorkdepthMaximumSpeed
     * \endinternal
     */
    MaximumSpeed,
    /**
     * \brief Slightly favor speed over accuracy
     *
     * \internal
     * c_api_name WorkdepthFavorSpeedOverAccuracy
     * \endinternal
     */
    FavorSpeedOverAccuracy,
    /**
     * \brief Balanced speed/accuracy 
     *
     * \internal
     * c_api_name WorkdepthBalanced
     * \endinternal
     */
    Balanced,
    /**
     * \brief Slightly favor accuracy over speed
     *
     * \internal
     * c_api_name WorkdepthFavorAccuracyOverSpeed
     * \endinternal
     */
    FavorAccuracyOverSpeed,
    /**
     * \brief Favor accuracy over speed
     *
     * \internal
     * c_api_name WorkdepthMaximumAccuracy
     * \endinternal
     */
    MaximumAccuracy
  };
  /**
   * \brief Text detection sensitivity modes
   */
  enum class TextDetectionSensivity
  {
    /**
     * \brief Maximize the text output. The OCR engine will search for as much text as possible, including in zones which could be seen as graphics
     *
     * \internal
     * c_api_name TextDetectionSensivityMaximumText
     * \endinternal
     */
    MaximumText,
    /**
     * \brief Prioritize the detection of text over graphics
     *
     * \internal
     * c_api_name TextDetectionSensivityFavorTextOverLayout
     * \endinternal
     */
    FavorTextOverLayout,
    /**
     * \brief Balanced text/graphics detection sensitivity
     *
     * \internal
     * c_api_name TextDetectionSensivityBalanced
     * \endinternal
     */
    Balanced,
    /**
     * \brief Prioritize the detection of graphics elements over text
     *
     * \internal
     * c_api_name TextDetectionSensivityFavorLayoutOverText
     * \endinternal
     */
    FavorLayoutOverText,
    /**
     * \brief Maximize the graphics output. Using this mode, some text parts might be recognized as graphics
     *
     * \internal
     * c_api_name TextDetectionSensivityMaximumLayout
     * \endinternal
     */
    MaximumLayout
  };
  /**
   * \brief Multi-threading usage modes
   */
  enum class ThreadingMode
  {
    /**
     * \brief Disable multi-threading. SDK operations will be executed on a single thread
     *
     * \internal
     * c_api_name ThreadingModeNone
     * \endinternal
     */
    None,
    /**
     * \brief Multi-threading enabled. Number of worker threads is set to half the number CPU for OCR engine
     *
     * \internal
     * c_api_name ThreadingModeLimited
     * \endinternal
     */
    Limited,
    /**
     * \brief Multi-threading enabled. Number of worker threads set to number of CPU for OCR engine
     *
     * \internal
     * c_api_name ThreadingModeOptimized
     * \endinternal
     */
    Optimized,
    /**
     * \brief Multi-threading enabled. 
     * Number of worker threads set to number of CPU for OCR engine + initialize 1 OCR engine / context in the case of zonal OCR
     * 
     * \important This mode uses a lot of memory in case of zonal OCR with several context.
     *
     * \internal
     * c_api_name ThreadingModeMaximum
     * \endinternal
     */
    Maximum
  };
  /**
   * \brief Barcode encoding modes
   */
  enum class BarcodeEncoding
  {
    /**
     * \brief UTF-8 encoding
     *
     * \internal
     * c_api_name BarcodeEncodingUtf8
     * \endinternal
     */
    Utf8,
    /**
     * \brief Shift JIS encoding
     *
     * \internal
     * c_api_name BarcodeEncodingSjis
     * \endinternal
     */
    Sjis
  };

  /**
   * \brief Barcode engines that are shipped with iDRS SDK.
   */
  enum class BarcodeEngineIdentifier
  {
    /**
     * \brief Default IRIS barcode engine.
     *
     * It supports the following barcode types: BarcodeType::Ean13, BarcodeType::Ean8, BarcodeType::Msi, BarcodeType::MsiPharma, BarcodeType::UpcA, BarcodeType::UpcE,
     * BarcodeType::Codabar, BarcodeType::Interleaved2Of5, BarcodeType::Code39, BarcodeType::Code39Extended, BarcodeType::Code39Hibc, BarcodeType::Code93, BarcodeType::Code128,
     * BarcodeType::Pdf417, BarcodeType::Postnet, BarcodeType::Patchcode, BarcodeType::Ucc128, BarcodeType::QrCode
     *
     * By default, the work depth range is MaximumSpeed to MaximumAccuracy
     *
     * It gets enabled automatically when setting up a license for Barcode module
     *
     * \internal
     * c_api_name BarcodeEngineUIDStandard
     * \endinternal
     */
    Standard = 0,
    /**
     * \brief Advanced barcode engine.
     *
     * It supports the following barcode types: BarcodeType::Ean13, BarcodeType::Ean8, BarcodeType::UpcA, BarcodeType::UpcE, BarcodeType::Codabar, BarcodeType::Interleaved2Of5,
     * BarcodeType::Code39, BarcodeType::Code39Extended, BarcodeType::Code39Hibc, BarcodeType::Code128, BarcodeType::Pdf417, BarcodeType::Ucc128, BarcodeType::QrCode,
     * BarcodeType::DataMatrix, BarcodeType::Patchcode
     *
     * By default the work depth range is FavorAccuracyOverSpeed to MaximumAccuracy
     *
     * It gets enabled automatically when setting up a license for Barcode module with extension BarcodeAdvanced
     *
     * \internal
     * c_api_name BarcodeEngineUIDAdvanced
     * \endinternal
     */
    Advanced,
    /**
     * \brief Datamatrix barcode engine. 
     * 
     * It supports the following barcode types: BarcodeType::DataMatrix
     * 
     * By default, the work depth range is MaximumSpeed to MaximumAccuracy
     * 
     * It gets enabled automatically when setting up a license for Barcode module with extension Barcode2D
     *
     * \internal
     * c_api_name BarcodeEngineUIDDatamatrix
     * \endinternal
     */
    Datamatrix,
    /**
     * \brief Advanced qrcode/aztec detection engine. It gets enabled automatically when setting up a license for IDRS_BARCODE_MODULE with extension IDRS_BARCODE_EXTENSION_QRCODE
     * 
     * It supports the following barcode types: BarcodeType::QrCode, BarcodeType::Aztec
     * 
     * By default the work depth range is FavorAccuracyOverSpeed to MaximumAccuracy
     * 
     * It gets enabled automatically when setting up a license for Barcode module with extension Barcode2D
     *
     * \internal
     * c_api_name BarcodeEngineUIDExtra2D
     * \endinternal
     */
    Extra2d,
    /**
     * \brief Default IRIS barcode engine with white pixels despeckle preprocessing step.
     * Due to the fact that a preprocessing operation is performed before the barcode detection, the speed might be slightly degraded
     * 
     * It supports the same barcode types as the \see Standard barcode engine: BarcodeType::Ean13, BarcodeType::Ean8, BarcodeType::Msi, BarcodeType::MsiPharma, BarcodeType::UpcA, BarcodeType::UpcE,
     * BarcodeType::Codabar, BarcodeType::Interleaved2Of5, BarcodeType::Code39, BarcodeType::Code39Extended, BarcodeType::Code39Hibc, BarcodeType::Code93, BarcodeType::Code128,
     * BarcodeType::Pdf417, BarcodeType::Postnet, BarcodeType::Patchcode, BarcodeType::Ucc128, BarcodeType::QrCode
     * 
     * By default the work depth range is MaximumAccuracy
     * 
     * It gets enabled automatically when setting up a license for Barcode module
     *
     * \internal
     * c_api_name BarcodeEngineUIDStandardDespeckle
     * \endinternal
     */
    StandardDespeckle,
    /**
     * \brief Advanced qrcode/aztec detection engine with white pixels despeckle preprocessing step.
     * Due to the fact that a preprocessing operation is performed before the barcode detection, the speed might be slightly degraded
     * 
     * It supports the following barcode types: BarcodeType::QrCode, BarcodeType::Aztec
     * 
     * By default the work depth range is MaximumAccuracy
     * 
     * It gets enabled automatically when setting up a license for Barcode module with extension Barcode2D
     *
     * \internal
     * c_api_name BarcodeEngineUIDExtra2dDespeckle
     * \endinternal
     */
    Extra2dDespeckle,
    /**
     * \brief Default IRIS barcode engine with dither removal preprocessing step.
     * Due to the fact that a preprocessing operation is performed before the barcode detection, the speed might be slightly degraded
     * 
     * It supports the same barcode types as the \see Standard barcode engine: BarcodeType::Ean13, BarcodeType::Ean8, BarcodeType::Msi, BarcodeType::MsiPharma, BarcodeType::UpcA, BarcodeType::UpcE,
     * BarcodeType::Codabar, BarcodeType::Interleaved2Of5, BarcodeType::Code39, BarcodeType::Code39Extended, BarcodeType::Code39Hibc, BarcodeType::Code93, BarcodeType::Code128,
     * BarcodeType::Pdf417, BarcodeType::Postnet, BarcodeType::Patchcode, BarcodeType::Ucc128, BarcodeType::QrCode
     * 
     * By default the work depth range is MaximumAccuracy
     * 
     * It gets enabled automatically when setting up a license for Barcode module
     *
     * \internal
     * c_api_name BarcodeEngineUIDStandardUndither
     * \endinternal
     */
    StandardUndither,
    /**
     * \brief Advanced qrcode/aztec detection engine with dither removal preprocessing step.
     * Due to the fact that a preprocessing operation is performed before the barcode detection, the speed might be slightly degraded
     * 
     * It supports the following barcode types: BarcodeType::QrCode, BarcodeType::Aztec
     * 
     * By default the work depth range is MaximumAccuracy
     * 
     * It gets enabled automatically when setting up a license for Barcode module with extension Barcode2D
     *
     * \internal
     * c_api_name BarcodeEngineUIDExtra2dUndither
     * \endinternal
     */
    Extra2dUndither,
    /**
     * \brief Custom barcode engine identifier.
     * This identifier is present here to indicate any custom barcode engine that might be integrated with iDRS SDK
     *
     * \internal
     * c_api_name BarcodeEngineUIDCustom
     * \endinternal
     */
    Custom
  };

  //! recognition mode specifies how the engine will behave when performing recognition
  enum class BarcodeRecognitionMode
  {
  /**
     * \brief Stop on first result
     *
     * \internal
     * c_api_name BarcodeRecognitionModeStopOnFirstResult
     * \endinternal
     */
    StopOnFirstResult,
    /**
     * \brief Read all barcodes in the supplied image
     *
     * \internal
     * c_api_name BarcodeRecognitionModeReadAllBarcodes
     * \endinternal
     */
    ReadAllBarcodes
  };

  //! list with all possible capabilities for a barcode engine
  enum class BarcodeCapability
  {
    /**
     * \brief The engine supports black&white images
     *
     * \internal
     * c_api_name BarcodeCapabilityImageBlackAndWhite
     * \endinternal
     */
    ImageBlackAndWhite = 1,
    /**
     * \brief The engine supports greyscale images
     *
     * \internal
     * c_api_name BarcodeCapabilityImageGreyscale
     * \endinternal
     */
    ImageGreyscale,
    /**
     * \brief The engine supports color images
     *
     * \internal
     * c_api_name BarcodeCapabilityImageColor
     * \endinternal
     */
    ImageColor,
    /**
     * \brief The engine is able to get control codes for code128 barcode
     *
     * \internal
     * c_api_name BarcodeCapabilityCode128ControlCode
     * \endinternal
     */
    Code128ControlCode
  };

  /**
   * \brief Enumerable containing all barcode session parameters
   * These parameters are used to control the behavior of the barcode engines
   */
  enum class BarcodeSessionParameter
  {
    /**
     * \brief Sets the barcode engine work depth.
     * A lower value means that the engine should return the result(s) fast, while a higher value allows the engine to spend more time searching for barcodes.
     *
     * Expected range of values: [0 - 100]
     *
     * \internal
     * c_api_name BarcodeSessionWorkdepth
     * \endinternal
     */
    Workdepth = 0,
    /**
     * \brief Sets the minimum height for a barcode to be taken into consideration. Values are in pixels
     *
     * \internal
     * c_api_name BarcodeSessionMinHeight
     * \endinternal
     */
    MinHeight,
    /**
     * \brief Sets the maximum height for a barcode to be taken into consideration. Values are in pixels
     *
     * \internal
     * c_api_name BarcodeSessionMaxHeight
     * \endinternal
     */
    MaxHeight,
    /**
     * \brief Sets the minimum solution length (character count) for a barcode to be taken into consideration.
     *
     * \internal
     * c_api_name BarcodeSessionMinLength
     * \endinternal
     */
    MinLength,
    /**
     * \brief Sets the maximum solution length (character count) for a barcode to be taken into consideration.
     *
     * \internal
     * c_api_name BarcodeSessionMaxLength
     * \endinternal
     */
    MaxLength,
    /**
     * \brief Sets the barcode recognition mode that needs to be used for detection.
     * The possible values are described in \see IDRS::IDRS_BARCODE_RECOGNITION_MODE
     * - BarcodeRecognitionMode::StopOnFirstResult
     * - BarcodeRecognitionMode::ReadAllBarcodes
     *
     * \internal
     * c_api_name BarcodeSessionRecognitionMode
     * \endinternal
     */
    RecognitionMode,
    /**
     * \brief Sets the timeout in milliseconds after which the engine should stop doing recognition
     *
     * \internal
     * c_api_name BarcodeSessionTimeoutMilliseconds
     * \endinternal
     */
    TimeoutMilliseconds,
    /**
     * \brief Enables barcode code128 control code mode.
     *
     * Possible values are:
     *  - IDRS_TRUE: enables the setting
     *  - IDRS_FALSE: disables the setting
     *
     * \internal
     * c_api_name BarcodeSessionCode128ControlCode
     * \endinternal
     */
    Code128ControlCode,
    /**
     * \brief Enables automatic utf8 encoding detection.
     *
     * Possible values are:
     *  - IDRS_TRUE: enables the automatic detection
     *  - IDRS_FALSE: disables the automatic detection
     *
     * \internal
     * c_api_name BarcodeSessionAutomaticEncodingDetectionUtf8
     * \endinternal
     */
    AutomaticEncodingDetectionUtf8,
    /**
     * \brief Enables automatic SJIS encoding detection.
     *
     * Possible values are:
     *  - IDRS_TRUE: enables the automatic detection
     *  - IDRS_FALSE: disables the automatic detection
     *
     * \internal
     * c_api_name BarcodeSessionAutomaticEncodingDetectionSJIS
     * \endinternal
     */
    AutomaticEncodingDetectionSJIS,
    /**
     * \brief Internal value.
     *
     * \internal
     * c_api_name BarcodeSessionMax
     * \endinternal
     */
    Max
  };

  /**
   * \brief Definition of interactive form fields types
   */
  enum class FormFieldType
  {
    /**
     * \brief Input field that accepts a single or multiple lines of unformatted text.
     * 
     * \internal
     * c_api_name FormFieldTypeText
     * \endinternal
     */
    Text,
    /**
     * \brief Input field subdivided in single letter boxes that accepts a single line of unformatted text.
     * 
     * \internal
     * c_api_name FormFieldTypeCombedText
     * \endinternal
     */
    CombedText,
    /**
     * \brief Input field of hidden text that accepts a password value.
     * 
     * \internal
     * c_api_name FormFieldTypePassword
     * \endinternal
     */
    Password,
    /**
     * \brief Togglable button that holds a two states value (on/off).
     * 
     * \internal
     * c_api_name FormFieldTypeCheckbox
     * \endinternal
     */
    Checkbox,
    /**
     * \brief Togglable option button owned by a RadioButton.
     * 
     * \internal
     * c_api_name FormFieldTypeRadioButtonItem
     * \endinternal
     */
    RadioButtonItem,
    /**
     * \brief RadioButton field that contains a set of RadioButtonItem elements.
     *
     * \internal
     * c_api_name FormFieldTypeRadioButton
     * \endinternal
     */
    RadioButton,
    /**
     * \brief Logical group of fields sharing the same parent in the interactive form hierarchy.
     *
     * \internal
     * c_api_name FormFieldTypeGroup
     * \endinternal
     */
    Group,
    /**
     * \brief List of selectable items with an optional text input field.
     * 
     * \internal
     * c_api_name FormFieldTypeDropdown
     * \endinternal
     */
    Dropdown,
    /**
     * \brief Scrollable list of selectable items where one or more item(s) may be selected at a given time.
     * 
     * \internal
     * c_api_name FormFieldTypeListBox
     * \endinternal
     */
    ListBox,
  };
  /**
   * \brief Definition of actions types available in interactive forms.
   */
  enum class FormActionType
  {
    /**
     * \brief Action that is implemented using the JavaScript Adobe Form API.
     *
     * \internal
     * c_api_name FormActionTypeJavaScript
     * \endinternal
     */
    JavaScript,
  };
  /**
   * \brief Definition of events types available for an interactive form field
   */
  enum class FormFieldEventType
  {
    /**
     * \brief Event triggered when the user type a keystroke in a form field or selects an item in a list.
     *
     * \internal
     * c_api_name FormFieldEventTypeOnKeyStroke
     * \endinternal
     */
    OnKeyStroke,
    /**
     * \brief Event triggered before the form field value is formatted for display.
     *
     * \internal
     * c_api_name FormFieldEventTypeOnBeforeFormat
     * \endinternal
     */
    OnBeforeFormat,
    /**
     * \brief Event triggered for validation after the form field's value is changed.
     *
     * \internal
     * c_api_name FormFieldEventTypeOnValidate
     * \endinternal
     */
    OnValidate,
    /**
     * \brief Event triggered when the form field value re-calculation is requested.
     *
     * \internal
     * c_api_name FormFieldEventTypeOnCalculate
     * \endinternal
     */
    OnCalculate,
    /**
     * \brief Event triggered when the cursor enters the field's active area.
     *
     * \internal
     * c_api_name FormFieldEventTypeOnMouseEnter
     * \endinternal
     */
    OnMouseEnter,
    /**
     * \brief Event triggered when the cursor leaves the field's active area.
     *
     * \internal
     * c_api_name FormFieldEventTypeOnMouseLeave
     * \endinternal
     */
    OnMouseLeave,
    /** 
     * \brief Event triggered when the mouse button is pressed inside the field's active area.
     *
     * \internal
     * c_api_name FormFieldEventTypeOnMouseDown
     * \endinternal
     */
    OnMouseDown,
    /**
     * \brief Event triggered when the mouse button is released inside the field's active area.
     *
     * \internal
     * c_api_name FormFieldEventTypeOnMouseUp
     * \endinternal
     */
    OnMouseUp,
    /**
     * \brief Event triggered when the field receives the input focus.
     *
     * \internal
     * c_api_name FormFieldEventTypeOnFocus
     * \endinternal
     */
    OnFocus,
    /**
     * \brief Event triggered when the field loses the input focus.
     *
     * \internal
     * c_api_name FormFieldEventTypeOnBlur
     * \endinternal
     */
    OnBlur,
    /**
     * \brief Event triggered when the page containing the field is opened.
     *
     * \internal
     * c_api_name FormFieldEventTypeOnPageOpen
     * \endinternal
     */
    OnPageOpen,
    /**
     * \brief Event triggered when the page containing the field is closed.
     *
     * \internal
     * c_api_name FormFieldEventTypeOnPageClose
     * \endinternal
     */
    OnPageClose,
    /**
     * \brief Event triggered when the page containing the field becomes visible in the viewer application.
     *
     * \internal
     * c_api_name FormFieldEventTypeOnPageVisible
     * \endinternal
     */
    OnPageVisible,
    /**
     * \brief Event triggered when the page containing the field is no longer visible in the viewer application.
     *
     * \internal
     * c_api_name FormFieldEventTypeOnPageHide
     * \endinternal
     */
    OnPageHide,
  };
  /**
   * \brief Definition of border styles available for the interactive forms.
   */
  enum class FormFieldBorderStyle
  {
    /**
     * \brief Defaults to none or inherits from the parent field if applicable.
     *
     * \internal
     * c_api_name FormFieldBorderStyleInherit
     * \endinternal
     */
    Inherit,
    /**
     * \brief no border surrounding the form field.
     *
     * \internal
     * c_api_name FormFieldBorderStyleNone
     * \endinternal 
     */
    None,
    /**
     * \brief A solid rectangle surrounding the form field.
     * 
     * \internal
     * c_api_name FormFieldBorderStyleSolid
     * \endinternal 
     */
    Solid,
    /**
     * \brief A dashed rectangle surrounding the form field.
     * 
     * \internal
     * c_api_name FormFieldBorderStyleDashed
     * \endinternal 
     */
    Dashed,
    /**
     * \brief A simulated embossed rectangle that appears to be raised above the surface of the page.
     * 
     * \internal
     * c_api_name FormFieldBorderStyleBeveled
     * \endinternal 
     */
    Beveled,
    /**
     * \brief A simulated engraved rectangle that appears to be recessed below the surface of the page.
     * 
     * \internal
     * c_api_name FormFieldBorderStyleInset
     * \endinternal 
     */
    Inset,
    /**
     * \brief A single line along the bottom of the field bounding box.
     * 
     * \internal
     * c_api_name FormFieldBorderStyleUnderline
     * \endinternal 
     */
    Underline
  };
  /**
   * \brief Definition of the text alignments available for an interactive form field.
   */
  enum class FormFieldTextAlignment
  {
    /**
     * \brief Default text alignment or inherits from the parent field if applicable.
     * 
     * \internal
     * c_api_name FormFieldTextAlignmentNone
     * \endinternal 
     */
    Inherit,
    /**
     * \brief Centered text.
     * 
     * \internal
     * c_api_name FormFieldTextAlignmentCenter
     * \endinternal 
     */
    Center,
    /**
     * \brief Left aligned text.
     * 
     * \internal
     * c_api_name FormFieldTextAlignmentLeft
     * \endinternal 
     */
    Left,
    /**
     * \brief Right aligned text.
     * 
     * \internal
     * c_api_name FormFieldTextAlignmentRight
     * \endinternal 
     */
    Right
  };
  /**
    * \brief The AttachmentType enum lists the supported Pdf attachments file types.
    */
  enum class AttachmentType : int
  {
    /**
     * \brief "*.txt" file attachment
     *
     * \internal
     * c_api_name AttachmentTypeText
     * \endinternal
     */
    Text = 0,
    /**
     * \brief "*.pdf" file attachment
     *
     * \internal
     * c_api_name AttachmentTypePdf
     * \endinternal
     */
    Pdf,
    /**
     * \brief "*.xml" file attachment
     *
     * \internal
     * c_api_name AttachmentTypeXml
     * \endinternal
     */
    Xml,
    /**
     * \brief "*.html" file attachment
     *
     * \internal
     * c_api_name AttachmentTypeHtml
     * \endinternal
     */
    Html,
    /**
     * \brief "*.rtf" file attachment
     *
     * \internal
     * c_api_name AttachmentTypeRtf
     * \endinternal
     */
    Rtf,
    /**
     * \brief "*.doc" file attachment
     *
     * \internal
     * c_api_name AttachmentTypeDoc
     * \endinternal
     */
    Doc,
    /**
     * \brief "*.dot" file attachment
     *
     * \internal
     * c_api_name AttachmentTypeDot
     * \endinternal
     */
    Dot,
    /**
     * \brief "*.docx" file attachment
     *
     * \internal
     * c_api_name AttachmentTypeDocx
     * \endinternal
     */
    Docx,
    /**
     * \brief "*.dotx" file attachment
     *
     * \internal
     * c_api_name AttachmentTypeDotx
     * \endinternal
     */
    Dotx,
    /**
     * \brief "*.xls" file attachment
     *
     * \internal
     * c_api_name AttachmentTypeXls
     * \endinternal
     */
    Xls,
    /**
     * \brief "*.xlt" file attachment
     *
     * \internal
     * c_api_name AttachmentTypeXlt
     * \endinternal
     */
    Xlt,
    /**
     * \brief "*.xla" file attachment
     *
     * \internal
     * c_api_name AttachmentTypeXla
     * \endinternal
     */
    Xla,
    /**
     * \brief "*.xlsx" file attachment
     *
     * \internal
     * c_api_name AttachmentTypeXlsx
     * \endinternal
     */
    Xlsx,
    /**
     * \brief "*.xltx" file attachment
     *
     * \internal
     * c_api_name AttachmentTypeXltx
     * \endinternal
     */
    Xltx,
    /**
     * \brief "*.csv" file attachment
     *
     * \internal
     * c_api_name AttachmentTypeCsv
     * \endinternal
     */
    Csv,
    /**
     * \brief "*.ppt" file attachment
     *
     * \internal
     * c_api_name AttachmentTypePpt
     * \endinternal
     */
    Ppt,
    /**
     * \brief "*.pptx" file attachment
     *
     * \internal
     * c_api_name AttachmentTypePptx
     * \endinternal
     */
    Pptx,
    /**
     * \brief "*.pot" file attachment
     *
     * \internal
     * c_api_name AttachmentTypePot
     * \endinternal
     */
    Pot,
    /**
     * \brief "*.potx" file attachment
     *
     * \internal
     * c_api_name AttachmentTypePotx
     * \endinternal
     */
    Potx,
    /**
     * \brief "*.pps" file attachment
     *
     * \internal
     * c_api_name AttachmentTypePps
     * \endinternal
     */
    Pps,
    /**
     * \brief "*.ppa" file attachment
     *
     * \internal
     * c_api_name AttachmentTypePpa
     * \endinternal
     */
    Ppa,
    /**
     * \brief "*.jpg" file attachment
     *
     * \internal
     * c_api_name AttachmentTypeJpeg
     * \endinternal
     */
    Jpeg,
    /**
     * \brief "*.png" file attachment
     *
     * \internal
     * c_api_name AttachmentTypePng
     * \endinternal
     */
    Png,
    /**
     * \brief "*.tif" and "*.tiff" file attachment
     *
     * \internal
     * c_api_name AttachmentTypeTiff
     * \endinternal
     */
    Tiff,
    /**
     * \brief "*.gif" file attachment
     *
     * \internal
     * c_api_name AttachmentTypeGif
     * \endinternal
     */
    Gif,
    /**
     * \brief Non-standard application specific attachment
     *
     * \internal
     * c_api_name AttachmentTypeAppSpecific
     * \endinternal
     */
    AppSpecific,
  };
  /**
   * \brief Enumerable that defines the dimension adjustment options available when performing Deskew feature.
   */
  enum class DimensionAdjust
  {
    /**
     * \brief Do not perform dimensions adjustment.
     *
     * The deskewed image dimensions will be slightly bigger than the original image if a skew angle
     * has been detected. This is the fastest mode, and ensures that all the information on the image is kept.
     *
     * \internal
     * c_api_name DimensionAdjustNone
     * \endinternal
     */
    None,
    /**
     * \brief If a skew angle is found, crop the deskewed image so that its dimensions matches exactly
     * the original image.
     *
     * This guarantees that the created output document will have the proper dimensions when it's according
     * to a standard (e.g. A4 paper size).
     *
     * Note that if the image was containing data very close to the borders, it might be removed by the crop operation.
     *
     * \internal
     * c_api_name DimensionAdjustCrop
     * \endinternal
     */
    Crop
  };


  /**
   * \brief Definition of the available types of IPageCollection implementations
   */
  enum class PageCollectionType
  {
    /**
     * \brief Default implementation of IPageCollection
     * 
     * \internal
     * c_api_name PageCollectionTypeDefault
     * \endinternal
     */
    Default,
    /**
     * \brief Custom implementation of the IPageCollection
     * 
     * \internal
     * c_api_name PageCollectionTypeCustom
     * \endinternal
     */
    Custom
  };

  /**
   * \brief XML shemas.
   */
  enum class XmlSchema : int
  {
    /**
     * \brief Basic XML schema.
     *
     * This format will describe the recognized zones and their content with a simple representation (for instance text lines entries for text zones).
     * 
     * \important Please note that this format doesn't allow multipage outputs yet, and CDocumentWriter will throw an exception if the case occurs.
     * This possibility will be added in a future release.
     *
     * \internal
     * c_api_name XmlSchemaBasic
     * \endinternal
     */
    Basic,
    /**
     * \brief XML schema for ALTO export.
     *
     * By using this format for export, the output xml file will contain information about the recognized data, including the page layout properties conform to ALTO specification
     *
     * \internal
     * c_api_name XmlSchemaAlto
     * \endinternal
     */
     Alto,
  };

  /**
   * \brief Definition of the available versions of serialization
   */
  enum class SerializationFormat : unsigned char
  {
    /**
     * \brief Version 10
     *
     * \internal
     * c_api_name SerializationVersion10
     * \endinternal
     */
    Version10 = 10,
    /**
     * \brief Version 11
     *
     * \internal
     * c_api_name SerializationVersion11
     * \endinternal
     */
    Version11 = 11,
    /**
     * \brief Version 12
     *
     * \internal
     * c_api_name SerializationVersion12
     * \endinternal
     */
    Version12 = 12,
    /**
     * \brief Version 13
     *
     * \internal
     * c_api_name SerializationVersion13
     * \endinternal
     */
    Version13 = 13,
    /**
     * \brief Version 14
     *
     * \internal
     * c_api_name SerializationVersion14
     * \endinternal
     */
    Version14 = 14,
    /**
     * \brief Version 15
     *
     * \internal
     * c_api_name SerializationVersion15
     * \endinternal
     */
    Version15 = 15,
    /**
     * \brief Version 16
     *
     * \internal
     * c_api_name SerializationVersion16
     * \endinternal
     */
    Version16 = 16,
    /**
     * \brief Version 17
     *
     * \internal
     * c_api_name SerializationVersion17
     * \endinternal
     */
    Version17 = 17,
    /**
     * \brief Version 18
     *
     * \internal
     * c_api_name SerializationVersion18
     * \endinternal
     */
    Version18 = 18,
    /**
     * \brief Version 19
     *
     * \internal
     * c_api_name SerializationVersion19
     * \endinternal
     */
    Version19 = 19,
    /**
     * \brief Latest Version
     *
     * \internal
     * c_api_name SerializationVersionLatest
     * \endinternal
     */
    Latest = Version19,
  };

  /**
   * \brief The image file formats handled by iDRS.
   *
   */
  enum class ImageFormat
  {
    /**
     * \brief Tiff
     *
     * \internal
     * c_api_name ImageFormatTiff
     * \endinternal
     */
    Tiff = 0,
    /**
     * \brief Png
     *
     * \internal
     * c_api_name ImageFormatPng
     * \endinternal
     */
    Png = 1,
    /**
     * \brief Jpeg
     *
     * \internal
     * c_api_name ImageFormatJpeg
     * \endinternal
     */
    Jpeg = 2,
    /**
     * \brief Bmp
     *
     * \internal
     * c_api_name ImageFormatBmp
     * \endinternal
     */
    Bmp = 3,
    /**
     * \brief Jpeg 2000
     *
     * \internal
     * c_api_name ImageFormatJpeg2000
     * \endinternal
     */
    Jpeg2000 = 5,
    /**
     * \brief Jbig2
     * 
     * \internal
     * c_api_name ImageFormatJbig2
     * \endinternal
     *
     * \internal
     * c_api_name ImageFormatJbig2
     * \endinternal
     */
    Jbig2 = 6,
    /**
     * \brief Custom
     *
     * \internal
     * c_api_name ImageFormatCustom
     * \endinternal
     */
    Custom= 10,
    /**
     * \brief PDF image file.
     *
     * \internal
     * c_api_name ImageFormatPdf
     * \endinternal
     */
    Pdf = 11,
  };

  /**
   * \brief The encryption levels.
   *
   */
  enum class EncryptionAlgorithm
  {
    /**
     * \brief No encryption
     *
     * \internal
     * c_api_name EncryptionAlgorithmNone
     * \endinternal
     */
    None,
    /**
     * \brief Autodetect encryption algorithm
     * The best algorithm for the format will be chosen
     *
     * \internal
     * c_api_name EncryptionAlgorithmAuto
     * \endinternal
     */
    Auto,
    /**
     * \brief RC4 128 bit algorithm.
     *
     * \important Please note that RC4 is considered insecure, but allows to apply encryption
     * on PDF versions 1.4 and 1.5. If possible, prefer generating PDF versions 1.6 or later with
     * AES 128 encryption.
     *
     * \internal
     * c_api_name EncryptionAlgorithmRc4
     * \endinternal
     */
    Rc4,
    /**
     * \brief AES 128 bit algorithm
     *
     * \important Required PDF version 1.6 or higher
     *
     * \internal
     * c_api_name EncryptionAlgorithmAes128
     * \endinternal
     */
    Aes128,
  };
  /**
   * \brief Source for graphical zones
   */
  enum class PageZoneGraphicSource
  {
    /**
     * \brief The source is the base image, usually the one used for text recognition or barcode detection
     *
     * \internal
     * c_api_name PageZoneGraphicSourceBaseImage
     * \endinternal
     */
    BaseImage,
    /**
     * \brief The source is an image from an external source
     *
     * \internal
     * c_api_name PageZoneGraphicSourceExternal
     * \endinternal
     */
    External
  };
  /**
   * \brief Enum defining the Tiff Compression formats
   */
  enum class TiffCompression
  {
    /**
     * \brief Group4 compression (a.k.a. CCITT Group 4)
     * 
     * \internal 
     * c_api_name TiffCompressionGroup4
     * \endinternal 
     */
    Group4,
    /**
     * \brief Specialized version of Group4 compression, required by some formats/softwares.
     *
     * \remarks This compression should be used only in specific and known contexts. For general purpose, prefer standard Group4 compression.
     *
     * \internal
     * c_api_name TiffCompressionFaxGroup4
     * \endinternal
     */
    FaxGroup4,
    /**
     * \brief Packbits compression
     *
     * \internal
     * c_api_name TiffCompressionPackbits
     * \endinternal
     */
    Packbits,
    /**
     * \brief Jpeg compression
     *
     * \internal
     * c_api_name TiffCompressionJpeg
     * \endinternal
     */
    Jpeg,
  };
  /**
   * \brief PngTransparencyMode defines the PNG image transparency
   */
  enum class PngTransparencyMode
  {
    /**
     * \brief No transparency applied
     * \internal
     * c_api_name PngTransparencyModeNone
     * \endinternal
     */ 
    None = 0,
    /**
     * \brief The black pixels will be converted to transparent
     * \internal
     * c_api_name PngTransparencyModeBlack
     * \endinternal
     */
    Black = 1
  };
  /**
   * \brief Restrictions on output document printing.
   */
  enum class PrintPermission
  {
    /**
     * \brief User is not allowed to print the document.
     * 
     * \internal
     * c_api_name PrintPermissionForbidden
     * \endinternal
     */
    Forbidden,
    /**
     * \brief User will be able to print the document but only at a low resolution (150 dpi).
     *
     * \internal
     * c_api_name PrintPermissionLowResolution
     * \endinternal
     */
    LowResolution,
    /**
     * \brief User will be able to print the document.
     *
     * \internal
     * c_api_name PrintPermissionAllowed
     * \endinternal
     */
    Allowed,
  };
  /**
   * \brief Restrictions on output document edition.
   */
  enum class EditPermission
  {
    /**
     * \brief User will not be able to edit the document.
     *
     * \internal
     * c_api_name EditPermissionNone
     * \endinternal
     */
    None,
    /**
     * \brief User will only be able to insert, delete or rotate pages.
     *
     * \internal
     * c_api_name EditPermissionOrganizePages
     * \endinternal
     */
    OrganizePages,
    /**
     * \brief User will be able to fill form fields and sign the document.
     *
     * \internal
     * c_api_name EditPermissionFillAndSign
     * \endinternal
     */
    FillAndSign,
    /**
     * \brief User will be able to add annotations, fill form fields and sign the document.
     *
     * \internal
     * c_api_name EditPermissionFillAndSignAndComment
     * \endinternal
     */
    FillAndSignAndComment,
    /**
     * \brief User will have access to all functionalities listed by other values of the enum. Extraction of the pages' content
     * is not included by this value, and handled separately via another property of CEncryptionOptions class.
     *
     * \internal
     * c_api_name EditPermissionAllViewerOptions
     * \endinternal
     */
    AllViewerOptions,
  };

  /**
   * \brief Table detection modes
   */
  enum class TableDetectionMode
  {
    /**
     * \brief Table detection is disabled.
     *
     * In this mode, no table will be detected during page recognition
     *
     * \internal
     * c_api_name TableDetectionModeDisabled
     * \endinternal
     */
    Disabled,
    /**
     * \brief Automatic table detection.
     *
     * \internal
     * c_api_name TableDetectionModeAutomatic
     * \endinternal
     */
    Automatic,
    /**
     * \brief Forces one table on the whole page
     *
     * In this mode the ocr engine treats the whole input page as a table.
     * 
     * If the ocr engine cannot treat the entire page as a table, it will automatically switch to automatic mode.
     *
     * \internal
     * c_api_name TableDetectionModeForceSingleTable
     * \endinternal
     */
    ForceSingleTable
  };

} // namespace
#endif // _EnumDefinitions_h_
