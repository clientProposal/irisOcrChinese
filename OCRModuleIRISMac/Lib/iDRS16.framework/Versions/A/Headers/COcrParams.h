/**
 * \file COcrParams.h
 * \brief Interface for COcrParams class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _COcrParams_h_
#define _COcrParams_h_

#include "CObjPtr.h"
#include "EnumDefinitions.h"

namespace IDRS
{
  class COcrParamsData;
  /**
   * \brief Base class for OCR parameters. 
   * 
   * The class offers the most common OCR parameters like threading model to use and the amount of work to spend while in the OCR process
   * 
   * \important This class is not supposed to be instantiated
   */
  class IDRSKRN_API COcrParams : public CObjPtr
  {
  public:
    /**
     * \brief Default constructor
     */
    inline COcrParams();
    /**
     * \brief Copy constructor
     */
    inline COcrParams(const COcrParams& argCOcrParams);
    /**
     * \brief Constructor that initializes the data class
     */
    inline COcrParams(CObj* pargCOcrParamsData);
    /**
     * \brief Destructor
     */
    inline virtual ~COcrParams();
    /**
     * \brief GetType returns the recognition type.
     *
     * This parameter is expected to be automatically set by the inheriting classes. 
     *
     * \return The recognition type used for this object
     */
    RecognitionType GetType() const;
    /**
     * \brief GetThreadingMode returns the threading model that should be used for OCR process
     *
     * Please see \see ThreadingMode for details about the available threading modes.
     * 
     * \return The threading model to be used
     * \remark Default value is set to ThreadingMode::None
     */
    ThreadingMode GetThreadingMode() const;
    /**
     * \brief SetThreadingMode sets a threading mode that should be used for the OCR process
     *
     * Please see \see ThreadingMode for details about the available threading modes.
     * 
     * \param evThreadingMode The threading model to be used
     */
    void SetThreadingMode(const ThreadingMode evThreadingMode);
    /**
     * \brief GetWorkdepth returns an indicator specifying how much time should the OCR process spend on recognition
     *
     * Please see \see Workdepth for details about the available work modes.
     * 
     * \return Enumerable specifying the OCR work depth 
     */
    Workdepth GetWorkdepth() const;
    /**
     * \brief SetWorkdepth sets the OCR work depth
     *
     * Please see \see Workdepth for details about the available work modes.
     *
     * \param evWorkdepth Enumerable specifying the OCR work depth 
     */
    void SetWorkdepth(const Workdepth evWorkdepth);
  private:
    // For internal use only
    COcrParamsData& TypedObject() const
    {
      return (COcrParamsData&)Object();
    };
  };
	
  /*
   *
   */
  inline COcrParams::COcrParams()
  {
  }
  /*
   *
   */
  inline COcrParams::COcrParams(const COcrParams& argCOcrParams)
    : CObjPtr((CObjPtr &)argCOcrParams)
  {
  }
  /*
   *
   */
  inline COcrParams::COcrParams(CObj* pargCOcrParamsData)
    : CObjPtr(pargCOcrParamsData)
  {
  }
  /*
   *
   */
  inline COcrParams::~COcrParams()
  {
  }
}
#endif // _COcrParams_h_
