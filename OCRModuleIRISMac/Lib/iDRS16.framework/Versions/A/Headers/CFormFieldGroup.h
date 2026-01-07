/**
 * \file CFormFieldGroup.h
 * Interface for a CFormFieldGroup class.
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef __CFormFieldGroup_h__
#define __CFormFieldGroup_h__

#include "CFormField.h"

namespace IDRS
{
  class CFormFieldData;
  class CFormFieldGroupData;
  
  /**
   * Class CFormRadioButtonGroup represents a group of related radio button fields.
   */
  class IDRSKRN_API CFormFieldGroup : public CFormField
  {
  public:
    /**
     * \brief Default constructor
     */
    inline CFormFieldGroup( );
    /**
     * \brief Copy constructor
     *
     * \param argFormField Object to copy (shallow copy)
     */
    inline CFormFieldGroup( const CFormFieldGroup& argFormField );
    /**
     * \brief Constructor from base class
     *
     * \param argFormField Base class object
     */
    inline CFormFieldGroup( const CFormField& argFormField );
    /**
     * \brief CFormFieldGroup constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CFormFieldGroup( CFormFieldGroupData* pObj );
    /**
     * \brief CFormFieldGroup destructor
     */
    inline virtual ~CFormFieldGroup( );
    /**
     * \brief Creates an new CFormFieldGroup element.
     *
     * \return new CFormFieldGroup instance.
     */
    static CFormFieldGroup Create( );
    /**
     * \brief GetChildren returns the form fields contained in this group.
     *
     * \return the array containing the CFormField elements
     */
    CFormFieldArray GetChildren( ) const;
    /**
     * \brief GetAlternateName returns the field alternate name.
     *
     * \return String containing the alternate name
     */
    const idrs_string &GetAlternateName( ) const;
    /**
     * \brief SetAlternateName sets the field alternate name
     *
     * \param strAlternateName String containing the alternate name
     */
    void SetAlternateName( const idrs_string &strAlternateName );

  private:
    //! Internal use 
    CFormFieldGroupData& TypedObject( ) const
    {
      return (CFormFieldGroupData&)Object( );
    }
  };
  /*
   *
   */
  inline CFormFieldGroup::CFormFieldGroup( )
  {
  }
  /*
   *
   */
  inline CFormFieldGroup::CFormFieldGroup( const CFormFieldGroup& objFormField ) :
    CFormField( (CFormField&)objFormField )
  {
  }
  /*
   *
   */
  inline CFormFieldGroup::CFormFieldGroup( const CFormField& objFormField ) :
    CFormField( objFormField )
  {
  }
  /*
   *
   */
  inline CFormFieldGroup::CFormFieldGroup( CFormFieldGroupData* pObj ) :
    CFormField( (CFormFieldData*)pObj )
  {
  }
  /*
   *
   */
  inline CFormFieldGroup::~CFormFieldGroup( )
  {
  }
} // namespace IDRS
#endif // __CFormFieldGroup_h__
