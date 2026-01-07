/**
 * \file CBarcodeContext.h
 * \brief Interface for the IDRS::CBarcodeContext class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _cbarcodecontext_h_
#define _cbarcodecontext_h_
#include <CObjPtr.h>
#include <ArrayDefinitions.h>

namespace IDRS
{
  class CBarcodeContextData;
  class CBarcodeModule;
  /**
   * \brief The CBarcodeContext class manages a barcode recognition context.
   * \ingroup module_barcode
   *
   * A barcode recognition context is a set of parameters used by the barcode engine to process images.
   *
   * When more than one barcode type is enable and a barcode may be recognized by different algorithms (with possible different solutions),
   * the barcode is rejected except when:
   * - If it is recognized as EAN 13 and UPC-A: the UPC-A is output
   * - If it is recognized as code 128 and UCC 128: the UCC 128 is output
   * - If it is recognized as MSI and MSIPH: the MSIPH is output
   * - If it is recognized as code 39 and code 39 extended: the code 39 extended is output
   * - If it is recognized as code 39 HIBC and code 39 or code 39 extended: the code 39 HIBC is output
   * - If it is recognized as UPC-E and UPC-E extended: the UPC-E is output
   *
   * \req IDRS::Module::Barcode
   *
   * \see BarcodeType The barcode types supported by iDRS.
   * \see group_idrs_defaults The default recognition parameters.
   * \see BarcodeDirection iDRS barcode detection direction flags.
   * \see Module::Barcode
   *
   */
  class IDRSKRN_API CBarcodeContext : public CObjPtr
  {
    public:
      //
      inline CBarcodeContext ();
      //
      inline CBarcodeContext ( const CBarcodeContext & aBCodeContext );
      //
      inline CBarcodeContext ( CBarcodeContextData * pObj );
      //
      inline virtual ~CBarcodeContext ();
      /**
       * \brief Create creates a barcode recognition context.
       * The context is initialized to detect all recommended barcode types allowed by the licenses,
       * apart from QrCode, Aztec and Datamatrix types which are not enabled by default.
       */
      static CBarcodeContext Create ();
      /**
       * \brief Create creates a barcode recognition context to recognize the given barcode type.
       *
       * \param evBarcodeType The barcode type to recognize.
       *
       * \see group_idrs_barcodes iDRS barcode types.
       *
       * \note If the provided value is BarcodeType::None, all recommended barcode types allowed by the licenses,
       * apart from QrCode, Aztec and Datamatrix types which are not enabled by default.
       */
      static CBarcodeContext Create ( const BarcodeType evBarcodeType );
      /**
       * \brief Create creates a barcode recognition context to recognize the given barcode types.
       *
       * \pre xBarcodeTypes.GetCount() > 0
       *
       * \param xBarcodeTypes An array containing the barcode types to recognize.
       *
       * \see group_idrs_barcodes iDRS barcode types.
       */
      static CBarcodeContext Create ( const BarcodeTypeArray& xBarcodeTypes );
      /**
       * \brief SetBarcodeTypes sets the barcode types to look for.
       *
       * \pre ! IsNull ()
       *
       * \param xBarcodeTypes An array containing the barcode types to recognize.
       *
       * \see group_idrs_barcodes iDRS barcode types.
       */
      void SetBarcodeTypes ( const BarcodeTypeArray& xBarcodeTypes );
      /**
       * \brief Gets the barcode types set
       *
       * \return The array of barcode types to be used for recognition
       */
      BarcodeTypeArray GetBarcodeTypes() const;
      /**
       * \brief Get the minimum bar height required to validate a 1D barcode candidate
       *
       * \return The minimum bar height
       */
      IDRS_UINT GetMinimumPixelsHeight() const;
      /**
       * \brief Set the minimum bar height required to validate a 1D barcode candidate
       *
       * \param uiMinimumPixelsHeight The value to set
       */
      void SetMinimumPixelsHeight(const IDRS_UINT uiMinimumPixelsHeight);
      /**
       * \brief Get the maximum bar height required to validate a 1D barcode candidate
       *
       * \return The maximum bar height
       */
      IDRS_UINT GetMaximumPixelsHeight() const;
      /**
       * \brief Set the maximum bar height required to validate a 1D barcode candidate
       *
       * \param uiMaximumPixelsHeight The value to set
       */
      void SetMaximumPixelsHeight(const IDRS_UINT uiMaximumPixelsHeight);
      /**
       * \brief Get the minimum number of symbols required to validate a 1D barcode candidate
       *
       * \return The minimum symbols number
       */
      IDRS_UINT GetMinimumSymbolsLength() const;
      /**
       * \brief Set the minimum number of symbols required to validate a 1D barcode candidate
       *
       * \param uiMinimumSymbolsLength The value to set
       */
      void SetMinimumSymbolsLength(const IDRS_UINT uiMinimumSymbolsLength);
      /**
       * \brief Get the maximum number of symbols required to validate a 1D barcode candidate
       *
       * \return The maximum symbols number
       */
      IDRS_UINT GetMaximumSymbolsLength() const;
      /**
       * \brief Set the maximum number of symbols required to validate a 1D barcode candidate
       *
       * \param uiMaximumSymbolsLength The value to set
       */
      void SetMaximumSymbolsLength(const IDRS_UINT uiMaximumSymbolsLength);
      /**
       * \brief Get the array of barcode encodings to detect.
       *
       * \return The array of barcode encodings
       */
      BarcodeEncodingArray GetDetectedEncodings() const;
      /**
       * \brief Set the array of barcode encodings to detect.
       *
       * \brief argBarcodeEncodingArray The array of barcode encodings to detect
       */
      void SetDetectedEncodings(const BarcodeEncodingArray& argBarcodeEncodingArray);
      /**
       * \brief Get the flag indicating if the iDRS should stop barcode recognition as soon as a result is found
       *
       * \return The value of the flag
       */
      IDRS_BOOL GetStopOnFirstResult() const;
      /**
       * \brief Set the flag indicating if the iDRS should stop barcode recognition as soon as a result is found
       */
      void SetStopOnFirstResult(const IDRS_BOOL bStopOnFirstResult);
      /**
       * \brief Gets a CBarcodeSet object populated with the barcode types recommended
       * for most barcode recognition workflows.
       * - PDF417, QRCode and Aztec barcodes will be added automatically if the required extensions are enabled.
       * - Datamatrix barcode type will not be enabled by default, even if the corresponding extension is set, it needs to be activated explicitly.
       * - For other barcode types, they can be activated provided they are a valid type.
       *
       * \return The set of recommended barcode types.
       */
      static BarcodeTypeArray GetRecommendedBarcodeTypes ();
    private:
      /**
       * Internal use only;
       */
      CBarcodeContextData & TypedObject () const
      {
        return ( CBarcodeContextData & )Object ();
      };
  };
  /*
   *
   */
  inline CBarcodeContext::CBarcodeContext ()
  {
  }
  /*
   *
   */
  inline CBarcodeContext::CBarcodeContext ( const CBarcodeContext & aBCodeContext )
    : CObjPtr ((CObjPtr & )aBCodeContext )
  {
  }
  /*
   *
   */
  inline CBarcodeContext::CBarcodeContext ( CBarcodeContextData * pObj )
    : CObjPtr((CObj* )pObj )
  {
  }
  /*
   *
   */
  inline CBarcodeContext::~CBarcodeContext ()
  {
  }
} // namespace
#endif /* _cbarcodecontext_h_ */
