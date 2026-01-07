/**
 * \file COcrZonalParams.h
 * \brief Interface for COcrZonalParams class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _COcrZonalParams_h_
#define _COcrZonalParams_h_

#include "CObjPtr.h"
#include "COcrParams.h"
#include "COcrZonalSettings.h"

namespace IDRS
{
  class COcrZonalParamsData;
  /**
   * \brief The class COcrZonalParams contains the ocr parameters for zonal recognition
   */
  class IDRSKRN_API COcrZonalParams : public COcrParams
  {
  public:
    /**
     * \brief Default constructor
     */
    inline COcrZonalParams();
    /**
     * \brief Copy constructor
     */
    inline COcrZonalParams(const COcrZonalParams& argCZonalOcrParams);
    /**
     * \brief Constructor that initializes the data class
     */
    inline COcrZonalParams(CObj* pargCZonalOcrParamsData);
    /**
     * \brief Destructor
     */
    inline virtual ~COcrZonalParams();
    /**
     * \brief Creates a new instance of COcrZonalParams object and initializes the data object with default values.
     */
    static COcrZonalParams Create();
    /**
     * \brief GetZonalSettings retrieves an array of objects which contains the settings to be used during the OCR process. See \see COcrZonalSettings
     *
     * \return Array of \see COcrZonalSettings objects
     */
    COcrZonalSettingsArray GetZonalSettings() const;
    /**
     * \brief SetZonalSettings sets the settings for the zones
     *
     * \param argZonalSettings Settings for ocr zonal settings
     */
    void SetZonalSettings(const COcrZonalSettingsArray& argZonalSettings);

  private:
    // For internal use only
    COcrZonalParamsData& TypedObject() const
    {
      return (COcrZonalParamsData&)Object();
    };

  };
	
  /*
   *
   */
  inline COcrZonalParams::COcrZonalParams()
  {
  }
  /*
   *
   */
  inline COcrZonalParams::COcrZonalParams(const COcrZonalParams& argCZonalOcrParams)
    : COcrParams((COcrParams&)argCZonalOcrParams)
  {
  }
  /*
   *
   */
  inline COcrZonalParams::COcrZonalParams(CObj* pargCZonalOcrParamsData)
    : COcrParams(pargCZonalOcrParamsData)
  {
  }
  /*
   *
   */
  inline COcrZonalParams::~COcrZonalParams()
  {
  }
}
#endif // _COcrZonalParams_h_
