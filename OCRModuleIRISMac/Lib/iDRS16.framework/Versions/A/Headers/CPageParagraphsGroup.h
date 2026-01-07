/**
 * \file CPageParagraphsGroup.h
 * \brief Interface for CPageParagraphsGroup class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _CPageParagraphsGroup_h_
#define _CPageParagraphsGroup_h_

#include "CPolygon.h"
#include "TObjPtrArray.h"
#include "CPageStyleParagraph.h"
#include "CPageParagraph.h"
#include "CPageStyleParagraphList.h"
#include "CPageCustomData.h"

namespace IDRS
{
  class CPageParagraphsGroupData;
  /**
   * \brief CPageParagraphsGroup represents a group of text paragraphs
   */
  class IDRSKRN_API CPageParagraphsGroup : public CPageCustomData
  {
  public:
    /**
     * \brief Default constructor
     */
    inline CPageParagraphsGroup();
    /**
     * \brief Copy constructor
     *
     * \param argPageParagraphsGroup Object to copy (shallow copy)
     */
    inline CPageParagraphsGroup(const CPageParagraphsGroup& argPageParagraphsGroup);
    /**
     * \brief CPageParagraphsGroup constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageParagraphsGroup(CPageParagraphsGroupData * pObj);
    /**
     * \brief CPageParagraphsGroup constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageParagraphsGroup(CObj * pObj);
    /**
     * \brief Destructor
     */
    inline virtual ~CPageParagraphsGroup();
    /**
     * \brief Creates a new instance of CPageParagraphsGroup
     */
    static CPageParagraphsGroup Create();
    /**
     * \brief Returns the polygon that embeds the paragraphs group content
     */
    CPolygon GetBoundingPolygon() const;
    /**
     * \brief Sets the polygon that embeds the paragraphs group content
     *
     * \param argBoundingPolygon Bounding polygon
     */
    void SetBoundingPolygon(const CPolygon& argBoundingPolygon);
    /**
     * \brief Retrieves the style that is applied to the paragraphs group
     */
    CPageStyleParagraph GetStyle() const;
    /**
     * \brief Returns the list with inner paragraphs
     */
    CPageParagraphArray GetParagraphs() const;
    /**
     * \brief Sets the paragraph group style
     *
     * \param argPageStyleParagraph Style to be applied to the entire paragraph group
     */
    void SetStyle(const CPageStyleParagraph& argPageStyleParagraph);
    /**
     * \brief Sets the list with paragraphs
     *
     * \param xParagraphs List containing the paragraphs in the group
     */
    void SetParagraphs(const CPageParagraphArray& xParagraphs);
    /**
     * \brief Gets the paragraph type for the paragraphs in the group
     */
    ParagraphType GetParagraphType() const;
    /**
     * \brief Returns the paragraph list style applied to the paragraph group.
     *
     * The paragraph list style is expected to be used only if the group paragraph type is ParagraphType::List
     */
    CPageStyleParagraphList GetParagraphListStyle() const;
    /**
     * \brief Sets the paragraph type for the paragraphs in the group
     *
     * \param evParagraphType Group paragraph type 
     */
    void SetParagraphType(const ParagraphType evParagraphType);
    /**
     * \brief Sets the paragraph list style applied to the paragraph group.
     *
     * \param argPageParagraphList Paragraph list style object
     */
    void SetParagraphListStyle(const CPageStyleParagraphList& argPageParagraphList);
  private:
    //! Internal use 
    CPageParagraphsGroupData & TypedObject() const
    {
      return (CPageParagraphsGroupData &)Object();
    };
  };
  typedef TObjPtrArray<CPageParagraphsGroup> CPageParagraphsGroupArray;
  /*
   *
   */
  inline CPageParagraphsGroup::CPageParagraphsGroup()
  {
  }
  /*
   *
   */
  inline CPageParagraphsGroup::CPageParagraphsGroup(const CPageParagraphsGroup& argPageParagraphsGroup)
    : CPageCustomData((CPageCustomData&)argPageParagraphsGroup)
  {
  }
  /*
   *
   */
  inline CPageParagraphsGroup::CPageParagraphsGroup(CPageParagraphsGroupData * pObj)
    : CPageCustomData((CPageCustomDataData*)pObj)
  {
  }
  /*
   *
   */
  inline CPageParagraphsGroup::CPageParagraphsGroup(CObj * pObj)
    : CPageCustomData(pObj)
  {
  }
  /*
   *
   */
  inline CPageParagraphsGroup::~CPageParagraphsGroup()
  {
  }
}
#endif // _CPageParagraphsGroup_h_
