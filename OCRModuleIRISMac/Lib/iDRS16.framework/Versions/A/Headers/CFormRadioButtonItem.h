/**
 * \file CFormRadioButtonItem.h
 * Interface for a CFormRadioButtonItem.
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef __CFormRadioButtonItem_h__
#define __CFormRadioButtonItem_h__

#include "EnumDefinitions.h"
#include "CObjPtr.h"
#include "TObjPtrArray.h"

namespace IDRS
{
  class CFormFieldData;
  class CFormFieldStyle;
  class CFormAction;
  class CFormRadioButtonItemData;
  class CFormRadioButtonField;
  class idrs_string;
  /**
   * Class CFormRadioButtonField represents a radio button form field.
   */
  class IDRSKRN_API CFormRadioButtonItem : public CObjPtr
  {
  public:
    /**
     * \brief Default constructor
     */
    inline CFormRadioButtonItem( );
    /**
     * \brief Copy constructor
     *
     * \param argFormField Object to copy (shallow copy)
     */
    inline CFormRadioButtonItem( const CFormRadioButtonItem& argFormField );
    /**
     * \brief CFormRadioButtonItem constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CFormRadioButtonItem( CFormRadioButtonItemData* pObj );
    /**
     * \brief CFormRadioButtonItem constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CFormRadioButtonItem( CObj* pObj );
    /**
     * \brief CFormRadioButtonField destructor
     */
    inline virtual ~CFormRadioButtonItem( );
    /**
     * \brief Creates an new CFormRadioButtonItem element.
     *
     * \return new CFormRadioButtonItem instance.
     */
    static CFormRadioButtonItem Create( );
    /**
     * \brief GetName returns the radio button item name.
     * 
     * The item name is used to identify the radio button value. Two or more items 
     * are allowed to share a same name; they are then representing a group of related items for 
     * the "SetInUnison" mode.
     *
     * \return String containing the partial name
     */
    const idrs_string &GetName( ) const;
    /**
     * \brief GetBoundingBox returns the bounding box of the field.
     *
     * \return IDRS_RECT containing the bounding box
     */
    IDRS_RECT GetBoundingBox( ) const;
    /**
     * \brief Get the parent field
     *
     * \return The parent form field if this field is not a root element. A null object otherwise.
     */
    virtual CFormRadioButtonField GetParent( ) const;
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
     * \brief Read-only property indicating wether the item is currently selected.
     * 
     * \pre GetParent().IsNull() == IDRS_FALSE
     * 
     * \return IDRS_TRUE when the item is selected, IDRS_FALSE otherwise.
     */
    IDRS_BOOL GetState( ) const;
    /**
     * \brief Read-only property indicating wether the item is selected by default.
     *
     * \pre GetParent().IsNull() == IDRS_FALSE
     *
     * \return IDRS_TRUE when the item is selected by default, IDRS_FALSE otherwise.
     */
    IDRS_BOOL GetDefaultState( ) const;
    /**
     * \brief SetName sets the field partial name.
     *
     * \param strName String containing the partial name
     */
    void SetName( const idrs_string &strName );
    /**
     * \brief SetBoundingBox sets the bounding box of the field.
     *
     * \param stBoundingBox New bounding box of the field
     */
    void SetBoundingBox( const IDRS_RECT& stBoundingBox );
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
    CFormRadioButtonItemData& TypedObject( ) const
    {
      return (CFormRadioButtonItemData&)Object( );
    }
  };
  //
  typedef TObjPtrArray<CFormRadioButtonItem> CFormRadioButtonItemArray;
  /*
   *
   */
  inline CFormRadioButtonItem::CFormRadioButtonItem( )
  {
  }
  /*
   *
   */
  inline CFormRadioButtonItem::CFormRadioButtonItem( const CFormRadioButtonItem& objFormField ) :
    CObjPtr( (CObjPtr&)objFormField )
  {
  }
  /*
   *
   */
  inline CFormRadioButtonItem::CFormRadioButtonItem( CFormRadioButtonItemData* pObj ) :
    CObjPtr( (CObj*)pObj )
  {
  }
  /*
   *
   */
  inline CFormRadioButtonItem::CFormRadioButtonItem( CObj* pObj ) :
    CObjPtr( pObj )
  {
  }
  /*
   *
   */
  inline CFormRadioButtonItem::~CFormRadioButtonItem( )
  {
  }
} // namespace IDRS
#endif // __CFormRadioButtonItem_h__
