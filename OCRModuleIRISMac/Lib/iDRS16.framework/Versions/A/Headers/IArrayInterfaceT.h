/**
 * \file IArrayInterfaceT.h
 * \brief Interface for IArrayInterfaceT class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _IArrayInterfaceT_h_
#define _IArrayInterfaceT_h_
 
#include <idrskrn.h>

namespace IDRS
{
  template <class TYPE>
  class IDRSKRN_API IArrayInterfaceT
  {
  public:
    /**
     * \return The count of elements in the array.
     */
    virtual IDRS_UINT GetCount() const = 0;
    /**
     * \pre uiIndex < GetCount ()
     *
     * \param uiIndex The index of the element to retrieve.
     *
     * \return The element at the given index.
     */
    virtual TYPE GetAt(const IDRS_UINT uiIndex) const = 0;
    /**
     * Replaces the element at the given index.
     *
     * \pre uiIndex < GetCount ()
     * \pre ! toSet.IsNull ()
     *
     * \param uiIndex The index of the element to replace.
     * \param toSet The element to place in the array.
     */
    virtual void SetAt(const IDRS_UINT uiIndex, const TYPE & toSet) = 0;
    /**
     * Adds the given element at the end of the array.
     *
     * \pre ! toAdd.IsNull ()
     *
     * \param toAdd The element to add.
     */
    virtual void AddTail(const TYPE & toAdd) = 0;
    /**
     * Inserts an element in the array.
     *
     * \pre uiIndex <= GetCount ()
     * \pre ! toInsert.IsNull ()
     *
     * \param uiIndex The index where to insert the element.
     * \param toInsert The element to insert.
     */
    virtual void InsertAt(const IDRS_UINT uiIndex, const TYPE & toInsert) = 0;
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
    virtual void RemoveAt(const IDRS_UINT uiFirstEltIndex, const IDRS_UINT uiCount = 1) = 0;
    /**
     * Removes all the elments from the array.
     *
     */
    virtual void RemoveAll() = 0;
  };
}
#endif // _IArrayInterfaceT_h_
