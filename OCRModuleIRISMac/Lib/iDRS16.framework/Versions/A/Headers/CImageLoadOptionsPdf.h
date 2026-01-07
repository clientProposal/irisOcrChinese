/**
 * \file CImageLoadOptionsPdf.h
 * \brief Declaration of class CImageLoadOptionsPdf
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _CImageLoadOptionsPdf_h_
#define _CImageLoadOptionsPdf_h_

#include "CImageLoadOptions.h"
#include "EnumDefinitions.h"
namespace IDRS
{
  class idrs_string;
  class CImageLoadOptionsData;
  /**
   * \brief CImageLoadOptionsPdf contains the options for loading image to pdf file format
   * \ingroup module_image_formats
   *
   */
  class IDRSKRN_API CImageLoadOptionsPdf : public CImageLoadOptions
  {
    public:
      /**
       * \brief Default constructor
       */
      CImageLoadOptionsPdf();
      /**
       * \brief Constructor from Data object
       *
       * \param pargImageLoadOptionsData Pointer to the data object
       */
      CImageLoadOptionsPdf( const CImageLoadOptionsData* pargImageLoadOptionsData );
      /**
       * \brief Destructor
       */
      virtual ~CImageLoadOptionsPdf();
      /**
       * \brief Creates a new CImageLoadOptionsPdf object and initializes its internal data structures
       *
       * \param bKeepAnnotations The flag indicating if annotations should be kept when loading the page
       * \return The newly created object
       */
      static CImageLoadOptionsPdf Create ( const IDRS_BOOL bKeepAnnotations = IDRS_TRUE );
      /**
       * \brief Get the flag for keeping annotations when loading a PDF page
       *
       * \return The flag (IDRS_TRUE if annotations must be kept, IDRS_FALSE otherwise)
       */
      IDRS_BOOL GetKeepAnnotations() const;
      /**
       * \brief Set the flag for keeping annotations when loading a PDF page
       *
       * \param bKeepAnnotations IDRS_TRUE to keep annotations when loading the page, IDRS_FALSE otherwise
       */
      void SetKeepAnnotations( const IDRS_BOOL bKeepAnnotations );
      /**
       * \brief Get the password that was set to open an encrypted PDF
       *
       * \return A string containing the document's password
       */
      const idrs_string& GetOpenPassword() const;
      /**
       * \brief Set the user/owner password to open the protected input PDF
       *
       * \param strPassword A string containing the password to open the PDF file
       */
      void SetOpenPassword ( const idrs_string& strPassword );
      /**
       * \brief Set the path to custom fonts that can be used when loading the pdf files.
       *
       * The custom fonts folder is used whenever iDRS is trying to read a pdf file that contains a font not known by pdfium.
       * This scenario typically occurs on Linux platform, where there's no standard API for accessing the fonts on the system.
       *
       * By default the custom fonts path is set to NULL
       *
       * \param strCustomFontsPath Path to custom fonts
       */
      void SetCustomFontsPath( const idrs_string& strCustomFontsPath );
      /**
       * \brief Get the custom fonts path
       *
       * \return A string containing the path
       */
      const idrs_string& GetCustomFontsPath() const;
      /**
       * \brief Set the flag to allow incomplete rendering
       *
       * In some cases, glyphs are not found in the specified font in the pdf document but we can also continue
       * rendering and these glyphs will be empty in the output
       *
       * By default the flag is set to IDRS_TRUE, if set to IDRS_FALSE we will stop rendering and throw an exception
       *
       * \param bAllowIncompleteRendering flag status
       */
      void SetAllowIncompleteRendering(const IDRS_BOOL bAllowIncompleteRendering);
      /**
       * \brief Get the flag value to check if incomplete rendering is allowed
       * \return The value of the flag indicating if incomplete rendering is allowed
       */
      IDRS_BOOL GetAllowIncompleteRendering() const;
      /**
       * \brief Set the flag to load page content.
       *
       * If this flag is activated, your CPage object will be filled with the page content data such as:
       * - Paragraphs, lines of text
       * - Font information
       * - Graphical zones
       *
       * By default the flag is set to IDRS_FALSE
       *
       * \param bLoadPageContent flag status
       */
      void SetLoadPageContent(const IDRS_BOOL bLoadPageContent);
      /**
       * \brief Get the flag value to check if load page content
       * \return The value of the flag indicating if we load page content
       */
      IDRS_BOOL GetLoadPageContent() const;
      /**
       * \brief Set the flag to allow incomplete text loading
       *
       * iDRS does not support unicode characters with value higher than U+FFFF
       * When this flag is set to IDRS_TRUE and such character is encountered, it will be replaced by U+FFFD (replacement character).
       * When this flag is set to IDRS_FALSE, exception IDRS_ERROR_IMAGE_FORMATS_PDF_INPUT_UNSUPPORTED_CHARACTER will be thrown instead
       *
       * By default the flag is set to IDRS_TRUE
       *
       * \param bAllowIncompleteTextLoading flag status
       */
      void SetAllowIncompleteTextLoading(const IDRS_BOOL bAllowIncompleteTextLoading);
      /**
       * \brief Get the flag value to check if incomplete text loading is allowed
       * \return The value of the flag indicating if incomplete text loading is allowed
       */
      IDRS_BOOL GetAllowIncompleteTextLoading() const;
      /**
       * \brief Get the loading resolution value
       * 
       * By default the loading resolution is set to 300dpi
       * 
       * \return The loading resolution value
       */
      IDRS_UINT GetLoadingResolution() const;
      /**
       * \brief Set the loading resolution value
       * 
       * By default the loading resolution is set to 300dpi
       * 
       * \param uiResolution the loading resolution value to set
       */
      void SetLoadingResolution(const IDRS_UINT uiResolution);
      /**
       * \brief Get the black and white detection mode currently set.
       *
       * \return the black and white detection mode
       *
       * \remarks The default detection mode is PdfInputBlackAndWhiteDetection::Accurate.
       */
      PdfInputBlackAndWhiteDetection GetBlackAndWhiteDetection() const;
      /**
       * \brief Set the black and white detection mode.
       *
       * \param evBlackAndWhiteDetection The black and white detection mode to set
       */
      void SetBlackAndWhiteDetection(const PdfInputBlackAndWhiteDetection evBlackAndWhiteDetection);
    private:
      /**
       * \brief Return a CImageLoadOptionsData reference.
       *
       * Internal use only
       */
      inline CImageLoadOptionsData & TypedObject () const
      {
        return ( CImageLoadOptionsData & )Object ();
      };
  };
}

#endif //_CImageLoadOptionsPdf_h_
