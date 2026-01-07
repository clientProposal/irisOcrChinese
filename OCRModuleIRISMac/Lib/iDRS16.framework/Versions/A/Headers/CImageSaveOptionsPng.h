/**
 * \file CImageSaveOptionsPng.h
 * \brief Interface for the IDRS::CImageSaveOptionsPng class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _CImageSaveOptionsPng_h_
#define _CImageSaveOptionsPng_h_
#include <CImageSaveOptions.h>
#include "EnumDefinitions.h"

namespace IDRS
{
  class CImageSaveOptionsData;
  /**
   * \brief The CImageSaveOptionsPng class represents the various options to deal with PNG images.
   * \ingroup module_image_formats
   *
   */
  class IDRSKRN_API CImageSaveOptionsPng : public CImageSaveOptions
  {
    public:
      /**
       * \brief Default constructor.
       */
      inline CImageSaveOptionsPng ();
      /**
       * \brief Copy constructor.
       *
       * \param argImageSaveOptionsPng The CImageSaveOptionsPng object to copy.
       */
      inline CImageSaveOptionsPng ( const CImageSaveOptionsPng & argImageSaveOptionsPng );
      /**
       * \brief Constructor.
       *
       * \param pImageSaveOptionsData The object to point to.
       */
      inline CImageSaveOptionsPng ( const CImageSaveOptionsData* pImageSaveOptionsData );
      /**
       * \brief Destructor
       */
      inline virtual ~CImageSaveOptionsPng();
      /**
       * \brief Creates a new CImageSaveOptionsPng object and initializes it with the provided value
       */
      static CImageSaveOptionsPng Create ( );
      /**
       * \brief Gets the PNG image file format.
       *
       * \return The PNG image file format
       */
      PngTransparencyMode GetTransparencyMode() const;
      /**
       * \brief Sets the PNG image file format.
       *
       * \param evPngTransparencyMode The PNG image file format to set
       */
      void SetTransparencyMode( const PngTransparencyMode evPngTransparencyMode );
      /**
       * \brief Gets the PNG image compression level.
       *
       * \return The PNG compression level
       */
      CompressionLevel GetCompressionLevel () const;
      /**
       * \brief Sets the PNG image compression level.
       *
       * \param evCompressionLevel The PNG compression level to set
       */
      void SetCompressionLevel (const CompressionLevel evCompressionLevel);
    private:
      /**
       * \brief Return a CImageSaveOptionsPngData reference.
       *
       * Internal use only
       */
      inline CImageSaveOptionsData& TypedObject () const
      {
        return (CImageSaveOptionsData& )Object ();
      };
  };
  /*
   * \brief Default constructor.
   */
  inline CImageSaveOptionsPng::CImageSaveOptionsPng ()
  {
  }
  /*
   *
   */
  inline CImageSaveOptionsPng::CImageSaveOptionsPng ( const CImageSaveOptionsPng & argImageSaveOptionsPng )
    : CImageSaveOptions (( const CImageSaveOptions & )argImageSaveOptionsPng )
  {
  }
  /*
   *
   */
  inline CImageSaveOptionsPng::CImageSaveOptionsPng ( const CImageSaveOptionsData* pImageSaveOptionsData)
    : CImageSaveOptions (pImageSaveOptionsData)
  {
  }
  /*
   * \brief Destructor
   */
  inline CImageSaveOptionsPng::~CImageSaveOptionsPng ()
  {
  }
} // namespace
#endif /* _CImageSaveOptionsPng_h_ */
