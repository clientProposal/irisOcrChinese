/**
 * \file CImagePluginManager.h
 * \brief Interface for the IDRS::CImagePluginManager class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _CImagePluginManager_h_
#define _CImagePluginManager_h_
#include <CObjPtr.h>
#include <IBaseImagePlugin.h>
namespace IDRS
{
  class CImagePluginManagerData;
  /**
   * \brief The CImagePluginManager class contains the registry for the user defined plugins
   * \ingroup module_core
   *
   * The class provides static methods for dealing with the plugin registration. It is not supposed to be instantiated.
   *
   * The class will maintain a list with references to the image plugin objects supplied.
   * Besides this list, CImagePluginManager contains a reference to an image plugin implemented in iDRS SDK that expose all the imaging functionality in iDRS SDK.
   */
  class IDRSKRN_API CImagePluginManager
  {
    public:
      /**
       * Destructor
       */
      inline virtual ~CImagePluginManager ();
      /**
       * \brief RegisterPlugin adds a plugin to the plugin list
       *
       * Please note that the plugin is added by reference. iDRS SDK will store the reference internally.
       * It is integrator's job to make sure that the reference is still valid during the program execution or until the plugin is removed from CImagePluginManager
       *
       * \param argImagePlugin Reference to the plugin to be added
       */
      static void RegisterPlugin ( const IBaseImagePlugin & argImagePlugin );
      /**
       * \brief Returns the number of plugins already added to image plugin registry
       *
       * \return The number of plugins already added
       */
      static IDRS_UINT32 GetPluginCount ();
      /**
       * \brief GetAt returns a reference to a plugin already added
       *
       * \param uiIndex Index of the plugin to be returned
       *
       * \return Reference to the plugin stored at specified index
       */
      static IBaseImagePlugin & GetAt ( const IDRS_UINT32 uiIndex );
      /**
       * \brief RemoveAt removes a plugin at a specified index.
       *
       * Please note that iDRS SDK will not try to perform delete or cleanup of the removed object. It is integrator's job to cleanup any memory used by the plugin.
       *
       * \param uiIndex Index where to remove
       */
      static void RemoveAt ( const IDRS_UINT32 uiIndex );
      /**
       * \brief RemoveAll clears the internal container of any previous added plugin.
       *
       * Please note that iDRS SDK will not try to perform delete or cleanup of the removed objects. It is integrator's job to cleanup any memory used by the plugins.
       */
      static void RemoveAll ();
      /**
       * \brief GetDefaultPlugin returns the default imaging plugin.
       *
       * \return The default imaging plugin
       */
      static IBaseImagePlugin & GetDefaultPlugin ();
      /**
       * \brief Unloads all plugin objects that are loaded
       */
      static void Unload();
    private:
      /**
       * \brief Default constructor.
       */
      inline CImagePluginManager ();
      /**
       * \brief Copy constructor
       */
      inline CImagePluginManager ( const CImagePluginManager & argOtherPluginManager );
  };
  /*
   *
   */
  inline CImagePluginManager::CImagePluginManager ()
  {
  }
  /*
   *
   */
  inline CImagePluginManager::~CImagePluginManager ()
  {
  }
} // namespace
#endif /* _CImagePluginManager_h_ */
