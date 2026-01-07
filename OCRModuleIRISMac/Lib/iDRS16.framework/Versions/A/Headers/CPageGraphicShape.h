/**
 * \file CPageGraphicShape.h
 * \brief Interface for CPageGraphicShape class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _CPageGraphicShape_h_
#define _CPageGraphicShape_h_

#include "CPolygon.h"
#include "TObjPtrArray.h"
#include "CPageCustomData.h"
#include "EnumDefinitions.h"
 
namespace IDRS
{
  class CPageGraphicShapeData;

  /**
   * \brief CPageGraphicShape represents the base class for graphic shapes that can be represented in iDRS SDK
   *
   * This class is a base class, so integrators are not expected to instantiate objects of this type.
   */
  class IDRSKRN_API CPageGraphicShape : public CPageCustomData
  {
  public:
    /**
     * \brief Default constructor
     */
    inline CPageGraphicShape();
    /**
     * \brief Copy constructor
     *
     * \param argPageGraphicShape Object to copy (shallow copy)
     */
    inline CPageGraphicShape(const CPageGraphicShape& argPageGraphicShape);
    /**
     * \brief CPageGraphicShape constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageGraphicShape(CObj * pObj);
    /**
     * \brief CPageZone constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageGraphicShape(CPageGraphicShapeData * pObj);
    /**
     * \brief Destructor
     */
    inline virtual ~CPageGraphicShape();
    /**
     * \brief Returns the type of graphic shape associated to this object
     *
     * \internal
     * property GraphicShapeTypeValue/Get
     * \endinternal
     */
    GraphicShapeType GetGraphicShapeType() const;
    /**
     * \brief Retrieves the bounding box of the graphic shape.
     *
     * \return the bounding box of the graphic shape.
     */
    virtual IDRS_RECT GetBoundingBox() const;    
  private:
    //! Internal use 
    CPageGraphicShapeData & TypedObject() const
    {
      return (CPageGraphicShapeData &)Object();
    };
  };
  //! Array of CPageGraphicShape elements
  typedef TObjPtrArray<CPageGraphicShape> CPageGraphicShapeArray;
  /*
   *
   */
  inline CPageGraphicShape::CPageGraphicShape()
  {
  }
  /*
   *
   */
  inline CPageGraphicShape::CPageGraphicShape(const CPageGraphicShape& argPageGraphicShape)
    : CPageCustomData((CPageCustomData&)argPageGraphicShape)
  {
  }
  /*
   *
   */
  inline CPageGraphicShape::CPageGraphicShape(CPageGraphicShapeData * pObj)
    : CPageCustomData((CPageCustomDataData*)pObj)
  {
  }
  /*
   *
   */
  inline CPageGraphicShape::CPageGraphicShape(CObj * pObj)
    : CPageCustomData(pObj)
  {
  }
  /*
   *
   */
  inline CPageGraphicShape::~CPageGraphicShape()
  {
  }

}
#endif // _CPageGraphicShape_h_
