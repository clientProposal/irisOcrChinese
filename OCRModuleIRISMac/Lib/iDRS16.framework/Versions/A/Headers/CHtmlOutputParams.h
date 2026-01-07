/**
 * \file CHtmlOutputParams.h
 * \brief Interface for CHtmlOutputParams class
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */

#ifndef _chtmloutputparams_h_
#define _chtmloutputparams_h_
#include <CObjPtr.h>
#include "COutputParams.h"
#include "EnumDefinitions.h"

namespace IDRS
{
  class COutputParamsData;
  class CJpegCompressionOptions;
  /**
   * \brief CHtmlOutputParams class manages the parameters to create a Html file
   */
  class IDRSKRN_API CHtmlOutputParams : public COutputParams
  {
    public:
      /**
       * \brief Default constructor.
       */
      inline CHtmlOutputParams();
      /**
       * \brief copy constructor.
       */
      inline CHtmlOutputParams(const CHtmlOutputParams& argHtmlOutputParams);
      /**
       * \brief constructor from data object.
       */
      inline CHtmlOutputParams(COutputParamsData* pObj);
      /**
       * \brief destructor.
       */
      inline virtual ~CHtmlOutputParams();
      /**
       * \brief Create is instantiating a new instance of CHtmlOutputParams and associated data object
       *
       * \param evPageLayout the page layout type. 
       * \note
       * Limitation: Flowing and Editable layouts will provide the same output
       *
       * \return New instance of CHtmlOutputParams
       */
      static CHtmlOutputParams Create(const PageLayout evPageLayout);
      /**
       * \brief Get the page layout type.
       *
       * \returns the page layout type
       */
      PageLayout GetPageLayout() const;
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
  inline CHtmlOutputParams::CHtmlOutputParams()
  {
  }
  /*
   *
   */
  inline CHtmlOutputParams::CHtmlOutputParams(const CHtmlOutputParams& argHtmlOutputParams)
    : COutputParams((COutputParams&)argHtmlOutputParams)
  {
  }
  /*
   *
   */
  inline CHtmlOutputParams::CHtmlOutputParams(COutputParamsData* pObj)
    : COutputParams(pObj)
  {
  }
  /*
   *
   */
  inline CHtmlOutputParams::~CHtmlOutputParams()
  {
  }
  /*
   *
   */
  inline COutputParamsData& CHtmlOutputParams::TypedObject() const
  {
    return (COutputParamsData&)Object();
  }
} // namespace
#endif // _chtmloutputparams_h_
