/**
 * \file CImagePluginCapability.h
 * \brief Interface for the IDRS::CImagePluginCapability class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _CImagePluginCapability_h_
#define _CImagePluginCapability_h_
#include <CObjPtr.h>
#include <CImageSaveOptions.h>
#include <CImageLoadOptions.h>
namespace IDRS
{
  class CImagePluginCapabilityData;
  /**
   * \brief The CImagePluginCapability represents a image capability implemented in the image plugin it belongs to.
   * \ingroup module_core
   *
   * The class contains the fine-grained settings that define a image plugin capability:
   * - file format
   * - various options specific to file format: compression algorithm, image mode, etc
   * - ability to load an image
   * - ability to save an image
   *
   */
  class IDRSKRN_API CImagePluginCapability : public CObjPtr
  {
    public:
      /**
       * \brief Default constructor.
       */
      inline CImagePluginCapability ();
      /**
       * \brief Copy constructor.
       *
       * \param argImagePluginCapability The smart pointer to copy.
       */
      inline CImagePluginCapability ( const CImagePluginCapability & argImagePluginCapability );
      /**
       * \brief Constructor.
       *
       * \param pImagePluginCapabilityData The object to point to.
       */
      inline CImagePluginCapability ( CImagePluginCapabilityData * pImagePluginCapabilityData );
      /**
       * \brief Destructor
       */
      inline virtual ~CImagePluginCapability ();
      /**
       * \brief Creates a new CImagePluginCapability object
       *
       * \return The newly created CImagePluginCapability object
       */
      static CImagePluginCapability Create ();
      /**
       * \brief Creates a new CImagePluginCapability object
       *
       * \param ffFileFormat The file format
       * \param bCanSaveFormat Flag specifying whether save operation is supported
       * \param bCanLoadFormat Flag specifying whether load operation is supported
       * \param argImageSaveOptions Image options object usually contains information about the compression or color mode to be used
       *
       * \return The newly created CImagePluginCapability object
       *
       * \see ImageFormat
       * \see CImageSaveOptions
       */
      static CImagePluginCapability Create ( const ImageFormat ffFileFormat, const IDRS_BOOL bCanSaveFormat, const IDRS_BOOL bCanLoadFormat,
                                             const CImageSaveOptions & argImageSaveOptions );
      /**
       * \brief Gets the file format set
       *
       * \return The file format
       *
       * \see ImageFormat
       */
      ImageFormat GetFileFormat () const;
      /**
       * \brief Sets the file format for the capability
       *
       * \param ffFileFormat The file format
       *
       * \see ImageFormat
       */
      void SetFileFormat ( const ImageFormat ffFileFormat );
      /**
       * \brief Returns the flag specifying if the current capability supports saving operation
       *
       * \return IDRS_TRUE if the save operation is implemented, IDRS_FALSE otherwise
       */
      IDRS_BOOL GetCanSave () const;
      /**
       * \brief Sets the flag specifying if the current capability supports saving operation
       *
       * \param bValue Boolean flag
       */
      void SetCanSave ( const IDRS_BOOL bValue );
      /**
       * \brief Returns the flag specifying if the current capability supports loading operation
       *
       * \return IDRS_TRU if the load operation is implemented, IDRS_FALSE otherwise
       */
      IDRS_BOOL GetCanLoad () const;
      /**
       * \brief Sets the flag specifying if the current capability supports loading operation
       *
       * \param bValue Boolean flag
       */
      void SetCanLoad ( const IDRS_BOOL bValue );
      /**
       * \brief Gets the CImageSaveOptions object associated with the current capability
       *
       * The CImageSaveOptions object usually contains information like the color mode or the image compression algorithm to be used.
       *
       * \return The CImageSaveOptions object
       *
       * \see CImageSaveOptions and derived classes
       */
      const CImageSaveOptions & GetImageSaveOptions () const;
      /**
       * \brief Sets the CImageSaveOptions object associated with the current capability
       *
       * \param argImageSaveOptions The CImageSaveOptions object
       *
       * \see CImageSaveOptions and derived classes
       */
      void SetImageSaveOptions ( const CImageSaveOptions & argImageSaveOptions );
    private:
      // For internal use only
      CImagePluginCapabilityData & TypedObject () const
      {
        return ( CImagePluginCapabilityData & )Object ();
      };
  };
  /*
   *
   */
  inline CImagePluginCapability::CImagePluginCapability ()
  {
  }
  /*
   *
   */
  inline CImagePluginCapability::CImagePluginCapability ( const CImagePluginCapability & argImagePluginCapability )
    : CObjPtr (( CObjPtr & )argImagePluginCapability )
  {
  }
  /*
   *
   */
  inline CImagePluginCapability::CImagePluginCapability ( CImagePluginCapabilityData * pImagePluginCapabilityData )
    : CObjPtr (( CObj * )pImagePluginCapabilityData )
  {
  }
  /*
   *
   */
  inline CImagePluginCapability::~CImagePluginCapability ()
  {
  }
} // namespace
#endif /* _CImagePluginCapability_h_ */
