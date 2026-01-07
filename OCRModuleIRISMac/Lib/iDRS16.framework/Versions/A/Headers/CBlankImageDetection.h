/**
 * \file CBlankImageDetection.h
 * \brief Interface for the IDRS::CBlankImageDetection class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _CBlankImageDetection_h_
#define _CBlankImageDetection_h_
#include <EnumDefinitions.h>
#include <CIDRS.h>
#include <CImageOperation.h>
namespace IDRS
{
  class CBlankImageDetectionData;
  /**
   * \brief The CBlankImageDetection class offers blank image detection features
   * \ingroup module_prepro
   *
   * It contains an implementation of blank image detection algorithm that is able to detect whether a image contains any useful information.
   * The algorithm can work with images obtained from various paper sources, like glaring white, yellow old paper or gray recycled paper.
   *
   * \req IDRS::Module::Prepro
   */
  class IDRSKRN_API CBlankImageDetection : public CImageOperation
  {
    public:
      /**
       * \brief Default constructor.
       */
      inline CBlankImageDetection ();
      /**
       * \brief Copy constructor.
       *
       * \param argBlankImageDetection The smart pointer to copy.
       */
      inline CBlankImageDetection ( const CBlankImageDetection & argBlankImageDetection );
      /**
       * \brief Constructor.
       *
       * \param pBlankImageDetectionData The object to point to.
       */
      inline CBlankImageDetection ( CBlankImageDetectionData * pBlankImageDetectionData );
      /**
       * \brief Destructor
       */
      inline virtual ~CBlankImageDetection ();
      /**
       * \brief Creates a new CBlankImageDetection object.
       *
       * \param argIDRS The iDRS
       *
       * \return The newly created CBlankImageDetection object.
       *
       * \remarks The default blank detection mode used is BlankImageDetectionMode::Advanced which gives the most accurate results.
       *
       * \throw CIDRSException if an error occur.
       */
      static CBlankImageDetection Create ( const CIDRS & argIDRS );
      /**
       * \brief Sets the detection mode.
       *
       * \param evBlankImageDetectionMode The detection mode to set
       */
      void SetDetectionMode (const BlankImageDetectionMode evBlankImageDetectionMode);
      /**
       * \brief Returns the detection mode.
       *
       * \remarks The default blank detection mode used is BlankImageDetectionMode::Advanced which gives the most accurate results.
       *
       * \return The detection mode
       */
      BlankImageDetectionMode GetDetectionMode () const;
      /**
       * \brief Sets the detection sensitivity.
       *
       * \param evBlankImageDetectionSensitivity The detection sensitivity to set
       */
      void SetDetectionSensitivity(const BlankImageDetectionSensitivity evBlankImageDetectionSensitivity);
      /**
       * \brief Returns the detection sensitivity.
       *
       * \return The detection sensitivity
       */
      BlankImageDetectionSensitivity GetDetectionSensitivity() const;
      /**
       * \brief IsBlank detects blank images.
       *
       * \pre ! IsNull ()
       * \pre ! argImage.IsNull ()
       *
       * \param argImage The image to analyze.
       *
       * \retval IDRS_TRUE if the image is considered as blank.
       * \retval IDRS_FALSE otherwise.
       *
       */
      IDRS_BOOL IsBlank ( const CImage & argImage ) const;
    private:
      // For internal use only
      CBlankImageDetectionData & TypedObject () const
      {
        return ( CBlankImageDetectionData & )Object ();
      };
  };
  /*
   *
   */
  inline CBlankImageDetection::CBlankImageDetection ()
  {
  }
  /*
   *
   */
  inline CBlankImageDetection::CBlankImageDetection ( const CBlankImageDetection & argBlankImageDetection )
    : CImageOperation (( CImageOperation & )argBlankImageDetection )
  {
  }
  /*
   *
   */
  inline CBlankImageDetection::CBlankImageDetection ( CBlankImageDetectionData * pBlankImageDetectionData )
    : CImageOperation (( CImageOperationData * )pBlankImageDetectionData )
  {
  }
  /*
   *
   */
  inline CBlankImageDetection::~CBlankImageDetection ()
  {
  }
} // namespace
#endif /* _CBlankImageDetection_h_ */
