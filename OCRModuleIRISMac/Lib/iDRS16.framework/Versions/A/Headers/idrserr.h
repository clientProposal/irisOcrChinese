/**
 * \file idrserr.h
 * \brief This file contains the declaration of iDRS error codes.
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _idrserr_h_
#define _idrserr_h_
namespace IDRS
{
/**
 * \brief The IDRS_ERROR data type defines an error code.
 */
typedef unsigned long IDRS_ERROR;
/**
 * Success.
 */
#define IDRS_SUCCESS                          0
/*
 * ======================================
 * Generic errors.
 * ======================================
 */
/**
 * The function failed.
 */
#define IDRS_ERROR_FAILURE                    1
/**
 * Unable to allocate a block of memory.
 */
#define IDRS_ERROR_MEMORY_ALLOCATION          2
/**
 * This method isn't available yet.
 */
#define IDRS_ERROR_TODO_METHOD                3
/**
 * A library is missing.
 */
#define IDRS_ERROR_LIBRARY_MISSING            4
/**
 * This method isn't available yet on linux
 */
#define IDRS_ERROR_TODO_METHOD_LINUX          5
/**
 * This method isn't available yet on mactel
 */
#define IDRS_ERROR_TODO_METHOD_MACOS          6
/**
 * This method isn't available yet on Windows
 */
#define IDRS_ERROR_TODO_METHOD_WINDOWS        7
/**
 * The buffer used is too small.
 */
#define IDRS_ERROR_BUFFER_TOO_SMALL           9
/**
 * The user has aborted the current processing.
 */
#define IDRS_ERROR_USER_ABORT                11
/**
 * This method isn't available yet on iOS
 */
#define IDRS_ERROR_TODO_METHOD_IOS           14
/**
 * The buffer is too full to append any string.
 */
#define IDRS_ERROR_BUFFER_IS_FULL 17
/**
 * The module is invalid.
 */
#define IDRS_ERROR_INVALID_MODULE 18
/**
 * The file path doesn't contain a file name.
 */
#define IDRS_ERROR_FILE_NAME_NOT_EXIST 19
/**
 * Fail to create a mutex object.
 */
#define IDRS_ERROR_MUTEX_CREATION_FAILURE 20
/**
 * Key has expired
 */
#define IDRS_ERROR_TEMPORARY_LICENSE_EXPIRED  22
/**
 * This method isn't available yet on Android
 */
#define IDRS_ERROR_TODO_METHOD_ANDROID          23
/**
 * This operation is not supported by the iDRS in its current configuration or on the current platform.
 */
#define IDRS_ERROR_NOT_SUPPORTED 24
/**
 * The iDRS failed to create a thread
 */
#define IDRS_ERROR_THREAD_CREATION_FAILURE 26
/**
 * The iDRS failed to join a thread
 */
#define IDRS_ERROR_THREAD_WAIT_FAILURE 27
/**
 * The iDRS failed to lock a mutex
 */
#define IDRS_ERROR_MUTEX_LOCK_FAILURE  28
/**
 * The iDRS failed to release a mutex
 */
#define IDRS_ERROR_MUTEX_RELEASE_FAILURE  29
/**
 * The memory allocated by iDRS is above the maximum threshold
 */
#define IDRS_ERROR_MEMORY_OVER_MAX_LIMIT          30
/**
 * The memory monitoring was enabled after setting up iDRS modules.
 */
#define IDRS_ERROR_MEMORY_MONITORING_AFTER_SETUP          31
/*
 * ======================================
 * File access errors.
 * ======================================
 */
/**
 * Unable to seek in the file.
 */
#define IDRS_ERROR_FILE_SEEK                  1001
/**
 * Unable to open the file.
 */
#define IDRS_ERROR_FILE_OPEN                  1002
/**
 * Invalid file format.
 */
#define IDRS_ERROR_FILE_FORMAT                1003
/**
 * Read operation failed.
 */
#define IDRS_ERROR_READ_FAILURE               1004
/**
 * Write operation failed.
 */
#define IDRS_ERROR_WRITE_FAILURE              1005
/**
 * The supplied image index is invalid.
 * This error might occur during image loading, when the image index is not correct (possibly larger than the number of images contained in the file)
 */
