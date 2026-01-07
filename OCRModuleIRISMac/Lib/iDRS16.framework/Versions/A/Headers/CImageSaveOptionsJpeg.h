/**
 * \file CImageSaveOptionsJpeg.h
 * \brief Interface for the IDRS::CImageSaveOptionsJpeg class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _CImageSaveOptionsJpeg_h_
#define _CImageSaveOptionsJpeg_h_
#include <CObjPtr.h>
#include <CImageSaveOptions.h>
#include <EnumDefinitions.h>
namespace IDRS
{
  class CImageSaveOptionsData;
  /**
   * \brief The CImageSaveOptionsJpeg class represents the various options to deal with JPEG images.
   * \ingroup module_image_formats
   *
   * \see CImage::Load
   */
  class IDRSKRN_API CImageSaveOptionsJpeg : public CImageSaveOptions
  {
    public:
      /**
       * \brief Default constructor.
       */
      inline CImageSaveOptionsJpeg ();
      /**
       * \brief Copy constructor.
       *
       * \param argImageSaveOptionsJPEG The CImageSaveOptionsJpeg object to copy.
       */
      inline CImageSaveOptionsJpeg ( const CImageSaveOptionsJpeg & argImageSaveOptionsJPEG );
      /**
       * \brief Constructor.
       *
       * \param pImageSaveOptionsData The object to point to.
       */
      inline CImageSaveOptionsJpeg (CImageSaveOptionsData* pImageSaveOptionsData );
      /**
       * \brief Destructor
       */
      inline virtual ~CImageSaveOptionsJpeg ();
      /**
       * \brief Creates a new CImageSaveOptionsJpeg object and initializes it with the provided value
       *
       * \return A newly created CImageSaveOptionsJpeg object
       */
      static CImageSaveOptionsJpeg Create ();
      /**
       * \brief Gets the compression quality.
       *
       * \return The compression quality
       * \remark Default value CompressionQuality::HighQuality
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
       * \brief Return a CImageSaveOptionsData reference.
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
  inline CImageSaveOptionsJpeg::CImageSaveOptionsJpeg ()
  {
  }
  /*
   *
   */
  inline CImageSaveOptionsJpeg::CImageSaveOptionsJpeg ( const CImageSaveOptionsJpeg & argImageSaveOptionsJPEG )
    : CImageSaveOptions (( const CImageSaveOptions & )argImageSaveOptionsJPEG )
  {
  }
  /*
   *
   */
  inline CImageSaveOptionsJpeg::CImageSaveOptionsJpeg (CImageSaveOptionsData* pImageSaveOptionsData)
    : CImageSaveOptions (pImageSaveOptionsData)
  {
  }
  /*
   *
   */
  inline CImageSaveOptionsJpeg::~CImageSaveOptionsJpeg ()
  {
  }
} // namespace
#endif /* _CImageSaveOptionsJpeg_h_ */
