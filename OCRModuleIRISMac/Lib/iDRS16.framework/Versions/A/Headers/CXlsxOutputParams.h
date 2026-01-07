/**
 * \file CXlsxOutputParams.h
 * \brief Interface for CXlsxOutputParams class
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */

#ifndef _cxlsxoutputparams_h_
#define _cxlsxoutputparams_h_
#include <CObjPtr.h>
#include <idrs.h>
#include <COutputParams.h>
#include <EnumDefinitions.h>
#include <CJpegCompressionOptions.h>
namespace IDRS
{
  class COutputParamsData;
  /**
   * \brief CXlsxOutputParams class manages the parameters to create an xlsx file
   */
  class IDRSKRN_API CXlsxOutputParams : public COutputParams
  {
    public:
      /**
       * \brief Default constructor.
       */
      inline CXlsxOutputParams();
      /**
       * \brief copy constructor.
       */
      inline CXlsxOutputParams(const CXlsxOutputParams& argXlsxOutputParams);
      /**
       * \brief constructor from data object.
       */
      inline CXlsxOutputParams(COutputParamsData* pObj);
      /**
       * \brief Default destructor.
       */
      inline virtual ~CXlsxOutputParams();
      /**
       * \brief Create is instantiating a new instance of CXlsxOutputParams and associated data object
       *
       * \param evSpreadsheetLayout spreadsheet layout type
       *
       * \return New instance of CXlsxOutputParams
       */
      static CXlsxOutputParams Create(const SpreadsheetLayout evSpreadsheetLayout);
      /**
       * \brief getter for the spreadsheet layout.
       *
       * \returns the spreadsheet layout type
       */
      SpreadsheetLayout GetSpreadsheetLayout() const;
      /**
       * \brief getter for the Jpeg Compression Options.
       *
       * \returns the Jpeg compression options object
       */
      CJpegCompressionOptions GetJpegCompressionOptions() const;
      /**
       * \brief setter for the Jpeg Compression Options property.
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
  inline CXlsxOutputParams::CXlsxOutputParams()
  {
  }
  /*
   *
   */
  inline CXlsxOutputParams::CXlsxOutputParams(const CXlsxOutputParams& argXlsxOutputParams)
    : COutputParams((COutputParams&)argXlsxOutputParams)
  {
  }
  /*
   *
   */
  inline CXlsxOutputParams::CXlsxOutputParams(COutputParamsData* pObj)
    : COutputParams(pObj)
  {
  }
  /*
   *
   */
  inline CXlsxOutputParams::~CXlsxOutputParams()
  {
  }
  /*
   *
   */
  inline COutputParamsData& CXlsxOutputParams::TypedObject() const
  {
    return (COutputParamsData&)Object();
  }
} // namespace
#endif //_cxlsxoutputparams_h_
