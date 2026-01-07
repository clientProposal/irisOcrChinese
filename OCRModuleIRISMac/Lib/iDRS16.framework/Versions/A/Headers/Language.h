/**
 * \file Language.h
 * \brief Definition of iDRS languages.
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _idrslng_h_
#define _idrslng_h_
#include <idrskrn.h>
namespace IDRS
{
  /** \page page7 Language combination rules
   *
   * iDRS OCR engine accepts up to IDRS_LNG_COUNT_LIMIT recognition languages at a time.
   *
   * This is helpful to process mixed documents but, because of the various character sets, not all combinations are allowed.
   *
   * iDRS recognition languages are grouped by categories according to their character set.
   *
   * \see CLngUtils::TestCompatibility Tests if two languages can be mixed.
   *
   */
  /**
   * \brief The number of language identifiers for iDRS.
   */
  #define IDRS_LNG_COUNT 139
  /**
   * \brief The maximum number of languages that iDRS can process at a time.
   */
  #define IDRS_LNG_COUNT_LIMIT 8
  /**
   * \brief The Language data type defines a language identifier.
   * \ingroup module_ocr
   *
   *
   */
  enum class Language : int
  {
    /**
     * \brief English (American)
     *
     * \internal
     * c_api_name LanguageEnglish
     * \endinternal
     */
    English = 0,
    /**
     * \brief German
     *
     * \internal
     * c_api_name LanguageGerman
     * \endinternal
     */
    German = 1,
    /**
     * \brief French
     *
     * \internal
     * c_api_name LanguageFrench
     * \endinternal
     */
    French = 2,
    /**
     * \brief Spanish
     *
     * \internal
     * c_api_name LanguageSpanish
     * \endinternal
     */
    Spanish = 3,
    /**
     * \brief Italian
     *
     * \internal
     * c_api_name LanguageItalian
     * \endinternal
     */
    Italian = 4,
    /**
     * \brief English (British)
     *
     * \internal
     * c_api_name LanguageBritish
     * \endinternal
     */
    British = 5,
    /**
     * \brief Swedish
     *
     * \internal
     * c_api_name LanguageSwedish
     * \endinternal
     */
    Swedish = 6,
    /**
     * \brief Danish
     *
     * \internal
     * c_api_name LanguageDanish
     * \endinternal
     */
    Danish = 7,
    /**
     * \brief Norwegian
     *
     * Norwegian Bokm�l.
     *
     * \see Nynorsk
     *
     * \internal
     * c_api_name LanguageNorwegian
     * \endinternal
     */
    Norwegian = 8,
    /**
     * \brief Dutch
     *
     * \internal
     * c_api_name LanguageDutch
     * \endinternal
     */
    Dutch = 9,
    /**
     * \brief Portuguese
     *
     * \internal
     * c_api_name LanguagePortuguese
     * \endinternal
     */
    Portuguese = 10,
    /**
     * \brief Brazilian Portuguese
     *
     * \internal
     * c_api_name LanguageBrazilian
     * \endinternal
     */
    Brazilian = 11,
    /**
     * \brief Galician
     *
     * \internal
     * c_api_name LanguageGalician
     * \endinternal
     */
    Galician = 12,
    /**
     * \brief Icelandic
     *
     * \internal
     * c_api_name LanguageIcelandic
     * \endinternal
     */
    Icelandic = 13,
    /**
     * \brief Greek
     *
     * \internal
     * c_api_name LanguageGreek
     * \endinternal
     */
    Greek = 14,
    /**
     * \brief Czech
     *
     * \internal
     * c_api_name LanguageCzech
     * \endinternal
     */
    Czech = 15,
    /**
     * \brief Hungarian
     *
     * \internal
     * c_api_name LanguageHungarian
     * \endinternal
     */
    Hungarian = 16,
    /**
     * \brief Polish
     *
     * \internal
     * c_api_name LanguagePolish
     * \endinternal
     */
    Polish = 17,
    /**
     * \brief Romanian
     *
     * \internal
     * c_api_name LanguageRomanian
     * \endinternal
     */
    Romanian = 18,
    /**
     * \brief Slovak
     *
     * \internal
     * c_api_name LanguageSlovak
     * \endinternal
     */
    Slovak = 19,
    /**
     * \brief Croatian
     *
     * \internal
     * c_api_name LanguageCroatian
     * \endinternal
     */
    Croatian = 20,
    /**
     * \brief Serbian
     *
     * \internal
     * c_api_name LanguageSerbian
     * \endinternal
     */
    Serbian = 21,
    /**
     * \brief Slovenian
     *
     * \internal
     * c_api_name LanguageSlovenian
     * \endinternal
     */
    Slovenian = 22,
    /**
     * \brief Luxembourgish
     *
     * \internal
     * c_api_name LanguageLuxembourgish
     * \endinternal
     */
    Luxembourgish = 23,
    /**
     * \brief Finnish
     *
     * \internal
     * c_api_name LanguageFinnish
     * \endinternal
     */
    Finnish = 24,
    /**
     * \brief Turkish
     *
     * \internal
     * c_api_name LanguageTurkish
     * \endinternal
     */
    Turkish = 25,
    /**
     * \brief Russian
     *
     * \internal
     * c_api_name LanguageRussian
     * \endinternal
     */
    Russian = 26,
    /**
     * \brief Belarusian
     *
     * \internal
     * c_api_name LanguageBelarusian
     * \endinternal
     */
    Belarusian = 27,
    /**
     * \brief Ukrainian
     *
     * \internal
     * c_api_name LanguageUkrainian
     * \endinternal
     */
    Ukrainian = 28,
    /**
     * \brief Macedonian
     *
     * \internal
     * c_api_name LanguageMacedonian
     * \endinternal
     */
    Macedonian = 29,
    /**
     * \brief Bulgarian
     *
     * \internal
     * c_api_name LanguageBulgarian
     * \endinternal
     */
    Bulgarian = 30,
    /**
     * \brief Estonian
     *
     * \internal
     * c_api_name LanguageEstonian
     * \endinternal
     */
    Estonian = 31,
    /**
     * \brief Lithuanian
     *
     * \internal
     * c_api_name LanguageLithuanian
     * \endinternal
     */
    Lithuanian = 32,
    /**
     * \brief Afrikaans
     *
     * \internal
     * c_api_name LanguageAfrikaans
     * \endinternal
     */
    Afrikaans = 33,
    /**
     * \brief Albanian
     *
     * \internal
     * c_api_name LanguageAlbanian
     * \endinternal
     */
    Albanian = 34,
    /**
     * \brief Catalan
     *
     * \internal
     * c_api_name LanguageCatalan
     * \endinternal
     */
    Catalan = 35,
    /**
     * \brief Irish Gaelic
     *
     * \internal
     * c_api_name LanguageIrishGaelic
     * \endinternal
     */
    IrishGaelic = 36,
    /**
     * \brief Scottish Gaelic
     *
     * \internal
     * c_api_name LanguageScottishGaelic
     * \endinternal
     */
    ScottishGaelic = 37,
    /**
     * \brief Basque
     *
     * \internal
     * c_api_name LanguageBasque
     * \endinternal
     */
    Basque = 38,
    /**
     * \brief Breton
     *
     * \internal
     * c_api_name LanguageBreton
     * \endinternal
     */
    Breton = 39,
    /**
     * \brief Corsican
     *
     * \internal
     * c_api_name LanguageCorsican
     * \endinternal
     */
    Corsican = 40,
    /**
     * \brief Frisian
     *
     * \internal
     * c_api_name LanguageFrisian
     * \endinternal
     */
    Frisian = 41,
    /**
     * \brief Norwegian Nynorsk
     *
     * \see Norwegian
     *
     * \internal
     * c_api_name LanguageNynorsk
     * \endinternal
     */
    Nynorsk = 42,
    /**
     * \brief Indonesian
     *
     * \internal
     * c_api_name LanguageIndonesian
     * \endinternal
     */
    Indonesian = 43,
    /**
     * \brief Malay
     *
     * \internal
     * c_api_name LanguageMalay
     * \endinternal
     */
    Malay = 44,
    /**
     * \brief Swahili
     *
     * \internal
     * c_api_name LanguageSwahili
     * \endinternal
     */
    Swahili = 45,
    /**
     * \brief Tagalog
     *
     * \internal
     * c_api_name LanguageTagalog
     * \endinternal
     */
    Tagalog = 46,
    /**
     * \brief Japanese.
     *
     * \attention Requires Extension.OcrAsianExtra.
     *
     * \internal
     * c_api_name LanguageJapanese
     * \endinternal
     */
    Japanese = 47,
    /**
     * \brief Korean.
     *
     * \attention Requires Extension.OcrAsianExtra.
     *
     * \internal
     * c_api_name LanguageKorean
     * \endinternal
     */
    Korean = 48,
    /**
     * \brief Simplified chinese.
     *
     * \attention Requires Extension.OcrAsianExtra.
     *
     * \internal
     * c_api_name LanguageChineseSimplified
     * \endinternal
     */
    ChineseSimplified = 49,
    /**
     * \brief Traditional chinese.
     *
     * \attention Requires Extension.OcrAsianExtra.
     *
     * \internal
     * c_api_name LanguageChineseTraditional
     * \endinternal
     */
    ChineseTraditional = 50,
    /**
     * \brief Quechua
     *
     * \internal
     * c_api_name LanguageQuechua
     * \endinternal
     */
    Quechua = 51,
    /**
     * \brief Aymara
     *
     * \internal
     * c_api_name LanguageAymara
     * \endinternal
     */
    Aymara = 52,
    /**
     * \brief Faroese
     *
     * \internal
     * c_api_name LanguageFaroese
     * \endinternal
     */
    Faroese = 53,
    /**
     * \brief Friulian
     *
     * \internal
     * c_api_name LanguageFriulian
     * \endinternal
     */
    Friulian = 54,
    /**
     * \brief Greenlandic
     *
     * \internal
     * c_api_name LanguageGreenlandic
     * \endinternal
     */
    Greenlandic = 55,
    /**
     * \brief Haitian Creole
     *
     * \internal
     * c_api_name LanguageHaitianCreole
     * \endinternal
     */
    HaitianCreole = 56,
    /**
     * \brief Rhaeto-Romance
     *
     * \internal
     * c_api_name LanguageRhaetoRoman
     * \endinternal
     */
    RhaetoRoman = 57,
    /**
     * \brief Sardinian
     *
     * \internal
     * c_api_name LanguageSardinian
     * \endinternal
     */
    Sardinian = 58,
    /**
     * \brief Kurdish
     *
     * \internal
     * c_api_name LanguageKurdish
     * \endinternal
     */
    Kurdish = 59,
    /**
     * \brief Cebuano
     *
     * \internal
     * c_api_name LanguageCebuano
     * \endinternal
     */
    Cebuano = 60,
    /**
     * \brief Bemba
     *
     * \internal
     * c_api_name LanguageBemba
     * \endinternal
     */
    Bemba = 61,
    /**
     * \brief Chamorro
     *
     * \internal
     * c_api_name LanguageChamorro
     * \endinternal
     */
    Chamorro = 62,
    /**
     * \brief Fijian
     *
     * \internal
     * c_api_name LanguageFijian
     * \endinternal
     */
    Fijian = 63,
    /**
     * \brief Ganda
     *
     * \internal
     * c_api_name LanguageGanda
     * \endinternal
     */
    Ganda = 64,
    /**
     * \brief Hani
     *
     * \internal
     * c_api_name LanguageHani
     * \endinternal
     */
    Hani = 65,
    /**
     * \brief Ido
     *
     * \internal
     * c_api_name LanguageIdo
     * \endinternal
     */
    Ido = 66,
    /**
     * \brief Interlingua
     *
     * \internal
     * c_api_name LanguageInterlingua
     * \endinternal
     */
    Interlingua = 67,
    /**
     * \brief Kikongo
     *
     * \internal
     * c_api_name LanguageKikongo
     * \endinternal
     */
    Kikongo = 68,
    /**
     * \brief Kinyarwanda
     *
     * \internal
     * c_api_name LanguageKinyarwanda
     * \endinternal
     */
    Kinyarwanda = 69,
    /**
     * \brief Malagasy
     *
     * \internal
     * c_api_name LanguageMalagasy
     * \endinternal
     */
    Malagasy = 70,
    /**
     * \brief Maori
     *
     * \internal
     * c_api_name LanguageMaori
     * \endinternal
     */
    Maori = 71,
    /**
     * \brief Mayan
     *
     * \internal
     * c_api_name LanguageMayan
     * \endinternal
     */
    Mayan = 72,
    /**
     * \brief Minangkabau
     *
     * \internal
     * c_api_name LanguageMinangkabau
     * \endinternal
     */
    Minangkabau = 73,
    /**
     * \brief Nahuatl
     *
     * \internal
     * c_api_name LanguageNahuatl
     * \endinternal
     */
    Nahuatl = 74,
    /**
     * \brief Nyanja
     *
     * \internal
     * c_api_name LanguageNyanja
     * \endinternal
     */
    Nyanja = 75,
    /**
     * \brief Kirundi
     *
     * \internal
     * c_api_name LanguageKirundi
     * \endinternal
     */
    Kirundi = 76,
    /**
     * \brief Samoan
     *
     * \internal
     * c_api_name LanguageSamoan
     * \endinternal
     */
    Samoan = 77,
    /**
     * \brief Shona
     *
     * \internal
     * c_api_name LanguageShona
     * \endinternal
     */
    Shona = 78,
    /**
     * \brief Somali
     *
     * \internal
     * c_api_name LanguageSomali
     * \endinternal
     */
    Somali = 79,
    /**
     * \brief Sotho
     *
     * \internal
     * c_api_name LanguageSotho
     * \endinternal
     */
    Sotho = 80,
    /**
     * \brief Sundanese
     *
     * \internal
     * c_api_name LanguageSundanese
     * \endinternal
     */
    Sundanese = 81,
    /**
     * \brief Tahitian
     *
     * \internal
     * c_api_name LanguageTahitian
     * \endinternal
     */
    Tahitian = 82,
    /**
     * \brief Tongan
     *
     * \internal
     * c_api_name LanguageTonga
     * \endinternal
     */
    Tonga = 83,
    /**
     * \brief Tswana
     *
     * \internal
     * c_api_name LanguageTswana
     * \endinternal
     */
    Tswana = 84,
    /**
     * \brief Wolof
     *
     * \internal
     * c_api_name LanguageWolof
     * \endinternal
     */
    Wolof = 85,
    /**
     * \brief Xhosa
     *
     * \internal
     * c_api_name LanguageXhosa
     * \endinternal
     */
    Xhosa = 86,
    /**
     * \brief Zapotec
     *
     * \internal
     * c_api_name LanguageZapotec
     * \endinternal
     */
    Zapotec = 87,
    /**
     * \brief Javanese
     *
     * \internal
     * c_api_name LanguageJavanese
     * \endinternal
     */
    Javanese = 88,
    /**
     * \brief Nigerian Pidgin
     *
     * \internal
     * c_api_name LanguageNigerianPidgin
     * \endinternal
     */
    NigerianPidgin = 89,
    /**
     * \brief Occitan
     *
     * \internal
     * c_api_name LanguageOccitan
     * \endinternal
     */
    Occitan = 90,
    /**
     * \brief Manx
     *
     * \internal
     * c_api_name LanguageManx
     * \endinternal
     */
    Manx = 91,
    /**
     * \brief Tok pisin
     *
     * \internal
     * c_api_name LanguageTokPisin
     * \endinternal
     */
    TokPisin = 92,
    /**
     * \brief Bislama
     *
     * \internal
     * c_api_name LanguageBislama
     * \endinternal
     */
    Bislama = 93,
    /**
     * \brief Hiligaynon
     *
     * \internal
     * c_api_name LanguageHiligaynon
     * \endinternal
     */
    Hiligaynon = 94,
    /**
     * \brief Kapampangan
     *
     * \internal
     * c_api_name LanguageKapampangan
     * \endinternal
     */
    Kapampangan = 95,
    /**
     * \brief Balinese
     *
     * \internal
     * c_api_name LanguageBalinese
     * \endinternal
     */
    Balinese = 96,
    /**
     * \brief Bikol
     *
     * \internal
     * c_api_name LanguageBikol
     * \endinternal
     */
    Bikol = 97,
    /**
     * \brief Ilocano.
     *
     * \internal
     * c_api_name LanguageIlocano
     * \endinternal
     */
    Ilocano = 98,
    /**
     * \brief Madurese.
     *
     * \internal
     * c_api_name LanguageMadurese
     * \endinternal
     */
    Madurese = 99,
    /**
     * \brief Waray.
     *
     * \internal
     * c_api_name LanguageWaray
     * \endinternal
     */
    Waray = 100,
    /**
     * \brief No language, Latin alphabet
     *
     * \internal
     * c_api_name LanguageNone
     * \endinternal
     */
    None = 101,
    /**
     * \brief Serbian latin.
     *
     * \internal
     * c_api_name LanguageSerbianLatin
     * \endinternal
     */
    SerbianLatin = 102,
    /**
     * \brief Latin.
     *
     * \internal
     * c_api_name LanguageLatin
     * \endinternal
     */
    Latin = 103,
    /**
     * \brief Latvian.
     *
     * \internal
     * c_api_name LanguageLatvian
     * \endinternal
     */
    Latvian = 104,
    /**
     * \brief Hebrew.
     *
     * \attention Requires Extension.OcrHebrew.
     *
     * \internal
     * c_api_name LanguageHebrew
     * \endinternal
     */
    Hebrew = 105,
    /**
     * \brief CMC7
     *
     * This language allows you to read CMC7 character strings. The character set is limited to the numbers and the five
     * special symbols.
     *
     * No syntax checks are performed as the special symbols are an "internal" symbol which indicates the start of the bank's
     * internal information, an amount symbol, a terminator symbol and a "routing" symbol. The  symbol is recognized but has
     * no name and is used by only few applications.
     *
     * The five "special" characters are replaced by ANSI symbols: the internal symbol is by default represented by the
     * symbol "-", the amount symbol as "=", the terminator symbol  as "<", the symbol as ";" and the routing symbol as "+".
     *
     * The spaces as occur in CMC7 magnetic lines are ignored.
     *
     * \internal
     * c_api_name LanguageCmc7
     * \endinternal
     */
    Cmc7 = 106,
    /**
     * \brief E13B Optical
     *
     * This language limits recognition to the banking font E13B and supports the following character set: the numerals (0 - 9)
     * and four special characters (<, >, + and #).
     *
     * These four special characters are represented by the following Unicode symbols: the transit character (U+2446) is represented
     * by the "#" character, the amount character (U+2447) by "<", the on-us character (U+2448) by ">" and the dash character (U+2449)
     * by "+".
     *
     * \internal
     * c_api_name LanguageE13bOptical
     * \endinternal
     */
    E13bOptical = 107,
    /**
     * \brief OCR-A1 Alphanumeric
     *
     * This language limits recognition to the banking font OCR-A size I and supports an extended character sets: the numerals
     * (0 - 9), the uppercase letters and a wide range of special characters (! " # $ % & ' ( ) * + , . / \ : ; < > = ? @ [ ] ^
     ****_ ' { } � � �) are recognized.
     *
     * \remarks Size I corresponds to characters which are 0.094" (2.39 mm) high.
     *
     * \internal
     * c_api_name LanguageOcrA1Alphanumeric
     * \endinternal
     */
    OcrA1Alphanumeric = 108,
    /**
     * \brief OCR-A1 Eurobanking
     *
     * This language limits recognition to the banking font OCR-A size I and recognizes the character set of the Eurobanking
     * standard: the numerals (0 - 9), some uppercase letters (C, P, R, U, X and Z) and a range of special characters (+ # | /
     * . , * ^ ` _ "   ).
     *
     * The three "robotic" characters are replaced by ANSI symbols: the chair is represented by the symbol "^", the
     * fork by the symbol "_" (underscore) and the hook by the symbol "`" ("grave accent").
     *
     * \remarks Size I corresponds to characters which are 0.094" (2.39 mm) high.
     *
     * \internal
     * c_api_name LanguageOcrA1Eurobanking
     * \endinternal
     */
    OcrA1Eurobanking = 109,
    /**
     * \brief OCR-A1 Numeric
     *
     * This language limits recognition to the banking font OCR-A size I and recognizes a basically numeric character set
     * composed of the numerals (0 - 9) and three special characters (^ ` _).
     *
     * \remarks Size I corresponds to characters which are 0.094" (2.39 mm) high.
     *
     * \internal
     * c_api_name LanguageOcrA1Numeric
     * \endinternal
     */
    OcrA1Numeric = 110,
    /**
     * \brief OCR-B1 Alphanumeric
     *
     * This language limits recognition to the banking font OCR-B size I and supports an extended character sets: the numerals
     * (0 - 9), the uppercase letters and a wide range of special characters (! " # $ % & ' ( ) * + , . / \ : ; < > = ? @ [ ] ^
     * _ ' { } � � �) are recognized.
     *
     * \remarks Size I corresponds to characters which are 0.094" (2.39 mm) high.
     *
     * \internal
     * c_api_name LanguageOcrB1Alphanumeric
     * \endinternal
     */
    OcrB1Alphanumeric = 111,
    /**
     * \brief OCR-B1 Eurobanking
     *
     * This language limits recognition to the banking font OCR-B size I and supports the character set of the Eurobanking
     * standard: the numbers (0 - 9), some uppercase letters (J, N, P and X) and a range of special characters (< > + - / # *
     * | . , ").
     *
     * \remarks Size I corresponds to characters which are 0.094" (2.39 mm) high.
     *
     * \internal
     * c_api_name LanguageOcrB1Eurobanking
     * \endinternal
     */
    OcrB1Eurobanking = 112,
    /**
     * \brief OCR-B1 Numeric
     *
     * This language limits recognition to the banking font OCR-B size I and supports a basically numeric character set
     * composed of the numerals (0 - 9) and three special characters (+ < >).
     *
     * \remarks Size I corresponds to characters which are 0.094" (2.39 mm) high.
     *
     * \internal
     * c_api_name LanguageOcrB1Numeric
     * \endinternal
     */
    OcrB1Numeric = 113,
    /**
     * \brief Numeric
     *
     * This language limits recognition to numeric characters.
     *
     * \internal
     * c_api_name LanguageNumeric
     * \endinternal
     */
    Numeric = 114,
    /**
     * \brief Esperanto.
     *
     * \internal
     * c_api_name LanguageEsperanto
     * \endinternal
     */
    Esperanto = 115,
    /**
     * \brief Maltese.
     *
     * \internal
     * c_api_name LanguageMaltese
     * \endinternal
     */
    Maltese = 116,
    /**
     * \brief Zulu.
     *
     * \internal
     * c_api_name LanguageZulu
     * \endinternal
     */
    Zulu = 117,
    /**
     * \brief Afaan Oromo.
     *
     * \internal
     * c_api_name LanguageAfaan
     * \endinternal
     */
    Afaan = 118,
    /**
     * \brief Asturian.
     *
     * \internal
     * c_api_name LanguageAsturian
     * \endinternal
     */
    Asturian = 119,
    /**
     * \brief Azeri (latin).
     *
     * \internal
     * c_api_name LanguageAzeriLatin
     * \endinternal
     */
    AzeriLatin = 120,
    /**
     * \brief Luba.
     *
     * \internal
     * c_api_name LanguageLuba
     * \endinternal
     */
    Luba = 121,
    /**
     * \brief Papiamento.
     *
     * \internal
     * c_api_name LanguagePapiamento
     * \endinternal
     */
    Papiamento = 122,
    /**
     * \brief Tatar (latin).
     *
     * \internal
     * c_api_name LanguageTatar
     * \endinternal
     */
    Tatar = 123,
    /**
     * \brief Turkmen (latin).
     *
     * \internal
     * c_api_name LanguageTurkmen
     * \endinternal
     */
    Turkmen = 124,
    /**
     * \brief Welsh.
     *
     * \internal
     * c_api_name LanguageWelsh
     * \endinternal
     */
    Welsh = 125,
    /**
     * \brief Arabic.
     *
     * \attention Requires Extension.OcrArabic.
     *
     * \internal
     * c_api_name LanguageArabic
     * \endinternal
     */
    Arabic = 126,
    /**
     * \brief Farsi.
     *
     * \attention Requires Extension.OcrArabic.
     *
     * \internal
     * c_api_name LanguageFarsi
     * \endinternal
     */
    Farsi = 127,
    /**
     * \brief Mexican Spanish.
     *
     * \internal
     * c_api_name LanguageMexican
     * \endinternal
     */
    Mexican = 128,
    /**
     * \brief Bosnian (Latin).
     *
     * \internal
     * c_api_name LanguageBosnianLatin
     * \endinternal
     */
    BosnianLatin = 129,
    /**
     * \brief Bosnian (Cyrillic).
     *
     * \internal
     * c_api_name LanguageBosnianCyrillic
     * \endinternal
     */
    BosnianCyrillic = 130,
    /**
     * \brief Moldovan.
     *
     * \internal
     * c_api_name LanguageMoldovan
     * \endinternal
     */
    Moldovan = 131,
    /**
     * \brief German (Switzerland).
     *
     * \internal
     * c_api_name LanguageSwissGerman
     * \endinternal
     */
    SwissGerman = 132,
    /**
     * \brief Tetum.
     *
     * \internal
     * c_api_name LanguageTetum
     * \endinternal
     */
    Tetum = 133,
    /**
     * \brief Kazakh (Cyrillic).
     *
     * \internal
     * c_api_name LanguageKazakh
     * \endinternal
     */
    Kazakh = 134,
    /**
     * \brief Mongolian (Cyrillic).
     *
     * \internal
     * c_api_name LanguageMongolianCyrillic
     * \endinternal
     */
    MongolianCyrillic = 135,
    /**
     * \brief Uzbek (Latin).
     *
     * \internal
     * c_api_name LanguageUzbekLatin
     * \endinternal
     */
    UzbekLatin = 136,
    /**
     * \brief Vietnamese
     *
     * \attention Requires Extension.OcrAsianExtra.
     *
     * \internal
     * c_api_name LanguageVietnamese
     * \endinternal
     *
     * \attention Requires Extension.OcrAsianExtra.
     */
    Vietnamese = 137,
    /**
     * \brief Thai
     *
     * \attention Requires Extension.OcrAsianExtra.
     *
     * \internal
     * c_api_name LanguageThai
     * \endinternal
     *
     * \attention Requires Extension.OcrAsianExtra.
     */
    Thai = 138
  };
} // namespace
#endif /* _idrslng_h_ */
