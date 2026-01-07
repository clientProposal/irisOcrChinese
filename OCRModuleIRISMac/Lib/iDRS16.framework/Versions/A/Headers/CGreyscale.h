/**
 * \file CGreyscale.h
 * \brief Interface for the IDRS::CGreyscale class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _CGreyscale_h_
#define _CGreyscale_h_
#include <CImageOperation.h>
#include <CIDRS.h>
#include <CImage.h>
namespace IDRS
{
  class CGreyscaleData;
  /**
   * \brief The CGreyscale class offers image greyscale conversion
   * \ingroup module_prepro
   *
   * This class contains an algorithm for converting color images to greyscale.
   *
   * \req IDRS::Module::Prepro
   */
  class IDRSKRN_API CGreyscale : public CImageOperation
  {
    public:
      /**
       * \brief Default constructor.
       */
      inline CGreyscale ();
      /**
       * \brief Copy constructor.
       *
       * \param argGreyscale The smart pointer to copy.
       */
      inline CGreyscale ( const CGreyscale & argGreyscale );
      /**
       * \brief Constructor.
       *
       * \param pGreyscaleData The object to point to.
       */
      inline CGreyscale ( CGreyscaleData * pGreyscaleData );
      /**
       * \brief Destructor
       */
      inline virtual ~CGreyscale ();
      /**
       * \brief Creates a new CGreyscale object.
       *
       * \param argIDRS The iDRS
       *
       * \return The newly created CGreyscale object.
       *
       * \throw CIDRSException if an error occur.
       */
      static CGreyscale Create ( const CIDRS & argIDRS );
      /**
       * \brief Greyscale converts an image to greyscale.
       *
       * \pre ! argImageSource.IsNull ()
       *
       * \param argIDRS The iDRS
       * \param argImage The image where greyscale operation will be applied
       *
       */
      static void Greyscale ( const CIDRS & argIDRS, CImage & argImage );
      /**
       * \brief Greyscale converts an image to greyscale.
       *
       * \pre ! argImageSource.IsNull ()
       *
       * \param argImage The image where greyscale operation will be applied
       *
       */
      void Greyscale ( CImage & argImage );
    private:
      // For internal use only
      CGreyscaleData & TypedObject () const
      {
        return ( CGreyscaleData & )Object ();
      };
  };
  /*
   *
   */
  inline CGreyscale::CGreyscale ()
  {
  }
  /*
   *
   */
  inline CGreyscale::CGreyscale ( const CGreyscale & argGreyscale )
    : CImageOperation (( CImageOperation & )argGreyscale )
  {
  }
  /*
   *
   */
  inline CGreyscale::CGreyscale ( CGreyscaleData * pGreyscaleData )
    : CImageOperation (( CImageOperationData * )pGreyscaleData )
  {
  }
  /*
   *
   */
  inline CGreyscale::~CGreyscale ()
  {
  }
} // namespace
#endif /* _CGreyscale_h_ */
