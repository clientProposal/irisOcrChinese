/**
 * \file CImage.h
 * \brief Interface for the IDRS::CImage class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _cimage_h_
#define _cimage_h_
#include <EnumDefinitions.h>
#include <CObjPtr.h>
#include <CIDRS.h>
#include <CImagePixels.h>
#include <CImageSaveOptions.h>
#include <IByteStream.h>
#include <CImageLoadOptions.h>
namespace IDRS
{
  class CImageData;
  class CImgPartData;
  class ILineReader;
  class CImgCompressor;
  class IBaseImagePlugin;
  /**
   * \brief The CImage class manages images for iDRS.
   * \ingroup module_core module_image_formats
   *
   * An image is a buffer of pixels and some characteristics such as width, height, resolution.
   *
   * The class CImage offers a set of convenient methods for loading, saving and manipulating image pixels.
   * Internally the class stores the data in uncompressed format.
   *
   * \see ColorMode for color modes
   *
   */
  class IDRSKRN_API CImage : public CObjPtr
  {
    friend class CPage;
    friend class CDeskewLogic;
    friend class CRotateUtil;
    friend class CIDRSObjectAccess;
    public:
      /**
       * \brief Default constructor.
       */
      inline CImage ();
      /**
       * \brief Copy constructor.
       *
       * \param argImage The smart pointer to copy.
       */
      inline CImage ( const CImage & argImage );
      /**
       * \brief Constructor.
       *
       * \param pImageData The object to point to.
       */
      inline CImage ( CImageData * pImageData );
      /**
       * \brief Destructor
       */
      inline virtual ~CImage ();
      /**
       * \brief Create creates an empty image.
       *
       * \param argIDRS - CIDRS handle object
       *
       * \throw CIDRSException if an error occur.
       *
       */
      static CImage Create ( CIDRS argIDRS );
      /**
       * \brief Create creates an image buffer with the given characteristics.
       *
       * \pre uiWidth != 0 && uiHeight != 0
       * \pre colorMode == BLACK_AND_WHITE || itImgType == GREYSCALE || itImgType == COLOR
       *
       * \param argIDRS - CIDRS handle object
       * \param uiWidth The width in pixels of the image.
       * \param uiHeight The height in pixels of the image.
       * \param colorMode The image color mode.
       * \param uiResolution The resolution of the image.
       *
       * \throw CIDRSException if an error occur.
       *
       */
      static CImage Create ( CIDRS argIDRS, const IDRS_UINT32 uiWidth, const IDRS_UINT32 uiHeight, const ColorMode colorMode,
                             const IDRS_UINT32 uiResolution );
      /**
       * \brief Creates an image and initializes it with the content of the supplied image parameter
       *
       * \param argImage - the source image that will be copied to the newly created image
       */
      static CImage Create ( const CImage & argImage );
      /**
       * \brief CreateBitmap modifies the current image buffer to fit to the specified characteristics.
       *
       * \pre ! IsNull ()
       * \pre uiWidth != 0 && uiHeight != 0
       * \pre itImgType == BLACK_AND_WHITE || itImgType == GREYSCALE || itImgType == COLOR
       *
       * \param uiWidth The width in pixels of the image.
       * \param uiHeight The height in pixels of the image.
       * \param colorMode The color mode
       * \param uiResolution The resolution of the image.
       *
       * \throw CIDRSException if an error occur.
       *
       */
      void CreateBitmap ( const IDRS_UINT uiWidth, const IDRS_UINT uiHeight, const ColorMode colorMode, const IDRS_UINT uiResolution );
      /**
       * \brief CreateBitmap modifies the current image buffer to meet the characteristics and sets its lines using the
       * given line reader.
       *
       * \pre ! IsNull ()
       * \pre uiWidth != 0 && uiHeight != 0
       *
       * \param uiWidth The width in pixels of the image.
       * \param uiHeight The height in pixels of the image.
       * \param colorMode The color mode
       * \param uiResolution The resolution of the image.
       * \param lrLineReader The object that provides the lines of the image.
       *
       * \see ILineReader
       *
       * \throw CIDRSException if an error occur.
       *
       */
      void CreateBitmap ( const IDRS_UINT uiWidth, const IDRS_UINT uiHeight, const ColorMode colorMode, const IDRS_UINT uiResolution,
                          ILineReader & lrLineReader );
      /**
       * \brief Clone the current image.
       *
       * \pre ! IsNull ()
       *
       * \return The cloned image.
       *
       * \throw CIDRSException if an error occur.
       *
       */
      CImage Clone () const;
      /**
       * \brief Gets the image width, in pixels
       *
       * \pre ! IsNull ()
       *
       * \return The width in pixels of the image.
       *
       */
      IDRS_UINT GetWidth () const;
      /**
       * \brief Gets the image width, in pixels
       *
       * \pre ! IsNull ()
       *
       * \return The height in pixels of the image.
       */
      IDRS_UINT GetHeight () const;
      /**
       * \brief Gets the image byte width
       *
       * \note iDRS black and white images are one bit per pixel, aligned on 32 bits.
       * \note iDRS greyscale images are 8 bits per pixel with no alignment. This means that byte width equals the pixel width.
       * \note iDRS color images are 24 bits per pixel with no alignment. This means that byte width is equal to 3 times the pixel width.
       *
       * \pre ! IsNull ()
       *
       * \return The width in bytes of the image.
       *
       */
      IDRS_UINT GetByteWidth () const;
      /**
       * \brief Gets the image size, in bytes
       *
       * \pre ! IsNull ()
       *
       * \return The size in bytes of the image.
       *
       */
      IDRS_UINT GetImageSize () const;
      /**
       * \brief Gets the image resolution
       *
       * \pre ! IsNull ()
       *
       * \return The resolution of the image.
       *
       */
      IDRS_UINT GetResolution () const;
      /**
       * \brief Gets the image bit per pixels info
       *
       * \pre ! IsNull ()
       *
       * \return The number of bits per pixels for the image.
       *
       */
      IDRS_UINT GetBitsPerPixel () const;
      /**
       * Sets the image resolution.
       *
       * \pre ! IsNull ()
       *
       * \param uiResolution The new resolution (dots per inch).
       *
       */
      void SetResolution ( const IDRS_UINT uiResolution );
      /**
       * \brief Gets the image pixels data
       *
       * \pre ! IsNull ()
       *
       * \return The pixels of the image
       */
      CImagePixels GetImagePixels () const;
      /**
       * \brief Returns the color mode of the image
       *
       * \return The color mode of the image.
       * If the image is not yet initialized, the returned color mode value is ColorMode::UNKNOWN
       */
      ColorMode GetColorMode () const;
      /**
       * \brief Returns the CIDRS handle used
       *
       * \return the CIDRS handle used during object initialization
       *
       * \throws CIDRSException if the object is not initialized
       */
      const CIDRS & GetIDRS () const;
      /**
       * \brief Provides the information, if the current resolution parameter is the default one.
       *
       * \returns IDRS_TRUE if the current resolution is set by default in the iDRS, IDRS_FALSE otherwise.
       */
      IDRS_BOOL IsDefaultResolution() const;
    private:
      // For internal use only
      CImageData & TypedObject () const
      {
        return ( CImageData & )Object ();
      };
  };
  /*
   *
   */
  inline CImage::CImage ()
  {
  }
  /*
   *
   */
  inline CImage::CImage ( const CImage & aImage )
    : CObjPtr (( CObjPtr & )aImage )
  {
  }
  /*
   *
   */
  inline CImage::CImage ( CImageData * pObj )
    : CObjPtr (( CObj * )pObj )
  {
  }
  /*
   *
   */
  inline CImage::~CImage ()
  {
  }
} // namespace
#endif /* _cimage_h_ */
