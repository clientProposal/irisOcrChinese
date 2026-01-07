/**
 * \file CIDRS.h
 * \brief Interface for the IDRS::CIDRS class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _cidrs_h_
#define _cidrs_h_
#include <CObjPtr.h>
#include <CIDRSLicense.h>
#include "ILogger.h"
namespace IDRS
{
  class CDocumentWriter;
  class CIDRSData;
  /**
   *
   */
  class IDRSKRN_API CIDRS : public CObjPtr
  {
    friend class CImage;
    friend class CPage;
    friend class CFastReader;
    friend class CDocumentWriter;
    public:
      /**
       *
       */
      inline CIDRS ();
      /**
       *
       */
      inline CIDRS ( const CIDRS & argBCode );
      /**
       *
       */
      inline CIDRS ( CIDRSData * pObj );
      /**
       *
       */
      inline virtual ~CIDRS();
      /**
       * \brief Create initializes the modules for which a valid license has been provided
       */
      static CIDRS Create ();
      /**
       * \brief SetLoggerCallback Sets the callback object used to log events.
       * The object used as a callback object will be called every time iDRS receives a message during an 
       * operation, of severity level equal or higher than the level provided by user.
       *
       * \remarks The logger callback class should inherit from ILogger interface
       *
       * \param plCallback The  callback object pointer
       * \param evLevel The severity level threshold for which calls to logger callback class should be performed.
       */
       void SetLoggerCallback ( ILogger * plCallback, const SeverityLevel evLevel );
    private:
      /**
       *
       */
      inline CIDRSData & TypedObject () const;
  };
  /*
   *
   */
  inline CIDRS::CIDRS ()
  {
  }
  /*
   *
   */
  inline CIDRS::CIDRS ( const CIDRS & otherIDRS )
    : CObjPtr (( CObjPtr & )otherIDRS )
  {
  }
  /*
   *
   */
  inline CIDRS::CIDRS ( CIDRSData * pObj )
    : CObjPtr (( CObj * )pObj )
  {
  }
  /*
   *
   */
  inline CIDRS::~CIDRS()
  {
  }
  /*
   *
   */
  inline CIDRSData & CIDRS::TypedObject () const
  {
    return ( CIDRSData & )Object ();
  }
} // namespace
#endif /* _cidrs_h_ */
