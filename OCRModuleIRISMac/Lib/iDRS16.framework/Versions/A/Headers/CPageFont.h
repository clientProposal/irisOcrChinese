/**
 * \file CPageFont.h
 * \brief Interface for CPageFont class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _CPageFont_h_
#define _CPageFont_h_

#include "CObjPtr.h"
#include "TObjPtrArray.h"
#include "EnumDefinitions.h"

namespace IDRS
{
  class CPageFontData;
  class idrs_string;

  /**
   * \brief CPageFont represents a font in iDRS SDK
   *
   * A font contains the following data:
   * - font family name and/or font postscript name
   * - font properties
   */
  class IDRSKRN_API CPageFont : public CObjPtr
  {
  public:
    /**
     * \brief Default constructor
     */
    inline CPageFont();
    /**
     * \brief Copy constructor
     *
     * \param argPageFont Object to copy (shallow copy)
     */
    inline CPageFont(const CPageFont& argPageFont);
    /**
     * \brief CPageFont constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageFont(CPageFontData * pObj);
    /**
     * \brief CPageFont constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageFont(CObj * pObj);
    /**
     * \brief Destructor
     */
    inline virtual ~CPageFont();
    /**
     * \brief Instantiates a new font object
     */
    static CPageFont Create();
    /**
     * \brief Retrieves the family name for the current font
     */
    const idrs_string& GetFontFamilyName() const;
    /**
     * \brief Retrieves the postscript name for the current font
     */
    const idrs_string& GetFontPostscriptName() const;
    /**
     * \brief Gets a boolean flag specifying wether the font is bold
     *
     * \internal
     * property Bold/Get
     * \endinternal
     */
    IDRS_BOOL IsBold() const;
    /**
     * \brief Gets a boolean flag specifying wether the font is italic
     *
     * \internal
     * property Italic/Get
     * \endinternal
     */
    IDRS_BOOL IsItalic() const;
    /**
     * \brief Gets a boolean flag specifying wether the font is asian
     *
     * \internal
     * property Asian/Get
     * \endinternal
     */
    IDRS_BOOL IsAsian() const;
    /**
     * \brief Retrieves the font family type.
     *
     * \see FontFamilyType for a list with available font family types
     */
    FontFamilyType GetFamilyType() const;
    /**
     * \brief Sets the font family name
     *
     * \param strFontFamilyName NULL terminated utf8 string containing the font family
     */
    void SetFontFamilyName(const idrs_string& strFontFamilyName);
    /**
     * \brief Sets the font postscript name
     *
     * \pre strFontPostscriptName cannot contain space
     * \pre strFontPostscriptName cannot contain non-ASCII character
     * \pre The length of strFontPostscriptName <= IDRS_MAX_POSTSCRIPT_NAME_SIZE, cannot contain space
     *
     * \param strFontPostscriptName NULL terminated utf8 string containing the font post script name
     */
    void SetFontPostscriptName(const idrs_string& strFontPostscriptName);
    /**
     * \brief Sets the boolean flag for bold property
     *
     * \param bValue Bold flag
     */
    void SetBold(const IDRS_BOOL bValue);
    /**
     * \brief Sets the italic flag
     *
     * \param bValue Italic flag
     */
    void SetItalic(const IDRS_BOOL bValue);
    /**
     * \brief Sets the asian flag
     *
     * \param bValue Asian flag
     */
    void SetAsian(const IDRS_BOOL bValue);
    /**
     * \brief Sets the font family type
     *
     * \param evFamilyType Font family type
     */
    void SetFamilyType(const FontFamilyType& evFamilyType);
    /**
     * \brief Sets the font set associated to the font
     *
     * Currently the only FontInfoComputation::Custom is allowed to be created by integrators.
     * Setting any other value might cause an error.
     *
     * \see FontInfoComputation for more details
     * 
     * \param evFontSet Font set
     */
    void SetTextFontSet(const FontInfoComputation evFontSet);
    /**
     * \brief Retrieves the source text font set used for the current font
     */
    FontInfoComputation GetTextFontSet() const;
    /**
     * \brief Equality operator compares 2 CPageFont objects
     *
     * The comparison takes into account the values stored in the CPageFont objects
     *
     *\retval true if the content of the 2 objects is the same
     *\retval false if the content of the 2 objects differs
     */
    bool operator ==(const CPageFont& argPageFontOther) const;
  private:
    //! Internal use 
    CPageFontData & TypedObject() const
    {
      return (CPageFontData &)Object();
    };
  };

  typedef TObjPtrArray<CPageFont> CPageFontArray;
  /*
   *
   */
  inline CPageFont::CPageFont()
  {
  }
  /*
   *
   */
  inline CPageFont::CPageFont(const CPageFont& argPageFont)
    : CObjPtr((CObjPtr &)argPageFont)
  {
  }
  /*
   *
   */
  inline CPageFont::CPageFont(CPageFontData * pObj)
    : CObjPtr((CObj *)pObj)
  {
  }
  /*
   *
   */
  inline CPageFont::CPageFont(CObj * pObj)
    : CObjPtr(pObj)
  {
  }
  /*
   *
   */
  inline CPageFont::~CPageFont()
  {
  }
}
#endif // _CPageFont_h_
