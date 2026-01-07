/**
 * \file CPageStyleParagraphList.h
 * \brief Interface for CPageStyleParagraphList class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _CPageStyleParagraphList_h_
#define _CPageStyleParagraphList_h_

#include "CObjPtr.h"
#include "TObjPtrArray.h"
#include "EnumDefinitions.h"
 
namespace IDRS
{
  class CPageStyleParagraphListData;

  /**
   * \brief CPageStyleParagraphList represents a list style associated to a text paragraph
   *
   * A list can contain one or more paragraphs. This class contains the info that describe the style of the list which should be applied to the text paragraph:
   * - List type: ordered/unordered
   * - List style: character type used in front of list elements: disc, circle, square, decimal number, etc
   * - Starting number: the starting number for numbered lists
   * - Post character: the character to be used after the list type. Ex: ')' generates the output 1), 2), a), etc
   */
  class IDRSKRN_API CPageStyleParagraphList : public CObjPtr
  {
  public:
    /**
     * \brief Default constructor
     */
    inline CPageStyleParagraphList();
    /**
     * \brief Copy constructor
     *
     * \param argPageStyleParagraphList Object to copy (shallow copy)
     */
    inline CPageStyleParagraphList(const CPageStyleParagraphList& argPageStyleParagraphList);
    /**
     * \brief CPageStyleParagraphList constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageStyleParagraphList(CPageStyleParagraphListData * pObj);
    /**
     * \brief CPageStyleParagraphList constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageStyleParagraphList(CObj * pObj);
    /**
     * \brief Destructor
     */
    inline virtual ~CPageStyleParagraphList();
    /**
     * \brief Generates a new instance of a CPageStyleParagraphList and initializes it with default values
     */
    static CPageStyleParagraphList Create();
    /**
     * \brief Gets the type of list (ordered/unordered).
     *
     * \return the type of list.
     */
    ListType GetListType() const;
    /**
     * \brief Gets the list style: character type used in front of list elements: disc, circle, square, decimal number, etc.
     *
     * \return the list style.
     */
    ListStyle GetListStyle() const;
    /**
     * \brief Gets the starting number.
     *
     * \return the starting number.
     */
    IDRS_UINT GetStartingNumber() const;
    /**
     * \brief Gets the character that should be used after the starting character. ex: a.
     *
     * \remarks Only UCS-2 characters are currently supported.
     *
     * \return the character that should be used after the starting character.
     */
    IDRS_WCHAR32 GetPostCharacter() const;
    /**
     * \brief Gets the list coordinates.
     *
     * \return a list of the coordinates.
     */
    IDRS_RECT GetCoordinates() const;
    /**
     * \brief Sets the list type (ordered/unordered).
     *
     * \param evListType List type
     */
    void SetListType(const ListType evListType);
    /**
     * \brief Sets the list style: character type used in front of list elements: disc, circle, square, decimal number, etc.
     *
     * \param evListStyle List style value
     */
    void SetListStyle(const ListStyle evListStyle);
    /**
     * \brief Sets the list starting number.
     *
     * \param uiStartingNumber List starting number
     */
    void SetStartingNumber(const IDRS_UINT uiStartingNumber);
    /**
     * \brief Sets the character to be used after the list type. Ex: ')' generates the output 1), 2), a), etc.
     *
     * \param chPostCharacter Post character
     */
    void SetPostCharacter(const IDRS_WCHAR32 chPostCharacter);
    /**
     * \brief Sets list coordinates.
     *
     * \param rcCoordinates List coordinates
     */
    void SetCoordinates(const IDRS_RECT& rcCoordinates);
    /**
     * \brief Equality operator compares 2 CPageStyleParagraphList objects
     *
     * The comparison takes into account the values stored in the CPageStyleParagraphList objects
     *
     *\retval true if the content of the 2 objects is the same
     *\retval false if the content of the 2 objects differs
     */
    bool operator ==(const CPageStyleParagraphList& argPageStyleParagraphListOther) const;
  private:
    //! Internal use
    CPageStyleParagraphListData & TypedObject() const
    {
      return (CPageStyleParagraphListData &)Object();
    };
  };

  typedef TObjPtrArray<CPageStyleParagraphList> CPageParagraphListArray;

  /*
   *
   */
  inline CPageStyleParagraphList::CPageStyleParagraphList()
  {
  }
  /*
   *
   */
  inline CPageStyleParagraphList::CPageStyleParagraphList(const CPageStyleParagraphList& argPageStyleParagraphList)
    : CObjPtr((CObjPtr &)argPageStyleParagraphList)
  {
  }
  /*
   *
   */
  inline CPageStyleParagraphList::CPageStyleParagraphList(CPageStyleParagraphListData * pObj)
    : CObjPtr((CObj *)pObj)
  {
  }
  /*
   *
   */
  inline CPageStyleParagraphList::CPageStyleParagraphList(CObj * pObj)
    : CObjPtr(pObj)
  {
  }
  /*
   *
   */
  inline CPageStyleParagraphList::~CPageStyleParagraphList()
  {
  }
}
#endif // _CPageStyleParagraphList_h_
