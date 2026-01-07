/**
 * \file COutputParams.h
 * \brief Interface for COutputParams class
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */

#ifndef _coutputparams_h_
#define _coutputparams_h_
#include <CObjPtr.h>
#include "EnumDefinitions.h"
namespace IDRS
{
  class COutputParamsData;
  /**
   * \brief COutputParams class is the base class for different output classes
   */
  class IDRSKRN_API  COutputParams : public CObjPtr
  {
    friend class CIDRSObjectAccess;
    public:
      /**
       * \brief Default constructor.
       */
      inline COutputParams();
      /**
       * \brief copy constructor.
       */
      inline COutputParams(const COutputParams& argPageSizeOptions);
      /**
       * \brief constructor from data object.
       */
      inline COutputParams(COutputParamsData* pObj);
      /**
       * \brief destructor.
       */
      inline virtual ~COutputParams();
      /**
       * \brief gets the output format.
       *
       * \returns the output format
       */
      OutputFormat GetOutputFormat() const;
    private:
      /**
       * Internal use only
       */
      inline COutputParamsData& TypedObject() const;
  };
  /*
   *
   */
  inline COutputParams::COutputParams()
  {
  }
  /*
   *
   */
  inline COutputParams::COutputParams(const COutputParams& argOutputParams)
    : CObjPtr((CObjPtr&)argOutputParams)
  {
  }
  /*
   *
   */
  inline COutputParams::COutputParams(COutputParamsData* pObj)
    : CObjPtr((CObj*)pObj)
  {
  }
  /*
   *
   */
  inline COutputParams::~COutputParams()
  {
  }
  /*
   *
   */
  inline COutputParamsData& COutputParams::TypedObject() const
  {
    return (COutputParamsData&)Object();
  }
} // namespace
#endif //_coutputparams_h_
