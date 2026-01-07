/**
 * \file CDeskew.h
 * \brief Interface for the IDRS::CDeskew class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _CDeskew_h_
#define _CDeskew_h_
#include <CIDRS.h>
#include <CImageOperation.h>
namespace IDRS
{
  class CDeskewData;
  /**
   * \brief The CDeskew class offers deskew image correction.
   * \ingroup module_prepro
   *
   * Deskew image correction is normally used for images that were scanned misaligned or photographed from a low angle
   * Deskew/Skew angles are calculated counter-clockwise.
   *
   * \req IDRS::Module::Prepro
   *
   * \see Module::Prepro
   */
  class IDRSKRN_API CDeskew : public CImageOperation
  {
    public:
      /**
       * \brief Default constructor.
       */
      inline CDeskew ();
      /**
       * \brief Copy constructor.
       *
       * \param argDeskew The smart pointer to copy.
       */
      inline CDeskew ( const CDeskew & argDeskew );
      /**
       * \brief Constructor.
       *
       * \param pDeskewData The object to point to.
       */
      inline CDeskew ( CDeskewData * pDeskewData );
      /**
       * \brief Destructor
       */
      inline virtual ~CDeskew ();
      /**
       * \brief Creates a new CDeskew object.
       *
       * \param argIDRS The iDRS
       *
       * \return The newly created CDeskew object.
       *
       * \throw CIDRSException if an error occur.
       */
      static CDeskew Create ( const CIDRS & argIDRS );
      /**
       * \brief DetectSkewAngle analyzes the supplied image and detects its skew angle.
       *
       * The provided image will not be modified.
       *
       * \pre ! IsNull ()
       * \pre ! argImage.IsNull ()
       *
       * \param argImage The image to process.
       *
       * \return The skew angle.
       *
       * \note Deskew handles images skewed upto 10 degrees. It doesn't handle higher skew angles.
       *
       * \throw CIDRSException if an error occur.
       */
      SkewInfo DetectSkewAngle(const CImage& argImage) const;
      /**
       * \brief DetectSkewAngle analyzes the supplied page and detects its skew angle.
       *
       * Detection will be performed based on the source image. The provided page will not be modified.
       *
       * \pre ! IsNull ()
       * \pre ! argPage.IsNull ()
       *
       * \param argPage The page to process.
       *
       * \return The skew angle.
       *
       * \note Deskew handles images skewed upto 10 degrees. It doesn't handle higher skew angles.
       *
       * \throw CIDRSException if an error occur.
       */
      SkewInfo DetectSkewAngle(const CPage& argPage) const;
      /**
       * \brief Deskew analyzes and rotates the image to correct its skew angle.
       *
       * \pre ! IsNull ()
       * \pre ! argImage.IsNull ()
       *
       * \param argImage The image to process.
       *
       * \return The skew angle.
       *
       * \note Deskew handles images skewed upto 10 degrees. It doesn't handle higher skew angles.
       *
       * \throw CIDRSException if an error occur.
       */
      SkewInfo Deskew ( CImage & argImage );
      /**
       * \brief Deskew analyzes and rotates the page to correct its skew angle.
       *
       * The skew angle is always detected on the source image, and applied also to work and background images if existing.
       *
       * \pre ! IsNull ()
       * \pre ! argPage.IsNull ()
       * \pre argPage.GetHeight () && argPage.GetWidth ()
       *
       * \param argPage The page to deskew.
       *
       * \return The skew angle.
       *
       * \note The page's zones are removed.
       *
       * \note Deskew handles images skewed upto 10 degrees. It doesn't handle higher skew angles.
       *
       * \throw CIDRSException if an error occur.
       */
      SkewInfo Deskew ( CPage & argPage );
      /**
       * \brief Correct the skew angle of the image according to the skew info provided.
       *
       * \pre ! IsNull ()
       * \pre ! argImage.IsNull ()
       *
       * \param argImage The image to process.
       * \param stSkewInfo The skew angle.
       *
       * \throw CIDRSException if an error occur.
       */
      void CorrectSkewAngle ( CImage & argImage, const SkewInfo & stSkewInfo );
      /**
       * \brief Correct the skew angle of the provided page according to the skew info provided.
       *
       * The correction is applied on all existing images (source, work and background).
       *
       * \pre ! IsNull ()
       * \pre ! argPage.IsNull ()
       * \pre argPage.GetHeight () && argPage.GetWidth ()
       *
       * \param argPage The page to deskew.
       * \param stSkewInfo The skew angle.
       *
       * \note The page's zone are removed.
       *
       * \throw CIDRSException if an error occur.
       */
      void CorrectSkewAngle ( CPage & argPage, const SkewInfo & stSkewInfo );
      /**
       * \brief Sets the behavior regarding dimension adjustment for deskew.
       *
       * \param evDimensionAdjust The dimension adjust value selected
       */
      void SetDimensionAdjust(const DimensionAdjust evDimensionAdjust);
      /**
       * \brief Retrieves the behavior regarding dimension adjustment for deskew operation.
       *
       * \return The dimension adjust value
       */
      DimensionAdjust GetDimensionAdjust() const;
    private:
      // For internal use only
      CDeskewData & TypedObject () const
      {
        return ( CDeskewData & )Object ();
      };
  };
  /*
   *
   */
  inline CDeskew::CDeskew ()
  {
  }
  /*
   *
   */
  inline CDeskew::CDeskew ( const CDeskew & argDeskew )
    : CImageOperation (( CImageOperation & )argDeskew )
  {
  }
  /*
   *
   */
  inline CDeskew::CDeskew ( CDeskewData * pDeskewData )
    : CImageOperation (( CImageOperationData * )pDeskewData )
  {
  }
  /*
   *
   */
  inline CDeskew::~CDeskew ()
  {
  }
} // namespace
#endif /* _CDeskew_h_ */
