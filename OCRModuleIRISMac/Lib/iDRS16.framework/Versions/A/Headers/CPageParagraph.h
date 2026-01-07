/**
 * \file CPageParagraph.h
 * \brief Interface for CPageParagraph class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _CPageParagraph_h_
#define _CPageParagraph_h_

#include "CPolygon.h"
#include "CPageStyleParagraph.h"
#include "TObjPtrArray.h"
#include "CPageTextLine.h"
#include "CPageStyleParagraphList.h"
#include "CPageCustomData.h"

namespace IDRS
{
  class CPageParagraphData;
  /**
   * \brief CPageParagraph represents a text paragraph
   *
   * The class contains the following info:
   * - lines with text
   * - bounding rectangle
   * - paragraph style
   */
  class IDRSKRN_API CPageParagraph : public CPageCustomData
  {
  public:
    /**
     * \brief Default constructor
     */
    inline CPageParagraph();
    /**
     * \brief Copy constructor
     *
     * \param argPageParagraph Object to copy (shallow copy)
     */
    inline CPageParagraph(const CPageParagraph& argPageParagraph);
    /**
     * \brief CPageParagraph constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageParagraph(CPageParagraphData * pObj);
    /**
     * \brief CPageParagraph constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageParagraph(CObj * pObj);
    /**
     * \brief Destructor
     */
    inline virtual ~CPageParagraph();
    /**
     * \brief Creates a new instance of a paragraph object
     */
    static CPageParagraph Create();
    /**
     * \brief GetBoundingPolygon retrieves the bounding polygon
     */
    CPolygon GetBoundingPolygon() const;
    /**
     * \brief Sets the polygon containing all paragraph content
     *
     * \param argBoundingPolygon Polygon object
     */
    void SetBoundingPolygon(const CPolygon& argBoundingPolygon);
    /**
     * \brief Returns the paragraph style
     */
    CPageStyleParagraph GetStyle() const;
    /**
     * \brief Returns an array containing the lines of text in the paragraph
     */
    CPageTextLineArray GetTextLines() const;
    /**
     * \brief SetStyle sets the paragraph style
     *
     * \param argStyle Paragraph style
     */
    void SetStyle(const CPageStyleParagraph& argStyle);
    /**
     * \brief SetTextLines sets the text lines in the paragraph
     *
     * \param argTextLines Array containing the lines of text
     */
    void SetTextLines(const CPageTextLineArray& argTextLines);
    /**
     * \brief Returns the paragraph type
     */
    ParagraphType GetParagraphType() const;
    /**
     * \brief Returns the paragraph list style
     *
     * A paragraph can be part of a list spanning multiple paragraphs. Details about the type can be found in CPageStyleParagraphList
     * The list style is expected to be set if the paragraph type is set to ParagraphType::List (see \see GetParagraphType)
     */
    CPageStyleParagraphList GetParagraphListStyle() const;
    /**
     * \brief Sets the paragraph type.
     *
     * Please note that if the paragraph type is set to ParagraphType::List, the paragraph list style needs to be set as well. (see \see SetParagraphListStyle)
     */
    void SetParagraphType(const ParagraphType evParagraphType);
    /**
     * \brief Sets the list style
     *
     * The list style is expected to be set if the paragraph type is set to ParagraphType::List (see \see GetParagraphType)
     *
     * \param argPageParagraphListStyle Object containing the list style
     */
    void SetParagraphListStyle(const CPageStyleParagraphList& argPageParagraphListStyle);
  private:
    //! Internal use 
    CPageParagraphData & TypedObject() const
    {
      return (CPageParagraphData &)Object();
    };
  };

  typedef TObjPtrArray<CPageParagraph> CPageParagraphArray;
  /*
   *
   */
  inline CPageParagraph::CPageParagraph()
  {
  }
  /*
   *
   */
  inline CPageParagraph::CPageParagraph(const CPageParagraph& argPageParagraph)
    : CPageCustomData((CPageCustomData&)argPageParagraph)
  {
  }
  /*
   *
   */
  inline CPageParagraph::CPageParagraph(CPageParagraphData * pObj)
    : CPageCustomData((CPageCustomDataData*)pObj)
  {
  }
  /*
   *
   */
  inline CPageParagraph::CPageParagraph(CObj * pObj)
    : CPageCustomData(pObj)
  {
  }
  /*
   *
   */
  inline CPageParagraph::~CPageParagraph()
  {
  }
}
#endif // _CPageParagraph_h_
