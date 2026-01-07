/**
 * \file CPageStyleFont.h
 * \brief Interface for CPageStyleFont class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _CPageStyleFont_h_
#define _CPageStyleFont_h_
#include "CPageFont.h"
#include "TObjPtrArray.h"

namespace IDRS
{
  class CPageStyleFontData;

  /**
   * \brief CPageStyleFont represents a style used for a specific font
   *
   * This class contains:
   * - A reference to a font object: see \see CPageFont
   * - Size for the font
   * - Stretch factor applied to the font
   */
  class IDRSKRN_API CPageStyleFont : public CObjPtr
  {
  public:
    /**
     * \brief Default constructor
     */
    inline CPageStyleFont();
    /**
     * \brief Copy constructor
     *
     * \param argPageStyleFont Object to copy (shallow copy)
     */
    inline CPageStyleFont(const CPageStyleFont& argPageStyleFont);
    /**
     * \brief CPageStyleFont constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageStyleFont(CPageStyleFontData * pObj);
    /**
     * \brief CPageStyleFont constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageStyleFont(CObj * pObj);
    /**
     * \brief Destructor
     */
    inline virtual ~CPageStyleFont();
    /**
     * \brief Instantiates a new CPageStyleFont object
     */
    static CPageStyleFont Create();
    /**
     * \brief Retrieves the associated font object
     */
    CPageFont GetPageFont() const;
    /**
     * \brief Retrieves the font size
     */
    IDRS_INT GetFontSize() const;
    /**
     * \brief Retrieves the stretching to be applied for the font
     *
     * Default value is 100
     */
    IDRS_INT GetFontStretch() const;
    /**
     * \brief Sets the associated font object
     *
     * \param argPageFont Font object
     */
    void SetPageFont(const CPageFont& argPageFont);
    /**
     * \brief Sets the font size
     *
     * \param iFontSize Font size
     */
    void SetFontSize(const IDRS_INT iFontSize);
    /**
     * \brief Sets the font stretching
     *
     * \param iFontStretch Font stretching, in percentage.
     */
    void SetFontStretch(const IDRS_INT iFontStretch);
    /**
     * \brief Equality operator compares 2 CPageStyleFont objects
     *
     * The comparison takes into account the values stored in the CPageStyleFont objects
     *
     *\retval true if the content of the 2 objects is the same
     *\retval false if the content of the 2 objects differs
     */
    bool operator ==(const CPageStyleFont& argPageStyleFontOther) const;
  private:
    //! Internal use 
    CPageStyleFontData & TypedObject() const
    {
      return (CPageStyleFontData &)Object();
    };
  };
  typedef TObjPtrArray<CPageStyleFont> CPageStyleFontArray;
  /*
   *
   */
  inline CPageStyleFont::CPageStyleFont()
  {
  }
  /*
   *
   */
  inline CPageStyleFont::CPageStyleFont(const CPageStyleFont& argPageStyleFont)
    : CObjPtr((CObjPtr &)argPageStyleFont)
  {
  }
  /*
   *
   */
  inline CPageStyleFont::CPageStyleFont(CObj * pObj)
    : CObjPtr(pObj)
  {
  }
  /*
   *
   */
  inline CPageStyleFont::CPageStyleFont(CPageStyleFontData * pObj)
    : CObjPtr((CObj *)pObj)
  {
  }
  /*
   *
   */
  inline CPageStyleFont::~CPageStyleFont()
  {
  }
}
#endif // _CPageStyleFont_h_
