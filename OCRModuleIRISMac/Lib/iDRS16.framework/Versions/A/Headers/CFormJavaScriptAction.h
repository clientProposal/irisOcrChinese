/**
 * \file CFormJavaScriptAction.h
 * Interface of the CFormJavaScriptAction class
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef __CFormJavascriptAction_h__
#define __CFormJavascriptAction_h__

#include "CFormAction.h"

namespace IDRS
{
  class CFormJavaScriptActionData;
  class idrs_string;
  /**
   * \brief Class CFormAction represents the base class for all types of interactive form actions available in iDRS SDK.
   */
  class IDRSKRN_API CFormJavaScriptAction : public CFormAction
  {

  public:
    /**
     * \brief Default constructor
     */
    inline CFormJavaScriptAction( );
    /**
     * \brief Copy constructor
     * 
     * \param argFormAction Object to copy (shallow copy)
     */
    inline CFormJavaScriptAction( const CFormJavaScriptAction &argFormAction );
    /**
     * \brief Copy constructor
     * 
     * \param argFormAction Object to copy (shallow copy)
     */
    inline CFormJavaScriptAction( const CFormAction &argFormAction );
    /**
     * \brief CFormJavaScriptAction constructor that initializes an object with a data object.
     * 
     * \param pObj Pointer to an object representing the data class
     */
    inline CFormJavaScriptAction( CFormJavaScriptActionData *pObj );
    /**
     * \brief CFormJavaScriptAction constructor that initializes an object with a data object.
     *
     * \param pObj Pointer to an object representing the base data class
     */
    inline CFormJavaScriptAction( CObj* pObj );
    /**
     * \brief CFormJavaScriptAction destructor
     */
    inline virtual ~CFormJavaScriptAction( );
    /**
     * \brief Creates an new CFormJavaScriptAction element. 
     * 
     * \return new CFormJavaScriptAction instance.
     */
    static CFormJavaScriptAction Create( );
    /**
     * \brief GetScript gets the JavaScript script definition
     *
     * \return A string containing the JavaScript script definition.
     */
    const idrs_string &GetScript( ) const;
    /**
     * \brief SetScript sets the JavaScript script definition
     *
     * \note No syntactic or semantic validation of the script
     *
     * \param strScript String containing the JavaScript script definition.
     */
    void SetScript( const idrs_string &strScript );


  private:
    //! Internal use 
    CFormJavaScriptActionData& TypedObject( ) const
    {
      return (CFormJavaScriptActionData&)Object( );
    };
  };
  /*
   *
   */
  inline CFormJavaScriptAction::CFormJavaScriptAction()
  {
  }
  /*
   *
   */
  inline CFormJavaScriptAction::CFormJavaScriptAction( const CFormJavaScriptAction& argFormAction ) :
    CFormAction( (CFormAction&) argFormAction )
  {
  }
  /*
   *
   */
  inline CFormJavaScriptAction::CFormJavaScriptAction( const CFormAction& argFormAction ) :
    CFormAction( argFormAction )
  {
  }
  /*
   *
   */
  inline CFormJavaScriptAction::CFormJavaScriptAction( CFormJavaScriptActionData* pObj ) :
    CFormAction( (CObj*) pObj )
  {
  }
  /*
   *
   */
  inline CFormJavaScriptAction::CFormJavaScriptAction( CObj* pObj ) :
    CFormAction( pObj )
  {
  }
  /*
   *
   */
  inline CFormJavaScriptAction::~CFormJavaScriptAction( )
  {
  }
} // namespace IDRS
#endif // __CFormJavascriptAction_h__
