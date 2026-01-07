/**
 * \file CPolygonUtils.h
 * Interface for CPolygonUtils class.
 */

#ifndef _CPolygonUtils_h_
#define _CPolygonUtils_h_
#include <CObjPtr.h>
#include <CIDRS.h>
#include <CPolygon.h>

namespace IDRS
{
  /**
   * The CPolygonUtils class implements utilities to get information regarding polygons.
   *
   * It offers operations like:
   * - check whether or not a point is inside a polygon
   * - check whether or not a polygon is a rectangle
   * - check whether or not a rectangle and a polygon have an intersection
   * - check whether or not two polygons have an intersection
   */
  class IDRSKRN_API CPolygonUtils : public CObjPtr
  {
  public:
    /**
     * \brief ContainsPoint tests if a polygon contains the given point or not.
     *
     * \param argPolygon The polygon to test.
     * \param stPoint The point to test.
     *
     * \return IDRS_TRUE if the point is in the polygon, otherwise IDRS_FALSE
     */
    static IDRS_BOOL ContainsPoint(const CPolygon& argPolygon, const IDRS_POINT& stPoint);
    /**
     * \brief IsRectangle tests if a polygon is a rectangle or not.
     *
     * \param argPolygon The polygon to test.
     *
     * \return IDRS_TRUE if the provided polygon is rectangle, otherwise IDRS_FALSE
     */
    static IDRS_BOOL IsRectangle(const CPolygon& argPolygon);
    /**
     * \brief IntersectsRectangle tests if a polygon intersects the given rectangle or not.
     *
     * \pre CRectangle::IsValid ( rect )
     *
     * \param argPolygon The polygon to test.
     * \param argRectangle The rectangle to test.
     *
     * \return IDRS_TRUE if the provided polygon intersects the provided rectangle, otherwise IDRS_FALSE
     */
    static IDRS_BOOL IntersectsRectangle(const CPolygon& argPolygon, const IDRS_RECT& argRectangle);
    /**
     * \brief IntersectsPolygon tests if there's an intersection between the two given polygons.
     *
     * \param argPolygon1 The data of the first polygon to test.
     * \param argPolygon2 The data of the second polygon to test.
     *
     * \return IDRS_TRUE if an intersection exists, otherwise IDRS_FALSE
     */
    static IDRS_BOOL IntersectsPolygon(const CPolygon& argPolygon1, const CPolygon& argPolygon2);

  };
}

#endif /* _CPolygonUtils_h_ */