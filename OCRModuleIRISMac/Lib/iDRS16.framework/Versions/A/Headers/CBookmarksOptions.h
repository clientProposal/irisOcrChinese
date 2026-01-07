/**
 * \file CBookmarksOptions.h
 * \brief CBookmarksOptions class defining all bookmarks options
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _CBookmarksOptions_h_
#define _CBookmarksOptions_h_
#include <CObj.h>
#include "EnumDefinitions.h"
#include "CPageBookmark.h"
#include "CPageContent.h"
#include "idrs_string.h"
namespace IDRS
{
  class CBookmarksOptionsData;
  /**
   * \brief CBookmarksOptions class defines all bookmarks options.
   */
  class IDRSKRN_API CBookmarksOptions : public CObjPtr
  {
    public:
      /**
       * \brief Default constructor.
       */
      inline CBookmarksOptions();
      /**
       * \brief copy constructor.
       */
      inline CBookmarksOptions(const CBookmarksOptions& argBookmarksOptions);
      /**
       * \brief constructor from data object.
       */
      inline CBookmarksOptions(CBookmarksOptionsData* pObj);
      /**
       * \brief destructor.
       */
      inline virtual ~CBookmarksOptions();
      /**
       * \brief Create is instantiating a new instance of CBookmarksOptions and associated data object
       *
       * \return New instance of CBookmarksOptions
       */
      static CBookmarksOptions Create();
      /**
       * \brief Sets the bookmarks mode.
       *
       * \param evBookmarksMode bookmarks mode value
       */
      void SetBookmarksMode(const BookmarksMode evBookmarksMode);
      /**
       * \brief Gets the bookmarks mode
       *
       * \returns the bookmarks mode
       */
      BookmarksMode GetBookmarksMode() const;
      /**
       * \brief Helper method allowing to automatically generate some bookmarks corresponding to the provided page's content.
       *
       * The generated bookmarks will be organized the following way:
       * - One bookmark for the whole page, with DisplayMode set to Page
       * - As children of this page-level bookmark, one bookmark for each detected title, table and graphics. Title
       *   bookmarks will have DisplayMode set to PageWidth, while table and graphics bookmarks will have DisplayMode Rectangle.
       *   These bookmarks will be added following the reading order of the page.
       *
       * \param argPageContent The page content
       * \param strPageTitle The title of the parent bookmark for the whole page.
       * \param argDestinationPage The bookmarks' destination page number starting at index zero. If not set, the first page is selected by default.
       * \return The generated bookmarks
       */
      static CPageBookmarkArray GenerateBookmarks ( const CPageContent & argPageContent, const idrs_string& strPageTitle = "Page", const IDRS_UINT argDestinationPage = 0);
    private:
      /**
       * Internal use only
       */
      inline CBookmarksOptionsData& TypedObject() const;
  };
  /*
   *
   */
  inline CBookmarksOptions::CBookmarksOptions()
  {
  }
  /*
   *
   */
  inline CBookmarksOptions::CBookmarksOptions(const CBookmarksOptions& argBookmarksOptions)
    : CObjPtr((CObjPtr&)argBookmarksOptions)
  {
  }
  /*
   *
   */
  inline CBookmarksOptions::CBookmarksOptions(CBookmarksOptionsData* pObj)
    : CObjPtr((CObj*)pObj)
  {
  }
  /*
   *
   */
  inline CBookmarksOptions::~CBookmarksOptions()
  {
  }
  /*
   *
   */
  inline CBookmarksOptionsData& CBookmarksOptions::TypedObject() const
  {
    return (CBookmarksOptionsData&)Object();
  }
} // namespace
#endif //_CBookmarksOptions_h_
