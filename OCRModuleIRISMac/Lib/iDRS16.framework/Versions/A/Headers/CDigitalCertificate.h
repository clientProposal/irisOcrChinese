/**
 * \file CDigitalCertificate.h
 * \brief Interface to the CDigitalCertificate class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _cdigitalcertificate_h_
#define _cdigitalcertificate_h_
#include "CObjPtr.h"
namespace IDRS
{
  class CDigitalCertificateData;
  class CMemoryBuffer;
  /**
    * \brief CDigitalCertificate manages the digital certificate content.
    *
    * \req IDRS::Module::DocumentOutput
    */
  class IDRSKRN_API CDigitalCertificate : public CObjPtr
  {
    public:
      /**
        * \brief Default constructor
        */
      inline CDigitalCertificate();
      /**
        * \brief Copy constructor
        */
      inline CDigitalCertificate( const CDigitalCertificate& argDigitalCertificate);
      /**
        * \brief Constructor
        */
      inline CDigitalCertificate(CDigitalCertificateData * pObj );
      /**
        * \brief Destructor
        */
      inline virtual ~CDigitalCertificate();
      /**
        * \brief Create creates a CDigitalCertificate object.
        *
        * \return The newly created page.
        */
      static CDigitalCertificate Create ();
      /**
       * \brief Set the issuer data that will be used for document signature. The supplied data are stored and will be used to search the certificate
       * when the document signing step will be performed.
       *
       * \remarks Please note that during the signing step, the signature lookup is performed in "MY" store.
       *
       * \remarks The provided memory buffer is copied internally, therefore it can be safely released afterwards.
       *
       * \param argIssuerData Buffer containing the issuer data. Typically, it can be found in pCertInfo->Issuer.pbData
       *
       * \pre ( argIssuerData.IsNull() || argIssuerData.GetSize() != 0 )
       */
      void SetIssuerData ( const CMemoryBuffer & argIssuerData );
      /**
       * \brief Get the issuer data.
       *
       * \return A memory buffer containing the issuer data.
       *
       * \remarks The buffer returned is a copy of the object stored internally.
       */
      CMemoryBuffer GetIssuerData () const;
      /**
       * \brief Set the serial number data that will be used for document signature. The supplied data are stored and will be used to search the certificate
       * when the document signing step will be performed.
       *
       * \remarks Please note that during the signing step, the signature lookup is performed in "MY" store.
       *
       * \remarks The provided memory buffer is copied internally, therefore it can be safely released afterwards.
       *
       * \param argSerialNumberData Buffer containing the Serial number data. Typically, it can be found in pCertInfo->SerialNumber.pbData
       *
       * \pre ( argSerialNumberData.IsNull() || argSerialNumberData.GetSize() != 0 )
       */
      void SetSerialNumberData ( const CMemoryBuffer & argSerialNumberData);
      /**
       * \brief Get the serial number data.
       *
       * \return A memory buffer containing the serial number data.
       *
       * \remarks The buffer returned is a copy of the object stored internally.
       */
      CMemoryBuffer GetSerialNumberData () const;
    private:
      /**
        * \brief Private use only
        */
      CDigitalCertificateData & TypedObject () const
      {
        return (CDigitalCertificateData & )Object ();
      };
  };
  /*
   *
   */
  inline CDigitalCertificate::CDigitalCertificate()
  {
  }
  /*
   *
   */
  inline CDigitalCertificate::CDigitalCertificate( const CDigitalCertificate& argDigitalCertificate)
    : CObjPtr (( CObjPtr & )argDigitalCertificate)
  {
  }
  /*
   *
   */
  inline CDigitalCertificate::CDigitalCertificate(CDigitalCertificateData * pObj )
    : CObjPtr (( CObj * )pObj )
  {
  }
  /*
   *
   */
  inline CDigitalCertificate::~CDigitalCertificate()
  {
  }
} // namespace
#endif /* _cdigitalcertificate_h_ */
