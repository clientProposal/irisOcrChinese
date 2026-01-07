/**
 * \file CDarkBordersRemoval.h
 * \brief Interface for the IDRS::CDarkBordersRemoval class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _cdarkbordersremoval_h_
#define _cdarkbordersremoval_h_
#include <CIDRS.h>
#include <CImageOperation.h>
namespace IDRS
{
  class CDarkBordersRemovalData;
  /**
   * \brief The CDarkBordersRemoval class provides dark  borders removal capabilities.
   * \ingroup module_prepro
   *
   * It features an algorithm for automatic dark border detection and removal in all types of images: monochrome, grayscale or color.
   *
   * The integrator can also specify threshold under which the border pixels are considered "dark" by the dark border removal algorithm.
   * If not, the algorithm will use the following predefined values for the definition of "dark" borders:
   * - threshold under which the border pixels are considered "dark": 0x7A
   * - threshold under which the pixels connected to the border pixels are considered "dark": 0x7A
   * - value indicating the maximum difference in greyscale levels between 2 adjacent pixels: 0x1E
   *
   * \req IDRS::Module::Prepro
   *
   * \see Module::Prepro for information about the preprocessing library
   *
   */
  class IDRSKRN_API CDarkBordersRemoval : public CImageOperation
  {
    public:
      /**
       * \brief Default constructor.
       */
      inline CDarkBordersRemoval ();
      /**
       * \brief Copy constructor.
       *
       * \param argDarkBordersRemoval The smart pointer to copy.
       */
      inline CDarkBordersRemoval ( const CDarkBordersRemoval & argDarkBordersRemoval );
      /**
       * \brief Constructor.
       *
       * \param pDarkBordersRemovalData The object to point to.
       */
      inline CDarkBordersRemoval ( CDarkBordersRemovalData * pDarkBordersRemovalData );
      /**
       * \brief Destructor
       */
      inline virtual ~CDarkBordersRemoval ();
      /**
       * \brief Creates a new CDarkBordersRemoval object.
       *
       * \param argIDRS The iDRS
       *
       * \return The newly created CDarkBordersRemoval object.
       *
       * \throw CIDRSException if an error occur.
       */
      static CDarkBordersRemoval Create ( const CIDRS & argIDRS );
      /**
       * \brief RemoveDarkBorders removes dark borders in the given image.
       *
       * RemoveDarkBorders function works with all image types: black and white, greyscale and color images.
       *
       * The dark border is composed of the "dark" pixels present on the margins of the image and the "dark" pixels that are connected to them.
       *
       * The algorithm considers the following pixels as "dark" and clears them from the image:
       * <ul>
       *   <li> pixels that are on the image margins, with their greyscale levels lower than <b>ubDarkBorder</b> parameter
       *   <li> pixels that are connecting to at least 1 other "dark" pixels, with the greyscale levels below <b>ubDarkInside</b> parameter
       *   <li> pixels that are connecting to at least 1 other "dark" pixels, with the difference of the greyscale levels lower than <b>ubDelta</b> parameter
       * </ul>
       *
       * The parameter <b>bCropImage</b> specifies how the pixels that are found as part of the dark border surrounding the image are treated:
       * <ul>
       *   <li> If the parameter is IDRS_TRUE, then the image will be cropped and the dark borders will be removed from the image. In this case, the resulting image dimensions will be different than the input image.
       *   <li> If the parameters is IDRS_FALSe, then the "dark" pixels will be changed to white color. 
       * </ul>
       *
       * \pre ! IsNull ()
       * \pre ! argImageSource.IsNull ()
       *
       * \param argImage The image where dark borders will be removed
       * \param bCropImage Boolean flag specifying if the image will be cropped to remove the dark borders
       * \param ubDarkBorder Greyscale value indicating the threshold under which the border pixels are considered "dark"
       * \param ubDarkInside Greyscale value indicating the threshold under which the pixels connected to the border pixels are considered "dark"
       * \param ubDelta Value indicating the maximum difference in greyscale levels between 2 adjacent pixels. 
       * If one of the pixels is "dark" and the difference is lower than ubDelta, both pixels are considered "dark"
       *
       * \throw CIDRSException if an error occur.
       */
      void RemoveDarkBorders ( CImage & argImage, const IDRS_BOOL bCropImage, const IDRS_UCHAR ubDarkBorder = 0x7a,
                               const IDRS_UCHAR ubDarkInside = 0x7a, const IDRS_UCHAR ubDelta = 0x1E ) const;
      /**
       * \brief SetMaxBorderWidth sets the page dark border width limitation.
       *
       * The default value is 0, meaning that the dark border removal can filter out any number of pixels that are considered "border"
       * When the margin is set to any other value than 0, the dark border removal will occur only in the margin defined by the specified value.
       * If border width is larger equal or equal to width/2 or border height is larger or equal to height/2, an exception is thrown (IDRS_ERROR_PREPRO_DARKBORDER_REMOVAL_INVALID_MARGINS)
       *
       * Please note that setting the page margins increases the computation time.
       *
       * \param uiMaxBorderWidth Maximum border width where the dark border algorithm will work
       */
      void SetMaxBorderWidth(const IDRS_UINT uiMaxBorderWidth);
      /**
       * \brief Get the max border width.
       *
       * \return the value set for maximum border width
       */
      IDRS_UINT GetMaxBorderWidth() const;
      /**
       * \brief SetMaxBorderHeight sets the page dark border height limitation.
       *
       * The default value is 0, meaning that the dark border removal can filter out any number of pixels that are considered "border"
       * When the margin is set to any other value than 0, the dark border removal will occur only in the margin defined by the specified value.
       * If border width is larger equal or equal to width/2 or border height is larger or equal to height/2, an exception is thrown (IDRS_ERROR_PREPRO_DARKBORDER_REMOVAL_INVALID_MARGINS)
       *
       * Please note that setting the page margins increases the computation time.
       *
       * \param uiMaxBorderHeight Maximum border height where the dark border algorithm will work
       */
      void SetMaxBorderHeight(const IDRS_UINT uiMaxBorderHeight);
      /**
       * \brief Get the max border height.
       *
       * \return the value set for maximum border height
       */
      IDRS_UINT GetMaxBorderHeight() const;
    private:
      //
      CDarkBordersRemovalData & TypedObject () const
      {
        return ( CDarkBordersRemovalData & )Object ();
      };
  };
  /*
   *
   */
  inline CDarkBordersRemoval::CDarkBordersRemoval ()
  {
  }
  /*
   *
   */
  inline CDarkBordersRemoval::CDarkBordersRemoval ( const CDarkBordersRemoval & argDarkBordersRemoval )
    : CImageOperation (( CImageOperation & )argDarkBordersRemoval )
  {
  }
  /*
   *
   */
  inline CDarkBordersRemoval::CDarkBordersRemoval ( CDarkBordersRemovalData * pDarkBordersRemovalData )
    : CImageOperation (( CImageOperationData * )pDarkBordersRemovalData )
  {
  }
  /*
   *
   */
  inline CDarkBordersRemoval::~CDarkBordersRemoval ()
  {
  }
} //namespace
#endif /* _cdarkbordersremoval_h_ */
