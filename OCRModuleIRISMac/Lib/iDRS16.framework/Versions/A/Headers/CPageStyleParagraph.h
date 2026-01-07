/**
 * \file CPageStyleParagraph.h
 * \brief Interface for CPageStyleParagraph class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _CPageStyleParagraph_h_
#define _CPageStyleParagraph_h_

#include "CObjPtr.h"
#include "CPageStyleTabulation.h"
#include "TObjPtrArray.h"
#include "CPageStyleFont.h"
#include "idrsstd.h"

namespace IDRS
{
  class CPageStyleParagraphData;

  /**
   * \brief CPageStyleParagraph represents the text paragraph style data.
   *
   * This class contains the following info related to a text paragraph.
   * - horizontal alignment
   * - margins
   * - font, drop-cap font
   * - foreground & background colors
   * - first line indentation
   * - tabulations
   * - line height
   */
  class IDRSKRN_API CPageStyleParagraph : public CObjPtr
  {
  public:
    /**
     * \brief Default constructor
     */
    inline CPageStyleParagraph();
    /**
     * \brief Copy constructor
     *
     * \param argPageStyleParagraph Object to copy (shallow copy)
     */
    inline CPageStyleParagraph(const CPageStyleParagraph& argPageStyleParagraph);
    /**
     * \brief CPageStyleParagraph constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageStyleParagraph(CPageStyleParagraphData * pObj);
    /**
     * \brief CPageStyleParagraph constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageStyleParagraph(CObj * pObj);
    /**
     * \brief Destructor
     */
    inline virtual ~CPageStyleParagraph();
    /**
     * \brief Creates an instance of CPageStyleParagraph and initializes it with default values
     */
    static CPageStyleParagraph Create();
    /**
     * \brief Get the horizontal alignment
     */
    HorizontalAlignment GetHorizontalAlignment() const;
    /**
     * \brief Get the margins for the paragraph
     */
    MarginInfo GetMargins() const;
    /**
     * \brief Get the font style used for the paragraph
     */
    CPageStyleFont GetFont() const;
    /**
     * \brief Get the font style used for the drop-cap character(s)
     * 
     * This font style is expected to be set only if drop-cap is present in a paragraph
     */
    CPageStyleFont GetDropCapFont() const;
    /**
     * \brief Get the foreground color used for a paragraph
     */
    IDRS_COLOR GetForegroundColor() const;
    /**
     * \brief Get the text paragraph background color
     */
    IDRS_COLOR GetBackgroundColor() const;
    /**
     * \brief Get the indentation that should be applied for the first line in the paragraph
     *
     * The indentation value is specified in pixels
     */
    IDRS_INT GetFirstLineIndentation() const;
    /**
     * \brief Get the list of tabulations applied to the text paragraph 
     */
    CPageStyleTabulationArray GetPageStyleTabulations() const;
    /**
     * \brief Get the height of a text line in the paragraph
     */
    IDRS_INT GetLineHeight() const;
    /**
     * \brief Set the paragraph text horizontal alignment
     *
     * \param evHorizontalAlignment Horizontal alignment value 
     */
    void SetHorizontalAlignment(const HorizontalAlignment evHorizontalAlignment);
    /**
     * \brief Set the paragraph margins
     *
     * \param stMargins Structure containing the paragraph margins
     */
    void SetMargins(const MarginInfo & stMargins);
    /**
     * \brief Set the font style used for the paragraph
     *
     * Please note that individual components of the paragraph (lines, words, letters) are allowed to have different font styles
     *
     * \param argFont Font style used in the paragraph
     */
    void SetFont(const CPageStyleFont& argFont);
    /**
     * \brief Set the font style used for the drop cap character
     *
     * The drop cap font style is used only if the paragraph has a drop cap character
     *
     * \param argDropCapFont Font style used by the drop cap character
     */
    void SetDropCapFont(const CPageStyleFont& argDropCapFont);
    /**
     * \brief Set the foreground color for the text in the paragraph
     *
     * Please note that individual components of the paragraph (lines, words, letters) are allowed to have different foreground colors
     *
     * \param stColor Structure containing the color in RGB components
     */
    void SetForegroundColor(const IDRS_COLOR & stColor);
    /**
     * \brief Set the background color for the text in the paragraph
     *
     * Please note that individual components of the paragraph (lines, words, letters) are allowed to have different background colors
     *
     * \param stColor Structure containing the color in RGB components
     */
    void SetBackgroundColor(const IDRS_COLOR & stColor);
    /**
     * \brief Set the indentation for the first line in the paragraph
     *
     * \param iFirstLineIndentation Indentation value, in pixels
     */
    void SetFirstLineIndentation(const IDRS_INT iFirstLineIndentation);
    /**
     * \brief Set the list of tabulation styles associated to the paragraph 
     *
     * \param xPageStyleTabulation Array of tabulation styles
     */
    void SetPageStyleTabulations(const CPageStyleTabulationArray& xPageStyleTabulation);
    /**
     * \brief Set the line height for the lines in the paragraph
     *
     * \param iLineHeight Line height value, in pixels
     */
    void SetLineHeight(const IDRS_INT iLineHeight);
  private:
    //! Internal use 
    CPageStyleParagraphData & TypedObject() const
    {
      return (CPageStyleParagraphData &)Object();
    };
  };
  typedef TObjPtrArray<CPageStyleParagraph> CPageStyleParagraphArray;
  /*
   *
   */
  inline CPageStyleParagraph::CPageStyleParagraph()
  {
  }
  /*
   *
   */
  inline CPageStyleParagraph::CPageStyleParagraph(const CPageStyleParagraph& argPageStyleParagraph)
    : CObjPtr((CObjPtr &)argPageStyleParagraph)
  {
  }
  /*
   *
   */
  inline CPageStyleParagraph::CPageStyleParagraph(CPageStyleParagraphData * pObj)
    : CObjPtr((CObj *)pObj)
  {
  }
  /*
   *
   */
  inline CPageStyleParagraph::CPageStyleParagraph(CObj * pObj)
    : CObjPtr(pObj)
  {
  }
  /*
   *
   */
  inline CPageStyleParagraph::~CPageStyleParagraph()
  {
  }
}
#endif // _CPageStyleParagraph_h_
