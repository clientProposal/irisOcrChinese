/**
 * \file COcrContext.h
 * \brief Interface for the IDRS::COcrContext class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _COcrContext_h_
#define _COcrContext_h_
#include "EnumDefinitions.h"
#include "ArrayDefinitions.h"
namespace IDRS
{
  class COcrContextData;
  class idrs_string;
  /**
   * \brief The COcrContext class manages a recognition context for the OCR engine.
   *
   * A recognition context consists in a recognition environment, one or multiple decision environments, a character set and a
   * set of parameters the OCR engine will use to analyze/recognize pages.
   *
   * An OCR context has a unique recognition environment and one ore more decision environments.
   * Decision environments are related to a specific language; recognition is related to the alphabets.
   *
   * The recognition environment is not immediately loaded at the time the integrator sets one or more languages in the OCR context.
   *
   * The number of languages an OCR context can manage at a time is specified in the define IDRS_LNG_COUNT_LIMIT.
   *
   * In addition to specifying the language, the integrator can limit the OCR context's character set. When the integrator set
   * the languages for the OCR context, iDRS computes the characters used by the languages to limit the OCR character set to
   * these characters.
   *
   * \req IDRS::Module::Ocr
   *
   * \see Language iDRS languages.
   * \see TextType for the available text types in iDRS.
   * \see TextDirection for the available text direction types
   * \see group_idrs_defaults The default recognition parameters.
   */
  class IDRSKRN_API COcrContext : public CObjPtr
  {
    public:
      //
      inline COcrContext ();
      //
      inline COcrContext ( const COcrContext & aOcrContext );
      //
      inline COcrContext ( COcrContextData * pObj );
      //
      inline virtual ~COcrContext ();
      /**
       * \brief Create creates an OCR context for the given language and text type parameters.
       *
       * \param lLanguage The identifier for the recognition language.
       *
       */
      static COcrContext Create ( const Language lLanguage );
      /**
       * \brief Create creates an OCR context for the given languages and text type parameters.
       *
       * \param xlLanguages An array that contains the identifiers for the languages to recognize.
       *
       * \throw CIDRSException If an error occur.
       *
       *
       * \ref page7
       *
       */
      static COcrContext Create ( const LanguageArray& xlLanguages );
      /**
       * \brief Create creates an OCR context for the given languages and text type parameters.
       *
       * \param xlLanguages An array that contains the identifiers for the languages to recognize.
       * \param uiLanguagesCount Number of language items in xlLanguages argument.
       *
       * \throw CIDRSException If an error occur.
       *
       *
       * \ref page7
       *
       */
      static COcrContext Create(const Language* xlLanguages, const IDRS_UINT uiLanguagesCount);
      /**
       * \brief Gets the languages used for ocr recognition
       *
       * \attention All changes to the returned object will have effect on the COcrContext object
       */
      LanguageArray GetLanguages() const;
      /**
       * \brief Set the ocr recognition languages 
       *
       * \param argLanguages The array containing the languages to be used during ocr recognition
       */
      void SetLanguages ( const LanguageArray & argLanguages );
      /**
       * \brief Sets the text detection sensitivity
       * 
       * \param evTextDetectionSensivity Text detection sensitivity
       */
      void SetTextDetectionSensivity(const TextDetectionSensivity evTextDetectionSensivity);
      /**
       * \brief Gets the text detection sensitivity
       *
       * \return Text detection sensitivity
       */
      TextDetectionSensivity GetTextDetectionSensivity() const;
      /**
       * \brief Sets the font computation type
       *
       * \param evFontInfoComputation Font computation type
       */
      void SetFontInfoComputation(const FontInfoComputation evFontInfoComputation);
      /**
       * \brief Gets the font computation type
       *
       * \return Font computation type
       */
      FontInfoComputation GetFontInfoComputation() const;
      /**
       * \brief Sets the character set to be used during text recognition 
       *
       * \param strCharacterSet Buffer containing the characters to be used during text recognition
       */
      void SetCharacterSet(const idrs_string& strCharacterSet);
      /**
       * \brief Gets the character set to be used during text recognition
       *
       * \return Buffer containing the characters to be used during text recognition
       */
      const idrs_string& GetCharacterSet() const;
      /**
       * \brief Sets the type of text that is expected to be recognized
       *
       * By default, the text type is set to TextType::Printed
       *
       * \param evTextType Text type - see \see TextType for more details
       */
      void SetTextType(const TextType evTextType);
      /**
       * \brief Gets the text type associated to this ocr context
       *
       * By default, the text type is set to TextType::Printed
       * 
       * \return Text type associated to the context
       */
      TextType GetTextType() const;
      /**
       * \brief IsEqual tests if two ocr contexts are equal.
       * \pre ! IsNull ()
       * \pre ! argOcrContext.IsNull ()
       * \param argOcrContext The ocr context to compare to
       * \return IDRS_TRUE if the provided ocr context equals the ocr context.
       */
      IDRS_BOOL IsEqual ( const COcrContext & argOcrContext ) const;
    private:
      //
      COcrContextData & TypedObject () const
      {
        return ( COcrContextData & )Object ();
      };
  };
  /*
   *
   */
  inline COcrContext::COcrContext ()
  {
  }
  /*
   *
   */
  inline COcrContext::COcrContext ( const COcrContext & aOcrContext )
    : CObjPtr((CObjPtr& )aOcrContext )
  {
  }
  /*
   *
   */
  inline COcrContext::COcrContext ( COcrContextData * pObj )
    : CObjPtr((CObj* )pObj )
  {
  }
  /*
   *
   */
  inline COcrContext::~COcrContext ()
  {
  }
} // namespace
#endif /* _COcrContext_h_ */
