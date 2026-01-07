/**
 * \file CPageCollectionStorageOptions.h
 * \brief Interface of the IDRS::CPageCollectionStorageOptions class.
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _CPageCollectionStorageOptions_h_
#define _CPageCollectionStorageOptions_h_

#include <CObjPtr.h>

namespace IDRS
{
  class CPageCollectionStorageOptionsData;
  class CImageSaveOptions;
  class idrs_string;
  /**
   * \brief CPageCollectionStorageOptions class represents the set of options for an IPageCollection.
   */
  class IDRSKRN_API CPageCollectionStorageOptions : public CObjPtr
  {
  public:
    /**
     * \brief Default constructor.
     */
    inline CPageCollectionStorageOptions();
    /**
     * \brief Constructor from a object
     *
     * \param argPageCollectionStorageOptionsData The data object
     */
    inline CPageCollectionStorageOptions( CPageCollectionStorageOptionsData * argPageCollectionStorageOptionsData );
    /**
     * \brief Copy constructor
     *
     * \param argCollectionStorageOptions The smart pointer to the object to copy (shallow copy).
     */
    inline CPageCollectionStorageOptions( const CPageCollectionStorageOptions & argCollectionStorageOptions );
    /**
     * \brief Creates a new CPageCollectionStorageOptions
     *
     * \return A new instance of CPageCollectionStorageOptions.
     */
    static CPageCollectionStorageOptions Create();
    /**
     * \brief Sets the path to folder where temporary data is created
     * 
     * \param strFolderPath String containing the path where to store the temporary data.
     * 
     * \note By default the temporary data is created in the folder referenced by the CIDRSSetup.TemporaryFolder property.
     */
    void SetStorageFolder( const idrs_string &strFolderPath );
    /**
     * \brief Gets the path to folder where temporary data is created
     *
     * \return String containing the path where to store the temporary data.
     */
    const idrs_string& GetStorageFolder() const;
    /**
     * \brief Sets the memory threshold to reach before storing the data in temporary files on disk.
     * 
     * When the pages collection reaches the memory usage defined by the threshold, the data will start being transferred into temporary files.
     * The pages with lowest pirority are transferred first to the filesystem, that is:
     * - Pages already processed by CDocumentWriter 
     * - Then pages with highest index.
     * 
     * \note The threshold value represents a hint for the memory management but not contract in terms of memory usage. In other words, the pages 
     *       will be moved to temporary files after the collection size exceeds the limit.
     * 
     * \param argMemoryThreshold The threshold value in bytes. Default value is 100 * 1024 * 1024 (100 Mb)
     */
    void SetMemoryThreshold( const IDRS_UINT64 argMemoryThreshold );
    /**
     * \brief Gets the memory threshold property.
     *
     * \return The threshold value in bytes.
     */
    IDRS_UINT64 GetMemoryThreshold() const;
    /**
     * \brief Specifies the type of compression to be applied when storing the images on disk
     * 
     * This Image options may affect the performance and the document quality depending on the settings.
     * - Lossless formats (such as png) offer a better document quality, but use more space on the disk;
     * - lossy formats on the other hand are generally faster to compute and use less space, but may degrade the output quality due to compression.
     * 
     * \note This option only applies to the color and greyscale images. The black and white images are always saved using the lossless tiff G4 format.
     * 
     * \param argImageSaveOptions The CImageSaveOptions object
     */
    void SetImageCompression( const CImageSaveOptions& argImageSaveOptions );
    /**
     * \brief Returns the ImageCompression property value.
     *
     * \return The CImageSaveOptions object.
     */
    CImageSaveOptions GetImageCompression() const;
    /**
     * \brief Sets the flag that indicates whether the page should remain in the collection after the processing.
     *
     * \param bValue When set to 'true', the page elements are kept in the collection after the CDocumentWriter::save() is complete
     *               If set to 'false', the elements are discarded as soon as they are processed.
     *
     * \note When the flag is set to 'false', the CDocument cannot be used in multiple CDocumentWriter::save() operations.
     */
    void SetKeepProcessedPages( const IDRS_BOOL bValue );
    /**
     * \brief Gets the KeepProcessedPages flag value.
     *
     * \return The flag value
     */
    IDRS_BOOL GetKeepProcessedPages( ) const;

  private:
    //! Internal use only
    CPageCollectionStorageOptionsData& TypedObject( ) const
    {
      return (CPageCollectionStorageOptionsData&)Object( );
    }
  };
  /*
   *
   */
  inline CPageCollectionStorageOptions::CPageCollectionStorageOptions( )
  {
  }
  /*
   *
   */
  inline CPageCollectionStorageOptions::CPageCollectionStorageOptions( CPageCollectionStorageOptionsData* argPageCollectionStorageOptionsData ) :
    CObjPtr( (CObj *)argPageCollectionStorageOptionsData )
  {
  }
  /*
   *
   */
  inline CPageCollectionStorageOptions::CPageCollectionStorageOptions( const CPageCollectionStorageOptions& argPageCollectionStorageOptions ) :
    CObjPtr( (CObjPtr &)argPageCollectionStorageOptions )
  {
  }
}
#endif // _CPageCollectionStorageOptions_h_
