/**
 * \file CConsoleLogger.h
 * Implementation of the CConsoleLogger class.
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */

#ifndef _CConsoleLogger_h_
#define _CConsoleLogger_h_

#include <CObjPtr.h>
#include "ILogger.h"

namespace IDRS
{
  class CConsoleLoggerData;
  /**
   * The CConsoleLogger class is an iDRS implementation of the ILogger interface.
   * It exposes a default iDRS Logger that can be used to log messages during an operation.
   *
   * This class will print log messages in console.
   *
   * Log entries are expressed by this class as per the following pattern: YYYY-MM-DD hh:mm:ss [severity level] [message]
   * - First part is a timestamp of a current date time
   * - Second part is the severity level of the message
   * - Third part is the message itself.
   *
   */
  class IDRSKRN_API CConsoleLogger : public ILogger, public CObjPtr
  {
    public :
    /**
     * \brief Default Constructor
     */
    inline CConsoleLogger ();
    /**
     * \brief Copy constructor
     *
     * \param argConsoleLogger The smart pointer to copy
     */
    inline CConsoleLogger ( const CConsoleLogger & argConsoleLogger );
    /**
     * \brief Constructor
     *
     * \param pConsoleLoggerData The object to point to
     */
    inline CConsoleLogger ( CConsoleLoggerData * pConsoleLoggerData );
    /**
     * \brief Destructor
     */
    inline virtual ~CConsoleLogger ();
    /**
     * \brief Creates an object
     *
     * \throw CIDRSException if an error occur.
     */
    static CConsoleLogger Create ();
    /**
     * \brief OnReceivedMessage is a method which will be called on reception of meaningful events
     * to provide information about the status and the type of the event. Function will provide 
     * information only to events that occur with a severity level equal or higher than the logging 
     * severity level provided by user. This function appends the timestamp and the message severity 
     * level overhead to the output string and then prints it to console
     *
     * \param evMessageSeverityLevel The severity level of the message that will be logged
     * \param strMessage A message providing more information about the occurred event
     */
    virtual void OnReceivedMessage ( const SeverityLevel evMessageSeverityLevel, const idrs_string& strMessage );
  private:
    // For Internal use only
    CConsoleLoggerData & TypedObject () const
    {
      return ( CConsoleLoggerData & )Object ();
    }
  };
  /*
   *
   */
  inline CConsoleLogger::CConsoleLogger ()
  {
  }
  /*
   *
   */
  inline CConsoleLogger::CConsoleLogger ( const CConsoleLogger & argConsoleLogger )
  : CObjPtr (( CObjPtr & )argConsoleLogger )
  {
  }
  /*
   *
   */
  inline CConsoleLogger::CConsoleLogger ( CConsoleLoggerData * pConsoleLoggerData )
  : CObjPtr (( CObj * ) pConsoleLoggerData )
  {
  }
  /*
   *
   */
  inline CConsoleLogger::~CConsoleLogger ()
  {
  }
}
#endif /* _CConsoleLogger_h_ */
