/**
 * \file CPageZoneGraphicExternalImage.h
 * \brief Interface for CPageZoneGraphicExternalImage class
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */

#ifndef _CPageZoneGraphicExternalImage_h_
#define _CPageZoneGraphicExternalImage_h_

#include "CPageZoneGraphic.h"
#include "CImage.h"

namespace IDRS
{
  class CPageZoneGraphicExternalImageData;
  /**
   * \brief CPageZoneGraphicExternalImage represents a zone that is loaded from an external source
   *
   * By default the image zones in iDRS SDK represent parts of the source image for a document.
   * The class CPageZoneGraphicExternalImage allows integrators to specify image zones that have the source in other images.
   * This allows greater flexibility when creating output documents.
   *
   * \important Currently the external images are used only as part of \see CSignatureContent class.
   * Trying to add an external graphical image to \see CPageContent2 would have no effect in the output.
   *
   */
  class IDRSKRN_API CPageZoneGraphicExternalImage : public CPageZoneGraphic
  {
  public:
    /**
     * \brief Default constructor
     */
    inline CPageZoneGraphicExternalImage();
    /**
     * \brief Copy constructor
     *
     * \param argCPageZoneGraphicExternalImage Object to copy (shallow copy)
     */
    inline CPageZoneGraphicExternalImage(const CPageZoneGraphicExternalImage& argCPageZoneGraphicExternalImage);
    /**
     * \brief CPageZoneGraphicExternalImage constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pargCPageZoneGraphicExternalImageData Pointer to an object representing the data class
     */
    inline CPageZoneGraphicExternalImage(CPageZoneGraphicExternalImageData* pargCPageZoneGraphicExternalImageData);
    /**
     * \brief Destructor
     */
    inline virtual ~CPageZoneGraphicExternalImage();
    /**
     * \brief Creates a new instance of CPageZoneGraphicExternalImage and initializes it with an image
     *
     * \param argImage Image that will be used as page graphical zone
     *
     * \return IDRS::CPageZoneGraphicExternalImage newly created object
     */
    static CPageZoneGraphicExternalImage Create(const CImage& argImage);
    /**
     * \brief Sets the image associated with the page graphical image
     *
     * \param argImage CImage object
     */
    void SetImage(const CImage& argImage);
    /**
     * \brief Returns the image associated with the page graphical image
     */
    CImage GetImage() const;

  private:
    //! Internal use
    CPageZoneGraphicExternalImageData& TypedObject() const
    {
      return (CPageZoneGraphicExternalImageData&)Object();
    };
  };
  /*
   *
   */
  inline CPageZoneGraphicExternalImage::CPageZoneGraphicExternalImage()
  {
  }
  /*
   *
   */
  inline CPageZoneGraphicExternalImage::CPageZoneGraphicExternalImage(const CPageZoneGraphicExternalImage& argCPageZoneGraphicExternalImage)
    : CPageZoneGraphic((CPageZoneGraphic&)argCPageZoneGraphicExternalImage)
  {
  }
  /*
   *
   */
  inline CPageZoneGraphicExternalImage::CPageZoneGraphicExternalImage(CPageZoneGraphicExternalImageData* pargCPageZoneGraphicExternalImageData)
    : CPageZoneGraphic((CObj *)pargCPageZoneGraphicExternalImageData)
  {
  }
  /*
   *
   */
  inline CPageZoneGraphicExternalImage::~CPageZoneGraphicExternalImage()
  {
  }
}
#endif // _CPageZoneGraphicExternalImage_h_
