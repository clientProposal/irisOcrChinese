/**
 * \file CCopyArray.h
 * \brief Interface for CCopyArray class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _CCopyArray_h_
#define _CCopyArray_h_

#include "CObjPtr.h"
#include "TObjArrayIteratorImpl.h"
namespace IDRS
{
  // Predeclaration of data class
  class CCopyArrayData;
  
  /**
   * \brief CCopyArray represents the base class for an array implementation which stores the provided elements by plain copy.
   *
   * \remarks It is not designed to work with classes.
   */
  template <typename T>
  class IDRSKRN_API CCopyArray : public CObjPtr
  {
  public:
    /**
     * \brief Default constructor
     */
    inline CCopyArray ();
    /**
     * \brief Copy constructor
     *
     * \param argOther Object to copy (shallow copy)
     */
    inline CCopyArray ( const CCopyArray<T>& argOther );
    /**
     * \brief Copy constructor that initializes an object from a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pData Pointer to the data object
     */
    inline CCopyArray ( CCopyArrayData* pData );
    /**
     * \brief Copy constructor that initializes an object from a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pData Pointer to the data object
     */
    inline CCopyArray(CObj* pData);
    /**
     * \brief Destructor
     */
    inline virtual ~CCopyArray ();
    /**
     * \brief Creates a new instance of CCopyArray
     */
    static CCopyArray Create ();
    /**
     * \return The count of elements in the array.
     */
    IDRS_UINT GetCount () const;
    /**
     * \pre uiIndex < GetCount ()
     *
     * \param uiIndex The index of the element to retrieve.
     *
     * \return A pointer to the element at the given index.
     */
    T GetAt ( const IDRS_UINT uiIndex ) const;
    /**
     * Replaces the element at the given index.
     *
     * \pre uiIndex < GetCount ()
     * \pre pElement != NULL
     *
     * \param uiIndex The index of the element to replace.
     * \param pElement The element to place in the array.
     */
    void SetAt ( const IDRS_UINT uiIndex, const T& pElement );
    /**
     * Adds the given element at the end of the array.
     *
     * \pre pElement != NULL
     *
     * \param pElement The element to add.
     */
    void AddTail ( const T& pElement );
    /**
     * Inserts an element in the array.
     *
     * \pre uiIndex <= GetCount ()
     * \pre pElement != NULL
     *
     * \param uiIndex The index where to insert the element.
     * \param pElement The element to insert.
     */
    void InsertAt ( const IDRS_UINT uiIndex, const T& pElement );
    /**
     * Removes the elements starting at the given index.
     *
     * \pre uiRemoveCount != 0
     * \pre uiStartIndex + uiRemoveCount <= GetCount ()
     *
     * \param uiStartIndex The index of the first element to remove.
     * \param uiRemoveCount The number of elements to remove.
     */
    void RemoveAt ( const IDRS_UINT uiStartIndex, const IDRS_UINT uiRemoveCount = 1 );
    /**
     * Removes all the elements from the array.
     */
    void RemoveAll();
    /**
     * Checks if the array contains the provided element.
     *
     * \param pElement The element to search for
     *
     * \return IDRS_TRUE if the array contains the element, IDRS_FALSE otherwise
     */
    IDRS_BOOL Contains ( const T& pElement ) const;
    /**
     * \brief Equality comparison operator verifies if 2 CCopyArray objects contain the same data
     *
     * \return true if the objects contain the same data, false otherwise
     */
    bool operator==(const CCopyArray& argOther);
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

    using iterator = TObjArrayIteratorImpl<T>;
    using const_iterator = TObjArrayIteratorImpl<const T>;

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
    CCopyArrayData & TypedObject () const
    {
      return (CCopyArrayData &) Object ();
    };
  };
  /*
   *
   */
  template<typename T>
  CCopyArray<T>::CCopyArray ()
  {
  }
  /*
   *
   */
  template<typename T>
  inline CCopyArray<T>::CCopyArray ( const CCopyArray<T>& argOther )
    : CObjPtr ((CObjPtr &) argOther )
  {
  }
  /*
   *
   */
  template<typename T>
  inline CCopyArray<T>::CCopyArray ( CCopyArrayData* pData )
    : CObjPtr ((CObj*) pData )
  {
  }
  /*
   *
   */
  template<typename T>
  inline CCopyArray<T>::CCopyArray(CObj* pData)
    : CObjPtr(pData)
  {
  }
  /*
   *
   */
  template<typename T>
  CCopyArray<T>::~CCopyArray ()
  {
  }

}
#endif // _CCopyArray_h_

