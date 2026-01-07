/**
 * \file CPageTableCell.h
 * \brief Interface for CPageTableCell class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _CPageTableCell_h_
#define _CPageTableCell_h_
 
#include "CPageStyleTableCell.h"
#include "TObjPtrArray.h"
#include "CPageTextLine.h"
#include "CPageCustomData.h"

namespace IDRS
{
  class CPageTableCellData;
  /**
   * \brief CPageTableCell represents a table cell. It contains the following information:
   * - row & column indexes
   * - row & column spans
   * - cell style
   * - inner text lines
   */
  class IDRSKRN_API CPageTableCell : public CPageCustomData
  {
  public:
    /**
     * \brief Default constructor
     */
    inline CPageTableCell();
    /**
     * \brief Copy constructor
     *
     * \param argPageTableCell Object to copy (shallow copy)
     */
    inline CPageTableCell(const CPageTableCell& argPageTableCell);
    /**
     * \brief CPageTableCell constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageTableCell(CPageTableCellData * pObj);
    /**
     * \brief CPageTableCell constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageTableCell(CObj * pObj);
    /**
     * \brief Destructor
     */
    inline virtual ~CPageTableCell();
    /**
     * \brief Instantiates a new CPageTableCell object
     */
    static CPageTableCell Create();
    /**
     * \brief Get the rectangle containing the column
     */
    IDRS_RECT GetBoundingBox() const;
    /**
     * \brief Get the row index
     */
    IDRS_INT GetRowIndex() const;
    /**
     * \brief Get the column index
     */
    IDRS_INT GetColIndex() const;
    /**
     * \brief Get the rows span
     */
    IDRS_INT GetRowSpan() const;
    /**
     * \brief Get the columns span
     */
    IDRS_INT GetColSpan() const;
    /**
     * \brief Get the cell style
     */
    CPageStyleTableCell GetCellStyle() const;
    /**
     * \brief Get the array containing text lines
     */
    CPageTextLineArray GetTextLines() const;
    /**
     * \brief Set the coordinates for the bounding rectangle
     *
     * \param rcBoundingBox Bounding rectangle
     */
    void SetBoundingBox(const IDRS_RECT& rcBoundingBox);
    /**
     * \brief Set the cell row index
     *
     * \param iRowIndex 0 based row index
     */
    void SetRowIndex(const IDRS_INT iRowIndex);
    /**
     * \brief Set the cell column index
     *
     * \param iColIndex 0 based column index
     */
    void SetColIndex(const IDRS_INT iColIndex);
    /**
     * \brief Set the rows span for the cell
     *
     * \param iRowSpan Rows span value
     */
    void SetRowSpan(const IDRS_INT iRowSpan);
    /**
     * \brief Set the cols span for the cell
     *
     * \param iColSpan Columns span value
     */
    void SetColSpan(const IDRS_INT iColSpan);
    /**
     * \brief Set the style associated to the table cell
     *
     * \param argPageStyleTableCell Object containing the style associated to the cell
     */
    void SetCellStyle(const CPageStyleTableCell& argPageStyleTableCell);
    /**
     * \brief Set the array containing the lines of text in the cell
     *
     * \param argTextLines Array containing the lines of text in the cell
     */
    void SetTextLines(const CPageTextLineArray& argTextLines);
  private:
    //! Internal use 
    CPageTableCellData & TypedObject() const
    {
      return (CPageTableCellData &)Object();
    };
  };

  typedef TObjPtrArray<CPageTableCell> CPageTableCellArray;

  /*
   *
   */
  inline CPageTableCell::CPageTableCell()
  {
  }
  /*
   *
   */
  inline CPageTableCell::CPageTableCell(const CPageTableCell& argPageTableCell)
    : CPageCustomData((CPageCustomData&)argPageTableCell)
  {
  }
  /*
   *
   */
  inline CPageTableCell::CPageTableCell(CPageTableCellData * pObj)
    : CPageCustomData((CPageCustomDataData*)pObj)
  {
  }
  /*
   *
   */
  inline CPageTableCell::CPageTableCell(CObj * pObj)
    : CPageCustomData(pObj)
  {
  }  
  /*
   *
   */
  inline CPageTableCell::~CPageTableCell()
  {
  }
}
#endif // _CPageTableCell_h_
