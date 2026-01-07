/**
 * \file CPageStyleTabulation.h
 * \brief Interface for CPageStyleTabulation class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _CPageStyleTabulation_h_
#define _CPageStyleTabulation_h_

#include "CObjPtr.h"
#include "TObjPtrArray.h"
#include "EnumDefinitions.h"

namespace IDRS
{
  class CPageStyleTabulationData;
  /**
   * \brief CPageStyleTabulation represents the style for a text tabulation
   */
  class IDRSKRN_API CPageStyleTabulation : public CObjPtr
  {
  public:
    /**
     * \brief Default constructor
     */
    inline CPageStyleTabulation();
    /**
     * \brief Copy constructor
     *
     * \param argPageStyleTabulation Object to copy (shallow copy)
     */
    inline CPageStyleTabulation(const CPageStyleTabulation& argPageStyleTabulation);
    /**
     * \brief CPageStyleTabulation constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageStyleTabulation(CPageStyleTabulationData * pObj);
    /**
     * \brief CPageStyleTabulation constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageStyleTabulation(CObj * pObj);
    /**
     * \brief Destructor
     */
    inline virtual ~CPageStyleTabulation();
    /**
     * \brief Creates a new instance of a CPageStyleTabulation object
     */
    static CPageStyleTabulation Create();
    /**
     * \brief Retrieves the tabulation stop value
     */
    IDRS_INT GetStopValue() const;
    /**
     * \brief Returns the horizontal alignment for the tabulation
     */
    HorizontalAlignment GetHorizontalAlignment() const;
    /**
     * \brief Returns the tabulation leader type
     */
    TabulationLeader GetTabulationLeader() const;
    /**
     * \brief Sets the tabulation stop value
     *
     * \param iStopValue Tabulation stop value
     */
    void SetStopValue(const IDRS_INT iStopValue);
    /**
     * \brief Sets the horizontal alignment for the tabulation
     *
     * \param evHorizontalAlignment Horizontal alignment value
     */
    void SetHorizontalAlignment(const HorizontalAlignment evHorizontalAlignment);
    /**
     * \brief Sets the tabulation leader type
     *
     * \param evTabLeader Tabulation leader type
     */
    void SetTabulationLeader(const TabulationLeader evTabLeader);
    /**
     * \brief Retrieves the id associated to the tabulation style
     */
    IDRS_UINT GetId() const;
    /**
     * \brief Retrieves the tabulation cell width
     */
    IDRS_UINT GetCellWidth() const;
    /**
     * \brief Returns the tabulation left padding
     */
    IDRS_INT GetLeftPadding() const;
    /**
     * \brief Returns the tabulation right padding
     */
    IDRS_INT GetRightPadding() const;
    /**
     * \brief Sets the id for the tabulation style
     *
     * \param uiId Unique id for the tabulation style
     */
    void SetId(const IDRS_UINT uiId);
    /**
     * \brief Sets the tabulation cell width
     *
     * \param uiCellWidth Tabulation cell width
     */
    void SetCellWidth(const IDRS_UINT uiCellWidth);
    /**
     * \brief Sets the tabulation style left padding
     *
     * \param iLeftPadding Left padding value
     */
    void SetLeftPadding(const IDRS_INT iLeftPadding);
    /**
     * \brief Sets the tabulation style right padding
     *
     * \param iRightPadding Right padding value
     */
    void SetRightPadding(const IDRS_INT iRightPadding);
  private:
    //! Internal use 
    CPageStyleTabulationData & TypedObject() const
    {
      return (CPageStyleTabulationData &)Object();
    };
  };

  typedef TObjPtrArray<CPageStyleTabulation> CPageStyleTabulationArray;

  /*
   *
   */
  inline CPageStyleTabulation::CPageStyleTabulation()
  {
  }
  /*
   *
   */
  inline CPageStyleTabulation::CPageStyleTabulation(const CPageStyleTabulation& argPageStyleTabulation)
    : CObjPtr((CObjPtr &)argPageStyleTabulation)
  {
  }
  /*
   *
   */
  inline CPageStyleTabulation::CPageStyleTabulation(CPageStyleTabulationData * pObj)
    : CObjPtr((CObj *)pObj)
  {
  }
  /*
   *
   */
  inline CPageStyleTabulation::CPageStyleTabulation(CObj * pObj)
    : CObjPtr(pObj)
  {
  }
  /*
   *
   */
  inline CPageStyleTabulation::~CPageStyleTabulation()
  {
  }
}
#endif // _CPageStyleTabulation_h_
