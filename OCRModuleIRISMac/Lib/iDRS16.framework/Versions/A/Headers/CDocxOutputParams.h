/**
 * \file CDocxOutputParams.h
 * \brief Interface for CDocxOutputParams class
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */

#ifndef _cdocxoutputparams_h_
#define _cdocxoutputparams_h_
#include <CObjPtr.h>
#include "EnumDefinitions.h"
#include "CJpegCompressionOptions.h"
#include "CPageSizeOptions.h"
namespace IDRS
{
  class COutputParamsData;
  /**
   * \brief CDocxOutputParams class manages the parameters to create a docx file
   */
  class IDRSKRN_API CDocxOutputParams : public COutputParams
  {
    public:
      /**
       * \brief Default constructor.
       */
      inline CDocxOutputParams();
      /**
       * \brief copy constructor.
       */
      inline CDocxOutputParams(const CDocxOutputParams& argDocxOutputParams);
      /**
       * \brief constructor from data object.
       */
      inline CDocxOutputParams(COutputParamsData* pObj);
      /**
       * \brief destructor.
       */
      inline virtual ~CDocxOutputParams();
      /**
       * \brief Create is instantiating a new instance of CDocxOutputParams and associated data object
       *
       * \param evPageLayout the page layout type
       *
       * \return New instance of CDocxOutputParams
       */
      static CDocxOutputParams Create(const PageLayout evPageLayout);
      /**
       * \brief Gets the page layout type.
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
  inline CDocxOutputParams::CDocxOutputParams()
  {
  }
  /*
   *
   */
  inline CDocxOutputParams::CDocxOutputParams(const CDocxOutputParams& argDocxOutputParams)
    : COutputParams((COutputParams&)argDocxOutputParams)
  {
  }
  /*
   *
   */
  inline CDocxOutputParams::CDocxOutputParams(COutputParamsData* pObj)
    : COutputParams(pObj)
  {
  }
  /*
   *
   */
  inline CDocxOutputParams::~CDocxOutputParams()
  {
  }
  /*
   *
   */
  inline COutputParamsData& CDocxOutputParams::TypedObject() const
  {
    return (COutputParamsData&)Object();
  }
} // namespace
#endif // _cdocxoutputparams_h_
