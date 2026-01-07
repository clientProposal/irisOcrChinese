/**
 * \file CObjPtr.h
 * \brief Interface to the IDRS::CObjPtr class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _CObjPtr_h_
#define _CObjPtr_h_
#include <CObj.h>
namespace IDRS
{
  /**
   * \brief Base class for all iDRS pointer classes.
   * \ingroup module_core
   *
   * It provides a safe way to use pointers on classes inheriting CObj because it correctly uses the reference
   * counter of the CObj class.
   *
   * All iDRS classes that inherit the "CObjPtr" class (like CPageRecognition, CPage and CImgProcessor ) use "smart pointers".
   * The memory area pointed to by a smart pointer is associated with a reference counter and this reference counter is updated during the creation, copying and destruction. The memory is freed when this reference counter reaches 0.
   *
   * For example:
   * \code
   * CPage aPage1, aPage2;
   * aPage1 = CPage::Create (); // Allocates memory and increments the reference counter to 1
   * aPage2 = aPage1; // Increments the reference counter to 2
   * aPage1 = NULL; // Decrements the reference counter to 1
   * aPage2 = NULL; // Decrements the reference counter to 0, the memory is freed
   * \endcode
   *
   * Of course, it isn't necessary to do aPage2 = NULL, the CPage destructor will decrement the counter itself.
   *
   */
  class IDRSKRN_API CObjPtr : public CObj
  {
    public:
      /**
       * Copy constructor.
       */
      inline CObjPtr ( const CObjPtr & ptr );
      /**
       * Constructs a CObjPtr that point at the given address.
       *
       * \param pObj Address of the object to point on. It can be NULL.
       *
       */
      inline CObjPtr ( CObj * pObj = nullptr );
      /**
       * Destructs the object.
       *
       * If it's pointing a non NULL address, it substracts a reference to the pointed object.
       */
      inline virtual ~CObjPtr ();
      /**
       * Give an access to the pointed object.
       *
       * \pre m_pObj != NULL
       *
       * \return A reference to the pointed object.
       */
      inline CObj & Object () const;
      /**
       * Assigns pObj to CObjPtr.
       *
       * \param pObj The address to point to.
       */
      inline CObjPtr & operator= ( CObj * pObj );
      /**
       * Copies the given pointer.
       *
       * \param toCopy The object to copy.
       */
      virtual inline CObjPtr & operator= ( const CObjPtr & toCopy );
      /**
       * Tests if the object points on something (NULL pointer test).
       *
       * \retval IDRS_TRUE if the pointer is NULL.
       * \retval IDRS_FALSE otherwise.
       */
      inline IDRS_BOOL IsNull () const;
      /**
       * Compares two pointers.
       *
       * \param toCompare The pointer to compare with.
       *
       * \retval IDRS_FALSE if the two objects are pointing on the same object or if they are together NULL.
       * \return IDRS_TRUE otherwise.
       */
      inline IDRS_BOOL operator!= ( const CObjPtr & toCompare ) const;
      /**
       * Compares two pointers.
       *
       * \param toCompare The pointer to compare with.
       *
       * \retval IDRS_TRUE if the two objects are pointing on the same object or if they are together NULL.
       * \retval IDRS_FALSE otherwise.
       */
      inline IDRS_BOOL operator== ( const CObjPtr & toCompare ) const;
    protected:
      /**
       * The address of the pointed object.
       */
      CObj * m_pObj;
  };
  /*
   *
   */
  inline CObjPtr::CObjPtr ( const CObjPtr & ptr )
    : m_pObj ( ptr.m_pObj )
  {
    if ( m_pObj != NULL )
    {
      m_pObj->AddRef ();
    }
  }
  /*
   *
   */
  inline CObjPtr::CObjPtr ( CObj * pObj )
    : m_pObj ( pObj )
  {
    if ( m_pObj != NULL )
    {
      m_pObj->AddRef ();
    }
  }
  /*
   *
   */
  inline CObjPtr::~CObjPtr ()
  {
    if ( m_pObj == NULL )
    {
      return;
    }
    m_pObj->SubRef ();
    m_pObj = NULL;
  }
  /*
   *
   */
  inline CObj & CObjPtr::Object () const
  {
    /* Preconditions */
    IDRS_DEBUG_ASSERT ( m_pObj != NULL );
    return *m_pObj;
  }
  /*
   *
   */
  inline CObjPtr & CObjPtr::operator= ( CObj * pObj )
  {
    if ( m_pObj != NULL )
    {
      m_pObj->SubRef ();
    }
    if (( m_pObj = pObj ) != NULL )
    {
      m_pObj->AddRef ();
    }
    return *this;
  }
  /*
   *
   */
  inline CObjPtr & CObjPtr::operator= ( const CObjPtr & toCopy )
  {
    if ( m_pObj != NULL )
    {
      m_pObj->SubRef ();
    }
    if (( m_pObj = toCopy.m_pObj ) != NULL )
    {
      m_pObj->AddRef ();
    }
    return *this;
  }
  /*
   *
   */
  inline IDRS_BOOL CObjPtr::IsNull () const
  {
    return ( m_pObj == NULL ) ? IDRS_TRUE : IDRS_FALSE;
  }
  /*
   *
   */
  inline IDRS_BOOL CObjPtr::operator!= ( const CObjPtr & toCompare ) const
  {
    return ( toCompare.m_pObj != m_pObj ) ? IDRS_TRUE : IDRS_FALSE;
  }
  /*
   *
   */
  inline IDRS_BOOL CObjPtr::operator== ( const CObjPtr & toCompare ) const
  {
    return ( toCompare.m_pObj == m_pObj ) ? IDRS_TRUE : IDRS_FALSE;
  }
} // namespace
#endif /* _CObjPtr_h_ */
