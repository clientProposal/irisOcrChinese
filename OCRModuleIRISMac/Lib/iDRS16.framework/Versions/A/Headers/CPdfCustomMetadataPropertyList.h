/**
 * \file CPdfCustomMetadataPropertyList.h
 * \brief Interface for IDRS::CPdfCustomMetadataPropertyList class
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */

#ifndef _CPdfCustomMetadataPropertyList_h_
#define _CPdfCustomMetadataPropertyList_h_

#include <CObjPtr.h>
#include "CPdfCustomMetadataResource.h"


namespace IDRS
{
  class CPdfCustomMetadataProperty;
  class CPdfCustomMetadataPropertyListData;
  /**
    * \brief CPdfCustomMetadataPropertyList represents a list of custom metadata properties
    *
    */
  class IDRSKRN_API CPdfCustomMetadataPropertyList : public CPdfCustomMetadataResource
  {
    public:
    /**
      * \brief Default constructor.
      */
    inline CPdfCustomMetadataPropertyList();
    /**
      * \brief Copy constructor.
      *
      * \param argPdfCustomMetadataPropertyList The smart pointer to copy.
      */
    inline CPdfCustomMetadataPropertyList(const CPdfCustomMetadataPropertyList & argPdfCustomMetadataPropertyList);
    /**
      * \brief Constructor.
      *
      * \param pPdfCustomMetadataPropertyListData The object to point to.
      */
    inline CPdfCustomMetadataPropertyList(CPdfCustomMetadataPropertyListData * pPdfCustomMetadataPropertyListData);
    /**
      * \brief Destructor
      */
    inline virtual ~CPdfCustomMetadataPropertyList();
    /**
      * \brief Create Creates a CPdfCustomMetadataPropertyList object.
      *
      * \throw CIDRSException if an error occurs.
      */
    static CPdfCustomMetadataPropertyList Create();
    /**
      * \brief Adds a new CPdfCustomMetadataProperty to the metadata properties list
      *
      * \param objPdfCustomMetadataProperty Object containing a cutsom metadata property.
      */
    void AddProperty(const CPdfCustomMetadataProperty & objPdfCustomMetadataProperty);
    /**
      * \brief Adds a list of CPdfCustomMetadataResource to the PDF custom metadata list
      *
      * \param objPdfCustomMetadataPropertyList a CPdfCustomMetadataPropertyList containing the properties to merge.
      */
    void AddPropertyList(const CPdfCustomMetadataPropertyList & objPdfCustomMetadataPropertyList);
    /**
      * \brief GetCount returns the number of properties stored in the list
      *
      * \return The number of metadata properties
      */
    IDRS_UINT GetCount() const;
    /**
      * \brief GetAt returns the CPdfCustomMetadataResource at a certain index
      *
      * \param uiIndex Index where to read the CPdfCustomMetadataResource
      *
      * \return The CPdfCustomMetadataResource at the supplied index
      */
    CPdfCustomMetadataProperty GetAt(const IDRS_UINT uiIndex) const;
    /**
      * \brief RemoveAt removes a CPdfCustomMetadataProperty from the list
      *
      * \param uiIndex The index where to remove the object
      */
    void RemoveAt(const IDRS_UINT uiIndex);
    /**
      * \brief RemoveAll removes all CPdfCustomMetadataProperty from the list
      */
    void RemoveAll();

  private:
    // For internal use only
    CPdfCustomMetadataPropertyListData & TypedObject() const
    {
      return (CPdfCustomMetadataPropertyListData &)Object();
    };
  };
  /*
   *
   */
  inline CPdfCustomMetadataPropertyList::CPdfCustomMetadataPropertyList()
  {
  }
  /*
   *
   */
  inline CPdfCustomMetadataPropertyList::CPdfCustomMetadataPropertyList(const CPdfCustomMetadataPropertyList & argPdfCustomMetadataPropertyList)
    : CPdfCustomMetadataResource( (CPdfCustomMetadataResource &) argPdfCustomMetadataPropertyList)
  {
  }
  /*
   *
   */
  inline CPdfCustomMetadataPropertyList::CPdfCustomMetadataPropertyList(CPdfCustomMetadataPropertyListData * pPdfCustomMetadataPropertyListData)
    : CPdfCustomMetadataResource( (CPdfCustomMetadataResourceData *) pPdfCustomMetadataPropertyListData)
  {
  }
  /*
   *
   */
  inline CPdfCustomMetadataPropertyList::~CPdfCustomMetadataPropertyList()
  {
  }
}
#endif // _CPdfCustomMetadataPropertyList_h_
