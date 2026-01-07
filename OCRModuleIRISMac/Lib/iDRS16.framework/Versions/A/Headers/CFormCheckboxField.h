/**
 * \file CFormCheckboxField.h
 * Interface for a CFormCheckboxField.
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef __CFormCheckboxField_h__
#define __CFormCheckboxField_h__

#include "CFormField.h"

namespace IDRS
{
  class CFormFieldData;
  class CFormCheckboxFieldData;
  /**
   * Class CFormPasswordField represents a checkbox form field.
   */
  class IDRSKRN_API CFormCheckboxField : public CFormField
  {
  public:
    /**
     * \brief Default constructor
     */
    inline CFormCheckboxField( );
    /**
     * \brief Copy constructor
     *
     * \param argFormField Object to copy (shallow copy)
     */
    inline CFormCheckboxField( const CFormCheckboxField& argFormField );
    /**
     * \brief Constructor from a base class
     *
     * \param argFormField Base class object
     */
    inline CFormCheckboxField( const CFormField& argFormField );
    /**
     * \brief CFormCheckboxField constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CFormCheckboxField( CFormCheckboxFieldData* pObj );
    /**
     * \brief CFormCheckboxField destructor
     */
    inline virtual ~CFormCheckboxField( );
    /**
     * \brief Creates an new CFormCheckboxField element.
     *
     * \return new CFormCheckboxField instance.
     */
    static CFormCheckboxField Create( );
    /**
     * \brief GetValue returns the value assigned to the field
     *
     * \return The field's assigned value
     */
    IDRS_BOOL GetValue( ) const;
    /**
     * \brief GetDefaultValue returns the default value of the field
     *
     * \return The field's default value
     */
    IDRS_BOOL GetDefaultValue( ) const;
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
    void SetValue( const IDRS_BOOL argValue );
    /**
     * \brief SetDefaultValue sets the field's default value
     *
     * \param argValue The default value to be set for the field
     */
    void SetDefaultValue( const IDRS_BOOL argValue );
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
    CFormCheckboxFieldData& TypedObject( ) const
    {
      return (CFormCheckboxFieldData&)Object( );
    }
  };
  /*
   *
   */
  inline CFormCheckboxField::CFormCheckboxField( )
  {
  }
  /*
   *
   */
  inline CFormCheckboxField::CFormCheckboxField( const CFormCheckboxField& objFormField ) :
    CFormField( (CFormField&)objFormField )
  {
  }
  /*
   *
   */
  inline CFormCheckboxField::CFormCheckboxField( const CFormField& objFormField ) :
    CFormField( objFormField )
  {
  }
  /*
   *
   */
  inline CFormCheckboxField::CFormCheckboxField( CFormCheckboxFieldData* pObj ) :
    CFormField( (CFormFieldData*)pObj )
  {
  }
  /*
   *
   */
  inline CFormCheckboxField::~CFormCheckboxField( )
  {
  }
} // namespace IDRS
#endif // __CFormCheckboxField_h__
