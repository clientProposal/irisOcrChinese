/**
 * \file CPageStyleTableCell.h
 * \brief Interface for CPageStyleTableCell class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _CPageStyleTableCell_h_
#define _CPageStyleTableCell_h_
 
#include "CObjPtr.h"
#include "CPageStyleFont.h"
#include "TObjPtrArray.h"

namespace IDRS
{
  class CPageStyleTableCellData;
  /**
   * \brief CPageStyleTableCell contains the style information associated to a table cell.
   *
   * The class holds the following information:
   * - horizontal & vertical alignment
   * - padding
   * - borders (present, color, width)
   * - font
   */
  class IDRSKRN_API CPageStyleTableCell : public CObjPtr
  {
  public:
    /**
     * \brief Default constructor
     */
    inline CPageStyleTableCell();
    /**
     * \brief Copy constructor
     *
     * \param argPageStyleTableCell Object to copy (shallow copy)
     */
    inline CPageStyleTableCell(const CPageStyleTableCell& argPageStyleTableCell);
    /**
     * \brief CPageStyleTableCell constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageStyleTableCell(CPageStyleTableCellData * pObj);
    /**
     * \brief CPageStyleTableCell constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageStyleTableCell(CObj * pObj);
    /**
     * \brief Destructor
     */
    inline virtual ~CPageStyleTableCell();
    /**
     * \brief Creates a new instance of CPageStyleTableCell
     */
    static CPageStyleTableCell Create();
    /**
     * \brief Retrieves the horizontal alignment for the cell text 
     */
    HorizontalAlignment GetHorizontalAlignment() const;
    /**
     * \brief Retrieves the vertical for the cell text
     */
    VerticalAlignment GetVerticalAlignment() const;
    /**
     * \brief Retrieves the left padding, in pixels
     */
    IDRS_INT GetLeftPadding() const;
    /**
     * \brief Retrieves the right padding, in pixels
     */
    IDRS_INT GetRightPadding() const;
    /**
     * \brief Retrieves the boolean flag indicating that the cell has a top border
     */
    IDRS_BOOL GetTopBorder() const;
    /**
     * \brief Retrieves the boolean flag indicating that the cell has a left border
     */
    IDRS_BOOL GetLeftBorder() const;
    /**
     * \brief Retrieves the boolean flag indicating that the cell has a bottom border
     */
    IDRS_BOOL GetBottomBorder() const;
    /**
     * \brief Retrieves the boolean flag indicating that the cell has a right border
     */
    IDRS_BOOL GetRightBorder() const;
    /**
     * \brief Retrieves the cell background color
     */
    IDRS_COLOR GetBackgroundColor() const;
    /**
     * \brief Retrieves the color for the cell top border
     */
    IDRS_COLOR GetTopBorderColor() const;
    /**
     * \brief Retrieves the color for the cell left border
     */
    IDRS_COLOR GetLeftBorderColor() const;
    /**
     * \brief Retrieves the color for the cell bottom border
     */
    IDRS_COLOR GetBottomBorderColor() const;
    /**
     * \brief Retrieves the color for the cell right border
     */
    IDRS_COLOR GetRightBorderColor() const;
    /**
     * \brief Retrieves the width in pixels for the cell top border
     */
    IDRS_INT GetTopBorderWidth() const;
    /**
     * \brief Retrieves the width in pixels for the cell left border
     */
    IDRS_INT GetLeftBorderWidth() const;
    /**
     * \brief Retrieves the width in pixels for the cell bottom border
     */
    IDRS_INT GetBottomBorderWidth() const;
    /**
     * \brief Retrieves the width in pixels for the cell right border
     */
    IDRS_INT GetRightBorderWidth() const;
    /**
     * \brief Retrieves the font style associated to this cell style
     */
    CPageStyleFont GetFontStyle() const;
    /**
     * \brief Sets the horizontal alignment for the text in the cell
     *
     * \param evHorizontalAlignment Horizontal alignment value
     */
    void SetHorizontalAlignment(const HorizontalAlignment evHorizontalAlignment);
    /**
     * \brief Sets the vertical alignment for the text in the cell
     *
     * \param evVerticalAlignment Vertical alignment value
     */
    void SetVerticalAlignment(const VerticalAlignment evVerticalAlignment);
    /**
     * \brief Sets the left padding value
     *
     * \param iLeftPadding Left padding value
     */
    void SetLeftPadding(const IDRS_INT iLeftPadding);
    /**
     * \brief Sets the right padding value
     *
     * \param iRightPadding Right padding value
     */
    void SetRightPadding(const IDRS_INT iRightPadding);
    /**
     * \brief Sets a flag indicating that the style contains a top border
     *
     * \param bTopBorder Flag indicating whether a top border is present or not
     */
    void SetTopBorder(const IDRS_BOOL bTopBorder);
    /**
     * \brief Sets a flag indicating that the style contains a left border
     *
     * \param bLeftBorder Flag indicating whether a left border is present or not
     */
    void SetLeftBorder(const IDRS_BOOL bLeftBorder);
    /**
     * \brief Sets a flag indicating that the style contains a bottom border
     *
     * \param bBottomBorder Flag indicating whether a bottom border is present or not
     */
    void SetBottomBorder(const IDRS_BOOL bBottomBorder);
    /**
     * \brief Sets a flag indicating that the style contains a right border
     *
     * \param bRightBorder Flag indicating whether a right border is present or not
     */
    void SetRightBorder(const IDRS_BOOL bRightBorder);
    /**
     * \brief Sets the cell style background color
     *
     * \param stColorValue Background color
     */
    void SetBackgroundColor(const IDRS_COLOR & stColorValue);
    /**
     * \brief Sets the color for the top border
     *
     * \param stColorValue Top border color value (RGB)
     */
    void SetTopBorderColor(const IDRS_COLOR & stColorValue);
    /**
     * \brief Sets the color for the top border
     *
     * \param stColorValue Left border color value (RGB)
     */
    void SetLeftBorderColor(const IDRS_COLOR & stColorValue);
    /**
     * \brief Sets the color for the bottom border
     *
     * \param stColorValue Bottom border color value (RGB)
     */
    void SetBottomBorderColor(const IDRS_COLOR & stColorValue);
    /**
     * \brief Sets the color for the right border
     *
     * \param stColorValue Right border color value (RGB)
     */
    void SetRightBorderColor(const IDRS_COLOR & stColorValue);
    /**
     * \brief Sets the width for the top border (in pixels)
     *
     * \param iTopBorderWidth Top border width (in pixels)
     */
    void SetTopBorderWidth(const IDRS_INT iTopBorderWidth);
    /**
     * \brief Sets the width for the left border (in pixels)
     *
     * \param iLeftBorderWidth Left border width (in pixels)
     */
    void SetLeftBorderWidth(const IDRS_INT iLeftBorderWidth);
    /**
     * \brief Sets the width for the bottom border (in pixels)
     *
     * \param iBottomBorderWidth Bottom border width (in pixels)
     */
    void SetBottomBorderWidth(const IDRS_INT iBottomBorderWidth);
    /**
     * \brief Sets the width for the right border (in pixels)
     *
     * \param iRightBorderWidth Right border width (in pixels)
     */
    void SetRightBorderWidth(const IDRS_INT iRightBorderWidth);
    /**
     * \brief Sets the font style associated to the cell style
     *
     * \param argPageStyleFontSize Font style
     */
    void SetFontStyle(const CPageStyleFont& argPageStyleFontSize);

  private:
    //! Internal use 
    CPageStyleTableCellData & TypedObject() const
    {
      return (CPageStyleTableCellData &)Object();
    };

  };
  typedef TObjPtrArray<CPageStyleTableCell> CPageStyleTableCellArray;

  /*
   *
   */
  inline CPageStyleTableCell::CPageStyleTableCell()
  {
  }
  /*
   *
   */
  inline CPageStyleTableCell::CPageStyleTableCell(const CPageStyleTableCell& argPageStyleTableCell)
    : CObjPtr((CObjPtr &)argPageStyleTableCell)
  {
  }
  /*
   *
   */
  inline CPageStyleTableCell::CPageStyleTableCell(CPageStyleTableCellData * pObj)
    : CObjPtr((CObj *)pObj)
  {
  }
  /*
   *
   */
  inline CPageStyleTableCell::CPageStyleTableCell(CObj * pObj)
    : CObjPtr(pObj)
  {
  }
  /*
   *
   */
  inline CPageStyleTableCell::~CPageStyleTableCell()
  {
  }
}

#endif // _CPageStyleTableCell_h_
