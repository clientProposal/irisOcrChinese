/**
 * \file CImageSource.h
 * \brief Interface for the IDRS::CImageSource class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _cimagesource_h_
#define _cimagesource_h_
#include <CObjPtr.h>
#include <CIDRS.h>
#include <CImage.h>
#include <CImageIO.h>
#include <CPage.h>

namespace IDRS
{
  class CImageSourceData;
  class idrs_string;
  /**
   * \brief The CImageSource class offers method to identify the source of an image.
   *
   * The images can be captured by many different devices, including document scanner and cameras. In order to
   * improve the character recognition accuracy, it can be interesting to apply specific image preprocessing
   * features. The CImageSource class helps identifying the source of an image so the correct preprocessing
   * is done.
   * 
   * <br>When the image source is identified as "Camera", it is recommended to use the CPerspective class to correct
   * any perspective corrections and improve the recognition accuracy. 
   *
   */
  class IDRSKRN_API CImageSource : public CObjPtr
  {
    public:
      /**
       * \brief Default constructor.
       */
      inline CImageSource ();
      /**
       * \brief Copy constructor.
       *
       * \param argImageSource The smart pointer to copy.
       */
      inline CImageSource ( const CImageSource & argImageSource );
      /**
       * \brief Constructor.
       *
       * \param pImageSourceData The object to point to.
       */
      inline CImageSource ( CImageSourceData * pImageSourceData );
      /**
       * \brief Destructor
       */
      inline virtual ~CImageSource ();
      /**
       * \brief Create creates a CImageSource object.
       *
       * \param argIDRS - CIDRS handle object
       *
       * \throw CIDRSException if an error occur.
       *
       */
      static CImageSource Create ( CIDRS argIDRS );
      /**
       * \brief EstimateSourceType analyzes the image to identify its source.
       *
       * \remarks If input file is available, EstimateSourceType() overload taking a file path as argument can be more accurate than the overload
       * taking a CImage as argument, because it will also inspect the EXIF metadata when available.
       *
       * \pre ! argImage.IsNull ()
       *
       * \param argImage The image to analyze.
       * \return The type of the source for the image.
       *
       * \throw CIDRSException if an error occur.
       */
      ImageSource EstimateSourceType ( const CImage & argImage );
      /**
       * \brief EstimateSourceType analyzes the image file to identify its source.
       *
       * \remarks If input file is available, EstimateSourceType() overload taking a file path as argument can be more accurate than the overload
       * taking a CImage as argument, because it will also inspect the EXIF metadata when available.
       *
       * \param strFilePath The path to the file.
       * \return The type of the source for the image.
       *
       * \throw CIDRSException if an error occur.
       *
       */
      ImageSource EstimateSourceType ( const idrs_string &strFilePath );
    private:
      // For internal use only
      CImageSourceData & TypedObject () const
      {
        return ( CImageSourceData & )Object ();
      };
  };
  /*
   *
   */
  inline CImageSource::CImageSource ()
  {
  }
  /*
   *
   */
  inline CImageSource::CImageSource ( const CImageSource & aImageSource )
    : CObjPtr (( CObjPtr & )aImageSource )
  {
  }
  /*
   *
   */
  inline CImageSource::CImageSource ( CImageSourceData * pObj )
    : CObjPtr (( CObj * )pObj )
  {
  }
  /*
   *
   */
  inline CImageSource::~CImageSource ()
  {
  }
} // namespace
#endif /* _cimagesource_h_ */
