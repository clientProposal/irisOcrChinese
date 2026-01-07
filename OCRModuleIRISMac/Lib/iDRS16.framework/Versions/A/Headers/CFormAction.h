/**
 * \file CFormAction.h
 * Base class that represents an interactive form action.
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef __CFormAction_h__
#define __CFormAction_h__

#include "CObjPtr.h"
#include "EnumDefinitions.h"
#include "TObjPtrArray.h"

namespace IDRS
{
  class CFormActionData;
  class CFormAction;
  typedef TObjPtrArray<CFormAction> CFormActionArray;
  /**
   * \brief Class CFormAction represents the base class for all types of interactive form actions available in iDRS SDK.
   */
  class IDRSKRN_API CFormAction : public CObjPtr
  {

  public:
    /**
     * \brief Default constructor
     */
    inline CFormAction( );
    /**
     * \brief Copy constructor
     * 
     * \param argFormAction Object to copy (shallow copy)
     */
    inline CFormAction( const CFormAction &argFormAction );
    /**
     * \brief CFormAction constructor that initializes an object with a data object.
     * 
     * \param pObj Pointer to an object representing the data class
     */
    inline CFormAction( CFormActionData *pObj );
    /**
     * \brief CFormAction constructor that initializes an object with a data object.
     *
     * \param pObj Pointer to an object representing the base data class
     */
    inline CFormAction( CObj* pObj );
    /**
     * \brief CFormAction destructor
     */
    inline virtual ~CFormAction( );
    /**
     * \brief Creates a new form action element of the given type.
     * 
     * \param argFormActionType Type of the form action to be created
     * 
     * \return New form action instance.
     */
    static CFormAction Create( const FormActionType argFormActionType );
    /**
     * \brief GetFormActionType returns the form action type.
     *
     * \return The FormActionType value
     */
    FormActionType GetFormActionType( ) const;
    /**
     * \brief GetNextFormActions returns the array of subsequent form actions.
     * 
     * \note 
     * The current action is supposed to be executed first by the reader application, then the next 
     * actions are executed in a sequence corresponding to their order in the array. Each action in the
     * array may describe subsequent actions, in which case they are also executed in the same way recursively.
     * 
     * \return The array containing the next CFormAction objects.
     */
    CFormActionArray GetNextFormActions( ) const;
    /**
     * \brief SetNextFormActions sets the array of subsequent form actions.
     *
     * \param argNextFormActions The array containing the next CFormAction objects.
     */
    void SetNextFormActions( const CFormActionArray &argNextFormActions ) const;

  private:
    //! Internal use 
    CFormActionData& TypedObject( ) const
    {
      return (CFormActionData&)Object( );
    };
  };
  /*
   *
   */
  inline CFormAction::CFormAction()
  {
  }
  /*
   *
   */
  inline CFormAction::CFormAction( const CFormAction& argFormAction ) :
    CObjPtr( (CObjPtr&) argFormAction )
  {
  }
  /*
   *
   */
  inline CFormAction::CFormAction( CFormActionData* pObj ) :
    CObjPtr( (CObj*) pObj )
  {
  }
  /*
   *
   */
  inline CFormAction::CFormAction( CObj* pObj ) :
    CObjPtr( pObj )
  {
  }
  /*
   *
   */
  inline CFormAction::~CFormAction( )
  {
  }

} // namespace IDRS
#endif // __CFormAction_h__
