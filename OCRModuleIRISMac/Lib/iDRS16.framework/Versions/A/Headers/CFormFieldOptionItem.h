/**
 * \file CFormFieldOptionItem.h
 * Data class that represents an item value in a choice form field.
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef __CFormFieldOptionItem_h__
#define __CFormFieldOptionItem_h__

#include "TObjPtrArray.h"

namespace IDRS
{
  class CFormFieldOptionItemData;
  class idrs_string;
  /**
   * CFormFieldValueData represents the value of an item of a choice form field.
   */
  class IDRSKRN_API CFormFieldOptionItem : public CObjPtr
  {
  public:
    /**
     * \brief CFormFieldOptionItem default constructor.
     */
    inline CFormFieldOptionItem( );
    /**
     * \brief Copy constructor
     *
     * \param argFormFieldOptionItem Object to copy (shallow copy)
     */
    inline CFormFieldOptionItem( const CFormFieldOptionItem& argFormFieldOptionItem );
    /**
     * \brief CFormFieldOptionItem constructor that initializes an object with a data object.
     *
     * \param pObj Pointer to an object representing the base data class
     */
    inline CFormFieldOptionItem( CObj* pObj );
    /**
     * \brief CFormFieldOptionItem destructor.
     */
    inline virtual ~CFormFieldOptionItem( );
    /**
     * \brief Creates an new CFormFieldOptionItem element.
     *
     * \return new CFormFieldOptionItem instance.
     */
    static CFormFieldOptionItem Create( );
    /**
     * \brief SetValue sets the option item value.
     *
     * This property is the display value of the option item. Furthermore, unless 
     * the ExportValue property is also set, it represents the actually exported value.
     * 
     * \param argValue Value to be assigned to the option item.
     */
    void SetValue( const idrs_string &argValue );
    /**
     * \brief SetExportValue sets the export value for the option item.
     *
     * Whe this property is set, it represents the exported value for the field option.
     * 
     * \param argValue Export value of the option item.
     */
    void SetExportValue( const idrs_string &argValue );
    /**
     * \brief GetValue gets the option item value.
     *
     * \return The value assigned to this option item.
     */
    const idrs_string &GetValue( ) const;
    /**
     * \brief GetExportValue gets the export value of the option item.
     *
     * \return The export value of this option item.
     */
    const idrs_string &GetExportValue( ) const;

  private:
    //! Internal use 
    CFormFieldOptionItemData& TypedObject( ) const
    {
      return (CFormFieldOptionItemData&)Object( );
    };
  };
  /**
   * Form field option items array
   */
  typedef TObjPtrArray< CFormFieldOptionItem > CFormFieldOptionItemArray;
  /*
   *
   */
  inline CFormFieldOptionItem::CFormFieldOptionItem( )
  {
  }
  /*
   *
   */
  inline CFormFieldOptionItem::CFormFieldOptionItem( const CFormFieldOptionItem& argFormFieldOptionItem ) :
    CObjPtr ( (CObjPtr &) argFormFieldOptionItem )
  {
  }
  /*
   *
   */
  inline CFormFieldOptionItem::CFormFieldOptionItem( CObj* pObj ) :
    CObjPtr( pObj )
  {
  }
  /*
   *
   */
  inline CFormFieldOptionItem::~CFormFieldOptionItem( )
  {
  }
} // namespace IDRS
#endif // __CFormFieldOptionItem_h__
