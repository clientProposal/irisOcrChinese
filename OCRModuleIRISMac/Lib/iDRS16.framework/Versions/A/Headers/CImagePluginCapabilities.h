/**
 * \file CImagePluginCapabilities.h
 * \brief Interface for the IDRS::CImagePluginCapabilities class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _CImagePluginCapabilities_h_
#define _CImagePluginCapabilities_h_
#include <CObjPtr.h>
#include <CImagePluginCapability.h>
namespace IDRS
{
  class CImagePluginCapabilitiesData;
  /**
   * \brief The CImagePluginCapabilities class contains the capabilities implemented in a image plugin.
   * \ingroup module_core
   *
   * The class acts as a storage for CImagePluginCapability objects and also provides useful methods for detecting if a certain image can be saved or loaded using various parameteres.
   *
   */
  class IDRSKRN_API CImagePluginCapabilities : public CObjPtr
  {
    public:
      /**
       * \brief Default constructor.
       */
      inline CImagePluginCapabilities ();
      /**
       * \brief Copy constructor.
       *
       * \param argImagePluginCapabilities The smart pointer to copy.
       */
      inline CImagePluginCapabilities ( const CImagePluginCapabilities & argImagePluginCapabilities );
      /**
       * \brief Constructor.
       *
       * \param pImagePluginCapabilitiesData The object to point to.
       */
      inline CImagePluginCapabilities ( CImagePluginCapabilitiesData * pImagePluginCapabilitiesData );
      /**
       * \brief Destructor
       */
      inline virtual ~CImagePluginCapabilities ();
      /**
       * \brief Adds a new CImagePluginCapability to capabilities list
       *
       * \param argCapability object containing the supported capability.
       */
      void Add ( const CImagePluginCapability & argCapability );
      /**
       * \brief Adds a vector of image capabilities to the capabilities list
       *
       * \param xCapabilities Vector containing the capabilities to add
       * \param uiCapabilitiesCount Number of capability objects to add       
       */
      void Add ( const CImagePluginCapability xCapabilities [], const IDRS_UINT32 uiCapabilitiesCount );
      /**
       * \brief GetAt returns the CImagePluginCapability at a certain index
       *
       * \param uiIndex Index where to read the CImagePluginCapability
       *
       * \return The CImagePluginCapability at the supplied index
       */
      CImagePluginCapability GetAt ( const IDRS_UINT32 uiIndex ) const;
      /**
       * \brief GetCount returns the number of capabilities set
       *
       * \return The number of capabilities
       */
      IDRS_UINT32 GetCount () const;
      /**
       * \brief RemoveAt removes a CImagePluginCapability from the list
       *
       * \param uiIndex The index where to remove the object
       */
      void RemoveAt ( const IDRS_UINT32 uiIndex );
      /**
       * \brief RemoveAll removes all capabilities.
       *
       */
      void RemoveAll ();
      /**
       * \brief This method verifies whether the image plugin is able to load an image format with respect to the provided options.
       *
       * \param argImageLoadOptions The image loading options
       *
       * \return IDRS_TRUE if the plugin can load the supplied format and options; otherwise IDRS_FALSE
       */
      IDRS_BOOL CanLoad ( const CImageLoadOptions & argImageLoadOptions ) const;
      /**
       * \brief This method verifies whether the image plugin is able to save an image format with respect to the provided options.
       *
       * \param argImageSaveOptions The image saving options
       *
       * \return IDRS_TRUE if the plugin can save the supplied format and options; otherwise IDRS_FALSE
       */
      IDRS_BOOL CanSave ( const CImageSaveOptions & argImageSaveOptions ) const;
      /**
       * \brief Creates a new CImagePluginCapabilities object
       *
       * \return The newly created CImagePluginCapabilities
       */
      static CImagePluginCapabilities Create ();
    private:
      // For internal use only
      CImagePluginCapabilitiesData & TypedObject () const
      {
        return ( CImagePluginCapabilitiesData & )Object ();
      };
  };
  /*
   *
   */
  inline CImagePluginCapabilities::CImagePluginCapabilities ()
  {
  }
  /*
   *
   */
  inline CImagePluginCapabilities::CImagePluginCapabilities ( const CImagePluginCapabilities & argImagePluginCapabilities )
    : CObjPtr (( CObjPtr & )argImagePluginCapabilities )
  {
  }
  /*
   *
   */
  inline CImagePluginCapabilities::CImagePluginCapabilities ( CImagePluginCapabilitiesData * pImagePluginCapabilitiesData )
    : CObjPtr (( CObj * )pImagePluginCapabilitiesData )
  {
  }
  /*
   *
   */
  inline CImagePluginCapabilities::~CImagePluginCapabilities ()
  {
  }
} // namespace
#endif /* _CImagePluginCapabilities_h_ */
