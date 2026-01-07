/**
 * \file CPunchHoleRemoval.h
 * \brief Interface for the IDRS::CPunchHoleRemoval class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _cpunchholeremoval_h_
#define _cpunchholeremoval_h_
#include <CObjPtr.h>
#include <CImage.h>
namespace IDRS
{
  class CImage;
  class CPunchHoleRemovalData;
  class CImgPart;
  /**
   * \brief The CPunchHoleRemoval class is part of iDRS advanced preprocessing module. It provides punch hole removal capabilities.
   * \ingroup module_prepro
   *
   * \req IDRS::Module::Prepro
   *
   */
  class IDRSKRN_API CPunchHoleRemoval : public CObjPtr
  {
    public:
      //
      inline CPunchHoleRemoval ();
      //
      inline CPunchHoleRemoval ( const CPunchHoleRemoval & aPunchHoleRemoval );
      //
      inline CPunchHoleRemoval ( CPunchHoleRemovalData * pObj );
      //
      inline virtual ~CPunchHoleRemoval ();
      /**
       * \brief The Create method creates a CPunchHoleRemoval object.
       *
       * \param argIDRS The iDRS instance.
       *
       * \return The newly created CPunchHoleRemoval object.
       *
       * \throw CIDRSException if an error occur.
       */
      static CPunchHoleRemoval Create ( const CIDRS & argIDRS );
      /**
       * \brief RemovePunchHole automatically detects the location of the punch holes on the image and removes them.
       *
       * \pre ! IsNull ()
       * \pre ! argImage.IsNull ()
       *
       * \param argImage The image to process.
       *
       * The punch hole algorithm can be used on images with the following minimum dimensions (computed for 300dpi): width: 300px, height: 100
       * Please note that the minimum height and width can vary with the image resolution.
       */
      void RemovePunchHole ( CImage & argImage );
    private:
      //
      CPunchHoleRemovalData & TypedObject () const
      {
        return ( CPunchHoleRemovalData & )Object ();
      };
  };
  inline CPunchHoleRemoval::CPunchHoleRemoval ()
  {
  }
  inline CPunchHoleRemoval::CPunchHoleRemoval ( const CPunchHoleRemoval & aPunchHoleRemoval )
    : CObjPtr (( CObjPtr & )aPunchHoleRemoval )
  {
  }
  inline CPunchHoleRemoval::CPunchHoleRemoval ( CPunchHoleRemovalData * pObj )
    : CObjPtr (( CObj * )pObj )
  {
  }
  inline CPunchHoleRemoval::~CPunchHoleRemoval ()
  {
  }
} //namespace
#endif /* _cpunchholeremoval_h_ */
