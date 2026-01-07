/**
 * \file CPageBookmark.h
 * \brief Interface for CPageBookmark class
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */

#ifndef _CPageBookmark_h_
#define _CPageBookmark_h_

#include "TObjPtrArray.h"
#include "CPageCustomData.h"
#include "EnumDefinitions.h"

namespace IDRS
{
  class CPageBookmarkData;
  class CPageBookmark;
  class idrs_string;
  typedef TObjPtrArray<CPageBookmark> CPageBookmarkArray;
  /**
   * \brief CPageBookmark represents a bookmark on a page.
   */
  class IDRSKRN_API CPageBookmark : public CPageCustomData
  {
  public:
    /**
     * \brief Default constructor
     */
    inline CPageBookmark ();
    /**
     * \brief Copy constructor
     *
     * \param argPageBookmark Object to copy (shallow copy)
     */
    inline CPageBookmark ( const CPageBookmark& argPageBookmark );
    /**
     * \brief Constructor from data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageBookmark ( CObj * pObj );
    /**
     * \brief Destructor
     */
    inline virtual ~CPageBookmark ();
    /**
     * \brief Creates a new instance.
     *
     * \pre !strTitle.empty()
     *
     * \param strTitle The bookmark's title.
     */
    static CPageBookmark Create (const idrs_string& strTitle);
    /**
     * \brief Returns the bookmark's children.
     */
    CPageBookmarkArray GetChildren () const;
    /**
     * \brief Set the bookmark's children.
     *
     * \pre !xChildren.IsNull()
     *
     * \param xChildren The bookmark's children
     */
    void SetChildren ( const CPageBookmarkArray& xChildren );
    /**
     * \brief Get the title of the bookmark
     *
     * \return The bookmark's title.
     */
    const idrs_string& GetTitle () const;
    /**
     * \brief Set the title of the bookmark.
     *
     * \pre !strTitle.empty()
     *
     * \param strTitle The new title.
     */
    void SetTitle (const idrs_string& strTitle );
    /**
     * \brief Get the display mode of the bookmark.
     *
     * \return The bookmark's display mode.
     */
    BookmarkDisplayMode GetDisplayMode () const;
    /**
     * \brief Set the display mode of the bookmark.
     *
     * \param evDisplayMode The display mode to set.
     *
     * \remarks This setting allows to specify how a bookmark's destination should be displayed, when the created document is opened
     * in a viewer and the bookmark is selected there.
     * It has no effet on the content of the output document itself; only the intended behavior of the bookmark's selection in a viewer is concerned.
     */
    void SetDisplayMode ( const BookmarkDisplayMode & evDisplayMode );
    /**
     * \brief Gets the bookmark destination page index.
     *
     * \return The bookmark's destination page number, starting at zero.
     */
    IDRS_UINT GetDestinationPage( ) const;
    /**
     * \brief Sets the bookmark destination page index.
     *
     * \param uiDestinationPageIndex The index of the page referenced by the bookmark
     */
    void SetDestinationPage( const IDRS_UINT uiDestinationPageIndex );

    /**
     * \brief Get the bookmark destination (positioning on the page).
     *
     * \return The bookmark's destination, with coordinates expressed in pixels.
     */
    IDRS_RECT GetDestination () const;
    /**
     * \brief Set the bookmark destination (positioning on the page).
     *
     * \param stDestination The destination to set
     *
     * \remarks The destination's coordinates actually used to write the bookmark depend on the display mode set:
     * - iTop: used by modes PageWidth, ContentWidth, Rectangle, Zoom
     * - iLeft: used by modes PageHeight, ContentHeight, Rectangle, Zoom
     * - iBottom and iRight: used by mode Rectangle only
     */
    void SetDestination ( const IDRS_RECT & stDestination );
    /**
     * \brief Get the bookmark zoom factor.
     *
     * \return The bookmark zoom factor, expressed as a percentage.
     */
    IDRS_UINT GetZoomFactor () const;
    /**
     * \brief Set the bookmark zoom factor.
     *
     * \param uiZoomFactor The zoom factor to set
     *
     * \remarks The zoom factor is used only if the display mode is set to Zoom. The magnification level of the page will
     * then be set to the zoom factor.
     * A zoom factor of 100 (i.e. 100%) means the page will be displayed with its actual size.
     *
     * \pre uiZoomFactor > 0
     */
    void SetZoomFactor ( const IDRS_UINT & uiZoomFactor );
  private:
    //! Internal use
    CPageBookmarkData & TypedObject () const
    {
      return (CPageBookmarkData &) Object ();
    };
  };
  /*
   *
   */
  CPageBookmark::CPageBookmark ()
  {
  }
  /*
   *
   */
  CPageBookmark::CPageBookmark ( const CPageBookmark& argPageBookmark )
    : CPageCustomData ((CPageCustomData&) argPageBookmark )
  {
  }
  /*
   *
   */
  CPageBookmark::CPageBookmark (CObj* pObj )
    : CPageCustomData ( pObj )
  {
  }
  /*
   *
   */
  CPageBookmark::~CPageBookmark ()
  {
  }
}
#endif // _CPageBookmark_h_
