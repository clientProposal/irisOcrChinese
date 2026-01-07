/**
 * \file CPageAnalysisResult.h
 * \brief Interface for CPageAnalysisResult class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _CPageAnalysisResult_h_
#define _CPageAnalysisResult_h_

#include "CObjPtr.h"
#include "ArrayDefinitions.h"

namespace IDRS
{
  class CPageAnalysisResultData;

  /**
   * \brief CPageAnalysisResult contains the results of page analysis. See \see CPageAnalysis  
   */
  class IDRSKRN_API CPageAnalysisResult : public CObjPtr
  {
  public:
    /**
     * \brief Default constructor. 
     */
    inline CPageAnalysisResult();
    /**
     * \brief Copy constructor. 
     * 
     * \param argCPageAnalysisResult Object to copy. 
     *
     * This method will initialize the newly created CPageAnalysisResult with the data object from argCPageAnalysisResult parameter.
     */
    inline CPageAnalysisResult(const CPageAnalysisResult& argCPageAnalysisResult);
    /**
     * \brief Constructor that initializes the associated data object 
     * 
     * \param pargCPageAnalysisResultData Data object containing the state that will be used for the new CPageAnalysisResult object
     */
    inline CPageAnalysisResult(CObj* pargCPageAnalysisResultData);
    /**
     * \brief Destructor
     */
    inline virtual ~CPageAnalysisResult();
    /**
     * \brief Creates a new CPageAnalysisResult object instance
     */
    static CPageAnalysisResult Create();
    /**
     * \brief Gets the page orientation
     * 
     * \return Page orientation
     */
    PageOrientation GetPageOrientation() const;
    /**
     * \brief Gets the page/image skew information
     *
     * \return Skew information
     */
    SkewInfo GetSkew() const;
    /**
     * \brief Gets the detected language
     *
     * \return Detected language
     */
    LanguageCandidateArray GetLanguages() const;
    /**
     * \brief Gets the confidence level for the detected features.
     *
     * \return Confidence level
     */
    IDRS_UINT GetPageOrientationConfidence() const;
    /**
     * \brief Computes the angle in degrees based on a \see SkewInfo structure
     * 
     * \return Angle in degrees
     */
    static IDRS_DOUBLE ComputeSkewAngle(const SkewInfo& stSkewInfo);

  private:
    // For internal use only
    CPageAnalysisResultData& TypedObject() const
    {
      return (CPageAnalysisResultData&)Object();
    };
  };


  /*
   *
   */
  inline CPageAnalysisResult::CPageAnalysisResult()
  {
  }
  /*
   *
   */
  inline CPageAnalysisResult::CPageAnalysisResult(const CPageAnalysisResult& argCPageAnalysisResult)
    : CObjPtr((CObjPtr &)argCPageAnalysisResult)
  {
  }
  /*
   *
   */
  inline CPageAnalysisResult::CPageAnalysisResult(CObj* pargCPageAnalysisResultData)
    : CObjPtr(pargCPageAnalysisResultData)
  {
  }
  /*
   *
   */
  inline CPageAnalysisResult::~CPageAnalysisResult()
  {
  }
}
#endif // _CPageAnalysisResult_h_
