/**
 * \file CFormDropdownField.h
 * Interface of the class that represents a dropdown form field.
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef __CFormDropdownField_h__
#define __CFormDropdownField_h__

#include "CFormField.h"
#include "CFormFieldOptionItem.h"

namespace IDRS
{
  class CFormFieldData;
  class CFormDropdownFieldData;

  /**
   * \brief Class that represents a Dropdown form field with an optional text input (Combo-box mode).
   */
  class IDRSKRN_API CFormDropdownField : public CFormField
  {
  public:
    /**
     * \brief CFormDropDownField constructor
     */
    inline CFormDropdownField( );
    /**
     * \brief Copy constructor
     *
     * \param argFormField Object to copy (shallow copy)
     */
    inline CFormDropdownField( const CFormDropdownField& argFormField );
    /**
     * \brief Constructor from base class
     *
     * \param argFormField Base class object 
     */
    inline CFormDropdownField( const CFormField& argFormField );
    /**
     * \brief CFormDropdownField constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CFormDropdownField( CFormDropdownFieldData* pObj );
    /**
     * \brief CFormDropDownField destructor
     */
    inline virtual ~CFormDropdownField( );
    /**
     * \brief Creates an new CFormDropdownField element.
     *
     * \return new CFormDropdownField instance.
     */
    static CFormDropdownField Create( );
    /**
     * \brief GetValue returns the value assigned to the field
     *
     * \return The field's assigned value
     */
    const idrs_string &GetValue( ) const;
    /**
     * \brief GetDefaultValue returns the default value of the field
     *
     * \return The field's default value
     */
    const idrs_string &GetDefaultValue( ) const;
    /**
     * \brief Gets a boolan flag specifying wether the Dropdown includes an editable text box.
     *
     * \return The Editable flag value.
     */
    IDRS_BOOL GetEditable( ) const;
    /**
     * GetOptionItems returns the array of option items
     *
     * \return The option items
     */
    CFormFieldOptionItemArray GetOptionItems( ) const;
    /**
     * GetSelectedItem returns the read-only list of selected items
     *
     * \return read-only array containing the selected option items.
     */
    CFormFieldOptionItem GetSelectedItem( ) const;
    /**
     * GetDefaultSelectedItem gets the option item choosen as default value for the field.
     *
     * \return Item selected as default value
     */
    CFormFieldOptionItem GetDefaultSelectedItem( ) const;
    /**
     * \brief GetBoundingBox returns the bounding box of the field.
     *
     * \return IDRS_RECT containing the bounding box
     */
    IDRS_RECT GetBoundingBox( ) const;
    /**
     * \brief GetAlternateName returns the field alternate name.
     *
     * \return String containing the alternate name
     */
    const idrs_string &GetAlternateName( ) const;
    /**
     * \brief SetValue assigns a value to the field
     *
     * \param argValue The value to be assigned to the field
     */
    void SetValue( const idrs_string &argValue );
    /**
     * \brief SetDefaultValue sets the field's default value
     *
     * \param argValue The default value to be set for the field
     */
    void SetDefaultValue( const idrs_string &argValue );
    /**
     * \brief Sets the flag for the Editable property.
     *
     * \param bValue Editable flag
     */
    void SetEditable( const IDRS_BOOL bValue );
    /**
     * SetSelectedItem selects the option item given as parameter.
     *
     * \pre GetOptionItems().Contains ( argOptionItems ) == IDRS_TRUE
     *
     * \param argOptionItem Object to be selected
     */
    void SetSelectedItem( const CFormFieldOptionItem& argOptionItem );
    /**
     * SetDefaultSelectedItem sets the option item choosen as default value for the field.
     *
     * \pre GetOptionItems().Contains ( argOptionItems ) == IDRS_TRUE
     *
     * \param argOptionItem Object to be chosen as default value
     */
    void SetDefaultSelectedItem( const CFormFieldOptionItem& argOptionItem );
    /**
     * \brief SetBoundingBox sets the bounding box of the field.
     *
     * \param stBoundingBox New bounding box of the field
     */
    void SetBoundingBox( const IDRS_RECT& stBoundingBox );
    /**
     * \brief SetAlternateName sets the field alternate name
     *
     * \param strAlternateName String containing the alternate name
     */
    void SetAlternateName( const idrs_string &strAlternateName );

  private:
    //! Internal use 
    CFormDropdownFieldData& TypedObject( ) const
    {
      return (CFormDropdownFieldData&)Object( );
    }
  };
  /*
   *
   */
  inline CFormDropdownField::CFormDropdownField( )
  {
  }
  /*
   *
   */
  inline CFormDropdownField::CFormDropdownField( const CFormDropdownField& argFormField ) :
    CFormField( (CFormField&) argFormField )
  {
  }
  /*
   *
   */
  inline CFormDropdownField::CFormDropdownField( const CFormField& argFormField ) :
    CFormField( argFormField )
  {
  }
  /*
   *
   */
  inline CFormDropdownField::CFormDropdownField( CFormDropdownFieldData* pObj ) :
    CFormField( (CFormFieldData*) pObj )
  {
  }
  /*
   *
   */
  inline CFormDropdownField::~CFormDropdownField( )
  {
  }

} // namespace IDRS
#endif // __CFormDropdownField_h__
