/**
 * \file CPageWord.h
 * \brief Interface for CPageWord class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _CPageWord_h_
#define _CPageWord_h_

#include "CPolygon.h"
#include "CPageStyleWord.h"
#include "CPageTextElement.h"
#include "TObjPtrArray.h"
#include "CPageCustomData.h"

namespace IDRS
{
  class CPageWordData;

  /**
   * \brief CPageWord represents a text word 
   */
  class IDRSKRN_API CPageWord : public CPageCustomData
  {
  public:
    /**
     * \brief Default constructor
     */
    inline CPageWord();
    /**
     * \brief Copy constructor
     *
     * \param argPageWord Object to copy (shallow copy)
     */
    inline CPageWord(const CPageWord& argPageWord);
    /**
     * \brief CPageWord constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageWord(CPageWordData * pObj);
    /**
     * \brief CPageWord constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageWord(CObj * pObj);
    /**
     * \brief Destructor
     */
    inline virtual ~CPageWord();
    /**
     * \brief Creates a new instance of CPageWord
     */
    static CPageWord Create();
    /**
     * \brief Retrieves the polygon where the text word is located
     */
    CPolygon GetBoundingPolygon() const;
    /**
     * \brief Sets the polygon where the text word is located
     *
     * \param argBoundingPolygon Polygon containing the text word
     */
    void SetBoundingPolygon(const CPolygon& argBoundingPolygon);
    /**
     * \brief Retrieves the style associated to the word 
     */
    CPageStyleWord GetStyle() const;
    /**
     * \brief Sets the word style
     *
     * \param argStyleWord Object containing the word style
     */
    void SetStyle(const CPageStyleWord& argStyleWord);
    /**
     * \brief Retrieves the array of text elements 
     */
    CPageTextElementArray GetTextElements() const;
    /**
     * \brief Sets the array of text element in the word
     *
     * \param argTextElements Text elements array
     */
    void SetTextElements(const CPageTextElementArray& argTextElements);
    /**
     * \brief Retrieves the type of hyperlink for the current word
     *
     * By default the value of the hyperlink type is set to Hyperlink::None
     */
    Hyperlink GetHyperlinkType() const;
    /**
     * \brief Sets the hyperlink type for the word
     *
     * By default the value of the hyperlink type is set to Hyperlink::None
     *
     * \param evHyperlinkType Hyperlink type
     */
    void SetHyperlinkType(const Hyperlink evHyperlinkType);

  private:
    //! Internal use 
    CPageWordData & TypedObject() const
    {
      return (CPageWordData &)Object();
    };
  };

  typedef TObjPtrArray<CPageWord> CPageWordArray;

  /*
   *
   */
  inline CPageWord::CPageWord()
  {
  }
  /*
   *
   */
  inline CPageWord::CPageWord(const CPageWord& argPageWord)
    : CPageCustomData((CPageCustomData&)argPageWord)
  {
  }
  /*
   *
   */
  inline CPageWord::CPageWord(CPageWordData * pObj)
    : CPageCustomData((CPageCustomDataData*)pObj)
  {
  }
  /*
   *
   */
  inline CPageWord::CPageWord(CObj* pObj)
    : CPageCustomData(pObj)
  {
  }
  /*
   *
   */
  inline CPageWord::~CPageWord()
  {
  }
}
#endif // _CPageWord_h_
