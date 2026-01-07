/**
 * \file COdtOutputParams.h
 * \brief Interface for COdtOutputParams class
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */

#ifndef _codtoutputparams_h_
#define _codtoutputparams_h_
#include <CObjPtr.h>
#include "EnumDefinitions.h"
#include "COutputParams.h"

namespace IDRS
{
  class COutputParamsData;
  class CPageSizeOptions;
  class CJpegCompressionOptions;
  /**
   * \brief COdtOutputParams class manages the parameters to create an Odt file
   */
  class IDRSKRN_API COdtOutputParams : public COutputParams
  {
  public:
    /**
     * \brief Default constructor.
     */
    inline COdtOutputParams();
    /**
     * \brief copy constructor.
     */
    inline COdtOutputParams(const COdtOutputParams& argOdtOutputParams);
    /**
     * \brief constructor from data object.
     */
    inline COdtOutputParams(COutputParamsData* pObj);
    /**
     * \brief destructor.
     */
    inline virtual ~COdtOutputParams();
    /**
     * \brief Create is instantiating a new instance of COdtOutputParams and associated data object
     *
     * \param evPageLayout the page layout type
     *
     * \return New instance of COdtOutputParams
     */
    static COdtOutputParams Create(const PageLayout evPageLayout);
    /**
     * \brief getter for the page layout type.
     *
     * \returns the page layout type
     */
    PageLayout GetPageLayout() const;
    /**
     * \brief Gets the Jpeg Compression Options.
     *
     * \returns the Jpeg compression options object
     */
    CJpegCompressionOptions GetJpegCompressionOptions() const;
    /**
     * \brief Sets the Jpeg Compression Options property.
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
  inline COdtOutputParams::COdtOutputParams()
  {
  }
  /*
   *
   */
  inline COdtOutputParams::COdtOutputParams(const COdtOutputParams& argOdtOutputParams)
    : COutputParams((COutputParams&)argOdtOutputParams)
  {
  }
  /*
   *
   */
  inline COdtOutputParams::COdtOutputParams(COutputParamsData* pObj)
    : COutputParams(pObj)
  {
  }
  /*
   *
   */
  inline COdtOutputParams::~COdtOutputParams()
  {
  }
  /*
   *
   */
  inline COutputParamsData& COdtOutputParams::TypedObject() const
  {
    return (COutputParamsData&)Object();
  }
} // namespace
#endif // _codtoutputparams_h_
