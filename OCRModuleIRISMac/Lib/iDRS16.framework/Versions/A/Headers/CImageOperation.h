/**
 * \file CImageOperation.h
 * \brief Interface for the IDRS::CImageOperation class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _CImageOperation_h_
#define _CImageOperation_h_
#include <CPage.h>
namespace IDRS
{
  class CImageOperationData;
  /**
   * \brief The CImageOperation class represents the base class for the image operations related classes in iDRS SDK.
   * \ingroup module_prepro
   *
   * \req \ref IDRS::Module::Prepro
   */
  class IDRSKRN_API CImageOperation : public CObjPtr
  {
    public:
      /**
       * \brief Default constructor.
       */
      inline CImageOperation ();
      /**
       * \brief Copy constructor.
       *
       * \param argImageOperation The smart pointer to copy.
       */
      inline CImageOperation ( const CImageOperation & argImageOperation );
      /**
       * \brief Constructor.
       *
       * \param pImageOperationData The object to point to.
       */
      inline CImageOperation ( CImageOperationData * pImageOperationData );
      /**
       * \brief Destructor
       */
      inline virtual ~CImageOperation ();
    protected:
      /**
       * \brief Get the black and white image (a.k.a. work image) of the provided page
       * \pre ! argPage.IsNull ()
       *
       * \param argPage The provided CPage object
       * \return The work image of the provided page if available. Otherwise, an empty image object is returned.
       */
      CImage GetBlackAndWhiteImage ( const CPage & argPage ) const;
      /**
       * \brief Get the source image of the provided page.
       * \pre ! argPage.IsNull ()
       *
       * \param argPage The page
       *
       * \return The source image of a page.
       */
      CImage GetSourceImage ( const CPage & argPage ) const;
    private:
      // For internal use only
      CImageOperationData & TypedObject () const
      {
        return ( CImageOperationData & )Object ();
      };
  };
  /*
   *
   */
  inline CImageOperation::CImageOperation ()
  {
  }
  /*
   *
   */
  inline CImageOperation::CImageOperation ( const CImageOperation & argImageOperation )
    : CObjPtr (( CObjPtr & )argImageOperation )
  {
  }
  /*
   *
   */
  inline CImageOperation::CImageOperation ( CImageOperationData * pImageOperationData )
    : CObjPtr (( CObj * )pImageOperationData )
  {
  }
  /*
   *
   */
  inline CImageOperation::~CImageOperation ()
  {
  }
} // namespace
#endif /* _CImageOperation_h_ */
