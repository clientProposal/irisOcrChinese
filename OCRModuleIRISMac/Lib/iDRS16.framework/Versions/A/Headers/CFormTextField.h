/**
 * \file CFormTextField.h
 * Interface for the CFormTextField class.
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef __CFormTextField_h__
#define __CFormTextField_h__

#include "CFormField.h"
#include "idrsstd.h"


namespace IDRS
{
  class CFormFieldData;
  class CFormTextFieldData;
  /**
   * Class CFormTextField represents a text input form field.
   */
  class IDRSKRN_API CFormTextField : public CFormField
  {
  public:
    /**
     * \brief Default constructor
     */
    inline CFormTextField();
    /**
     * \brief Copy constructor
     *
     * \param argFormField Object to copy (shallow copy)
     */
    inline CFormTextField( const CFormTextField& argFormField );
    /**
     * \brief Copy constructor
     *
     * \param argFormField Object to copy (shallow copy)
     */
    inline CFormTextField( const CFormField& argFormField );
    /**
     * \brief CFormTextField constructor that initializes an object with a data object
     * 
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CFormTextField( CFormTextFieldData* pObj );
    /**
     * \brief CFormTextField destructor
     */
    inline virtual ~CFormTextField( );
    /**
     * \brief Creates an new CFormTextField element.
     *
     * \return new CFormTextField instance.
     */
    static CFormTextField Create( );
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
     * \brief GetMultiline gets a boolean flag specifying wether the input allows multi-line editing
     */
    IDRS_BOOL GetMultiline( ) const;
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
     * \brief SetMultiline Sets the boolan flag for the multi-line property
     *
     * \param bValue Multi-line flag
     */
    void SetMultiline( const IDRS_BOOL bValue );
    /**
     * \brief SetMaxLength sets the maximum number of chars allowed in the field
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
    CFormTextFieldData& TypedObject( ) const
    {
      return (CFormTextFieldData& )Object( );
    }
  };
  /*
   *
   */
  inline CFormTextField::CFormTextField( )
  {
  }
  /*
   *
   */
  inline CFormTextField::CFormTextField( const CFormTextField& objFormField ) :
    CFormField( (CFormField&) objFormField )
  {
  }
  /*
   *
   */
  inline CFormTextField::CFormTextField( const CFormField& objFormField ) :
    CFormField( objFormField )
  {
  }
  /*
   *
   */
  inline CFormTextField::CFormTextField( CFormTextFieldData* pObj ) : 
    CFormField ( (CFormFieldData*) pObj )
  {
  }
  /*
   *
   */
  inline CFormTextField::~CFormTextField( )
  {
  }
} // namespace IDRS
#endif // __CFormTextField_h__
