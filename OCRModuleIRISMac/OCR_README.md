## Apryse SDK OCR Module

This module allows optical character recognition operations within Apryse SDK. Specifically, the functionality within the `PDF.OCRModuleIRIS` class relies on this package.

### Installation

This archive should be expanded on top of an existing Apryse SDK package (version 7.0 or later). This will place the module itself in the correct location, as well as additional resource files required to run the OCR conversion (located at `resources/` in the original download package).

### Usage 

Within your own application logic, call `PDFNet.AddResourceSearchPath()` with the path to the location of `Lib/OCRModuleIRIS` from this package, if this has been done correctly, then `PDF.OCRModule.IsIRISModuleAvailable()` will return true, and the module will be operational.
