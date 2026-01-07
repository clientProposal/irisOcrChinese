/**
 * \file CRotate.h
 * \brief Interface for the IDRS::CRotate class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _CRotate_h_
#define _CRotate_h_
#include <CIDRS.h>
#include <CImageOperation.h>
#include <CPage.h>
namespace IDRS
{
  class CRotateData;
  /**
   * \brief The CRotate class offers image rotation features.
   * \ingroup module_prepro
   *
   * The class contains an algorithm for image rotation using all types of images:
   * - black and white
   * - greyscale
   * - color
   *
   * \req IDRS::Module::Prepro
   */
  class IDRSKRN_API CRotate : public CImageOperation
  {
    public:
      /**
       * \brief Default constructor.
       */
      inline CRotate ();
      /**
       * \brief Copy constructor.
       *
       * \param argRotate The smart pointer to copy.
       */
      inline CRotate ( const CRotate & argRotate );
      /**
       * \brief Constructor.
       *
       * \param pRotateData The object to point to.
       */
      inline CRotate ( CRotateData * pRotateData );
      /**
       * \brief Destructor
       */
      inline virtual ~CRotate ();
      /**
       * \brief Creates a new CRotate object.
       *
       * \return The newly created CRotate object.
       *
       * \throw CIDRSException if an error occur.
       */
      static CRotate Create ( const CIDRS & argIDRS );
      /**
       * \brief Rotates the image clockwise by the supplied angle.
       *
       * \note The rotation angle can be any value (integer or floating point) between -360 and 360
       *
       * \pre ! IsNull ()
       * \pre ! argImage.IsNull ()
       * \pre -360 < dAngle < 360
       *
       * \param argImage The image to rotate.
       * \param dAngle The rotation angle in degrees.
       *
       * \remarks The background color used to fill the corners of the resulting image will be white (0xff, 0xff, 0xff)
       *
       * \throw CIDRSException if an error occur.
       */
      void Rotate ( CImage & argImage, const IDRS_DOUBLE dAngle ) const;
      /**
       * \brief Rotates the image clockwise by the supplied angle.
       *
       * \note The rotation angle can be any value (integer or floating point) between -360 and 360
       *
       * \pre ! IsNull ()
       * \pre ! argImage.IsNull ()
       * \pre -360 < dAngle < 360
       *
       * \param argImage The image to rotate.
       * \param dAngle The rotation angle in degrees.
       * \param stBackgroundColor The background color used to fill the corners of the resulting image (if needed)
       *
       * \throw CIDRSException if an error occur.
       */
      void Rotate(CImage& argImage, const IDRS_DOUBLE dAngle, const IDRS_COLOR stBackgroundColor) const;
      /**
       * \brief Rotates the page clockwise by the given angle:
       * - rotates the page's images
       * - rotates the zones of the pages.
       *
       * \attention The rotation doesn't keep the meaning of the zones.
       *
       * \note The rotation angle must be a multiple of 90° ( 90°, 180° or 270° ). Other values currently aren't supported yet.
       *
       * \pre ! IsNull ()
       * \pre ! argPage.IsNull ()
       * \pre (dAngle == 0 || dAngle == 90 || dAngle == 180 || dAngle == 270)
       *
       * \param argPage The page to rotate.
       * \param dAngle The rotation angle in degrees.
       *
       * \throw CIDRSException if an error occur.
       *
       */
      void Rotate ( CPage & argPage, const IDRS_DOUBLE dAngle ) const;
      /**
       * \brief Rotates the image to correct its orientation according to the provided value. After the operation
       * the image will be in straight position.
       *
       * The PageOrientation to provide in argument should be according to the result of orientation detection feature.
       * 
       * \pre ! IsNull ()
       * \pre ! argImage.IsNull ()
       *
       * \param argImage The image to rotate.
       * \param evPageOrientation The orientation to correct.
       *
       * \throw CIDRSException if an error occur.
       */
      void CorrectOrientation(CImage& argImage, const PageOrientation evPageOrientation) const;
      /**
       * \brief Rotates the page to correct its orientation according to the provided value.
       *
       * The PageOrientation to provide should be according to the result of orientation detection feature.
       *
       * \pre ! IsNull ()
       * \pre ! argPage.IsNull ()
       *
       * \param argPage The page to rotate.
       * \param evPageOrientation The orientation to correct.
       *
       * \throw CIDRSException if an error occur.
       */
      void CorrectOrientation(CPage& argPage, const PageOrientation evPageOrientation) const;
    private:
      // For internal use only
      CRotateData & TypedObject () const
      {
        return ( CRotateData & )Object ();
      };
  };
  /*
   *
   */
  inline CRotate::CRotate ()
  {
  }
  /*
   *
   */
  inline CRotate::CRotate ( const CRotate & argRotate )
    : CImageOperation (( CImageOperation & )argRotate )
  {
  }
  /*
   *
   */
  inline CRotate::CRotate ( CRotateData * pRotateData )
    : CImageOperation (( CImageOperationData * )pRotateData )
  {
  }
  /*
   *
   */
  inline CRotate::~CRotate ()
  {
  }
} // namespace
#endif /* _CRotate_h_ */
