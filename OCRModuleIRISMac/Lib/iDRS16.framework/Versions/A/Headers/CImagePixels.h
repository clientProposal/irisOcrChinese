/**
 * \file CImagePixels.h
 * \brief Interface for the IDRS::CImagePixels class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _CImagePixels_h_
#define _CImagePixels_h_
#include <EnumDefinitions.h>
#include <CObjPtr.h>
namespace IDRS
{
  class CImagePixelsData;
  class CMemoryBuffer;
  /**
   * \brief The CImagePixels class handles the pixels of an image.
   * \ingroup module_core module_image_formats
   *
   * The class offers pixel level access for an image
   */
  class IDRSKRN_API CImagePixels : public CObjPtr
  {
    public:
      friend class CImage;
      /**
       * \brief Default constructor.
       */
      inline CImagePixels ();
      /**
       * \brief Copy constructor.
       *
       * \param argImagePixels The smart pointer to copy.
       */
      inline CImagePixels ( const CImagePixels & argImagePixels );
      /**
       * \brief Constructor.
       *
       * \param pImagePixelsData The object to point to.
       */
      inline CImagePixels ( CImagePixelsData * pImagePixelsData );
      /**
       * \brief Destructor
       */
      inline virtual ~CImagePixels ();
      /**
       * \brief Sets the color of the pixel at the given coordinates.
       *
       * \pre ! IsNull ()
       *
       * \param uiCol The 0 based index of the column.
       * \param uiRow The 0 based index of the row.
       * \param color The color.
       *
       * \note For a black and white image, the valid colors have blue == green == red ==0xFF or blue == green == red ==0x00
       * \note For a greyscale image, the valid colors have blue == green == red.
       *
       */
      void SetPixelColor ( const IDRS_UINT32 uiCol, const IDRS_UINT32 uiRow, const IDRS_COLOR & color );
      /**
       * \brief Gets the color of the pixel at the given coordinates.
       *
       * \pre ! IsNull ()
       * \pre uiCol < GetWidth ()
       * \pre uiRow < GetHeight ()
       *
       * \param uiCol The 0 based index of the column.
       * \param uiRow The 0 based index of the row.
       *
       * \return The color of the pixel.
       */
      IDRS_COLOR GetPixelColor ( const IDRS_UINT32 uiCol, const IDRS_UINT32 uiRow ) const;
      /**
       * \brief FillBitmap fills the image with the given color.
       *
       * \pre ! IsNull ()
       *
       * \param color The color.
       *
       * \note For a black and white image, the valid colors have blue == green == red ==0xFF or blue == green == red ==0x00
       * \note For a greyscale image, the valid colors have blue == green == red.
       *
       */
      void FillBitmap ( const IDRS_COLOR & color );
      /**
       * \pre ! IsNull ()
       *
       * \return The buffer of pixels
       */
      IDRS_PVOID GetPixels () const;
      /**
       * \brief Sets the image pixels from an external buffer.
       *
       * \param xbPixelsBuffer Buffer containing the pixels
       * \param uiBufferSize Size of the buffer, in bytes
       *
       * \attention The buffer size provided needs to be exactly the same than the size required for this image.
       */
      void SetPixelsBuffer ( const IDRS_PBYTE xbPixelsBuffer, const IDRS_UINT32 uiBufferSize );
      /**
       * \brief Gets the size of the buffer allocated to store the image pixels.
       *
       * This size is expressed in bytes.
       *
       * \return The size of the buffer allocated to store the image pixels.
       *
       * \remarks The value returned by this method is identical to the value of GetSize ().uiImageSize
       */
      IDRS_UINT32 GetPixelsBufferSize () const;
      /**
       * \brief Gets the image pixels to a preallocated buffer.
       *
       * The buffer size provided needs to be at least the image size.
       *
       * \param xbPixelsBuffer Buffer where the pixels will be copied
       * \param uiBufferSize The size of the buffer provided, in bytes.
       */
      void GetPixelsBuffer ( IDRS_PBYTE xbPixelsBuffer, const IDRS_UINT32 uiBufferSize ) const;
      /**
       * \brief Gets the image width, in pixels
       *
       * \pre ! IsNull ()
       *
       * \return The width in pixels of the image
       */
      IDRS_UINT32 GetWidth () const;
      /**
       * \brief Gets the image width, in pixels
       *
       * \pre ! IsNull ()
       *
       * \return The height in pixels of the image
       */
      IDRS_UINT32 GetHeight() const;
      /**
       * \brief Gets the image byte width
       *
       * \note iDRS black and white images are one bit per pixel, aligned on 32 bits.
       * \note iDRS greyscale images are 8 bits per pixel with no alignment. This means that byte width equals the pixel width.
       * \note iDRS color images are 24 bits per pixel with no alignment. This means that byte width is equal to 3 times the pixel width.
       *
       * \pre ! IsNull ()
       *
       * \return The width in bytes of the image
       */
      IDRS_UINT32 GetByteWidth() const;
      /**
       * \pre ! IsNull ()
       *
       * \return The color mode of the image
       */
      ColorMode GetColorMode () const;
      /**
       * \brief Gets the image size image with the provided properties.
       *
       * \param uiWidth The width in pixels of the image.
       * \param uiHeight The height in pixels of the image.
       * \param cmColorMode The color mode for the image.
       *
       * \return The size of the image (bytes)
       */
      inline static IDRS_UINT32 GetImageSize ( const IDRS_UINT32 uiWidth, const IDRS_UINT32 uiHeight, const ColorMode cmColorMode );
      /**
       * \brief Gets the width in bytes of an image with the provided properties.
       *
       * \param uiWidth The width in pixels of the image.
       * \param cmColorMode The color mode for the image.
       *
       * \return The width of the image (bytes)
       */
      inline static IDRS_UINT32 GetByteWidth ( const IDRS_UINT32 uiWidth, const ColorMode cmColorMode );
    private:
      /**	
       * \brief Creates a new CImagePixels object.	
       *	
       * \param uiWidth The width of the image.	
       * \param uiHeight The height of the image.	
       * \param uiByteWidth The width of the image in bytes.	
       * \param uiImageSizeInBytes The size of the image in bytes.	
       * \param cmColorMode The color mode for the image.	
       * \param argPixelsBuffer The buffer of pixels	
       *	
       * \return The newly created CImagePixels object.	
       *	
       * \throw CIDRSException if an error occur.	
       */	
      static CImagePixels Create(IDRS_UINT32 uiWidth, IDRS_UINT32 uiHeight, IDRS_UINT32 uiByteWidth, IDRS_UINT32 uiImageSizeInBytes, const ColorMode cmColorMode, const CMemoryBuffer& argPixelsBuffer);	
      // For internal use only
      CImagePixelsData & TypedObject () const
      {
        return ( CImagePixelsData & )Object ();
      };
  };
  /*
   *
   */
  inline CImagePixels::CImagePixels ()
  {
  }
  /*
   *
   */
  inline CImagePixels::CImagePixels ( const CImagePixels & theImagePixels )
    : CObjPtr (( CObjPtr & )theImagePixels )
  {
  }
  /*
   *
   */
  inline CImagePixels::CImagePixels ( CImagePixelsData * pImagePixelsData )
    : CObjPtr (( CObj * )pImagePixelsData )
  {
  }
  /*
   *
   */
  inline CImagePixels::~CImagePixels ()
  {
  }
  /*
   *
   */
  inline IDRS_UINT32 CImagePixels::GetImageSize ( const IDRS_UINT32 uiWidth, const IDRS_UINT32 uiHeight, const ColorMode cmColorMode )
  {
    return uiHeight * GetByteWidth ( uiWidth, cmColorMode );
  }
  /*
   *
   */
  inline IDRS_UINT32 CImagePixels::GetByteWidth ( const IDRS_UINT32 uiWidth, const ColorMode cmColorMode )
  {
    switch ( cmColorMode )
    {
    /**/
    case ColorMode::BlackAndWhite:
      // each pixel data is coded on 1 bit, 
      // each B&W data is manipulated as int (4 bytes)
      // ( + 31)/32 is added to avoid losing data as division returns 
      // integer part of the floating result.
      return ((( uiWidth + 31 ) / 32 ) * 4 );
    /**/
    case ColorMode::Greyscale:
      // each pixel data is coded on 1 char, ie 1 byte.
      return uiWidth;
    /**/
    case ColorMode::Color:
      // each RGB pixel data is coded on 3 chars
      return 3 * uiWidth;
    default:
      ThrowException ( IDRS_ERROR_INVALID_ARGS );
    }
  }
} // namespace
#endif /* _CImagePixels_h_ */
