/**
 * \file CResize.h
 * \brief Interface for the IDRS::CResize class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _CResize_h_
#define _CResize_h_
#include <CIDRS.h>
#include <CImageOperation.h>
#include <CImage.h>
namespace IDRS
{
  class CResizeData;
  /**
   * \brief The CResize class offers image resizing.
   * \ingroup module_prepro
   *
   * The class contains an algorithm for image resizing using all types of images:
   * - black and white
   * - greyscale
   * - color
   *
   * \req IDRS::Module::Prepro
   */
  class IDRSKRN_API CResize : public CImageOperation
  {
    public:
      /**
       * \brief Default constructor.
       */
      inline CResize ();
      /**
       * \brief Copy constructor.
       *
       * \param argResize The smart pointer to copy.
       */
      inline CResize ( const CResize & argResize );
      /**
       * \brief Constructor.
       *
       * \param pResizeData The object to point to.
       */
      inline CResize ( CResizeData * pResizeData );
      /**
       * \brief Destructor
       */
      inline virtual ~CResize ();
      /**
       * \brief Creates a new CResize object.
       *
       * \param argIDRS The iDRS
       *
       * \return The newly created CResize object.
       *
       * \throw CIDRSException if an error occur.
       */
      static CResize Create ( const CIDRS & argIDRS );
      /**
       * \brief Resize resizes the image
       *
       * \pre ! IsNull ()
       * \pre ! argImageSource.IsNull ()
       * \pre uiPercentage > 0
       *
       * \param argImage The image to resize
       * \param uiPercentage The resize percentage.
       */
      void Resize ( CImage & argImage, const IDRS_UINT uiPercentage ) const;
      /**
       * \brief Resize resizes the image
       *
       * \pre ! IsNull ()
       * \pre ! argImageSource.IsNull ()
       * \pre uiNewWidth != 0
       * \pre uiNewHeight != 0
       * \pre uiNewWidth <= IDRS_MAX_IMAGE_WIDTH
       * \pre uiNewHeight <= IDRS_MAX_IMAGE_HEIGHT
       *
       * \param argImage The image to resize
       * \param uiNewWidth The new width.
       * \param uiNewHeight The new height.
       */
      void Resize ( CImage & argImage, const IDRS_UINT uiNewWidth, const IDRS_UINT uiNewHeight ) const;
      /**
       * \brief Resize resizes the image to a new target resolution
       *
       * \pre ! IsNull ()
       * \pre ! argImageSource.IsNull ()
       *
       * \param argImage The image to resize
       * \param uiTargetResolution The new resolution.
       */
      void ResizeToResolution( CImage& argImage, const IDRS_UINT uiTargetResolution ) const;
    private:
      /**
       * \brief DoResize performs the image scaling
       *
       * \pre ! IsNull ()
       * \pre ! argImageSource.IsNull ()
       * \pre ! argImagePixelsTarget.IsNull ()
       * \pre dScaleX != 0
       * \pre dScaleY != 0
       *
       * \param argImagePixelsTarget The pixels of the target image
       * \param argImageSource The source image
       * \param dScaleX The horizontal scaling factor.
       * \param dScaleY The vertical scaling factor.
       */
      void DoResize(CImagePixels& argImagePixelsTarget, const CImage& argImageSource, const IDRS_DOUBLE dScaleX, const IDRS_DOUBLE dScaleY) const;
      /**
       * \brief IntegerReduce Perform an image downscale by an integer factor
       *
       * \pre ! IsNull ()
       * \pre ! argImageSource.IsNull ()
       * \pre ! argImagePixelsTarget.IsNull ()
       * \pre uiReduceFactor != 0
       *
       * \param argImagePixelsTarget The pixels of the target image
       * \param argImageSource The source image
       * \param uiReduceFactor the scaling factor.
       */
      void IntegerReduce(CImagePixels& argImagePixelsTarget, const CImage& argImageSource, const IDRS_UINT uiReduceFactor) const;
      /**
       * \brief IntegerReduce Perform an image upscale by an integer factor
       *
       * \pre ! IsNull ()
       * \pre ! argImageSource.IsNull ()
       * \pre ! argImagePixelsTarget.IsNull ()
       * \pre uiEnlargeFactor != 0
       *
       * \param argImagePixelsTarget The pixels of the target image
       * \param argImageSource The source image
       * \param uiReduceFactor the scaling factor.
       */
      void IntegerEnlarge(CImagePixels& argImagePixelsTarget, const CImage& argImageSource, const IDRS_UINT uiEnlargeFactor) const;
      // For internal use only
      CResizeData & TypedObject () const
      {
        return ( CResizeData & )Object ();
      };
  };
  /*
   *
   */
  inline CResize::CResize () = default;
  /*
   *
   */
  inline CResize::CResize ( const CResize & argResize )
    : CImageOperation (( CImageOperation & )argResize )
  {
  }
  /*
   *
   */
  inline CResize::CResize ( CResizeData * pResizeData )
    : CImageOperation (( CImageOperationData * )pResizeData )
  {
  }
  /*
   *
   */
  inline CResize::~CResize() = default;
} // namespace
#endif /* _CResize_h_ */
