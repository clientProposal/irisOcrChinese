/**
 * \file CImageIO.h
 * \brief Interface for the IDRS::CImageIO class.
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */

#ifndef _CImageIO_h_
#define _CImageIO_h_
#include <CObjPtr.h>
#include <CIDRS.h>
#include <CImageSaveOptionsTiff.h>
#include <CImageSaveOptionsJpeg.h>
#include <CImageSaveOptionsJpeg2000.h>
#include <CImageSaveOptionsPdf.h>
#include <CImageSaveOptionsPng.h>
#include <IByteStream.h>
#include <CImageLoadOptions.h>
#include <CImageLoadOptionsPdf.h>

namespace IDRS
{
  class CPage;
  class CImage;
  class CImageIOData;
  class IBaseImagePlugin;
  class idrs_string;

  /**
   * \brief The CImageIO class manages loading and saving of images for the iDRS.
   *
   * An image is a buffer of pixels and some characteristics such as width, height, resolution.
   *
   * The class CImageIO offers a set of convenient methods for loading and saving images.
   *
   */
  class IDRSKRN_API CImageIO : public CObjPtr
  {
  public:
    /**
     * \brief Default constructor.
     */
    CImageIO() = default;
    /**
     * \brief Copy constructor.
     *
     * \param argImageIO The smart pointer to copy.
     */
    inline CImageIO(const CImageIO& argImageIO);
    /**
     * \brief Constructor.
     *
     * \param pImageData The object to point to.
     */
    inline CImageIO(CImageIOData* pImageData);
    /**
     * \brief Destructor
     */
    virtual ~CImageIO() = default;
    /**
     * \brief Create object.
     *
     * \param argIdrs - CIDRS handle object
     *
     * \throw CIDRSException if an error occur.
     *
     */
    static CImageIO Create(const CIDRS& argIdrs);
    /**
     * \brief LoadImage loads an image from a file.
     *
     * \pre ! IsNull ()
     *
     * \param strFileName The name of the input file.
     * \param uiImageIndex The 0 based index of the image to load from the provided file
     *
     * \return The newly created image.
     *
     * \attention This function requires the imaging module to be enabled in order to load a file.
     *
     * \remarks The method will interrogate the registered plugins (see CImagePluginManager) until finding
     * one having the necessary loading capabilities.
     *
     * \attention iDRS default image plugin will throw an exception if uiImageIndex is different than 0 for
     * non-multipage formats (any other than TIFF and PDF).
     */
    CImage LoadImage(const idrs_string& strFileName, const IDRS_UINT uiImageIndex = 0) const;
    /**
     * \brief LoadImage loads an image from a stream.
     *
     * \pre ! IsNull ()
     *
     * \param argInputStream The stream containing the image to be loaded
     * \param uiImageIndex The 0 based index of the image to load from the provided file
     *
     * \return The newly created image.
     *
     * \attention This function requires the imaging module to be enabled in order to load a file.
     *
     * \attention iDRS default image plugin will throw an exception if uiImageIndex is different than 0 for
     * non-multipage formats (any other than TIFF and PDF).
     *
     * \attention The provided stream must contain one file.
     *
     * \see IDRS::CFileStream
     * \see IDRS::CMemoryStream
     */
    CImage LoadImage(IByteStream& argInputStream, const IDRS_UINT uiImageIndex = 0) const;
    /**
     * \brief SaveImage saves an image to a file using the supplied image plugin
     *
     * In case the supplied image plugin does not know how to save the indicated file format,
     * the function with throw IDRS_ERROR_FILE_FORMAT
     *
     * \pre ! IsNull ()
     * \pre ! argImageSaveOptions.IsNull ()
     * 
     * \param argImage The CImage object containing the image data.
     * \param strFileName The name of the output file.
     * \param ffFileFormat The file format
     *
     */
    void SaveImage(const CImage& argImage, const idrs_string &strFileName, const ImageFormat ffFileFormat) const;
    /**
     * \brief SaveImage saves an image to a stream using the supplied image plugin
     *
     * In case the supplied image plugin does not know how to save the indicated file format,
     * the function with throw IDRS_ERROR_FILE_FORMAT
     *
     * \pre ! IsNull ()
     * \pre ! argImageSaveOptions.IsNull ()
     *
     * \param argImage The CImage object containing the image data.
     * \param objStream The IByteStream object where to write the compressed image
     * \param ffFileFormat The file format
     *
     */
    void SaveImage(const CImage& argImage, IByteStream& objStream, const ImageFormat ffFileFormat) const;
    /**
     * \brief LoadPage loads the source image from a file.
     *
     * \pre ! IsNull ()
     *
     * \param strFileName The name of the file that contains the source image.
     * \param uiImageIndex The 0 based index of the image to load from the provided file
     *
     * \return The newly created page.
     *
     * \note Removing zones also removes the page layout.
     *
     * \attention iDRS default image plugin will throw an exception if uiImageIndex is uiPageIndex than 0 for
     * non-multipage formats (any other than TIFF and PDF).
     *
     * \throw CIDRSException if an error occur.
     */
    CPage LoadPage(const idrs_string& strFileName, const IDRS_UINT uiImageIndex = 0) const;
    /**
     * \brief LoadPage loads the source image from the supplied stream.
     *
     * \pre ! IsNull ()
     *
     * \param argInputStream The input stream
     * \param uiImageIndex The 0 based index of the image to load from the provided file
     *
     * \return The newly created page.
     *
     * \note Removing zones also removes the page layout.
     *
     * \attention iDRS default image plugin will throw an exception if uiImageIndex is uiPageIndex than 0 for
     * non-multipage formats (any other than TIFF and PDF).
     *
     * \attention The provided stream must contain one file.
     *
     * \throw CIDRSException if an error occur.
     */
    CPage LoadPage(IByteStream& argInputStream, const IDRS_UINT uiImageIndex = 0) const;
    /**
     * \brief SavePage saves the source image to a file.
     *
     * \see CImage::Save
     *
     * \pre ! IsNull ()
     * \pre ! argImageSaveOptions.IsNull ()
     *
     * \param argPage The CPage object containing the page data.
     * \param strFileName The name of the file.
     * \param ffFileFormat The file format.
     *
     * \attention It requires an imaging module to be enabled in order to save the files.
     *
     * \throw CIDRSException if an error occur.
     */
    void SavePage(const CPage& argPage, const idrs_string &strFileName, const ImageFormat ffFileFormat) const;
    /**
     * \brief SavePage saves the source image to a file using the specified image compressor.
     *
     * \see CImage::Save
     *
     * \pre ! IsNull ()
     * \pre ! argImageSaveOptions.IsNull ()
     *
     * \param argPage The CPage object containing the page data.
     * \param argStream The stream where to store the image data
     * \param evFileFormat The file format.
     *
     * \throw CIDRSException if an error occur.
     */
    void SavePage(const CPage& argPage, IByteStream& argStream, const ImageFormat evFileFormat) const;
    /**
     * \brief Load loads an image or a page from a file.
     *
     * \pre ! IsNull ()
     *
     * \param strFileName The name of the input file.
     * \param uiImageIndex The 0 based index of the image to load from the provided file
     *
     * \return The newly created image or page.
     *
     * \attention This function requires the imaging module to be enabled in order to load a file as image.
     *
     * \note Removing zones also removes the page layout.
     *
     * \remarks The method will interrogate the registered plugins (see CImagePluginManager) until finding
     * one having the necessary loading capabilities.
     *
     * \attention iDRS default image plugin will throw an exception if uiImageIndex is different than 0 for
     * non-multipage formats (any other than TIFF and PDF).
     *
     * \throw CIDRSException if an error occur.
     *
     * \tparam T CImage or CPage
     */
    template <typename T>
    T Load(const idrs_string& strFileName, const IDRS_UINT uiImageIndex = 0) const;
    /**
     * \brief Load loads an image or a file from a stream.
     *
     * \pre ! IsNull ()
     *
     * \param argInputStream The input stream
     * \param uiImageIndex The 0 based index of the image to load from the provided file
     *
     * \return The newly created image or file.
     *
     * \attention This function requires the imaging module to be enabled in order to load a file.
     *
     * \note Removing zones also removes the page layout.
     *
     * \attention iDRS default image plugin will throw an exception if uiImageIndex is different than 0 for
     * non-multipage formats (any other than TIFF and PDF).
     *
     * \attention The provided stream must contain one file.
     *
     * \see IDRS::CFileStream
     * \see IDRS::CMemoryStream
     *
     * \throw CIDRSException if an error occur.
     *
     * \tparam T CImage or CPage
     */
    template <typename T>
    T Load(IByteStream& argInputStream, const IDRS_UINT uiImageIndex = 0) const;
    /**
     * \brief Retrieves the page count for multiple page documents
     * This function can be used in all page formats. Multiple page formats ( TIFF, PDF )
     * and single page formats. For single page formats the page count will be 1.
     *
     * IMAGE_FILE module is required to use an image as an input, and IDRS_FILE_EXTENSION_PDF
     * is required for pdf file input. Function will first check if all required modules are enabled
     * and throw an exception in any different case
     *
     * \param strFileName The name of the input file.
     *
     * \return The number of pages of the document.
     *
     */
    IDRS_UINT GetPageCount( const idrs_string &strFileName) const;
    /**
     * \brief Retrieves the page count for multiple page documents
     * This function can be used in all page formats. Multiple page formats ( TIFF, PDF )
     * and single page formats. For single page formats the page count will be 1.
     *
     * IMAGE_FILE module is required to use an image as an input, and IDRS_FILE_EXTENSION_PDF
     * is required for pdf file input. Function will first check if all required modules are enabled
     * and throw an exception in any different case
     *
     * \param argInputStream The input stream object
     *
     * \return The number of pages of the document.
     *
     */
    IDRS_UINT GetPageCount(IByteStream& argInputStream) const;
    /**
     * \brief Get the PDF loading options object
     * \returns The CImageLoadOptionsPdf object
     */
    CImageLoadOptionsPdf GetPdfLoadOptions() const;
    /**
     * \brief Set the PDF loading options with the provided object
     * \param argPdfLoadOptions The CImageLoadOptionsPdf object
     */
    void SetPdfLoadOptions(const CImageLoadOptionsPdf& argPdfLoadOptions);
    /**
     * \brief Get the JPEG saving options object
     * \return The CImageSaveOptionsJpeg object
     */
    CImageSaveOptionsJpeg GetJpegSaveOptions() const;
    /**
     * \brief Set the JPEG options for saving
     * \param argJpegSaveOptions The CImageSaveOptionsJpeg to be provided
     */
    void SetJpegSaveOptions(const CImageSaveOptionsJpeg& argJpegSaveOptions);
    /**
     * \brief Get the JPEG 2000 saving options object
     * \return The CImageSaveOptionsJpeg object
     */
    CImageSaveOptionsJpeg2000 GetJpeg2000SaveOptions() const;
    /**
     * \brief Set the JPEG 2000 options for saving
     * \param argJpeg2000SaveOptions The CImageSaveOptionsJpeg2000 to be provided
     */
    void SetJpeg2000SaveOptions(const CImageSaveOptionsJpeg2000& argJpeg2000SaveOptions);
    /**
     * \brief Get the PNG saving options object
     * \return The CImageSaveOptionsPng object
     */
    CImageSaveOptionsPng GetPngSaveOptions() const;
    /**
     * \brief Set the PNG options for saving
     * \param argPngSaveOptions The CImageSaveOptionsPng to be provided
     */
    void SetPngSaveOptions(const CImageSaveOptionsPng& argPngSaveOptions);
    /**
     * \brief Get the PDF saving options object
     * \return The CImageSaveOptionsPdf object
     */
    CImageSaveOptionsPdf GetPdfSaveOptions() const;
    /**
     * \brief Set the PDF options for saving
     * \param argPdfSaveOptions The CImageSaveOptionsPdf to be provided
     */
    void SetPdfSaveOptions(const CImageSaveOptionsPdf& argPdfSaveOptions);
    /**
     * \brief Get the Tiff saving options object
     * \return The CImageSaveOptionsPdf object
     */
    CImageSaveOptionsTiff GetTiffSaveOptions() const;
    /**
     * \brief Set the Tiff options for saving
     * \param argTiffSaveOptions The CImageSaveOptionsTiff to be provided
     */
    void SetTiffSaveOptions(const CImageSaveOptionsTiff& argTiffSaveOptions);
  private:
    // For internal use only
    CImageIOData& TypedObject() const
    {
      return (CImageIOData&)Object();
    };
  };
  /*
   *
   */
  CImageIO::CImageIO(const CImageIO& argImageIO)
    : CObjPtr((CObjPtr&)argImageIO)
  {
  }
  /*
   *
   */
  CImageIO::CImageIO(CImageIOData* pObj)
    : CObjPtr((CObj*)pObj)
  {
  }
}
#endif /* _CImageIO_h_ */   
