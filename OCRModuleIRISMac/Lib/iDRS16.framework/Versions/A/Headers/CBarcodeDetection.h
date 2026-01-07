/**
 * \file CBarcodeDetection.h
 * \brief Interface for CBarcodeDetection class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */

#ifndef _CBarcodeDetection_h_
#define _CBarcodeDetection_h_

#include "CObjPtr.h"
#include "CBarcodeParams.h"
#include "IProgressPageProcessing.h"

namespace IDRS
{
  class CBarcodeDetectionData;
  class CPage;
  class CImage;
  /**
   * \brief CBarcodeDetection is the main class used for barcode detection feature
   *
   * This class allows the following operations
   * - Set/get the barcode detection parameters
   * - Set/get the barcode detection progress callback
   * - Run barcode detection and retrieve results
   */
  class IDRSKRN_API CBarcodeDetection : public CObjPtr
  {
  public:
    /**
     * \brief Default constructor. 
     */
    inline CBarcodeDetection();
    /**
     * \brief Copy constructor. 
     * 
     * \param argCBarcodeDetection Object to copy. 
     *
     * This method will initialize the newly created CBarcodeDetection is the data object from argCBarcodeDetection parameter.
     */
    inline CBarcodeDetection(const CBarcodeDetection& argCBarcodeDetection);
    /**
     * \brief Constructor that initializes the associated data object 
     * 
     * \param pargCBarcodeDetectionData Data object containing the state that will be used for the new CBarcodeDetection object
     */
    inline CBarcodeDetection(CObj* pargCBarcodeDetectionData);
    /**
     * \brief Destructor
     */
    inline virtual ~CBarcodeDetection();
    /**
     * \brief Creates a new instance of this class and associates the provided \see CIDRS handle to it.
     * 
     * \param argIdrs CIDRS instance
     */
    static CBarcodeDetection Create(const CIDRS& argIdrs);
    /**
     * \brief Creates a new instance of this class and associates the provided \see CIDRS handle and barcode detection parameters
     * 
     * \param argIdrs CIDRS instance
     * \param argBarcodeParams Object containing the barcode detection parameters
     */
    static CBarcodeDetection Create(const CIDRS& argIdrs, const CBarcodeParams& argBarcodeParams);
    /**
     * \brief Gets the parameters used for the detection (barcode type(s), full page/zonal recognition, etc) 
     * 
     * By default, the barcode detection runs on full page with all barcode types enabled (depends on enabled extensions) 
     * 
     * \return Parameters used for barcode detection.
     */
    CBarcodeParams GetBarcodeParams() const;
    /**
     * \brief Sets the parameters used for barcode detection
     * 
     * By default, the barcode detection runs on full page with all barcode types enabled (depends on enabled extensions) 
     * 
     * \param argBarcodeParams Parameters used for barcode detection.
     */
    void SetBarcodeParams(const CBarcodeParams& argBarcodeParams);
    /**
     * \brief Gets the callback used to notify about barcode detection progress.
     * 
     * The callback mechanism also allows stopping the barcode detection. See \see CProgressBarcodeDetection for more details
     *
     * By default, there's no callback defined for barcode detection, so the returned value will be NULL
     * 
     * \return Pointer to the current progress callback object.
     */
    IProgressPageProcessing* GetProgressCallback() const;
    /**
     * \brief Sets the callback used to notify about barcode detection progress.
     * 
     * The callback mechanism also allows stopping the barcode detection. See \see CProgressBarcodeDetection for more details
     *
     * Please make sure that the provided object lifetime spans the duration of the barcode detection progress. 
     * Deleting the object pointed by argpProgressCallback before/while the barcode detection is running might result in a crash.
     *
     * By default, there's no callback defined for barcode detection, so the returned value will be NULL
     * 
     * \param argpProgressCallback Pointer to the progress callback object that will be used by barcode detection
     */
    void SetProgressCallback(IProgressPageProcessing* argpProgressCallback);
    /**
     * \brief Runs barcode detection and returns the detected barcodes
     *
     * \param argImage Image on which barcode detection will be run
     * 
     * \return Detected barcodes
     */
    CBarcodeArray DetectBarcodes(const CImage& argImage) const;
    /**
     * \brief Runs barcode detection and returns the detected barcodes
     *
     * \param argPage Page on which barcode detection will be run. The page object data will be updated with the recognized barcodes.
     */
    void DetectBarcodes(CPage& argPage) const;

  private:
    // For internal use only
    CBarcodeDetectionData& TypedObject() const
    {
      return (CBarcodeDetectionData&)Object();
    };

  };
	
  /*
   *
   */
  inline CBarcodeDetection::CBarcodeDetection()
  {
  }
  /*
   *
   */
  inline CBarcodeDetection::CBarcodeDetection(const CBarcodeDetection& argCBarcodeDetection)
    : CObjPtr((CObjPtr &)argCBarcodeDetection)
  {
  }
  /*
   *
   */
  inline CBarcodeDetection::CBarcodeDetection(CObj* pargCBarcodeDetectionData)
    : CObjPtr(pargCBarcodeDetectionData)
  {
  }
  /*
   *
   */
  inline CBarcodeDetection::~CBarcodeDetection()
  {
  }
}
#endif // _CBarcodeDetection_h_
