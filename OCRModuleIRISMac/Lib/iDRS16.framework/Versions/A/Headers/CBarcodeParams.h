/**
 * \file CBarcodeParams.h
 * \brief Interface for CBarcodeParams class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _CBarcodeParams_h_
#define _CBarcodeParams_h_

#include "CObjPtr.h"
#include "CBarcodeEngineConfig.h"
#include "EnumDefinitions.h"

namespace IDRS
{
  class CBarcodeParamsData;
  /**
   * \brief CBarcodeParams represents the base class for the barcode parameters containing the configuration for barcode detection.
   *
   * This class allows setting the following barcode detection options:
   * - Threading mode - use one or several threads for barcode detection
   * - The workdepth - enabling/disabling barcode engines (\see CBarcodeEngineConfig) 
   * - Barcode engines configuration
   * - Behavior when an exception occurs during barcode detection.
   */
  class IDRSKRN_API CBarcodeParams : public CObjPtr
  {
  public:
    /**
     * \brief Default constructor. 
     */
    inline CBarcodeParams();
    /**
     * \brief Copy constructor. 
     * 
     * \param argCBarcodeParams Object to copy. 
     *
     * This method will initialize the newly created CBarcodeParams with the data object from argCBarcodeParams parameter.
     */
    inline CBarcodeParams(const CBarcodeParams& argCBarcodeParams);
    /**
     * \brief Constructor that initializes the associated data object 
     * 
     * \param pargCBarcodeParamsData Data object containing the state that will be used for the new CBarcodeParams object
     */
    inline CBarcodeParams(CBarcodeParamsData* pargCBarcodeParamsData);
    /**
     * \brief Constructor that initializes the associated data object 
     * 
     * \param pObj Data object containing the state that will be used for the new CBarcodeParams
     */
    inline CBarcodeParams(CObj* pObj);
    /**
     * \brief Destructor
     */
    inline virtual ~CBarcodeParams();
    /**
     * \brief Gets the type of barcode detection - full page or zonal
     * 
     * The barcode detection is initialized automatically by the type of the instantiated object: \see CBarcodePageParams or \see CBarcodeZonalParams
     *
     * \return Barcode detection type
     */
    RecognitionType GetType() const;
    /**
     * \brief Gets the threading mode used for barcode detection
     * 
     * By default, the threading mode is set to \see ThreadingMode::Balanced
     *
     * \return Threading mode used for barcode detection
     */
    ThreadingMode GetThreadingMode() const;
    /**
     * \brief Sets the threading mode used for barcode detection
     * 
     * By default, the threading mode is set to \see ThreadingMode::Balanced
     * 
     * \param evThreadingMode Threading mode to set
     */
    void SetThreadingMode(const ThreadingMode evThreadingMode);
    /**
     * \brief Gets the work depth used for barcode detection
     * 
     * The work depth indicates how much time/processing the barcode engines can spend for barcode detection. See \see Workdepth for more details 
     *
     * By default, the work depth is set to \see Workdepth::Balanced
     *
     * \return Work depth used for barcode detection
     */
    Workdepth GetWorkdepth() const;
    /**
     * \brief Sets the work depth used for barcode detection
     * 
     * The work depth indicates how much time/processing the barcode engines can spend for barcode detection. See \see Workdepth for more details 
     *
     * By default, the work depth is set to \see Workdepth::Balanced
     *
     * \param evWorkdepth Work depth to be used for barcode detection
     */
    void SetWorkdepth(const Workdepth evWorkdepth);
    /**
     * \brief Gets the flag that indicates whether the barcode detection should raise an exception if an error occurrs in a barcode engine
     * 
     * During barcode processing it might happen that one or more engines will throw an exception. This setting determines the behavior of barcode processing code in such event.
     * If the setting is IDRS_TRUE, then the barcode detection process will throw an exception as soon as a barcode engine has raised an error
     * If the setting is IDRS_FALSE, then the barcode detection process will not throw an exception when a barcode engine raises an error and the barcode detection execution will continue.
     *
     * By default, the setting is IDRS_FALSE
     *
     * \return Boolean flag indicating whether the barcode detection should raise an exception when a barcode engine throwns an error.
     */
    IDRS_BOOL GetRaiseEngineErrors() const;
    /**
     * \brief Sets the flag that indicates whether the barcode detection should raise an exception if an error occurrs in a barcode engine
     * 
     * During barcode processing it might happen that one or more engines will throw an exception. This setting determines the behavior of barcode processing code in such event.
     * If the setting is IDRS_TRUE, then the barcode detection process will throw an exception as soon as a barcode engine has raised an error
     * If the setting is IDRS_FALSE, then the barcode detection process will not throw an exception when a barcode engine raises an error and the barcode detection execution will continue.
     *
     * By default, the setting is IDRS_FALSE
     *
     * \param bRaiseEngineErrors Boolean flag indicating whether the barcode detection should raise an exception when a barcode engine throwns an error.
     */
    void SetRaiseEngineErrors(const IDRS_BOOL bRaiseEngineErrors);
    /**
     * \brief Gets an array containing the barcode engine configurations. See \see CBarcodeEngineConfig for engine configurations.
     * 
     * During barcode detection, there might be one or more barcode engines that are used. The barcode engine configuration plays an important role whether a barcode engine will be run or not.
     *
     * The place in the barcode engine configuration will also set the barcode engine priorities. The barcode engine priority is an indirect setting that is taken into account during the following situations:
     * - sequential barcode engine execution, when threading mode is set to \see ThreadingMode::None. The barcode engines added first in the CBarcodeEngineConfigArray will be executed first.
     * - 2 or more barcode engines detect barcode(s) in the same place. The barcode that will be added to the results will be the one detected by the barcode engine with the highest priority (lower index in CBarcodeEngineConfigArray)
     *
     * By default, all the available barcode engines will be enabled. 
     *
     * \return Array containing the barcode engine configurations.
     */
    CBarcodeEngineConfigArray GetEngineConfigs() const;
    /**
     * \brief Sets an array containing the barcode engine configurations. See \see CBarcodeEngineConfig for engine configurations.
     * 
     * During barcode detection, there might be one or more barcode engines that are used. The barcode engine configuration plays an important role whether a barcode engine will be run or not.
     *
     * The place in the barcode engine configuration will also set the barcode engine priorities. The barcode engine priority is an indirect setting that is taken into account during the following situations:
     * - sequential barcode engine execution, when threading mode is set to \see ThreadingMode::None. The barcode engines added first in the CBarcodeEngineConfigArray will be executed first.
     * - 2 or more barcode engines detect barcode(s) in the same place. The barcode that will be added to the results will be the one detected by the barcode engine with the highest priority (lower index in CBarcodeEngineConfigArray)
     *
     * By default, all the available barcode engines will be enabled. 
     *
     * \param argxEngineConfigs Array containing the barcode engine configurations.
     */
    void SetEngineConfigs(CBarcodeEngineConfigArray& argxEngineConfigs);
  private:
    // For internal use only
    CBarcodeParamsData& TypedObject() const
    {
      return (CBarcodeParamsData&)Object();
    };
  };
	
  /*
   *
   */
  inline CBarcodeParams::CBarcodeParams()
  {
  }
  /*
   *
   */
  inline CBarcodeParams::CBarcodeParams(const CBarcodeParams& argCBarcodeParams)
    : CObjPtr((CObjPtr &)argCBarcodeParams)
  {
  }
  /*
   *
   */
  inline CBarcodeParams::CBarcodeParams(CBarcodeParamsData* pargCBarcodeParamsData)
    : CObjPtr((CObj *)pargCBarcodeParamsData)
  {
  }
  /*
   *
   */
  inline CBarcodeParams::CBarcodeParams(CObj* pObj)
    : CObjPtr(pObj)
  {
  }
  /*
   *
   */
  inline CBarcodeParams::~CBarcodeParams()
  {
  }
}
#endif // _CBarcodeParams_h_
