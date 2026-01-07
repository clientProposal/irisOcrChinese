/**
 * \file IBarcodeEnginePreprocess.h
 * Interface for IBarcodeEnginePreprocess class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */

#ifndef _IBarcodeEnginePreprocess_h_
#define _IBarcodeEnginePreprocess_h_

#include <idrskrn.h>
#include <CImage.h>
#include <TObjPtrArray.h>

namespace IDRS
{
  /**
   * \brief IBarcodeEnginePreprocess defines the interface required to provide a custom image preprocessing for a barcode engine.
   *
   * The purpose of image preprocessing options is to enhance the image before it will be processed by the barcode recognition engine
   */
  class IDRSKRN_API IBarcodeEnginePreprocess
  {
  public:
    //! Destructor
    inline virtual ~IBarcodeEnginePreprocess() = default;
    /**
     * \brief Preprocess runs the image preprocessing on the image provided as argument. 
     * The image be modified by this method
     *
     * \param argImage Image to modify.
     *
     * \retval IDRS_SUUCESS if everything is OK, error code otherwise
     */
    inline virtual IDRS_ERROR Preprocess(CImage& argImage);
  };

  typedef TObjPtrArray<IBarcodeEnginePreprocess> CBarcodeEnginePreprocessArray;

  /*
   *
   */
  inline IDRS_ERROR IBarcodeEnginePreprocess::Preprocess(CImage& /*argImage*/)
  {
    return IDRS_SUCCESS;
  }
}
#endif // _IBarcodeEnginePreprocess_h_
