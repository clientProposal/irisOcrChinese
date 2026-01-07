/**
 * \file CPdfCompressionOptions.h
 * \brief Interface for CPdfCompressionOptions class
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */

#ifndef _cpdfcompressionoptions_h_
#define _cpdfcompressionoptions_h_
#include <CObjPtr.h>
#include "EnumDefinitions.h"
namespace IDRS
{
  class CPdfCompressionOptionsData;
  /**
   * \brief CPdfCompressionOptions class specifies the pdf compression options
   */
  class IDRSKRN_API CPdfCompressionOptions : public CObjPtr
  {
    public:
      /**
       * \brief Default constructor.
       */
      inline CPdfCompressionOptions();
      /**
       * \brief copy constructor.
       */
      inline CPdfCompressionOptions(const CPdfCompressionOptions& argPdfCompressionOptions);
      /**
       * \brief constructor from data object.
       */
      inline CPdfCompressionOptions(CPdfCompressionOptionsData* pObj);
      /**
       * \brief Default destructor.
       */
      inline virtual ~CPdfCompressionOptions();
      /**
       * \brief Create is instantiating a new instance of CPdfCompressionOptions and associated data object
       *
       * \return New instance of CPdfCompressionOptions
       */
      static CPdfCompressionOptions Create();
      /**
       * \brief Sets the pdf compression quality.
       *
       * \param evCompressionQuality pdf compression quality value
       */
      void SetCompressionQuality(const CompressionQuality evCompressionQuality);
      /**
       * \brief Gets the pdf compression quality
       *
       * \returns the pdf compression quality
       */
      CompressionQuality GetCompressionQuality() const;
      /**
       * \brief Sets the Bitonal file format.
       * This compression format will be used when input is black and white,
       * or for the mask layer if PDF PageDisplay is set to HyperCompressed
       *
       * \pre Only Tiff and Jbig2 accepted
       *
       * \param evBitonalFormat Bitonal file format
       */
      void SetBitonalFormat(const ImageFormat evBitonalFormat);
      /**
       * \brief Gets the Bitonal file format.
       *
       * \returns the Bitonal file format.
       */
      ImageFormat GetBitonalFormat() const;
      /**
       * \brief Sets the Color file format.
       * This compression format will be used when when input is color or grayscale
       *
       * \pre Only Jpeg and Jpeg2000 accepted
       *
       * \param evColorFormat Color file format
       */
      void SetColorFormat(const ImageFormat evColorFormat);
      /**
       * \brief Gets the Color file format.
       *
       * \returns the Color file format.
       */
      ImageFormat GetColorFormat() const;
    private:
      /**
       * Internal use only
       */
      inline CPdfCompressionOptionsData& TypedObject() const;
  };
  /*
   *
   */
  inline CPdfCompressionOptions::CPdfCompressionOptions()
  {
  }
  /*
   *
   */
  inline CPdfCompressionOptions::CPdfCompressionOptions(const CPdfCompressionOptions& argPdfCompressionOptions)
    : CObjPtr((CObjPtr&)argPdfCompressionOptions)
  {
  }
  /*
   *
   */
  inline CPdfCompressionOptions::CPdfCompressionOptions(CPdfCompressionOptionsData* pObj)
    : CObjPtr((CObj*)pObj)
  {
  }
  /*
   *
   */
  inline CPdfCompressionOptions::~CPdfCompressionOptions()
  {
  }
  /*
   *
   */
  inline CPdfCompressionOptionsData& CPdfCompressionOptions::TypedObject() const
  {
    return (CPdfCompressionOptionsData&)Object();
  }
} // namespace
#endif //_cpdfcompressionoptions_h_