#define IDRS_ERROR_INVALID_IMAGE_INDEX              1006
/**
 * The iDRS was unable to create a temporary file.
 */
#define IDRS_ERROR_TEMPORARY_FILE_CREATE      1007
/**
 * The iDRS tries to load an image with invalid load options
 */
#define IDRS_ERROR_INVALID_IMAGE_LOAD_OPTIONS    1008
 /**
  * The iDRS tries to load an image with invalid save options
  */
#define IDRS_ERROR_INVALID_IMAGE_SAVE_OPTIONS    1009
/*
 * ======================================
 * Arguments errors.
 * ======================================
 */
/**
 * Invalid arguments for the method.
 */
#define IDRS_ERROR_INVALID_ARGS               1101
/**
 * Invalid call to this method.
 */
#define IDRS_ERROR_INVALID_CALL               1102
/**
 * The index is not valid.
 */
#define IDRS_ERROR_INVALID_INDEX              1103
/**
 * The resolution is not valid.
 */
#define IDRS_ERROR_INVALID_RESOLUTION         1104
/**
 * The number of pixels in the supplied image size exceeds the maximum allowed value
 * Please see IDRS_MAX_IMAGE_DIMENSION_OCR
 */
#define IDRS_ERROR_IMAGE_TOO_LARGE 1105
/**
 * The PDF password supplied is invalid
 */
#define IDRS_ERROR_INVALID_PDF_PASSWORD 1106
/**
 * The Page has no ocr results
 */
#define IDRS_ERROR_PAGE_WITHOUT_OCR_RESULTS 1107

/*
 * ======================================
 * Character recognition module errors.
 * ======================================
 */
/**
 * Character recognition engine already initialized
 */
#define IDRS_ERROR_CHARACTER_RECOGNITION_ENGINE_IS_READY               1201
/**
 * Character recognition engine is not ready
 */
#define IDRS_ERROR_CHARACTER_RECOGNITION_ENGINE_NOT_READY              1202
/**
 * Invalid Character recognition engine software key.
 */
#define IDRS_ERROR_CHARACTER_RECOGNITION_ENGINE_INVALID_KEY            1203
/**
 * Unable to load a recognition environment.
 */
#define IDRS_ERROR_CHARACTER_RECOGNITION_ENGINE_LOAD_RECOGNITION_ENV   1204
/**
 * Unable to load a decision environment.
 */
#define IDRS_ERROR_CHARACTER_RECOGNITION_ENGINE_LOAD_DECISION_ENV      1205
/**
 * Character recognition engine failure
 */
#define IDRS_ERROR_CHARACTER_RECOGNITION_ENGINE_FAILURE                1206
/**
 * The Asian OCR add-on is not ready.
 */
#define IDRS_ERROR_CHARACTER_RECOGNITION_ENGINE_ASIAN_NOT_READY        1207
/**
 * The Hebrew OCR add-on is not ready.
 */
#define IDRS_ERROR_CHARACTER_RECOGNITION_ENGINE_HEBREW_NOT_READY       1208
/**
 * The HAND_WRITE module is not ready.
 */
#define IDRS_ERROR_CHARACTER_RECOGNITION_ENGINE_HAND_WRITE_NOT_READY          1209
/**
 * The arabic fonts recognition add-on is not ready.
 */
#define IDRS_ERROR_CHARACTER_RECOGNITION_ENGINE_ARABIC_NOT_READY       1211
/**
 * An error occured in the Arabic OCR engine.
 */
#define IDRS_ERROR_CHARACTER_RECOGNITION_ENGINE_ARABIC_FAILURE         1213
/**
 * The zone type found at segmentation does not match the zone type returned by recognition.
 */
#define IDRS_ERROR_CHARACTER_RECOGNITION_ENGINE_UNEXPECTED_ZONE_TYPE 1216
/**
 * The language combination is invalid. Please see \see CLngUtils::TestCompatibility for details about mixing recognition languages
 */
#define IDRS_ERROR_CHARACTER_RECOGNITION_ENGINE_INVALID_LANGUAGE_COMBINATION 1217
/*
 * ======================================
 * Barcode recognition module errors.
 * ======================================
 */
/**
 * Barcode already initialized
 */
#define IDRS_ERROR_BARCODE_IS_READY             1301
/**
 * Barcode is not ready
 */
