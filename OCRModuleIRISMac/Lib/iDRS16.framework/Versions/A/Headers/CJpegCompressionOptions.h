/**
 * \file CJpegCompressionOptions.h
 * \brief Interface for CJpegCompressionOptions class
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */

#ifndef _cjpegcompressionoptions_h_
#define _cjpegcompressionoptions_h_
#include <CObjPtr.h>
#include <idrs.h>
#include "EnumDefinitions.h"
namespace IDRS
{
  class CJpegCompressionOptionsData;
  /**
   * \brief CJpegCompressionOptions class specifies the jpeg compression options
   */
  class IDRSKRN_API CJpegCompressionOptions : public CObjPtr
  {
    public:
      /**
       * \brief Default constructor.
       */
      inline CJpegCompressionOptions();
      /**
       * \brief copy constructor.
       */
      inline CJpegCompressionOptions(const CJpegCompressionOptions& argJpegCompressionOptions);
      /**
       * \brief constructor from data object.
       */
      inline CJpegCompressionOptions(CJpegCompressionOptionsData* pObj);
      /**
       * \brief destructor.
       */
      inline virtual ~CJpegCompressionOptions();
      /**
       * \brief Create is instantiating a new instance of CJpegCompressionOptions and associated data object
       *
       * \return New instance of CJpegCompressionOptions
       */
      static CJpegCompressionOptions Create();
      /**
       * \brief Set the jpeg compression quality.
       *
       * \param evCompressionQuality jpeg compression quality value
       */
      void SetCompressionQuality(const CompressionQuality evCompressionQuality);
      /**
       * \brief Get the jpeg compression quality
       *
       * \returns the jpeg compression quality
       */
      CompressionQuality GetCompressionQuality() const;
    private:
      /**
       * Internal use only
       */
      inline CJpegCompressionOptionsData& TypedObject() const;
  };
  /*
   *
   */
  inline CJpegCompressionOptions::CJpegCompressionOptions()
  {
  }
  /*
   *
   */
  inline CJpegCompressionOptions::CJpegCompressionOptions(const CJpegCompressionOptions& argJpegCompressionOptions)
    : CObjPtr((CObjPtr&)argJpegCompressionOptions)
  {
  }
  /*
   *
   */
  inline CJpegCompressionOptions::CJpegCompressionOptions(CJpegCompressionOptionsData* pObj)
    : CObjPtr((CObj*)pObj)
  {
  }
  /*
   *
   */
  inline CJpegCompressionOptions::~CJpegCompressionOptions()
  {
  }
  /*
   *
   */
  inline CJpegCompressionOptionsData& CJpegCompressionOptions::TypedObject() const
  {
    return (CJpegCompressionOptionsData&)Object();
  }
} // namespace
#endif // _cjpegcompressionoptions_h_
