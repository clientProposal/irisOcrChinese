/**
 * \file CImageSaveOptionsJpeg2000.h
 * \brief Interface for the IDRS::CImageSaveOptionsJpeg2000 class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _CImageSaveOptionsJpeg2000_h_
#define _CImageSaveOptionsJpeg2000_h_
#include <CObjPtr.h>
#include <CImageSaveOptions.h>
namespace IDRS
{
  class CImageSaveOptionsData;
  /**
   * \brief The CImageSaveOptionsJpeg2000 class represents the various options to deal with JPEG 2000 image compression algorithm
   * \ingroup module_image_formats
   *
   *
   */
  class IDRSKRN_API CImageSaveOptionsJpeg2000 : public CImageSaveOptions
  {
    public:
      /**
       * \brief Default constructor.
       */
      inline CImageSaveOptionsJpeg2000 ();
      /**
       * \brief Copy constructor.
       *
       * \param argImageSaveOptionsJpeg2000 The CImageSaveOptionsJpeg2000 object to copy.
       */
      inline CImageSaveOptionsJpeg2000 ( const CImageSaveOptionsJpeg2000 & argImageSaveOptionsJpeg2000 );
      /**
       * \brief Constructor.
       *
       * \param pImageSaveOptionsData The object to point to.
       */
      inline CImageSaveOptionsJpeg2000 (CImageSaveOptionsData* pImageSaveOptionsData);
      /**
       * \brief Destructor
       */
      inline virtual ~CImageSaveOptionsJpeg2000 ();
      /**
       * \brief Creates a new CImageSaveOptionsJpeg2000 object and initializes it with the provided value
       *
       * \return A newly created object
       */
      static CImageSaveOptionsJpeg2000 Create ();
      /**
       * \brief Gets the compression quality.
       *
       * \return The compression quality
       * \remark The default value is CompressionQuality::HighQuality
       */
      CompressionQuality GetCompressionQuality() const;
      /**
       * \brief Sets the compression quality.
       *
       * \param evCompressionQuality The compression quality
       */
      void SetCompressionQuality(const CompressionQuality evCompressionQuality);
  private:
      /**
       * \brief Return a CImageSaveOptionsJpeg2000Data reference.
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
  inline CImageSaveOptionsJpeg2000::CImageSaveOptionsJpeg2000 ()
  {
  }
  /*
   *
   */
  inline CImageSaveOptionsJpeg2000::CImageSaveOptionsJpeg2000 ( const CImageSaveOptionsJpeg2000 & argImageSaveOptionsJpeg2000 )
    : CImageSaveOptions (( const CImageSaveOptions & )argImageSaveOptionsJpeg2000 )
  {
  }
  /*
   *
   */
  inline CImageSaveOptionsJpeg2000::CImageSaveOptionsJpeg2000 (CImageSaveOptionsData* pImageSaveOptionsData)
    : CImageSaveOptions (pImageSaveOptionsData)
  {
  }
  /*
   *
   */
  inline CImageSaveOptionsJpeg2000::~CImageSaveOptionsJpeg2000 ()
  {
  }
} // namespace
#endif /* _CImageSaveOptionsJpeg2000_h_ */
