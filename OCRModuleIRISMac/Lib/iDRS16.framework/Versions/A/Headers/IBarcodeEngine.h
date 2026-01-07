/**
 * \file IBarcodeEngine.h
 * Interface for IBarcodeEngine class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */

#ifndef _IBarcodeEngine_h_
#define _IBarcodeEngine_h_

#include <ArrayDefinitions.h>
#include <CBarcode.h>
#include <CImage.h>
#include <EnumDefinitions.h>
namespace IDRS
{

  //! Barcode handle
  typedef IDRS_PVOID IDRS_BARCODE_SESSION_HANDLE;

  // forward declarations
  class CBarcodeContext;

  /**
   * \brief IBarcodeEngine defines the interface representing a barcode engine used by iDRS SDK
   *
   * This class needs to be extended when creating a new barcode engine that would be used with iDRS SDK.
   *
   * A typical barcode engine is expected to have:
   * - session based recognition
   * - a set of barcodes that it can recognize. 
   * - a set of capabilities
   * - a unique identifier which will be used to target the specific barcode engine. Please use a value larger than 100. 
   */
  class IDRSKRN_API IBarcodeEngine
  {
  public:
    //! Destructor
    inline virtual ~IBarcodeEngine() = default;
    /**
     * \brief GetBarcodeEngineUniqueIdentifier retrieves barcode unique identifier.
     *
     * The value retrieved by this function will be used to reference this barcode engine when setting different properties
     * as well as in results.
     *
     * Please use values larger than 100 when creating new barcode engines registered with iDRS SDK.
     * Currently iDRS SDK uses values 0 to 7, but future versions might include new engines.
     *
     * \return Unique identifier for the barcode engine
     */
    virtual BarcodeEngineIdentifier GetBarcodeEngineUniqueIdentifier() const = 0;
    /**
     * \brief GetSupportedCapabilities retrieves the list of capabilities supported by the barcode engine.
     *
     * \return An array containing all supported capabilities
     */
    virtual BarcodeCapabilityArray GetSupportedCapabilities() const;
    /**
     * \brief GetSupportedBarcodeTypes retrieves the engine's supported barcode types
     *
     * \return An array containing all barcode types supported by the engine.
     */
    virtual BarcodeTypeArray GetSupportedBarcodeTypes() const;
    /**
     * \brief CreateSession creates a new session for recognition purposes
     *
     * \return Barcode session handle
     */
    virtual IDRS_BARCODE_SESSION_HANDLE CreateSession () = 0;
    /**
     * \brief CloseSession closes an already opened session
     *
     * \param hBarcodeSession Barcode session
     */
    virtual void CloseSession(IDRS_BARCODE_SESSION_HANDLE hBarcodeSession) = 0;
    /**
     * \brief SessionEnableBarcodeType enables a barcode type for the specified session
     *
     * \param hBarcodeHandle Barcode session handle
     * \param evBarcodeType Barcode type
     * \param bEnable Flag indicating whether the barcode type should be enabled or not.
     *
     * \return IDRS_SUCCESS if the barcode type could be enabled. Error code otherwise
     */
    inline virtual IDRS_ERROR SessionEnableBarcodeType(IDRS_BARCODE_SESSION_HANDLE hBarcodeHandle, 
      const BarcodeType evBarcodeType, const IDRS_BOOL bEnable);
    /**
     * \brief SessionSetBarcodeProperties sets barcode type properties for the specified session
     *
     * \param hBarcodeHandle Barcode session handle
     * \param evBarcodeType Barcode type
     * \param stAdvancedParameters Structure containing the barcode type properties
     *
     * \return IDRS_SUCCESS if the barcode type properties could be set. Error code otherwise
     */
    inline virtual IDRS_ERROR SessionSetBarcodeProperties(IDRS_BARCODE_SESSION_HANDLE hBarcodeHandle, 
      const BarcodeType evBarcodeType, const BarcodeAdvancedParameters& stAdvancedParameters);
    /**
     * \brief SessionSetParameters sets a session parameter
     *
     * \param hBarcodeHandle Barcode session handle
     * \param evParameter Parameter identifier
     * \param uiValue Parameter type
     *
     * \return IDRS_SUCCESS if the session parameter could be set. Error code otherwise
     */
    inline virtual IDRS_ERROR SessionSetParameters(IDRS_BARCODE_SESSION_HANDLE hBarcodeHandle,
      const BarcodeSessionParameter evParameter, const IDRS_UINT uiValue);
    /**
     * \brief ProcessImage runs barcode recognition on the supplied image
     *
     * The image data is guaranteed to be valid until the function ends. If the engine does not change the input image, then it can safely reference the pixels from the provided image.
     * In case the image needs to be modified, the engine should make a copy of the provided image.
     *
     * The barcode results are expected to be added to argBarcodeResults as individual CBarcodeResult objects.
     *
     * \param hBarcodeEngineHandle Barcode session handle
     * \param argInputImage Input image
     * \param argBarcodeContext Barcode context
     * \param argBarcodeResults Object where all barcode results are expected to be stored.
     *
     * \return IDRS_SUCCESS if the barcode recognition was executed without any error. Error code otherwise
     */
    inline virtual IDRS_ERROR ProcessImage(IDRS_BARCODE_SESSION_HANDLE hBarcodeEngineHandle,
      const CImage& argInputImage, const CBarcodeContext & argBarcodeContext, CBarcodeArray& argBarcodeResults ) = 0;
  };
  /*
   *
   */
  IDRS_ERROR IBarcodeEngine::SessionEnableBarcodeType(IDRS_BARCODE_SESSION_HANDLE /*hBarcodeHandle*/,
    const BarcodeType /*evBarcodeType*/, const IDRS_BOOL /*bEnable*/)
  {
    return IDRS_SUCCESS;
  }
  /*
   *
   */
  IDRS_ERROR IBarcodeEngine::SessionSetBarcodeProperties(IDRS_BARCODE_SESSION_HANDLE /*hBarcodeHandle*/,
    const BarcodeType /*evBarcodeType*/, const BarcodeAdvancedParameters& /*bapAdvancedParameters*/)
  {
    return IDRS_SUCCESS;
  }
  /*
   *
   */
  IDRS_ERROR IBarcodeEngine::SessionSetParameters(IDRS_BARCODE_SESSION_HANDLE /*hBarcodeHandle*/,
    const BarcodeSessionParameter /*bpParameter*/, const IDRS_UINT /*uiValue*/)
  {
    return IDRS_SUCCESS;
  }
}
#endif // _IBarcodeEngine_h_
