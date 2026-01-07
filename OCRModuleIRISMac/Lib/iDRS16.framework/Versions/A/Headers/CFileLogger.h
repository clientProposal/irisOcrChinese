/**
 * \file CFileLogger.h
 * Interface of the CFileLogger class.
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _CFileLogger_h_
#define _CFileLogger_h_

#include <CObjPtr.h>
#include "ILogger.h"

namespace IDRS
{
  class CFileLoggerData;
  /**
   * The CFileLogger class is an iDRS implementation of the ILogger interface.
   * It exposes a default iDRS Logger that can be used to log messages during an operation.
   *
   * This class will write log messages to a file on disk. 
   * Note that each instance of CFileLogger must use a unique file. Having several loggers
   * using the same file results in undefined behavior.
   *
   * Log entries are expressed by this class as per the following pattern: YYYY-MM-DD hh:mm:ss [severity level] [message]
   * - First part is a timestamp of a current date time
   * - Second part is the severity level of the message
   * - Third part is the message itself.
   * 
   */
  class IDRSKRN_API CFileLogger : public ILogger, public CObjPtr
  {
  public :
    /**
     * \brief Default Constructor
     */
    inline CFileLogger ();
    /**
     * \brief Copy constructor
     *
     * \param argFileLogger The smart pointer to copy
     */
    inline CFileLogger ( const CFileLogger & argFileLogger );
    /**
     * \brief Constructor
     *
     * \param pFileLoggerData The object to point to
     */
    inline CFileLogger ( CFileLoggerData * pFileLoggerData );
    /**
     * \brief Destructor
     */
    inline virtual ~CFileLogger ();
    /**
     * \brief Creates an object with the given characteristics
     *
     * \pre strFilePath != NULL
     *
     * \param strFilePath The path of the file that will save the logger messages
     */
    static CFileLogger Create ( const idrs_string &strFilePath );
    /**
     * \brief OnReceivedMessage is a method which will be called on reception of meaningful events
     * to provide information about the status and the type of the event. Function will provide 
     * information only to events that occur with a severity level equal or higher than the logging 
     * severity level provided by user. This function appends the timestamp and the message severity 
     * level overhead to the received string and then stores it to a file on disk
     *
     * \param evMessageSeverityLevel The severity level of the message that will be logged
     * \param strMessage A message providing information about the occurred event
     */
    virtual void OnReceivedMessage ( const SeverityLevel evMessageSeverityLevel, const idrs_string& strMessage );
  private:
    // For Internal use only
    CFileLoggerData & TypedObject () const
    {
      return ( CFileLoggerData & )Object ();
    }
  };
  /*
   *
   */
  inline CFileLogger::CFileLogger ()
  {
  }
  /*
   *
   */
  inline CFileLogger::CFileLogger ( const CFileLogger & argFileLogger )
  : CObjPtr (( CObjPtr & )argFileLogger )
  {
  }
  /*
   *
   */
  inline CFileLogger::CFileLogger ( CFileLoggerData * pFileLoggerData )
  : CObjPtr (( CObj * ) pFileLoggerData )
  {
  }
  /*
   *
   */
  inline CFileLogger::~CFileLogger ()
  {
  }
}
#endif /* _CFileLogger_h_ */
