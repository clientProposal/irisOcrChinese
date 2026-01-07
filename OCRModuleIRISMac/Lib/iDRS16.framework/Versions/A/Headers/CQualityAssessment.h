/**
 * \file CQualityAssessment.h
 * Declaration of CQualityAssessment class
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _CQUALITY_ASSESSMENT_H
#define _CQUALITY_ASSESSMENT_H
#include <CIDRS.h>
#include <CPerspective.h>

namespace IDRS
{
  class CQualityAssessmentData;
  /**
   * \brief The CQualityAssessment class offers a set of methods to estimate the OCR quality of a provided image.
   * \ingroup module_prepro_camera_image
   *
   * \req IDRS::Module::Prepro with extension Extension::PreproCameraImage
   *
   * \see Module::Prepro
   * \see Extension::PreproCameraImage for information about camera image extension
   */
  class IDRSKRN_API CQualityAssessment : public CObjPtr
  {
    public:
      /**
       * \brief The default constructor
       */
      inline CQualityAssessment();
      /**
       * \brief Copy constructor.
       *
       * \param argQualityAssessment The smart pointer to copy.
       */
      inline CQualityAssessment ( const CQualityAssessment & argQualityAssessment );
      /**
       * \brief Constructor.
       *
       * \param pQualityAssessmentData The object to point to.
       */
      inline CQualityAssessment ( CQualityAssessmentData * pQualityAssessmentData );
      /**
       * \brief The destructor
       */
      inline virtual ~CQualityAssessment();
      /**
       * \brief Creates a new CQualtityAssessment object to estimate the OCR quality on the provided image.
       * 
       * \return The newly created CQualityAssessment object.
       * \throw CIDRSException if an error occur.
       */
      static CQualityAssessment Create (const CIDRS& argIdrs);
      /**
       * \brief Estimate the OCR quality of a given image
       *
       * If the result is:
       * - Between 0 and 50: the conditions for OCR are bad
       * - Between 50 and 90 : the conditions for OCR are acceptable
       * - Between 90 and 100 : the conditions for OCR are excellent
       *
       * \param argImage the input image
       * \return An estimation value between 0 and 100
       */
      IDRS_UINT EstimateOcrQuality(const CImage& argImage) const;
      /**
       * \brief Estimate the OCR quality of a given image zone defined by corners
       *
       * If the result is:
       * - Between 0 and 50: the conditions for OCR are bad
       * - Between 50 and 90 : the conditions for OCR are acceptable
       * - Between 90 and 100 : the conditions for OCR are excellent
       *
       * \param argImage the input image
       * \param pcPerspectiveCorners zone corners
       * \return An estimation value between 0 and 100
       */
      IDRS_UINT EstimateOcrQuality(const CImage& argImage, const PerspectiveCorners & pcPerspectiveCorners) const;
      /**
       * \brief Estimates the resolution of the image
       *
       * \param argImage the input image
       * \returns The resolution in DPI
       * \throw CIDRSException if an error occured
       */
      IDRS_UINT EstimateResolution(const CImage& argImage) const;
    private:
      CQualityAssessmentData& TypedObject() const
      {
        return (CQualityAssessmentData&) Object();
      }
  };
  /*
   *
   */
  inline CQualityAssessment::CQualityAssessment()
  {
  }
  /*
   *
   */
  inline CQualityAssessment::CQualityAssessment(const CQualityAssessment & argQualityAssessment )
    : CObjPtr((CObjPtr &) argQualityAssessment)
  {
  }
  /*
   *
   */
  inline CQualityAssessment::CQualityAssessment( CQualityAssessmentData * pQualityAssessmentData )
    : CObjPtr((CObj *) pQualityAssessmentData)
  {
  }
  /*
   *
   */
  inline CQualityAssessment::~CQualityAssessment()
  {
  }
}

#endif //_CQUALITY_ASSESSMENT_H
