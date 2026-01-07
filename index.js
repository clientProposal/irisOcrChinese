require('dotenv').config();

const { PDFTRON_KEY: PDFTronLicense, PWD } = process.env;

const { PDFNet } = require('@pdftron/pdfnet-node');

// This sample was prepared to demonstrate this functionality with Chinese
// Taken from here https://docs.apryse.com/core/samples/ocrtest
// For East Asian languages, use 1 language at a time

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
          const doc = await PDFNet.PDFDoc.createFromFilePath(input_path + 'chinese_not_searchable.pdf');
          doc.initSecurityHandler();

          const opts = new PDFNet.OCRModule.OCROptions();
          if(useIRIS) opts.setOCREngine('iris');
          opts.addLang('chi_tra');

          await PDFNet.OCRModule.processPDF(doc, opts);

          await doc.save(output_path + 'chinese_not_searchable.pdf', 0);

        } catch (err) {
          console.log(err);
        }


        console.log('Done.');
      } catch (err) {
        console.log(err);
      }
    };
    PDFNet.runWithCleanup(main, PDFTronLicense).catch(function(error) {
      console.log('Error: ' + JSON.stringify(error));
    }).then(function(){ return PDFNet.shutdown(); });
  };
  exports.runOCRTest();
})(exports);
// eslint-disable-next-line spaced-comment
//# sourceURL=OCRTest.js