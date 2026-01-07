/**
 * \file CPageMetadata.h
 * \brief Interface for CPageMetadata class
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */

#ifndef _CPageMetadata_h_
#define _CPageMetadata_h_

#include "CPageCustomData.h"
#include "CPageBookmark.h"
#include "CPageInteractiveForm.h"
#include "EnumDefinitions.h"
#include "CBarcode.h"

namespace IDRS
{
  class CPageMetadataData;
  /**
   * \brief CPageMetadata represents the metadata content of a page.
   */
  class IDRSKRN_API CPageMetadata : public CPageCustomData
  {
  public:
    /**
     * \brief Default constructor
     */
    inline CPageMetadata ();
    /**
     * \brief Copy constructor
     *
     * \param argPageMetadata Object to copy (shallow copy)
     */
    inline CPageMetadata ( const CPageMetadata& argPageMetadata );
    /**
     * \brief Constructor from data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageMetadata ( CPageMetadataData * pObj );
    /**
     * \brief Destructor
     */
    inline virtual ~CPageMetadata ();
    /**
     * \brief Creates a new instance.
     */
    static CPageMetadata Create ();
    /**
     * \brief Returns the page's interactive form.
     */
    CPageInteractiveForm GetInteractiveForm( ) const;
    /**
     * \brief Sets the page's interactive form.
     *
     * \pre !pobjInteractiveForm.IsNull()
     *
     * \param pobjInteractiveForm An interactive form object
     */
    void SetInteractiveForm( const CPageInteractiveForm& pobjInteractiveForm );
    /**
     * \brief Sets the value for the original rotation of the input source.
     *
     * When running the OCR and automatic orientation detection is enabled, iDRS automatically sets the detected rotation angle as OriginalRotation.
     * Since the OCR can only be executed on input sources with 0 degrees rotation, the input source is also rotated internally.
     *
     * Updating the OriginalRotation is having an effect on the following output document types:
     * - PDF: when UseOriginalRotation is set to IDRS_TRUE in CPdfOutputParams
     *
     * \param evPageRotation New value for page rotation
     */
    void SetOriginalOrientation ( const PageOrientation evPageRotation );
    /**
     * \brief Gets the original rotation of the input source.
     *
     * When running the OCR and automatic orientation detection is enabled, iDRS automatically sets the detected rotation angle as OriginalRotation.
     * Since the OCR can only be executed on input sources with 0 degrees rotation, the input source is also rotated internally.
     * This function is retrieving the original rotation angle of the input source image
     *
     * \return Original rotation angle of the input source image
     */
    PageOrientation GetOriginalOrientation () const;
    /**
     * \brief Sets the barcode data
     */
    void SetBarcodes(const CBarcodeArray& argxBarcodes);
    /**
     * \brief Retrieve the barcode data
     */
    CBarcodeArray GetBarcodes() const;
  private:
    //! Internal use
    CPageMetadataData & TypedObject () const
    {
      return (CPageMetadataData &) Object ();
    };
  };
  /*
   *
   */
  CPageMetadata::CPageMetadata ()
  {
  }
  /*
   *
   */
  CPageMetadata::CPageMetadata ( const CPageMetadata& argPageMetadata )
    : CPageCustomData ((CPageCustomData&) argPageMetadata )
  {
  }
  /*
   *
   */
  CPageMetadata::CPageMetadata ( CPageMetadataData * pObj )
    : CPageCustomData ((CPageCustomDataData*) pObj )
  {
  }
  /*
   *
   */
  CPageMetadata::~CPageMetadata ()
  {
  }
}
#endif // _CPageMetadata_h_