#define IDRS_ERROR_BARCODE_NOT_READY             1302
/**
 * Invalid barcode software key.
 */
#define IDRS_ERROR_BARCODE_INVALID_KEY         1303
/**
 * Barcode 2D extension is not ready
 */
#define IDRS_ERROR_BARCODE_2D_NOT_READY       1304
/**
 * Barcode engine failure.
 */
#define IDRS_ERROR_BARCODE_FAILURE               1306
/**
 * \brief Barcode engine could not be properly setup due to invalid internal response
 */
#define IDRS_ERROR_BARCODE_ENGINE_INVALID_RESPONSE 1308
/**
 * \brief Barcode engine could not be properly setup due to library loading
 */
#define IDRS_ERROR_BARCODE_ENGINE_SETUP_FAILURE 1309
/**
 * \brief The barcode engine is not registered. Please register the barcode engine with the supplied identifier using CBarcodeEngineManager
 */
#define IDRS_ERROR_BARCODE_ENGINE_NOT_REGISTERED  1310
/**
 * \brief The supplied barcode engine identifier is not yet available. Please make sure it is registered using \see IDRS::CBarcodeEngineManager and 
 * enabled using \see IDRS::CBarcodeDetailedParameters
 */
#define IDRS_ERROR_BARCODE_ENGINE_NOT_AVAILABLE  1311
/**
 * \brief A barcode engine with the same unique identifier has been already registered.
 */
#define IDRS_ERROR_BARCODE_ENGINE_ALREADY_REGISTERED  1312
/**
 * \brief There was an error while removing the specified barcode engine.
 * Please note that the default barcode engines shipped with iDRS SDK cannot be unregistered.
 */
#define IDRS_ERROR_BARCODE_ENGINE_CANNOT_UNREGISTER  1313

/*
 * ======================================
 * Preprocessing module errors.
 * ======================================
 */
/**
 * Pre-process already initialized
 */
#define IDRS_ERROR_PREPRO_IS_READY             1401
/**
 * Pre-process is not ready.
 */
#define IDRS_ERROR_PREPRO_NOT_READY            1402
/**
 * Invalid pre-process software key.
 */
#define IDRS_ERROR_PREPRO_INVALID_KEY          1403
/**
 * Prepro failure.
 */
#define IDRS_ERROR_PREPRO_FAILURE              1406
/**
 * Prepro despeckle failure.
 */
#define IDRS_ERROR_PREPRO_DESPECKLE_FAILURE    1407
/**
 * The margins set for dark border removal are invalid for the supplied image
 */
#define IDRS_ERROR_PREPRO_DARKBORDER_REMOVAL_INVALID_MARGINS  1408
/**
 * \brief The prepro camera image library is not currently loaded.
 */
#define IDRS_ERROR_PREPRO_CAMERA_IMAGE_LIBRARY_NOT_READY 1409
/**
 * \brief The prepro camera image library encountered an error while performing perspective correction
 */
#define IDRS_ERROR_PREPRO_CAMERA_IMAGE_FAILURE           1410
 /**
  * \brief The prepro camera image library detected a perspective distortion too large to allow correction while keeping the whole image.
  */
#define IDRS_ERROR_PREPRO_CAMERA_IMAGE_PERSPECTIVE_DISTORTION_TOO_LARGE    1411
  /*
 * ======================================
 * Document output module errors.
 * ======================================
 */
/**
 * Document output module already initialized.
 */
#define IDRS_ERROR_DOCUMENT_OUTPUT_IS_READY                1501
/**
 * Document output module is not ready.
 */
#define IDRS_ERROR_DOCUMENT_OUTPUT_NOT_READY               1502
/**
 * Document output error.
 */
#define IDRS_ERROR_DOCUMENT_OUTPUT_FAILURE                 1503
/**
 * Invalid document output module software key.
 */
#define IDRS_ERROR_DOCUMENT_OUTPUT_INVALID_KEY             1504
/**
 * Specified certificate not found.
 */
#define IDRS_ERROR_DOCUMENT_OUTPUT_CERTIFICATE_NOT_FOUND   1505
/**
 * Document output HyperCompression extension is not ready.
 */
#define IDRS_ERROR_DOCUMENT_OUTPUT_HYPER_COMPRESSION_NOT_READY          1506
/**
 * Invalid advanced document output software key.
 */
