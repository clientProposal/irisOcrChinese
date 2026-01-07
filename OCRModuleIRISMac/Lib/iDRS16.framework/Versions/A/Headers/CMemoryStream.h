/**
 * \file CMemoryStream.h
 * \brief Interface for the IDRS::CMemoryStream class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _CMemoryStream_h_
#define _CMemoryStream_h_
#include <CObjPtr.h>
#include <IByteStream.h>
namespace IDRS
{
  class CMemoryStreamData;
  class CMemoryBuffer;
  /**
   * \brief The CMemoryStream class provides a IByteStream implementation for reading and writing memory zones.
   * \ingroup module_core
   *
   * The memory is allocated in heap and the class guarantees that the allocated memory is freed on object destruction.
   * In case the initial allocated memory is not sufficient, the class will automatically allocate more memory.
   *
   */
  class IDRSKRN_API CMemoryStream : public IByteStream, public CObjPtr
  {
    public:
      /**
       * \brief Default constructor.
       */
      inline CMemoryStream ();
      /**
       * \brief Copy constructor.
       *
       * \param argMemoryStream The smart pointer to copy.
       */
      inline CMemoryStream ( const CMemoryStream & argMemoryStream );
      /**
       * \brief Constructor.
       *
       * \param pMemoryStreamData The object to point to.
       */
      inline CMemoryStream ( CMemoryStreamData * pMemoryStreamData );
      /**
       * \brief Destructor
       */
      inline virtual ~CMemoryStream ();
      /**
       * \brief The Create method creates a memory stream object.
       *
       * \param uiInitialMemoryBufferSize The initial memory buffer size.
       *
       * \return The newly created memory stream.
       *
       * \throw CIDRSException if an error occur.
       */
      static CMemoryStream Create ( const IDRS_UINT uiInitialMemoryBufferSize = 0);
      /**
       * \brief The Create method creates a memory stream object and initializes the underlying buffer object with the supplied object.
       * If opened for writing, the memory stream object can increase the size of the supplied memory buffer
       *
       * \param argMemoryBuffer Memory buffer where the memory stream object will read/write the data.
       *
       * \return The newly created memory stream.
       *
       * \throw CIDRSException if an error occur.
       */
      static CMemoryStream Create ( CMemoryBuffer& argMemoryBuffer );
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
       * \param pvMem The buffer that contains the data to transfer
       * \param uiToWrite The number of bytes to transfer
       *
       * \throw CIDRSException if an error occur.
       *
       * \return The number of bytes transfered from pvMem to the stream.
       */
      virtual IDRS_UINT Write ( IDRS_CPVOID pvMem, const IDRS_UINT uiToWrite );
      /**
       * \brief Seek changes the current position in the stream.
       *
       * \pre IsOpen ()
       *
       * If the current position after cursor update is less than 0, the function will set the current position to 0
       * If the current position after cursor update is greater than the maximum allocated memory,
       * the class will automatically allocate enough memory so the required cursor position will be valid within the memory buffer
       *
       * \param iOffset The number of bytes to move the pointer.
       * \param evPos Pointer movement mode (from begin, current, or end position).
       *
       * \throw CIDRSException if an error occur.
       *
       * \return The new byte offset from the beginning of the stream.
       */
      virtual IDRS_UINT64 Seek ( const IDRS_INT64 iOffset, const SeekPosition evPos);
      /**
       * \brief IsOpen tests if the stream is opened in read or write mode
       *
       * \retval IDRS_TRUE if the stream is opened
       * \retval IDRS_FALSE otherwise
       */
      virtual IDRS_BOOL IsOpen () const;
      /**
       * \brief IsWriteOpen tests if the stream is opened in write mode.
       *
       * \retval IDRS_TRUE if the stream is opened in write mode.
       * \retval IDRS_FALSE otherwise.
       *
       */
      virtual IDRS_BOOL IsWriteOpen () const;
      /**
       * \brief IsReadOpen tests if the stream is opened in read mode.
       *
       * \retval IDRS_TRUE if the stream is opened in read mode.
       * \retval IDRS_FALSE otherwise.
       */
      virtual IDRS_BOOL IsReadOpen () const;
      /**
       * \brief GetWrittenCount outputs the number of bytes written to the output stream
       *
       * Please note that it only makes sense to call this function when the stream is opened in write mode
       *
       * \return Number of bytes written to the stream
       */
      virtual IDRS_UINT GetWrittenCount() const;
    private:
      //! For internal use only
      CMemoryStreamData & TypedObject () const
      {
        return ( CMemoryStreamData & )Object ();
      };
  };
  /*
   *
   */
  inline CMemoryStream::CMemoryStream ()
  {
  }
  /*
   *
   */
  inline CMemoryStream::CMemoryStream ( const CMemoryStream & argMemoryStream )
    : CObjPtr (( CObjPtr & )argMemoryStream )
  {
  }
  /*
   *
   */
  inline CMemoryStream::CMemoryStream ( CMemoryStreamData * pMemoryStreamData )
    : CObjPtr (( CObj * )pMemoryStreamData )
  {
  }
  /*
   *
   */
  inline CMemoryStream::~CMemoryStream ()
  {
  }
} // namespace
#endif /* _CMemoryStream_h_ */
