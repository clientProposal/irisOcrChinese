/**
 * \file CPolygon.h
 * \brief Interface for the IDRS::CPolygon class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _CPolygon_h_
#define _CPolygon_h_
#include <ArrayDefinitions.h>
#include <CObjPtr.h>
namespace IDRS
{
  class CPolygonData;
  /**
   * \brief The CPolygon class handles polygons for iDRS.
   * \ingroup module_core
   *
   * iDRS SDK uses polygons to describe zones in images.
   *
   * In iDRS, a polygon is defined by a list of points.
   */
  class IDRSKRN_API CPolygon : public CObjPtr
  {
    public:
      /**
       * \brief Default constructor.
       */
      inline CPolygon ();
      /**
       * \brief Copy constructor.
       *
       * \param argPolygon The smart pointer to copy.
       */
      inline CPolygon ( const CPolygon & argPolygon );
      /**
       * \brief Constructor.
       *
       * \param pPolygonData The object to point to.
       */
      inline CPolygon ( CObj * pPolygonData );
      /**
       * \brief Destructor
       */
      inline virtual ~CPolygon ();
      /**
       * \brief Creates a new polygon defined by the provided bounding box.
       *
       * \pre stBoundingBox.iTop < stBoundingBox.iBottom
       * \pre stBoundingBox.iLeft < stBoundingBox.iRight
       *
       * \param stBoundingRect The polygon's bounding rectangle (smallest rectangular area around the polygon).
       * 
       * \remarks The bounding rectangle is defined with borders top and left inclusive (i.e. they are part of the defined zone),
       * and borders bottom and right exclusive (i.e. they are not part of the defined zone).
       *
       * \remarks areas of one pixel width or height are forbidden.
       *
       * \return The newly created polygon.
       *
       * \throw CIDRSException if an error occur.
       */
      static CPolygon Create ( const IDRS_RECT & stBoundingRect );
      /**
       * \brief Creates a new polygon defined by the provided polyline.
       *
       * \pre ! xPoints ()
       * \pre xPoints.GetCount () >= 4
       *
       * \param xPoints The polyline defining the polygon's boundaries.
       *
       * \remarks The polyline's points are all considered included in the defined zone.
       *
       * \remarks The provided points array must conform to the following specifications:
       * - First point must be the top-most (and from the top-most points, the left-most one) of the defined zone
       * - Only horizontal and vertical segments are allowed, alternating each other (this limitation will be removed in a future release)
       * - The shape must be drawn counter-clockwise (therefore the second point must be below the first one)
       * - The polyline must not be explicitely closed (i.e. the last point must not be the same than the first)
       *
       * \remarks areas of one pixel width or height are forbidden.
       *
       * \return The newly created polygon.
       *
       * \throw CIDRSException if an error occur.
       */
      static CPolygon Create ( const PointArray & xPoints );
      /**
       *
       * \pre ! IsNull ()
       *
       * \return The bounding rectangle of the polygon.
       */
      IDRS_RECT GetBoundingBox () const;
      /**
       * \brief Retrieves the polyline defining the polygon.
       *
       * \return The polyline defining the polygon.
       */
      PointArray GetPoints() const;
      /**
       * \brief Sets the polyline defining the polygon.
       *
       * \param xPoints The polyline defining the polygon.
       */
      void SetPoints(const PointArray& xPoints);
    private:
      // For internal use only
      CPolygonData & TypedObject () const
      {
        return ( CPolygonData & )Object ();
      };
  };

  typedef TObjPtrArray<CPolygon> CPolygonArray;

  /*
   *
   */
  inline CPolygon::CPolygon ()
  {
  }
  /*
   *
   */
  inline CPolygon::CPolygon ( const CPolygon & argPolygon )
    : CObjPtr (( CObjPtr & )argPolygon )
  {
  }
  /*
   *
   */
  inline CPolygon::CPolygon ( CObj * pPolygonData )
    : CObjPtr (pPolygonData )
  {
  }
  /*
   *
   */
  inline CPolygon::~CPolygon ()
  {
  }
} // namespace
#endif /* _CPolygon_h_ */
