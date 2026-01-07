/**
 * \file IBarcodeEnginePostprocess.h
 * Interface for IBarcodeEnginePostprocess class.
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */

#ifndef _IBarcodeEnginePostprocess_h_
#define _IBarcodeEnginePostprocess_h_

#include <idrskrn.h>
#include <CBarcode.h>

namespace IDRS
{
  /**
   * \brief IBarcodeEnginePostprocess defines the interface required to provide a custom post-processing on barcode results.
   *
   * The purpose of barcode results post-processing is to allow modification of barcode results returned by an engine 
   * before it is actually mixed with the results obtained from other barcode engines
   */
  class IDRSKRN_API IBarcodeEnginePostprocess
  {
  public:
    //! Destructor
    inline virtual ~IBarcodeEnginePostprocess() = default;
    /**
     * \brief Postprocess executes postprocessing on the supplied barcode results
     *
     * \param argResults Barcode results 
     * \param uiSourceEngine Engine that generated the results
     *
     * \retval IDRS_SUUCESS if everything is OK, error code otherwise
     */
    inline virtual IDRS_ERROR Postprocess(CBarcodeArray& argResults, const BarcodeEngineIdentifier uiSourceEngine);
  };

  typedef TObjPtrArray<IBarcodeEnginePostprocess> CBarcodeEnginePostprocessArray;

  /*
   *
   */
  inline IDRS_ERROR IBarcodeEnginePostprocess::Postprocess(CBarcodeArray& /*argResults*/, const BarcodeEngineIdentifier /*uiSourceEngine*/)
  {
    return IDRS_SUCCESS;
  }
}

#endif // _IBarcodeEnginePostprocess_h_
