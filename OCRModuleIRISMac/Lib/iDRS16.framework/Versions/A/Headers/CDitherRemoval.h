/**
 * \file CDitherRemoval.h
 * Interface for CDitherRemoval class.
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */

#ifndef _CDitherRemoval_h_
#define _CDitherRemoval_h_

#include <CImageOperation.h>

namespace IDRS
{
  class CDitherRemovalData;

  /**
   * \brief CDitherRemoval attempts to perform the reversal of image dithering, which is a common technique for printing with inkjet printers.
   *
   * Dithering is analogous to the halftone technique used in printing. Due to the fact that during the dithering process a part of the image information is lost,
   * the resulting image after the dithering removal will not be the same as the original.
   * However, the resulting image would improve the recognition rate of iDRS recognition engines (both OCR and barcode).
   *
   * \note The algorithm works only for black & white images
   * 
   * \ingroup module_prepro
   * \req IDRS::Module::Prepro
   *
   * \see Module::Prepro
   */
  class IDRSKRN_API CDitherRemoval : public CImageOperation
  {
    public:
      /**
       * \brief Default constructor.
       */
      inline CDitherRemoval ();
      /**
       * \brief Copy constructor.
       *
       * \param argDitherRemoval The smart pointer to copy.
       */
      inline CDitherRemoval ( const CDitherRemoval & argDitherRemoval );
      /**
       * \brief Constructor.
       *
       * \param pDitherRemovalData The object to point to.
       */
      inline CDitherRemoval ( CDitherRemovalData * pDitherRemovalData );
      /**
       * \brief Destructor
       */
      inline virtual ~CDitherRemoval ();
      /**
       * \brief Creates a new CDitherRemoval object.
       *
       * \param argIDRS The iDRS
       *
       * \return The newly created CDitherRemoval object.
       *
       * \throw CIDRSException if an error occur.
       */
      static CDitherRemoval Create ( const CIDRS & argIDRS );
      /**
       * \brief RemoveDither applies the dither removal algorithm to the supplied image. 
       * The result will be stored in the same image.
       *
       * \param argImage Image where the dither removal algorithm will be executed
       *
       * \throws The function throws CIDRSException if the supplied image is not black & white
       */
      void RemoveDither(CImage& argImage) const;
    private:
      //! Internal use only
      CDitherRemovalData & TypedObject () const
      {
        return ( CDitherRemovalData & )Object ();
      };
  };

  /*
   *
   */
  inline CDitherRemoval::CDitherRemoval ()
  {
  }
  /*
   *
   */
  inline CDitherRemoval::CDitherRemoval ( const CDitherRemoval & argDitherRemoval )
    : CImageOperation (( CImageOperation & )argDitherRemoval )
  {
  }
  /*
   *
   */
  inline CDitherRemoval::CDitherRemoval ( CDitherRemovalData * pDitherRemovalData )
    : CImageOperation (( CImageOperationData * )pDitherRemovalData )
  {
  }
  /*
   *
   */
  inline CDitherRemoval::~CDitherRemoval ()
  {
  }
}
#endif // _CDitherRemoval_h_
