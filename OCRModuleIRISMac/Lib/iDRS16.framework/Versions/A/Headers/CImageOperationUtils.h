/**
 * \file CImageOperationUtils.h
 * \brief Interface for the IDRS::CImageOperationUtils class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _CImageOperationUtils_h_
#define _CImageOperationUtils_h_
#include <CImageOperation.h>
#include <CIDRS.h>
#include <CImage.h>
#include <CPolygon.h>
#include <CPage.h>
namespace IDRS
{
  class CImageOperationUtilsData;
  /**
   * \brief The CImageOperationUtils class offers image operation utilities.
   * \ingroup module_prepro
   *
   * \req \ref IDRS::Module::Prepro
   */
  class IDRSKRN_API CImageOperationUtils : public CImageOperation
  {
    public:
      /**
       * \brief Default constructor.
       */
      inline CImageOperationUtils ();
      /**
       * \brief Copy constructor.
       *
       * \param argImageOperationUtils The smart pointer to copy.
       */
      inline CImageOperationUtils ( const CImageOperationUtils & argImageOperationUtils );
      /**
       * \brief Constructor.
       *
       * \param pImageOperationUtilsData The object to point to.
       */
      inline CImageOperationUtils ( CImageOperationUtilsData * pImageOperationUtilsData );
      /**
       * \brief Destructor
       */
      inline virtual ~CImageOperationUtils ();
      /**
       * \brief Creates a new CImageOperationUtils object.
       *
       * \param argIdrs The iDRS
       *
       * \return The newly created CImageOperationUtils object.
       *
       * \throw CIDRSException if an error occur.
       */
      static CImageOperationUtils Create ( const CIDRS & argIdrs );
      /**
       * \brief Extracts the given area from the image to the target image.
       *
       * \pre ! argPolygon.IsNull ()
       * \pre ! argImage.IsNull ()
       * \pre argImageTarget != argImage
       *
       * \param argImageTarget The image to create.
       * \param argPolygon The area to extract.
       * \param argImage The image to process.
       *
       * \throw CIDRSException if an error occur.
       */
      void ExtractArea ( CImage & argImageTarget, const CPolygon & argPolygon, const CImage & argImage );
      /**
       * \brief Extracts the given area from an image of the page.
       *
       * \pre ! argPolygon.IsNull ()
       * \pre ! argPage.IsNull ()
       * \pre ! bExtractFromBlackAndWhiteImage || argPage.IsBlackAndWhiteImageAvailable ()
       *
       * \param argImageTarget The image to create.
       * \param argPolygon The area to extract.
       * \param argPage The page to process.
       * \param bExtractFromBlackAndWhiteImage If IDRS_TRUE, the image is extracted from the page's black and white image.
       *
       * \throw CIDRSException if an error occur.
       */
      void ExtractArea ( CImage & argImageTarget, const CPolygon & argPolygon, const CPage & argPage, const IDRS_BOOL bExtractFromBlackAndWhiteImage );
      /**
       * \brief Extracts the given area from the image to the target image.
       *
       * \pre ! argImage.IsNull ()
       * \pre argImageTarget != argImage
       *
       * \param argImageTarget The image to create.
       * \param rc The area to extract.
       * \param argImage The image to process.
       *
       * \throw CIDRSException if an error occur.
       */
      void ExtractArea ( CImage & argImageTarget, const IDRS_RECT & rc, const CImage & argImage );
      /**
       * \brief Extracts the given area from an image of the page.
       *
       * \pre ! argPage.IsNull ()
       * \pre ! bExtractFromBlackAndWhiteImage || argPage.IsBlackAndWhiteImageAvailable ()
       *
       * \param argImageTarget The image to create.
       * \param rc The area to extract.
       * \param argPage The page to process.
       * \param bExtractFromBlackAndWhiteImage If IDRS_TRUE, the image is extracted from the page's black and white image.
       *
       * \throw CIDRSException if an error occur.
       */
      void ExtractArea ( CImage & argImageTarget, const IDRS_RECT & rc, const CPage & argPage, const IDRS_BOOL bExtractFromBlackAndWhiteImage );
    private:
      // For internal use only
      CImageOperationUtilsData & TypedObject () const
      {
        return ( CImageOperationUtilsData & )Object ();
      };
  };
  /*
   *
   */
  inline CImageOperationUtils::CImageOperationUtils ()
  {
  }
  /*
   *
   */
  inline CImageOperationUtils::CImageOperationUtils ( const CImageOperationUtils & argImageOperationUtils )
    : CImageOperation (( CImageOperation & )argImageOperationUtils )
  {
  }
  /*
   *
   */
  inline CImageOperationUtils::CImageOperationUtils ( CImageOperationUtilsData * pImageOperationUtilsData )
    : CImageOperation (( CImageOperationData * )pImageOperationUtilsData )
  {
  }
  /*
   *
   */
  inline CImageOperationUtils::~CImageOperationUtils ()
  {
  }
} // namespace
#endif /* _CImageOperationUtils_h_ */
