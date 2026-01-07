/**
 * \file CNegative.h
 * \brief Interface for the IDRS::CNegative class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _CNegative_h_
#define _CNegative_h_
#include <CIDRS.h>
#include <CImageOperation.h>
#include <CPolygon.h>
namespace IDRS
{
  class CNegativeData;
  /**
   * \brief The CNegative class offers negative image transformation.
   * \ingroup module_prepro
   *
   * The class contains a image transformation algorithm that performs negative image transformation on an image or a part of an image
   *
   * \req IDRS::Module::Prepro
   *
   * \see Module::Prepro for information about the preprocessing library
   */
  class IDRSKRN_API CNegative : public CImageOperation
  {
    public:
      /**
       * \brief Default constructor.
       */
      inline CNegative ();
      /**
       * \brief Copy constructor.
       *
       * \param argNegative The smart pointer to copy.
       */
      inline CNegative ( const CNegative & argNegative );
      /**
       * \brief Constructor.
       *
       * \param pNegativeData The object to point to.
       */
      inline CNegative ( CNegativeData * pNegativeData );
      /**
       * \brief Destructor
       */
      inline virtual ~CNegative ();
      /**
       * \brief Creates a new CNegative object.
       *
       * \param argIDRS The iDRS
       *
       * \return The newly created CNegative object.
       *
       * \throw CIDRSException if an error occur.
       */
      static CNegative Create ( const CIDRS & argIDRS );
      /**
       * \brief Inverts the given image.
       *
       * \pre ! argImage.IsNull ()
       *
       * \param argImage The image to process.
       *
       * \throw CIDRSException if an error occur.
       */
      void Negative ( CImage & argImage );
      /**
       * \brief Inverts the given area in the image.
       *
       * \pre ! argPolygon.IsNull ()
       * \pre ! argImage.IsNull ()
       * \pre argImage != argImage
       *
       * \param argImage The image to process.
       * \param argPolygon The area to process.
       *
       * \throw CIDRSException if an error occur.
       */
      void Negative ( CImage & argImage, const CPolygon & argPolygon );
      /**
       * \brief Inverts the given image.
       *
       * \pre ! argImage.IsNull ()
       *
       * \param argIDRS The iDRS
       * \param argImage The image to process.
       *
       * \throw CIDRSException if an error occur.
       */
      static void Negative ( CIDRS & argIDRS, CImage & argImage );
      /**
       * \brief Inverts the given area in the image.
       *
       * \pre ! argPolygon.IsNull ()
       * \pre ! argImage.IsNull ()
       * \pre argImage != argImage
       *
       * \param argIDRS The iDRS
       * \param argImage The image to process.
       * \param argPolygon The area to process.
       *
       * \throw CIDRSException if an error occur.
       */
      static void Negative ( CIDRS & argIDRS, CImage & argImage, const CPolygon & argPolygon );
    private:
      /**
       * \brief Inverts the given area in the pixels.
       *
       * \pre ! argPolygon.IsNull ()
       * \pre ! argImagePixels.IsNull ()
       *
       * \param argImagePixels The pixels to process.
       * \param argPolygon The area to process.
       *
       * \throw CIDRSException if an error occur.
       */
      void Negative ( CImagePixels & argImagePixels, const CPolygon & argPolygon );
      /**
       * \brief Inverts the given area in the pixels.
       *
       * \pre ! argImagePixels.IsNull ()
       *
       * \param argImagePixels The pixels to process.
       *
       * \throw CIDRSException if an error occur.
       */
      void Negative ( CImagePixels & argImagePixels );
      // For internal use only
      CNegativeData & TypedObject () const
      {
        return ( CNegativeData & )Object ();
      };
  };
  /*
   *
   */
  inline CNegative::CNegative ()
  {
  }
  /*
   *
   */
  inline CNegative::CNegative ( const CNegative & argNegative )
    : CImageOperation (( CImageOperation & )argNegative )
  {
  }
  /*
   *
   */
  inline CNegative::CNegative ( CNegativeData * pNegativeData )
    : CImageOperation (( CImageOperationData * )pNegativeData )
  {
  }
  /*
   *
   */
  inline CNegative::~CNegative ()
  {
  }
} // namespace
#endif /* _CNegative_h_ */
