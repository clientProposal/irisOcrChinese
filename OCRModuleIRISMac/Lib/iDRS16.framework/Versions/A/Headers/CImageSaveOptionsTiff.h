/**
 * \file CImageSaveOptionsTiff.h
 * \brief Interface for the IDRS::CImageSaveOptionsTiff class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _CImageSaveOptionsTiff_h_
#define _CImageSaveOptionsTiff_h_
#include <CImageSaveOptions.h>
#include "EnumDefinitions.h"
namespace IDRS
{
  class CImageSaveOptionsData;
  /**
   * \brief The CImageSaveOptionsTiff class represents the various options to deal with TIFF images.
   * \ingroup module_image_formats
   *
   *
   */
  class IDRSKRN_API CImageSaveOptionsTiff : public CImageSaveOptions
  {
    public:
      /**
       * \brief Default constructor.
       */
      inline CImageSaveOptionsTiff ();
      /**
       * \brief Copy constructor.
       *
       * \param argImageSaveOptionsTIFF CImageSaveOptionsTiff object to copy
       */
      inline CImageSaveOptionsTiff ( const CImageSaveOptionsTiff & argImageSaveOptionsTIFF );
      /**
       * \brief Constructor.
       *
       * \param pImageSaveOptionsData The object to point to.
       */
      inline CImageSaveOptionsTiff (CImageSaveOptionsData* pImageSaveOptionsData );
      /**
       * \brief Create function creates an instance of CImageSaveOptionsTiff class and initializes it with the supplied tiff file format
       *
       */
      static CImageSaveOptionsTiff Create ( );
      /**
       * \brief Create function creates an instance of CImageSaveOptionsTiff class and initializes it with the supplied tiff file format
       *
       * \param bAppendIfExists Boolean flag specifying whether the image should be appended to an existing TIFF file.
       * If the file does not exists, then the image will be saved as the first image in the tiff file
       */
      static CImageSaveOptionsTiff Create ( const IDRS_BOOL bAppendIfExists );
      /**
       * \brief Destructor
       */
      inline virtual ~CImageSaveOptionsTiff ();
      /**
       * \brief Gets the TIFF bitonal compression.
       *
       * \return The TIFF compression for black and white images. Default is TiffCompression::Group4
       */
      TiffCompression GetBitonalCompression () const;
      /**
       * \brief Set the TIFF bitonal compression.
       *
       * \param evTiffCompression The TIFF compression for black and white images
       * \throw CIDRSException if TiffCompression::Jpeg is provided.
       */
      void SetBitonalCompression ( const TiffCompression evTiffCompression);
      /**
       * \brief Gets the TIFF color and greyscale compression.
       *
       * \return The TIFF compression for color and greyscale images. Default is TiffCompression::Packbits
       */
      TiffCompression GetColorCompression () const;
      /**
       * \brief Set the TIFF bitonal compression.
       *
       * \param evTiffCompression The TIFF compression for color and greyscale images
       * \throw CIDRSException if TiffCompression::Group4 or TiffCompression::FaxGroup4 is provided.
       */
      void SetColorCompression( const TiffCompression evTiffCompression );
      /**
       * \brief Set the number of rows per strip
       * TIFF image data can be organized into strips for faster random access and efficient I/O buffering. The default value in 1.
       * Choose RowsPerStrip such that each strip is about 8K bytes, even if the data is not compressed, since it makes buffering simpler for readers. 
       * The 8K value is fairly arbitrary, but seems to work well.
       * On a saved TIFF image, this value can be obtained by reading the TIFFTAG_ROWSPERSTRIP tag
       *
       * \param uiRowsPerStrip The value to be used as rows per strip. 
       */
      void SetRowsPerStrip ( const IDRS_UINT32 uiRowsPerStrip);
      /**
       * \brief Get the number of rows per strip set
       */
      IDRS_UINT32 GetRowsPerStrip () const;
      /**
       * \brief Returns the boolean flag that specify if the image will be appended to an existing file or not
       */
      IDRS_BOOL GetAppendIfExists() const;
      /**
       * \brief Set the boolean flag that specify if the image will be appended to an existing file or not
       *
       * \param bAppendIfExists New value
       */
      void SetAppendIfExists( const IDRS_BOOL bAppendIfExists );
      /**
       * \brief Get the boolean flag that specify if the image will include tiff header in compression
       */
      IDRS_BOOL GetWriteTiffHeader () const;
      /**
       * \brief Set the boolean flag that specify if the image will include tiff header in compression
       * \param bWriteTiffHeader Set to IDRS_TRUE if the header should be written.
       */
      void SetWriteTiffHeader ( const IDRS_BOOL bWriteTiffHeader );
    private:
      /**
       * \brief Return a CImageSaveOptionsTiffData reference.
       *
       * Internal use only
       */
      inline CImageSaveOptionsData& TypedObject () const
      {
        return (CImageSaveOptionsData& )Object ();
      };
  };
  /*
   *
   */
  inline CImageSaveOptionsTiff::CImageSaveOptionsTiff ()
  {
  }
  /*
   *
   */
  inline CImageSaveOptionsTiff::CImageSaveOptionsTiff ( const CImageSaveOptionsTiff & argImageSaveOptionsTIFF )
    : CImageSaveOptions (( const CImageSaveOptions & )argImageSaveOptionsTIFF )
  {
  }
  /*
   *
   */
  inline CImageSaveOptionsTiff::CImageSaveOptionsTiff (CImageSaveOptionsData* pImageSaveOptionsData)
    : CImageSaveOptions (pImageSaveOptionsData)
  {
  }
  /*
   *
   */
  inline CImageSaveOptionsTiff::~CImageSaveOptionsTiff ()
  {
  }
} // namespace
#endif /* _CImageSaveOptionsTiff_h_ */
