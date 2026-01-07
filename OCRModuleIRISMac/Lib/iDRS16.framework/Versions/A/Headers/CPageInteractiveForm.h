/**
 * \file CPageInteractiveForm.h
 * Interface of the CPageInteractiveForm class.
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef __CPageInteractiveForm_h__
#define __CPageInteractiveForm_h__


#include "CFormField.h"
#include "CFormCheckboxField.h"
#include "CFormCombedTextField.h"
#include "CFormDropdownField.h"
#include "CFormFieldOptionItem.h"
#include "CFormFieldGroup.h"
#include "CFormFieldStyle.h"
#include "CFormListBoxField.h"
#include "CFormPasswordField.h"
#include "CFormRadioButtonField.h"
#include "CFormRadioButtonItem.h"
#include "CFormTextField.h"
#include "CFormJavaScriptAction.h"

namespace IDRS
{
  class CPageInteractiveFormData;
  /**
   * \brief Class CPageInteractiveForm represents the interactive form gathering all page's form fields.
   */
  class IDRSKRN_API CPageInteractiveForm : public CPageCustomData
  {
  public:
    /**
     * \brief Default constructor
     */
    inline CPageInteractiveForm( );
    /**
     * \brief Copy constructor
     * 
     * \param argForm Object to copy (shallow copy)
     */
    inline CPageInteractiveForm( const CPageInteractiveForm &argForm );
    /**
     * \brief CPageInteractiveForm constructor that initializes an object with a data object.
     * 
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageInteractiveForm( CPageInteractiveFormData *pObj );
    /**
     * \brief CPageInteractiveForm constructor that initializes an object with a data object.
     *
     * \param pObj Pointer to an object representing the base data class
     */
    inline CPageInteractiveForm( CObj* pObj );
    /**
     * \brief CPageInteractiveForm destructor
     */
    inline virtual ~CPageInteractiveForm( );
    /**
     * \brief Creates a new interactive form instance.
     * 
     * \return New interactive form instance.
     */
    static CPageInteractiveForm Create( );
    /**
     * \brief GetFormFields returns the form fields declared in this form.
     *
     * \return The array of CFormField elements
     */
    CFormFieldArray GetFormFields( ) const;
    /**
     * \brief GetDefaultFieldStyle returns the style applied to all form fields by default.
     *
     * \return The default style object if defined, an empty object otherwise.
     */
    CFormFieldStyle GetDefaultFieldStyle( ) const;
    /**
     * \brief SetDefaultFieldStyle sets the form field style applied by default.
     *
     * \param pobjFieldStyle The default style object
     */
    void SetDefaultFieldStyle( const CFormFieldStyle& pobjFieldStyle );

  private:
    //! Internal use 
    CPageInteractiveFormData& TypedObject( ) const
    {
      return (CPageInteractiveFormData&)Object( );
    };
  };
  /*
   *
   */
  inline CPageInteractiveForm::CPageInteractiveForm()
  {
  }
  /*
   *
   */
  inline CPageInteractiveForm::CPageInteractiveForm( const CPageInteractiveForm& argFormField ) :
    CPageCustomData( (CPageCustomData&) argFormField )
  {
  }
  /*
   *
   */
  inline CPageInteractiveForm::CPageInteractiveForm( CPageInteractiveFormData* pObj ) :
    CPageCustomData( (CObj*) pObj )
  {
  }
  /*
   *
   */
  inline CPageInteractiveForm::CPageInteractiveForm( CObj* pObj ) :
    CPageCustomData( pObj )
  {
  }
  /*
   *
   */
  inline CPageInteractiveForm::~CPageInteractiveForm( )
  {
  }

} // namespace IDRS
#endif // __CPageInteractiveForm_h__
