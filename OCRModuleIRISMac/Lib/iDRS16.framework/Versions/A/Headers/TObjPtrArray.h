/**
 * \file TObjPtrArray.h
 * \brief Interface for TObjPtrArray class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _TObjPtrArray_h_
#define _TObjPtrArray_h_

#include "CObjPtr.h"
#include "CObjArray.h"
#include "IArrayInterfaceT.h"
#include "CCopyArray.h"

namespace IDRS
{
  /*
   * Internal logic to dynamically infer the correct storage class used by an array.
   */
  // Conditional selector based on boolean flag
  template <bool _Test, class _Ty1, class _Ty2>
  struct Conditional
  {
    // Choose _Ty1 if _Test is true, and _Ty2 otherwise
    using Type = _Ty1;
  };
  // Partial template specialization for boolean flag value = false
  template <class _Ty1, class _Ty2>
  struct Conditional<false, _Ty1, _Ty2>
  {
    using Type = _Ty2;
  };
  // Alternative implementation of std::is_base_of (working only with public class inheritance)
  template<class B, class D>
  struct IsBaseOf
  {
    static const bool value = __is_base_of(B, D);
  };

  // Array traits for standard value types
  template <typename T, bool = IsBaseOf<CObj, T>::value>
  struct TObjPtrArrayImplSelector
  {   
    using ArrayImpl = CCopyArray<T>;
    using iterator = typename CCopyArray<T>::iterator;
    using const_iterator = typename CCopyArray<T>::const_iterator;
    static inline T Get(const T& argValue)
    {
      return argValue;
    }
  };

  // Array traits for CObjPtr-derived types
  template <typename T>
  struct TObjPtrArrayImplSelector<T, true>
  {
    using ArrayImpl = CObjArray;
    using iterator = CObjArrayIteratorImpl<T>;
    using const_iterator = CObjArrayConstIteratorImpl<T>;
    static inline T Get(const CObjPtr& argValue)
    {
      return T(&argValue.Object());
    }
  };

  /**
   * \brief TObjPtrArray is a template class used to store arrays (including CObjPtr)
   */
  template <class T>
  class IDRSKRN_API TObjPtrArray final : public TObjPtrArrayImplSelector<T>::ArrayImpl, public IArrayInterfaceT<T>
  {
  public:
    using ArrayImpl = typename TObjPtrArrayImplSelector<T>::ArrayImpl;
    using iterator = typename TObjPtrArrayImplSelector<T>::iterator;
    using const_iterator = typename TObjPtrArrayImplSelector<T>::const_iterator;
    using value_type = T;

    /**
     * \brief Default constructor
     */
    inline TObjPtrArray();
    /**
     * \brief Copy constructor
     *
     * \param argTObjPtrArray Object to copy (shallow copy)
     */
    inline TObjPtrArray(const TObjPtrArray& argTObjPtrArray);
    /**
     * \brief TObjPtrArray constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pargTObjPtrArrayData Pointer to an object representing the data class
     */
    inline TObjPtrArray(CObj* pargTObjPtrArrayData);
    /**
     * \brief Destructor
     */
    inline virtual ~TObjPtrArray();
    /**
     * \brief Creates a new instance of TObjPtrArray<T>
     */
    inline static TObjPtrArray Create();
    /**
     * \return The count of elements in the array.
     */
    inline IDRS_UINT GetCount() const final;
    /**
     * \pre uiIndex < GetCount ()
     *
     * \param uiIndex The index of the element to retrieve.
     *
     * \return The element at the given index.
     */
    inline virtual T GetAt(const IDRS_UINT uiIndex) const;
    /**
     * \pre uiIndex < GetCount ()
     *
     * \param uiIndex The index of the element to retrieve.
     *
     * \return The element at the given index.
     */
    inline virtual T operator[] (const IDRS_UINT uiIndex) const;
    /**
     * Replaces the element at the given index.
     *
     * \pre uiIndex < GetCount ()
     * \pre ! toSet.IsNull ()
     *
     * \param uiIndex The index of the element to replace.
     * \param toSet The element to place in the array.
     */
    inline virtual void SetAt(const IDRS_UINT uiIndex, const T & toSet);
    /**
     * Adds the given element at the end of the array.
     *
     * \pre ! toAdd.IsNull ()
     *
     * \param toAdd The element to add.
     */
    inline virtual void AddTail(const T & toAdd);
    /**
     * Inserts an element in the array.
     *
     * \pre uiIndex <= GetCount ()
     * \pre ! toInsert.IsNull ()
     *
     * \param uiIndex The index where to insert the element.
     * \param toInsert The element to insert.
     */
    inline virtual void InsertAt(const IDRS_UINT uiIndex, const T & toInsert);
    /**
     * Removes the elements starting at the given index.
     *
     * \pre uiCount != 0
     * \pre uiFirstEltIndex + uiCount <= GetCount ()
     *
     * \param uiFirstEltIndex The index of the first element to remove.
     * \param uiCount The number of elements to remove.
     *
     */
    inline virtual void RemoveAt(const IDRS_UINT uiFirstEltIndex, const IDRS_UINT uiCount = 1);
    /**
     * Removes all the elements from the array.
     */
    inline virtual void RemoveAll();
    /**
     * Checks if the array contains the provided element.
     *
     * \param argObject The element to search for
     *
     * \return IDRS_TRUE if the array contains the element, IDRS_FALSE otherwise
     */
    inline virtual IDRS_BOOL Contains(const T argObject) const;
    /**
     * \brief Returns a hash value for the array.
     *
     * \return A hash value for the array
     *
     * \remarks The hash is guaranteed to remain identical as long as the array is not updated.
     * The following calls will trigger a change of hash:
     * - SetAt
     * - AddTail
     * - InsertAt
     * - Remove
     * - RemoveAll
     * Integrator code can therefore check the hash of an array to find out if it has changed since last access.
     *
     * \attention Note that the hash will NOT be updated when contained objects themselves are updated (for instance updated properties).
     */
    inline virtual IDRS_UINT64 GetHash() const;
    /**
     * \brief Sets boolean flag that enables synchronous access to operations that modify the content of the array
     * 
     * \param bSynchronized Boolean flag that enables/disables synchronous access to array
     */
    inline virtual void SetSynchronized(const IDRS_BOOL bSynchronized);
    /**
     * \brief Gets boolean flag that enables synchronous access to operations that modify the content of the array
     *
     * \return Boolean flag that enables/disables synchronous access to array
     */
    inline virtual IDRS_BOOL IsSynchronized() const;

    /**
     * \brief Gets an iterator to the beginning of the array
     *
     * \return the begin iterator
     *
     * \remark Iterators are invalidated whenever an element is added to the collection
     */
    inline iterator begin();
    inline const_iterator begin() const;

    /**
     * \brief Gets an iterator past the end of the array
     *
     * \return the end iterator
     *
     * \remark Iterators are invalidated whenever an element is added to the collection
     */
    inline iterator end();
    inline const_iterator end() const;

    /**
     * \brief Pushes an element to the end of the array
     * \param argObject the element to push
     * \remark similar to AddTail, but provided for compatibility with std::back_insert_iterator
     */
    inline void push_back(const T& argObject);
  private:
    //! Internal use 
    ArrayImpl& TypedObject() const
    {
      return static_cast<ArrayImpl&>(ArrayImpl::Object());
    };
  };
  /*
   *
   */
  template <class T>
  inline TObjPtrArray<T>::TObjPtrArray()
  {
  }
  /*
   *
   */
  template <class T>
  inline TObjPtrArray<T>::TObjPtrArray(const TObjPtrArray& argTObjPtrArray)
    : ArrayImpl(argTObjPtrArray)
  {
  }
  /*
   *
   */
  template <class T>
  inline TObjPtrArray<T>::TObjPtrArray(CObj* pargTObjPtrArrayData)
    : ArrayImpl(pargTObjPtrArrayData)
  {
  }
  /*
   *
   */
  template <class T>
  inline TObjPtrArray<T>::~TObjPtrArray()
  {
  }

  /*
   *
   */
  template <class T>
  inline TObjPtrArray<T> TObjPtrArray<T>::Create()
  {
    ArrayImpl objArray = ArrayImpl::Create();
    return TObjPtrArray<T>(&objArray.Object());
  }
  /*
   *
   */
  template <class T>
  inline IDRS_UINT TObjPtrArray<T>::GetCount() const
  {
    return ArrayImpl::GetCount();
  }
  /*
   *
   */
  template <class T>
  inline T TObjPtrArray<T>::GetAt(const IDRS_UINT uiIndex) const
  {
    return TObjPtrArrayImplSelector<T>::Get(ArrayImpl::GetAt(uiIndex));
  }
  /*
   *
   */
  template <class T>
  inline T TObjPtrArray<T>::operator[] (const IDRS_UINT uiIndex) const
  {
    return GetAt(uiIndex);
  }
  /*
   *
   */
  template <class T>
  inline void TObjPtrArray<T>::SetAt(const IDRS_UINT uiIndex, const T& toSet)
  {
    return ArrayImpl::SetAt(uiIndex, toSet);
  }
  /*
   *
   */
  template <class T>
  inline void TObjPtrArray<T>::AddTail(const T& toAdd)
  {
    return ArrayImpl::AddTail(toAdd);
  }
  /*
   *
   */
  template <class T>
  inline void TObjPtrArray<T>::InsertAt(const IDRS_UINT uiIndex, const T& toInsert)
  {
    return ArrayImpl::InsertAt(uiIndex, toInsert);
  }
  /*
   *
   */
  template <class T>
  inline void TObjPtrArray<T>::RemoveAt(const IDRS_UINT uiFirstEltIndex, const IDRS_UINT uiCount)
  {
    return ArrayImpl::RemoveAt(uiFirstEltIndex, uiCount);
  }
  /*
   *
   */
  template <class T>
  inline void TObjPtrArray<T>::RemoveAll()
  {
    return ArrayImpl::RemoveAll();
  }
  /*
   *
   */
  template <class T>
  inline IDRS_BOOL TObjPtrArray<T>::Contains(const T argObject) const
  {
    return ArrayImpl::Contains(argObject);
  }
  /*
   *
   */
  template <class T>
  inline IDRS_UINT64 TObjPtrArray<T>::GetHash() const
  {
    return ArrayImpl::GetHash();
  }
  /*
   *
   */
  template <class T>
  inline void TObjPtrArray<T>::SetSynchronized(const IDRS_BOOL bSynchronized)
  {
    return ArrayImpl::SetSynchronized(bSynchronized);
  }
  /*
   *
   */
  template <class T>
  inline IDRS_BOOL TObjPtrArray<T>::IsSynchronized() const
  {
    return ArrayImpl::IsSynchronized();
  }
  /*
   *
   */
  template <class T>
  inline auto TObjPtrArray<T>::begin() -> iterator
  {
    return ArrayImpl::begin();
  }
  /*
   *
   */
  template <class T>
  inline auto TObjPtrArray<T>::end() -> iterator
  {
    return ArrayImpl::end();
  }
  /*
   *
   */
  template <class T>
  inline auto TObjPtrArray<T>::begin() const -> const_iterator
  {
    return ArrayImpl::begin();
  }
  /*
   *
   */
  template <class T>
  inline auto TObjPtrArray<T>::end() const -> const_iterator
  {
    return ArrayImpl::end();
  }
  /*
   *
   */
  template <class T>
  inline void TObjPtrArray<T>::push_back(const T& argObject)
  {
    return ArrayImpl::AddTail(argObject);
  }
}
#endif // _TObjPtrArray_h_
