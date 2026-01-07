/**
 * \file CPageAnalysis.h
 * \brief Interface for CPageAnalysis class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _CPageAnalysis_h_
#define _CPageAnalysis_h_

#include "CObjPtr.h"
#include "CPageAnalysisParams.h"
#include "IProgressPageProcessing.h"
#include "CPageAnalysisResult.h"
#include "CPage.h"

namespace IDRS
{
  class CPageAnalysisData;
  class CPage;
  class CImage;
  /**
   * \brief CPageAnalysis is the main class used for page analysis feature:
   * - Skew angle detection and correction
   * - Orientation detection and correction
   * - Language detection
   * .
   *
   * This class allows the following operations:
   * - Set/get the page analysis parameters
   * - Set/get the page analysis progress callback
   * - Run page analysis and retrieve results
   */
  class IDRSKRN_API CPageAnalysis : public CObjPtr
  {
  public:
    /**
     * \brief Default constructor. 
     */
    inline CPageAnalysis();
    /**
     * \brief Copy constructor. 
     * 
     * \param argCPageAnalysis Object to copy. 
     *
     * This method will initialize the newly created CPageAnalysis is the data object from argCPageAnalysis parameter.
     */
    inline CPageAnalysis(const CPageAnalysis& argCPageAnalysis);
    /**
     * \brief Constructor that initializes the associated data object 
     * 
     * \param pargCPageAnalysisData Data object containing the state that will be used for the new CPageAnalysis object
     */
    inline CPageAnalysis(CObj* pargCPageAnalysisData);
    /**
     * \brief Destructor
     */
    inline virtual ~CPageAnalysis();
    /**
     * \brief Creates a new instance of this class and associates the provided \see CIDRS handle to it.
     * 
     * \param argIdrs CIDRS instance
     */
    static CPageAnalysis Create(const CIDRS& argIdrs);
    /**
     * \brief Creates a new instance of this class and associates to it the provided \see CIDRS handle and page analysis parameters.
     * 
     * \param argIdrs CIDRS instance
     * \param argPageAnalysisParams Object contain
     */
    static CPageAnalysis Create(const CIDRS& argIdrs, const CPageAnalysisParams& argPageAnalysisParams);
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
     * \param argPageAnalysisParams Parameters to be used for page analysis.
     */
    void SetPageAnalysisParams(const CPageAnalysisParams& argPageAnalysisParams);
    /**
     * \brief Gets the callback used to notify about page analysis progress.
     * 
     * The callback mecchanism also allows stopping the page analyis. See \see CProgressPageAnalysis for more details
     *
     * By default, there's no callback defined for page analysis, so the returned value will be NULL
     * 
     * \return Pointer to the progress callback object to set.
     */
    IProgressPageProcessing* GetProgressCallback() const;
    /**
     * \brief Sets the callback used to notify about page analysis progress.
     * 
     * \param argpProgressCallback Pointer to the progress callback object to set
     */
    void SetProgressCallback(IProgressPageProcessing* argpProgressCallback);
    /**
     * \brief Runs page analysis and returns the detected results
     *
     * \param argImage Image on which analysis will be run.
     * 
     * \return Page analysis results
     *
     * \remarks The provided image will not be modified by this call.
     */
    CPageAnalysisResult AnalyzePage(const CImage& argImage) const;
    /**
     * \brief Runs page analysis and returns the detected results
     *
     * \param argPage Page on which analysis will be run.
     * 
     * \param bUpdatePage If true, this method will correct the orientation/skew of the image whenever orientation or skew detection are enabled.
     * 
     * \return Page analysis results
     *
     * \remarks The provided page will be modified only if the flag bUpdatePage is set to IDRS_TRUE.
     */
    CPageAnalysisResult AnalyzePage(CPage& argPage, const IDRS_BOOL bUpdatePage = IDRS_TRUE) const;
  private:
    // For internal use only
    CPageAnalysisData& TypedObject() const
    {
      return (CPageAnalysisData&)Object();
    };
  };
  
  /*
   *
   */
  inline CPageAnalysis::CPageAnalysis()
  {
  }
  /*
   *
   */
  inline CPageAnalysis::CPageAnalysis(const CPageAnalysis& argCPageAnalysis)
    : CObjPtr((CObjPtr &)argCPageAnalysis)
  {
  }
  /*
   *
   */
  inline CPageAnalysis::CPageAnalysis(CObj* pargCPageAnalysisData)
    : CObjPtr(pargCPageAnalysisData)
  {
  }
  /*
   *
   */
  inline CPageAnalysis::~CPageAnalysis()
  {
  }
}
#endif // _CPageAnalysis_h_
