/**
 * \file CIDRSLicense.h
 * \brief Interface for the IDRS::CIDRSLicense class.
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _CIDRSLicense_h_
#define _CIDRSLicense_h_
#include <CObjPtr.h>
namespace IDRS
{
  class idrs_string;
  /**
   * \brief Module contains all the iDRS modules identifiers.
   *
   * iDRS is composed of many different modules, modular to your project requirements.
   *
   */
  enum class Module
  {
    /**
     * \brief The character recognition engine.
     *
     * The module provides ocr recognition capabilities. <br>
     * In order to extend the recognition capabilities, the following extensions are available:
     * - \ref Extension::OcrAsianExtra
     * - \ref Extension::OcrJapaneseAdvanced
     * - \ref Extension::OcrHebrew
     * - \ref Extension::OcrHandwritten
     * - \ref Extension::OcrArabic
     *
     */
    Ocr = 0,
    /**
     * \brief The barcode recognition engine.
     *
     * The barcode module will identify barcodes located anywhere on the page.
     * The barcodes can be used as separators and their content can be used for renaming files for example.<br>
     * In order to extend the barcode recognition capabilities, the following extensions are available:
     * - \ref Extension::Barcode2D
     * - \ref Extension::BarcodeAdvanced
     *
     */
    Barcode = 1,
    /**
     * \brief The image preprocessing module.
     *
     * Before doing the OCR, the images may need to be optimized for the OCR process. This is done by different pre-processing functions.
     * The Prepro module allows you to clean-up the images for optimized OCR such as deskew, despeckle, binarize, etc. <br>
     * The following extensions are available to enhance the image preprocessing:
     * - \ref Extension::PreproCameraImage
     */
    Prepro = 2,
    /**
     * \brief The document output module.
     *
     * Once the recognition of the document has been done, you may want to generate an output file. This is done by the document output module.
     * The following extensions are available to enhance the output document:
     * - \ref Extension::DocumentOutputHyperCompression
     */
    DocumentOutput = 3,
    /**
     * \brief The iDRS Image formats module.
     *
     * This module adds image loading/saving capabilities to iDRS SDK.
     * The following extensions are available to enhance image loading capabilities:
     * - \ref Extension::ImageFormatsPdfInput
     */
    ImageFormats = 10,
    /**
     * \brief Value reserved for iDRS internal usage
     */
    Reserved1  = 12,
    /**
     * \brief Value reserved for iDRS internal usage
     */
    Reserved2  = 13,
    /**
     * \brief Value reserved for iDRS internal usage
     */
    Reserved3  = 14,
    /**
     * \brief Value reserved for iDRS internal usage
     */
    Reserved4  = 15,
    /**
     * \brief Value reserved for iDRS internal usage
     */
    Reserved5  = 16,
    /**
     * \brief Value reserved for iDRS internal usage
     */
    Reserved6  = 17,
  };
  /**
   * \brief All the extensions available in iDRS SDK.
   * \note An extension cannot be loaded without it's corresponding module
   */
  enum class Extension
  {
    /**
     * \brief No extension
     *
     * \internal
     * c_api_name ExtensionNone
     * \endinternal
     */
    None = -1,
    /**
     * \brief The Hebrew OCR add-on extends the OCR languages with the Hebrew language.
     */
    OcrHebrew,
    /**
     * \brief The Handwritten OCR add-on.
     *
     * I.R.I.S. has developed its own Intelligent Character Recognition engine for the recognition of all handwritten characters based on the Latin alphabet.
     */
    OcrHandwritten,
    /**
     * \brief The Arabic OCR add-on extends the OCR languages with the Arabic and Farsi languages.
     */
    OcrArabic,
    /**
     * \brief The Asian Extra OCR add-on.
     *
     * This add-on extends the recognition for additional Asian OCR languages:
     * - Traditional Chinese
     * - Simplified Chinese
     * - Japanese
     * - Korean
     * - Vietnamese
     * - Thai
     */
    OcrAsianExtra,
    /**
     * \brief The Japanese Advanced OCR add-on.
     *
     * This add-on enables the combination of IRIS Asian engine with a 3rd party OCR Engine.
     * This allows to improve speed performance, without compromising OCR accuracy.
     *
     * \remarks The engine combination is available for Japanese language only
     */
    OcrJapaneseAdvanced,
    /**
     * \brief The 2D barcode detection add-on.
     *
     * This add-on enables detection of 2D barcode types:
     * - PDF417
     * - QRCode
     * - Aztec
     * - Datamatrix
     */
    Barcode2D,
    /**
     * \brief The advanced barcode detection add-on.
     *
     * This add-on enables the combination with an extra 3rd-party barcode engine to further increase detection accuracy.
     */
    BarcodeAdvanced,
    /**
     * \brief The camera image preprocessing add-on.
     *
     * This add-on allows to use preprocessing algorithms dedicated to camera images (corners detection, perspective correction, ...)
     */
    PreproCameraImage,
    /**
     * \brief The hyper compression document output add-on.
     *
     * This add-on allows to create hyper-compressed PDF files, using IRIS iHQC technology.
     */
    DocumentOutputHyperCompression,
    /**
     * \brief The PDF input image formats add-on.
     *
     * This add-on allows to load PDF files (rasterization or content loading).
     */
    ImageFormatsPdfInput
  };
  /**
   * \brief Available iDRS license types.
   *
   * iDRS manages different license type, depending on your project requirements. The license type goes with the protection type.
   *
   */
  enum class LicenseType : int
  {
    /**
     * \brief Custom software protection.
     *
     * I.R.I.S. provides to the integrator other types of protection depending on the constraints of the project of the integrator.
     * Usually, this type of protection is proposed by I.R.I.S. under a very specific license agreement for large deployment projects and for a business level
     * that represents substantial yearly revenue for I.R.I.S.
     *
     */
    CustomSoftware = 2
  };
