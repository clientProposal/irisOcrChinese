/**
 * \file idrskrn.h
 * \brief Main header file for the idrskrn dynamic link library.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _idrskrn_h_
#define _idrskrn_h_
/**
 * \mainpage iDRS user's manual
 *
 * Welcome to iDRS 16 SDK documentation, an essential source of information for developers using iDRS 16 SDK.
 * The documentation includes reference class and method documentation grouped by usage scenario, deployment information as well as a FAQ section.
 *
 * The documentation delivered with this SDK may contain extra information describing functionalities not purchased or covered by the signed contract.
 * The exact specifications of the received kit must be based upon the contract and not the documentation.
 * The documentation may also contain inaccuracies for which I.R.I.S will not be liable for.
 *
 * iDRS documentation is grouped in the following units:
 * - \ref module_core
 * - \ref module_image_formats
 * - \ref module_ocr
 * - \ref module_barcode
 * - \ref module_prepro
 * - \ref module_document_output
 *
 * Please note that the above grouping units are called "modules" throughout the documentation. 
 * These are documentation modules and can be different from IDRS.Module data type in iDRS 16 SDK.
 *
 * For a complete list of classes, please use the following <a href="annotated.html">link</a>.
 *
 * For tips&tricks and FAQ, you can consult the <a href="pages.html">Related pages</a> section.
 */

/** @defgroup module_core iDRS core
  * @{
  * \brief Core functionality in iDRS, used by several modules
  * @}
  */

/** @defgroup module_image_formats Imaging
  * @{
  * \brief Imaging module contains the features that allows an integrator to load/save bitmaps using various image formats.
  * @}
  */

/** @defgroup module_ocr Optical character recognition
  * @{
  * \brief Optical character recognition exposes OCR features that allows an integrator to perform text recognition.
  * @}
  */

/** @defgroup module_barcode Barcode recognition
  * @{
  * \brief Barcode module exposes the features that allows an integrator to perform barcode recognition.
  * @}
  */

/** @defgroup module_prepro Preprocessing
  * @{
  * \brief Preprocessing module exposes the features that allows an integrator to enhance the image data before performing various processing on it.
  * @}
  */

/** @defgroup module_prepro_camera_image Camera Image Preprocessing
 * \ingroup module_prepro
 * @{
 * \brief Camera Image Preprocessing module exposes the features that allows an integrator to enhance camera images before performing various processing on it.
 * @}
 */

/** @defgroup module_document_output Document output
  * @{
  * \brief Document output allows an integrator to create output documents based on the input images and recognized data
  * @}
  */

#if defined ( _WIN64 ) || defined ( WIN64 )
  #define IDRS_OS_WIN64
#elif defined( WIN32 )
  #define IDRS_OS_WIN32
#elif defined( macintosh ) || ( defined( __APPLE__ ) && defined( __MACH__ ))
  #include "TargetConditionals.h"
  #if (TARGET_OS_IPHONE == 1)
    #define IDRS_OS_IOS
  #else
    #define IDRS_OS_MACINTOSH
  #endif
#elif defined( __ANDROID__ )
  #define IDRS_OS_ANDROID
#else
  #define IDRS_OS_LINUX
#endif

#if defined( IDRS_OS_WIN32 ) || defined( IDRS_OS_WIN64 )
  #define IDRS_OS_WIN
#endif
/**
 * Class exportation/importation macro.
 */
#ifdef IDRS_OS_WIN
  #include <windows.h>
  #include <io.h>
  #include <stdint.h>
  #ifdef IDRSKRN_EXPORTS
    #define IDRSKRN_API __declspec ( dllexport )
  #else
    #define IDRSKRN_API __declspec ( dllimport )
  #endif
#endif /* IDRS_OS_WIN */
#ifdef IDRS_OS_MACINTOSH
  #include <limits.h>
  #include <stdlib.h>
  #include <unistd.h>
  #include <Carbon/Carbon.h>
  #define IDRS_BUNDLE_ID "com.irislink.iDRS16"
  #ifdef IDRSKRN_EXPORTS
    #define IDRSKRN_API __attribute__(( visibility ( "default" )))
  #else
    #define IDRSKRN_API
  #endif
#endif /* IDRS_OS_MACINTOSH */
#ifdef IDRS_OS_IOS
  #include <limits.h>
  #include <stdlib.h>
  #include <CoreFoundation/CoreFoundation.h>
  #define IDRS_BUNDLE_ID "com.irislink.iDRS16"
  #ifdef IDRSKRN_EXPORTS
    #define IDRSKRN_API __attribute__(( visibility ( "default" )))
  #else
    #define IDRSKRN_API
  #endif
#endif /* IDRS_OS_IOS */
#if defined(IDRS_OS_LINUX)
  #include <limits.h>
  #include <malloc.h>
  #include <unistd.h>
  #ifdef IDRSKRN_EXPORTS
    #define IDRSKRN_API
  #else
    #define IDRSKRN_API
  #endif
#endif /* IDRS_OS_LINUX */
#ifdef IDRS_OS_ANDROID
  #include <limits.h>
  #include <malloc.h>
  #include <unistd.h>
  #ifdef IDRSKRN_EXPORTS
    #define IDRSKRN_API
  #else
    #define IDRSKRN_API
  #endif
#endif /* IDRS_OS_ANDROID */

#ifndef __FILE_NAME__
  constexpr const char* idrs_filename(const char* strInput)
  {
    const char* strResult = strInput;
    do
    {
      if( (*strInput == '\\') || (*strInput == '/'))
      {
        strResult = ++strInput;
      }
    } while (*strInput++ != '\0');
    return strResult;
  }
  #define IDRS_FILE_NAME idrs_filename(__FILE__)
#else
  #define IDRS_FILE_NAME __FILE_NAME__
#endif 

#include "idrsstd.h"
#include "idrserr.h"
#include "Language.h"
#include <StructDefinitions.h>
#include <EnumDefinitions.h>
#endif /* _idrskrn_h_ */
