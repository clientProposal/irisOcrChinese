/**
 * \file CPageStyleTextElement.h
 * \brief Interface for CPageStyleTextElement class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _CPageStyleTextElement_h_
#define _CPageStyleTextElement_h_
 
#include "CObjPtr.h"
#include "CPageStyleFont.h"

namespace IDRS
{
  class CPageStyleTextElementData;

  /**
   * \brief CPageStyleTextElement represents the style associated to a text element \see IDRS::CPageTextElement
   */
  class IDRSKRN_API CPageStyleTextElement : public CObjPtr
  {
  public:
    /**
     * \brief Default constructor
     */
    inline CPageStyleTextElement();
    /**
     * \brief Copy constructor
     *
     * \param argPageStyleTextElement Object to copy (shallow copy)
     */
    inline CPageStyleTextElement(const CPageStyleTextElement& argPageStyleTextElement);   
    /**
     * \brief CPageStyleTextElement constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageStyleTextElement(CPageStyleTextElementData * pObj);
    /**
     * \brief CPageStyleTextElement constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageStyleTextElement(CObj * pObj);
    /**
     * \brief Destructor
     */
    inline virtual ~CPageStyleTextElement();
    /**
     * \brief Creates a new instance of a CPageStyleTextElement initialized with default values
     */
    static CPageStyleTextElement Create();
    /**
     * \brief Get the flag specifying if the text element is underlined or not. Returns IDRS_TRUE if the text element is underlined. IDRS_FALSE otherwise
     * 
     * \internal
     * property Underlined/Get
     * \endinternal
     */
    IDRS_BOOL IsUnderlined() const;
    /**
     * \brief Get the flag specifying if the text element is bold or not. Returns IDRS_TRUE if the text element is bold. IDRS_FALSE otherwise
     * 
     * \internal
     * property Bold/Get
     * \endinternal
     */
    IDRS_BOOL IsBold() const;
    /**
     * \brief Get the flag specifying if the text element is italic or not. Returns IDRS_TRUE if the text element is italic. IDRS_FALSE otherwise
     * 
     * \internal
     * property Italic/Get
     * \endinternal
     */
    IDRS_BOOL IsItalic() const;
    /**
     * \brief Get the flag specifying if the text element has a fixed font or not. Returns IDRS_TRUE if the text element has a fixed font. IDRS_FALSE otherwise
     * 
     * \internal
     * property FixedFont/Get
     * \endinternal
     */
    IDRS_BOOL IsFixedFont() const;
    /**
     * \brief Get the flag specifying if the text element represents a drop capital or not. Returns IDRS_TRUE if the text element represents a drop cap. IDRS_FALSE otherwise
     * 
     * \internal
     * property DropCapital/Get
     * \endinternal
     */
    IDRS_BOOL IsDropCapital() const;
    /**
     * \brief Get the flag specifying if the text element is super scripted or not. Returns IDRS_TRUE if the text element is super scripted. IDRS_FALSE otherwise
     * 
     * \internal
     * property Superscript/Get
     * \endinternal
     */
    IDRS_BOOL IsSuperscript() const;
    /**
     * \brief Get the flag specifying if the text element is sub scripted or not. Returns IDRS_TRUE if the text element is subscript. IDRS_FALSE otherwise
     * 
     * \internal
     * property Subscript/Get
     * \endinternal
     */
    IDRS_BOOL IsSubscript() const;
    /**
     * \brief Get the flag specifying if the text element is the first underlined character or not. Returns IDRS_TRUE if the text element is the first character where underline starts. IDRS_FALSE otherwise
     * 
     * \internal
     * property UnderlineStart/Get
     * \endinternal
     */
    IDRS_BOOL IsUnderlineStart() const;
    /**
     * \brief Get the flag specifying if the text element is the last underlined character or not. Returns IDRS_TRUE if the text element is last characters with underline. IDRS_FALSE otherwise
     * 
     * \internal
     * property UnderlineEnd/Get
     * \endinternal
     */
    IDRS_BOOL IsUnderlineEnd() const;
    /**
     * \brief Gets the text direction for the current text element
     *
     * \return the text direction.
     */
    TextDirection GetTextDirection() const;
    /**
     * \brief Gets the font style.
     *
     * \return the font style.
     */
    CPageStyleFont GetFontStyle() const;
    /**
     * \brief Gets the foreground color.
     *
     * \return the foreground color.
     */
    IDRS_COLOR GetForegroundColor() const;
    /**
     * \brief Gets the background color.
     *
     * \return the background color.
     */
    IDRS_COLOR GetBackgroundColor() const;
    /**
     * \brief Gets the baseline for the text element.
     *
     * \return the text element baseline.
     */
    IDRS_INT GetBaseline() const;
    /**
     * \brief Gets the number of blob cleanup rectangles.
     *
     * \return the number of blob cleanup rectangles.
     */
    IDRS_INT GetBlobCleanupRectanglesCount() const;
    /**
     * \brief Gets the blob cleanup rectangle located at a specific index.
     *
     * \param iIndex Index for the blob cleanup rectangle
     *
     * \return Blob cleanup rectangle
     */
    IDRS_RECT GetBlobCleanupRectangleAt(const IDRS_INT iIndex) const;
    /**
     * \brief Sets the flag specifying if the text element is underlined or not.
     *
     * \param bValue Boolean flag: IDRS_TRUE if the text element is underlined, IDRS_FALSE otherwise
     *     
     */
    void SetUnderlined(const IDRS_BOOL bValue);
    /**
     * \brief Sets the flag specifying if the text element is bold or not.
     *
     * \param bValue Boolean flag: IDRS_TRUE if the text element is bold, IDRS_FALSE otherwise
     */
    void SetBold(const IDRS_BOOL bValue);
    /**
     * \brief Sets the flag specifying if the text element is italic or not.
     *
     * \param bValue Boolean flag: IDRS_TRUE if the text element is italic, IDRS_FALSE otherwise
     */
    void SetItalic(const IDRS_BOOL bValue);
    /**
     * \brief Sets the flag specifying if the text element has fixed font or not.
     *
     * \param bValue Boolean flag: IDRS_TRUE if the text element has fixed font, IDRS_FALSE otherwise
     */
    void SetFixedFont(const IDRS_BOOL bValue);
    /**
     * \brief Sets the flag specifying if the text element is drop cap or not.
     *
     * \param bValue Boolean flag: IDRS_TRUE if the text element is drop cap, IDRS_FALSE otherwise
     */
    void SetDropCapital(const IDRS_BOOL bValue);
    /**
     * \brief Sets the flag specifying if the text element is superscript or not.
     *
     * \param bValue Boolean flag: IDRS_TRUE if the text element is superscript, IDRS_FALSE otherwise
     */
    void SetSuperscript(const IDRS_BOOL bValue);
    /**
     * \brief Sets the flag specifying if the text element is subscripted or not.
     *
     * \param bValue Boolean flag: IDRS_TRUE if the text element is subscripted, IDRS_FALSE otherwise
     */
    void SetSubscript(const IDRS_BOOL bValue);
    /**
     * \brief Sets the flag specifying if the text element is the first underlined text element or not.
     *
     * \param bValue Boolean flag: IDRS_TRUE if the text element is the first underlined text element, IDRS_FALSE otherwise
     */
    void SetUnderlineStart(const IDRS_BOOL bValue);
    /**
     * \brief Sets the flag specifying if the text element is the last underlined text element or not.
     *
     * \param bValue Boolean flag: IDRS_TRUE if the text element is the last underlined text element, IDRS_FALSE otherwise
     */
    void SetUnderlineEnd(const IDRS_BOOL bValue);
    /**
     * \brief Sets the text element text direction.
     *
     * \param evTextDirection Text direction value
     */
    void SetTextDirection(const TextDirection evTextDirection);
    /**
     * \brief Sets the font style.
     *
     * \param argFontStyle Font style
     */
    void SetFontStyle(const CPageStyleFont& argFontStyle);
    /**
     * \brief Sets the foreground color for the text element.
     *
     * \param stColor Color in RGB format
     */
    void SetForegroundColor(const IDRS_COLOR& stColor);
    /**
     * \brief Sets the background color for the text element.
     *
     * \param stColor Color in RGB format
     */
    void SetBackgroundColor(const IDRS_COLOR& stColor);
    /**
     * \brief Sets the baseline value.
     *
     * \param iBaselineValue Baseline value
     */
    void SetBaseline(const IDRS_INT iBaselineValue);
    /**
     * \brief AddBlobCleanupRectangle adds a cleanup rectangle
     *
     * \param stRectangle Coordinates for the cleanup rectangle
     */
    void AddBlobCleanupRectangle(const IDRS_RECT& stRectangle);
    /**
     * \brief Sets a cleanup rectangle at a specific index in the internal array.
     *
     * \param iIndex Array index
     * \param stRectangle Coordinates of the cleanup rectangle
     */
    void SetBlobCleanupRectangleAt(const IDRS_INT iIndex, const IDRS_RECT& stRectangle);
    /**
     * \brief RemoveBlobCleanupRectanglesAt removes a cleanup rectangle at a specific index
     *
     * \param iIndex Array index
     */
    void RemoveBlobCleanupRectangleAt(const IDRS_INT iIndex);
  private:
    //! Internal use 
    CPageStyleTextElementData & TypedObject() const
    {
      return (CPageStyleTextElementData &)Object();
    };

  };

  /*
   *
   */
  inline CPageStyleTextElement::CPageStyleTextElement()
  {
  }
  /*
   *
   */
  inline CPageStyleTextElement::CPageStyleTextElement(const CPageStyleTextElement& argPageStyleTextElement)
    : CObjPtr((CObjPtr &)argPageStyleTextElement)
  {
  }
  /*
   *
   */
  inline CPageStyleTextElement::CPageStyleTextElement(CPageStyleTextElementData * pObj)
    : CObjPtr((CObj *)pObj)
  {
  }
  /*
   *
   */
  inline CPageStyleTextElement::CPageStyleTextElement(CObj * pObj)
    : CObjPtr(pObj)
  {
  }
  /*
   *
   */
  inline CPageStyleTextElement::~CPageStyleTextElement()
  {
  }
}
#endif // _CPageStyleTextElement_h_
