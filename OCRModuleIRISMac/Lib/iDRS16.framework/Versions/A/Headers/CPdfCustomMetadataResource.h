/**
 * \file CPdfCustomMetadataResource.h
 * \brief Interface for IDRS::CPdfCustomMetadataResource class
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */

#ifndef _CPdfCustomMetadataResource_h_
#define _CPdfCustomMetadataResource_h_


#include <CObjPtr.h>
#include <EnumDefinitions.h>

namespace IDRS
{
  class CPdfCustomMetadataResourceData;
  class idrs_string;
  /**
    * \brief CPdfCustomMetadataResource is the base class for a PDF metadata element.
    *
    * A metadata resource can be a either a list of properties or a container.
    */
  class IDRSKRN_API CPdfCustomMetadataResource : public CObjPtr
  {
    public:
      /**
        * \brief Default constructor.
        */
      inline CPdfCustomMetadataResource();
      /**
        * \brief Copy constructor.
        *
        * \param argPdfCustomMetadataResource The smart pointer to copy.
        */
      inline CPdfCustomMetadataResource(const CPdfCustomMetadataResource & argPdfCustomMetadataResource);
      /**
        * \brief Constructor.
        *
        * \param pPdfCustomMetadataResourceData The object to point to.
        */
      inline CPdfCustomMetadataResource(CPdfCustomMetadataResourceData * pPdfCustomMetadataResourceData);
      /**
        * \brief Destructor
        */
      inline virtual ~CPdfCustomMetadataResource();
      /**
        * \brief SetNamespacePrefix sets the namespace prefix for the resource 
        * 
        * The namespace prefix is used in all children properties or container tags that belong to this resource.
        * The default value is "idrs".
        *
        * \important The prefix string will be used directly in XML file that describe the pdf custom metadata inside the PDF file structure.
        * The following characters will render the xml invalid: '&', '<', '>', ' '
        *
        * \param strPrefix The namespace prefix value
        */
      void SetNamespacePrefix(const idrs_string& strPrefix);
      /**
        * \brief Returns the namespace prefix for the PDF metadata resource.
        *
        * \return The namespace prefix value.
        */
      const idrs_string& GetNamespacePrefix() const;
      /**
        * \brief SetNamespaceName sets the value of the namespace for the PDF metadata resource.
        *
        * The default value for a resource namespace is "https://ns.iriscorporate.com/xmp-idrs"
        *
        * \param strNamespaceName The name of the namespace resource
        */
      void SetNamespaceName(const idrs_string& strNamespaceName);
      /**
        * \brief GetNamespaceName returns the name of the PDF metadata resource namespace
        *
        * \return The namespace name
        */
      const idrs_string& GetNamespaceName() const;
      /**
        * \brief SetNamespace set both namespace prefix and namespace name for the metadata resource.
        *
        * The default value is: xmlns:idrs="https://ns.iriscorporate.com/xmp-idrs"
        *
        * \param strPrefix The namespace prefix value
        * \param strNamespaceName The namespace name
        */
      void SetNamespace(const idrs_string& strPrefix, const idrs_string& strNamespaceName);
      /** 
        * \brief SetDescription sets a description text associated with the PDF metadata resource
        *
        * \param strDescription The description text
        */
      void SetDescription(const idrs_string& strDescription);
      /**
        * \brief GetDescription returns the description text associated with the PDF metadata resource
        *
        * \return The description text
        */
      const idrs_string& GetDescription() const;
      /**
        * \brief GetPdfCustomMetadataType returns the type of metadata resource
        *
        * \return The metadata type 
        */
      PdfCustomMetadataResourceType GetPdfCustomMetadataType() const;
    private:
      // For internal use only
      CPdfCustomMetadataResourceData & TypedObject() const
      {
        return (CPdfCustomMetadataResourceData &)Object();
      };
  };
  /*
   *
   */
  inline CPdfCustomMetadataResource::CPdfCustomMetadataResource()
  {
  }
  /*
   *
   */
  inline CPdfCustomMetadataResource::CPdfCustomMetadataResource(const CPdfCustomMetadataResource & argPdfCustomMetadataResource)
    : CObjPtr( (CObjPtr &)argPdfCustomMetadataResource )
  {
  }
  /*
   *
   */
  inline CPdfCustomMetadataResource::CPdfCustomMetadataResource(CPdfCustomMetadataResourceData * pPdfCustomMetadataResourceData)
    : CObjPtr((CObj *) pPdfCustomMetadataResourceData)
  {
  }
  /*
   *
   */
  inline CPdfCustomMetadataResource::~CPdfCustomMetadataResource()
  {
  }
}
#endif // _CPdfCustomMetadataResource_h_
