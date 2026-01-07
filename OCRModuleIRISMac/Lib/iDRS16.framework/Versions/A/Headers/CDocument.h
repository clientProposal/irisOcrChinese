/**
 * \file CDocument.h
 * \brief Interface of the IDRS::CDocument class.
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _CDocument_h_
#define _CDocument_h_

#include <CObjPtr.h>
#include "CDocumentMetadata.h"
#include "IPageCollection.h"

namespace IDRS
{
  class CIDRS;
  class CDocumentData;
  class CDocumentMetadata;
  /**
   * \brief CDocument class represents a document composed of a set of CPage elements.
   */
  class IDRSKRN_API CDocument : public CObjPtr
  {
  public:
    /**
     * \brief Default constructor.
     */
    inline CDocument();
    /**
     * \brief Constructor from a data object
     *
     * \param argDocumentData The data object
     */
    inline CDocument( CDocumentData * argDocumentData );
    /**
     * \brief Copy constructor
     *
     * \param argDocument The smart pointer to the other document.
     */
    inline CDocument( const CDocument & argDocument );
    /**
     * \brief Creates a new CDocument that uses a CDefaultPageCollection to handle the pages.
     * 
     * The CDefaultPageCollection page has two modes of operation:
     * - Non-blocking mode:
     *   Pages are added to the collection, then the Writer is called after all pages have been 
     *   added to generate the output document.
     * 
     * - Blocking mode:
     *   The Writer can be called to start generating the output document while pages are still 
     *   being added to the collection. If the Writer needs a page that has not been added to 
     *   the collection yet, it will be put on hold until it is inserted.
     *   Once all the pages have been added, the collection must be marked as complete using a flag, 
     *   so that the Writer knows that it should not wait for additional page.
     * 
     * Note that both modes are thread-safe.
     * 
     * \param argIDRS The CIDRS instance
     * \param bBlocking If set to 'IDRS_TRUE', enables the blocking mode for the page collection. Set to 'IDRS_FALSE' by default.
     */
    static CDocument Create( CIDRS &argIDRS, const IDRS_BOOL bBlocking = IDRS_FALSE );
    /**
     * \brief Creates a new CDocument that uses a custom IPageCollection
     *
     * \param argPageCollection Instance that implements the IPageCollection interface.
     */
    static CDocument Create( IPageCollection &argPageCollection );
    /**
     * \brief GetPages returns the collection of CPage elements.
     *
     * \return The IPageCollection instance where the document's pages are stored.
     */
    IPageCollection &GetPages() const;
    /**
     * \brief GetMetadata returns the document's metadata container
     *
     * \return The CDocumentMetadata instance containing the document level metadata.
     */
    CDocumentMetadata GetMetadata() const;
    /**
     * \brief SetMetadata sets the document's metadata
     *
     * \param argMetadata The metadata to be assigned to the document
     */
    void SetMetadata( const CDocumentMetadata &argMetadata );
  private:
    //! Internal use only
    CDocumentData& TypedObject( ) const
    {
      return (CDocumentData&)Object( );
    }
  };
  /*
   *
   */
  inline CDocument::CDocument( )
  {
  }
  /*
   *
   */
  inline CDocument::CDocument( CDocumentData* argDocumentData ) :
    CObjPtr( (CObj *) argDocumentData )
  {
  }
  /*
   *
   */
  inline CDocument::CDocument( const CDocument& argDocument ) :
    CObjPtr( (CObjPtr &) argDocument )
  {
  }
}
#endif // _CDocument_h_
