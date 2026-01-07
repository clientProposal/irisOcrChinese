/**
 * \file CFormCombedTextField.h
 * Interface for the CFormCombedTextField class.
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef __CFormCombedTextField_h__
#define __CFormCombedTextField_h__

#include "CFormField.h"

namespace IDRS
{
  class CFormFieldData;
  class CFormCombedTextFieldData;
  /**
   * Class CFormTextField represents a text input form field.
   */
  class IDRSKRN_API CFormCombedTextField : public CFormField
  {
  public:
    /**
     * \brief Default constructor
     */
    inline CFormCombedTextField( );
    /**
     * \brief Copy constructor
     *
     * \param argFormField Object to copy (shallow copy)
     */
    inline CFormCombedTextField( const CFormCombedTextField& argFormField );
    /**
     * \brief Constructor from base class
     *
     * \param argFormField Base class object
     */
    inline CFormCombedTextField( const CFormField& argFormField );
    /**
     * \brief CFormCombedTextField constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CFormCombedTextField( CFormCombedTextFieldData* pObj );
    /**
     * \brief CFormCombedTextField destructor
     */
    inline virtual ~CFormCombedTextField( );
    /**
     * \brief Creates an new CFormCombedTextField element.
     *
     * \return new CFormCombedTextField instance.
     */
    static CFormCombedTextField Create( );
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
     * Gets the number of parts composing the the combed text field
     *
     * \return The number of part the field is composed of.
     */
    IDRS_UINT GetPartsCount( ) const;
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
     * Sets the number of parts of the combed text field
     *
     * \param argCount Number of parts to be defined.
     */
    void SetPartsCount( const IDRS_UINT argCount );
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
    CFormCombedTextFieldData& TypedObject( ) const
    {
      return (CFormCombedTextFieldData&)Object( );
    }
  };
  /*
   *
   */
  inline CFormCombedTextField::CFormCombedTextField( )
  {
  }
  /*
   *
   */
  inline CFormCombedTextField::CFormCombedTextField( const CFormCombedTextField& objFormField ) :
    CFormField( (CFormField&)objFormField )
  {
  }
  /*
   *
   */
  inline CFormCombedTextField::CFormCombedTextField( const CFormField& objFormField ) :
    CFormField( objFormField )
  {
  }
  /*
   *
   */
  inline CFormCombedTextField::CFormCombedTextField( CFormCombedTextFieldData* pObj ) :
    CFormField( (CFormFieldData*)pObj )
  {
  }
  /*
   *
   */
  inline CFormCombedTextField::~CFormCombedTextField( )
  {
  }
} // namespace IDRS
#endif // __CFormCombedTextField_h__
