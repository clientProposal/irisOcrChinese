/**
 * \file CPageZoneTable.h
 * \brief Interface for CPageZoneTable class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _CPageZoneTable_h_
#define _CPageZoneTable_h_
#include "CPageZone.h"
#include "CPageTableCell.h"
#include "TObjPtrArray.h"
 
namespace IDRS
{
  class CPageZoneTableData;

  /**
   * \brief CPageZoneTable represents a table zone in iDRS SDK
   */
  class IDRSKRN_API CPageZoneTable : public CPageZone
  {
  public:
    /**
     * \brief Default constructor
     */
    inline CPageZoneTable();
    /**
     * \brief Copy constructor
     *
     * \param argPageZone Object to copy (shallow copy)
     */
    inline CPageZoneTable(const CPageZoneTable& argPageZone);
    /**
     * \brief Constructor using the base class
     *
     * \param argPageZone Base page zone 
     */
    inline CPageZoneTable(const CPageZone& argPageZone);
    /**
     * \brief CPageZoneTable constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageZoneTable(CPageZoneTableData * pObj);
    /**
     * \brief CPageZoneGraphic constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageZoneTable(CObj * pObj);
    /**
     * \brief Destructor
     */
    inline virtual ~CPageZoneTable();
    /**
     * \brief Creates a new instance of CPageZoneTable
     */
    static CPageZoneTable Create();
    /**
     * \brief Returns the number of columns in the table
     */
    IDRS_INT GetColsCount() const;
    /**
     * \brief Returns the number of rows in the table
     */
    IDRS_INT GetRowsCount() const;
    /**
     * \brief Sets the number of columns in the table
     *
     * \param iColsCount Number of columns
     */
    void SetColsCount(const IDRS_INT iColsCount);
    /**
     * \brief Sets the number of rows in the table
     *
     * \param iRowsCount Number of rows
     */
    void SetRowsCount(const IDRS_INT iRowsCount);
    /**
     * \brief Retrieves the array of cells in the table
     */
    CPageTableCellArray GetCells() const;
    /**
     * \brief Sets an array containing the cells in the table
     *
     * \param argCells Array containing the cells in the table
     */
    void SetCells(const CPageTableCellArray& argCells);
  private:
    //! Internal use 
    CPageZoneTableData & TypedObject() const
    {
      return (CPageZoneTableData &)Object();
    };
  };

  /*
   *
   */
  inline CPageZoneTable::CPageZoneTable()
  {
  }
  /*
   *
   */
  inline CPageZoneTable::CPageZoneTable(const CPageZoneTable& argPageZone)
    : CPageZone((CPageZone &)argPageZone)
  {
  }
  /*
   *
   */
  inline CPageZoneTable::CPageZoneTable(const CPageZone& argPageZone)
    : CPageZone(argPageZone)
  {
  }
  /*
   *
   */
  inline CPageZoneTable::CPageZoneTable(CPageZoneTableData * pObj)
    : CPageZone((CPageZoneData *)pObj)
  {
  }
  /*
   *
   */
  inline CPageZoneTable::CPageZoneTable(CObj * pObj)
    : CPageZone(pObj)
  {
  }
  /*
   *
   */
  inline CPageZoneTable::~CPageZoneTable()
  {
  }
}
#endif // _CPageZoneTable_h_
