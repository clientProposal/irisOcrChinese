/**
 * \file CPdfCustomMetadata.h
 * \brief Interface for IDRS::CPdfCustomMetadata class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _CPdfCustomMetadata_h_
#define _CPdfCustomMetadata_h_

#include <CObjPtr.h>
#include "CPdfCustomMetadataContainer.h"

namespace IDRS
{
  class CPdfCustomMetadataData;
  /**
    * \brief CPdfCustomMetadata is the root container gathering all PDF metadata resources
    */
  class IDRSKRN_API CPdfCustomMetadata : public CPdfCustomMetadataContainer
  {
  public:
    /**
      * \brief Default constructor.
      */
    inline CPdfCustomMetadata();
    /**
      * \brief Copy constructor.
      *
      * \param argPdfCustomMetadata The smart pointer to copy.
      */
    inline CPdfCustomMetadata( const CPdfCustomMetadata & argPdfCustomMetadata );
    /**
      * \brief Constructor.
      *
      * \param pPdfCustomMetadataData The object to point to.
      */
    inline CPdfCustomMetadata( CPdfCustomMetadataData * pPdfCustomMetadataData );
    /**
      * \brief Destructor
      */      
    inline virtual ~CPdfCustomMetadata();
    /**
      * \brief Create Creates a CPdfCustomMetadata object.
      *
      * \throw CIDRSException if an error occurs.
      */
    static CPdfCustomMetadata Create();
  private:
    // For internal use only
    CPdfCustomMetadataData & TypedObject() const
    {
      return (CPdfCustomMetadataData &)Object();
    };
  };
  /*
   *
   */
  inline CPdfCustomMetadata::CPdfCustomMetadata()
  {
  }
  /*
   *
   */
  inline CPdfCustomMetadata::CPdfCustomMetadata(const CPdfCustomMetadata & argPdfCustomMetadata)
    : CPdfCustomMetadataContainer((CPdfCustomMetadataContainer & ) argPdfCustomMetadata)
  {
  }
  /*
   *
   */
  inline CPdfCustomMetadata::CPdfCustomMetadata(CPdfCustomMetadataData * pPdfCustomMetadataData)
    : CPdfCustomMetadataContainer((CPdfCustomMetadataContainerData * ) pPdfCustomMetadataData )
  {
  }
  /*
   *
   */
  inline CPdfCustomMetadata::~CPdfCustomMetadata()
  {
  }
}
#endif // _CPdfCustomMetadata_h_