#define IDRS_ERROR_DOCUMENT_OUTPUT_HYPER_COMPRESSION_INVALID_KEY        1507
/*
 * ======================================
 * Image formats module errors.
 * ======================================
 */
/**
 * Image formats module already initialized.
 */
#define IDRS_ERROR_IMAGE_FORMATS_IS_READY           1601
/**
 * Image formats is not ready.
 */
#define IDRS_ERROR_IMAGE_FORMATS_NOT_READY          1602
/**
 * Image formats error.
 */
#define IDRS_ERROR_IMAGE_FORMATS_FAILURE            1603
/**
 * Invalid Image formats module software key.
 */
#define IDRS_ERROR_IMAGE_FORMATS_INVALID_KEY        1604
/**
 * Image formats pdf extension not enabled.
 */
#define IDRS_ERROR_IMAGE_FORMATS_PDF_INPUT_NOT_READY     1609
/**
 * Image formats pdf extension license is not correct
 */
#define IDRS_ERROR_IMAGE_FORMATS_PDF_INPUT_LICENSE_ERROR 1610
/**
 * Image formats pdf extension unknown error
 */
#define IDRS_ERROR_IMAGE_FORMATS_PDF_INPUT_UNKNOWN 1611
/**
 * Image formats pdf extension timeout
 */
#define IDRS_ERROR_IMAGE_FORMATS_PDF_INPUT_TIMEOUT 1612
/**
 * Image formats pdf extension process failure
 */
#define IDRS_ERROR_IMAGE_FORMATS_PDF_INPUT_PROCESS_FAILURE 1613
/**
 * The password set to open the PDF is invalid.
 */
#define IDRS_ERROR_IMAGE_FORMATS_PDF_INPUT_INVALID_PASSWORD 1614
/**
 * Image formats pdf corrupted
 */
#define IDRS_ERROR_IMAGE_FORMATS_PDF_INPUT_CORRUPT 1617
/**
 * Image formats pdf page not found or content error
 */
#define IDRS_ERROR_IMAGE_FORMATS_PDF_INPUT_PAGE_ERROR 1618
 /**
  * the pdf font is missing some glyph info 
  */
#define IDRS_ERROR_IMAGE_FORMATS_PDF_INPUT_FONT_MISSING_GLYPH_INFO 1619
 /**
  * the pdf contains some unsupprted characters
  */
#define IDRS_ERROR_IMAGE_FORMATS_PDF_INPUT_UNSUPPORTED_CHARACTER 1620
  //! The input external pdf contains an unexpected object type while reading Fields object from AcroForm dictionary
#define IDRS_ERROR_EXTERNAL_PDF_UNEXPECTED_TYPE_FIELDS_REFERENCE_OBJECT 1621
  //! The input external pdf contains an unexpected object type while reading Fields object from AcroForm dictionary
#define IDRS_ERROR_EXTERNAL_PDF_UNEXPECTED_TYPE_FIELDS_OBJECT 1622
  //! The input external pdf contains an unexpected type for the AcroForm object in Catalog object
#define IDRS_ERROR_EXTERNAL_PDF_UNEXPECTED_TYPE_ACROFORM_OBJECT 1623
  //! The input external pdf contains an unexpected type for Annots object on Page object
#define IDRS_ERROR_EXTERNAL_PDF_UNEXPECTED_TYPE_ANNOTS_OBJECT 1624
  //! The input external pdf uses an unsupported encryption method
#define IDRS_ERROR_EXTERNAL_PDF_UNSUPPORTED_ENCRYPTION 1625
/*
 * ======================================
 * JPEG 2000 compressor errors.
 * ======================================
 */
/**
 * JPEG 2000 compressor errors min value
 */
#define IDRS_ERROR_J2K_MIN_ERROR           1800
/**
 * JPEG 2000 compressor errors max value
 */
#define IDRS_ERROR_J2K_MAX_ERROR           1999
/*
 * ======================================
 * Document output kernel errors.
 * ======================================
 */
/**
 * Document Output kernel errors min value
 */
#define IDRS_ERROR_DOCUMENT_OUTPUT_KRN_MIN_ERROR           2000
/**
 * The document output engine reached an unexpected state.
 */
#define IDRS_ERROR_DOCUMENT_OUTPUT_ENGINE_ASSERTION 2009
/**
 * The memory allocation for the document output module exceeds the maximum size.
 */
