/**
 * \file CImageLoadOptions.h
 * \brief Interface class CImageLoadOptions
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _CImageLoadOptions_h_
#define _CImageLoadOptions_h_
#include <CObjPtr.h>
#include <EnumDefinitions.h>
namespace IDRS
{
  class CImageLoadOptionsData;
  /**
   * \brief The CImageLoadOptions is the base class to hold the options for loading an image file.
   * \note At the moment, only TIFF and PDF image formats have access to specific load options.
   *
   * \ingroup module_image_formats
   *
   */
  class IDRSKRN_API CImageLoadOptions : public CObjPtr
  {
    public:
      /**
       * \brief Default constructor
       */
      CImageLoadOptions();
      /**
       * \brief Copy Constructor
       */
      CImageLoadOptions ( const CImageLoadOptions & argImageSaveOptions );
      /**
       * \brief Constructor from Data object
       */
      CImageLoadOptions ( const CImageLoadOptionsData * pImageLoadOptionsData );
      /**
       * \brief Destructor
       */
      ~CImageLoadOptions();
      /**
       * \brief Creates a new instance of CImageLoadOptions and initializes it with the supplied image format
       *
       * \param evImageFormat The image format
       *
       * \return The newly created CImageLoadOptions object
       */
      static CImageLoadOptions Create(const ImageFormat evImageFormat);
      /**
       * \brief Get the format where the loading options will apply
       * \return The format
       */
      ImageFormat GetImageFormat() const;
    private:
      /**
       * \brief Return a CImageSaveOptionsData reference.
       *
       * Internal use only
       */
      inline CImageLoadOptionsData & TypedObject () const
      {
        return ( CImageLoadOptionsData & )Object ();
      };
  };
}
#endif //_CImageLoadOptions_h_
