/**
 * \file CPageTextLine.h
 * \brief Interface for CPageTextLine class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _CPageTextLine_h_
#define _CPageTextLine_h_

#include "CPolygon.h"
#include "TObjPtrArray.h"
#include "CPageWord.h"
#include "CPageCustomData.h"

namespace IDRS
{
  class CPageTextLineData;

  /**
   * \brief CPageTextLine represents a line of text 
   */
  class IDRSKRN_API CPageTextLine : public CPageCustomData
  {
  public:
    /**
     * \brief Default constructor
     */
    inline CPageTextLine();
    /**
     * \brief Copy constructor
     *
     * \param argPageTextLine Object to copy (shallow copy)
     */
    inline CPageTextLine(const CPageTextLine& argPageTextLine);
    /**
     * \brief CPageTextLine constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageTextLine(CPageTextLineData * pObj);
    /**
     * \brief CPageTextLine constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageTextLine(CObj * pObj);
    /**
     * \brief Destructor
     */
    inline virtual ~CPageTextLine();
    /**
     * \brief Creates a new instance of CPageTextLine
     */
    static CPageTextLine Create();
    /**
     * \brief Get the polygon where the text line is located
     */
    CPolygon GetBoundingPolygon() const;
    /**
     * \brief Set the polygon where the text line is located
     *
     * \param argBoundingPolygon Polygon containing the text line
     */
    void SetBoundingPolygon(const CPolygon& argBoundingPolygon);
    /**
     * \brief Get the baseline for the text line
     */
    IDRS_INT GetBaseline() const;
    /**
     * \brief Set the baseline for the text line
     *
     * \param iBaseline Baseline value
     */
    void SetBaseline(const IDRS_INT iBaseline);
    /**
     * \brief GetWords retrieves the array of words in the line
     */
    CPageWordArray GetWords() const;
    /**
     * \brief Set the array containing the words in the line
     *
     * \param argxWords Array containing the words in the line
     */
    void SetWords(const CPageWordArray& argxWords);
  private:
    //! Internal use 
    CPageTextLineData & TypedObject() const
    {
      return (CPageTextLineData &)Object();
    };
  };

  typedef TObjPtrArray<CPageTextLine> CPageTextLineArray;

  /*
   *
   */
  inline CPageTextLine::CPageTextLine()
  {
  }
  /*
   *
   */
  inline CPageTextLine::CPageTextLine(const CPageTextLine& argPageTextLine)
    : CPageCustomData((CPageCustomData&)argPageTextLine)
  {
  }
  /*
   *
   */
  inline CPageTextLine::CPageTextLine(CPageTextLineData * pObj)
    : CPageCustomData((CPageCustomDataData*)pObj)
  {
  }
  /*
   *
   */
  inline CPageTextLine::CPageTextLine(CObj * pObj)
    : CPageCustomData(pObj)
  {
  }
  /*
   *
   */
  inline CPageTextLine::~CPageTextLine()
  {
  }
}
#endif // _CPageTextLine_h_
