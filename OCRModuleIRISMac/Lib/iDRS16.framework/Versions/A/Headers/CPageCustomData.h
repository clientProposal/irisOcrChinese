/**
 * \file CPageCustomData.h
 * \brief Interface for CPageCustomData class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _CPageCustomData_h_
#define _CPageCustomData_h_

#include "CObjPtr.h"
#include "CMemoryStream.h"

namespace IDRS
{
  class CPageCustomDataData;

  /**
   * \brief CPageCustomData allows to store inside iDRS page content some integrator-provided data.
   */
  class IDRSKRN_API CPageCustomData : public CObjPtr
  {
  public:
    /**
     * \brief Default constructor
     */
    inline CPageCustomData ();
    /**
     * \brief Copy constructor
     *
     * \param argPageCustomData Object to copy (shallow copy)
     */
    inline CPageCustomData ( const CPageCustomData& argPageCustomData );
    /**
     * \brief Constructor.
     *
     * \param pPageCustomDataData The object to point to.
     */
    inline CPageCustomData ( CPageCustomDataData * pPageCustomDataData );
    /**
     * \brief CPageCustomData constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageCustomData ( CObj* pObj );
    /**
     * \brief Destructor
     */
    inline virtual ~CPageCustomData ();
    /**
     * \brief Set the custom data to be stored in this object. The iDRS will perform no interpretation of the provided buffer, and simply store it as-is.
     *
     * \param argCustomData The custom data
     *
     * \remarks The provided data will be copied in an internal buffer.
     */
    void SetCustomData ( const CMemoryBuffer & argCustomData );
    /**
     * \brief Get the custom data stored in this object.
     *
     * \return The custom data stored in this object
     *
     * \remarks The returned data is a copy of the data stored internally.
     */
    CMemoryBuffer GetCustomData () const;
  private:
    //! Internal use 
    CPageCustomDataData & TypedObject () const
    {
      return (CPageCustomDataData &) Object ();
    };
  };
  /*
   *
   */
  inline CPageCustomData::CPageCustomData ()
  {
  }
  /*
   *
   */
  inline CPageCustomData::CPageCustomData ( const CPageCustomData& argPageCustomData )
    : CObjPtr ((CObjPtr &) argPageCustomData )
  {
  }
  /*
   *
   */
  inline CPageCustomData::CPageCustomData ( CPageCustomDataData * pPageCustomDataData )
    : CObjPtr ((CObj *) pPageCustomDataData )
  {
  }
  /*
   *
   */
  inline CPageCustomData::CPageCustomData ( CObj* pObj )
    : CObjPtr ( pObj )
  {
  }
  /*
   *
   */
  inline CPageCustomData::~CPageCustomData ()
  {
  }
}
#endif // _CPageCustomData_h_
