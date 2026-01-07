/**
 * \file CFormPasswordField.h
 * Interface for a CFormPasswordField.
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef __CFormPasswordField_h__
#define __CFormPasswordField_h__

#include "CFormField.h"

namespace IDRS
{
  class CFormFieldData;
  class CFormPasswordFieldData;
  /**
   * Class CFormPasswordField represents a password input form field.
   */
  class IDRSKRN_API CFormPasswordField : public CFormField
  {
  public:
    /**
     * \brief Default constructor
     */
    inline CFormPasswordField( );
    /**
     * \brief Copy constructor
     *
     * \param argFormField Object to copy (shallow copy)
     */
    inline CFormPasswordField( const CFormPasswordField& argFormField );
    /**
     * \brief Copy constructor
     *
     * \param argFormField Object to copy (shallow copy)
     */
    inline CFormPasswordField( const CFormField& argFormField );
    /**
     * \brief CFormPasswordField constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CFormPasswordField( CFormPasswordFieldData* pObj );
    /**
     * \brief CFormPasswordField destructor
     */
    inline virtual ~CFormPasswordField( );
    /**
     * \brief Creates an new CFormPasswordField element.
     *
     * \return new CFormPasswordField instance.
     */
    static CFormPasswordField Create( );
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
     * \brief GetMaxLength gets the maximum number of chars allowed in the field
     *
     * \return The number of chars that the field can hold or zero if unlimited.
     */
    IDRS_UINT GetMaxLength( ) const;
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
     * \brief SetMaxLenght sets the maximum number of chars allowed in the field
     *
     * \param argMaxLength Number of chars that the field can hold or zero for unlimited (default: 0).
     */
    void SetMaxLength( const IDRS_UINT argMaxLength );
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
    CFormPasswordFieldData& TypedObject( ) const
    {
      return (CFormPasswordFieldData&)Object( );
    }
  };
  /*
   *
   */
  inline CFormPasswordField::CFormPasswordField( )
  {
  }
  /*
   *
   */
  inline CFormPasswordField::CFormPasswordField( const CFormPasswordField& objFormField ) :
    CFormField( (CFormField&)objFormField )
  {
  }
  /*
   *
   */
  inline CFormPasswordField::CFormPasswordField( const CFormField& objFormField ) :
    CFormField( objFormField )
  {
  }
  /*
   *
   */
  inline CFormPasswordField::CFormPasswordField( CFormPasswordFieldData* pObj ) :
    CFormField( (CFormFieldData*)pObj )
  {
  }
  /*
   *
   */
  inline CFormPasswordField::~CFormPasswordField( )
  {
  }
} // namespace IDRS
#endif // __CFormPasswordField_h__
