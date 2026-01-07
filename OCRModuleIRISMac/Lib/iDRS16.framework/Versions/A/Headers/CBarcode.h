/**
 * \file CBarcode.h
 * \brief Interface for CBarcode class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _CBarcode_h_
#define _CBarcode_h_

#include "CObjPtr.h"
#include "BarcodeType.h"
#include "EnumDefinitions.h"
#include "TObjPtrArray.h"

namespace IDRS
{
  class CBarcodeData;
  class idrs_string;
  /**
   * \brief CBarcode contains the data associated with a barcode result.
   *
   * Instances of this class are usually created during the barcode detection process
   */
  class IDRSKRN_API CBarcode : public CObjPtr
  {
  public:
    /**
     * \brief Default constructor
     */
    inline CBarcode();
    /**
     * \brief Copy constructor
     * 
     * \param argCBarcode CBarcode object to copy
     */
    inline CBarcode(const CBarcode& argCBarcode);
    /**
     * \brief Constructor from data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pargCBarcodeData Pointer to an object representing the data class
     */
    inline CBarcode(CObj* pargCBarcodeData);
    /**
     * \brief Destructor
     */
    inline virtual ~CBarcode();
    /**
     * \brief Creates a new instance and initializes the internal values with default values
     */
    static CBarcode Create();
    /**
     * \brief Create a new instance and initializes the internal values with the provided values
     *
     * \param strValue Barcode value
     * \param uiConfidence Barcode confidence level
     * \param evBarcodeType Barcode Type
     * \param uiOrientation Barcode orientation
     * \param rcBoundingBox Rectangle where the barcode is found in the page
     * \param evEngineIdentifier Identifier of the barcode engine that detected the barcode
     */
    static CBarcode Create(const idrs_string& strValue, const IDRS_UINT uiConfidence, const BarcodeType evBarcodeType, const IDRS_UINT uiOrientation, const IDRS_RECT& rcBoundingBox, const BarcodeEngineIdentifier evEngineIdentifier);

    /**
     * \brief GetBarcodeType retrieves the barcode type
     *
     * \return Barcode type
     */
    BarcodeType GetBarcodeType() const;
    /**
     * \brief GetValue retrieves the barcode value
     *
     * \return The barcode value
     */
    const idrs_string& GetValue() const;
    /**
     * \brief GetOrientation retrieves the barcode orientation
     *
     * \return Barcode orientation
     */
    IDRS_UINT GetOrientation() const;
    /**
     * \brief GetBoundingBox retrieves the bounding box where the barcode can be found
     *
     * \return Rectangle in the source image/page where the barcode was detected
     */
    IDRS_RECT GetBoundingBox() const;
    /**
     * \brief GetConfidence retrieves an indicator specifying how sure is the barcode engine about the detect barcode value
     *
     * The confidence level is a value ranging from 0 to 100, where 0 represents the least confidence and 100 represents the maximum confidence levels
     *
     * \return IDRS::IDRS_UINT
     */
    IDRS_UINT GetConfidence() const;
    /**
     * \brief GetEngineIdentifier retrieves the identified of the barcode engine that detected the barcode 
     *
     * \return Barcode identifier of the engine that detected the barcode value
     */
    BarcodeEngineIdentifier GetEngineIdentifier() const;
    /**
     * \brief Sets the barcode type
     *
     * \param evBarcodeType Barcode type
     */
    void SetBarcodeType(const BarcodeType& evBarcodeType);
    /**
     * \brief Sets the barcode value
     *
     * \param strValue The barcode value
     */
    void SetValue(const idrs_string& strValue);
    /**
     * \brief Sets the barcode orientation
     *
     * \param uiOrientation The value to set
     */
    void SetOrientation(const IDRS_UINT uiOrientation);
    /**
     * \brief Sets the bounding box where the barcode can be found
     *
     * \param rcBoundingBox Rectangle where the barcode is found in the page
     */
    void SetBoundingBox(const IDRS_RECT& rcBoundingBox);
    /**
     * \brief Sets an indicator specifying how sure is the barcode engine about the detect barcode value
     *
     * \param uiConfidence Barcode confidence level
     */
    void SetConfidence(const IDRS_UINT uiConfidence);
    /**
     * \brief Sets the identifier of the barcode engine that detected the barcode 
     *
     * \param evEngineIdentifier Identifier of the barcode engine that detected the barcode
     */
    void SetEngineIdentifier(const BarcodeEngineIdentifier evEngineIdentifier);
  private:
    // For internal use only
    CBarcodeData& TypedObject() const
    {
      return (CBarcodeData&)Object();
    };

  };

  typedef TObjPtrArray<CBarcode> CBarcodeArray;

  /*
   *
   */
  inline CBarcode::CBarcode()
  {
  }
  /*
   *
   */
  inline CBarcode::CBarcode(const CBarcode& argCBarcode)
    : CObjPtr((CObjPtr &)argCBarcode)
  {
  }
  /*
   *
   */
  inline CBarcode::CBarcode(CObj* pargCBarcodeData)
    : CObjPtr(pargCBarcodeData)
  {
  }
  /*
   *
   */
  inline CBarcode::~CBarcode()
  {
  }
}
#endif // _CBarcode_h_

