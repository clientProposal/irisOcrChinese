/**
 * \file CBarcodeEnginePreprocessDitherRemoval.h
 * Interface for CBarcodeEnginePreprocessDitherRemoval class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */

#ifndef _CBarcodeEnginePreprocessDitherRemoval_h_
#define _CBarcodeEnginePreprocessDitherRemoval_h_

#include <IBarcodeEnginePreprocess.h>

namespace IDRS
{
  /**
   * \brief CBarcodeEnginePreprocessDitherRemoval represents the an implementation of IBarcodeEnginePreprocess that offers dither removal
   */
  class IDRSKRN_API CBarcodeEnginePreprocessDitherRemoval : public IBarcodeEnginePreprocess
  {
  public:
    /**
     * \brief Destructor
     */
    inline virtual ~CBarcodeEnginePreprocessDitherRemoval();
    /**
     * \brief Preprocess runs the image preprocessing on the image provided as argument. 
     *
     * \param argImage Image to modify.
     *
     * \retval IDRS_SUCCESS if everything is OK, error code otherwise
     */
    virtual IDRS_ERROR Preprocess(CImage& argImage);
  };
  /*
   *
   */
  inline CBarcodeEnginePreprocessDitherRemoval::~CBarcodeEnginePreprocessDitherRemoval()
  {
  }
}

#endif // _CBarcodeEnginePreprocessDitherRemoval_h_
