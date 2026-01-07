/**
 * \file CIDRSException.h
 * \brief Interface for the IDRS::CIDRSException class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _cidrsexception_h_
#define _cidrsexception_h_
#include <idrskrn.h>
namespace IDRS
{
  /**
   * \brief CIDRSException is the base class for all iDRS exceptions.
   * \ingroup module_core
   *
   * A CIDRSException is localized in the source file by the name of the file and the line number.
   *
   * The exception type is identified by the associated error code.
   *
   */
  class IDRSKRN_API CIDRSException
  {
    public:
      /**
       * Constructs a CIDRSException object.
       *
       */
      CIDRSException ();
      /**
       * Constructs a CIDRSException object and initializes members with the parameters.
       *
       * \pre strlen ( strSrcFile ) < IDRS_MAX_PATH
       *
       * \param strSrcFile The path of the source file that is creating the exception.
       * \param uiSrcLine The number of the source line.
       * \param error The error code.
       *
       */
      CIDRSException ( const char strSrcFile[], const IDRS_UINT uiSrcLine, const IDRS_ERROR error);
      /**
       * Constructs a CIDRSException object and initializes members with the parameters.
       *
       * \pre strlen ( strSrcFile ) < IDRS_MAX_PATH
       *
       * \param argIDRSExceptionInner Reference to the inner exception object
       * \param strSrcFile The path of the source file that is creating the exception.
       * \param uiSrcLine The number of the source line.
       * \param error The error code.
       *
       */
      CIDRSException ( const CIDRSException & argIDRSExceptionInner, const char strSrcFile[], const IDRS_UINT uiSrcLine, const IDRS_ERROR error);
      /**
       * Constructs a copy of the given exception.
       *
       * \param toCopy The exception to copy.
       *
       */
      CIDRSException ( const CIDRSException & toCopy );
      /**
       * Destructor.
       *
       */
      virtual ~CIDRSException ();
      /**
       * Assignement operator.
       *
       * \param argIDRSExceptionToAssign The exception to copy
       */
      CIDRSException & operator = ( const CIDRSException & argIDRSExceptionToAssign );
      /**
       * The source code file path.
       */
      char m_strSrcFile [ IDRS_MAX_PATH ];
      /**
       * The source code line.
       */
      IDRS_UINT m_uiSrcLine;
      /**
       * The error code.
       */
      IDRS_ERROR m_code;
      /**
       * \return A pointer to the inner exception, NULL if there's no inner exception.
       */
      const CIDRSException * GetInnerException () const;
    private:
      /**
       * Inner exception pointer
       */
      const CIDRSException * m_pobjIDRSExceptionInner;
  };
} // namespace
/**
 * Macro to easily create and throw an exception.
 *
 */
#define ThrowException( idrs_error ) throw IDRS::CIDRSException ( IDRS_FILE_NAME, __LINE__, idrs_error )
#define ReThrowException( idrs_error, current_exception ) throw IDRS::CIDRSException ( current_exception, IDRS_FILE_NAME, __LINE__, idrs_error )
#ifndef IDRSKRN_DISABLE_ASSERT
/**
 * Assertion macro.
 *
 */
#define IDRS_ASSERT( x )  if ( ! ( x )) \
    throw IDRS::CIDRSException ( IDRS_FILE_NAME, __LINE__, IDRS_ERROR_FAILURE )
#else /* IDRSKRN_DISABLE_ASSERT */
#define IDRS_ASSERT( x ) //
#endif /* IDRSKRN_DISABLE_ASSERT */

#ifndef IDRSKRN_DISABLE_ASSERT
/**
 * Assertion macro.
 *
 */
#define IDRS_ASSERT_WITH_ERROR( x, err )  if ( ! ( x )) \
    throw IDRS::CIDRSException ( IDRS_FILE_NAME, __LINE__, err )
#else /* IDRSKRN_DISABLE_ASSERT */
#define IDRS_ASSERT_WITH_ERROR( x, err ) //
#endif /* IDRSKRN_DISABLE_ASSERT */

#ifdef IDRSKRN_ENABLE_DEBUG_ASSERT
/**
 * Assertion macro.
 *
 */
#define IDRS_DEBUG_ASSERT( x ) if ( ! ( x )) \
    throw IDRS::CIDRSException ( IDRS_FILE_NAME, __LINE__, IDRS_ERROR_FAILURE )
#else /* IDRSKRN_ENABLE_DEBUG_ASSERT */
#define IDRS_DEBUG_ASSERT( x ) //
#endif /* IDRSKRN_ENABLE_DEBUG_ASSERT */
#ifndef IDRSKRN_DISABLE_ASSERT
/**
 * Verification macro.
 *
 */
#define IDRS_VERIFY( x ) if ( ! ( x )) \
    throw IDRS::CIDRSException ( IDRS_FILE_NAME, __LINE__, IDRS_ERROR_FAILURE )
#else /* IDRSKRN_DISABLE_ASSERT */
#define IDRS_VERIFY( x ) ( x )
#endif /* IDRSKRN_DISABLE_ASSERT */
/**
 * Verification macro on arguments.
 */
#define IDRS_VERIFY_ARGS( x ) if ( ! ( x )) \
    throw IDRS::CIDRSException ( IDRS_FILE_NAME, __LINE__, IDRS_ERROR_INVALID_ARGS )
/**
 * Verification macro on call validity.
 */
#define IDRS_VERIFY_CALL( x ) if ( ! ( x )) \
    throw IDRS::CIDRSException ( IDRS_FILE_NAME, __LINE__, IDRS_ERROR_INVALID_CALL )
/**
 * Verification macro on buffer size.
 */
#define IDRS_VERIFY_BUFFER_SIZE( x ) if ( ! ( x )) \
    throw IDRS::CIDRSException ( IDRS_FILE_NAME, __LINE__, IDRS_ERROR_BUFFER_TOO_SMALL )
#endif /* _cidrsexception_h_ */
