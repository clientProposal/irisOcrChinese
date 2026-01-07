/**
 * \file CDigitalSignature.h
 * \brief Interface to the CDigitalSignature class.
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */

#ifndef _cdigitalsignature_h_
#define _cdigitalsignature_h_

#include "CObjPtr.h"
#include "CSignatureContent.h"
#include "CDigitalCertificate.h"
namespace IDRS
{
  class CDigitalSignatureData;
  /**
    * \brief CDigitalSignature container class that manages all signature aspects (digital certificate, UI content and page index).
    *
    * \req IDRS::Module::DocumentOutput
    */
  class IDRSKRN_API CDigitalSignature : public CObjPtr
  {
    public:
      /**
        * \brief Default constructor
        */
      inline CDigitalSignature();
      /**
        * \brief Copy constructor
        */
      inline CDigitalSignature(const CDigitalSignature& argDigitalSignature);
      /**
        * \brief Constructor
        */
      inline CDigitalSignature(CDigitalSignatureData* pObj);
      /**
        * \brief Constructor
        */
      inline CDigitalSignature(CObj* pObj);
      /**
        * \brief Destructor
        */
      inline virtual ~CDigitalSignature();
      /**
        * \brief Create creates a CDigitalSignature object.
        *
        * \return The newly created page.
        */
      static CDigitalSignature Create();
      /**
        * \brief Sets the signature visual content.
        *
        * By default the signatures placed by iDRS do not have any visual elements.
        * Using CSignatureContent you can define the way the signature looks on the pdf page as well as its location
        */
      void SetSignatureContent(const CSignatureContent& argSignatureContent);
      /**
        * \brief Retrieves the signature visual content.
        */
      CSignatureContent GetSignatureContent() const;
      /**
        * \brief Sets the digital signature
        */
      void SetDigitalCertificate(const CDigitalCertificate& argDigitalCertificate);
      /**
        * \brief Retrieves the digital signature
        */
      CDigitalCertificate GetDigitalCertificate() const;
      /**
        * \brief Sets the page index
        */
      void SetPageIndex(const IDRS_UINT uiPageIndex);
      /**
        * \brief Retrieves the page index
        * default value 0
        */
      IDRS_UINT GetPageIndex() const;
    private:
      /**
        * \brief Private use only
        */
      CDigitalSignatureData& TypedObject() const
      {
        return (CDigitalSignatureData&)Object();
      };
  };

  typedef TObjPtrArray<CDigitalSignature> CDigitalSignatureArray;

  /*
   *
   */
  inline CDigitalSignature::CDigitalSignature()
  {
  }
  /*
   *
   */
  inline CDigitalSignature::CDigitalSignature(const CDigitalSignature& argDigitalSignature)
    : CObjPtr((CObjPtr&)argDigitalSignature)
  {
  }
  /*
   *
   */
  inline CDigitalSignature::CDigitalSignature(CDigitalSignatureData* pObj)
    : CObjPtr((CObj*)pObj)
  {
  }
  /*
   *
   */
  inline CDigitalSignature::CDigitalSignature(CObj* pObj)
    : CObjPtr(pObj)
  {
  }
  /*
   *
   */
  inline CDigitalSignature::~CDigitalSignature()
  {
  }
} // namespace
#endif /* _cdigitalsignature_h_ */
