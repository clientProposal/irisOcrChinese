/**
 * \file CPageSection.h
 * \brief Interface for CPageSection class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _CPageSection_h_
#define _CPageSection_h_
 
#include "TObjPtrArray.h"
#include "CPageColumn.h"
#include "CPageZone.h"
#include "CPageCustomData.h"

namespace IDRS
{
  class CPageSectionData;
  /**
   * \brief CPageSection represents a section in a page
   *
   * A section class contains the following elements:
   * - columns
   * - zones outside columns
   */
  class IDRSKRN_API CPageSection : public CPageCustomData
  {
  public:
    /**
     * \brief Default constructor
     */
    inline CPageSection();
    /**
     * \brief Copy constructor
     *
     * \param argPageSection2 Object to copy (shallow copy)
     */
    inline CPageSection(const CPageSection& argPageSection2);
    /**
     * \brief CPageSection constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageSection(CPageSectionData * pObj);
    /**
     * \brief CPageSection constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageSection(CObj * pObj);
    /**
     * \brief Destructor
     */
    inline virtual ~CPageSection();
    /**
     * \brief Creates a new instance of a section object
     */
    static CPageSection Create();
    /**
     * \brief Get the rectangle where the section is located
     */
    IDRS_RECT GetBoundingBox() const;
    /**
     * \brief Set the rectangle where the page section is located
     *
     * \param rcBoundingBox Rectangle containing the coordinates for section location
     */
    void SetBoundingBox(const IDRS_RECT& rcBoundingBox);
    /**
     * \brief Get the columns that are inside the section
     */
    CPageColumnArray GetColumns() const;
    /**
     * \brief Get the zones that are inside the section, but not in any column
     */
    CPageZoneArray GetZones() const;
    /**
     * \brief Set the array of columns available in the current section
     *
     * \param xColumns Array of columns
     */
    void SetColumns(const CPageColumnArray& xColumns);
    /**
     * \brief Set the array of zones in the current section that are not present in any column
     *
     * \param xZones Array of zones
     */
    void SetZones(const CPageZoneArray& xZones);
    /**
     * \brief HasLineBetweenColumns returns a flag indicating whether there's a line between the columns in the section
     *
     * \internal
     * property HasLineBetweenColumns/Get
     * \endinternal
     */
    IDRS_BOOL HasLineBetweenColumns() const;
    /**
     * \brief SetHasLineBetweenColumns sets the flag indicating that there's a line betweent the columns in the section
     *
     * \param bValue Line between columns flag value
     */
    void SetHasLineBetweenColumns(const IDRS_BOOL bValue);
  private:
    //! Internal use 
    CPageSectionData & TypedObject() const
    {
      return (CPageSectionData &)Object();
    };
  };

  typedef TObjPtrArray<CPageSection> CPageSectionArray;

  /*
   *
   */
  inline CPageSection::CPageSection()
  {
  }
  /*
   *
   */
  inline CPageSection::CPageSection(const CPageSection& argPageSection2)
    : CPageCustomData((CPageCustomData&)argPageSection2)
  {
  }
  /*
   *
   */
  inline CPageSection::CPageSection(CPageSectionData * pObj)
    : CPageCustomData((CPageCustomDataData*)pObj)
  {
  }
  /*
   *
   */
  inline CPageSection::CPageSection(CObj * pObj)
    : CPageCustomData(pObj)
  {
  }
  /*
   *
   */
  inline CPageSection::~CPageSection()
  {
  }
}
#endif // _CPageSection_h_
