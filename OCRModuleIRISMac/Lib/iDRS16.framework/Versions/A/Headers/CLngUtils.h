/**
 * \file CLngUtils.h
 * \brief Interface for the IDRS::CLngUtils class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _CLngUtils_h_
#define _CLngUtils_h_
#include <CIDRS.h>
#include <ArrayDefinitions.h>

namespace IDRS
{
  class CLngUtilsData;
  class idrs_string;
  /**
   * \brief The CLngUtils class provides some helper methods to manage the iDRS languages.
   *
   * The class exposes functions for:
   * - testing languages compatibility
   * - detecting language type
   * - compute character set
   *
   * \req IDRS::Module::Ocr
   */
  class IDRSKRN_API CLngUtils
  {
    public:
      /**
       * \brief Destructor
       */
      inline virtual ~CLngUtils ();
      /**
       * \brief TestCompatibility tests if two languages are compatible for an OCR context.
       *
       * TestCompatibility tests if the given two languages can be mixed inside the same OCR context.
       *
       * \pre lMainLng < IDRS_LNG_COUNT
       * \pre lSecLng < IDRS_LNG_COUNT
       *
       * \param lMainLng The identifier for the main language.
       * \param lSecLng The identifier for the secondary language.
       *
       * \retval IDRS_TRUE if the first language accepts the given secondary language.
       * \retval IDRS_FALSE otherwise.
       *
       */
      static IDRS_BOOL TestCompatibility ( const Language lMainLng, const Language lSecLng );
      /**
       * \brief TestCompatibility tests if the given languages can be mixed inside the same OCR context.
       *
       * \param argLanguages Array containing the languages to be tested
       *
       * \retval IDRS_TRUE if the languages can be mixed.
       * \retval IDRS_FALSE otherwise.
       *
       */
      static IDRS_BOOL TestCompatibility ( const LanguageArray& argLanguages );
      /**
       * \brief ComputeCharset computes the character set for the given language.
       *
       * \param lLanguage The identifier for the language.
       * \return The character set.
       */
      static idrs_string ComputeCharset ( const Language lLanguage );
      /**
       * \brief ComputeCharset computes the character set for the supplied LanguageArray object.
       *
       * \pre ! argCharacterSet.IsNull ()
       *
       * \param xLanguages The LanguageArray object containing the languages.
       * \return The character set for the provided languages
       */
      static idrs_string ComputeCharset ( const LanguageArray& xLanguages );
    private:
      /**
       * \brief Default constructor.
       */
      inline CLngUtils();
      /**
       * \brief Copy constructor.
       *
       * \param argLngUtils The object to copy.
       */
      inline CLngUtils(const CLngUtils& argLngUtils);
  };
} // namespace
#endif /* _CLngUtils_h_ */
