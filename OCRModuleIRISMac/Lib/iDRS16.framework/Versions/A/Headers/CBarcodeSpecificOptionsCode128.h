/**
 * \file CBarcodeSpecificOptionsCode128.h
 * class defining specific parameters for code128.
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */

#ifndef _CBarcodeSpecificOptionsCode128_h_
#define _CBarcodeSpecificOptionsCode128_h_

#include "CBarcodeSpecificOptions.h"

namespace IDRS
{
  class CBarcodeSpecificOptionsCode128Data;
  class CBarcodeSpecificOptionsData;
  /**
   * \brief CBarcodeSpecificOptions contains some specific options for code128 barcode type
   *  the specific options are: control code mode and mapping
   */
  class IDRSKRN_API CBarcodeSpecificOptionsCode128 : public CBarcodeSpecificOptions
  {
    public:
    /**
     * \brief Default constructor.
     */
    inline CBarcodeSpecificOptionsCode128();
    /**
     * \brief constructor from a CBarcodeSpecificOptionsData object.
     *
     */
    inline CBarcodeSpecificOptionsCode128(const CBarcodeSpecificOptionsCode128Data * pargBarcodeSpecificOptionsData);
    /**
     * \brief Default destructor.
     */
    inline ~CBarcodeSpecificOptionsCode128();
    /**
     * \brief checks if barcode is enabled.
     *
     * \returns IDRS_TRUE if enabled else IDRS_FALSE
     */
    IDRS_BOOL IsControlCodeEnabled() const;
    /**
     * \brief enable or disable control code.
     *
     * \param bEnable control code status
     */
    void SetControlCodeStatus(const IDRS_BOOL bEnable);
    /**
     * \brief checks if mapping is enabled.
     *
     * \returns IDRS_TRUE if enabled else IDRS_FALSE
     */
    IDRS_BOOL IsMappingEnabled() const;
    /**
     * \brief enable or disable control code.
     *
     * \param bUseMapping mapping status
     */
    void SetMappingStatus(const IDRS_BOOL bUseMapping);
    /**
     * \brief creates a new instance of CBarcodeSpecificOptionsCode128.
     *
     * \param benableControlCode IDRS_TRUE to enable
     * \param buseMapping IDRS_TRUE to use default mapping
     *
     * \return an instance of CBarcodeSpecificOptionsCode128
     */
    static CBarcodeSpecificOptionsCode128 Create(const IDRS_BOOL benableControlCode, const IDRS_BOOL buseMapping);
    private:
      CBarcodeSpecificOptionsCode128Data & TypedObject() const
      {
        return (CBarcodeSpecificOptionsCode128Data &)Object();
      }
  };
  /*
   *
   */
  inline CBarcodeSpecificOptionsCode128::CBarcodeSpecificOptionsCode128()
  {

  }
  /*
   *
   */
  inline CBarcodeSpecificOptionsCode128::CBarcodeSpecificOptionsCode128(const CBarcodeSpecificOptionsCode128Data * pargBarcodeSpecificOptionsCode128Data)
    : CBarcodeSpecificOptions((CObj*) pargBarcodeSpecificOptionsCode128Data )
  {
  }
  /*
   *
   */
  inline CBarcodeSpecificOptionsCode128::~CBarcodeSpecificOptionsCode128()
  {

  }
}

#endif // _CBarcodeSpecificOptionsCode128_h_
