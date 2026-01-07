/**
 * \file CPdfOutputParams.h
 * \brief Interface for CPdfOutputParams class
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */

#ifndef _cpdfoutputparams_h_
#define _cpdfoutputparams_h_
#include <CObjPtr.h>
#include "EnumDefinitions.h"
#include "COutputParams.h"
#include "CPdfCustomMetadata.h"
#include "CEncryptionOptions.h"
#include "CDigitalSignature.h"
#include "CAttachment.h"
#include "TObjPtrArray.h"
namespace IDRS
{
  class COutputParamsData;
  class CBookmarksOptions;
  class CPdfCompressionOptions;
  class CDocumentSeparationOptions;
  /**
   * \brief CPdfOutputParams class manages the parameters to create a Pdf file
   */
  class IDRSKRN_API CPdfOutputParams : public COutputParams
  {
    public:
      /**
       * \brief Default constructor.
       */
      inline CPdfOutputParams();
      /**
       * \brief copy constructor.
       */
      inline CPdfOutputParams(const CPdfOutputParams& argPdfOutputParams);
      /**
       * \brief constructor from data object.
       */
      inline CPdfOutputParams(COutputParamsData* pObj);
      /**
       * \brief Default destructor.
       */
      inline virtual ~CPdfOutputParams();
      /**
       * \brief Create is instantiating a new instance of CPdfOutputParams and associated data object
       *
       * \param evPdfVersion pdf version value
       * \param evPageDisplay page display value
       *
       * \return New instance of CPdfOutputParams
       */
      static CPdfOutputParams Create(const PdfVersion evPdfVersion, const PageDisplay evPageDisplay);
      /**
       * \brief Gets the pdf version.
       *
       * \returns the pdf version
       */
      PdfVersion GetPdfVersion() const;
      /**
       * \brief Gets the page display type.
       *
       * \returns the page display type
       */
      PageDisplay GetPageDisplay() const;
      /**
       * \brief Gets  the pdf custom metadata.
       *
       * \returns the pdf custom metadata object
       */
      CPdfCustomMetadata GetPdfCustomMetadata() const;
      /**
       * \brief Sets the pdf custom metadata.
       *
       * \param argPdfCustomMetadata a pdf custom metadata object
       */
      void SetPdfCustomMetadata(const CPdfCustomMetadata& argPdfCustomMetadata);
      /**
       * \brief Gets the encryption options.
       *
       * \returns the encryption options object
       */
      CEncryptionOptions GetEncryptionOptions() const;
      /**
       * \brief Sets the encryption options.
       *
       * \param argEncryptionOptions an encryption options object
       */
      void SetEncryptionOptions(const CEncryptionOptions& argEncryptionOptions);
      /**
       * \brief Get the pdf bookmarks options.
       *
       * \returns the bookmarks options
       */
      CBookmarksOptions GetBookmarksOptions() const;
      /**
       * \brief Set the pdf bookmarks options.
       *
       * \param argBookmarksOptions the bookmarks options
       */
      void SetBookmarksOptions(const CBookmarksOptions& argBookmarksOptions);
      /**
       * \brief Gets the pdf compression options object
       *
       * \returns the Pdf compression options object
       */
      CPdfCompressionOptions GetPdfCompressionOptions() const;
      /**
       * \brief Sets the pdf compression options object
       *
       * \param argPdfCompressionOptions a Pdf compression options object
       */
      void SetPdfCompressionOptions(const CPdfCompressionOptions& argPdfCompressionOptions);
      /**
       * \brief Gets the Pdf document separation options object.
       *
       * \returns The Pdf document separation options object.
       */
      CDocumentSeparationOptions GetDocumentSeparationOptions() const;
      /**
       * \brief Sets the Pdf document separation options object.
       *
       * \param argDocumentSeparationOptions The Pdf document separation options object.
       */
      void SetDocumentSeparationOptions( const CDocumentSeparationOptions &argDocumentSeparationOptions );
      /**
       * \brief Gets a boolean flag indicating whether the use original rotation is enabled.
       *
       * \returns IDRS_TRUE if use original rotation is enabled, otherwise IDRS_FALSE
       */
      IDRS_BOOL GetUseOriginalRotation() const;
      /**
       * \brief Sets a boolean flag indicating whether the use original rotation is enabled.
       *
       * \param bUseOriginalRotation bolean indicating the status
       */
      void SetUseOriginalRotation(const IDRS_BOOL bUseOriginalRotation);
      /**
       * \brief Gets the boolean flag specifying if the embed fonts is enabled.
       *
       * \returns IDRS_TRUE if embed fonts is enabled, otherwise IDRS_FALSE
       */
      IDRS_BOOL GetEmbedFonts() const;
      /**
       * \brief Gets the boolean flag specifying if the embed fonts is enabled.
       *
       * \param bEmbedFonts bolean indicating the font embedding status
       */
      void SetEmbedFonts(const IDRS_BOOL bEmbedFonts);
    private:
      /**
       * Internal use only
       */
      inline COutputParamsData& TypedObject() const;
  };
  /*
   *
   */
  inline CPdfOutputParams::CPdfOutputParams()
  {
  }
  /*
   *
   */
  inline CPdfOutputParams::CPdfOutputParams(const CPdfOutputParams& argPdfOutputParams)
    : COutputParams((COutputParams&)argPdfOutputParams)
  {
  }
  /*
   *
   */
  inline CPdfOutputParams::CPdfOutputParams(COutputParamsData* pObj)
    : COutputParams(pObj)
  {
  }
  /*
   *
   */
  inline CPdfOutputParams::~CPdfOutputParams()
  {
  }
  /*
   *
   */
  inline COutputParamsData& CPdfOutputParams::TypedObject() const
  {
    return (COutputParamsData&)Object();
  }
} // namespace
#endif // _cpdfoutputparams_h_
