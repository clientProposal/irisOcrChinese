/**
 * \file CBarcodePageParams.h
 * \brief Interface for CBarcodePageParams class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _CBarcodePageParams_h_
#define _CBarcodePageParams_h_

#include "CBarcodeParams.h"
#include "CBarcodeContext.h"

namespace IDRS
{
  class CBarcodePageParamsData;
  /**
   * \brief CBarcodePageParams contains the configuration for full page barcode detection. 
   *
   * This class allows setting the following barcode detection options:
   * - Barcode context - specifying the list of barcode types to recognize
   * - Threading mode - use one or several threads for barcode detection
   * - The workdepth - enabling/disabling barcode engines (\see CBarcodeEngineConfig) 
   * - Barcode engines configuration
   */
  class IDRSKRN_API CBarcodePageParams : public CBarcodeParams
  {
  public:
    /**
     * \brief Default constructor. 
     */
    inline CBarcodePageParams();
    /**
     * \brief Copy constructor. 
     * 
     * \param argCPageBarcodeParams Object to copy. 
     *
     * This method will initialize the newly created CBarcodePageParams with the data object from argCPageBarcodeParams parameter.
     */
    inline CBarcodePageParams(const CBarcodePageParams& argCPageBarcodeParams);
    /**
     * \brief Constructor that initializes the associated data object 
     * 
     * \param pargCPageBarcodeParamsData Data object containing the state that will be used for the new CBarcodePageParams object
     */
    inline CBarcodePageParams(CBarcodePageParamsData* pargCPageBarcodeParamsData);
    /**
     * \brief Constructor that initializes the associated data object 
     * 
     * \param pObj Data object containing the state that will be used for the new CBarcodePageParams
     */
    inline CBarcodePageParams(CObj* pObj);
    /**
     * \brief Destructor
     */
    inline virtual ~CBarcodePageParams();
    /**
     * \brief Creates a new instance of this class
     */
    static CBarcodePageParams Create();
    /**
     * \brief Creates a new instance of this class and sets the associated \see CBarcodeContext
     *
     * \param argBarcodeContext Barcode context to set
     *
     * By default the associated barcode context enables all available barcode types (license permitting)
     */
    static CBarcodePageParams Create(const CBarcodeContext& argBarcodeContext);
    /**
     * \brief Gets the associated barcode context.
     * 
     * The barcode context allows setting the list of barcodes that can be detected by the barcode engine, barcode size range & encodings
     *
     * \return Associated barcode context
     */
    CBarcodeContext GetContext() const;
    /**
     * \brief Sets the associated barcode context.
     * 
     * The barcode context allows setting the list of barcodes that can be detected by the barcode engine, barcode size range & encodings
     *
     * \param argContext Associated barcode context
     */
    void SetContext(const CBarcodeContext& argContext);
  private:
    // For internal use only
    CBarcodePageParamsData& TypedObject() const
    {
      return (CBarcodePageParamsData&)Object();
    };
  };
  /*
   *
   */
  inline CBarcodePageParams::CBarcodePageParams()
  {
  }
  /*
   *
   */
  inline CBarcodePageParams::CBarcodePageParams(const CBarcodePageParams& argCPageBarcodeParams)
    : CBarcodeParams((CBarcodeParams&)argCPageBarcodeParams)
  {
  }
  /*
   *
   */
  inline CBarcodePageParams::CBarcodePageParams(CBarcodePageParamsData* pargCPageBarcodeParamsData)
    : CBarcodeParams((CObj *)pargCPageBarcodeParamsData)
  {
  }
  /*
   *
   */
  inline CBarcodePageParams::CBarcodePageParams(CObj* pObj)
    : CBarcodeParams(pObj)
  {

  }
  /*
   *
   */
  inline CBarcodePageParams::~CBarcodePageParams()
  {
  }
}
#endif // _CBarcodePageParams_h_
