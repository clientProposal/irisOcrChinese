/**
 * \file IBaseImagePlugin.h
 * \brief Interface for the IDRS::IBaseImagePlugin class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _IBaseImagePlugin_h_
#define _IBaseImagePlugin_h_
#include <CObjPtr.h>
#include <CImage.h>
#include <IByteStream.h>
#include <CImagePluginCapabilities.h>
namespace IDRS
{
  /**
   * \brief IBaseImagePlugin defines the interface required to provide custom image loading/saving capabilities.
   * \ingroup module_core
   *
   * An image plugin is a class that is able to load and/or save a specific type of image.
   * Each plugin needs to announce it's internal capabilities through CImagePluginCapabilities.
   * Each plugin needs to support all options from the used CImageSaveOptionsXXX class.
   * iDRS SDK will invoke function CanLoadFile whenever a file needs to be loaded.
   * The plugin's responsibility is to detect whether the supplied file can be loaded using it's own code.
   */
  class IDRSKRN_API IBaseImagePlugin
  {
    public:
      //! Destructor
      inline virtual ~IBaseImagePlugin() = default;
      /**
       * \brief SaveImage saves a CImage object to a IByteStream object, using the file format parameters provided
       *
       * \param argImage CImage object to save
       * \param argStream Stream where to store the image data
       * \param argSaveOptions Image file format options
       *
       * \see CImage
       * \see ImageFormat
       * \see CImageSaveOptions
       *
       * \return IDRS_TRUE if the image was successfully saved, IDRS_FALSE otherwise
       */
      virtual IDRS_BOOL SaveImage ( const CImage & argImage, IByteStream & argStream, const CImageSaveOptions & argSaveOptions ) = 0;
      /**
       * \brief CanLoadFile is the function that allows the plugin to signal whether it recognizes a certain file and that it can load it.
       *
       * The plugin can choose any algorithm for detecting the file type:
       * - based on file extension
       * - based on magic bytes inside the image header
       *
       * \param argInputStream The input stream to decode
       *
       * \return IDRS_TRUE if the plugin recognizes the file type and it can load it. IDRS_FALSE otherwise
       */
      virtual IDRS_BOOL CanLoadFile(IByteStream& argInputStream) const = 0;
      /*
       * \ brief GetPageCount Retrieves the number of pages of the given input image
       *
       * The plugin can provide an implementation for retrieving the number of pages of the
       * image used as an input
       *
       * \param argInputStream The input stream
       * \param argLoadOptions Reference to a CImageLoadOptions class containing options for loading
       *
       * \return The input page count
       */
      virtual IDRS_UINT GetPageCount(IByteStream& argInputStream, const CImageLoadOptions& argLoadOptions) const = 0;
      /**
       * \brief Loads a file or memory stream into the specified CImage object
       *
       * \param argImage Reference to the CImage object that will contain the data read from the disk
       * \param argInputStream the input stream
       * \param uiImageIndex The 0 based index of the image to load from the provided file
       * \param argLoadOptions Reference to a CImageLoadOptions class containing options for loading
       *
       * \return IDRS_TRUE if the load operation is successful, IDRS_FALSE otherwise
       *
       * \see CImage
       */
      virtual IDRS_BOOL LoadImage(CImage& argImage, IByteStream& argInputStream, const IDRS_UINT32 uiImageIndex, const CImageLoadOptions& argLoadOptions) = 0;
      /**
       * \brief GetCapabilities returns the capabilities of the plugin
       *
       * The plugin can have multiple capabilities: loading and/or saving one or more type of files
       *
       * \return An object containing all the capabilities supported by the plugin
       */
      virtual CImagePluginCapabilities GetCapabilities () const = 0;
  };
} // namespace
#endif /* _IBaseImagePlugin_h_ */
