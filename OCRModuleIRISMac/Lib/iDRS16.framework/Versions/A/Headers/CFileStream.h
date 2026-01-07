/**
 * \file CFileStream.h
 * \brief Interface for the IDRS::CFileStream class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _CFileStream_h_
#define _CFileStream_h_
#include "IByteStream.h"
namespace IDRS
{
  class CFileStreamData;
  class idrs_string;

  /**
   * \brief Class CFileStream provides an IByteStream implementation for reading and writing data from files
   * \ingroup module_core
   *
   * The file to be associated with the stream can be specified either as a parameter in the Create function or by calling member Open
   * After all necessary operations on a file have been performed, it can be closed (or disassociated) by calling member close.
   * Once closed, the same file stream object may be used to open another file.
   *
   * The member function IsOpen can be used to determine whether the stream object is currently associated with a file.
   */
  class IDRSKRN_API CFileStream : public IByteStream, public CObjPtr
  {
    public:
      /**
       * Constructs a IByteStream object.
       *
       */
      inline CFileStream ();
      /**
       * \brief Copy constructor.
       *
       * \param argFileStream The smart pointer to copy.
       */
      inline CFileStream ( const CFileStream & argFileStream );
      /**
       * \brief Smart pointer initialization constructor.
       *
       * \param pFileStreamData Pointer to the object.
       */
      inline CFileStream ( CFileStreamData * pFileStreamData );
      /**
       * \brief Destructor closes the file currently associated with the object, disassociating it from the stream.
       * Any pending output sequence is written to the physical file.
       */
      inline virtual ~CFileStream ();
      /**
       * \brief Create creates a CFileStream object and opens the stream.
       *
       * \param strFileName The name of the file to open.
       * \param evFileStreamMode The mode to open the file, by default Read.
       *
       */
      static CFileStream Create ( const idrs_string &strFileName, const FileStreamMode evFileStreamMode = FileStreamMode::Read );
      /**
       * \brief Open opens a stream.
       *
       * Closes the currently opened stream if necessary.
       *
       * \param strFileName The name of the file to open.
       * \param evFileStreamMode The mode to open the file, by default Read.
       *
       * \throw CIDRSException if an error occur.
       */
      void Open ( const idrs_string &strFileName, const FileStreamMode evFileStreamMode = FileStreamMode::Read);
      /**
       * \brief GetFileStreamMode returns the open file mode.
       *       
       * \pre IsOpen ()       
       *
       */
      FileStreamMode GetFileStreamMode() const;
      /**
       * \brief Read reads data from the stream at the current stream position.
       *
       * \pre pvMem != NULL
       * \pre IsOpen ()
       * \pre IsReadOpen ()
       *
       * \param pvMem The buffer that will receive the data.
       * \param uiToRead The number of bytes to transfer.
       *
       * \throw CIDRSException if an error occur.
       *
       * \return The number of bytes transfered from the stream to pvMem.
       */
      virtual IDRS_UINT Read ( IDRS_PVOID pvMem, const IDRS_UINT uiToRead );
      /**
       * \brief Write writes data in the stream at the current position.
       *
       * \pre pvMem != NULL
       * \pre IsOpen ()
       * \pre IsWriteOpen ()
       *
       * \param pvMem The buffer that contains the data to write.
       * \param uiToWrite The number of bytes to write.
       *
       * \throw CIDRSException if an error occur.
       *
       * \return The number of bytes transfered from pvMem to the stream.
       */
      virtual IDRS_UINT Write ( IDRS_CPVOID pvMem, const IDRS_UINT uiToWrite );
      /**
       * \brief Closes the current opened file
       *
       * Closes the file currently associated with the object, disassociating it from the stream. Any pending output sequence is written to the physical file.
       */
      virtual void Close ();
      /**
       * \brief Seek changes the current position in the file stream.
       *
       * \pre IsOpen ()
       *
       * \param iOffset The number of bytes to move the pointer.
       * \param evPos Pointer movement mode (from begin, current, or end position).
       *
       * \throw CIDRSException if an error occur.
       *
       * \return The new byte offset from the beginning of the file stream.
       */
      virtual IDRS_UINT64 Seek ( const IDRS_INT64 iOffset, const SeekPosition evPos);
      /**
       * \brief IsOpen tests if the file stream is opened in read or write mode
       *
       * \retval IDRS_TRUE if the file stream is opened
       * \retval IDRS_FALSE otherwise
       */
      virtual IDRS_BOOL IsOpen () const;
      /**
       * \brief IsWriteOpen tests if the file stream is opened in write mode.
       *
       * \retval IDRS_TRUE if the file stream is opened in write mode.
       * \retval IDRS_FALSE otherwise.
       *
       */
      virtual IDRS_BOOL IsWriteOpen () const;
      /**
       * \brief IsReadOpen tests if the file stream is opened in read mode.
       *
       * \retval IDRS_TRUE if the file stream is opened in read mode.
       * \retval IDRS_FALSE otherwise.
       */
      virtual IDRS_BOOL IsReadOpen () const;
      /**
       * \brief Deletes the file specified
       *
       * \param strFileName The name of the file to delete.
       *
       */
      static void Delete ( const idrs_string &strFileName );
    protected:
      /**
       * Internal use only
       */
      CFileStreamData & TypedObject () const
      {
        return ( CFileStreamData & )Object ();
      };
  };
  /*
   *
   */
  inline CFileStream::CFileStream ()
  {
  }
  /*
   *
   */
  inline CFileStream::CFileStream ( const CFileStream & argFileStream )
    : CObjPtr (( const CObjPtr & )argFileStream )
  {
  }
  /*
   *
   */
  inline CFileStream::CFileStream ( CFileStreamData * pFileStreamData )
    : CObjPtr ( ( CObjPtr * )pFileStreamData )
  {
  }
  /*
   *
   */
  inline CFileStream::~CFileStream ()
  {
  }
}  // namespace IDRS
#endif // _CFileStream_h_
