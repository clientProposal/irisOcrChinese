/**
 * \file BarcodeType.h
 * 
 * \internal
 *
 * 2024-01-09 - Simon Poudou
 * - Creation
 *
 * \endinternal
 */  
#ifndef _BarcodeType_h
#define _BarcodeType_h
namespace IDRS
{
  /**
   * \brief Barcode types recognized by iDRS SDK
   */
  enum class BarcodeType
  {
    /**
     * \brief Represents an unknown barcode type
     *
     * \internal
     * c_api_name BarcodeTypeNone
     * \endinternal
     */
    None,
    /**
     * \brief EAN13, EAN encoding 13 digits.
     *
     * EAN-13 is a numeric, fixed-length barcode for 13 characters. The barcodes are composed of two characters for the country
     * digit, followed by ten data characters and a check digit. (The user encodes 12 digits.)
     *
     * EAN-13 - EAN stands for "European Article Number" - is the standard of the publishing industry for the ISBN numbers on
     * books and publications. EAN-13 is actually a European version of UPC-A.
     *
     * \internal
     * c_api_name BarcodeTypeEan13
     * \endinternal
     */
    Ean13 = 1,
    /**
     * \brief EAN8, EAN encoding 8 digits.
     *
     * EAN-8 is a numeric, fixed-length barcode for eight characters. The barcodes are composed of two characters for the
     * country code, followed by five data characters and a check digit. (The user encodes seven digits.)
     *
     * EAN stands for "European Article Number" - is used for products where the origin country must be encoded. It is actually
     * a European version of UPC-A.
     *
     * \internal
     * c_api_name BarcodeTypeEan8
     * \endinternal
     */
    Ean8 = 2,
    /**
     * \brief MSI Plessey barcode type
     *
     * MSI - also called "Plessey" in some literature - is a variable-length, numeric barcode that allows to encode up to 13
     * characters.
     *
     * Historically speaking, MSI was one of the first symbologies ever to be developed. Nowadays, MSI is used mainly in the
     * grocery industry for shelf labels and inventory control. This is no surprise, because it is a "robust" barcode that
     * stands up to well to "tear and wear".
     *
     * Each character of the barcodes consists of 8 elements - 4 bars and 4 spaces. MSI barcodes are not self-checking, the use
     * of a check digit is therefore highly recommended.
     *
     * \internal
     * c_api_name BarcodeTypeMsi
     * \endinternal
     */
    Msi = 5,
    /**
     * \brief MSI Pharma.
     *
     * A variation of MSI with a double check digit that is used by pharmaceutical companies.
     *
     * \internal
     * c_api_name BarcodeTypeMsiPharma
     * \endinternal
     */
    MsiPharma = 6,
    /**
     * \brief UPC-A barcode type
     *
     * UPC is a coding system as well as a symbology; it is designed to uniquely identify a product and its manufacturer.
     *
     * UPC-A is a fixed-length, numeric barcode that allows to encode 12 characters.
     *
     * The barcodes are composed of a number system digit (encoded in odd parity), the manufacturer's code (encoded in odd
     * parity), the product code and a check digit. (The user encodes 11 digits.)
     *
     * The check digit is verified but filtered from the reading result when the option "Verify and Erase Check Digit" is
     * enabled, otherwise, it is read and included in the output. Disable this option to support the variation of UPC which does
     * not contain a check digit.
     *
     * Apart from the check digit, there is a left, center and right guard pattern. The first half of the barcodes uses odd
     * parity digits, the second half uses even parity digits.
     *
     * UPC stands for "Universal Product Code" - has been designed to uniquely identify a product and its manufacturer.
     *
     * \internal
     * c_api_name BarcodeTypeUpcA
     * \endinternal
     *
     */
    UpcA = 7,
    /**
     * \brief UPC-E barcode type
     *
     * UPC-E is a variation of the UPC-A symbol.
     *
     * UPC-E, is restricted to 6 digits and "zero suppressed" - UPC-E compresses the 12 digit UPC codes into six digits by
     * suppressing the number system digit, trailing zeros in the manufacturer's code and leading zeros in the product code.
     *
     *
     * \internal
     * c_api_name BarcodeTypeUpcE
     * \endinternal
     */
    UpcE = 8,
    /**
     * \brief Codabar
     *
     * Codabar is a primarily numeric, self-checking and variable-length barcode for up to 16 data characters. There is a
     * leading and trailing quiet zone and a start and stop character (A B C D).
     *
     * This standard is used primarily for numeric applications; you can encode the digits and six special characters
     * (- . $ / + :).
     *
     * The digits and the $ and - symbol are printed with one wide bar and one space. The start and stop characters (A, B, C
     * and D) are printed with one wide bar and two white spaces.
     *
     *
     * \internal
     * c_api_name BarcodeTypeCodabar
     * \endinternal
     */
    Codabar = 9,
    /**
     * \brief Interleaved 2 of 5
     *
     * Interleaved 2 of 5 is a numeric, self-checking, variable-length and highly compact barcode. A character is defined by
     * five black bars and five spaces; two black and two white bars are wide, all others bars are white. There is a leading and
     * trailing quiet zone, a start and stop character and an optional check character.
     *
     * The encoding is "interleaved" as the odd position numbers are encoded in the bars and the numbers in even positions in the
     * spaces. These barcodes must by necessity contain an even number of digits. (The length is often used as a check in
     * itself.)
     *
     * \internal
     * c_api_name BarcodeTypeInterleaved2Of5
     * \endinternal
     */
    Interleaved2Of5 = 10,
    /**
     * \brief Code 39
     *
     * Code 39 is an alphanumeric, self-checking, variable-length barcode. A character is defined by five black bars and four
     * spaces; three elements are wide, six are narrow. There is a leading and trailing quiet zone, a start and stop character
     * (the asterisk), an optional check character and a gap between the data characters.
     *
     * This symbology is sometimes called "3 of 9 code". It is primarily used where alphabetic characters are mandatory as you
     * can not only encode the digits, but also the uppercase letters and seven special characters (- . $ / + % and a space).
     *
     * Code 39 is a widely used industrial barcode and is mandated for some automotive industry and Department of Defense
     * labels, because of its ability to represent alphanumeric data.
     *
     * \internal
     * c_api_name BarcodeTypeCode39
     * \endinternal
     */
    Code39 = 12,
    /**
     * \brief Code 39 extended
     *
     * This is an extended version of Code 39 that supports the ASCII character set.
     *
     * So with Code 39 Extended you can also code the 26 lower letters (a-z) and the special characters you have on your
     * keyboard.
     *
     * It's an extended version of Code 39 allows to encode the full 128 ASCII character set. The "full" ASCII set refers to all
     * characters up to character 128 in the ASCII table set, the "special" and accentuated symbols from 128 onwards such as ?
     * and ? are not included.
     *
     * \internal
     * c_api_name BarcodeTypeCode39Extended
     * \endinternal
     */
    Code39Extended = 13,
    /**
     * \brief Code 39 HIBC
     *
     * Code 39 HIBC ("Health Industry Barcode") is a Code 39 barcode with a check character.
     *
     * \internal
     * c_api_name BarcodeTypeCode39Hibc
     * \endinternal
     */
    Code39Hibc = 14,
    /**
     * \brief Code 93
     *
     * Code 93 is a alphanumeric, self-checking, variable-length barcode. Every character is composed of nine elements arranged
     * in three bars with adjacent spaces.
     *
     * A character is defined by five black bars and four spaces; three elements are wide, six are narrow. There is a leading and
     * trailing quiet zone, a start and stop character, a termination bar and two check characters. The check characters are
     * verified but filtered from the output.
     *
     * Code 93 is an extended version of Code 39 that allows to encode the full 128 ASCII character set. The "full" ASCII set
     * refers to all characters up to character 128 in the ASCII table set, the "special" and accentuated symbols from 128
     * onwards such as ? and ? are not included. Code 93 is also slightly more compact than Code 39.
     *
     * This standard is used in an alphanumeric context as you can define the complete 128 ASCII character set.
     *
     * Code 93 is specifically designed to provide a more compact version of Code 39 due to its high-density complement.
     *
     * \internal
     * c_api_name BarcodeTypeCode93
     * \endinternal
     */
    Code93 = 15,
    /**
     * \brief Code 128
     *
     * Code 128 is a very high-density alphanumeric symbology.
     *
     * The Code 128 character set includes the digits 0-9, the letters A-Z (upper and lower cases), and all standard ASCII
     * symbols and control codes.
     *
     * It's a specialized barcode symbology for the banking world,
     *
     * \internal
     * c_api_name BarcodeTypeCode128
     * \endinternal
     */
    Code128 = 16,
    /**
     * \brief Postnet.
     *
     * The US postal barcode.
     *
     * PostNet is a numeric barcode for 5, 9 or 11 characters. PostNet is different from the other symbologies, as the data is
     * encoded in the height of the bars, not in the width of the bars and spaces, therefore few barcode reader can decode
     * PostNet barcodes. (This allows great flexibility: successful decoding is hardly dependent on brightness.)
     *
     * \internal
     * c_api_name BarcodeTypePostnet
     * \endinternal
     */
    Postnet = 18,
    /** 
     * \brief Patchcode are a set of 6 barcodes that are used to separate documents during scanning. 
     *
     * A patch code is a pattern of parallel, alternating black bars and spaces that is printed on a document. 
     * The patch code doesn't actually contain data; it is just a code which provides information to document processing.  
     *
     * The scanners which can understand patch codes can automatically switch through different modes, saving this way a lot of time during scanning.
     *
     * \internal
     * c_api_name BarcodeTypePatchcode
     * \endinternal
     */
    Patchcode = 22,
    /** 
     * \brief UCC 128, also known as GS1-128 is an application standard of the GS1 implementation using the Code 128 barcode specification.
     *
     * \internal
     * c_api_name BarcodeTypeUcc128
     * \endinternal
     */
    Ucc128 = 23,
    /**
     * \brief PDF 417
     *
     * PDF417 is a two-dimensional, stacked, public-domain barcode . ("PDF" stands for "Portable Data File". )
     *
     * It is a multi-row, continuous, variable length symbology that has high data capacity of storing up to about 1,800
     * printable ASCII characters or 1,100 binary character per symbol.
     *
     * The symbol is rectangular; the shape of the symbol can be adjusted to some extent by setting the width and allowing
     * the height to grow with the data.
     *
     * It is also possible to break large number of data into several PDF417 symbols that can logically linked.
     *
     * \attention Requires Barcode2D extension.
     *
     * \internal
     * c_api_name BarcodeTypePdf417
     * \endinternal
     */
    Pdf417 = 17,
    /**
     * \brief QR code (abbreviated from Quick Response Code) is a type of matrix barcode widely used across different industries due to its fast readability and greater storage capacity.
     *
     * The information encoded by a QR code may be made up of four standardized types ("modes") of data (numeric, alphanumeric, byte / binary, Kanji) or, through supported extensions, virtually any type of data
     *
     * \attention Requires Barcode2D extension.
     *
     * \internal
     * c_api_name BarcodeTypeQrCode
     * \endinternal
     */
    QrCode = 31,
    /**
     * \brief DataMatrix.
     *
     * DataMatrix is a high density 2D symbology that can encode up to 3116 characters from the entire 256 byte ASCII character set.
     *
     * \attention Requires Barcode2D extension.
     *
     * \internal
     * c_api_name BarcodeTypeDataMatrix
     * \endinternal
     */
    DataMatrix = 32,
    /**
     * \brief Aztec Code
     *
     * Aztec Code is a type of 2D barcode that has the potential to use less space than other matrix barcodes because it does not require a surrounding quiet zone.
     *
     * \attention Requires Barcode2D extension.
     *
     * \internal
     * c_api_name BarcodeTypeAztec
     * \endinternal
     */
    Aztec = 33,
    /**
     * \brief Custom barcode type
     * 
     * The custom barcode type allows integrators to use other barcode types than the ones provided by iDRS SDK.
     * Recognizing custom barcode types can be accomplished only with custom barcode engines - CBarcodeEngine
     *
     * \internal
     * c_api_name BarcodeTypeCustom
     * \endinternal
     */
    Custom = 100
  };
}
#endif //_BarcodeType_h