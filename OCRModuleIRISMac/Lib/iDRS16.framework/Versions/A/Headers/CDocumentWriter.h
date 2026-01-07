/**
 * \file CDocumentWriter.h
 * \brief Interface to the IDRS::CDocumentWriter class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _CDocumentWriter_h_
#define _CDocumentWriter_h_
#include <CIDRS.h>
#include <CPage.h>
#include <COutputParams.h>
#include <IStreamFactory.h>
#include <IProgressDocumentWriting.h>

namespace IDRS
{
  class IFontDataProviderCallback;
  class CDocumentWriterData;
  class CDocument;
  class idrs_string;

  /**
   * \brief The CDocumentWriter class exports iDRS structures to external file formats.
   *
   * \req IDRS::Module::DocumentOutput
   */
  class IDRSKRN_API CDocumentWriter : public CObjPtr
  {
    public:
      //
      inline CDocumentWriter ();
      //
      inline CDocumentWriter ( const CDocumentWriter & argFormat );
      //
      inline CDocumentWriter ( CDocumentWriterData * pObj );
      //
      inline virtual ~CDocumentWriter ();
      /**
       * \brief Create creates a CDocumentWriter object.
       *
       * \param argIDRS  The IDRS handle
       *
       * \throw CIDRSException if an error occur.
       *
       */
      static CDocumentWriter Create ( const CIDRS & argIDRS );
      /**
       * \brief Create creates a CDocumentWriter object.
       *
       * This CDocumentWriter object will use the specified image compressor.
       *
       * \param argIDRS  The IDRS handle
       * \param argImagePlugin The external image plugin to use.
       *
       * \throw CIDRSException if an error occur.
       *
       */
      static CDocumentWriter Create ( const CIDRS & argIDRS, IBaseImagePlugin & argImagePlugin );
      /**
       * \brief Creates the output file using the supplied document and writes it to the
       * given file path
       * 
       * \pre ! IsNull ()
       * 
       * \param strOutputFilePath The path to the output file.
       * \param argDocument The document containing the pages to format.
       * 
       * \return IDRS_SUCCESS on success, the error or warning identifier otherwise.
       */
      IDRS_ERROR Save( const idrs_string &strOutputFilePath, const CDocument& argDocument ) const;
      /**
       * \brief Creates the output file using the supplied document and writes it to the
       * given stream
       * 
       * \pre ! IsNull ()
       * \pre argOutputStream.IsReadOpen () && argOutputStream.IsWriteOpen ()
       * 
       * \param argOutputStream The stream where the document content will be written.
       * \param argDocument The document containing the pages to format.
       * 
       * \return IDRS_SUCCESS on success, the error or warning identifier otherwise.
       */
      IDRS_ERROR Save( IByteStream& argOutputStream, const CDocument& argDocument ) const;
      /**
       * \brief Creates the output file using the supplied pages array and writes it to the
       * given file path
       * 
       * \pre ! IsNull ()
       * 
       * \param strOutputFilePath The path to the output file.
       * \param argPageArray The array containing the pages to format.
       * 
       * \return IDRS_SUCCESS on success, the error or warning identifier otherwise.
       * 
       * \note Note that unlike the overload that takes a CDocument as a parameter, it is not 
       * possible to configure metadata that are specific to the document level, such as 
       * bookmarks, attachments, and metadata information.
       */
      IDRS_ERROR Save( const idrs_string &strOutputFilePath, const CPageArray& argPageArray ) const;
      /**
       * \brief Creates the output file using the supplied pages array and writes it to the
       * given stream
       *
       * \pre ! IsNull ()
       * \pre argOutputStream.IsReadOpen () && argOutputStream.IsWriteOpen ()
       *
       * \param argOutputStream The stream where the document content will be written.
       * \param argPageArray The array containing the pages to format.
       * 
       * \return IDRS_SUCCESS on success, the error or warning identifier otherwise.
       *
       * \note Note that unlike the overload that takes a CDocument as a parameter, it is not
       * possible to configure metadata that are specific to the document level, such as
       * bookmarks, attachments, and metadata information.
       */
      IDRS_ERROR Save( IByteStream& argOutputStream, const CPageArray& argPageArray ) const;
      /**
       * \brief Creates the output file using the supplied pages and writes it to the
       * given file path
       * 
       * \pre ! IsNull ()
       * 
       * \param strOutputFilePath The path to the output file.
       * \param xargPageBuffer The buffer containing the pages to format.
       * \param uiPageCount The number of pages in xPageBuffer.
       * 
       * \return IDRS_SUCCESS on success, the error or warning identifier otherwise.
       * 
       * \note Note that unlike the overload that takes a CDocument as a parameter, it is not 
       * possible to configure metadata that are specific to the document level, such as 
       * bookmarks, attachments, and metadata information.
       */
      IDRS_ERROR Save( const idrs_string &strOutputFilePath, const CPage xargPageBuffer[], const IDRS_UINT uiPageCount ) const;
      /**
       * \brief Creates the output file using the supplied pages and writes it to the
       * given stream
       *
       * \pre ! IsNull ()
       * \pre argOutputStream.IsReadOpen () && argOutputStream.IsWriteOpen ()
       *
       * \param argOutputStream The stream where the document content will be written.
       * \param xargPageBuffer The buffer containing the pages to format.
       * \param uiPageCount The number of pages in xPageBuffer.
       * 
       * \return IDRS_SUCCESS on success, the error or warning identifier otherwise.
       *
       * \note Note that unlike the overload that takes a CDocument as a parameter, it is not
       * possible to configure metadata that are specific to the document level, such as
       * bookmarks, attachments, and metadata information.
       */
      IDRS_ERROR Save( IByteStream& argOutputStream, const CPage xargPageBuffer[], const IDRS_UINT uiPageCount ) const;
      /**
       * \brief Creates one or more output documents using the supplied document object.
       * The method is using argStreamFactory to create one or more streams for the output document(s).
       *
       * The document will be split into one or more streams, according to the options set in argDocumentSplitParameters argument.
       *
       * \param argStreamFactory Output stream creator factory
       * \param argDocument CDocument instance containing the information about the image and the recognition results
       * 
       * \return IDRS_SUCCESS on success, the error or warning identifier otherwise.
       *
       * \see CDocument
       * \see IStreamFactory
       *
       * \note The document split feature is available for the moment with the following restrictions:
       * - PDF output only
       * - No encryption, certification, header/footer
       * - Linearization disabled
       * If the document split type is different than None and any of these constraint is not fulfilled,
       * an exception IDRS_ERROR_NOT_SUPPORTED will be thrown.
       */
      IDRS_ERROR Save( IStreamFactory& argStreamFactory, const CDocument& argDocument ) const;
      /**
       * \brief Creates one or more output documents using the supplied pages array.
       * The method is using argStreamFactory to create one or more streams for the output document(s).
       *
       * The document will be split into one or more streams, according to the options set in argDocumentSplitParameters argument.
       *
       * \param argStreamFactory Output stream creator factory
       * \param argPageArray The array containing the pages to format.
       * 
       * \return IDRS_SUCCESS on success, the error or warning identifier otherwise.
       *
       * \see IStreamFactory
       *
       * \note The document split feature is available for the moment with the following restrictions:
       * - PDF output only
       * - No encryption, certification, header/footer
       * - Linearization disabled
       * If the document split type is different than None and any of these constraint is not fulfilled,
       * an exception IDRS_ERROR_NOT_SUPPORTED will be thrown.
       * Unlike the overload that takes a CDocument as a parameter, it is not possible to configure metadata 
       * that are specific to the document level, such as  bookmarks, attachments, and metadata information.
       */
      IDRS_ERROR Save( IStreamFactory& argStreamFactory, const CPageArray& argPageArray ) const;
      /**
       * \brief Creates one or more output documents using the supplied pages.
       * The method is using argStreamFactory to create one or more streams for the output document(s).
       *
       * The document will be split into one or more streams, according to the options set in argDocumentSplitParameters argument.
       *
       * \param argStreamFactory Output stream creator factory
       * \param xargPageBuffer The buffer containing the pages to format.
       * \param uiPageCount The number of pages in xPageBuffer.
       * 
       * \return IDRS_SUCCESS on success, the error or warning identifier otherwise.
       *
       * \see IStreamFactory
       * \see CDocumentSplitParams
       *
       * \note The document split feature is available for the moment with the following restrictions:
       * - PDF output only
       * - No encryption, certification, header/footer
       * - Linearization disabled
       * If the document split type is different than None and any of these constraint is not fulfilled,
       * an exception IDRS_ERROR_NOT_SUPPORTED will be thrown.
       * Unlike the overload that takes a CDocument as a parameter, it is not possible to configure metadata 
       * that are specific to the document level, such as  bookmarks, attachments, and metadata information.
       */
      IDRS_ERROR Save( IStreamFactory& argStreamFactory, const CPage xargPageBuffer[], const IDRS_UINT uiPageCount ) const;
      /**
       * \brief Sets the parameters used to generate the output document.
       * 
       * The output parameters are used during the output document saving process, thus they must be set prior
       * to invoking the Save() method.
       * 
       * \param argOutputParams The output parameters.
       */
      void SetOutputParams( const COutputParams& argOutputParams );
      /**
       * \brief Gets the output parameters property value.
       * 
       * \return The output parameters.
       */
      COutputParams GetOutputParams( ) const;
      /**
       * \brief Gets the callback object used for formatting.
       * 
       * \return The callback pointer
       */
      IFontDataProviderCallback* GetFontDataProvider() const;
      /**
        * \brief Sets the callback class used by integrators to retrieve font data when creating documents.
        *
        * \param argpFontProviderCallback Reference to a class containing an implementation for IFontDataProviderCallback
        */
      void SetFontDataProvider(IFontDataProviderCallback* argpFontProviderCallback);
      /**
        * \brief Sets the threshold for the maximum amount of memory that will be allocated to
        * store the output document in memory. When nearing this threshold, temporary files will be used to avoid crossing it.
        *
        * \remarks For the moment the following limitations exist:
        * - Threshold is monitored only for PDF output format. Other formats will not take it into account (however they are
        *   less likely to grow very large in memory)
        * - For PDF, only compressed image stream size (usually a very large part of the PDF document itself) is taken into account.
        *
        * \param uiMaxMemoryConsumption The maximum memory consumption threshold (in bytes)
        */
      void SetDocumentMaxMemoryConsumption(const IDRS_UINT64 uiMaxMemoryConsumption);
      /**
        * \brief Gets the value for the max memory consumption threshold.
        *
        * \return The maximum memory consumption threshold (in bytes)
        */
      IDRS_UINT64 GetDocumentMaxMemoryConsumption() const;
      /**
        * \brief Sets the object for monitoring progress.
        *
        * The methods of the object overiding the methods of the IProgressDocumentWriting class will be called during the execution.
        * This let the integrator implement a cancel button or a progress bar.
        *
        * \param argpProgress The object to use for monitoring the progress.
        */
      void SetOutputProgressCallback ( IProgressDocumentWriting* argpProgress );
      /**
        * \brief GetOutputProgressCallback gets the object used for monitoring progress.       
        *
        * \return The callback pointer
        */
      IProgressDocumentWriting* GetOutputProgressCallback () const;
    private:
      //! Internal use only
      CDocumentWriterData & TypedObject () const
      {
        return ( CDocumentWriterData & )Object ();
      };
  };
  /*
   *
   */
  inline CDocumentWriter::CDocumentWriter ()
  {
  }
  /*
   *
   */
  inline CDocumentWriter::CDocumentWriter ( const CDocumentWriter & argFormat )
    : CObjPtr (( CObjPtr & )argFormat )
  {
  }
  /*
   *
   */
  inline CDocumentWriter::CDocumentWriter ( CDocumentWriterData * pObj )
    : CObjPtr (( CObj * )pObj )
  {
  }
  /*
   *
   */
  inline CDocumentWriter::~CDocumentWriter ()
  {
  }
} // namespace
#endif /* _CDocumentOutput_h_ */
