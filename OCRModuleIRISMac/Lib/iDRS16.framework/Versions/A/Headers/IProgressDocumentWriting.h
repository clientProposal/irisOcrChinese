/**
 * \file IProgressDocumentWriting.h
 * \brief Interface to the IDRS::IProgressDocumentWriting class.
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _IProgressDocumentWriting_h_
#define _IProgressDocumentWriting_h_
#include <CObj.h>
namespace IDRS
{
  /**
    * \brief IProgressDocumentWriting defines the interface required to monitor document writing progress.
    *
    * \ingroup module_document_output
    */
  class IDRSKRN_API IProgressDocumentWriting
  {
    public:
      //! Destructor
      inline virtual ~IProgressDocumentWriting () = default;
      /**
       * \brief BeginPageProcess is called whenever iDRS DocumentOutput engine starts the conversion of a page.
       *
       * \param uiPageIndex The index of the page that is being converted
       */
      virtual void BeginPageProcess ( const IDRS_UINT uiPageIndex ) = 0;
      /**
       * \brief GetAbortFlag can be overridden so the current process will be stopped if returning IDRS_TRUE.
       *
       * \return IDRS_TRUE to abort, IDRS_FALSE to continue
       */
      virtual IDRS_BOOL GetAbortFlag () = 0;
  };
}
#endif // _CProgressDocumentWriting_h_
