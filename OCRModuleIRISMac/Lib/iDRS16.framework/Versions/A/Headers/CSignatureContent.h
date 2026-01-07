/**
 * \file CSignatureContent.h
 * \brief Interface for CSignatureContent class
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */

#ifndef _CSignatureContent_h_
#define _CSignatureContent_h_

#include "CObjPtr.h"
#include "CPageZone.h"

namespace IDRS
{
  class CSignatureContentData;
  /**
   * \brief CSignatureContent contains the UI elements for displaying a signature on a PDF document
   *
   * The class is a light weight version of CPageContent2, allowing the integrators to define custom zones,
   * paragraphs, lines, words and text elements having custom styles and fonts
   */
  class IDRSKRN_API CSignatureContent : public CObjPtr
  {
  public:
    /**
     * \brief Default constructor
     */
    inline CSignatureContent();
    /**
     * \brief Copy constructor
     *
     * \param argSignatureContent Object to copy (shallow copy)
     */
    inline CSignatureContent(const CSignatureContent& argSignatureContent);
    /**
     * \brief CSignatureContent constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CSignatureContent(CSignatureContentData* pObj);
    /**
     * \brief Destructor
     */
    inline virtual ~CSignatureContent();
    /**
     * \brief Creates a new CSignatureContent object
     *
     * \return The newly created CPdfOutputParameters object.
     *
     * \throw CIDRSException if an error occur.
     */
    static CSignatureContent Create();
    /**
     * \brief Sets the area where the signature will be placed on pdf page.
     *
     * The coordinates are expressed in pixels.
     * While the coordinates are expected to be in the page bounding box, there is no strict enforcement on this rule.
     * In case the coordinates are partially in the page area, only that part of the signature will appear on the pdf document.
     *
     * \param rcSignatureArea Rectangle where the signature will be displayed
     */
    void SetSignatureArea(const IDRS_RECT& rcSignatureArea);
    /**
     * \brief Gets the area where the signature will be inserted in the pdf page.
     *
     * \return Rectangle representing the area where the signature will be inserted in the pdf page.
     */
    IDRS_RECT GetSignatureArea() const;
    /**
     * \brief Gets an array containing the zones in the signature.
     */
    CPageZoneArray GetZones() const;
    /**
     * \brief Sets the zones in the signature.
     *
     * \important The zone coordinates need to be included in the signature bounding box.
     *
     * \param xZones List of zones
     */
    void SetZones(const CPageZoneArray& xZones);
  private:
    //! Internal use
    CSignatureContentData& TypedObject() const
    {
      return (CSignatureContentData&)Object();
    };
  };
  /*
   *
   */
  inline CSignatureContent::CSignatureContent()
  {
  }
  /*
   *
   */
  inline CSignatureContent::CSignatureContent(const CSignatureContent& argPageParagraphsGroup)
    : CObjPtr((CObjPtr&)argPageParagraphsGroup)
  {
  }
  /*
   *
   */
  inline CSignatureContent::CSignatureContent(CSignatureContentData* pObj)
    : CObjPtr((CObj*)pObj)
  {
  }
  /*
   *
   */
  inline CSignatureContent::~CSignatureContent()
  {
  }
}
#endif // _CSignatureContent_h_
