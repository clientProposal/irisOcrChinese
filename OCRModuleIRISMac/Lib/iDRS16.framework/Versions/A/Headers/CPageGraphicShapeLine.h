/**
 * \file CPageGraphicShapeLine.h
 * \brief Interface for CPageGraphicShapeLine class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _CPageGraphicShapeLine_h_
#define _CPageGraphicShapeLine_h_

#include "CPageGraphicShape.h"
 
namespace IDRS
{
  class CPageGraphicShapeLineData;

  /**
   * \brief CPageGraphicShapeLine represents a line graphic shape
   */
  class IDRSKRN_API CPageGraphicShapeLine : public CPageGraphicShape
  {
  public:
    /**
     * \brief Default constructor
     */
    inline CPageGraphicShapeLine();
    /**
     * \brief Copy constructor
     *
     * \param argPageGraphicShape Object to copy (shallow copy)
     */
    inline CPageGraphicShapeLine(const CPageGraphicShapeLine& argPageGraphicShape);
    /**
     * \brief Copy constructor
     *
     * \param argPageGraphicShape Object to copy (shallow copy)
     */
    inline CPageGraphicShapeLine(const CPageGraphicShape& argPageGraphicShape);
    /**
     * \brief CPageGraphicShape constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageGraphicShapeLine(CPageGraphicShapeLineData* pObj);
    /**
     * \brief CPageGraphicShape constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageGraphicShapeLine(CObj* pObj);
    /**
     * \brief Destructor
     */
    inline virtual ~CPageGraphicShapeLine();
    /**
     * \brief Creates a new instance of a CPageGraphicShapeLine object
     */
    static CPageGraphicShapeLine Create();
    /**
     * \brief Sets the width of the line
     *
     * \param uiValue Line width
     */
    void SetLineWidth(const IDRS_UINT uiValue);
    /**
     * \brief Retrieves the line width
     *
     * \return the line width
     */
    IDRS_UINT GetLineWidth() const;
    /**
     * \brief Sets the color used to draw the line
     *
     * \param stColor Color used to draw the line
     */
    void SetDrawingColor(const IDRS_COLOR & stColor);
    /**
     * \brief Returns the color used to draw the line
     *
     * \return the drawing color
     */
    IDRS_COLOR GetDrawingColor() const;
    /**
     * \brief Sets the first point of the line
     *
     * \remarks The iDRS document output engine only handles horizontal or vertical lines at the moment. If the points are not aligned
     * on X or Y axis, an exception will be thrown when creating the output document.
     *
     * \param stPoint The point to set
     */
    void SetPoint1(const IDRS_POINT & stPoint);
    /**
     * \brief Returns the first point of the line
     *
     * \return The first point
     */
    IDRS_POINT GetPoint1() const;
    /**
     * \brief Sets the second point of the line
     *
     * \remarks The iDRS document output engine only handles horizontal or vertical lines at the moment. If the points are not aligned
     * on X or Y axis, an exception will be thrown when creating the output document.
     *
     * \param stPoint The point to set
     */
    void SetPoint2(const IDRS_POINT& stPoint);
    /**
     * \brief Returns the second point of the line
     *
     * \return The second point
     */
    IDRS_POINT GetPoint2() const;
  private:
    //! Internal use 
    CPageGraphicShapeLineData & TypedObject() const
    {
      return (CPageGraphicShapeLineData &)Object();
    };
  };

  /*
   *
   */
  inline CPageGraphicShapeLine::CPageGraphicShapeLine()
  {
  }
  /*
   *
   */
  inline CPageGraphicShapeLine::CPageGraphicShapeLine(const CPageGraphicShapeLine& argPageGraphicShape)
    : CPageGraphicShape((CPageGraphicShape &)argPageGraphicShape)
  {
  }
  /*
   *
   */
  inline CPageGraphicShapeLine::CPageGraphicShapeLine(const CPageGraphicShape& argPageGraphicShape)
    : CPageGraphicShape(argPageGraphicShape)
  {
  }
  /*
   *
   */
  inline CPageGraphicShapeLine::CPageGraphicShapeLine(CPageGraphicShapeLineData * pObj)
    : CPageGraphicShape((CPageGraphicShapeData *)pObj)
  {
  }
  /*
   *
   */
  inline CPageGraphicShapeLine::CPageGraphicShapeLine(CObj * pObj)
    : CPageGraphicShape(pObj)
  {
  }
  /*
   *
   */
  inline CPageGraphicShapeLine::~CPageGraphicShapeLine()
  {
  }

}
#endif // _CPageGraphicShapeLine_h_
