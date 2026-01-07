/**
 * \file idrs.h
 * \brief iDRS SDK main header file
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 * 2024-01-09 - Simon Poudou
 * - Added BarcodeType.h
 * \endinternal
 */
#ifndef _idrs_h_
#define _idrs_h_
#include <idrsversion.h>
#include <idrskrn.h>
#include <StructDefinitions.h>
#include <EnumDefinitions.h>
#include <Language.h>
#include <BarcodeType.h>
#include <CIDRSException.h>
#include <CIDRS.h>
#include <CPage.h>
#include <CTextRecognition.h>
#include <CLngUtils.h>
#include <IByteStream.h>
#include <CDeskew.h>
#include <CRotate.h>
#include <CDespeckle.h>
#include <CLineRemoval.h>
#include <CDarkBordersRemoval.h>
#include <CBlankImageDetection.h>
#include <CDespeckle.h>
#include <IDespeckleCallback.h>
#include <CIDRSLicense.h>
#include <CImageOperationUtils.h>
#include <COutputParams.h>
#include <CDocumentWriter.h>
#include <CDocument.h>
#include <IPageCollection.h>
#include <CDefaultPageCollection.h>
#include <CHtmlOutputParams.h>
#include <COdtOutputParams.h>
#include <CPdfOutputParams.h>
#include <CRtfOutputParams.h>
#include <CXlsxOutputParams.h>
#include <CPptxOutputParams.h>
#include <CTextOutputParams.h>
#include <CEpubOutputParams.h>
#include <CDocxOutputParams.h>
#include <CBookmarksOptions.h>
#include <CPdfCompressionOptions.h>
#include <CImageSaveOptionsJpeg2000.h>
#include <CImageSaveOptionsPdf.h>
#include <CImageSaveOptionsJpeg.h>
#include <CImageSaveOptionsPng.h>
#include <CImageSaveOptionsTiff.h>
#include <CIDRSSetup.h>
#include <CImageLimits.h>
#include <CDitherRemoval.h>
#include <CPerspective.h>
#include <CImageSource.h>
#include <CFileStream.h>
#include <CMemoryStream.h>
#include <IFontDataProviderCallback.h>
#include <CBinarize.h>
#include <IBinarizeCallback.h>
#include <CGreyscale.h>
#include <CImageLoadOptionsPdf.h>
#include <CQualityAssessment.h>
#include <IBarcodeEngine.h>
#include <CBarcodeEngineManager.h>
#include <IBarcodeEnginePreprocess.h>
#include <CBarcodeEnginePreprocessDitherRemoval.h>
#include <CBarcodeEnginePreprocessWhitePixelsRemoval.h>
#include <IBarcodeEnginePostprocess.h>
#include <ILogger.h>
#include <CFileLogger.h>
#include <CConsoleLogger.h>
#include <CDocumentSeparationOptions.h>
#include <IStreamFactory.h>
#include <CPdfCustomMetadata.h>
#include <CPdfCustomMetadataPropertyList.h>
#include <CPdfCustomMetadataProperty.h>
#include <CAttachment.h>
#include <CPageContent.h>
#include <CPageZone.h>
#include <CPageZoneTable.h>
#include <CPageZoneText.h>
#include <CPageZoneGraphicExternalImage.h>
#include <CPageGraphicShapeLine.h>
#include <CResize.h>
#include <COcrPageParams.h>
#include <COcrZonalParams.h>
#include <CBarcodeValidationCriteria.h>
#include <CBarcodeSpecificOptions.h>
#include <CBarcodeEngineConfig.h>
#include <CBarcodeParams.h>
#include <CBarcodePageParams.h>
#include <CBarcodeZonalParams.h>
#include <CBarcodeDetection.h>
#include <CPageAnalysis.h>
#include <CPageAnalysisParams.h>
#include <CPageProcessing.h>
#include <idrs_string.h>
#include <CXmlOutputParams.h>
#endif /* _idrs_h_ */
