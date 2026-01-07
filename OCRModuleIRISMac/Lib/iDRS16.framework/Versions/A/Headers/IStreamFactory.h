/**
 * \file IStreamFactory.h
 * \brief Interface for IStreamFactory class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _IStreamFactory_h_
#define _IStreamFactory_h_
 
#include <CFileStream.h>
#include <CMemoryStream.h>

namespace IDRS
{
  /**
   * \brief IStreamFactory represents an interface used for output stream creation
   *
   * This interface can be used to create new streams for the output documents. 
   * Currently it is used for document split feature
   *
   * Currently the sequence of calls is always CreateStream then CloseStream.
   * However, integrators code should not reply on this assumption. There might be several CreateStream called before CloseStream
   */
  class IStreamFactory
  {
  public:
    //! Destructor
    inline virtual ~IStreamFactory () = default;
    /**
     * \brief CreateStream is instantiating a new stream that should be opened for write/read
     *
     * The output stream can be a file stream (CFileStream), a memory stream (CMemoryStream) or a custom defined stream
     *
     * The method is expected to return a pointer to the created stream. The class inheriting IStreamFactory should 
     * take the necessary precautions to keep the pointer valid until \see CloseStream is called
     *
     * \return Pointer to the created IByteStream object
     */
    virtual IByteStream* CreateStream() = 0;
    /**
     * \brief CloseStream is closing an output stream
     *
     * This method is called automatically when closing a stream created using \see CreateStream
     *
     * \param pStream Stream to close
     */
    virtual void CloseStream(IByteStream* pStream) = 0;
  };
}
 
#endif // _IStreamFactory_h_
