/**
 * \file CBarcodeSpecificOptions.h
 * class defining specific parameters for barcode engine.
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */

#ifndef _CBARCODESPECIFICOPTIONS_H
#define _CBARCODESPECIFICOPTIONS_H
 
#include <CObjPtr.h>
#include <TObjPtrArray.h>
#include "BarcodeType.h"


namespace IDRS
{
  class CBarcodeSpecificOptionsData;
  /**
   * \brief CBarcodeSpecificOptions contains some specific options for some specific barcode types
   */
  class IDRSKRN_API CBarcodeSpecificOptions : public CObjPtr
  {
    public:
      /**
       * \brief Default constructor.
       */
      inline CBarcodeSpecificOptions ( );
      /**
       * \brief copy constructor.
       */
      inline CBarcodeSpecificOptions ( const CBarcodeSpecificOptions & argBarcodeSpecificOptions );
      /**
       * \brief constructor from CObj object.
       */
      inline CBarcodeSpecificOptions( const CObj* pObj );
      /**
       * \brief Default destructor.
       */
      inline ~CBarcodeSpecificOptions ( );
      /**
       * \brief gets the barcode type
       *
       * \returns barcode type.
       */
      BarcodeType GetBarcodeType() const;
    private:
      /**
       * \brief returns a CBarcodeSpecificOptionsData reference
       *
       * Internal use only
       */
      CBarcodeSpecificOptionsData & TypedObject () const
      {
        return (CBarcodeSpecificOptionsData & ) Object ();
      }
  };

  typedef TObjPtrArray<CBarcodeSpecificOptions> CBarcodeSpecificOptionsArray;
  
  /*
   *
   */
  CBarcodeSpecificOptions::CBarcodeSpecificOptions ( )
  {
  }
  /*
   *
   */
  CBarcodeSpecificOptions::CBarcodeSpecificOptions ( const CBarcodeSpecificOptions & argBarcodeSpecificOptions )
    : CObjPtr ((const CObjPtr &) argBarcodeSpecificOptions)
  {
  }
  /*
   *
   */
  CBarcodeSpecificOptions::CBarcodeSpecificOptions(const CObj* pObj)
    : CObjPtr(const_cast<CObj*>(pObj))
  {
  }
  /*
   *
   */
  CBarcodeSpecificOptions::~CBarcodeSpecificOptions ( )
  {
  }
}

#endif // _CBARCODESPECIFICOPTIONS_H
