/**
 * \file CPageContent.h
 * \brief Interface for CPageContent class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _CPageContent_h_
#define _CPageContent_h_
 
#include "CPageGraphicShape.h"
#include "CPageSection.h"
#include "CPageMetadata.h"
#include "CPageStyle.h"
#include <vector>
#include "TObjPtrArray.h"
#include "CPageCustomData.h"

namespace IDRS
{
  class CPageContentData;
  /**
   * \brief CPageContent represents the results content of CPage.
   *
   * The content is editable, meaning that an integrator can easily update any part of the page content
   */
  class IDRSKRN_API CPageContent : public CPageCustomData
  {
  public:
    /**
     * \brief Default constructor
     */
    inline CPageContent();
    /**
     * \brief Copy constructor
     *
     * \param argPageContent2 Object to copy (shallow copy)
     */
    inline CPageContent(const CPageContent & argPageContent2);
    /**
     * \brief CPageContent constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageContent(CPageContentData * pObj);
    /**
     * \brief CPageContent constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageContent(CObj * pObj);
    /**
     * \brief Destructor
     */
    inline virtual ~CPageContent();
    /**
     * \brief Instantiates a new page content object with default values
     */
    static CPageContent Create();
    /**
     * \brief Create instantiates a new page content object and initializes the basic values
     *
     * \param iPageWidth Page width
     * \param iPageHeight Page height
     * \param iPageResolution Page resolution
     */
    static CPageContent Create(const IDRS_INT iPageWidth, const IDRS_INT iPageHeight, const IDRS_INT iPageResolution);
    /**
     * \brief Gets the page width.
     */
    IDRS_INT GetPageWidth() const;
    /**
     * \brief Gets the page height.
     */
    IDRS_INT GetPageHeight() const;
    /**
     * \brief Gets the page resolution.
     */
    IDRS_INT GetPageResolution() const;
    /**
     * \brief Gets the page margins.
     */
    MarginInfo GetPageMargins() const;
    /**
     * \brief Gets the main language used in the page.
     *
     * \note There might be several languages used in the page. The main language represents the language that is used more often.
     */
    Language GetPageMainLanguage() const;
    /**
     * \brief Gets an array with all sections in the page.
     */
    CPageSectionArray GetSections() const;
    /**
     * \brief Gets an array containing all graphic shapes in the page.
     */
    CPageGraphicShapeArray GetGraphicShapes() const;
    /**
     * \brief Retrieves a list containing all the the zones of the page content sorted by reading order.
     * 
     * \note A new array is created for retrieving the results, therefore any modification such as adding or 
     *       removing elements from that array has no effect on the page content.
     */
    const CPageZoneArray QueryPageZones() const;
    /**
     * \brief Sets the page width.
     *
     * \param iPageWidth Page width
     */
    void SetPageWidth(const IDRS_INT iPageWidth);
    /**
     * \brief Sets the page height.
     *
     * \param iPageHeight Page height
     */
    void SetPageHeight(const IDRS_INT iPageHeight);
    /**
     * \brief Sets the page resolution.
     *
     * \param iPageResolution Page resolution
     */
    void SetPageResolution(const IDRS_INT iPageResolution);
    /**
     * \brief Sets the page margins.
     *
     * \param stPageMargins Structure containing the page margins
     */
    void SetPageMargins(const MarginInfo & stPageMargins);
    /**
     * \brief Sets the main language used in the page.
     *
     * \param evPageLanguage Main language used in the page
     */
    void SetPageMainLanguage(const Language evPageLanguage);
    /**
     * \brief Sets the array containing the page sections.
     *
     * \param argSections Page sections array
     */
    void SetSections(const CPageSectionArray& argSections);
    /**
     * \brief Sets the array containing the graphic shapes.
     *
     * \param argShapes Array containing graphic shapes
     */
    void SetGraphicShapes(const CPageGraphicShapeArray& argShapes);
    /**
     * \brief Gets the style object associated to the page content.
     */
    CPageStyle GetPageStyle() const;
    /**
     * \brief Sets the page style associated to the page content.
     *
     * \param argPageStyle Page style object
     */
    void SetPageStyle(const CPageStyle& argPageStyle);
    /**
     * \brief Gets the page metadata.
     *
     * \return The page metadata.
     */
    CPageMetadata GetMetadata () const;
    /**
     * \brief Sets the page metadata.
     *
     * \pre !argPageMetadata.IsNull()
     *
     * \param argPageMetadata The metadata to set
     */
    void SetMetadata ( const CPageMetadata& argPageMetadata );
    /**
     * \brief Clears all elements in the page
     */
    void Clear();
  private:
    //! Internal use 
    CPageContentData & TypedObject() const
    {
      return (CPageContentData &)Object();
    };
  };

  /*
   *
   */
  inline CPageContent::CPageContent()
  {
  }
  /*
   *
   */
  inline CPageContent::CPageContent(const CPageContent & argPageContent2)
    : CPageCustomData((CPageCustomData&)argPageContent2)
  {
  }
  /*
   *
   */
  inline CPageContent::CPageContent(CPageContentData * pObj)
    : CPageCustomData((CPageCustomDataData*)pObj)
  {
  }
  /*
   *
   */
  inline CPageContent::CPageContent(CObj * pObj)
    : CPageCustomData(pObj)
  {
  }
  /*
   *
   */
  inline CPageContent::~CPageContent()
  {
  }
}
#endif // _CPageContent_h_
