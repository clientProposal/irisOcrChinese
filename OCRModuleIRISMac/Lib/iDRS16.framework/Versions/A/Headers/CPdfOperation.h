/**
 * \file CPdfOperation.h
 * \brief Interface for CPdfOperation class
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _CPdfOperation_h_
#define _CPdfOperation_h_

#include "idrs.h"
#include "CDigitalSignature.h"

namespace IDRS
{
  class CPdfUpdateParams;
  class idrs_string;
  /**
   * \brief CPdfOperation exposes features which can be used on PDF documents.
   */
  class IDRSKRN_API CPdfOperation
  {
  public:
    /**
     * \brief Adds a digital signature to an existing PDF document and save the result to another document
     *
     * \param strInputFilePath Path to the PDF document
     * \param strOutputFilePath Path to the new PDF document to create
     * \param strPassword Owner password if specified otherwise User password used to open the PDF document. (empty if it is not password-protected)
     * \param argDigitalSignature digital signature to apply
     * \param argPdfUpdateParams The PDF update parameters
     *
     * \return IDRS_SUCCESS if the digital signature was properly added, a specific error code otherwise
     *
     * \req IDRS::Module::DocumentOutput
     * \req IDRS::Module::ImageFormats with Extension::ImageFormatsPdfInput
     *
     * \remarks If the input PDF is a PDF/A, the method will throw an exception with code IDRS_ERROR_INVALID_ARGS unless font embedding is set in the PDF Update params.
     */
    static IDRS_ERROR ApplySignature ( const idrs_string & strInputFilePath, const idrs_string & strOutputFilePath,
      const idrs_string & strPassword, const CDigitalSignature& argDigitalSignature, const CPdfUpdateParams& argPdfUpdateParams);
    /**
     * \brief Adds a digital signature to an existing PDF document and save the result in the same document (appending)
     *
     * \param strDocumentFilePath Path to the PDF document to update
     * \param strPassword Owner password if specified otherwise User password used to open the PDF document. (empty if it is not password-protected)
     * \param argDigitalSignature digital signature to apply
     * \param argPdfUpdateParams The PDF update parameters
     *
     * \return IDRS_SUCCESS if the digital signature was properly added, a specific error code otherwise
     *
     * \remarks Updating the input file "in-place" will be faster and consume less memory, however if the method fails, the document may be corrupted.
     *
     * \req IDRS::Module::DocumentOutput
     * \req IDRS::Module::ImageFormats with Extension::ImageFormatsPdfInput
     *
     * \remarks If the input PDF is a PDF/A, the method will throw an exception with code IDRS_ERROR_INVALID_ARGS unless font embedding is set in the PDF Update params.
     */
    static IDRS_ERROR ApplySignature ( const idrs_string & strDocumentFilePath,
      const idrs_string& strPassword, const CDigitalSignature& argDigitalSignature, const CPdfUpdateParams& argPdfUpdateParams);
    /**
     * \brief Adds a digital signature to an existing PDF document and save the result to another document
     *
     * \param argInputStream Stream opened on the PDF document
     * \param argOutputStream Stream to the new PDF document to create
     * \param strPassword Owner password if specified otherwise User password used to open the PDF document. (empty if it is not password-protected)
     * \param argDigitalSignature digital signature to apply
     * \param argPdfUpdateParams The PDF update parameters
     *
     * \return IDRS_SUCCESS if the digital signature was properly added, a specific error code otherwise
     *
     * \req IDRS::Module::DocumentOutput
     * \req IDRS::Module::ImageFormats with Extension::ImageFormatsPdfInput
     *
     * \remarks If the input PDF is a PDF/A, the method will throw an exception with code IDRS_ERROR_INVALID_ARGS unless font embedding is set in the PDF Update params.
     */
    static IDRS_ERROR ApplySignature ( IByteStream & argInputStream, IByteStream & argOutputStream,
      const idrs_string& strPassword, const CDigitalSignature& argDigitalSignature, const CPdfUpdateParams& argPdfUpdateParams);
    /**
     * \brief Adds a digital signature to an existing PDF document and save the result in the same document (appending)
     *
     * \param argDocumentStream Stream opened on the PDF document to update
     * \param strPassword Owner password if specified otherwise User password used to open the PDF document. (empty if it is not password-protected)
     * \param argDigitalSignature digital signature to apply
     * \param argPdfUpdateParams The PDF update parameters
     *
     * \return IDRS_SUCCESS if the digital signature was properly added, a specific error code otherwise
     *
     * \remarks Updating the input file "in-place" will be faster and consume less memory, however if the method fails, the document may be corrupted.
     *
     * \req IDRS::Module::DocumentOutput
     * \req IDRS::Module::ImageFormats with Extension::ImageFormatsPdfInput
     *
     * \remarks If the input PDF is a PDF/A, the method will throw an exception with code IDRS_ERROR_INVALID_ARGS unless font embedding is set in the PDF Update params.
     */
    static IDRS_ERROR ApplySignature ( IByteStream & argDocumentStream,
      const idrs_string& strPassword, const CDigitalSignature& argDigitalSignature, const CPdfUpdateParams& argPdfUpdateParams);
  };
}
#endif // _CPdfOperation_h_
