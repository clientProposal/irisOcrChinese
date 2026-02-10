

require('dotenv').config();

const { PDFTRON_KEY: PDFTronLicense, PWD } = process.env;


const { PDFNet } = require('@pdftron/pdfnet-node');


((exports) => {
  'use strict';

  exports.runOCRTest = () => {
    const main = async () => {
      try {

        PDFNet.addResourceSearchPath('./OCRModuleIRISMac/Lib/');

        const useIRIS = await PDFNet.OCRModule.isIRISModuleAvailable();
        if (!(await PDFNet.OCRModule.isModuleAvailable())) {
          console.log('\nUnable to run OCRTest: Apryse SDK OCR module not available.');
          console.log('---------------------------------------------------------------');
          console.log('The OCR module is an optional add-on, available for download');
          console.log('at https://docs.apryse.com/core/guides/info/modules#ocr-module . If you have already downloaded this');
          console.log('module, ensure that the SDK is able to find the required files');
          console.log('using the PDFNet.addResourceSearchPath() function.\n');

          return;
        }

        const input_path = './pdfToOcr/';
        const output_path = './result/';

        try {
          const doc = await PDFNet.PDFDoc.createFromFilePath(input_path + 'certificate-of-registration-1.pdf');
          doc.initSecurityHandler(PDFTronLicense);

          const opts = new PDFNet.OCRModule.OCROptions();
          if (useIRIS) opts.setOCREngine('iris');
          opts.addLang('eng');

          const page = await doc.getPage(1);
          const mediaBox = await page.getMediaBox();

          const pageHeight = mediaBox.y2 - mediaBox.y1;
          const pageWidth = mediaBox.x2 - mediaBox.x1;
          const zoneHeight = pageHeight * (1 / 3); 

          /**
           * 
           * To produce: certificate-of-registration-full-area.pdf
           const bottomTwoThirdsZone = new PDFNet.Rect(
            mediaBox.x1,               
            mediaBox.y1,                   
            mediaBox.x2 ,                   
            mediaBox.y2  
          );
           */

          const bottomTwoThirdsZone = new PDFNet.Rect(
            mediaBox.x1 + (pageWidth * 0.12),               
            mediaBox.y1 + zoneHeight,                   
            mediaBox.x2 - (pageWidth * 0.12),                   
            mediaBox.y2  
          );
          console.log(
            `
            x1 mediaBox.x1 ${mediaBox.x1 + (pageWidth * 0.12)},               
            y1 mediaBox.y1 + zoneHeight ${mediaBox.y1 + zoneHeight},                  
            x2 mediaBox.x2 ${mediaBox.x2 - (pageWidth * 0.12)},                 
            y2 mediaBox.y2 ${mediaBox.y2},
            `
          )

          opts.addTextZonesForPage([bottomTwoThirdsZone], 1);

          opts.addDPI(400);

          await PDFNet.OCRModule.processPDF(doc, opts);

          await doc.save(output_path + 'certificate-of-registration-smaller-area-only.pdf', 0);

        } catch (err) {
          console.log(err);
        }


        console.log('Done.');
      } catch (err) {
        console.log(err);
      }
    };
    PDFNet.runWithCleanup(main, PDFTronLicense).catch(function (error) {
      console.log('Error: ' + JSON.stringify(error));
    }).then(function () { return PDFNet.shutdown(); });
  };
  exports.runOCRTest();
})(exports);