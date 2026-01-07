/**
 * \file CDefaultPageCollection.h
 * \brief Declaration of the IDRS::CDefaultPageCollection interface.
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _CDefaultPageCollection_h_
#define _CDefaultPageCollection_h_

#include "IPageCollection.h"
#include "CPageCollectionStorageOptions.h"
#include "CObjPtr.h"


namespace IDRS
{
  class CIDRS;
  class CDefaultPageCollectionData;
  /**
   * \brief CDefaultPageCollection is the default implementation for the IPageCollection interface.
   * 
   * This default implementation will store pages in memory until a given memory treshold is reached, after which
   * pages will be stored on disk as temporary files. This behavior can be configured via the StorageOptions property.
   *
   * This means that this default implementation is able to automatically:
   * - optimize performance for documents with a small number of pages (as all pages will be kept in memory)
   * - ensure the memory consumption will not raise dramatically when processing documents with huge number of pages (as pages
   *   will be stored on disk past the specified memory threshold)
   */
  class IDRSKRN_API CDefaultPageCollection : public CObjPtr, public IPageCollection
  {
  public:
    /**
     * \brief Constructor
     * 
     */
    inline CDefaultPageCollection( );
    /** 
     * \brief Destructor
     */
    inline virtual ~CDefaultPageCollection( );
    /**
     * \brief Constructor from a data object
     * 
     * \param argDefaultPageCollectionData The data object
     */
    inline CDefaultPageCollection( const CDefaultPageCollectionData *argDefaultPageCollectionData );
    /**
     * \brief Copy constructor
     *
     * \param argDefaultPageCollection The data object
     */
    inline CDefaultPageCollection( const CDefaultPageCollection &argDefaultPageCollection );
    /**
     * \brief Creates a new CDefaultPageCollection object.
     * 
     * \param argIDRS The CIDRS instance
     * \param bBlocking If set to 'IDRS_TRUE', enables the blocking mode. Set to 'IDRS_FALSE' by default.
     */
    static CDefaultPageCollection Create( const CIDRS &argIDRS, const IDRS_BOOL bBlocking = IDRS_FALSE );
    /**
     * \brief GetType returns the type of this collection, either default or custom
     * 
     * \return The collection type
     */
    PageCollectionType GetType( ) const override;
    /**
     * \brief GetAt returns the page at the specified position
     * 
     * \param uiPageIndex The index of the page to retrieve
     * 
     * \return The CPage object if it exists, a null pointer otherwise
     */
    CPage GetAt( const IDRS_UINT uiPageIndex ) const override;
    /**
     * \brief Sets the page at the specified position
     * 
     * \param uiPageIndex The index of the page
     * \param argPage The page object
     * 
     * \note If the the index is out of bounds, for instance greater than the highest index in the
     *       collection, the missing elements are filled-in with empty records.
     */
    void SetAt( const IDRS_UINT uiPageIndex, const CPage &argPage ) override;
    /**
     * \brief Adds the specified page after the one stored with the highest index in the collection.
     *
     * \param argPage The page object to insert
     */
    void AddTail( const CPage& argPage ) override;
    /**
     * \brief Sets the flag that indicates whether the page at specified index has been processed by CDocumentWriter.
     *
     * \param uiPageIndex The index of the page
     * \param bValue The boolean flag value.
     */
    void SetPageProcessed( const IDRS_UINT uiPageIndex, const IDRS_BOOL bValue = IDRS_TRUE ) override;
    /**
     * \brief Reads the flag that indicates whether the page at specified index has been processed by CDocumentWriter.
     *
     * \param uiPageIndex The index of the page
     * \return The flag value.
     */
    IDRS_BOOL GetPageProcessed( const IDRS_UINT uiPageIndex ) const override;
    /**
     * \brief Sets the storage options 
     * 
     * \param argStorageOptions The storage options
     */
    void SetStorageOptions( const CPageCollectionStorageOptions &argStorageOptions );
    /**
     * \brief Gets the storage options
     * 
     * \return The storage options
     */
    CPageCollectionStorageOptions GetStorageOptions( ) const;
    /**
     * \brief Sets the flag that indicates whether the document's full set of pages is ready for the DocumentWriter.
     *
     * \param bValue The flag value
     */
    void SetReadyToClose( const IDRS_BOOL bValue );
    /**
     * \brief Gets the flag that indicates whether the document's full set of pages is ready for the DocumentWriter.
     *
     * \return IDRS_TRUE if the collection contains all the pages of the document, IDRS_FALSE is the collection only contains a partial set.
     */
    IDRS_BOOL GetReadyToClose( ) const;

  private:
    //! Internal use only
    CDefaultPageCollectionData& TypedObject( ) const
    {
      return (CDefaultPageCollectionData&)Object( );
    }
  };
  /*
   *
   */
  inline CDefaultPageCollection::CDefaultPageCollection(  )
  {
  }
  /*
   *
   */
  inline CDefaultPageCollection::~CDefaultPageCollection(  )
  {
  }
  /*
   *
   */
  inline CDefaultPageCollection::CDefaultPageCollection( const CDefaultPageCollectionData* argDefaultPageCollectionData ) : 
    CObjPtr( (CObj *) argDefaultPageCollectionData )
  {
  }
  /*
   *
   */
  inline CDefaultPageCollection::CDefaultPageCollection( const CDefaultPageCollection& argDefaultPageCollection ) : 
    CObjPtr( (CObjPtr &) argDefaultPageCollection )
  {
  }
}
#endif // _CDefaultPageCollection_h_
