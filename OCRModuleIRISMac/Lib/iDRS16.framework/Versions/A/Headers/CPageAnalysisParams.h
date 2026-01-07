/**
 * \file CPageAnalysisParams.h
 * \brief Interface for CPageAnalysisParams class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _CPageAnalysisParams_h_
#define _CPageAnalysisParams_h_

#include <CObjPtr.h>
#include <ArrayDefinitions.h>

namespace IDRS
{
  class CPageAnalysisParamsData;  
  /**
   * \brief CPageAnalysisParams contains the configuration for page analysis.
   * 
   * This class allows setting the following page analysis options:
   * - Detect skew angle
   * - Detect page orientation
   * - Detect text languages used in the analysed image/page
   */
  class IDRSKRN_API CPageAnalysisParams : public CObjPtr
  {
  public:
    /**
     * \brief Default constructor. 
     */
    inline CPageAnalysisParams();
    /**
     * \brief Copy constructor. 
     * 
     * \param argCPageAnalysisParams Object to copy. 
     *
     * This method will initialize the newly created CPageAnalysisParams with the data object from argCPageAnalysisParams parameter.
     */
    inline CPageAnalysisParams(const CPageAnalysisParams& argCPageAnalysisParams);
    /**
     * \brief Constructor that initializes the associated data object 
     * 
     * \param pargCPageAnalysisParamsData Data object containing the state that will be used for the new CPageAnalysisParams object
     */
    inline CPageAnalysisParams(CPageAnalysisParamsData* pargCPageAnalysisParamsData);
    /**
     * \brief Destructor
     */
    inline virtual ~CPageAnalysisParams();
    /**
     * \brief Creates a new instance of this class
     */
    static CPageAnalysisParams Create();
    /**
     * \brief Gets the boolean flag indicating whether skew detection should be executed as part of page analysis
     * 
     * \return Boolean flag enabling/disabling skew detection
     */
    SkewDetection GetSkewDetection() const;
    /**
     * \brief Sets the boolean flag indicating whether skew detection should be executed as part of page analysis
     * 
     * \param evSkewDetection Boolean flag enabling/disabling skew detection
     */
    void SetSkewDetection(const SkewDetection evSkewDetection);
    /**
     * \brief Gets the boolean flag indicating whether image should be cropped after deskew during page analysis
     *
     * \return Boolean flag enabling/disabling dimension adjust
     */
    DimensionAdjust GetDimensionAdjust() const;
    /**
     * \brief Sets the boolean flag indicating whether image should be cropped after deskew during page analysis
     *
     * \param evDimensionAdjust Boolean flag enabling/disabling dimension adjust
     */
    void SetDimensionAdjust(const DimensionAdjust evDimensionAdjust);
    /**
     * \brief Gets the boolean flag indicating whether page orientation should be executed as part of page analysis
     * 
     * \return Boolean flag enabling/disabling page orientation detection
     */
    IDRS_BOOL GetDetectOrientation() const;
    /**
     * \brief Sets the boolean flag indicating whether page orientation should be executed as part of page analysis
     * 
     * \param bDetectOrientation Boolean flag enabling/disabling page orientation detection
     */
    void SetDetectOrientation(const IDRS_BOOL bDetectOrientation);
    /**
     * \brief Gets the array with all possible page orientations that page analysis is allowed to take into consideration.
     *
     * Not setting this parameter will allow the page orientation algorithm to take all page orientations into consideration.
     * It is not advisable to restrict the page orientations for the page analysis. This should be done only in specific conditions.
     * 
     * \return Array containing all page orientation that are allowed during page analysis 
     */
    PageOrientationArray GetOrientations() const;
    /**
     * \brief Sets the array with all possible page orientations that page analysis is allowed to take into consideration.
     *
     * Not setting this parameter will allow the page orientation algorithm to take all page orientations into consideration.
     * It is not advisable to restrict the page orientations for the page analysis. This should be done only in specific conditions.
     * 
     * \param argxOrientations Array containing all page orientation that are allowed during page analysis 
     */
    void SetOrientations(const PageOrientationArray& argxOrientations);
    /**
     * \brief Gets the boolean flag indicating whether language detection should be executed as part of page analysis
     * 
     * \return Boolean flag enabling/disabling language detection detection
     */
    IDRS_BOOL GetDetectLanguage() const;
    /**
     * \brief Sets the boolean flag indicating whether language detection should be executed as part of page analysis
     * 
     * \param bDetectLanguage Boolean flag enabling/disabling language detection detection
     */
    void SetDetectLanguage(const IDRS_BOOL bDetectLanguage);
    /**
     * \brief Gets the array with all possible languages that page analysis is allowed to take into consideration.
     * 
     * \return Array containing all languages that are allowed during page analysis 
     */
    LanguageArray GetAllowedLanguages() const;
    /**
     * \brief Sets the array with all possible languages that page analysis is allowed to take into consideration.
     *
     * Not setting this parameter will allow the language detection algorithm to take all supported languages into consideration.
     * 
     * \param xLanguages Array containing all languages that are allowed during page analysis 
     */
    void SetAllowedLanguages(const LanguageArray& xLanguages);
  private:
    //! Internal use 
    CPageAnalysisParamsData& TypedObject() const
    {
      return (CPageAnalysisParamsData&)Object();
    };

  };
	
  /*
   *
   */
  inline CPageAnalysisParams::CPageAnalysisParams()
  {
  }
  /*
   *
   */
  inline CPageAnalysisParams::CPageAnalysisParams(const CPageAnalysisParams& argCPageAnalysisParams)
    : CObjPtr((CObjPtr &)argCPageAnalysisParams)
  {
  }
  /*
   *
   */
  inline CPageAnalysisParams::CPageAnalysisParams(CPageAnalysisParamsData* pargCPageAnalysisParamsData)
    : CObjPtr((CObj *)pargCPageAnalysisParamsData)
  {
  }
  /*
   *
   */
  inline CPageAnalysisParams::~CPageAnalysisParams()
  {
  }
}
#endif // _CPageAnalysisParams_h_
