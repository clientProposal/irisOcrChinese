/**
 * \file COcrPageParams.h
 * \brief Interface for COcrPageParams class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _COcrPageParams_h_
#define _COcrPageParams_h_

#include "CObjPtr.h"
#include "COcrParams.h"
#include "COcrContext.h"

namespace IDRS
{
  class COcrPageParamsData;
  /**
   * \brief COcrPageParams contains the configuration for the full page OCR text recognition.
   * 
   * This class allows setting the following text recognition options:
   * - OCR context - allows specifying options like languages to detect. See \see COcrContext for more details
   * - Compute background image
   * - Detect empty form fields
   */
  class IDRSKRN_API COcrPageParams : public COcrParams
  {
  public:
    /**
     * \brief Default constructor. 
     */
    inline COcrPageParams();
    /**
     * \brief Copy constructor. 
     * 
     * \param argCPageOcrParams Object to copy. 
     *
     * This method will initialize the newly created COcrPageParams with the data object from argCPageOcrParams parameter.
     */
    inline COcrPageParams(const COcrPageParams& argCPageOcrParams);
    /**
     * \brief Constructor that initializes the associated data object 
     * 
     * \param pargCPageOcrParamsData Data object containing the state that will be used for the new COcrPageParams object
     */
    inline COcrPageParams(CObj* pargCPageOcrParamsData);
    /**
     * \brief Destructor
     */
    inline virtual ~COcrPageParams();
    /**
     * \brief Creates a new instance of this class
     */
    static COcrPageParams Create();
    /**
     * \brief Creates a new instance of this class and sets the associated \see COcrContext
     *
     * \param argContext Ocr context to set
     *
     * By default the associated ocr context enables only English language
     */
    static COcrPageParams Create(const COcrContext& argContext);
    /**
     * \brief Gets the boolean flag that specifies if the background image should be extracted during text recognition process
     * 
     * The background image represents a variant of the original image where the detected text characters are removed.
     * iDRS SDK takes care of replacing the zones where the text has been removed with the appropriate colors.
     *
     * If set to IDRS_TRUE, the background image will be extracted and set into the \see CPage object provided as argument during text recognition.
     *
     * \return Boolean flag enabling/disabling background image extraction
     */
    IDRS_BOOL GetComputeBackgroundImage() const;
    /**
     * \brief Sets the boolean flag that specifies if the background image should be extracted during text recognition process
     * 
     * The background image represents a variant of the original image where the detected text characters are removed.
     * iDRS SDK takes care of replacing the zones where the text has been removed with the appropriate colors.
     *
     * If set to IDRS_TRUE, the background image will be extracted and set into the \see CPage object provided as argument during text recognition.
     *
     * \param bComputeBackgroundImage Boolean flag enabling/disabling background image extraction
     */
    void SetComputeBackgroundImage(const IDRS_BOOL bComputeBackgroundImage);
    /**
     * \brief Gets the boolean flag that specifies if empty form fields should be detected or not during text recognition
     * 
     * Default value is IDRS_FALSE
     * 
     * \return IDRS_TRUE to enable the empty forms detection, IDRS_FALSE otherwise.
     */
    IDRS_BOOL GetDetectEmptyFormFields() const;
    /**
     * \brief Set the boolean flag that enables or not the empty forms detection 
     *
     * \param bDetectEmptyFormFields IDRS_TRUE to enable the empty forms detection, IDRS_FALSE otherwise.
     */
    void SetDetectEmptyFormFields(const IDRS_BOOL bDetectEmptyFormFields);
    /**
     * \brief Gets the associated ocr context.
     * 
     * The ocr context allows specifying options like languages to detect. See \see COcrContext for more details
     *
     * \return Associated ocr context
     */
    COcrContext GetContext() const;
    /**
     * \brief Sets the associated ocr context.
     * 
     * The ocr context allows specifying options like languages to detect. See \see COcrContext for more details
     *
     * \param argContext Associated ocr context
     */
    void SetContext(const COcrContext& argContext);
    /**
    * \brief Gets the table detection mode
    *
    * \return Table detection mode
    */
    TableDetectionMode GetTableDetectionMode() const;
    /**
     * \brief Sets the table detection mode
     *
     * Setting this flag will change the way the ocr engine will interpret the layout of the page.
     * Please see \see TableDetectionMode for the different modes supported.
     */
    void SetTableDetectionMode(const TableDetectionMode evTableDetection);
  private:
    // For internal use only
    COcrPageParamsData& TypedObject() const
    {
      return (COcrPageParamsData&)Object();
    };
  };
	
  /*
   *
   */
  inline COcrPageParams::COcrPageParams()
  {
  }
  /*
   *
   */
  inline COcrPageParams::COcrPageParams(const COcrPageParams& argCPageOcrParams)
    : COcrParams((COcrParams&)argCPageOcrParams)
  {
  }
  /*
   *
   */
  inline COcrPageParams::COcrPageParams(CObj* pargCPageOcrParamsData)
    : COcrParams(pargCPageOcrParamsData)
  {
  }
  /*
   *
   */
  inline COcrPageParams::~COcrPageParams()
  {
  }
}
#endif // _COcrPageParams_h_
