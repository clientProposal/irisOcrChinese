/**
 * \file CDespeckle.h
 * \brief Interface for the IDRS::CDespeckle class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _CDespeckle_h_
#define _CDespeckle_h_
#include <CIDRS.h>
#include <CImageOperation.h>
#include <CPolygon.h>
#include <IDespeckleCallback.h>
namespace IDRS
{
  class CDespeckleData;
  /**
   * \brief The CDespeckle class provides image noise reduction features via an image despeckle filter
   * \ingroup module_prepro
   *
   * It works only with black and white images
   *
   * \req IDRS::Module::Prepro
   *
   * \see Module::Prepro
   */
  class IDRSKRN_API CDespeckle : public CImageOperation
  {
    public:
      /**
       * \brief Default constructor.
       */
      inline CDespeckle ();
      /**
       * \brief Copy constructor.
       *
       * \param argDespeckle The smart pointer to copy.
       */
      inline CDespeckle ( const CDespeckle & argDespeckle );
      /**
       * \brief Constructor.
       *
       * \param pDespeckleData The object to point to.
       */
      inline CDespeckle ( CDespeckleData * pDespeckleData );
      /**
       * \brief Destructor
       */
      inline virtual ~CDespeckle ();
      /**
       * \brief Creates a new CDespeckle object.
       *
       * \param argIDRS The iDRS
       *
       * \return The newly created CDespeckle object.
       *
       * \throw CIDRSException if an error occur.
       */
      static CDespeckle Create ( const CIDRS & argIDRS );
      /**
       * \brief Despeckle removes all the groups of connected pixels with a number of pixels below the SpeckleMaxSize property.
       *
       * Those connected pixels are not removed if the distance to a larger connected component is below the Dilatation property.
       * As a result only the isolated pixels get deleted.
       *
       * \attention Despeckling is only available for black and white images.
       *
       * \pre ! IsNull ()
       * \pre ! argImage.IsNull ()
       * \pre argImage.GetColorMode () == ColorMode::BlackAndWhite
       *
       * \param argImage The image to despeckle.
       */
      void Despeckle ( CImage & argImage );
      /**
       * \brief Despeckle removes all the groups of connected pixels with a number of pixels below the SpeckleMaxSize property.
       *
       * Those connected pixels are not removed if the distance to a larger connected component is below the Dilatation property.
       * As a result only the isolated pixels get deleted.
       *
       * \attention Despeckling is only available for black and white images.
       *
       * \pre ! IsNull ()
       * \pre ! argImage.IsNull ()
       * \pre ! argPolygon.IsNull ()
       * \pre argImage.GetColorMode () == ColorMode::BlackAndWhite
       *
       * \param argImage The image to despeckle.
       * \param argPolygon The area to process.
       *
       */
      void Despeckle ( CImage & argImage, const CPolygon & argPolygon );
      /**
       * \brief Set the maximum size (area in pixels) of the connected pixels to be removed.
       *
       * \remarks The speckle max size is not used if a callback is registered.
       * 
       * \param uiSpeckleMaxSize The speckle max size.
       */
      void SetSpeckleMaxSize(const IDRS_UINT uiSpeckleMaxSize);
      /**
       * \brief Get the maximum size (area in pixels) of the connected pixels to be removed.
       *
       * \remarks Default value is set to 12.
       *
       * \return The speckle max size.
       */
      IDRS_UINT GetSpeckleMaxSize() const;
      /**
       * \brief Set the dilatation value (in pixels) that will be used during despeckling.
       *
       * \param uiDilatation The dilatation.
       */
      void SetDilatation(const IDRS_UINT uiDilatation);
      /**
       * \brief Get the dilatation value (in pixels) that will be used during despeckling.
       *
       * \remarks Default value is set to 0.
       *
       * \return The speckle max size.
       */
      IDRS_UINT GetDilatation() const;
      /**
       * \brief Set the despeckle type to perform.
       *
       * \param evDespeckleType The despeckle type.
       */
      void SetDespeckleType(const DespeckleType evDespeckleType);
      /**
       * \brief Get the despeckle type to perform.
       *
       * \remarks Default value is set to DespeckleType::Black.
       */
      DespeckleType GetDespeckleType() const;
      /**
       * \brief Gets the callback used to indicate which groups of connected pixels to remove.
       *
       * \return The callback pointer
       */
      IDespeckleCallback* GetDespeckleCallback() const;
      /**
       * \brief Sets the callback used to indicate which groups of connected pixels to remove.
       *
       * \param pDespeckleCallback Callback pointer to set
       */
      void SetDespeckleCallback(IDespeckleCallback* pDespeckleCallback);
    private:
      // For internal use only
      CDespeckleData & TypedObject () const
      {
        return ( CDespeckleData & )Object ();
      };
  };
  /*
   *
   */
  inline CDespeckle::CDespeckle ()
  {
  }
  /*
   *
   */
  inline CDespeckle::CDespeckle ( const CDespeckle & argDespeckle )
    : CImageOperation (( CImageOperation & )argDespeckle )
  {
  }
  /*
   *
   */
  inline CDespeckle::CDespeckle ( CDespeckleData * pDespeckleData )
    : CImageOperation (( CImageOperationData * )pDespeckleData )
  {
  }
  /*
   *
   */
  inline CDespeckle::~CDespeckle ()
  {
  }
} // namespace
#endif /* _CDespeckle_h_ */
