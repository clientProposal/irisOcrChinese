/**
 * \file IProgressPageProcessing.h
 * \brief Interface for IProgressPageProcessing class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _IProgressPageProcessing_h_
#define _IProgressPageProcessing_h_
#include <CObj.h>

namespace IDRS
{  
  /**
   * \brief CProgressTextRecognition defines the interface required to monitor page processing progress.
   */
  class IDRSKRN_API IProgressPageProcessing
  {
    public:
      //! Destructor
      inline virtual ~IProgressPageProcessing() = default;
      /**
       * \brief OnPercentageUpdate must be overridden to monitor the processing progress.
       *
       * \param uiPercent The current progress, from 0 to 100.
       */
      virtual void OnPercentageUpdate ( const IDRS_UINT uiPercent ) = 0;
      /**
       * \brief GetAbortFlag can be overridden so the current process will be stopped if returning IDRS_TRUE.
       *
       * \return IDRS_TRUE to abort, IDRS_FALSE to continue
       */
      virtual IDRS_BOOL GetAbortFlag () = 0;
  };
}
#endif // _IProgressPageProcessing_h_
