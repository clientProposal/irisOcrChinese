/**
 * \file IDocumentSeparationCallback.h
 * \brief Interface for IDocumentSeparationCallback class
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */

#ifndef _IDocumentSeparationCallback_h_
#define _IDocumentSeparationCallback_h_

#include "CObjPtr.h"

namespace IDRS
{
  /**
   * \brief IDocumentSeparationCallback defines the interface required to provide a custom document separation logic.
   */
  class IDRSKRN_API IDocumentSeparationCallback
  {
  public:
    //! Destructor
    inline virtual ~IDocumentSeparationCallback() = default;
    /**
     * \brief SeparateDocument callback method is automatically called by iDRS SDK for each page that is 
     * created by the document output engine, <b>before</b> it is added to the output document.
     *
     * \param uiDocumentSizeWithoutCurrentPage Size of the document without the current page added to it
     * \param uiDocumentSizeWithCurrentPage Size of the document if the current page would be added to it
     * \param uiPageCount Number of pages already added to the document (not including the current one)
     *
     * \retval IDRS_TRUE if the current document should be separated without adding the current page. The current page will be added to the next document
     * \retval IDRS_FALSE if the current page should be added to the current document
     */
    virtual IDRS_BOOL SeparateDocument( const IDRS_UINT64 uiDocumentSizeWithoutCurrentPage, const IDRS_UINT64 uiDocumentSizeWithCurrentPage, const IDRS_UINT uiPageCount ) = 0;
  };
} // namespace
#endif // _IDocumentSeparationCallback_h_
