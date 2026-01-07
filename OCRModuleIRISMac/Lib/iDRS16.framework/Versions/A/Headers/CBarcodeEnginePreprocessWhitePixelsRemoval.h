/**
 * \file CBarcodeEnginePreprocessWhitePixelsRemoval.h
 * Interface for CBarcodeEnginePreprocessWhitePixelRemoval class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */

#ifndef _CBarcodeEnginePreprocessWhitePixelRemoval_h_
#define _CBarcodeEnginePreprocessWhitePixelRemoval_h_

#include "idrs.h"

namespace IDRS
{
  /**
   * \brief CBarcodeEnginePreprocessWhitePixelRemoval represents the an implementation of IBarcodeEnginePreprocess that offers white pixels removal
   *
   * This preprocessing operation will use the same operations as CAdvancedDespeckle
   */
  class IDRSKRN_API CBarcodeEnginePreprocessWhitePixelsRemoval : public IBarcodeEnginePreprocess
  {
  public:
    /**
     * \brief Destructor
     */
    inline virtual ~CBarcodeEnginePreprocessWhitePixelsRemoval();
    /**
     * \brief Preprocess runs the image preprocessing on the image provided as argument. 
     *
     * \param argImage Image to modify.
     *
     * \retval IDRS_SUUCESS if everything is OK, error code otherwise
     */
    virtual IDRS_ERROR Preprocess(CImage& argImage);
  };
  /*
   *
   */
  inline CBarcodeEnginePreprocessWhitePixelsRemoval::~CBarcodeEnginePreprocessWhitePixelsRemoval()
  {
  }
}
#endif // _CBarcodeEnginePreprocessWhitePixelRemoval_h_
