/**
 * \file CFormFieldStyle.h
 * Interface of the CFormFieldStyle class.
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef __CFormFieldStyle_h__
#define __CFormFieldStyle_h__

#include "EnumDefinitions.h"
#include "CObjPtr.h"
#include "TObjPtrArray.h"

namespace IDRS
{
  class CFormFieldStyleData;
  class CPageStyleFont;
  /**
   * \brief Class CFormFieldStyle represents the styling information applying to a group or a single form field (CFormField)
   */
  class IDRSKRN_API CFormFieldStyle : public CObjPtr
  {
  public:
    /**
     * \brief Default constructor
     */
    inline CFormFieldStyle( );
    /**
     * \brief Copy constructor
     * 
     * \param argFormFieldStyle Object to copy (shallow copy)
     */
    inline CFormFieldStyle( const CFormFieldStyle &argFormFieldStyle );
    /**
     * \brief CFormFieldStyle constructor that initializes an object with a data object.
     * 
     * \param pObj Pointer to an object representing the data class
     */
    inline CFormFieldStyle( CFormFieldStyleData *pObj );
    /**
     * \brief CFormFieldStyle constructor that initializes an object with a data object.
     *
     * \param pObj Pointer to an object representing the base data class
     */
    inline CFormFieldStyle( CObj* pObj );
    /**
     * \brief CFormFieldStyle destructor
     */
    inline virtual ~CFormFieldStyle( );
    /**
     * \brief Creates a new style element of the given type.
     * 
     * \return New form field instance.
     */
    static CFormFieldStyle Create( );
    /**
     * \brief GetTextColor returns the text color property.
     *
     * \note When the HasTextColor flag is not set the color value is undefined.
     * 
     * \return The text color color.
     */
    IDRS_COLOR GetTextColor( ) const;
    /**
     * \brief The boolean flag specifying wether the color has been defined.
     * 
     * \return The flag value.
     */
    IDRS_BOOL GetHasTextColor( ) const;
    /**
     * \brief GetBorderColor returns the border color property.
     *
     * \note When the HasBorderColor flag is not set the border color value is undefined.
     *
     * \return The text color color.
     */
    IDRS_COLOR GetBorderColor( ) const;
    /**
     * \brief The boolean flag specifying wether the border color has been defined.
     *
     * \return The flag value.
     */
    IDRS_BOOL GetHasBorderColor( ) const;
    /**
     * \brief GetBackgroundColor returns the background color property.
     *
     * \note When the HasBackgroundColor flag is not set the background color value is undefined.
     * 
     * \return The background color.
     */
    IDRS_COLOR GetBackgroundColor( ) const;
    /**
     * \brief GetHasBackgroundColor returns the boolean flag specifying wether the background color has been defined.
     * 
     * \return The flag value.
     */
    IDRS_BOOL GetHasBackgroundColor( ) const;
    /**
     * \brief GetBorderStyle returns the border style property.
     * 
     * \return The border style.
     */
    FormFieldBorderStyle GetBorderStyle( ) const;
    /**
     * \brief GetBorderWidth returns the border width property.
     * 
     * \return The border width value in pixels.
     */
    IDRS_INT GetBorderWidth( ) const;
    /**
     * \brief FormFieldTextAlignment returns the text alignement property.
     * 
     * \return The text alignment.
     */
    FormFieldTextAlignment GetTextAlignment( ) const;
    /**
     * \brief Sets the text color property.
     * 
     * \param argColor The color to be assigned for the text.
     * 
     * \note When setting the color value, the HasTextColor flag is automatically set to IDRS_TRUE.
     */
    void SetTextColor( const IDRS_COLOR& argColor );
    /**
     * \brief Sets the HasColor flag.
     * 
     * \param argValue The flag boolean value.
     */
    void SetHasTextColor( const IDRS_BOOL argValue );    
    /**
     * \brief Sets the border color property.
     * 
     * \param argColor The color to be assigned to the border.
     * 
     * \note When setting the color value, the HasBorderColor flag is automatically set to IDRS_TRUE.
     */
    void SetBorderColor( const IDRS_COLOR& argColor );
    /**
     * \brief Sets the HasBorderColor flag.
     * 
     * \param argValue The flag boolean value.
     */
    void SetHasBorderColor( const IDRS_BOOL argValue );
    /**
     * \brief Sets the field background color property.
     *
     * \param argColor The color to be assigned as background of the field.
     *
     * \note When setting the color value, the HasBackgroundColor flag is automatically set to IDRS_TRUE.
     */
    void SetBackgroundColor( const IDRS_COLOR& argColor );
    /**
     * \brief Sets the HasBackgroundColor flag.
     * 
     * \param argValue The flag boolean value.
     */
    void SetHasBackgroundColor( const IDRS_BOOL argValue );
    /**
     * \brief Sets the border style property.
     * 
     * \param argBorderStyle The border style.
     */
    void SetBorderStyle( const FormFieldBorderStyle& argBorderStyle );
    /**
     * \brief SetBorderWidth sets the border width in points.
     * 
     * \param argWidth The width value in pixels.
     */
    void SetBorderWidth( const IDRS_INT argWidth );
    /**
     * \brief Sets the text alignment property.
     * 
     * \param argTextAlignement The text alignment.
     */
    void SetTextAlignment( const FormFieldTextAlignment& argTextAlignement );


  private:
    //! Internal use 
    CFormFieldStyleData& TypedObject( ) const
    {
      return (CFormFieldStyleData&)Object( );
    };
  };
  typedef TObjPtrArray<CFormFieldStyle> CFormFieldStyleArray;
  /*
   *
   */
  inline CFormFieldStyle::CFormFieldStyle()
  {
  }
  /*
   *
   */
  inline CFormFieldStyle::CFormFieldStyle( const CFormFieldStyle& argFormFieldStyle ) :
    CObjPtr( (CObjPtr&) argFormFieldStyle )
  {
  }
  /*
   *
   */
  inline CFormFieldStyle::CFormFieldStyle( CFormFieldStyleData* pObj ) :
    CObjPtr( (CObj*) pObj )
  {
  }
  /*
   *
   */
  inline CFormFieldStyle::CFormFieldStyle( CObj* pObj ) :
    CObjPtr( pObj )
  {
  }
  /*
   *
   */
  inline CFormFieldStyle::~CFormFieldStyle( )
  {
  }

} // namespace IDRS
#endif // __CFormFieldStyle_h__
