/**
 * \file CPageStyle.h
 * \brief Interface for CPageStyle class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _CPageStyle_h_
#define _CPageStyle_h_

#include "CObjPtr.h"
#include "CPageStyleParagraphList.h"

namespace IDRS
{
  class CPageStyleData;
  /**
   * \brief Sets the page style associated to a page
   *
   * Usually when a page has a style object associated, it is considered that it is containing enough information to generate a document (pdf, docx, etc)
   */
  class IDRSKRN_API CPageStyle : public CObjPtr
  {
  public:
    /**
     * \brief Default constructor
     */
    inline CPageStyle();
    /**
     * \brief Copy constructor
     *
     * \param argPageStyle Object to copy (shallow copy)
     */
    inline CPageStyle(const CPageStyle& argPageStyle);
    /**
     * \brief CPageFont constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageStyle(CPageStyleData * pObj);
    /**
     * \brief Destructor
     */
    inline virtual ~CPageStyle();
    /**
     * \brief Instantiates a new page style object
     */
    static CPageStyle Create();
    /**
     * \brief Get the array containing the paragraph lists
     */
    CPageParagraphListArray GetPageParagraphLists() const;
    /**
     * \brief Set the array containing the paragraph lists
     */
    void SetPageParagraphLists(const CPageParagraphListArray& argxPageParagraphLists);

  private:
    //! Internal use 
    CPageStyleData & TypedObject() const
    {
      return (CPageStyleData &)Object();
    };
  };

  /*
   *
   */
  inline CPageStyle::CPageStyle()
  {
  }
  /*
   *
   */
  inline CPageStyle::CPageStyle(const CPageStyle& argPageStyle)
    : CObjPtr((CObjPtr &)argPageStyle)
  {
  }
  /*
   *
   */
  inline CPageStyle::CPageStyle(CPageStyleData * pObj)
    : CObjPtr((CObj *)pObj)
  {
  }
  /*
   *
   */
  inline CPageStyle::~CPageStyle()
  {
  }
}
#endif // _CPageStyle_h_
