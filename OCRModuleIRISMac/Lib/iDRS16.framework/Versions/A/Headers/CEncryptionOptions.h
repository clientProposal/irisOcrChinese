/**
 * \file CEncryptionOptions.h
 * \brief Interface to the IDRS::DOCUMENT_OUTPUT::CEncryptionOptions class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _cencryptionoptions_h_
#define _cencryptionoptions_h_
#include "CObjPtr.h"
#include "EnumDefinitions.h"
namespace IDRS
{
  class CEncryptionOptionsData;
  class idrs_string;
  /**
   * \brief CEncryptionOptions manages the PDF Security parameters.
   *
   * \req IDRS::Module::DocumentOutput
   */
  class IDRSKRN_API CEncryptionOptions : public CObjPtr
  {
    public:
      /**
       * \brief Default constructor
       */
      inline CEncryptionOptions();
      /**
       * \brief Copy constructor
       */
      inline CEncryptionOptions( const CEncryptionOptions& argEncryptionOptions);
      /**
       * \brief Constructor
       */
      inline CEncryptionOptions(CEncryptionOptionsData * pObj );
      /**
       * \brief Destructor
       */
      inline virtual ~CEncryptionOptions();
      /**
       * \brief Create creates a CEncryptionOptions object.
       *
       * \param evEncryptionAlgorithm The encryption level.
       *
       */
      static CEncryptionOptions Create ( const EncryptionAlgorithm evEncryptionAlgorithm );
      /**
       * \brief Gets the encryption level.
       *
       * \return the encryption level
       */
      EncryptionAlgorithm GetEncryptionLevel () const;
      /**
       * \brief Sets the password required to open the document.
       * Please note that if the password length is more than 32 characters, only the first 32 characters will be considered.
       * Only ASCII characters are allowed in the password.
       *
       * \remarks The user password and owner password (if set) must be different.
       *
       * \pre ! IsNull ()
       *
       * \param strUserPassword The user password.
       *
       */
      void SetUserPassword ( const idrs_string& strUserPassword );
      /**
       * \brief Gets the password required to open the document.
       *
       * \pre ! IsNull ()
       *
       * \return The user password.
       */
      const idrs_string& GetUserPassword () const;
      /**
       * \brief Sets the owner password for the pdf document, allowing full access to it without taking restrictions into consideration.
       * Please note that if the password length is more than 32 characters, only the first 32 characters will be considered.
       * Only ASCII characters are allowed in the password. The accepted charsets are ANSI (range 0-127) and extended ANSI (range 128-255)
       *
       * \remarks The user password and owner password must be different.
       *
       * \param strOwnerPassword Password that will protect the document permissions to be changed
       */
      void SetOwnerPassword (const idrs_string& strOwnerPassword );
      /**
       * \brief Gets the owner password required to change permissions of the document.
       *
       * \pre ! IsNull ()
       *
       * \return The owner password.
       */
      const idrs_string& GetOwnerPassword () const;
      /**
       * \brief Sets the print permission for the pdf document.
       *
       * \param evPrintPermission The print permission to set
       */
      void SetPrintPermission ( const PrintPermission evPrintPermission );
      /**
       * \brief Gets the print permission.
       *
       * \return The print permission.
       */
      PrintPermission GetPrintPermission () const;
      /**
       * \brief Sets the edit permission for the pdf document.
       *
       * \param evEditPermission The edit permission to set
       */
      void SetEditPermission(const EditPermission evEditPermission);
      /**
       * \brief Gets the edit permission.
       *
       * \return The edit permission.
       */
      EditPermission GetEditPermission() const;
      /**
       * \brief Sets a flag that allows or denies content copy.
       *
       * Please note it is not allowed to have content copy enabled while text access is disabled.
       *
       * \param bEnableContentCopy flag specifying if copy operation is allowed or not
       */
      void SetEnableContentCopy ( const IDRS_BOOL bEnableContentCopy );
      /**
       * \brief Gets the content copy flag.
       *
       * \return Content copy flag
       */
      IDRS_BOOL GetEnableContentCopy () const;
      /**
       * \brief Sets the text access enable flag.
       *
       * \param bEnableTextAccess flag specifying whether to allow text access or not
       *
       */
      void SetEnableTextAccess ( const IDRS_BOOL bEnableTextAccess );
      /**
       * \brief Gets the flag specifying whether text access is enabled or not.
       *
       * \return flag for text access
       */
      IDRS_BOOL GetEnableTextAccess () const;

    private:
      /**
       * \brief Internal use
       */
      CEncryptionOptionsData & TypedObject () const
      {
        return (CEncryptionOptionsData & )Object ();
      };
  };
  /**
    *
    */
  inline CEncryptionOptions::CEncryptionOptions()
  {
  }
  /**
    *
    */
  inline CEncryptionOptions::CEncryptionOptions( const CEncryptionOptions& argEncryptionOptions)
    : CObjPtr (( CObjPtr & )argEncryptionOptions)
  {
  }
  /**
    *
    */
  inline CEncryptionOptions::CEncryptionOptions(CEncryptionOptionsData * pObj )
    : CObjPtr (( CObj * )pObj )
  {
  }
  /**
    *
    */
  inline CEncryptionOptions::~CEncryptionOptions()
  {
  }
} // namespace
#endif /* _cencryptionoptions_h_ */
