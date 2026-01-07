/**
 * \file CPerspective.h
 * \brief Interface for the IDRS::CPerspective class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _CPerspective_h_
#define _CPerspective_h_
#include <CIDRS.h>
#include <CImageOperation.h>
#include <CPolygon.h>
namespace IDRS
{
  class CPerspectiveData;
  /**
   * \brief The CPerspective class offers perspective correction of document images captured by a camera. Perspective distortions are a frequent phenomenon when it comes to camera-based document images and their correction is highly recommended as it increases significantly the recognition accuracy. The CPerspective class can be used for all types of document images (document images containing barcodes, printed or handwritten text).  
   * \ingroup module_prepro_camera_image
   *
   * <b>IMPORTANT</b>
   * <br> To clarify any confusion between the deskew correction and the perspective correction, it is important to note that the first one is needed for scanned image documents (estimation of the rotation angle of the distorted image) whereas the second one for camera-captured document images (estimation of many parameters).
   * <br> To identify the source of an image (scanner, camera or unknown), please use the CImageSource class. 
   *
   * \req IDRS::Module::Prepro with Extension::PreproCameraImage
   *
   * \see Module::Prepro
   * \see Extension::PreproCameraImage for information about mobile capture extension
   */
  class IDRSKRN_API CPerspective : public CImageOperation
  {
    public:
      /**
       * \brief Default constructor.
       */
      inline CPerspective ();
      /**
       * \brief Copy constructor.
       *
       * \param argPerspective The smart pointer to copy.
       */
      inline CPerspective ( const CPerspective & argPerspective );
      /**
       * \brief Constructor.
       *
       * \param pPerspectiveData The object to point to.
       */
      inline CPerspective ( CPerspectiveData * pPerspectiveData );
      /**
       * \brief Destructor
       */
      inline virtual ~CPerspective ();
      /**
       * \brief Creates a new CPerspective object 
       *
       * \pre ! objIdrs.IsNull ()
       *
       * \param objIdrs Idrs handle
       *
       * \return The newly created CPerspective object.
       *
       * \throw CIDRSException if an error occur.
       */
      static CPerspective Create ( const CIDRS& objIdrs );
      /**
       * \brief DetectDocumentCorners retrieves the corners for the supplied image.
       *
       * \pre ! IsNull ()
       *
       * \param argImage The image for which the perspective distortion corners will be computed.
       * \return The perspective distortion corners.
       * 
       * \throw CIDRSException if an error occur.
       */
      PerspectiveCorners DetectDocumentCorners (const CImage& argImage);
      /**
       * \brief ApplyCorrection corrects perspective distortion of the supplied image using the provided corners.
       *
       * \pre ! IsNull ()
       *
       * \param argImage The image where perspective distortions will be corrected, using the corners provided in pcPerspectiveCorners
       * \param stPerspectiveCorners The corners of corrected document (usually obtained using \see DetectDocumentCorners).
       *
       * \throw CIDRSException if an error occur.
       */
      void CorrectPerspective ( CImage& argImage, const PerspectiveCorners & stPerspectiveCorners );
      /**
       * \brief Sets the flag to crop to document area.
       *
       * If the flag is set to IDRS_TRUE, the method CorrectPerspective () will crop the underlying CImage or CPage object
       * so that it contains only the area delimited by the four corners provided as parameters.
       * If the flag is set to IDRS_FALSE, the method CorrectPerspective () will keep all pixels of the underlying
       * CImage object (and add extra pixels for area not represented by the original image)
       * 
       * \remarks If the flag is set to IDRS_FALSE, the method DetectDocumentCorners() may fail with a specific exception thrown: IDRS_ERROR_PREPRO_CAMERA_IMAGE_PERSPECTIVE_DISTORTION_TOO_LARGE.
       * This will happen when the detected perspective is considered too large; which consists in the following cases:
       * - The angle of any of the corners is less than 23 degrees
       * - The dimension (width or height) of the corrected image would be more than 2.5 times the corresponding dimension of the original image.
       * When such an exception is thrown, an integrator can fallback to performing perspective correction with CropToDocumentArea flag set to IDRS_TRUE.
       *
       * \param bCropToDocumentArea the value for the flag.
       */
      void SetCropToDocumentArea ( const IDRS_BOOL bCropToDocumentArea );
      /**
       * \brief Gets the flag to crop to document area.
       *
       * If the flag is set to IDRS_TRUE, the method CorrectPerspective () will crop the underlying CImage or CPage object
       * so that it contains only the area delimited by the four corners provided as parameters.
       * If the flag is set to IDRS_FALSE, the method CorrectPerspective () will keep all pixels of the underlying
       * CImage object (and add extra pixels for area not represented by the original image)
       *
       * Default value for the flag is IDRS_TRUE.
       *
       * \return The value of the flag.
       */
      IDRS_BOOL GetCropToDocumentArea () const;
    private:
      // For internal use only
      CPerspectiveData & TypedObject () const
      {
        return ( CPerspectiveData & )Object ();
      };
  };
  /*
   *
   */
  inline CPerspective::CPerspective ()
  {
  }
  /*
   *
   */
  inline CPerspective::CPerspective ( const CPerspective & argPerspective )
    : CImageOperation (( CImageOperation & )argPerspective )
  {
  }
  /*
   *
   */
  inline CPerspective::CPerspective ( CPerspectiveData * pPerspectiveData )
    : CImageOperation (( CImageOperationData * )pPerspectiveData )
  {
  }
  /*
   *
   */
  inline CPerspective::~CPerspective ()
  {
  }
} // namespace
#endif /* _CPerspective_h_ */
