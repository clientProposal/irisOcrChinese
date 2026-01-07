/**
 * \file CEpubOutputParams.h
 * \brief Interface for CEpubOutputParams class
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */

#ifndef _cepuboutputparams_h_
#define _cepuboutputparams_h_
#include <CObjPtr.h>
#include "COutputParams.h"

namespace IDRS
{
  class COutputParamsData;
  /**
   * \brief CEpubOutputParams class manages the parameters to create an Epub file
   */
  class IDRSKRN_API CEpubOutputParams : public COutputParams
  {
    public:
      /**
       * \brief Default constructor.
       */
      inline CEpubOutputParams();
      /**
       * \brief copy constructor.
       */
      inline CEpubOutputParams(const CEpubOutputParams& argEpubOutputParams);
      /**
       * \brief constructor from data object.
       */
      inline CEpubOutputParams(COutputParamsData* pObj);
      /**
       * \brief destructor.
       */
      inline virtual ~CEpubOutputParams();
      /**
       * \brief Create is instantiating a new instance of CEpubOutputParams and associated data object
       *
       * \return New instance of CEpubOutputParams
       */
      static CEpubOutputParams Create();
    private:
      /**
       * Internal use only
       */
      inline COutputParamsData& TypedObject() const;
  };
  /*
   *
   */
  inline CEpubOutputParams::CEpubOutputParams()
  {
  }
  /*
   *
   */
  inline CEpubOutputParams::CEpubOutputParams(const CEpubOutputParams& argEpubOutputParams)
    : COutputParams((COutputParams&)argEpubOutputParams)
  {
  }
  /*
   *
   */
  inline CEpubOutputParams::CEpubOutputParams(COutputParamsData* pObj)
    : COutputParams(pObj)
  {
  }
  /*
   *
   */
  inline CEpubOutputParams::~CEpubOutputParams()
  {
  }
  /*
   *
   */
  inline COutputParamsData& CEpubOutputParams::TypedObject() const
  {
    return (COutputParamsData&)Object();
  }
} // namespace
#endif // _cepuboutputparams_h_
