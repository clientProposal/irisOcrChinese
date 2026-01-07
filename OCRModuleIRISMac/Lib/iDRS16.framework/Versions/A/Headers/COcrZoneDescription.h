/**
 * \file COcrZoneDescription.h
 * \brief Interface for COcrZoneDescription class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _COcrZoneDescription_h_
#define _COcrZoneDescription_h_

#include "CObjPtr.h"
#include "EnumDefinitions.h"
#include "CPolygon.h"
#include <TObjPtrArray.h>

namespace IDRS
{
  class COcrZoneDescriptionData;
  /**
   * \brief The class COcrZoneDescription contains the configuration for a single zone where text recognition will be executed.
   *
   * This class allows setting following options fo the zonal configuration for text recognition:
   * - zone coordinates, as a \see CPolygon
   * - type of zone expected to be recognized. See \see ZoneType for possible zone types.
   */
  class IDRSKRN_API COcrZoneDescription : public CObjPtr
  {
  public:
    /**
     * \brief Default constructor. 
     */
    inline COcrZoneDescription();
    /**
     * \brief Copy constructor. 
     * 
     * \param argCOcrZoneDescription Object to copy. 
     *
     * This method will initialize the newly created COcrZoneDescription with the data object from argCOcrZoneDescription parameter.
     */
    inline COcrZoneDescription(const COcrZoneDescription& argCOcrZoneDescription);
    /**
     * \brief Constructor that initializes the associated data object 
     * 
     * \param pargCOcrZoneDescriptionData Data object containing the state that will be used for the new COcrZoneDescription object
     */
    inline COcrZoneDescription(CObj* pargCOcrZoneDescriptionData);
    /**
     * \brief Destructor
     */
    inline virtual ~COcrZoneDescription();
    /**
     * \brief Creates a new instance of this class and initializes the created object with the default values:
     * - zone type will be set to \see TextType::Text
     * - polygon will be set to NULL
     */
    static COcrZoneDescription Create();
    /**
     * \brief Creates a new instance of this class and initializes the created object with the provided arguments.
     *
     * \param evZoneType Zone type
     * \param rcZone Rectangle defining the zone where the text recognition will be run
     */
    static COcrZoneDescription Create(const ZoneType evZoneType, const IDRS_RECT& rcZone);
    /**
     * \brief Creates a new instance of this class and initializes the created object with the provided arguments.
     *
     * \param evZoneType Zone type
     * \param argPolygon Polygon defining the zone where the text recognition will be run
     */
    static COcrZoneDescription Create(const ZoneType evZoneType, const CPolygon& argPolygon);
    /**
     * \brief Gets the zone type.
     * 
     * \return Zone type expected during text recognition 
     */
    ZoneType GetType() const;
    /**
     * \brief Sets the zone type.
     * 
     * \param evZoneType Zone type expected during text recognition 
     */
    void SetType(const ZoneType evZoneType);
    /**
     * \brief Gets the polygon defining the coordinates of the zone where text recognition will be executed.
     * 
     * Setting one or more coordinates outside the page/image bounds will trigger an exception during text recognition execution 
     *
     * \return Polygon object defining the coordinates of the zone where text recognition will be executed.
     */
    CPolygon GetZone() const;
    /**
     * \brief Sets the polygon defining the coordinates of the zone where text recognition will be executed.
     *
     * Setting one or more coordinates outside the page/image bounds will trigger an exception during text recognition execution 
     *
     * \param argZone Polygon object defining the coordinates of the zone where text recognition will be executed.
     */
    void SetZone(const CPolygon& argZone);
  private:
    // For internal use only
    COcrZoneDescriptionData& TypedObject() const
    {
      return (COcrZoneDescriptionData&)Object();
    };

  };

  typedef TObjPtrArray<COcrZoneDescription> COcrZoneDescriptionArray;
	
  /*
   *
   */
  inline COcrZoneDescription::COcrZoneDescription()
  {
  }
  /*
   *
   */
  inline COcrZoneDescription::COcrZoneDescription(const COcrZoneDescription& argCOcrZoneDescription)
    : CObjPtr((CObjPtr &)argCOcrZoneDescription)
  {
  }
  /*
   *
   */
  inline COcrZoneDescription::COcrZoneDescription(CObj* pargCOcrZoneDescriptionData)
    : CObjPtr(pargCOcrZoneDescriptionData)
  {
  }
  /*
   *
   */
  inline COcrZoneDescription::~COcrZoneDescription()
  {
  }
}
#endif // _COcrZoneDescription_h_
