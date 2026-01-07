/**
 * \file CPageZoneText.h
 * \brief Interface for CPageZoneText class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _CPageZoneText_h_
#define _CPageZoneText_h_

#include "CPageZone.h"
#include "TObjPtrArray.h"
#include "CPageParagraphsGroup.h"
#include "CPageTextLine.h"
 
namespace IDRS
{
  class CPageZoneTextData;
  /**
   * \brief CPageZoneText represents a text zone in a page
   *
   * In contains a list with groups of paragraphs
   */
  class IDRSKRN_API CPageZoneText : public CPageZone
  {
  public:
    /**
     * \brief Default constructor
     */
    inline CPageZoneText();
    /**
     * \brief Copy constructor
     *
     * \param argPageZone Object to copy (shallow copy)
     */
    inline CPageZoneText(const CPageZoneText& argPageZone);
    /**
     * \brief Constructor using the base class
     *
     * \param argPageZone Base page zone
     */
    inline CPageZoneText(const CPageZone& argPageZone);
    /**
     * \brief CPageZoneText constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageZoneText(CPageZoneTextData * pObj);
    /**
     * \brief CPageZoneText constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageZoneText(CObj * pObj);
    /**
     * \brief Destructor
     */
    inline virtual ~CPageZoneText();
    /**
     * \brief Creates a new instance of a CPageZoneText object
     */
    static CPageZoneText Create();
    /**
     * \brief Get the list of paragraphs groups present in the current text zone
     */
    CPageParagraphsGroupArray GetParagraphsGroups() const;
    /**
     * \brief Set the list of paragraphs groups
     *
     * \param argParagraphsGroups Array of paragraph groups
     */
    void SetParagraphsGroups(const CPageParagraphsGroupArray& argParagraphsGroups);
  private:
    //! Internal use 
    CPageZoneTextData & TypedObject() const
    {
      return (CPageZoneTextData &)Object();
    };
  };

  /*
   *
   */
  inline CPageZoneText::CPageZoneText()
  {
  }
  /*
   *
   */
  inline CPageZoneText::CPageZoneText(const CPageZoneText& argPageZone)
    : CPageZone((CPageZone &)argPageZone)
  {
  }
  /*
   *
   */
  inline CPageZoneText::CPageZoneText(const CPageZone& argPageZone)
    : CPageZone(argPageZone)
  {
  }
  /*
   *
   */
  inline CPageZoneText::CPageZoneText(CPageZoneTextData * pObj)
    : CPageZone((CPageZoneData *)pObj)
  {
  }
  /*
   *
   */
  inline CPageZoneText::CPageZoneText(CObj * pObj)
    : CPageZone(pObj)
  {
  }
  /*
   *
   */
  inline CPageZoneText::~CPageZoneText()
  {
  }
}
#endif // _CPageZoneText_h_
