/**
 * \file CTextRecognition.h
 * \brief Interface for CTextRecognition class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _CTextRecognition_h_
#define _CTextRecognition_h_

#include "CObjPtr.h"
#include "COcrParams.h"
#include "IProgressPageProcessing.h"
#include "CPageContent.h"
#include "CIDRS.h"

namespace IDRS
{
  class CTextRecognitionData;
  class CImage;
  class CPage;
  /**
   * \brief CTextRecognition contains the text recognition features of iDRS SDK
   * 
   * This class allows the following operations:
   * - Set the ocr recognition parameters
   * - Set the ocr progress callback
   * - Recognize text and return the results
   */
  class IDRSKRN_API CTextRecognition : public CObjPtr
  {
  public:
    /**
     * \brief Default constructor.
     */
    inline CTextRecognition();
    /**
     * \brief Copy constructor.
     *
     * \param argCTextRecognition Object to copy.
     *
     * This method will initialize the newly created CTextRecognition is the data object from argCTextRecognition parameter.
     */
    inline CTextRecognition(const CTextRecognition& argCTextRecognition);
    /**
     * \brief Constructor that initializes the associated data object
     *
     * \param pargCTextRecognitionData Data object containing the state that will be used for the new CTextRecognition object
     */
    inline CTextRecognition(CObj* pargCTextRecognitionData);
    /**
     * \brief Destructor
     */
    inline virtual ~CTextRecognition();
    /**
     * \brief Creates a new instance of this class and associates the provided \see CIDRS handle to it.
     *
     * \param argIdrs CIDRS instance
     */
    static CTextRecognition Create(const CIDRS& argIdrs);
    /**
     * \brief Creates a new instance of this class and associates the provided \see CIDRS handle and ocr parameters
     *
     * \param argIdrs CIDRS instance
     * \param argOcrParams Object containing the ocr parameters
     */
    static CTextRecognition Create(const CIDRS& argIdrs, const COcrParams& argOcrParams);
    /**
     * \brief Gets the parameters used for the ocr (language(s), full page/zonal recognition, etc)
     *
     * By default, the ocr runs on full page with english language enabled
     *
     * \return Parameters used for ocr.
     */
    COcrParams GetOcrParams() const;
    /**
     * \brief Sets the parameters used for the ocr (language(s), full page/zonal recognition, etc)
     *
     * By default, the ocr runs on full page with english language enabled
     *
     * \param argOcrParams Parameters used for ocr.
     */
    void SetOcrParams(const COcrParams& argOcrParams);
    /**
     * \brief Gets the callback used to notify about text recognition progress.
     *
     * The callback mechanism also allows stopping the text recognition. See \see CProgressTextRecognition for more details
     *
     * By default, there's no callback defined for text recognition, so the returned value will be NULL
     *
     * \return Pointer to the current progress callback object.
     */
    IProgressPageProcessing* GetProgressCallback() const;
    /**
     * \brief Sets the callback used to notify about text recognition progress.
     *
     * The callback mechanism also allows stopping the text recognition. See \see CProgressTextRecognition for more details
     *
     * \param argpProgressCallback Pointer to the progress callback object to set.
     */
    void SetProgressCallback(IProgressPageProcessing* argpProgressCallback);
    /**
     * \brief Runs CProgressTextRecognition and returns the recognized text
     *
     * \param argImage Image on which text recognition will be run
     *
     * \return CPageContent object contained the recognized text split in words, lines, paragraphs, etc
     */
    CPageContent RecognizeText(const CImage& argImage) const;
    /**
     * \brief Runs CProgressTextRecognition and returns the recognized text
     *
     * \param argPage Page on which text recognition will be run. The page's content will be updated with the results of ocr
     */
    void RecognizeText(CPage& argPage) const;
  private:
    // For internal use only
    CTextRecognitionData& TypedObject() const
    {
      return (CTextRecognitionData&)Object();
    };

  };
	
  /*
   *
   */
  inline CTextRecognition::CTextRecognition()
  {
  }
  /*
   *
   */
  inline CTextRecognition::CTextRecognition(const CTextRecognition& argCTextRecognition)
    : CObjPtr((CObjPtr &)argCTextRecognition)
  {
  }
  /*
   *
   */
  inline CTextRecognition::CTextRecognition(CObj* pargCTextRecognitionData)
    : CObjPtr(pargCTextRecognitionData)
  {
  }
  /*
   *
   */
  inline CTextRecognition::~CTextRecognition()
  {
  }
}
#endif // _CTextRecognition_h_
