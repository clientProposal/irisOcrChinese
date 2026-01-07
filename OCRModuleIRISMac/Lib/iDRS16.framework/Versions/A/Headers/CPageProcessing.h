/**
 * \file CPageProcessing.h
 * \brief Interface for CPageProcessing class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _CPageProcessing_h_
#define _CPageProcessing_h_

#include "CObjPtr.h"
#include "CPageAnalysisParams.h"
#include "CBarcodeParams.h"
#include "COcrParams.h"
#include "IProgressPageProcessing.h"

namespace IDRS
{
  class CPageProcessingData;
  class CPage;
  class CImage;
  /**
   * \brief CPageProcessing exposes all recognition features of iDRS SDK: page analysis, text recognition and barcode detection
   *
   * Each of these features can be enabled/disabled. 
   * The order in which the features are executed is:
   * 1. page analysis
   * 2. barcode detection
   * 3. text recognition
   */
  class IDRSKRN_API CPageProcessing : public CObjPtr
  {
  public:
    /**
     * \brief Default constructor.
     */
    inline CPageProcessing();
    /**
     * \brief Copy constructor.
     *
     * \param argCPageProcessing Object to copy.
     *
     * This method will initialize the newly created CPageProcessing is the data object from argCPageProcessing parameter.
     */
    inline CPageProcessing(const CPageProcessing& argCPageProcessing);
    /**
     * \brief Constructor that initializes the associated data object
     *
     * \param pargCPageProcessingData Data object containing the state that will be used for the new CPageProcessing object
     */
    inline CPageProcessing(CObj* pargCPageProcessingData);
    /**
     * \brief Destructor
     */
    inline virtual ~CPageProcessing();
    /**
     * \brief Creates a new instance of this class and associates the provided \see CIDRS handle to it.
     *
     * \param argIdrs CIDRS instance
     * 
     * \return Newly created object
     */
    static CPageProcessing Create(CIDRS& argIdrs);
    /**
     * \brief Gets the parameters used for the page analysis (language detection, orientation detection, skew detection)
     *
     * By default, the page analysis will only preform orientation detection
     *
     * \return Parameters used for page analysis.
     */
    CPageAnalysisParams GetPageAnalysisParams() const;
    /**
     * \brief Gets the parameters used for the page analysis (language detection, orientation detection, skew detection)
     *
     * By default, the page analysis will only preform orientation detection.
     *
     * \param argPageAnalysisParams Parameters to be used for page analysis.
     *
     * \remarks Language detection result is only used when full page text recognition is used, when zonal recognition is used then language detection is ignored.
     */
    void SetPageAnalysisParams(const CPageAnalysisParams& argPageAnalysisParams);
    /**
     * \brief Gets the boolean flag that enables/disables the page analysis
     *
     * \return Boolean flag that enables/disables page analysis
     */
    IDRS_BOOL GetRunPageAnalysis() const;
    /**
     * \brief Sets the boolean flag that enables/disables the page analysis
     *
     * \param bAnalysePage Boolean flag that enables/disables page analysis
     */
    void SetRunPageAnalysis(const IDRS_BOOL bAnalysePage);
    /**
     * \brief Gets the boolean flag that enables/disables the barcode detection
     *
     * \return Boolean flag that enables/disables text barcode detection
     */
    IDRS_BOOL GetRunBarcodeDetection() const;
    /**
     * \brief Sets the boolean flag that enables/disables the barcode detection
     *
     * \param bDetectBarcodes Boolean flag that enables/disables barcode detection
     */
    void SetRunBarcodeDetection(const IDRS_BOOL bDetectBarcodes);
    /**
     * \brief Gets the boolean flag that enables/disables the text recognition
     *
     * \return Boolean flag that enables/disables text recognition
     */
    IDRS_BOOL GetRunTextRecognition() const;
    /**
     * \brief Sets the boolean flag that enables/disables the text recognition
     *
     * \param bRecognizeText Boolean flag that enables/disables text recognition
     */
    void SetRunTextRecognition(const IDRS_BOOL bRecognizeText);
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
     * \brief Gets the parameters used for the ocr (language(s), full page/zonal recognition, etc)
     *
     * By default, the ocr runs on full page with english language enabled
     *
     * \return Parameters used for ocr.
     */
    COcrParams GetOcrParams() const;
    /**
     * \brief Sets the parameters used for the ocr (language(s), full page/zonal recognition, etc).
     *
     * By default, the ocr runs on full page with english language enabled
     *
     * \param argOcrParams Parameters used for ocr.
     *
     * \remarks If OCR is set to full page recognition, and language detection has been enabled in the page analysis params,
     * then the language(s) provided therein will be used only as fallback value if language detection failed;
     * otherwise the detected language will be used instead for OCR.
     * \remarks If OCR is set to zonal recognition, then the language detection result will be ignored
     */
    void SetOcrParams(const COcrParams& argOcrParams);
    /**
     * \brief Gets the callback used to notify about page processing progress.
     *
     * The callback mechanism also allows stopping the page processing. See \see IProgressPageProcessing for more details
     *
     * By default, there's no callback defined for page processing, so the returned value will be NULL
     *
     * \return Pointer to the current progress callback object.
     */
    IProgressPageProcessing* GetProgressCallback() const;
    /**
     * \brief Sets the callback used to notify about page processing progress.
     *
     * The callback mechanism also allows stopping the page processing. See \see IProgressPageProcessing for more details
     *
     * By default, there's no callback defined for page processing, so the returned value will be NULL
     *
     * \param pProgressCallback Pointer to the progress callback object to set.
     */
    void SetProgressCallback(IProgressPageProcessing* pProgressCallback);
    /**
     * \brief Runs the page processing. This method is executing the following operations (if enabled), in succession. 
     * - Page analysis
     * - Barcode detection
     * - Text recognition
     * If any of the above operations is not specifically enabled, then it will not be executed
     *
     * \param argPage The page to process. Page's content will be updated with the results.
     */
    void ProcessPage(CPage& argPage);

  private:
    // For internal use only
    CPageProcessingData& TypedObject() const
    {
      return (CPageProcessingData&)Object();
    };

  };
	
  /*
   *
   */
  inline CPageProcessing::CPageProcessing()
  {
  }
  /*
   *
   */
  inline CPageProcessing::CPageProcessing(const CPageProcessing& argCPageProcessing)
    : CObjPtr((CObjPtr &)argCPageProcessing)
  {
  }
  /*
   *
   */
  inline CPageProcessing::CPageProcessing(CObj* pargCPageProcessingData)
    : CObjPtr(pargCPageProcessingData)
  {
  }
  /*
   *
   */
  inline CPageProcessing::~CPageProcessing()
  {
  }
}
#endif // _CPageProcessing_h_