/**
 * \brief Max size of a license.
 */
#define IDRS_LICENSE_MAX_SIZE 2048
  class CIDRSLicenseData;
  /**
   * \brief The CIDRSLicense class stores the licensing information for a module in iDRS SDK
   * \ingroup module_core
   *
   * The class stores the following information:
   *  - <b>module identifier</b> - Module
   *  - <b>license type</b> - LicenseType
   *  - <b>software key</b> that unlocks the module features
   *  - <b>address of the licensing server</b> - used in case license type is IDRS_LICENSE_SOFTWARE
   *  - <b>list of extensions to enable</b>
   *
   * This class should be used in conjunction with CIDRSSetup to specify which iDRS SDK modules and extensions will be enabled in integrator's applications.
   *
   * \note For Ocr, please see CIDRSLicenseOcr
   *
   * \see Module for a list with the modules available in iDRS SDK
   * \see Extension for a list with the extensions available in iDRS SDK
   * \see CIDRSSetup for CIDRSLicense usage details
   */
  class IDRSKRN_API CIDRSLicense
  {
    public:
      /**
       * \brief Default constructor
       * Creates the object but it doesn't initialize the inner structures
       */
      CIDRSLicense();
      /**
       * \brief Creates a CIDRSLicense object and initializes it with the supplied information
       *
       * \param evModule Module identifier
       * \param evLicenseType License type
       * \param strSoftwareKey The software key for unlocking the module features.
       */
      CIDRSLicense( const Module evModule, const LicenseType evLicenseType, const idrs_string& strSoftwareKey );
      /**
       * \brief Copy constructor initializes internal data with data present in argOtherLicense parameter
       *
       * \param argOtherLicense Object to copy
       */
      CIDRSLicense( const CIDRSLicense & argOtherLicense );
      /**
       * \brief Assignment operator copies all data from the supplied argument to current object
       *
       * \param argOtherLicense Object to copy
       *
       * \return Reference to current object
       */
      CIDRSLicense& operator=( const CIDRSLicense& argOtherLicense );
      /**
       * \brief Assignment operator copies all data from the supplied argument pointer to current object
       * This assignment operator can be used to assign a NULL value to the license, invalidating this way the license
       *
       * \param pargOtherLicenseData Pointer to the object to copy
       *
       * \return Reference to current object
       */
      CIDRSLicense& operator=( const CIDRSLicenseData* pargOtherLicenseData );
      /**
       * \brief Destructor
       */
      virtual ~CIDRSLicense();
      /**
       * \brief Sets the license type used by this license object
       *
       * \param evLicenseType License type
       */
      void SetLicenseType ( const LicenseType evLicenseType );
      /**
       * \brief Returns the module for this license object
       *
       * \return the current module
       */
      Module GetModule () const;
      /**
       * \brief Returns the license type for this license object
       *
       * \return the license type
       */
      LicenseType GetLicenseType () const;
      /**
       * \brief Returns the module software key
       *
       * \return The module software key
       */
      const idrs_string& GetSoftwareKey () const;
      /**
       * \brief Verifies if the extension specified as argument is enabled
       *
       * \param eExtension The extension to be verified
       *
       * \retval IDRS_TRUE if the specified extension is enable
       * \retval IDRS_FALSE otherwise
       *
       * \throw CIDRSException if the supplied extension is invalid for the current module
       */
      IDRS_BOOL IsExtensionEnabled ( const Extension eExtension ) const;
      /**
       * \brief Returns the extension software key
       *
       * \param eExtension The extension to be verified
       *
       * \return The extension software key
       *
       * \throw CIDRSException if the supplied extension is invalid for the current module
       */
      const idrs_string& GetExtensionSoftwareKey ( const Extension eExtension ) const;
      /**
       * \brief Enables an extension for the current module
       *
       * \param eExtension The extension to be verified
       * \param strExtensionSoftwareKey The extension software key
       *
       * \throw CIDRSException if the supplied extension is invalid for the current module
       */
      void EnableExtension ( const Extension eExtension, const idrs_string& strExtensionSoftwareKey );
      /**
       * \brief Disables an extension for the current module
       *
       * \param eExtension The extension to be verified
       *
       * \throw CIDRSException if the supplied extension is invalid for the current module
       */
      void DisableExtension ( const Extension eExtension );
      /**
       * \brief Returns the number of extension supported by the current module
       *
       * \return the number of extension supported by the current module
       */
      IDRS_UINT32 GetExtensionCount () const;
      /**
       * \brief Returns the extension at a specified index
       *
       * CIDRSLicense class contains an internal vector with all the extensions available for the current module.
       * The integrators can obtain in a programmatic way all the extensions available for the current module.
       *
       * \param uiIndex zero based index where to search for the extension
       *
       * \return the extension identified found at the supplied index
       *
       * \throws CIDRSException if the index is out of bounds
       */
      Extension GetExtensionAt ( const IDRS_UINT32 uiIndex ) const;
      /**
       * \brief IsNull checks if the license object is initialized
       *
       * \retval IDRS_TRUE if the license object is initialized with data
       * \retval IDRS_FALSE if the license object contains no data
       */
      IDRS_BOOL IsNull () const;
    protected:
      /**
       * \brief Member variable that stores the data associated with this class
       */
      CIDRSLicenseData * m_pLicenseData;
  };
}  // namespace IDRS
#endif // _CIDRSLicense_h_
