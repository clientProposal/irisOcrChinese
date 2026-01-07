/**
 * \file CXmlOutputParams.h
 * \brief Interface for CXmlOutputParams class
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */

#ifndef _CXmlOutputParams_h_
#define _CXmlOutputParams_h_
#include <CObjPtr.h>
#include <COutputParams.h>
#include "EnumDefinitions.h"
namespace IDRS
{
  class COutputParamsData;
  /**
   * \brief CXmlOutputParams class manages the parameters to create an XML file
   */
  class IDRSKRN_API CXmlOutputParams : public COutputParams
  {
    public:
      /**
       * \brief Default constructor.
       */
      inline CXmlOutputParams();
      /**
       * \brief copy constructor.
       */
      inline CXmlOutputParams(const CXmlOutputParams& argXmlOutputParam);
      /**
       * \brief constructor from data object.
       */
      inline CXmlOutputParams(COutputParamsData* pObj);
      /**
       * \brief Default destructor.
       */
      inline virtual ~CXmlOutputParams();
      /**
       * \brief Create is instantiating a new instance of CXmlOutputParams and associated data object
       *
       * \param evXmlSchema The XML schema to use for output
       *
       * \return New instance of CXmlOutputParams
       */
      static CXmlOutputParams Create(const XmlSchema evXmlSchema);
      /**
       * \brief getter for the XML schema.
       *
       * \returns the XML schema
       */
      XmlSchema GetXmlSchema() const;
    private:
      /**
       * Internal use only
       */
      inline COutputParamsData& TypedObject() const;
  };
  /*
   *
   */
  inline CXmlOutputParams::CXmlOutputParams()
  {
  }
  /*
   *
   */
  inline CXmlOutputParams::CXmlOutputParams(const CXmlOutputParams& argXmlOutputParams)
    : COutputParams((COutputParams&)argXmlOutputParams)
  {
  }
  /*
   *
   */
  inline CXmlOutputParams::CXmlOutputParams(COutputParamsData* pObj)
    : COutputParams(pObj)
  {
  }
  /*
   *
   */
  inline CXmlOutputParams::~CXmlOutputParams()
  {
  }
  /*
   *
   */
  inline COutputParamsData& CXmlOutputParams::TypedObject() const
  {
    return (COutputParamsData&)Object();
  }
} // namespace
#endif // _CXmlOutputParams_h_
