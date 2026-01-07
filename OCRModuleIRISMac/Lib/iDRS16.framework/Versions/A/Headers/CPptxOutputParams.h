/**
 * \file CPptxOutputParams.h
 * \brief Interface for CPptxOutputParams class
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */

#ifndef _cpptxoutputparams_h_
#define _cpptxoutputparams_h_
#include <CObjPtr.h>
#include <idrs.h>
#include <COutputParams.h>
#include "EnumDefinitions.h"
#include <CJpegCompressionOptions.h>
namespace IDRS
{
  class COutputParamsData;
  /**
   * \brief CPptxOutputParams class manages the parameters to create a pptx file
   */
  class IDRSKRN_API CPptxOutputParams : public COutputParams
  {
    public:
      /**
       * \brief Default constructor.
       */
      inline CPptxOutputParams();
      /**
       * \brief copy constructor.
       */
      inline CPptxOutputParams(const CPptxOutputParams& argPptxOutputParams);
      /**
       * \brief constructor from data object.
       */
      inline CPptxOutputParams(COutputParamsData* pObj);
      /**
       * \brief Default destructor.
       */
      inline virtual ~CPptxOutputParams();
      /**
       * \brief Create is instantiating a new instance of CPptxOutputParams and associated data object
       *
       * \param evSlideSize slide size type
       *
       * \return New instance of CPptxOutputParams
       */
      static CPptxOutputParams Create(const SlideSize evSlideSize);
      /**
       * \brief Get the Slide Size.
       *
       * \returns the slide size type
       */
      SlideSize GetSlideSize() const;
      /**
       * \brief Get the Jpeg Compression Options.
       *
       * \returns the Jpeg compression options object
       */
      CJpegCompressionOptions GetJpegCompressionOptions() const;
      /**
       * \brief Set the Jpeg Compression Options property.
       *
       * \param argJpegCompressionOptions a Jpeg compression options object
       */
      void SetJpegCompressionOptions(const CJpegCompressionOptions& argJpegCompressionOptions);
    private:
      /**
       * Internal use only
       */
      inline COutputParamsData& TypedObject() const;
  };
  /*
   *
   */
  inline CPptxOutputParams::CPptxOutputParams()
  {
  }
  /*
   *
   */
  inline CPptxOutputParams::CPptxOutputParams(const CPptxOutputParams& argPptxOutputParams)
    : COutputParams((COutputParams&)argPptxOutputParams)
  {
  }
  /*
   *
   */
  inline CPptxOutputParams::CPptxOutputParams(COutputParamsData* pObj)
    : COutputParams(pObj)
  {
  }
  /*
   *
   */
  inline CPptxOutputParams::~CPptxOutputParams()
  {
  }
  /*
   *
   */
  inline COutputParamsData& CPptxOutputParams::TypedObject() const
  {
    return (COutputParamsData&)Object();
  }
} // namespace
#endif // _cpptxoutputparams_h_
