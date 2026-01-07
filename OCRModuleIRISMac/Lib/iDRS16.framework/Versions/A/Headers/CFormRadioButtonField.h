/**
 * \file CFormRadioButtonField.h
 * Interface for a CFormRadioButtonField class.
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef __CFormRadioButtonGroup_h__
#define __CFormRadioButtonGroup_h__

#include "CFormField.h"
#include "CFormRadioButtonItem.h"

namespace IDRS
{
  class CFormFieldData;
  class CFormRadioButtonFieldData;
  
  /**
   * Class CFormRadioButtonGroup represents a group of related radio button fields.
   */
  class IDRSKRN_API CFormRadioButtonField : public CFormField
  {
  public:
    /**
     * \brief Default constructor
     */
    inline CFormRadioButtonField( );
    /**
     * \brief Copy constructor
     *
     * \param argFormField Object to copy (shallow copy)
     */
    inline CFormRadioButtonField( const CFormRadioButtonField& argFormField );
    /**
     * \brief Copy constructor
     *
     * \param argFormField Object to copy (shallow copy)
     */
    inline CFormRadioButtonField( const CFormField& argFormField );
    /**
     * \brief CFormRadioButtonField constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CFormRadioButtonField( CFormRadioButtonFieldData* pObj );
    /**
     * \brief Creates an new CFormRadioButtonGroup element.
     *
     * \return new CFormRadioButtonGroup instance.
     */
    static CFormRadioButtonField Create( );
    /**
     * \brief CFormRadioButtonGroup destructor
     */
    inline virtual ~CFormRadioButtonField( );
    /**
     * \brief GetAlternateName returns the field alternate name.
     *
     * \return String containing the alternate name
     */
    const idrs_string &GetAlternateName( ) const;
    /**
     * \brief GetToggleOffAllowed Gets the flag that indicated whether a field can be toggled off
     *
     * When the flag is not set, the user can only toggle On a radio button, to deselect another. If the
     * flag is set, the user can toggle Off a radio button, meaning that all radio buttons of the set are
     * allowed to be Off. Note that the flag is reflected in the output document, but does not apply
     * for the iDRS API.
     *
     * \return The ToggleOffAllowed flag value.
     */
    IDRS_BOOL GetToggleOffAllowed( ) const;
    /**
     * \brief GetToggleInUnison Gets the flag that indicates whether all the fields are updated together.
     *
     * \return The ToggleInUnison flag value.
     */
    IDRS_BOOL GetToggleInUnison( ) const;
    /**
     * \brief GetRadioButtons returns the list of radio button elements
     *
     * \return the array containing the CFormRadioButtonField elements
     */
    CFormRadioButtonItemArray GetRadioButtonItems( ) const;
    /**
     * \brief Returns the currently selected item
     *
     * \note
     * In case the 'ToggleInUnison' flag is set and other items are defined with the same name, they
     * are also considered as selected. However this method only return the last element that was 
     * explicitly selected. To identify all elements having a given state, please refer to the State 
     * property available from each individual item.
     * 
     * \return The last element explicitly selected by SetSelectedItem().
     */
    CFormRadioButtonItem GetSelectedItem( ) const;
    /**
     * \brief Returns the currently selected item
     *
     * \note
     * In case the 'ToggleInUnison' flag is set and other items are defined with the same name, they
     * are also considered as selected. However this method only return the last element that was
     * explicitly selected. To identify all elements having a given state, please refer to the State
     * property available from each individual item.
     *
     * \return The last element explicitly selected by SetDefaultSelectedItem().
     */
    CFormRadioButtonItem GetDefaultSelectedItem( ) const;
    /**
     * \brief SetAlternateName sets the field alternate name
     *
     * \param strAlternateName String containing the alternate name
     */
    void SetAlternateName( const idrs_string &strAlternateName );
    /**
     * \brief SetToggleOffAllowed Sets the AllowToggleOff flag value
     * 
     * \note Setting this flag to IDRS_TRUE resets the SetInUnison flag value to IDRS_FALSE.
     *
     * \param bValue The AllowsToggleOff flag value.
     */
    void SetToggleOffAllowed( const IDRS_BOOL bValue );
    /**
     * \brief SetToggleInUnison Sets the SetInUnison flag value
     * 
     * \note Setting this flag to IDRS_TRUE resets the AllowsToggleOff flag value to IDRS_FALSE.
     *
     * \param bValue The ToggleInUnison flag value.
     */
    void SetToggleInUnison( const IDRS_BOOL bValue );

    /**
     * \brief Selects the radio button given as parameter
     *
     * \param objRadioButton The CFormRadioButtonField element
     */
    void SetSelectedItem( const CFormRadioButtonItem& objRadioButton );
    /**
     * \brief Sets the given radio button as the default value
     *
     * \param objRadioButton The CFormRadioButtonField element
     */
    void SetDefaultSelectedItem( const CFormRadioButtonItem& objRadioButton );

  private:
    //! Internal use 
    CFormRadioButtonFieldData& TypedObject( ) const
    {
      return (CFormRadioButtonFieldData&)Object( );
    }
  };
  /*
   *
   */
  inline CFormRadioButtonField::CFormRadioButtonField( )
  {
  }
  /*
   *
   */
  inline CFormRadioButtonField::CFormRadioButtonField( const CFormRadioButtonField& objFormField ) :
    CFormField( (CFormField&)objFormField )
  {
  }
  /*
   *
   */
  inline CFormRadioButtonField::CFormRadioButtonField( const CFormField& objFormField ) :
    CFormField( objFormField )
  {
  }
  /*
   *
   */
  inline CFormRadioButtonField::CFormRadioButtonField( CFormRadioButtonFieldData* pObj ) :
    CFormField( (CFormFieldData*)pObj )
  {
  }
  /*
   *
   */
  inline CFormRadioButtonField::~CFormRadioButtonField( )
  {
  }
} // namespace IDRS
#endif // __CFormRadioButtonGroup_h__
