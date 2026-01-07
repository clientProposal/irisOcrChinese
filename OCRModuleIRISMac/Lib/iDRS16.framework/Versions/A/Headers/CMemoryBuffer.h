/**
 * \file CMemoryBuffer.h
 * \brief Interface for the IDRS::CMemoryBuffer class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _cmemorybuffer_h_
#define _cmemorybuffer_h_
#include <CObjPtr.h>
namespace IDRS
{
  class CMemoryBufferData;
  /**
   * \brief CMemoryBuffer class manages a memory buffer.
   * \ingroup module_core
   *
   *
   */
  class IDRSKRN_API CMemoryBuffer : public CObjPtr
  {
    public:
      /**
       * The default constructor.
       */
      inline CMemoryBuffer ();
      /**
       * The copy constructor.
       *
       * \param argMemoryBuffer The memory buffer to copy.
       */
      inline CMemoryBuffer ( const CMemoryBuffer & argMemoryBuffer );
      /**
       * The constructor creates an object with the memory buffer data.
       *
       * \param pObj The pointer that points to the memory buffer data.
       */
      inline CMemoryBuffer ( CMemoryBufferData * pObj );
      /**
       * The destructor.
       */
      inline virtual ~CMemoryBuffer ();
      /**
       * \brief The Create method creates a memory buffer object.
       *
       * \param uiInitialMemoryBufferSize The initial memory buffer size.
       *
       * \return The newly created memory buffer.
       *
       * \throw CIDRSException if an error occur.
       *
       */
      static CMemoryBuffer Create ( const IDRS_UINT uiInitialMemoryBufferSize = 0 );
      /**
       * \brief Creates a memory buffer object holding the provided data.
       *
       * \param pvData The data to hold in the buffer.
       * \param uiDataSize The size of the data
       *
       * \return The newly created memory buffer.
       *
       * \remarks The data buffer will be copied internally in the memory buffer.
       *
       * \throw CIDRSException if an error occur.
       */
      static CMemoryBuffer Create ( const IDRS_PVOID pvData, const IDRS_UINT uiDataSize );
      /**
       * \brief Allocate reallocates the memory buffer.
       *
       * The size of the memory buffer may be increase or decreased.
       *
       * \pre ! IsNull ()
       * \pre uiMemSize != 0
       *
       * \param uiMemSize The size of memory needed.
       *
       * \throw CIDRSException if an error occur.
       *
       */
      [[deprecated("Use Resize or ReserveCapacity")]]void Allocate ( const IDRS_UINT uiMemSize );
      /**
       * \brief Resizes the underlying memory buffer.
       *
       * If the provided size is larger that current size but lower than the current reserved capacity, then no new memory will be allocated.
       * If the provided size is lower than the current size, then reserved capacity will be lowered to the provided value.
       * If the provided size is higher than the current reserved capacity, then the underlying buffer will be re-allocated.
       * The size of the re-allocated buffer will be at least the size provided for Resize operation. You can get the reserved capacity size using the method GetReservedCapacity.
       *
       * The size of the memory buffer may be increase or decreased.
       *
       * \pre ! IsNull ()
       * \pre uiMemorySize64 != 0
       *
       * \param uiMemorySize64 The size of memory needed.
       *
       * \throw CIDRSException if an error occur.
       *
       */
      void Resize( const IDRS_UINT64 uiMemorySize64 );
      /**
       * \brief Reserves memory for the underlying memory buffer.
       *
       * This method controls how much memory is allocated for the underlying buffer.
       * Providing a lower value that the current size will cause the underlying memory buffer size to be reduced
       *
       * \pre ! IsNull ()
       * \pre uiMemorySize64 != 0
       *
       * \param uiMemorySize64 The size of memory needed.
       *
       * \throw CIDRSException if an error occur.
       *
       */
      void ReserveCapacity( const IDRS_UINT64 uiMemorySize64 );
      /**
       * \brief GetSize returns the number of bytes allocated through Resize.
       *
       * Please note that the total number of bytes in memory allocated might be larger.
       *
       * \return Size in bytes of the allocated buffer
       */
      IDRS_UINT GetSize () const;
      /**
       * \brief GetReserved returns the number of bytes allocated
       *
       * \return Size in bytes of the allocated buffer
       */
      IDRS_UINT64 GetReservedCapacity() const;

      /**
       * \brief GetData returns the memory data
       *
       * Please note that the provided buffer data has the real size indicated by GetReserved.
       *
       * \return Memory pointer on the data.
       */
      IDRS_PVOID GetData () const;
    private:
      //! Private use only
      CMemoryBufferData & TypedObject () const
      {
        return ( CMemoryBufferData & )Object ();
      };
  };
  /*
   *
   */
  inline CMemoryBuffer::CMemoryBuffer ()
  {
  }
  /*
   *
   */
  inline CMemoryBuffer::CMemoryBuffer ( const CMemoryBuffer & argMemoryBuffer )
    : CObjPtr (( CObjPtr & )argMemoryBuffer )
  {
  }
  /*
   *
   */
  inline CMemoryBuffer::CMemoryBuffer ( CMemoryBufferData * pObj )
    : CObjPtr (( CObj* )pObj )
  {
  }
  /*
   *
   */
  inline CMemoryBuffer::~CMemoryBuffer ()
  {
  }
} //namespace
#endif /* _cmemorybuffer_h_ */
