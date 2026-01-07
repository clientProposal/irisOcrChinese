/**
 * \file ILogger.h
 * Declaration of the ILogger interface.
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */

#ifndef _ILogger_h_
#define _ILogger_h_

#include "idrskrn.h"
#include "EnumDefinitions.h"
namespace IDRS
{
  class idrs_string;
  /**
   * The ILogger abstract class describes an interface which can be used
   * by a custom class to provide a global logging system
   *
   * The global logging system can be used to provide to an IDRS SDK integrator
   * information and feedback about meaningfuls event
   *
   * The interface contains information about the level of severity of the events that are going to be logged.
   *
   */
  class IDRSKRN_API ILogger
  {
  public:
    //! Destructor
    inline virtual ~ILogger () = default;
    /**
     * \brief OnReceivedMessage is a method which will be called on reception of meaningful events
     * to provide information about the status and the type of the event. Function will provide information 
     * only to events that occur with a severity level equal or higher than the critical severity level provided by user
     *
     * \param evSeverityLevel The severity level of the events that will be logged
     * \param strMessage A message providing more information about the occurred event
     */
    virtual void OnReceivedMessage ( const SeverityLevel evSeverityLevel, const idrs_string& strMessage ) = 0;
  };
}
#endif /* _ILogger_h_ */
