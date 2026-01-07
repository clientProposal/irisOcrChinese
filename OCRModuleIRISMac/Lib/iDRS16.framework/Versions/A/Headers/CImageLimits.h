/**
 * \file CImageLimits.h
 * \brief Interface for IDRS::CImageLimits class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _CImageLimits_h_
#define _CImageLimits_h_
#include <CPage.h>
namespace IDRS
{
  /**
   * \brief The maximum width for an image to be used for recognition
   *
   * Maximum value for the width an image can have in iDRS SDK
   */
  #define IDRS_MAX_IMAGE_WIDTH  32768
  /**
   * \brief The maximum height for an image to be used for recognition
   *
   * Maximum value for the height an image can have in iDRS SDK
   */
  #define IDRS_MAX_IMAGE_HEIGHT  32768
  /**
   * \brief The maximum size (in pixels) for an image to be used for recognition
   *
   * This value corresponds to an A2 (16.54 x 23.39 in or 420 x 594 mm) at 300 dpi
   */
  #define IDRS_IMAGE_MAX_DIMENSION_RECOGNITION 75000000
  /**
   * \brief The minimum resolution for an image to be used recognition
   */
  #define IDRS_IMAGE_MIN_RESOLUTION_RECOGNITION 72
  /**
   * \brief The maximum resolution for an image to be used recognition
   */
  #define IDRS_IMAGE_MAX_RESOLUTION_RECOGNITION 1200
  /**
   * \brief The maximum height for a character recognized at any resolution
   */
  #define IDRS_CHARACTER_MAX_HEIGHT 400
  /**
   * \brief The maximum height for a line of characters recognized at any resolution
   */
  #define IDRS_LINE_MAX_HEIGHT  512

  /**
   * \brief CImageLimits class contains helper methods useful when working with images
   * \ingroup module_core module_image_formats
   *
   *
   */
  class IDRSKRN_API CImageLimits
  {
    public:
      /**
       * \brief GetImageMaxWidth returns the maximum width in pixels for an image to be used with iDRS SDK
       */
      static inline IDRS_UINT32 GetImageMaxWidth ();
      /**
       * \brief GetImageMaxHeight returns the maximum height in pixels for an image to be used with iDRS SDK
       */
      static inline IDRS_UINT32 GetImageMaxHeight ();
      /**
       * \brief GetImageMaxSize returns the maximum number of pixels for an image to be used with iDRS SDK
       */
      static inline IDRS_UINT32 GetImageMaxSize ();
      /**
       * \brief GetImageMinResolution returns the minimum resolution in dpi that can be used by the recognition engine
       */
      static inline IDRS_UINT32 GetImageMinResolution ();
      /**
       * \brief GetImageMaxResolution returns the maximum resolution in dpi that can be used by the recognition engine
       */
      static inline IDRS_UINT32 GetImageMaxResolution ();
      /**
       * \brief GetCharacterMaxHeight returns the maximum character height, at the supplied resolution
       *
       * \param uiResolution Image resolution
       *
       * \return The maximum character height in pixels for the supplied resolution
       */
      static inline IDRS_UINT32 GetCharacterMaxHeight ( const IDRS_UINT32 uiResolution );
      /**
       * \brief GetLineMaxHeight returns the maximum line height, at the supplied resolution
       *
       * \param uiResolution Image resolution
       *
       * \return The maximum line height in pixels for the supplied resolution
       */
      static inline IDRS_UINT32 GetLineMaxHeight ( const IDRS_UINT32 uiResolution );
      /**
       * \brief CheckPageLimits verifies the limits of the supplied CPage object
       *
       * \param argPage CPage object that will be verified
       *
       * \retval IDRS_TRUE if argPage contains an image that can be used for recognition
       * \retval IDRS_FALSE if argPage internal image is not suitable for recognition
       */
      static inline IDRS_BOOL CheckPageLimits ( const CPage & argPage );
      /**
       * \brief CheckPageLimits verifies if the supplied width and height are within the minimum and maximum image limits
       *
       * \param uiWidth Image width
       * \param uiHeight Image height
       *
       * \retval IDRS_TRUE if the width and height are ok
       * \retval IDRS_FALSE if the width or height of the image exceeds the max limits
       */
      static inline IDRS_BOOL CheckPageLimits ( const IDRS_UINT32 uiWidth, const IDRS_UINT32 uiHeight );
      /**
       * \brief CheckPageLimits verifies the resolution of the supplied CPage object is in the min and max resolution interval
       *
       * \param argPage CPage object that will be verified
       *
       * \retval IDRS_TRUE if the argPage contains an image with a resolution that can be used for recognition
       * \retval IDRS_FALSE if the argPage internal image has a resolution not suitable for recognition
       */
      static inline IDRS_BOOL CheckPageResolution ( const CPage & argPage );
      /**
       * \brief CheckPageResolution verifies that the supplied resolution is within recognition accepted limits
       *
       * \param uiResolution resolution to verify
       *
       * \retval IDRS_TRUE if the supplied resolution can be used for recognition
       * \retval IDRS_FALSE if the supplied resolution is not suitable for recognition
       */
      static inline IDRS_BOOL CheckPageResolution ( const IDRS_UINT32 uiResolution );
  };
  /*
   *
   */
  inline IDRS_UINT32 CImageLimits::GetImageMaxWidth ()
  {
    return IDRS_MAX_IMAGE_WIDTH;
  }
  /*
   *
   */
  inline IDRS_UINT32 CImageLimits::GetImageMaxHeight ()
  {
    return IDRS_MAX_IMAGE_HEIGHT;
  }
  /*
   *
   */
  inline IDRS_UINT32 CImageLimits::GetImageMaxSize ()
  {
    return IDRS_IMAGE_MAX_DIMENSION_RECOGNITION;
  }
  /*
   *
   */
  inline IDRS_UINT32 CImageLimits::GetImageMinResolution ()
  {
    return IDRS_IMAGE_MIN_RESOLUTION_RECOGNITION;
  }
  /*
   *
   */
  inline IDRS_UINT32 CImageLimits::GetImageMaxResolution ()
  {
    return IDRS_IMAGE_MAX_RESOLUTION_RECOGNITION;
  }
  /*
   *
   */
  inline IDRS_BOOL CImageLimits::CheckPageLimits ( const CPage & argPage )
  {
    return CheckPageLimits ( argPage.GetWidth (), argPage.GetHeight ());
  }
  /*
   *
   */
  inline IDRS_BOOL CImageLimits::CheckPageLimits ( const IDRS_UINT32 uiWidth, const IDRS_UINT32 uiHeight )
  {
    if (( uiWidth > GetImageMaxWidth ()) || ( uiHeight > GetImageMaxHeight ()) || ( uiWidth * uiHeight > GetImageMaxSize ()) || (uiWidth * uiHeight == 0))
    {
      return IDRS_FALSE;
    }

    return IDRS_TRUE;
  }
  /*
   *
   */
  inline IDRS_BOOL CImageLimits::CheckPageResolution ( const CPage & argPage )
  {
    return CheckPageResolution ( argPage.GetResolution ());
  }
  /*
   *
   */
  inline IDRS_BOOL CImageLimits::CheckPageResolution ( const IDRS_UINT32 uiResolution )
  {
    if ( uiResolution < IDRS_IMAGE_MIN_RESOLUTION_RECOGNITION || uiResolution > IDRS_IMAGE_MAX_RESOLUTION_RECOGNITION )
    {
      return IDRS_FALSE;
    }
    return IDRS_TRUE;
  }
  /*
   *
   */
  inline IDRS_UINT32 CImageLimits::GetCharacterMaxHeight ( const IDRS_UINT32 uiResolution )
  {
    IDRS_VERIFY_ARGS (( uiResolution >= GetImageMinResolution ()) && ( uiResolution <= GetImageMaxResolution ()));
    IDRS_UINT32 uiValue = (IDRS_UINT32)(( uiResolution * 256.0f ) / 300.0f );
    if ( uiValue > IDRS_CHARACTER_MAX_HEIGHT )
    {
      uiValue = IDRS_CHARACTER_MAX_HEIGHT;
    }
    return uiValue;
  }
  /*
   *
   */
  inline IDRS_UINT32 CImageLimits::GetLineMaxHeight ( const IDRS_UINT32 uiResolution )
  {
    IDRS_VERIFY_ARGS (( uiResolution >= GetImageMinResolution ()) && ( uiResolution <= GetImageMaxResolution ()));
    IDRS_UINT32 uiValue = (IDRS_UINT32)(( uiResolution * 324.0f ) / 300.0f );
    if ( uiValue > IDRS_LINE_MAX_HEIGHT )
    {
      uiValue = IDRS_LINE_MAX_HEIGHT;
    }
    return uiValue;
  }
}
#endif  // _CImageLimits_h_
