/**
 * \file CPage.h
 * \brief Interface for the IDRS::CPage class.
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _CPage_h_
#define _CPage_h_
#include "CImage.h"
#include "ILineReader.h"
#include "CPageContent.h"
#include "TObjPtrArray.h"

namespace IDRS
{

  class CPageData;
  class CImageOperation;
  class IBaseImagePlugin;
  class CPageContent;
  /**
   * \brief The CPage class manages a page in the IDRS.
   * \ingroup module_core module_ocr module_barcode
   *
   * A page contains the following entities:
   * - source image
   * - binarized image in case the source image is not monochrome
   * - zoning information - information about the recognized zones in the image and their type
   * - recognition results - after the recognition process, the page object keeps a reference to the result
   *
   */
  class IDRSKRN_API CPage : public CObjPtr
  {
    public:
      friend class CImageOperation;
      friend class CFormsOperation;
      friend class CExport;
      friend class CIDRSObjectAccess;
      //
      inline CPage ();
      //
      inline CPage ( const CPage & aPage );
      //
      inline CPage ( CObj * pObj );
      //
      inline virtual ~CPage ();
      /**
       * \brief Create creates a new page.
       *
       * All contained images (Source, Work, and Background) will remain NULL.
       *
       * \param argIDRS - CIDRS handle object
       *
       * \return The newly created page.
       *
       * \throw CIDRSException if an error occur.
       */
      static CPage Create ( CIDRS & argIDRS );
      /**
       * \brief Create creates a new page from an existing image.
       *
       * The provided image will be set as the page's Source, and both Work and Background images will be NULL.
       *
       * \pre ! argImage.IsNull ()
       * \pre argImage.GetHeight () && argImage.GetWidth ()
       *
       * Note that the provided image instance will be associated with the newly created page using a shallow copy.
       * This means that any further change to the provided CImage will affect the CPage object.
       * 
       * \param argImage The image to set as source image.
       *
       * \return The newly created page.
       *
       * \throw CIDRSException if an error occur.
       */
      static CPage Create ( const CImage & argImage );
      /**
       * \brief SetSourceImage sets the source image for the page.
       *
       * \pre ! IsNull ()
       * \pre ! argImage.IsNull ()
       * \pre argImage.GetHeight () && argImage.GetWidth ()
       * \pre argImage.GetColorMode () == ColorMode::BlackAndWhite || argImage.GetColorMode () == ColorMode::Greyscale || argImage.GetColorMode () == ColorMode::Color
       * 
       * Note that the provided image instance will be associated with this page using a shallow copy.
       * This means that any further change to the provided CImage object will affect the CPage object.
       *
       * \param argImage The image to set as a source image.
       *
       * \throw CIDRSException if an error occur.
       */
      void SetSourceImage ( const CImage & argImage );
      /**
       * \brief Gets the source image associated to the current CPage object
       *
       * \return The source image associated to this CPage object
       */
      CImage GetSourceImage() const;
      /**
       *
       * \pre ! IsNull ()
       *
       * \retval The width of the page.
       * \return 0 if there's no image for the page.
       */
      IDRS_UINT GetWidth () const;
      /**
       *
       * \pre ! IsNull ()
       *
       * \retval The height of the page.
       * \return 0 if there's no image for the page.
       */
      IDRS_UINT GetHeight () const;
      /**
       *
       * \pre ! IsNull ()
       * \pre GetHeight () && GetWidth ()
       *
       * \return The resolution of the source image.
       */
      IDRS_UINT GetResolution () const;
      /**
       * \brief Gets page access content of the page via CPageContent class.
       *
       * Using CPageContent class provides an integrator with read/write access to page content
       *
       * \pre ! IsNull ()
       *
       * \return Read/write access to the page content.
       */
      CPageContent GetPageContent () const;
      /**
       * \brief Sets the CPageContent object associated with the CPage object.
       *
       * Using CPageContent class provides an integrator with read/write access to page content
       *
       * \pre ! IsNull ()
       * 
       * \param argPageContent CPageContent object that will be associated to the CPage
       */
      void SetPageContent(const CPageContent& argPageContent) const;
      /**
       * \brief Sets the work image that can be used by the processing engines (page analysis, barcode processing and text recognition)
       *
       * \pre ! IsNull ()
       *
       * The work image is an optional black & white image which can be used by page analysis, text recognition and barcode detection algorithms. 
       * If this image is set, it will be provided to the concerned engines in addition to the source image, in order to help recognition. 
       * The work image needs to be black & white, and have the same characteristics than the source image (dimensions and resolution).
       *
       * The work image can be changed during the deskew process, if there's a skew angle detected.
       *
       * \param argImage Black&white image that will be used by processing engines
       */
      void SetWorkImage(const CImage& argImage);
      /**
       * \brief Gets the work image set into the CPage object
       *
       * \pre ! IsNull ()
       *
       * \return Work image associated to the CPage object
       */
      CImage GetWorkImage() const;
      /**
       * \brief Sets the background image to use during document output if required.
       *
       * \pre ! IsNull ()
       * 
       * The Background image is an optional image which can be computed during text recognition. 
       * It will correspond to the source image with all detected text erased from it. 
       * It can therefore be used later when creating output formats needing such background image (Docx with Exact layout for instance).
       *
       * The background image can be changed during the deskew process, if there's a skew angle detected.
       *
       * \param argBackgroundImage The background image
       */
      void SetBackgroundImage(const CImage& argBackgroundImage);
      /**
       * \brief Gets the background image to use during document output if required.
       *
       * \return The background image
       */
      CImage GetBackgroundImage() const;
    private:
      //
      CPageData & TypedObject () const
      {
        return ( CPageData & )Object ();
      };
  };
  typedef TObjPtrArray<CPage> CPageArray;
  /*
   *
   */
  inline CPage::CPage ()
  {
  }
  /*
   *
   */
  inline CPage::CPage ( const CPage & aPage )
    : CObjPtr (( CObjPtr & )aPage )
  {
  }
  /*
   *
   */
  inline CPage::CPage ( CObj * pObj )
    : CObjPtr ( pObj )
  {
  }
  /*
   *
   */
  inline CPage::~CPage ()
  {
  }
} // namespace
#endif /* _CPage_h_ */
