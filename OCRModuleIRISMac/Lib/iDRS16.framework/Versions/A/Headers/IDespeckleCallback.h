/**
 * \file IDespeckleCallback.h
 * \brief Interface for the IDRS::IDespeckleCallback class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _IDespeckleCallback_h_
#define _IDespeckleCallback_h_
#include <CObjPtr.h>
namespace IDRS
{
  /**
   * \brief IBinarizeCallback defines the interface required to provide a custom algorithm for speckle removing.
   * \ingroup module_prepro
   *
   * \req IDRS::Module::Prepro
   *
   * \see Module::Prepro for information about the preprocessing library
   *
   * \see CDespeckle for the despeckle algorithm.
   */
  class IDRSKRN_API IDespeckleCallback
  {
    public:
      //! Destructor
      inline virtual ~IDespeckleCallback () = default;
      /**
       * \brief RemoveBlobTest is a callback method called by CDespeckle before removing a group of connected pixels.
       *
       * \param uiBlobHeight The height of the group of connected pixels.
       * \param uiBlobWidth The width of the group of connected pixels.
       * \param uiBlobPixelsCount The number of black pixels in the group.
       *
       * \retval IDRS_TRUE If the group of connected pixels must be removed.
       * \retval IDRS_FALSE otherwise.
       *
       */
      virtual IDRS_BOOL RemoveBlobTest ( const IDRS_UINT uiBlobHeight, const IDRS_UINT uiBlobWidth, const IDRS_UINT uiBlobPixelsCount ) = 0;
  };
} //namespace
#endif /* _IDespeckleCallback_h_ */
