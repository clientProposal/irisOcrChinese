/**
 * \file CBarcodeZonalParams.h
 * \brief Interface for CBarcodeZonalParams class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _CBarcodeZonalParams_h_
#define _CBarcodeZonalParams_h_

#include "CBarcodeZonalSettings.h"
#include "CBarcodeParams.h"

namespace IDRS
{
  class CBarcodeZonalParamsData;
  /**
   * \brief CBarcodeZonalParams contains the configuration for zonal barcode detection. 
   *
   * This class allows setting the zonal configuration for barcode detection.
   */
  class IDRSKRN_API CBarcodeZonalParams : public CBarcodeParams
  {
  public:
    /**
     * \brief Default constructor. 
     */
    inline CBarcodeZonalParams();
    /**
     * \brief Copy constructor. 
     * 
     * \param argCZonalBarcodeParams Object to copy. 
     *
     * This method will initialize the newly created CBarcodeZonalParams with the data object from argCZonalBarcodeParams parameter.
     */
    inline CBarcodeZonalParams(const CBarcodeZonalParams& argCZonalBarcodeParams);
    /**
     * \brief Constructor that initializes the associated data object 
     * 
     * \param pargCZonalBarcodeParamsData Data object containing the state that will be used for the new CBarcodeZonalParams object
     */
    inline CBarcodeZonalParams(CBarcodeZonalParamsData* pargCZonalBarcodeParamsData);
    /**
     * \brief Constructor that initializes the associated data object 
     * 
     * \param pObj Data object containing the state that will be used for the new CBarcodeZonalParams
     */
    inline CBarcodeZonalParams(CObj* pObj);
    /**
     * \brief Destructor
     */
    inline virtual ~CBarcodeZonalParams();
    /**
     * \brief Creates a new instance of this class
     */
    static CBarcodeZonalParams Create();
    /**
     * \brief Gets the configuration for the zones where the barcode detection will be executed
     *
     * The barcode detection will run all enabled barcode engines on the specified zones
     *
     * By default, there will be no zone added to the zones array
     * 
     * \return Array containing the configuration for the zones where detection will be run
     */
    CBarcodeZonalSettingsArray GetZonalSettings() const;
    /**
     * \brief Sets the configuration for the zones where the barcode detection will be executed
     *
     * The barcode detection will run all enabled barcode engines on the specified zones
     * 
     * By default, there will be no zone added to the zones array
     * 
     * \param argxZonalSettings Array containing the configuration for the zones where detection will be run
     */
    void SetZonalSettings(const CBarcodeZonalSettingsArray& argxZonalSettings);
  private:
    // For internal use only
    CBarcodeZonalParamsData& TypedObject() const
    {
      return (CBarcodeZonalParamsData&)Object();
    };
  };
	
  /*
   *
   */
  inline CBarcodeZonalParams::CBarcodeZonalParams()
  {
  }
  /*
   *
   */
  inline CBarcodeZonalParams::CBarcodeZonalParams(const CBarcodeZonalParams& argCZonalBarcodeParams)
    : CBarcodeParams((CBarcodeParams&)argCZonalBarcodeParams)
  {
  }
  /*
   *
   */
  inline CBarcodeZonalParams::CBarcodeZonalParams(CBarcodeZonalParamsData* pargCZonalBarcodeParamsData)
    : CBarcodeParams((CObj *)pargCZonalBarcodeParamsData)
  {
  }
  /*
   *
   */
  inline CBarcodeZonalParams::CBarcodeZonalParams(CObj* pObj)
    : CBarcodeParams(pObj)
  {
  }
  /*
   *
   */
  inline CBarcodeZonalParams::~CBarcodeZonalParams()
  {
  }
}
#endif // _CBarcodeZonalParams_h_
