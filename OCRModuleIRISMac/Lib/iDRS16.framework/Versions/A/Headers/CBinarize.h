/**
 * \file CBinarize.h
 * \brief Interface for the IDRS::CBinarize class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _CBinarize_h_
#define _CBinarize_h_
#include <CIDRS.h>
#include <CImageOperation.h>
#include <CPage.h>
#include <IBinarizeCallback.h>
namespace IDRS
{
  class CBinarizeData;
  /**
   * \brief The CBinarize class offers image binarization features
   * \ingroup module_prepro
   *
   * Binarization is the first stage in image recognition. It convert the input image into a black & white image for faster processing.
   * The CBinarize class offers the following image binarization algorithms:
   * - threshold binarization - uses a global threshold value is used for computing the result image.
   * - adaptive binarization  - uses different thresholds for different regions of the image.
   *
   * \req IDRS::Module::Prepro
   *
   * \see Module::Prepro
   */
  class IDRSKRN_API CBinarize : public CImageOperation
  {
    public:
      /**
       * \brief Default constructor.
       */
      inline CBinarize ();
      /**
       * \brief Copy constructor.
       *
       * \param argBinarize The smart pointer to copy.
       */
      inline CBinarize ( const CBinarize & argBinarize );
      /**
       * \brief Constructor.
       *
       * \param pBinarizeData The object to point to.
       */
      inline CBinarize ( CBinarizeData * pBinarizeData );
      /**
       * \brief Destructor
       */
      inline virtual ~CBinarize ();
      /**
       * \brief Creates a new CBinarize object.
       *
       * \param argIDRS The iDRS
       *
       * \return The newly created CBinarize object.
       *
       * \throw CIDRSException if an error occur.
       */
      static CBinarize Create ( const CIDRS & argIDRS );
      /**
       * Binarize the provided color/greyscale image.
       *
       * \pre ! argImage.IsNull ()
       *
       * \param argImage The image to binarize
       *
       * \return The binarized image
       *
       * \throw CIDRSException if an error occur.
       */
      CImage Binarize ( const CImage & argImage );
      /**
       * Binarize the provided color/greyscale using default parameters:
       * - Adaptive binarization
       * - Smoothing level 248
       * - Undithering desactivated
       *
       * \pre ! argImage.IsNull ()
       *
       * \param argIDRS The iDRS
       * \param argImage The image to binarize
       *
       * \throw CIDRSException if an error occur.
       */
      static CImage Binarize ( const CIDRS & argIDRS, const CImage & argImage );
      /**
       * \brief Set the type of binarization to use.
       *
       * \param evBinarizationType The type of binarization to use.
       */
      void SetBinarizationType(const BinarizationType evBinarizationType);
      /**
       * \brief Get the type of binarization to use.
       *
       * \remarks Default value is BinarizationType::Adaptive.
       *
       * \return The type of binarization to use.
       */
      BinarizationType GetBinarizationType() const;
      /**
       * \brief Sets the strength of the smoothing operation applied during binarization.
       *
       * \remarks Valid range goes from 0 to 255; values outside of this range will be clamped to it.
       *
       * \param iSmoothingLevel The smoothing level.
       */
      void SetSmoothingLevel(const IDRS_INT iSmoothingLevel);
      /**
       * \brief Gets the strength of the smoothing operation applied during binarization.
       *
       * \remarks Default value is 248.
       *
       * \return The smoothing level
       */
      IDRS_INT GetSmoothingLevel() const;
      /**
       * \brief Sets the global threshold to be use during binarization.
       *
       * \remarks Adaptive and Automatic-Threshold binarizations do not use this value.
       *
       * \remarks Valid range goes from 0 to 255; values outside of this range will be clamped to it.
       *
       * \param iGlobalThreshold The binarization global threshold.
       */
      void SetGlobalThreshold(const IDRS_INT iGlobalThreshold);
      /**
       * \brief Gets the global threshold to be use during binarization.
       *
       * \remarks Default value is 128.
       *
       * \return The binarization global threshold
       */
      IDRS_INT GetGlobalThreshold() const;
      /**
       * \brief Sets the brightness adjustment to apply during binarization.
       *
       * \remarks Valid range goes from 0 to 255; values outside of this range will be clamped to it.
       * \remarks Higher values will darken the resulting image
       *
       * \param iBrightness The brightness.
       */
      void SetBrightness(const IDRS_INT iBrightness);
      /**
       * \brief Gets the brightness adjustment to apply during binarization.
       *
       * \remarks Default value is 128.
       *
       * \return The brightness
       */
      IDRS_INT GetBrightness() const;
      /**
       * \brief Sets the contrast adjustment to apply during binarization.
       *
       * \remarks Valid range goes from 0 to 255; values outside of this range will be clamped to it.
       * \remarks Lower values will darken the resulting image
       *
       * \param iContrast The contrast.
       */
      void SetContrast(const IDRS_INT iContrast);
      /**
       * \brief Gets the contrast adjustment to apply during binarization.
       *
       * \remarks Default value is 40.
       *
       * \return The contrast
       */
      IDRS_INT GetContrast() const;
      /**
       * \brief Sets the automatic undithering when binarizing a page.
       *
       * Dithering is a scanning technique which consists in representing a color or greyscale image using
       * only a limited color palette. This allows to reduce file size while maintaining the general aspect of the image.
       *
       * This technique is known to create images more difficult to handle for OCR technology; this is why specific
       * image preprocessing is needed to detect and revert it.
       *
       * \param bUndithering IDRS_TRUE to activate automatic undithering
       *
       * \remarks Automatic undithering will be applied only if smoothing is also activated
       */
      void SetUndithering ( const IDRS_BOOL bUndithering );
      /**
       * \brief Gets a flag indicating if the automatic undithering correction will be applied before OCR.
       *
       * \remarks Default value is IDRS_FALSE.
       *
       * \returns IDRS_TRUE if automatic undithering is activated
       * \remark IDRS_FALSE is set by default
       */
      IDRS_BOOL GetUndithering () const;
      /**
       * \brief Sets the callback object used to indicate which color to drop out.
       *
       * \param pBinarizeCallback Callback pointer to set
       */
      void SetBinarizeCallback(IBinarizeCallback* pBinarizeCallback);
      /**
       * \brief Gets the callback object used to indicate which color to drop out.
       *
       * \return The callback pointer
       */
      IBinarizeCallback* GetBinarizeCallback() const;
    private:
      // For internal use only
      CBinarizeData & TypedObject () const
      {
        return ( CBinarizeData & )Object ();
      };
  };
  /*
   *
   */
  inline CBinarize::CBinarize ()
  {
  }
  /*
   *
   */
  inline CBinarize::CBinarize ( const CBinarize & argBinarize )
    : CImageOperation (( CImageOperation & )argBinarize )
  {
  }
  /*
   *
   */
  inline CBinarize::CBinarize ( CBinarizeData * pBinarizeData )
    : CImageOperation (( CImageOperationData * )pBinarizeData )
  {
  }
  /*
   *
   */
  inline CBinarize::~CBinarize ()
  {
  }
} // namespace
#endif /* _CBinarize_h_ */
