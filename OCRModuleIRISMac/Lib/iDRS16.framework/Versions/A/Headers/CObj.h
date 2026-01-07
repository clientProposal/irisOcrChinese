/**
 * \file CObj.h
 * \brief Interface for the IDRS::CObj class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _CObj_h_
#define _CObj_h_
#include <idrskrn.h>
#include <CIDRSException.h>
/**
 * \brief Namespace representing the root namespace for all classes of the IRIS Developer Reading System.
 *
 */
namespace IDRS
{
  /**
   * \brief Base class for all iDRS classes.
   * \ingroup module_core
   *
   * CObj provides basic services for:
   * - memory management,
   * - secured pointers,
   * - reference count.
   *
   * Each iDRS object has a reference meter. The object counts the number of objects that are using it.
   * When an object is no longer used, it removes itself from memory.
   *
   */
  class IDRSKRN_API CObj
  {
    public:
      /**
       * Constructs a CObj object.
       *
       * Initializes the number of references to 1.
       *
       */
      inline CObj ();
      /**
       * Destructs the object.
       *
       * \pre m_uiRefCount == 1
       */
      inline virtual ~CObj ();
      /**
       * Adds a reference to the object.
       *
       * \pre m_uiRefCount >= 1
       *
       */
      void AddRef ();
      /**
       * Substracts a reference to the object, potentially deletes the object.
       *
       * \pre m_uiRefCount >= 1
       *
       */
      void SubRef ();
      /**
       * Allocates a block of memory.
       *
       * \pre stAllocateBlock != 0
       *
       * \param stAllocateBlock The size of the memory block to allocate.
       *
       * \return A void pointer to the allocated zone.
       */
      void * operator new ( size_t stAllocateBlock );
      /**
       * Frees the given zone of memory.
       *
       * \pre pvMem != NULL
       *
       * \param pvMem Pointer to the zone of memory to free.
       */
      void operator delete ( void * pvMem );
      /**
       * Allocate a block of memory for an array.
       *
       * \pre stAllocateBlock != 0
       *
       * \param stAllocateBlock The size of the memory block to allocate.
       *
       * \return A void pointer to the allocated zone.
       *
       * \throw CIDRSException if not enough memory is available.
       */
      void * operator new [] ( size_t stAllocateBlock );
      /**
       * Frees the given zone of memory.
       *
       * \pre pvMem != NULL
       *
       * \param pvMem Pointer to the zone of memory to free.
       */
      void operator delete [] ( void * pvMem );
      /**
       * \return The value for the reference count.
       */
      inline IDRS_UINT32 GetRefCount ();
    private:
      /**
       * The reference meter. It's equal to the number of objects that needs this one.
       */
      volatile IDRS_UINT32 m_uiRefCount;
  };
  /*
   *
   */
  inline CObj::CObj ()
    : m_uiRefCount ( 1 )
  {
  }
  /*
   *
   */
  inline CObj::~CObj ()
  {
  }
  /*
   *
   */
  inline IDRS_UINT32 CObj::GetRefCount ()
  {
    return m_uiRefCount;
  }
} // namespace
#endif /* _CObj_h_ */
