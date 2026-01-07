/**
 * \file CBarcodeEngineConfig.h
 * \brief Interface for CBarcodeEngineConfig class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _CBarcodeEngineConfig_h_
#define _CBarcodeEngineConfig_h_

#include "CObjPtr.h"
#include <TObjPtrArray.h>
#include "EnumDefinitions.h"
#include "CBarcodeValidationCriteria.h"
#include "IBarcodeEnginePreprocess.h"
#include "IBarcodeEnginePostprocess.h"
#include "CBarcodeSpecificOptions.h"

namespace IDRS
{
  class CBarcodeEngineConfigData;
  class IBarcodeEngine;
  /**
   * \brief CBarcodeEngineConfig contains the configuration for a barcode engine.
   *
   * This class allows the barcode engines to define the following characteristics:
   * - Associated barcode engine
   * - Enable/disable the barcode engine
   * - The operational workdepth for the barcode engine
   * - Barcode results validation criteria
   * - Preprocessing operations: operations that can be applied to the input images before barcode recognition
   * - Barcode results postprocessing operations - operations that can be performed on the recognized barcodes
   * - Barcode processing timeout
   * - Specific options related to barcode types
   *
   * Adding a new instance of this class to the barcode parameters will cause the barcode recognition process to call the supplied barcode engine with the parameters defined in this class.
   */
  class IDRSKRN_API CBarcodeEngineConfig : public CObjPtr
  {
  public:
    /**
     * \brief Default constructor. 
     */
    inline CBarcodeEngineConfig();
    /**
     * \brief Copy constructor. 
     * 
     * \param argCBarcodeEngineConfig Object to copy. 
     *
     * This method will initialize the newly created CBarcodeEngineConfig with the data object from argCBarcodeEngineConfig parameter.
     */
    inline CBarcodeEngineConfig(const CBarcodeEngineConfig& argCBarcodeEngineConfig);
    /**
     * \brief Constructor that initializes the associated data object 
     * 
     * \param pargCBarcodeEngineConfigData Data object containing the state that will be used for the new CBarcodeEngineConfig object
     */
    inline CBarcodeEngineConfig(CBarcodeEngineConfigData* pargCBarcodeEngineConfigData);
    /**
     * \brief Constructor that initializes the associated data object 
     * 
     * \param pargObj Data object containing the state that will be used for the new CBarcodeEngineConfig object
     */
    inline CBarcodeEngineConfig(CObj* pargObj);
    /**
     * \brief Destructor
     */
    inline virtual ~CBarcodeEngineConfig();
    /**
     * \brief Creates a new instance of this class and associates the provided \see IBarcodeEngine to it.
     * 
     * \param pBarcodeEngine Instance of a barcode engine that will be used with the current \see CBarcodeEngineConfig.
     */
    static CBarcodeEngineConfig Create(const IBarcodeEngine& pBarcodeEngine);
    /**
     * \brief Gets the associated barcode engine.
     * 
     * \return Associated barcode engine
     */
    IBarcodeEngine& GetBarcodeEngine() const;
    /**
     * \brief Gets the flag that specifies if the associated barcode engine is enabled or not.
     * 
     * If this flag is set to IDRS_FALSE, the associated barcode engine will not be used during barcode detection
     * 
     * \return Boolean flag indicating whether the barcode engine should be used or not.
     */
    IDRS_BOOL GetEnabled() const;
    /**
     * \brief Sets the flag that specifies if the associated barcode engine is enabled or not.
     * 
     * If this flag is set to IDRS_TRUE, the associated barcode engine will be used during barcode detection with the settings defined in this class.
     * If this flag is set to IDRS_FALSE, the associated barcode engine will not be used during barcode detection
     * 
     * \param bEnabled Boolean flag indicating whether the barcode engine should be used or not.
     */
    void SetEnabled(const IDRS_BOOL bEnabled);
    /**
     * \brief Gets the minimum value of the workdepth range where the associated barcode engine will run.
     * 
     * When the barcode detection process is executed, this value will be checked against the Workdepth value in \see CBarcodeParams.
     * If the Workdepth value defined in \see CBarcodeParams is greater or equal than Workdepth minimum range and smaller or equal than the workdepth maximum range, 
     * then the barcode engine will be used during the barcode detection process. 
     * 
     * \return Minimum workdepth value for which the associated barcode engine will be run
     */
    Workdepth GetWorkdepthRangeMinimum() const;
    /**
     * \brief Sets the minimum value of the workdepth range where the associated barcode engine will run.
     * 
     * When the barcode detection process is executed, this value will be checked against the Workdepth value in \see CBarcodeParams.
     * If the Workdepth value defined in \see CBarcodeParams is greater or equal than Workdepth minimum range and smaller or equal than the workdepth maximum range, 
     * then the barcode engine will be used during the barcode detection process. 
     * 
     * \param evWorkdepth Minimum workdepth value for which the associated barcode engine will be run
     */
    void SetWorkdepthRangeMinimum(const Workdepth evWorkdepth);
    /**
     * \brief Gets the maximum value of the workdepth range where the associated barcode engine will run.
     * 
     * When the barcode detection process is executed, this value will be checked against the Workdepth value in \see CBarcodeParams.
     * If the Workdepth value defined in \see CBarcodeParams is greater or equal than Workdepth minimum range and smaller or equal than the workdepth maximum range, 
     * then the barcode engine will be used during the barcode detection process. 
     * 
     * \return Maximum workdepth value for which the associated barcode engine will be run
     */
    Workdepth GetWorkdepthRangeMaximum() const;
    /**
     * \brief Sets the maximum value of the workdepth range where the associated barcode engine will run.
     * 
     * When the barcode detection process is executed, this value will be checked against the Workdepth value in \see CBarcodeParams.
     * If the Workdepth value defined in \see CBarcodeParams is greater or equal than Workdepth minimum range and smaller or equal than the workdepth maximum range, 
     * then the barcode engine will be used during the barcode detection process. 
     * 
     * \param evWorkdepth Maximum workdepth value for which the associated barcode engine will be run
     */
    void SetWorkdepthRangeMaximum(const Workdepth evWorkdepth);
    /**
     * \brief Gets the time interval in milliseconds after which the associated barcode engine will stop barcode detection
     *
     * The default timeout value is set to 5000 milliseconds.
     * 
     * \return Time interval in milliseconds that the associated barcode engine will run barcode detection.
     */
    IDRS_UINT GetTimeout() const;
    /**
     * \brief Sets the time interval in milliseconds after which the associated barcode engine will stop barcode detection
     *
     * \param uiTimeout Time interval in milliseconds that the associated barcode engine will run barcode detection.
     */
    void SetTimeout(const IDRS_UINT uiTimeout);
    /**
     * \brief Gets the array of barcode validations that will be used when running the associated barcode engine
     * 
     * \return Array containing the validation criteria for the associated barcode engine
     */
    CBarcodeValidationCriteriaArray GetValidationCriteria() const;
    /**
     * \brief Sets the array of barcode validations that will be used when running the associated barcode engine
     * 
     * \param xValidationCriterias Array containing the validation criteria for the associated barcode engine
     */
    void SetValidationCriteria(const CBarcodeValidationCriteriaArray& xValidationCriterias);
    /**
     * \brief Gets the array of preprocessing operations that will be applied to the input image before the barcode detection process
     *
     * The preprocessing operations will be applied on a copy of the input image. The original image will remain unchanged, while the 
     * associated barcode engine will receive a cloned image, on which all the preprocessing oprations are applied.
     *
     * The preprocessing operations will be applied in the order they appear in the \see CBarcodeEnginePreprocessArray
     * 
     * \return Array containing the preprocessing operations
     */
    CBarcodeEnginePreprocessArray GetPreprocessOperations() const;
    /**
     * \brief Sets the array of preprocessing operations that will be applied to the input image before the barcode detection process
     *
     * The preprocessing operations will be applied on a copy of the input image. The original image will remain unchanged, while the 
     * associated barcode engine will receive a cloned image, on which all the preprocessing oprations are applied.
     *
     * The preprocessing operations will be applied in the order they appear in the \see CBarcodeEnginePreprocessArray
     * 
     * \param xPreprocessOperations Array containing the preprocessing operations
     */
    void SetPreprocessOperations(const CBarcodeEnginePreprocessArray& xPreprocessOperations);
    /**
     * \brief Gets the array of postprocessing operations that will be applied to the barcode results obtained during the barcode detection process
     *
     * The postprocessing operations will be applied to all results of barcode detection.
     *
     * The postprocessing operations will be applied in the order they appear in the \see CBarcodeEnginePreprocessArray
     * 
     * \return Array containing the postprocessing operations
     */
    CBarcodeEnginePostprocessArray GetPostprocessOperations() const;
    /**
     * \brief Sets the array of postprocessing operations that will be applied to the barcode results obtained during the barcode detection process
     *
     * The postprocessing operations will be applied to all results of barcode detection.
     *
     * The postprocessing operations will be applied in the order they appear in the \see CBarcodeEnginePreprocessArray
     * 
     * \param xPostprocessOperations Array containing the postprocessing operations
     */
    void SetPostprocessOperations(const CBarcodeEnginePostprocessArray& xPostprocessOperations);
    /**
     * \brief Gets the array of barcode specific options
     * 
     * \return Array containing the barcode specific options
     */
    CBarcodeSpecificOptionsArray GetSpecificOptions() const;
    /**
     * \brief Sets the array of barcode specific options
     * 
     * \param xSpecificOptions Array containing the barcode specific options
     */
    void SetSpecificOptions(const CBarcodeSpecificOptionsArray& xSpecificOptions);

    
  private:
    /**
     * \brief returns a CBarcodeEngineConfigData reference
     *
     * Internal use only
     */
    CBarcodeEngineConfigData& TypedObject() const
    {
      return (CBarcodeEngineConfigData&)Object();
    }

  };

  typedef TObjPtrArray<CBarcodeEngineConfig> CBarcodeEngineConfigArray;
	
  /*
   *
   */
  inline CBarcodeEngineConfig::CBarcodeEngineConfig()
  {
  }
  /*
   *
   */
  inline CBarcodeEngineConfig::CBarcodeEngineConfig(const CBarcodeEngineConfig& argCBarcodeEngineConfig)
    : CObjPtr((CObjPtr &)argCBarcodeEngineConfig)
  {
  }
  /*
   *
   */
  inline CBarcodeEngineConfig::CBarcodeEngineConfig(CBarcodeEngineConfigData* pargCBarcodeEngineConfigData)
    : CObjPtr((CObj *)pargCBarcodeEngineConfigData)
  {
  }
  /*
   *
   */
  inline CBarcodeEngineConfig::CBarcodeEngineConfig(CObj* pargObj)
    : CObjPtr(pargObj)
  {
  }
  /*
   *
   */
  inline CBarcodeEngineConfig::~CBarcodeEngineConfig()
  {
  }
}
#endif // _CBarcodeEngineConfig_h_
