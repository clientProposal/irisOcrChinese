/**
 * \file IPageCollection.h
 * \brief Declaration of the IDRS::IPageCollection interface.
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _IPageCollection_h_
#define _IPageCollection_h_

#include "EnumDefinitions.h"
#include <idrskrn.h>

namespace IDRS
{
  class CPage;
  /**
   * \brief IPageCollection defines the interface for a page collection.
   *
   * The page collection interface is used by the CDocument class to store the pages of a document. Additionally
   * that interface is used internally by the CDocumentWriter to access the document's pages and generate the output.
   * The collections that implement that interface must be thread-safe.
   */
  class IDRSKRN_API IPageCollection
  {
  public:
    //! Destructor
    inline virtual ~IPageCollection () = default;
    /**
     * \brief GetType returns the type of this collection, either default or custom
     *
     * \remarks Integrator-defined page collections must return PageCollectionType::Custom
     *
     * \return The collection type
     */
    inline virtual PageCollectionType GetType () const;
    /**
     * \brief GetAt returns the page at the specified index.
     * 
     * \param uiPageIndex The index of the page to retrieve
     * 
     * \return The CPage object if it exists, a null pointer otherwise
     */
    virtual CPage GetAt( const IDRS_UINT uiPageIndex ) const = 0;
    /**
     * \brief Sets the page at the specified index in the collection.
     * 
     * \param uiPageIndex The index of the page
     * \param argPage The page object to put in the collection
     * 
     * \note If the the index is out of bounds, for instance greater than the highest index in the
     *       collection, the missing elements are filled-in with empty records.
     */
    virtual void SetAt( const IDRS_UINT uiPageIndex, const CPage &argPage ) = 0;
    /**
     * \brief Adds the specified page after the one stored with the highest index in the collection.
     *
     * \param argPage The page object to insert
     */
    virtual void AddTail( const CPage& argPage ) = 0;
    /**
     * \brief Sets the flag that indicates whether the page at specified index has been processed by CDocumentWriter.
     * 
     * \param uiPageIndex The index of the page
     * \param argValue The boolean flag value.
     */
    virtual void SetPageProcessed( const IDRS_UINT uiPageIndex, const IDRS_BOOL argValue ) = 0;
    /**
     * \brief Reads the flag that indicates whether the page at specified index has been processed by CDocumentWriter.
     * 
     * \param uiPageIndex The index of the page where to retrieve the PageProcessed flag.
     *
     * \return The flag value.
     */
    virtual IDRS_BOOL GetPageProcessed( const IDRS_UINT uiPageIndex ) const = 0;
  };
  /*
   *
   */
  PageCollectionType IPageCollection::GetType( ) const
  {
    return PageCollectionType::Custom;
  }
}
#endif // _IPageCollection_h_
