/**
 * \file CBarcodeEngineManager.h
 * Interface for CBarcodeEngineManager class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */

#ifndef _CBarcodeEngineManager_h_
#define _CBarcodeEngineManager_h_

#include <IBarcodeEngine.h>

namespace IDRS
{
  /**
   * \brief CBarcodeEngineManager class contains the registry for all barcode engines available in iDRS SDK.
   * 
   * The class allows easy integration of 3rd party barcode engines 
   *
   * The class provides static methods for dealing with the barcode registration registration. It is not expected to be instantiated.
   *
   * The class will maintain a list with references to the available barcode engines.
   */
  class IDRSKRN_API CBarcodeEngineManager
  {
  public:
    /**
     * \brief RegisterBarcodeEngine adds a barcode engine to the barcode engines available for recognition
     *
     * Please note that the barcode engine is added by reference. iDRS SDK will store the pointers internally.
     * It is integrator's responsability to ensure that the reference stays valid until the barcode engine is unregistered from the CBarcodeEngineManager
     *
     * \param argBarcodeEngine Reference to the barcode engine object to register
     *
     * \retval IDRS_SUCCESS if the barcode engine was successfully registered
     * \retval IDRS_ERROR_BARCODE_ENGINE_ALREADY_REGISTERED if the barcode engine is already registered
     */
    static IDRS_ERROR RegisterBarcodeEngine ( const IBarcodeEngine & argBarcodeEngine );
    /**
     * \brief UnregisterBarcodeEngine removes a barcode engine from the barcode engines available for recognition.
     *
     * Please note that iDRS SDK will not try to delete or cleanup the removed object. 
     * It is integrator's responsability to cleanup any memory used by the barcode engine.
     *
     * Once unregistered, the concerned engine won't be taken into consideration anymore for barcode recognition.
     *
     * Please note that iDRS SDK internal barcode engines cannot be removed from the registry.
     * If you do not want to use a specific engine, you can instead disable it. See \see CBarcodeContext for details
     *
     * \param evBarcodeUID Barcode engine unique identifier
     *
     * \retval IDRS_SUCCESS if the barcode engine was successfully unregistered, another error code otherwise
     */
    static IDRS_ERROR UnregisterBarcodeEngine ( const BarcodeEngineIdentifier evBarcodeUID );
    /**
     * \brief Returns the number of barcode engines currently registered.
     *
     * Please note that iDRS barcode engines are also included in the count returned.
     *
     * \return The number of barcode engines already added
     */
    static IDRS_UINT GetBarcodeEngineCount ();
    /**
     * \brief GetAt returns a pointer to a barcode engine already added
     *
     * \param uiIndex Index of the barcode engine to be returned
     *
     * \return Pointer to the barcode engine stored at specified index
     */
    static IBarcodeEngine* GetAt ( const IDRS_UINT uiIndex );
    /**
     * \brief IsBarcodeEngineRegistered verifies if a specified barcode engine identifier is registered or not
     *
     * \param evBarcodeUID Barcode engine unique identifier
     *
     * \return IDRS_TRUE if the barcode engine has been found, IDRS_FALSE otherwise
     */
    static IDRS_BOOL IsBarcodeEngineRegistered ( const BarcodeEngineIdentifier evBarcodeUID );
    /**
     * \brief GetEngineByUniqueIdentifier retrieves a barcode engine by it's unique identifier.
     *
     * If there is no barcode engine having the supplied identifier, the function will return NULL
     *
     * \param evBarcodeUID Barcode engine unique identifier
     *
     * \return Pointer to the barcode engine if it has been found, NULL otherwise
     */
    static IBarcodeEngine* GetEngineByUniqueIdentifier ( const BarcodeEngineIdentifier evBarcodeUID );
    /**
     * \brief Destructor
     */
    inline ~CBarcodeEngineManager();
  private:
    /**
     * \brief Private default constructor to forbid class instantiation
     */
    inline CBarcodeEngineManager();
  };
  /*
   *
   */
  inline CBarcodeEngineManager::CBarcodeEngineManager()
  {
  }
  /*
   *
   */
  inline CBarcodeEngineManager::~CBarcodeEngineManager()
  {
  }
}

#endif // _CBarcodeEngineManager_h_
