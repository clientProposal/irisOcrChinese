/**
 * \file CPageZone.h
 * \brief Interface for CPageZone class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _CPageZone_h_
#define _CPageZone_h_

#include "TObjPtrArray.h"
#include "CPageCustomData.h"
#include <EnumDefinitions.h>
#include <StructDefinitions.h>

namespace IDRS
{
  class CPageZoneData;
  class CPolygon;
  /**
   * \brief Class CPageZone represents the base class for all zones available in iDRS SDK
   *
   * A zone contains the following entities:
   * - bounding polygon
   * - rotation angle
   * - skew angle
   * - text distances to surrounding zones
   * - zone context link id: useful for iDRS ocr zonal recognition using CMultiContext objects
   *
   * This class is a base class, so integrators are not expected to instantiate objects of this type.
   * 
   */
  class IDRSKRN_API CPageZone : public CPageCustomData
  {
  public:
    /**
     * \brief Default constructor
     */
    inline CPageZone();
    /**
     * \brief Copy constructor
     *
     * \param argPageZone Object to copy (shallow copy)
     */
    inline CPageZone(const CPageZone& argPageZone);
    /**
     * \brief CPageZone constructor that initializes an object with a data object
     * 
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageZone(CPageZoneData * pObj);
    /**
     * \brief CPageZone constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageZone(CObj * pObj);
    /**
     * \brief Destructor
     */
    inline virtual ~CPageZone();
    /**
     * \brief Creates an instance of CPageZone object with the data object pointing to the correct type of zone
     *
     * This method instantiates the following objects, based on the zone type:
     * - ZoneType::Text, ZoneType::Text: \see CPageZoneText CPageZoneText
     * - ZoneType::Table: \see CPageZoneTable CPageZoneTable
     * - ZoneType::Graphic: \see CPageZoneGraphic CPageZoneGraphic
     *
     * \param evZoneType Zone type
     *
     * \return CPageZone object with the data object pointing to the correct type of data class
     */
    static CPageZone Create(const ZoneType evZoneType);
    /**
     * \brief Creates an instance of CPageZone object with the data object pointing to the correct type of zone
     *
     * This method instantiates the following objects, based on the zone type:
     * - ZoneType::Text, ZoneType::Text: \see CPageZoneText CPageZoneText
     * - ZoneType::Table: \see CPageZoneTable CPageZoneTable
     * - ZoneType::Graphic: \see CPageZoneGraphic CPageZoneGraphic
     *
     * \param evZoneType Zone type
     * \param objBoundingPolygon Polygon where all elements withing the zone are located
     *
     * \return CPageZone object with the data object pointing to the correct type of data class
     */
    static CPageZone Create(const ZoneType evZoneType, CPolygon objBoundingPolygon);
    /**
     * \brief Get the zone type
     */
    ZoneType GetZoneType() const;
    /**
     * \brief Get the bounding polygon
     */
    CPolygon GetBoundingPolygon() const;
    /**
     * \brief Set the polygon containing all zone content
     *
     * \param argBoundingPolygon Polygon object
     */
    void SetBoundingPolygon(const CPolygon& argBoundingPolygon);
    /**
     * \brief Get the zone's padding information.
     *
     * Paragraph style's margins are expected to be computed relative to this rectangle.
     *
     * \return The padding box
     */
    PaddingInfo GetPadding() const;
    /**
     * \brief Set the zone's padding information.
     *
     * Paragraph style's margins are expected to be computed relative to this rectangle.
     *
     * \param stPaddingInfo The padding to set
     */
    void SetPadding( const PaddingInfo& stPaddingInfo);
    /**
     * \brief Get the text direction for the current zone
     *
     * \note Text direction is not useful for graphical zones
     *
     * The default value is IDRS::TextDirection::LeftToRight
     *
     * \return Text direction
     */
    TextDirection GetTextDirection() const;
    /**
     * \brief Set the text direction for the current zone
     *
     * \note Text direction is not useful for graphical zones
     *
     * The default value is IDRS::TextDirection::LeftToRight
     *
     * \param evTextDirection Text direction
     */
    void SetTextDirection(const TextDirection evTextDirection);
    /**
     * \brief Get the reading order of the zone 
     *
     * The ocr engine returns the zones in reading order. 
     * The reading order is considering the human reading order, based on the language used for OCR
     */
    IDRS_INT GetZoneOrder() const;
    /**
     * \brief Set the reading order to a zone.
     *
     * \param iZoneOrder Zone reading order
     */
    void SetZoneOrder(const IDRS_INT iZoneOrder);
  private:
    //! Internal use 
    CPageZoneData & TypedObject() const
    {
      return (CPageZoneData &)Object();
    };
  };

  typedef TObjPtrArray<CPageZone> CPageZoneArray;

  /*
   *
   */
  inline CPageZone::CPageZone()
  {
  }
  /*
   *
   */
  inline CPageZone::CPageZone(const CPageZone& argPageZone)
    : CPageCustomData((CPageCustomData&)argPageZone)
  {
  }
  /*
   *
   */
  inline CPageZone::CPageZone(CPageZoneData * pObj)
    : CPageCustomData((CPageCustomDataData*)pObj)
  {
  }
  /*
   *
   */
  inline CPageZone::CPageZone(CObj * pObj)
    : CPageCustomData(pObj)
  {
  }
  /*
   *
   */
  inline CPageZone::~CPageZone()
  {
  }
}
#endif // _CPageZone_h_