#define IDRS_ERROR_DOCUMENT_OUTPUT_ALLOC_CRITICAL_SIZE    2042
/**
 * The input data for the document output module are not well formed.
 */
#define IDRS_ERROR_DOCUMENT_OUTPUT_XML_NOT_WELL_DONE 2043
/**
 * The dimensions of a page from the output document exceeds the limitations of Word output format.
 *
 * The limitations are the following:
 * - The maximum number of columns and rows of a table are 63 and 32767 respectively.
 * - The maximum page size is 22 inches width or height (55.88 cm)
 *
 * Note that reaching the maximum page size often comes from an invalid resolution loaded from the input file.
 */
#define IDRS_ERROR_DOCUMENT_OUTPUT_WORD_LIMITATION        2044
/**
 * Parameters are not correctly set for the document output module.
 */
#define IDRS_ERROR_DOCUMENT_OUTPUT_API_PARAM_INCOHERENT   2110
/**
 * Unable to apply signature to the output document.
 */
#define IDRS_ERROR_DOCUMENT_OUTPUT_SIGNATURE_FAILURE   2145
/**
 * Font not available for embedding to the output document.
 */
#define IDRS_ERROR_DOCUMENT_OUTPUT_FONT_NOT_FOUND  2160
/**
 * The input data for the document output module are not loaded successfully.
 */
#define IDRS_ERROR_DOCUMENT_OUTPUT_XML_LOAD_IMPOSSIBLE    2301
/**
 * There is a problem in the font related input data for the document output module.
 */
#define IDRS_ERROR_DOCUMENT_OUTPUT_TTREADER_UNKNOWN       2400
/**
 * Creating a document with no page
 */
#define IDRS_ERROR_DOCUMENT_OUTPUT_PDF_NO_PAGE          3170
 /**
 * An error occurs when the prepro module extracts and processes the image for the document output module.
 */
#define IDRS_ERROR_DOCUMENT_OUTPUT_PREPRO_XTR             3200
/**
 * An error occurs when the prepro module processes the image on iHQC for the document output module.
 */
#define IDRS_ERROR_DOCUMENT_OUTPUT_PREPRO_MRC             3201
/**
 * Document Output kernel errors max value
 */
#define IDRS_ERROR_DOCUMENT_OUTPUT_KRN_MAX_ERROR          5000
/*
 * ======================================
 * Warning codes.
 * ======================================
 */
/**
 * \brief Output image size is bigger than A1 at 300dpi, interpolation and JBIG2 compression won't be used.
 */
#define IDRS_WARNING_MRC_JBIG2MASK_NOT_ALLOWED 9001
/**
 * \brief Output image size is too small for Jpeg2000 compression, JPEG will be used instead.
 */
#define IDRS_WARNING_JPEG2000_NOT_ALLOWED 9004
/**
 * \brief One or several glyphs could not be found and are missing from the output document.
 */
#define IDRS_WARNING_MISSING_GLYPH_INFO 9005
/**
 * \brief A text element provided to the document output engine contains only characters having a glyph width of 0.
 *
 * \remarks In such case, a default size is used in order to avoid this invalid configuration.
 */
#define IDRS_WARNING_ZERO_SIZE_ELEMENT 9008
/*
 * ======================================
 * C interface errors.
 * ======================================
 */
/**
 * \brief Success.
 */
#define IDRS_C_SUCCESS IDRS_SUCCESS
/**
 * \brief Invalid array object type.
 */
#define IDRS_ERROR_C_INVALID_ARRAY_OBJECT_TYPE 20001
/**
 * \brief Invalid object.
 */
#define IDRS_ERROR_C_INVALID_OBJECT 20002
/**
 * \brief Invalid object type.
 */
#define IDRS_ERROR_C_INVALID_OBJECT_TYPE 20003
/**
 * \brief Invalid parameter type.
 */
#define IDRS_ERROR_C_INVALID_PARAMETER_TYPE 20004
/**
 * \brief Object is null.
 */
#define IDRS_ERROR_C_NULL_OBJECT 20005
/**
 * \brief Internal error.
 */
#define IDRS_ERROR_C_UNKNOWN_ERROR 20006

} // namespace
#endif /* _idrserr_h_ */
