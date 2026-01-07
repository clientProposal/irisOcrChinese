/**
 * \file CPageZoneGraphic.h
 * \brief Interface for CPageZoneGraphic class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _CPageZoneGraphic_h_
#define _CPageZoneGraphic_h_
#include "CPageZone.h"

namespace IDRS
{
  class CPageZoneGraphicData;
  /**
   * \brief CPageZoneGraphic represents a graphic zone
   * 
   * The graphic zone can represent one of the following:
   *  - an area in the page underlying image. In this case the bounding box coordinates represent the coordinates in the page underlying image
   *  - a separate image loaded via a CImage object
   */
  class IDRSKRN_API CPageZoneGraphic : public CPageZone
  {
  public:
    /**
     * \brief Default constructor
     */
    inline CPageZoneGraphic();
    /**
     * \brief Copy constructor
     *
     * \param argPageZone Object to copy (shallow copy)
     */
    inline CPageZoneGraphic(const CPageZoneGraphic& argPageZone);
    /**
     * \brief Constructor using the base class
     *
     * \param argPageZone Base page zone 
     */
    inline CPageZoneGraphic(const CPageZone& argPageZone);
    /**
     * \brief CPageZoneGraphic constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageZoneGraphic(CPageZoneGraphicData * pObj);
    /**
     * \brief CPageZoneText constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageZoneGraphic(CObj * pObj);
    /**
     * \brief Destructor
     */
    inline virtual ~CPageZoneGraphic();
    /**
     * \brief Creates a new instance of CPageZoneGraphic
     */
    static CPageZoneGraphic Create();
    /**
     * \brief Retrieves the source type for the graphical zone.
     * 
     * The type can only be set by constructing the desired object type: CPageGraphic or CPageZoneGraphicExternalImage
     */
    PageZoneGraphicSource GetGraphicSourceType() const;

  private:
    //! Internal use 
    CPageZoneGraphicData & TypedObject() const
    {
      return (CPageZoneGraphicData &)Object();
    };
  };

  /*
   *
   */
  inline CPageZoneGraphic::CPageZoneGraphic()
  {
  }
  /*
   *
   */
  inline CPageZoneGraphic::CPageZoneGraphic(const CPageZoneGraphic& argPageZone)
    : CPageZone((CPageZone &)argPageZone)
  {
  }
  /*
   *
   */
  inline CPageZoneGraphic::CPageZoneGraphic(const CPageZone& argPageZone)
    : CPageZone(argPageZone)
  {
  }
  /*
   *
   */
  inline CPageZoneGraphic::CPageZoneGraphic(CPageZoneGraphicData * pObj)
    : CPageZone((CPageZoneData *)pObj)
  {
  }
  /*
   *
   */
  inline CPageZoneGraphic::CPageZoneGraphic(CObj * pObj)
    : CPageZone(pObj)
  {
  }
  /*
   *
   */
  inline CPageZoneGraphic::~CPageZoneGraphic()
  {
  }
}
#endif // _CPageZoneGraphic_h_
