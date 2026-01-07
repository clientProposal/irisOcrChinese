/**
 * \file CImageSaveOptions.h
 * \brief Interface for the IDRS::CImageSaveOptions class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _CImageSaveOptions_h_
#define _CImageSaveOptions_h_
#include "EnumDefinitions.h"
#include <CObjPtr.h>
namespace IDRS
{
  class CImageSaveOptionsData;
  /**
   * \brief The CImageSaveOptions is the base class to hold the options for an image file.
   * \ingroup module_image_formats
   *
   *
   */
  class IDRSKRN_API CImageSaveOptions : public CObjPtr
  {
    public:
      /**
       * \brief Default constructor.
       */
      inline CImageSaveOptions ();
      /**
       * \brief Copy constructor.
       *
       * \param argImageSaveOptions Object (Ptr) to copy
       */
      inline CImageSaveOptions ( const CImageSaveOptions & argImageSaveOptions );
      /**
       * \brief Constructor from Data object.
       *
       * \param pImageSaveOptionsData Data object to refer to
       */
      inline CImageSaveOptions ( const CImageSaveOptionsData * pImageSaveOptionsData );
      /**
       * \brief Destructor.
       */
      inline virtual ~CImageSaveOptions ();
      /**
       * \brief Creates a new instance of CImageSaveOptions and initializes it with the supplied image format
       *
       * \param evImageFormat The image format
       *
       * \return The newly created CImageSaveOptions object
       */
      static CImageSaveOptions Create ( const ImageFormat evImageFormat );
      /**
       * \brief Get the image format
       *
       * \return The image format.
       */
      ImageFormat GetImageFormat () const;
    private:
      /**
       * \brief Return a CImageSaveOptionsData reference.
       *
       * Internal use only
       */
      inline CImageSaveOptionsData & TypedObject () const
      {
        return ( CImageSaveOptionsData & )Object ();
      };
  };
  /*
   *
   */
  inline CImageSaveOptions::CImageSaveOptions ()
  {
  }
  /*
   *
   */
  inline CImageSaveOptions::~CImageSaveOptions ()
  {
  }
  inline CImageSaveOptions::CImageSaveOptions ( const CImageSaveOptions & argImageSaveOptions )
    :  CObjPtr (( const CObjPtr & )argImageSaveOptions )
  {
  }
  inline CImageSaveOptions::CImageSaveOptions( const CImageSaveOptionsData * pImageSaveOptionsData )
    : CObjPtr (( CObj * )pImageSaveOptionsData )
  {
  }
} // namespace
#endif /* _CImageSaveOptions_h_ */
