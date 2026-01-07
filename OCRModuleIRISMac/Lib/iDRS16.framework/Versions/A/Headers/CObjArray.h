/**
 * \file CObjArray.h
 * \brief Interface for CObjArray class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _CObjArray_h_
#define _CObjArray_h_

#include "CObjPtr.h"
#include "IArrayInterfaceT.h"

namespace IDRS
{
  class CObjArrayData;

  /**
   * \brief CObjArray represents the base class for TObjPtrArray which handles storage of CObjPtr objects
   *
   * This class provides CObjPtr objects to TObjPtrArray, which then handles transformation to the actual type
   */
  class IDRSKRN_API CObjArray : public CObjPtr
  {
  public:
    using value_type = CObj*;
    using iterator = value_type*;
    using const_iterator = const value_type*;
    /**
     * \brief Default constructor
     */
    inline CObjArray();
    /**
     * \brief Copy constructor
     *
     * \param argCObjArray Object to copy (shallow copy)
     */
    inline CObjArray(const CObjArray& argCObjArray);
    /**
     * \brief CObjArrayData constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pargCObjArrayData Pointer to an object representing the data class
     */
    inline CObjArray(CObjArrayData* pargCObjArrayData);
    /**
     * \brief CObjArrayData constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pargCObjData Pointer to an object representing the data class
     */
    inline CObjArray(CObj* pargCObjData);
    /**
     * \brief Destructor
     */
    inline virtual ~CObjArray();
    /**
     * \brief Creates a new instance of CObjArray
     */
    static CObjArray Create();
    /**
     * \return The count of elements in the array.
     */
    IDRS_UINT GetCount() const;
    /**
     * \pre uiIndex < GetCount ()
     *
     * \param uiIndex The index of the element to retrieve.
     *
     * \return The element at the given index.
     */
    CObjPtr GetAt(const IDRS_UINT uiIndex) const;
    /**
     * Replaces the element at the given index.
     *
     * \pre uiIndex < GetCount ()
     * \pre ! toSet.IsNull ()
     *
     * \param uiIndex The index of the element to replace.
     * \param toSet The element to place in the array.
     */
    void SetAt(const IDRS_UINT uiIndex, const CObjPtr & toSet);
    /**
     * Adds the given element at the end of the array.
     *
     * \pre ! toAdd.IsNull ()
     *
     * \param toAdd The element to add.
     */
    void AddTail(const CObjPtr & toAdd);
    /**
     * Inserts an element in the array.
     *
     * \pre uiIndex <= GetCount ()
     * \pre ! toInsert.IsNull ()
     *
     * \param uiIndex The index where to insert the element.
     * \param toInsert The element to insert.
     */
    void InsertAt(const IDRS_UINT uiIndex, const CObjPtr & toInsert);
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
    void RemoveAt(const IDRS_UINT uiFirstEltIndex, const IDRS_UINT uiCount = 1);
    /**
     * Removes all the elements from the array.
     */
    void RemoveAll();
    /**
     * Checks if the array contains the provided element.
     *
     * \param argObject The element to search for
     *
     * \return IDRS_TRUE if the array contains the element, IDRS_FALSE otherwise
     */
    IDRS_BOOL Contains(const CObjPtr& argObject) const;
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
    IDRS_UINT64 GetHash() const;
    /**
     * \brief Sets boolean flag that enables synchronous access to operations that modify the content of the array
     *
     * \param bSynchronized Boolean flag that enables/disables synchronous access to array
     */
    void SetSynchronized(const IDRS_BOOL bSynchronized);
    /**
     * \brief Gets boolean flag that enables synchronous access to operations that modify the content of the array
     *
     * \return Boolean flag that enables/disables synchronous access to array
     */
    IDRS_BOOL IsSynchronized() const;

    /**
     * \brief Gets an iterator to the beginning of the array
     *
     * \return the begin iterator
     *
     * \remark Iterators are invalidated whenever an element is added to the collection
     */
    iterator begin();
    const_iterator begin() const;

    /**
     * \brief Gets an iterator past the end of the array
     *
     * \return the end iterator
     *
     * \remark Iterators are invalidated whenever an element is added to the collection
     */
    iterator end();
    const_iterator end() const;

  private:
    //! Internal use 
    CObjArrayData & TypedObject() const
    {
      return (CObjArrayData &)Object();
    };
  };
  /*
   *
   */
  inline CObjArray::CObjArray()
  {
  }
  /*
   *
   */
  inline CObjArray::CObjArray(const CObjArray& argCObjArray)
    : CObjPtr((CObjPtr &)argCObjArray)
  {
  }
  /*
   *
   */
  inline CObjArray::CObjArray(CObjArrayData* pargCObjArrayData)
    : CObjPtr((CObj *)pargCObjArrayData)
  {
  }
  /*
   *
   */
  inline CObjArray::CObjArray(CObj* pargCObjData)
    : CObjPtr(pargCObjData)
  {
  }
  /*
   *
   */
  inline CObjArray::~CObjArray()
  {
  }
}
#endif // _CObjArray_h_

