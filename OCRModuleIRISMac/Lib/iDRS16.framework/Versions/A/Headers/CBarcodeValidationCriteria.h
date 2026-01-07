/**
 * \file CBarcodeValidationCriteria.h
 * \brief Interface for CBarcodeValidationCriteria class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _CBarcodeValidationCriteria_h_
#define _CBarcodeValidationCriteria_h_

#include "CObjPtr.h"
#include "BarcodeType.h"
#include "TObjPtrArray.h"

namespace IDRS
{
  class CBarcodeValidationCriteriaData;
  /**
   * \brief CBarcodeValidationCriteria contains detailed parametes for barcode validation
   *
   * This class allows setting the following barcode validation options:
   * - Enable/disable barcode type
   * - Minimum confidence level for detected barcode(s) of the specified type
   */
  class IDRSKRN_API CBarcodeValidationCriteria : public CObjPtr
  {
  public:
    /**
     * \brief Default constructor. 
     */
    inline CBarcodeValidationCriteria();
    /**
     * \brief Copy constructor. 
     * 
     * \param argCBarcodeValidationCriteria Object to copy. 
     *
     * This method will initialize the newly created CBarcodeValidationCriteria with the data object from argCBarcodeValidationCriteria parameter.
     */
    inline CBarcodeValidationCriteria(const CBarcodeValidationCriteria& argCBarcodeValidationCriteria);
    /**
     * \brief Constructor that initializes the associated data object 
     * 
     * \param pargCBarcodeValidationCriteriaData Data object containing the state that will be used for the new CBarcodeValidationCriteria object
     */
    inline CBarcodeValidationCriteria(CBarcodeValidationCriteriaData* pargCBarcodeValidationCriteriaData);
    /**
     * \brief Constructor that initializes the associated data object 
     * 
     * \param pargObj Data object containing the state that will be used for the new CBarcodeParams
     */
    inline CBarcodeValidationCriteria(CObj* pargObj);
    /**
     * \brief Destructor
     */
    inline virtual ~CBarcodeValidationCriteria();
    /**
     * \brief Creates a new instance of this class and associates the provided \see BarcodeType to it.
     * 
     * \param evBarcodeType Barcode type
     * \param bEnabled Boolean flag specifying whether the barcode type is enabled or not.
     */
    static CBarcodeValidationCriteria Create(const BarcodeType evBarcodeType, const IDRS_BOOL bEnabled = IDRS_TRUE);
    /**
     * \brief Gets the barcode barcode type associated to this criteria
     * 
     * Barcode criteria validation works per barcode type
     *
     * \return Barcode type
     */
    BarcodeType GetBarcodeType() const;
    /**
     * \brief Gets the boolean flag that specifies if the associated barcode barcode type is enabled or not
     * 
     * Since the barcode validation criteria are set for each engine separately, this setting has an effect on the
     * barcode engine for which the barcode validation criteria is assigned.
     *
     * \return Boolean flag enabling/disabling the associated barcode type
     */
    IDRS_BOOL GetEnabled() const;
    /**
     * \brief Sets the boolean flag that specifies if the associated barcode barcode type is enabled or not
     * 
     * Since the barcode validation criteria are set for each engine separately, this setting has an effect on the
     * barcode engine for which the barcode validation criteria is assigned.
     *
     * \param bEnabled Boolean flag enabling/disabling the associated barcode type
     */
    void SetEnabled(const IDRS_BOOL bEnabled);
    /**
     * \brief Gets the minimum confidence level for which a detected result of the associated barcode type is considered valid.
     * If the confidence level does not match the match this setting, the barcode result will be rejected
     * 
     * Since the barcode validation criteria are set for each engine separately, this setting has an effect on the
     * barcode engine for which the barcode validation criteria is assigned.
     *
     * \return Minimum confidence level for the specified barcode type
     */
    IDRS_UINT GetMinimumConfidence();
    /**
     * \brief Sets the minimum confidence level for which a detected result of the associated barcode type is considered valid.
     * If the confidence level does not match the match this setting, the barcode result will be rejected
     * 
     * Since the barcode validation criteria are set for each engine separately, this setting has an effect on the
     * barcode engine for which the barcode validation criteria is assigned.
     *
     * \param uiMinimumConfidence Minimum confidence level for the specified barcode type
     */
    void SetMinimumConfidence(const IDRS_UINT uiMinimumConfidence);
  private:
    // For internal use only
    CBarcodeValidationCriteriaData& TypedObject() const
    {
      return (CBarcodeValidationCriteriaData&)Object();
    };
  };	

  typedef TObjPtrArray<CBarcodeValidationCriteria> CBarcodeValidationCriteriaArray;
  /*
   *
   */
  inline CBarcodeValidationCriteria::CBarcodeValidationCriteria()
  {
  }
  /*
   *
   */
  inline CBarcodeValidationCriteria::CBarcodeValidationCriteria(const CBarcodeValidationCriteria& argCBarcodeValidationCriteria)
    : CObjPtr((CObjPtr &)argCBarcodeValidationCriteria)
  {
  }
  /*
   *
   */
  inline CBarcodeValidationCriteria::CBarcodeValidationCriteria(CBarcodeValidationCriteriaData* pargCBarcodeValidationCriteriaData)
    : CObjPtr((CObj *)pargCBarcodeValidationCriteriaData)
  {
  }
  /*
   *
   */
  inline CBarcodeValidationCriteria::CBarcodeValidationCriteria(CObj* pargObj)
    : CObjPtr(pargObj)
  {
  }
  /*
   *
   */
  inline CBarcodeValidationCriteria::~CBarcodeValidationCriteria()
  {
  }
}
#endif // _CBarcodeValidationCriteria_h_
