/**
 * \file CRtfOutputParams.h
 * \brief Interface for CRtfOutputParams class
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */

#ifndef _crtfoutputparams_h_
#define _crtfoutputparams_h_
#include <CObjPtr.h>
#include "COutputParams.h"
#include <EnumDefinitions.h>

namespace IDRS
{
  class COutputParamsData;
  class CJpegCompressionOptions;
  class CPageSizeOptions;
  /**
   * \brief CRtfOutputParams class manages the parameters to create an Rtf file
   */
  class IDRSKRN_API CRtfOutputParams : public COutputParams
  {
  public:
    /**
     * \brief Default constructor.
     */
    inline CRtfOutputParams();
    /**
     * \brief copy constructor.
     */
    inline CRtfOutputParams(const CRtfOutputParams& argRtfOutputParams);
    /**
     * \brief constructor from data object.
     */
    inline CRtfOutputParams(COutputParamsData* pObj);
    /**
     * \brief Default destructor.
     */
    inline virtual ~CRtfOutputParams();
    /**
     * \brief Create is instantiating a new instance of CRtfOutputParams and associated data object
     *
     * \param evPageLayout the page layout type
     *
     * \return New instance of CRtfOutputParams
     */
    static CRtfOutputParams Create(const PageLayout evPageLayout);
    /**
     * \brief Gets the page layout type.
     *
     * \returns the page layout type
     */
    PageLayout GetPageLayout() const;
    /**
     * \brief Gets the Jpeg Compression Options.
     *
     * \returns the Jpeg compression options
     */
    CJpegCompressionOptions GetJpegCompressionOptions() const;
    /**
     * \brief Sets for the Jpeg Compression Options property.
     *
     * \param argJpegCompressionOptions a Jpeg compression options object
     */
    void SetJpegCompressionOptions(const CJpegCompressionOptions& argJpegCompressionOptions);
    /**
     * \brief Gets the page size options.
     *
     * \returns the page size options
     */
    CPageSizeOptions GetPageSizeOptions() const;
    /**
     * \brief Sets the page size options.
     *
     * \param argPageSizeOptions the page size options
     */
    void SetPageSizeOptions(const CPageSizeOptions& argPageSizeOptions);
  private:
    /**
     * Internal use only
     */
    inline COutputParamsData& TypedObject() const;
  };
  /*
   *
   */
  inline CRtfOutputParams::CRtfOutputParams()
  {
  }
  /*
   *
   */
  inline CRtfOutputParams::CRtfOutputParams(const CRtfOutputParams& argRtfOutputParams)
    : COutputParams((COutputParams&)argRtfOutputParams)
  {
  }
  /*
   *
   */
  inline CRtfOutputParams::CRtfOutputParams(COutputParamsData* pObj)
    : COutputParams(pObj)
  {
  }
  /*
   *
   */
  inline CRtfOutputParams::~CRtfOutputParams()
  {
  }
  /*
   *
   */
  inline COutputParamsData& CRtfOutputParams::TypedObject() const
  {
    return (COutputParamsData&)Object();
  }
} // namespace
#endif // _crtfoutputparams_h_
