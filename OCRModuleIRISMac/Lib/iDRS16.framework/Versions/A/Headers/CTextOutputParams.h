/**
 * \file CTextOutputParams.h
 * \brief Interface for CTextOutputParams class
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */

#ifndef _ctextoutputparams_h_
#define _ctextoutputparams_h_
#include <CObjPtr.h>
#include <COutputParams.h>
#include "EnumDefinitions.h"
namespace IDRS
{
  class COutputParamsData;
  /**
   * \brief CTextOutputParams class manages the parameters to create a text file
   */
  class IDRSKRN_API CTextOutputParams : public COutputParams
  {
    public:
      /**
       * \brief Default constructor.
       */
      inline CTextOutputParams();
      /**
       * \brief copy constructor.
       */
      inline CTextOutputParams(const CTextOutputParams& argTextOutputParam);
      /**
       * \brief constructor from data object.
       */
      inline CTextOutputParams(COutputParamsData* pObj);
      /**
       * \brief Default destructor.
       */
      inline virtual ~CTextOutputParams();
      /**
       * \brief Create is instantiating a new instance of CTextOutputParams and associated data object
       *
       * \param evCharacterEncoding character encoding value.
       *
       * \return New instance of CTextOutputParams
       */
      static CTextOutputParams Create(const CharacterEncoding evCharacterEncoding);
      /**
       * \brief getter for the character encoding.
       *
       * \returns the character encoding type.
       */
      CharacterEncoding GetCharacterEncoding() const;
    private:
      /**
       * Internal use only
       */
      inline COutputParamsData& TypedObject() const;
  };
  /*
   *
   */
  inline CTextOutputParams::CTextOutputParams()
  {
  }
  /*
   *
   */
  inline CTextOutputParams::CTextOutputParams(const CTextOutputParams& argTextOutputParams)
    : COutputParams((COutputParams&)argTextOutputParams)
  {
  }
  /*
   *
   */
  inline CTextOutputParams::CTextOutputParams(COutputParamsData* pObj)
    : COutputParams(pObj)
  {
  }
  /*
   *
   */
  inline CTextOutputParams::~CTextOutputParams()
  {
  }
  /*
   *
   */
  inline COutputParamsData& CTextOutputParams::TypedObject() const
  {
    return (COutputParamsData&)Object();
  }
} // namespace
#endif // _ctextoutputparams_h_
