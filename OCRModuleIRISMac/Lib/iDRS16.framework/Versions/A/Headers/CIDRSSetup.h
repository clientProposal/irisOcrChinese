/**
 * \file CIDRSSetup.h
 * \brief Interface for the IDRS::CIDRSSetup class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _CIDRSSetup_h_
#define _CIDRSSetup_h_
#include <CObjPtr.h>
#include <CIDRSLicense.h>
#include "ILogger.h"
#include <idrsversion.h>
#include <idrs_string.h>
namespace IDRS
{
  /**
   * \brief The CIDRSSetup class manages the iDRS SDK licensing information
   * \ingroup module_core
   *
   * The class is responsible with the following tasks:
   * - <b>license management </b> - handles licenses verification and in-memory storage
   * - <b>setup/unload modules </b> - loads and unloads the modules based on the supplied licenses
   *
   * The class exposes static functions for license management and it stores all the licenses in internal structures. For each module type there is only one license available.
   * During module setup, the following steps are performed in order:
   * - license verification
   * - module loading
   * - extension loading
   *
   * If any of the above steps fails, an CIDRSException will be thrown and the process will stop.<br>
   * Each license object can be updated after it is setup. With every update, all the steps described above will be executed.
   *
   * The following code snippet shows how to create a license, enable an extension for it and setup it in iDRS SDK:
   * \code
   *    IDRS::CIDRSLicense aLicense(Module::Prepro, IDRS_LICENSE_SOFTWARE, "unlock key");
   *    aLicense.EnableExtension(IDRS_PREPRO_EXTENSION_ADVANCED_PREPRO, "adv prepro unlock key");
   *    IDRS::CIDRSSetup::SetupModule(aLicense);
   * \endcode
   *
   * \see CIDRSLicense
   * \see Module
   */
  class IDRSKRN_API CIDRSSetup
  {
    public:
      /**
       * \brief Destructor
       */
      virtual ~CIDRSSetup ();
      /**
       * \brief Setup the supplied CIDRSLicense
       *
       * The function checks that the supplied license is valid and loads the necessary resources for the module.
       *
       * \param argIdrsLicense The license object contains all the licensing information for a iDRS module.
       *
       * \throws CIDRSException if any error occurs during license verification or module and extension loading.
       */
      static void SetupModule ( const CIDRSLicense & argIdrsLicense );
      /**
       * \brief Unload iDRS SDK.
       *
       * \retval IDRS_TRUE if iDRS was unloaded successful.
       * \retval IDRS_FALSE if iDRS is used and can't be unloaded.
       *
       * \note The objects that keep the modules and extensions binaries in memory are reference counted, so the binaries will be unloaded from memory when all the objects that use them are destroyed
       *
       * \remarks If an ILogger has been registered via CIDRSSetup::SetLoggerCallback(), ensure that the logger instance is still valid during the call to CIDRSSetup::Unload()!
       */
      static IDRS_BOOL Unload ();
      /**
       * \brief Tests if the given module is ready.
       *
       * \param mModuleId The identifier for the module.
       *
       * \retval IDRS_TRUE if the module is ready.
       * \retval IDRS_FALSE if the module is not ready.
       *
       * \see Module for available modules in iDRS SDK
       */
      static IDRS_BOOL IsModuleReady ( const Module mModuleId );
      /**
       * \brief Tests if the given extension is ready.
       *
       * \param eExtensionId The identifier for the extension.
       *
       * \retval IDRS_TRUE if the module is ready.
       * \retval IDRS_FALSE if the module is not ready.
       *
       * \see Extension for available extensions in iDRS SDK
       */
      static IDRS_BOOL IsExtensionReady ( const Extension eExtensionId );
      /**
       * \brief Sets the temporary folder that will be used by iDRS SDK for storing temporary files and folders.
       *
       * \remarks By default, the iDRS uses the system temporary folder.
       *
       * \remarks If the platform doesn't have a notion of system-wide temporary folder, with default configuration an exception
       * will be thrown whenever a temporary file needs to be created.
       *
       * \remarks Passing NULL value as temporary folder will reset the temporary folder location to system temporary folder, or throw an exception
       * if the platform has no notion of system-wide temporary folder.
       *
       * \param strTemporaryFolder Path to temporary folder location
       */
      static void SetTemporaryFolder ( const idrs_string &strTemporaryFolder );
      /**
       * \brief Gets the temporary folder location.
       *
       * \remarks By default, the iDRS uses the system temporary folder.
       *
       * \remarks On platforms with no notion of system-wide temporary folder, an exception will be thrown unless SetTemporaryFolder()
       * has been previously called.
       *
       * \return The temporary folder path
       */
      static const idrs_string& GetTemporaryFolder ( );
      /**
       * \brief Sets the callback object used to log events.
       * The object used as a callback object will be called every time iDRS receives a message during an
       * operation, of severity level equal or higher than the level provided by user.
       * 
       * This logger callback is expected to be called for log messages that are not part of sessions
       *
       * \remarks The supplied callback object should be able to handle messages arriving from different threads, possibly at the same time
       *
       * \remarks The logger callback class should inherit from ILogger interface
       *
       * \param pCallback The  callback object pointer
       * \param evLevel The severity level threshold for which calls to logger callback class should be performed.
       */
      static void SetLoggerCallback(ILogger * pCallback, const SeverityLevel evLevel);
      /**
       * \brief Gets a short description of the iDRS.
       *
       * \return A short description of the iDRS.
       */
      static inline const idrs_string GetIdrsDescription ();
      /**
       * \brief Gets the revision of the iDRS.
       *
       * \return The revision of the iDRS.
       */
      static inline const idrs_string GetIdrsRevision ();
      /**
       * \brief Sets the path where the internal libraries are expected to be found.
       *
       * iDRS will use this path to load the internal libraries.
       *
       * \important This feature is not available on OSX and iOS platforms
       *
       * \param strInternalLibraryPath NULL terminated string containing the path to the internal libraries
       */
      static void SetInternalLibraryPath(const idrs_string & strInternalLibraryPath);
      /**
       * \brief Gets the path to the internal libraries.
       *
       * \important This feature is not available on OSX and iOS platforms
       *
       * \return String that will contain the path to internal libraries
       */
      static const idrs_string& GetInternalLibraryPath();
      /**
       * \brief Sets the resources path where all needed ressources by iDRS SDK are located.
       *
       * \param strResourcesPath Path to resources needed by the iDRS SDK
       *
       * \remarks If the resources path is an empty string, the iDRS will search resources in the current directory of execution (Windows, Linux, Android) or in bundle resources (macOS, iOS).
       */
      static void SetResourcesPath (const idrs_string & strResourcesPath);
      /**
       * \brief Gets the resources path.
       *
       * \remarks The default value of that property is "" (empty string).
       *
       * \return String containing the resources path
       */
      static const idrs_string& GetResourcesPath ();
      /**
       * \brief Sets the maximum of worker threads to be used for document temporary storage manipulation.
       *
       * \param uiWorkerThreads The number of threads to be used. The default value is 1.
       *
       * \note
       *  - The minimum allowed value is 1.
       *  - If the value is reduced while processing is in progress, the number of active threads may
       *    remain higher while the tasks are not completed.
       */
      static void SetDocumentStorageWorkerThreads(const IDRS_UINT uiWorkerThreads);
      /**
       * \brief Gets the number of worker threads.
       *
       * \return The threading limit currently configured.
       */
      static IDRS_UINT GetDocumentStorageWorkerThreads();
      /**
       * \brief Allows setting up extra features in iDRS SDK
       *
       * \param strExtraSettings String value containing the extra settings to be setup
       */
      static void SetupExtraSettings(const idrs_string& strExtraSettings);
    private:
      /**
       * \brief Default constructor.
       */
      inline CIDRSSetup ();
      /**
       * \brief Copy constructor.
       *
       * \param argIdrsSetup The idrs setup object to copy.
       */
      inline CIDRSSetup ( const CIDRSSetup & argIdrsSetup );
  };
  /*
   *
   */
  const idrs_string CIDRSSetup::GetIdrsDescription ()
  {
    return IDRS_DESCRIPTION;
  }
  /*
   *
   */
  const idrs_string CIDRSSetup::GetIdrsRevision ()
  {
    return IDRS_REVISION;
  }
} // namespace
#endif /* _CIDRSSetup_h_ */
