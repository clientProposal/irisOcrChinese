/**
 * \file CPageSizeOptions.h
 * \brief Interface for CPageSizeOptions class
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */

#ifndef _CPageSizeOptions_h_
#define _CPageSizeOptions_h_
#include <CObjPtr.h>
#include <idrs.h>
#include "EnumDefinitions.h"
namespace IDRS
{
  class CPageSizeOptionsData;
  /**
   * \brief CPageSizeOptions class specifies the page size options
   */
  class IDRSKRN_API CPageSizeOptions : public CObjPtr
  {
    public:
      /**
       * \brief Default constructor.
       */
      inline CPageSizeOptions();
      /**
       * \brief copy constructor.
       */
      inline CPageSizeOptions(const CPageSizeOptions& argPageSizeOptions);
      /**
       * \brief constructor from data object.
       */
      inline CPageSizeOptions(CPageSizeOptionsData* pObj);
      /**
       * \brief destructor.
       */
      inline virtual ~CPageSizeOptions();
      /**
       * \brief Create is instantiating a new instance of CPageSizeOptions and associated data object
       * 
       * \note by default we enable A4, A3, Letter and Legal all of them on both orientation (portrait & landscape)
       *
       * \return New instance of CPageSizeOptions
       */
      static CPageSizeOptions Create();
      /**
       * \brief enables/disables a given page size for a given orientation.
       *
       * \param evPageSize page size type to enable/disable
       * \param evPageOrientation page orientation type to enable/disable
       * \param bEnable boolean specifying the status
       *
       * \remarks If all sizes and orientations are disabled, iDRS will search for the closest fitting page size;
       * and if none are close enough, in that case the page size will be set to custom dimensions fitting exactly the input.
       */
      void EnablePageSize(const PageSize evPageSize, const PaperOrientation evPageOrientation, const IDRS_BOOL bEnable);
      /**
       * \brief checks if a given page size is enabled.
       *
       * \param evPageSize page size type
       * \param evPageOrientation page orienation type
       *
       * \returns IDRS_TRUE if enabled, otherwise IDRS_FALSE
       */
      IDRS_BOOL IsPageSizeEnabled(const PageSize evPageSize, const PaperOrientation evPageOrientation) const;
  private:
    /**
     * Internal use only
     */
    inline CPageSizeOptionsData& TypedObject() const;
  };
  /*
   *
   */
  inline CPageSizeOptions::CPageSizeOptions()
  {
  }
  /*
   *
   */
  inline CPageSizeOptions::CPageSizeOptions(const CPageSizeOptions& argPageSizeOptions)
    : CObjPtr((CObjPtr&)argPageSizeOptions)
  {
  }
  /*
   *
   */
  inline CPageSizeOptions::CPageSizeOptions(CPageSizeOptionsData* pObj)
    : CObjPtr((CObj*)pObj)
  {
  }
  /*
   *
   */
  inline CPageSizeOptions::~CPageSizeOptions()
  {
  }
  /*
   *
   */
  inline CPageSizeOptionsData& CPageSizeOptions::TypedObject() const
  {
    return (CPageSizeOptionsData&)Object();
  }
} // namespace
#endif //_CPageSizeOptions_h_
