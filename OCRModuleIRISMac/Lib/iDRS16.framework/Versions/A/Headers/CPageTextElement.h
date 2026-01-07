/**
 * \file CPageTextElement.h
 * \brief Interface for CPageTextElement class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _CPageTextElement_h_
#define _CPageTextElement_h_

#include "CPolygon.h"
#include "TObjPtrArray.h"
#include "CPageTextElementAlternative.h"
#include "CPageStyleTextElement.h"
#include "CPageCustomData.h"


namespace IDRS
{
  class CPageTextElementData;
  class idrs_string;

  /**
   * \brief CPageTextElement represents a text element in iDRS. 
   *
   * A text element can be a single character or a sequence of characters.
   *
   * This class contains the following info:
   * - Bounding polygon
   * - Text value
   * - Language 
   * - text element style. \see IDRS::CPageStyleTextElement
   * - Alternative solutions
   */
  class IDRSKRN_API CPageTextElement : public CPageCustomData
  {
  public:
    /**
     * \brief Default constructor
     */
    inline CPageTextElement();
    /**
     * \brief Copy constructor
     *
     * \param argPageTextElement Object to copy (shallow copy)
     */
    inline CPageTextElement(const CPageTextElement& argPageTextElement);
    /**
     * \brief CPageTextElement constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageTextElement(CPageTextElementData * pObj);
    /**
     * \brief CPageTextElement constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageTextElement(CObj * pObj);
    /**
     * \brief Destructor
     */
    inline virtual ~CPageTextElement();
    /**
     * \brief Creates a new instance of a CPageTextElement
     */
    static CPageTextElement Create();
    /**
     * \brief Gets the polygon where the text element is located
     */
    CPolygon GetBoundingPolygon() const;
    /**
     * \brief Sets the polygon where the text element is located
     *
     * \param argBoundingPolygon Polygon containing the text element
     */
    void SetBoundingPolygon(const CPolygon& argBoundingPolygon);
    /**
     * \brief Retrieves the text value
     */
    const idrs_string& GetTextValue() const;
    /**
     * \brief Sets the text value
     *
     * \param strTextValue The text value to set
     */
    void SetTextValue(const idrs_string& strTextValue);
    /**
     * \brief Retrieves the language for the text value
     */
    Language GetLanguage() const;
    /**
     * \brief Retrieves the text element style
     */
    CPageStyleTextElement GetStyle() const;
    /**
     * \brief Retrieves the confidence value for the text element.
     *
     * The confidence value ranges from 0 (lowest confidence) to 100 (highest confidence).
     *
     * This value corresponds to the likeliness that the provided result is correct, and is computed by the OCR engine based on the OCR local score
     * as well as contextual information like surrounding characters, typographical analysis, or presence of the word it belongs to in a lexicon.
     *
     * \return Confidence value for the text element.
     *
     * \remarks In most cases, an integrator who wishes to assess the quality of a text element's recognition should rely on the OCR confidence value instead of
     * on the OCR local score.
     */
    IDRS_UINT GetOcrConfidence() const;
    /**
     * \brief Sets the confidence value for the text element.
     *
     * The confidence value ranges from 0 (lowest confidence) to 100 (highest confidence).
     *
     * This value corresponds to the likeliness that the provided result is correct, and is computed by the OCR engine based on the OCR local score
     * as well as contextual information like surrounding characters, typographical analysis, or presence of the word it belongs to in a lexicon.
     *
     * \param uiOcrConfidence Confidence value for the text element.
     *
     * \remarks In most cases, an integrator who wishes to assess the quality of a text element's recognition should rely on the OCR confidence value instead of
     * on the OCR local score.
     */
    void SetOcrConfidence(const IDRS_UINT uiOcrConfidence);
    /**
     * \brief Retrieves the OCR local score of the text element.
     *
     * The OCR score ranges from 0 (lowest score) to 100 (highest score).
     *
     * This value corresponds to the recognition score of the text element, without taking into account information from surrounding elements.
     * The score corresponds to the result of looking only at the shape of the current character.
     *
     * \return OCR local score for the text element.
     *
     * \remarks In most cases, an integrator who wishes to assess the quality of a text element's recognition should rely on the OCR confidence value instead of
     * on the OCR local score.
     */
    IDRS_UINT GetOcrLocalScore() const;
    /**
     * \brief Sets the OCR local score of the text element.
     *
     * The OCR score ranges from 0 (lowest score) to 100 (highest score).
     *
     * This value corresponds to the recognition score of the text element, without taking into account information from surrounding elements.
     * The score corresponds to the result of looking only at the shape of the current character.
     *
     * \param uiOcrLocalScore OCR local score for the text element.
     *
     * \remarks In most cases, an integrator who wishes to assess the quality of a text element's recognition should rely on the OCR confidence value instead of
     * on the OCR local score.
     */
    void SetOcrLocalScore(const IDRS_UINT uiOcrLocalScore);
    /**
     * \brief Retrieves an array of alternative solutions for the text value
     */
    CPageTextElementAlternativeArray GetAlternatives() const;
    /**
     * \brief Sets the language for the text value
     *
     * \param evLanguage Language value
     */
    void SetLanguage(const Language evLanguage);
    /**
     * \brief Sets the text element style
     *
     * \param argStyle Text element style
     */
    void SetStyle(const CPageStyleTextElement& argStyle);
    /**
     * \brief Sets the array of alternative text values
     *
     * \param xAlternatives Array of alternative text values
     */
    void SetAlternatives(const CPageTextElementAlternativeArray& xAlternatives);
  private:
    //! Internal use 
    CPageTextElementData & TypedObject() const
    {
      return (CPageTextElementData &)Object();
    };
  };

  typedef TObjPtrArray<CPageTextElement> CPageTextElementArray;

  /*
   *
   */
  inline CPageTextElement::CPageTextElement()
  {
  }
  /*
   *
   */
  inline CPageTextElement::CPageTextElement(const CPageTextElement& argPageTextElement)
    : CPageCustomData((CPageCustomData&)argPageTextElement)
  {
  }
  /*
   *
   */
  inline CPageTextElement::CPageTextElement(CPageTextElementData * pObj)
    : CPageCustomData((CPageCustomDataData*)pObj)
  {
  }
  /*
   *
   */
  inline CPageTextElement::CPageTextElement(CObj * pObj)
    : CPageCustomData(pObj)
  {
  }
  /*
   *
   */
  inline CPageTextElement::~CPageTextElement()
  {
  }

}
#endif // _CPageTextElement_h_
