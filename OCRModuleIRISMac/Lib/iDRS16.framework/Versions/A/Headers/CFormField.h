/**
 * \file CFormField.h
 * Base class that represents a form field.
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef __CFormField_h__
#define __CFormField_h__

#include "EnumDefinitions.h"
#include "CPageCustomData.h"
#include "TObjPtrArray.h"

namespace IDRS
{
  class CFormFieldData;
  class CFormFieldStyle;
  class CFormAction;
  class idrs_string;
  /**
   * \brief Class CFormField represents the base class for all types of form fields available in iDRS SDK.
   */
  class IDRSKRN_API CFormField : public CPageCustomData
  {

  public:
    /**
     * \brief Default constructor
     */
    inline CFormField( );
    /**
     * \brief Copy constructor
     * 
     * \param argFormField Object to copy (shallow copy)
     */
    inline CFormField( const CFormField &argFormField );
    /**
     * \brief CFormField constructor that initializes an object with a data object.
     * 
     * \param pObj Pointer to an object representing the data class
     */
    inline CFormField( CFormFieldData *pObj );
    /**
     * \brief CFormField constructor that initializes an object with a data object.
     *
     * \param pObj Pointer to an object representing the base data class
     */
    inline CFormField( CObj* pObj );
    /**
     * \brief CFormField destructor
     */
    inline virtual ~CFormField( );
    /**
     * \brief Creates a new Form Field element of the given type.
     * 
     * \param argFormFieldType Type of the form field to be created
     * 
     * \return New form field instance.
     */
    static CFormField Create( const FormFieldType argFormFieldType );
    /**
     * \brief Creates a new Form Field element of the given type with the given bounding box.
     *
     * \param argFormFieldType Type of the form field to be created
     * \param argBoundingBox The bounding box of the field element
     *
     * \note
     * This method only supports types that allow specifying a bounding box, that is:
     * [ Text, CombedText, RichText, Password, Checkbox, Dropdown, ListBox ]
     * 
     * \return New form field instance.
     */
    static CFormField Create( const FormFieldType argFormFieldType, const IDRS_RECT &argBoundingBox );
    /**
     * \brief GetFormFieldType returns the form field type.
     *
     * \return The FormFieldType value
     */
    FormFieldType GetFormFieldType( ) const;
    /**
     * \brief Get the parent group
     * 
     * \return The parent form field if this field is not a root element. A null object otherwise.
     */
    virtual CFormField GetParent( ) const;
    /**
     * \brief GetName returns the field partial name.
     *
     * \note The full name is represented by the combined names from all parent CFormFieldGroup
     * elements starting at the topmost one in the hierarchy.
     *
     * \return String containing the partial name
     */
    const idrs_string &GetName( ) const;
    /**
     * \brief GetCalculationPriority retrieves the priority for ordering the calculated fields.
     *
     * \return The calculation priority property value.
     */
    IDRS_INT GetCalculationPriority( ) const;
    /**
     * \brief GetStyle returns the style associated with this field.
     *
     * \return The field style object.
     */
    CFormFieldStyle GetStyle( ) const;
    /**
     * \brief GetFormAction returs the action bound to the specified event
     *
     * \param argEvent Event that triggers the action
     *
     * \return The CFormAction smart pointer. Contains a NULL pointer if no action was set.
     */
    CFormAction GetFormAction( const FormFieldEventType argEvent ) const;
    /**
     * \brief SetName sets the field partial name.
     *
     * \note The full name is represented by the combined names from all parent CFormFieldGroup
     * elements starting at the topmost one in the hierarchy.
     *
     * \param strName String containing the partial name
     */
    void SetName( const idrs_string &strName );
    /**
     * \brief SetCalculationPriority sets the priority for ordering the evaluation of calculated fields.
     *
     * \param argPriority The priority value. Any arbitrary integer value is allowed, where an higher 
     *                    value is considered as higher priority (default: 0).
     */
    void SetCalculationPriority( const IDRS_INT argPriority );
    /**
     * \brief GetStyle returns the style associated with this field.
     *
     * \param argStyle The field style object.
     */
    void SetStyle( const CFormFieldStyle& argStyle );
    /**
     * \brief SetFormAction binds an action to the field for the specified event
     *
     * \param argEvent Event that triggers the action
     * \param argAction Form action to execute for the specified event.
     */
    void SetFormAction( const FormFieldEventType argEvent, const CFormAction& argAction );
    /**
     * \brief UnbindFormAction unbinds the action associated with the specified event
     *
     * \note
     * The method has no effect if no action was set for the given event.
     *
     * \param argEvent Event that triggers the action
     */
    void UnbindFormAction( const FormFieldEventType argEvent );

  private:
    //! Internal use 
    CFormFieldData& TypedObject( ) const
    {
      return (CFormFieldData&)Object( );
    };
  };
  /*
   * 
   */
  typedef TObjPtrArray<CFormField> CFormFieldArray;
  /*
   *
   */
  inline CFormField::CFormField()
  {
  }
  /*
   *
   */
  inline CFormField::CFormField( const CFormField& argFormField ) :
    CPageCustomData( (CPageCustomData&) argFormField )
  {
  }
  /*
   *
   */
  inline CFormField::CFormField( CFormFieldData* pObj ) :
    CPageCustomData( (CObj*) pObj )
  {
  }
  /*
   *
   */
  inline CFormField::CFormField( CObj* pObj ) :
    CPageCustomData( pObj )
  {
  }
  /*
   *
   */
  inline CFormField::~CFormField( )
  {
  }

} // namespace IDRS
#endif // __CFormField_h__
