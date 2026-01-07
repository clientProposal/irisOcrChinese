/**
 * \file CDocumentMetadata.h
 * \brief Interface of the IDRS::CDocumentMetadata class.
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _CDocumentMetadata_h_
#define _CDocumentMetadata_h_

#include <CObjPtr.h>
#include "TObjPtrArray.h"
#include "CPageBookmark.h"
#include "CMetadataInfo.h"
#include "CDigitalSignature.h"
#include "CAttachment.h"

namespace IDRS
{
  class CDocumentMetadataData;
  class CMetadataInfo;
  /**
   * \brief CDocumentMetadata class represents the set of metadata defined at the document level.
   */
  class IDRSKRN_API CDocumentMetadata : public CObjPtr
  {
  public:
    /**
     * \brief Default constructor.
     */
    inline CDocumentMetadata();
    /**
     * \brief Constructor from a object
     *
     * \param argDocumentMetadataData The data object
     */
    inline CDocumentMetadata( CDocumentMetadataData * argDocumentMetadataData );
    /**
     * \brief Copy constructor
     *
     * \param argDocumentMetadata The smart pointer to the object to copy (shallow copy).
     */
    inline CDocumentMetadata( const CDocumentMetadata & argDocumentMetadata );
    /**
     * \brief Gets the MetadataInfo property value.
     * 
     * \return The CMetadataInfo object.
     */
    CMetadataInfo GetMetadataInfo( ) const;
    /**
     * \brief Sets the MetadataInfo property value.
     * 
     * \param argMetadataInfo a CMetadataInfo object.
     */
    void SetMetadataInfo( const CMetadataInfo &argMetadataInfo );
    /**
     * \brief Returns the page's bookmarks.
     */
    CPageBookmarkArray GetBookmarks( ) const;
    /**
     * \brief Sets the page's bookmarks.
     *
     * \pre !xBookmarks.IsNull()
     *
     * \param xBookmarks Array of bookmarks
     */
    void SetBookmarks( const CPageBookmarkArray& xBookmarks );
    /**
     * \brief Get the digital signatures associated to the ouput pdf document.
     *
     * \returns the digital signatures array
     */
    CDigitalSignatureArray GetDigitalSignatures( ) const;
    /**
     * \brief Set the digital signatures associated to the ouput pdf document.
     *
     * \param xDigitalSignatures digital signatures array
     */
    void SetDigitalSignatures( const CDigitalSignatureArray& xDigitalSignatures );
    /**
     * \brief Gets the array of attachments to add to the output PDF.
     *
     * \return The array of attachments
     */
    CAttachmentArray GetAttachments( ) const;
    /**
     * \brief Sets the array of attachments to add to the output PDF.
     *
     * \param argAttachmentArray The array of attachments
     *
     * \remarks It is not possible to set attachments for PDF/A-1 and PDF/A-2 files, therefore in this case an exception will be thrown.
     *
     * \remarks Calling this method with a NULL parameter will remove any attachments array from this object.
     */
    void SetAttachments( const CAttachmentArray& argAttachmentArray );
    /**
     * \brief Creates a new CDocumentMetadata instance.
     */
    static CDocumentMetadata Create();

  private:
    //! Internal use only
    CDocumentMetadataData& TypedObject( ) const
    {
      return (CDocumentMetadataData&)Object( );
    }
  };
  /*
   *
   */
  inline CDocumentMetadata::CDocumentMetadata( )
  {
  }
  /*
   *
   */
  inline CDocumentMetadata::CDocumentMetadata( CDocumentMetadataData* argDocumentMetadataData ) :
    CObjPtr( (CObj *) argDocumentMetadataData )
  {
  }
  /*
   *
   */
  inline CDocumentMetadata::CDocumentMetadata( const CDocumentMetadata& argDocumentMetadata ) :
    CObjPtr( (CObjPtr &)argDocumentMetadata )
  {
  }
}
#endif // _CDocumentMetadata_h_
