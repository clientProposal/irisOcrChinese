/**
 * \file IBinarizeCallback.h
 * \brief Interface for the IDRS::IBinarizeCallback class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _IBinarizeCallback_h_
#define _IBinarizeCallback_h_
#include <CObjPtr.h>
namespace IDRS
{
  /**
   * \brief IBinarizeCallback defines the interface required to provide a custom algorithm for image binarization.
   *
   * \ingroup module_prepro
   * \req IDRS::Module::Prepro
   *
   * \see Module::Prepro for information about the preprocessing library
   *
   * \see CBinarize for the binarization algorithms.
   */
  class IDRSKRN_API IBinarizeCallback
  {
    public:
      //! Destructor
      inline virtual ~IBinarizeCallback () = default;
      /**
       * Dropout callback method called at the end of the binarization for each black pixel.
       *
       * The black pixel is transformed to white if the function returns IDRS_TRUE.
       *
       * \param ucRed The red component of the pixel's color.
       * \param ucGreen The green component of the pixel's color.
       * \param ucBlue The blue component of the pixel's color.
       *
       * \retval IDRS_TRUE If the black pixel must be transformed to white.
       * \retval IDRS_FALSE otherwise.
       *
       */
      virtual IDRS_BOOL RemovePixel ( const IDRS_UCHAR ucRed, const IDRS_UCHAR ucGreen, const IDRS_UCHAR ucBlue ) = 0;
  };
} // namespace
#endif /* _IBinarizeCallback_h_ */
