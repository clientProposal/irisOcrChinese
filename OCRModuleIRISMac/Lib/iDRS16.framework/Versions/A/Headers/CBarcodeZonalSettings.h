/**
 * \file CBarcodeZonalSettings.h
 * \brief Interface for CBarcodeZonalSettings class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _CBarcodeZonalSettings_h_
#define _CBarcodeZonalSettings_h_

#include "CObjPtr.h"
#include "CBarcodeContext.h"
#include "TObjPtrArray.h"
#include "CPolygon.h"

namespace IDRS
{
  class CBarcodeZonalSettingsData;
  /**
   * \brief CBarcodeZonalSettings contains the configuration for a set of zones where barcode detection will be executed with the same \see CBarcodeContext. 
   *
   * This class allows setting following options fo the zonal configuration for barcode detection:
   * - barcode context
   * - array of polygons
   */
  class IDRSKRN_API CBarcodeZonalSettings : public CObjPtr
  {
  public:
    /**
     * \brief Default constructor. 
     */
    inline CBarcodeZonalSettings();
    /**
     * \brief Copy constructor. 
     * 
     * \param argCBarcodeZonalSettings Object to copy. 
     *
     * This method will initialize the newly created CBarcodeZonalSettings with the data object from argCBarcodeZonalSettings parameter.
     */
    inline CBarcodeZonalSettings(const CBarcodeZonalSettings& argCBarcodeZonalSettings);
    /**
     * \brief Constructor that initializes the associated data object 
     * 
     * \param pargCBarcodeZonalSettingsData Data object containing the state that will be used for the new CBarcodeZonalSettings object
     */
    inline CBarcodeZonalSettings(const CObj* pargCBarcodeZonalSettingsData);
    /**
     * \brief Destructor
     */
    inline virtual ~CBarcodeZonalSettings();
    /**
     * \brief Creates a new instance of this class
     */
    static CBarcodeZonalSettings Create();
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
    /**
     * \brief Gets the array of zones (defined as \see CPolygon) where barcode recognition will be executed using the associated context.
     * 
     * \return Array of polygons where barcode detection will be run
     */
    CPolygonArray GetZones() const;
    /**
     * \brief Sets the array of zones (defined as \see CPolygon) where barcode recognition will be executed using the associated context.
     *
     * Setting one or more polygons with coordinates outside the input page/image bounds will trigger an exception during barcode detection. 
     *
     * \param argZones Array of polygons where barcode detection will be run
     */
    void SetZones(const CPolygonArray& argZones);
  private:
    // For internal use only
    CBarcodeZonalSettingsData& TypedObject() const
    {
      return (CBarcodeZonalSettingsData&)Object();
    };
  };

  typedef TObjPtrArray<CBarcodeZonalSettings> CBarcodeZonalSettingsArray;
	
  /*
   *
   */
  inline CBarcodeZonalSettings::CBarcodeZonalSettings()
  {
  }
  /*
   *
   */
  inline CBarcodeZonalSettings::CBarcodeZonalSettings(const CBarcodeZonalSettings& argCBarcodeZonalSettings)
    : CObjPtr((CObjPtr &)argCBarcodeZonalSettings)
  {
  }
  /*
   *
   */
  inline CBarcodeZonalSettings::CBarcodeZonalSettings(const CObj* pargCBarcodeZonalSettingsData)
    : CObjPtr(const_cast<CObj*>(pargCBarcodeZonalSettingsData))
  {
  }
  /*
   *
   */
  inline CBarcodeZonalSettings::~CBarcodeZonalSettings()
  {
  }
}
#endif // _CBarcodeZonalSettings_h_
