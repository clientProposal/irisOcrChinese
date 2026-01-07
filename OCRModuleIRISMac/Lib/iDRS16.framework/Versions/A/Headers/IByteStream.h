/**
 * \file IByteStream.h
 * \brief Interface to the IDRS::IByteStream class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _IByteStream_h_
#define _IByteStream_h_
#include <CObjPtr.h>
#include <EnumDefinitions.h>
namespace IDRS
{
  /**
   * \brief IByteStream defines the interface required to provide read, write and seek functionalities for a sequence of bytes.
   * \ingroup module_core
   */
  class IDRSKRN_API IByteStream
  {
    public:
      //! Destructor
      inline virtual ~IByteStream() = default;
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
      virtual IDRS_UINT Read ( IDRS_PVOID pvMem, const IDRS_UINT uiToRead ) = 0;
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
      virtual IDRS_UINT Write ( IDRS_CPVOID pvMem, const IDRS_UINT uiToWrite ) = 0;
      /**
       * \brief Seek changes the current position in the stream.
       *
       * \pre IsOpen ()
       *
       * \param iOffset The number of bytes to move the pointer.
       * \param evPos Pointer movement mode (from begin, current, or end position).
       *
       * \throw CIDRSException if an error occur.
       *
       * \return The new byte offset from the beginning of the stream.
       */
      virtual IDRS_UINT64 Seek ( const IDRS_INT64 iOffset, const SeekPosition evPos ) = 0;
      /**
       * \brief IsOpen tests if the stream is opened in read or write mode
       *
       * \retval IDRS_TRUE if the stream is opened
       * \retval IDRS_FALSE otherwise
       */
      virtual IDRS_BOOL IsOpen () const = 0;
      /**
       * \brief IsWriteOpen tests if the stream is opened in write mode.
       *
       * \retval IDRS_TRUE if the stream is opened in write mode.
       * \retval IDRS_FALSE otherwise.
       *
       */
      virtual IDRS_BOOL IsWriteOpen () const = 0;
      /**
       * \brief IsReadOpen tests if the stream is opened in read mode.
       *
       * \retval IDRS_TRUE if the stream is opened in read mode.
       * \retval IDRS_FALSE otherwise.
       */
      virtual IDRS_BOOL IsReadOpen () const = 0;
  };
} // namespace
#endif /* _IByteStream_h_ */
