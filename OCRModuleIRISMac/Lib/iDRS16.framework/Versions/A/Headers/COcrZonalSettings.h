/**
 * \file COcrZonalSettings.h
 * \brief Interface for COcrZonalSettings class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _COcrZonalSettings_h_
#define _COcrZonalSettings_h_

#include <CObjPtr.h>
#include <COcrZoneDescription.h>
#include <COcrContext.h>
#include <TObjPtrArray.h>

namespace IDRS
{
  class COcrZonalSettingsData;
  /**
   * \brief The class COcrZonalSettings contains the configuration for a set of zones where text recognition will be executed with the same \see COcrContext.
   *
   * This class allows setting following options fo the zonal configuration for text recognition:
   * - ocr context
   * - array of zones where text detection will be executed
   */
  class IDRSKRN_API COcrZonalSettings : public CObjPtr
  {
  public:
    /**
     * \brief Default constructor. 
     */
    inline COcrZonalSettings();
    /**
     * \brief Copy constructor. 
     * 
     * \param argCOcrZonalSettings Object to copy. 
     *
     * This method will initialize the newly created COcrZonalSettings with the data object from argCOcrZonalSettings parameter.
     */
    inline COcrZonalSettings(const COcrZonalSettings& argCOcrZonalSettings);
    /**
     * \brief Constructor that initializes the associated data object 
     * 
     * \param pargCOcrZonalSettingsData Data object containing the state that will be used for the new COcrZonalSettings object
     */
    inline COcrZonalSettings(CObj* pargCOcrZonalSettingsData);
    /**
     * \brief Destructor
     */
    inline virtual ~COcrZonalSettings();
    /**
     * \brief Creates a new instance of this class
     */
    static COcrZonalSettings Create();
    /**
     * \brief Gets the associated ocr context.
     * 
     * The ocr context allows specifying options like languages to detect. See \see COcrContext for more details
     *
     * \return Associated ocr context
     */
    COcrContext GetContext() const;
    /**
     * \brief Sets the associated ocr context.
     * 
     * The ocr context allows specifying options like languages to detect. See \see COcrContext for more details
     *
     * \param argContext Associated ocr context
     */
    void SetContext(const COcrContext& argContext);
    /**
     * \brief Gets the array of zones where text recognition will be executed using the associated context.
     * 
     * \return Array of zones where text detection will be run
     */
    COcrZoneDescriptionArray GetZones() const;
    /**
     * \brief Sets the array of zones where text recognition will be executed using the associated context.
     * 
     * Setting one or more zones with coordinates outside the input page/image bounds will trigger an exception during text recognition. 
     *
     * \param argxZones Array of zones where text detection will be run
     */
    void SetZones(const COcrZoneDescriptionArray& argxZones);
  private:
    // For internal use only
    COcrZonalSettingsData& TypedObject() const
    {
      return (COcrZonalSettingsData&)Object();
    };
  };

  typedef TObjPtrArray<COcrZonalSettings> COcrZonalSettingsArray;
	
  /*
   *
   */
  inline COcrZonalSettings::COcrZonalSettings()
  {
  }
  /*
   *
   */
  inline COcrZonalSettings::COcrZonalSettings(const COcrZonalSettings& argCOcrZonalSettings)
    : CObjPtr((CObjPtr &)argCOcrZonalSettings)
  {
  }
  /*
   *
   */
  inline COcrZonalSettings::COcrZonalSettings(CObj* pargCOcrZonalSettingsData)
    : CObjPtr(pargCOcrZonalSettingsData)
  {
  }
  /*
   *
   */
  inline COcrZonalSettings::~COcrZonalSettings()
  {
  }
}
#endif // _COcrZonalSettings_h_
