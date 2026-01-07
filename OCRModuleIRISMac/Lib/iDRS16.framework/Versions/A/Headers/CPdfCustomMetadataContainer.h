/**
 * \file CPdfCustomMetadataContainer.h
 * \brief Interface for IDRS::CPdfCustomMetadataContainer class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _CPdfCustomMetadataContainer_h_
#define _CPdfCustomMetadataContainer_h_

#include <CObjPtr.h>
#include "CPdfCustomMetadataResource.h"

namespace IDRS
{
  class CPdfCustomMetadataContainerData;
  class idrs_string;
  /**
    * \brief CPdfCustomMetadataContainer represents a PDF metadata bag
    *
    * A container can contain 
    */
  class IDRSKRN_API CPdfCustomMetadataContainer : public CPdfCustomMetadataResource
  {
    public:
      /**
        * \brief Default constructor.
        */
      inline CPdfCustomMetadataContainer();
      /**
        * \brief Copy constructor.
        *
        * \param argPdfCustomMetadataContainer The smart pointer to copy.
        */
      inline CPdfCustomMetadataContainer(const CPdfCustomMetadataContainer & argPdfCustomMetadataContainer);
      /**
        * \brief Constructor.
        *
        * \param pPdfCustomMetadataContainerData The object to point to.
        */
      inline CPdfCustomMetadataContainer(CPdfCustomMetadataContainerData * pPdfCustomMetadataContainerData);
      /**
        * \brief Destructor
        */
      inline virtual ~CPdfCustomMetadataContainer();
      /**
        * \brief Create Creates a CPdfCustomMetadata object.
        *
        * \param strContainerName The container name
        *
        * \throw CIDRSException if an error occurs.
        */
      static CPdfCustomMetadataContainer Create(const idrs_string& strContainerName);
      /**
        * \brief Adds a new CPdfCustomMetadataResource to the PDF custom metadata list
        *
        * \param pPdfCustomMetadataResource Object containing a custom metadata resource.
        */
      void Add(const CPdfCustomMetadataResource & pPdfCustomMetadataResource);
      /**
        * \brief Adds a list of CPdfCustomMetadataResource to the PDF custom metadata list
        *
        * \param xPdfCustomMetadataResource Vector containing the custom metadata resources to add.
        * \param uiResourceCount Number of custom metadata resource objects to add.
        */
      void Add(const CPdfCustomMetadataResource xPdfCustomMetadataResource[], const IDRS_UINT uiResourceCount);
      /**
        * \brief GetCount returns the number of PDF custom metadata resource
        *
        * \return The number of custom metadata resources
        */
      IDRS_UINT GetCount() const;
      /**
        * \brief GetAt returns the CPdfCustomMetadataResource at a certain index
        *
        * \param uiIndex Index where to read the CPdfCustomMetadataResource
        *
        * \return The CPdfCustomMetadataResource at the supplied index
        */
      CPdfCustomMetadataResource GetAt(const IDRS_UINT uiIndex) const;
      /**
        * \brief RemoveAt removes a CPdfCustomMetadataResource from the list
        *
        * \param uiIndex The index where to remove the object
        */
      void RemoveAt(const IDRS_UINT uiIndex);
      /**
        * \brief RemoveAll removes all CPdfCustomMetadataResource from the list
        */
      void RemoveAll();
      /**
        * \brief Retrieves the container name
        *
        * \return The container name
        */
      const idrs_string& GetContainerName() const;

    private:
      // For internal use only
      CPdfCustomMetadataContainerData & TypedObject() const
      {
        return (CPdfCustomMetadataContainerData &) Object();
      };
  };
  /*
   *
   */
  inline CPdfCustomMetadataContainer::CPdfCustomMetadataContainer()
  {
  }
  /*
   *
   */
  inline CPdfCustomMetadataContainer::CPdfCustomMetadataContainer(const CPdfCustomMetadataContainer & argPdfCustomMetadata)
    : CPdfCustomMetadataResource((CPdfCustomMetadataResource &)argPdfCustomMetadata)
  {
  }
  /*
   *
   */
  inline CPdfCustomMetadataContainer::CPdfCustomMetadataContainer(CPdfCustomMetadataContainerData * pPdfCustomMetadataContainerData)
    : CPdfCustomMetadataResource((CPdfCustomMetadataResourceData *)pPdfCustomMetadataContainerData)
  {
  }
  /*
   *
   */
  inline CPdfCustomMetadataContainer::~CPdfCustomMetadataContainer()
  {
  }
}
#endif // _CPdfCustomMetadataContainer_h_
