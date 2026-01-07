/**
 * \file CFormListBoxField.h
 * Interface of the class that represents a list box form field.
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef __CFormListBoxField_h__
#define __CFormListBoxField_h__

#include "CFormField.h"
#include "CFormFieldOptionItem.h"

namespace IDRS
{
  class CFormFieldData;
  class CFormListBoxFieldData;

  /**
   * \brief Class that represents a list box form field.
   */
  class IDRSKRN_API CFormListBoxField : public CFormField
  {
  public:
    /**
     * \brief CFormDropDownField constructor
     */
    inline CFormListBoxField( );
    /**
     * \brief Copy constructor
     *
     * \param argFormField Object to copy (shallow copy)
     */
    inline CFormListBoxField( const CFormListBoxField& argFormField );
    /**
     * \brief Copy constructor
     *
     * \param argFormField Object to copy (shallow copy)
     */
    inline CFormListBoxField( const CFormField& argFormField );
    /**
     * \brief CFormDropdownField constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CFormListBoxField( CFormListBoxFieldData* pObj );
    /**
     * \brief CFormDropDownField destructor
     */
    inline virtual ~CFormListBoxField( );
    /**
     * \brief Creates an new CFormListBoxField element.
     *
     * \return new CFormListBoxField instance.
     */
    static CFormListBoxField Create( );
    /**
     * GetOptionItems returns the array of option items
     *
     * \return The option items
     */
    CFormFieldOptionItemArray GetOptionItems( ) const;
    /**
     * GetSelectedItems returns the read-only list of selected items
     *
     * \return read-only array containing the selected option items.
     */
    CFormFieldOptionItemArray GetSelectedItems( ) const;
    /**
     * GetDefaultSelectedItem gets the option item choosen as default value for the field.
     *
     * \return Item selected as default value
     */
    CFormFieldOptionItemArray GetDefaultSelectedItems( ) const;
    /**
     * \brief GetMultiSelect returns the flag that indicates wether the multiple selection is allowed.
     * 
     * \return The boolean flag value.
     */
    IDRS_BOOL GetMultiSelect( ) const;
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
     * SetSelectedItem adds the given option item to the selection.
     *
     * \pre GetOptionItems().Contains ( argOptionItems ) == IDRS_TRUE
     *
     * \param argOptionItem Object to be added to the selection
     */
    void SetSelectedItem( const CFormFieldOptionItem& argOptionItem );
    /**
     * SetDefaultSelectedItem adds the given option item to the selection.
     *
     * \pre GetOptionItems().Contains ( argOptionItems ) == IDRS_TRUE
     *
     * \param argOptionItem Object to be chosen as default value.
     */
    void SetDefaultSelectedItem( const CFormFieldOptionItem& argOptionItem );
    /**
     * RemoveSelectedItem removes the given option item from the selection.
     *
     * \pre GetOptionItems().Contains ( argOptionItem ) == IDRS_TRUE
     *
     * \param argOptionItem Object to be removed from the selection.
     */
    void RemoveSelectedItem( const CFormFieldOptionItem& argOptionItem );
    /**
     * RemoveDefaultSelectedItem removes the given option item from the default selection.
     *
     * \pre GetOptionItems().Contains ( argOptionItem ) == IDRS_TRUE
     *
     * \param argOptionItem Object to be removed from default selection.
     */
    void RemoveDefaultSelectedItem( const CFormFieldOptionItem& argOptionItem );
    /**
     * ResetSelectedItems Removes all the items from the current selection.
     */
    void ResetSelectedItems( );
    /**
     * ResetDefaultSelectedOptionItem remove all the items from the default selection.
     */
    void ResetDefaultSelectedItems( );
    /**
     * \brief SetMultiSelect sets the MultiSelect property.
     * 
     * \param argValue The flag boolean value.
     */
    void SetMultiSelect( const IDRS_BOOL argValue );
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
    CFormListBoxFieldData& TypedObject( ) const
    {
      return (CFormListBoxFieldData&)Object( );
    }
  };
  /*
   *
   */
  inline CFormListBoxField::CFormListBoxField( )
  {
  }
  /*
   *
   */
  inline CFormListBoxField::CFormListBoxField( const CFormListBoxField& argFormField ) :
    CFormField( (CFormField&)argFormField )
  {
  }
  /*
   *
   */
  inline CFormListBoxField::CFormListBoxField( const CFormField& argFormField ) :
    CFormField( argFormField )
  {
  }
  /*
   *
   */
  inline CFormListBoxField::CFormListBoxField( CFormListBoxFieldData* pObj ) :
    CFormField( (CFormFieldData*)pObj )
  {
  }
  /*
   *
   */
  inline CFormListBoxField::~CFormListBoxField( )
  {
  }

} // namespace IDRS
#endif // __CFormListBoxField_h__
