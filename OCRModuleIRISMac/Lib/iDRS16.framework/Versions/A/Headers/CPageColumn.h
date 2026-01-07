/**
 * \file CPageColumn.h
 * \brief Interface for CPageColumn class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _CPageColumn_h_
#define _CPageColumn_h_
 
#include "TObjPtrArray.h"
#include "CPageZone.h"
#include "CPageCustomData.h"

namespace IDRS
{
  class CPageColumnData;
  /**
   * \brief CPageColumn represents a column in a page section.
   */
  class IDRSKRN_API CPageColumn : public CPageCustomData
  {
  public:
    /**
     * \brief Default constructor
     */
    inline CPageColumn();
    /**
     * \brief Copy constructor
     *
     * \param argPageColumn Object to copy (shallow copy)
     */
    inline CPageColumn(const CPageColumn& argPageColumn);
    /**
     * \brief CPageColumn constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageColumn(CPageColumnData * pObj);
    /**
     * \brief CPageColumn constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageColumn(CObj * pObj);
    /**
     * \brief Destructor
     */
    inline virtual ~CPageColumn();
    /**
     * \brief Instantiates a new CPageColumn object
     */
    static CPageColumn Create();
    /**
     * \brief Gets the rectangle containing the column.
     *
     * \return the rectangle containing the column.
     */
    IDRS_RECT GetBoundingBox() const;
    /**
     * \brief Sets the coordinates for the bounding rectangle.
     *
     * \param rcBoundingBox Bounding rectangle
     */
    void SetBoundingBox(const IDRS_RECT& rcBoundingBox);
    /**
     * \brief Gets an array containing the zones in the column.
     *
     * \return an array containing the zones in the column.
     */
    CPageZoneArray GetZones() const;
    /**
     * \brief Sets the zones in the column.
     *
     * \important The zone coordinates need to be included in the column bounding box
     *
     * \param xZones List of zones 
     */
    void SetZones(const CPageZoneArray& xZones);

  private:
    //! Internal use 
    CPageColumnData & TypedObject() const
    {
      return (CPageColumnData &)Object();
    };
  };

  typedef TObjPtrArray<CPageColumn> CPageColumnArray;

  /*
   *
   */
  inline CPageColumn::CPageColumn()
  {
  }
  /*
   *
   */
  inline CPageColumn::CPageColumn(const CPageColumn& argPageColumn)
    : CPageCustomData((CPageCustomData&)argPageColumn)
  {
  }
  /*
   *
   */
  inline CPageColumn::CPageColumn(CPageColumnData * pObj)
    : CPageCustomData((CPageCustomDataData*)pObj)
  {
  }  
  /*
   *
   */
  inline CPageColumn::CPageColumn(CObj * pObj)
    : CPageCustomData(pObj)
  {
  }
  /*
   *
   */
  inline CPageColumn::~CPageColumn()
  {
  }
}
#endif // _CPageColumn_h_
