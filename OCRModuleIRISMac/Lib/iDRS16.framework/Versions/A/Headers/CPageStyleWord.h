/**
 * \file CPageStyleWord.h
 * \brief Interface for CPageStyleWord class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _CPageStyleWord_h_
#define _CPageStyleWord_h_

#include "CObjPtr.h"
#include "TObjPtrArray.h"
#include "CPageStyleTabulation.h"

namespace IDRS
{
  class CPageStyleWordData;

  /**
   * \brief CPageStyleWord represents a text word style 
   */
  class IDRSKRN_API CPageStyleWord : public CObjPtr
  {
  public:
    /**
     * \brief Default constructor
     */
    inline CPageStyleWord();
    /**
     * \brief Copy constructor
     *
     * \param argPageStyleWord Object to copy (shallow copy)
     */
    inline CPageStyleWord(const CPageStyleWord& argPageStyleWord);
    /**
     * \brief CPageStyleWord constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CPageStyleWord(CPageStyleWordData * pObj);
    /**
     * \brief Destructor
     */
    inline virtual ~CPageStyleWord();
    /**
     * \brief Creates a new instance of CPageStyleWord 
     */
    static CPageStyleWord Create();
    /**
     * \brief Gets the list with tabulation styles.
     *
     * \return a list with the tabulation styles.
     */
    CPageStyleTabulationArray GetPageStyleTabulations() const;
    /**
     * \brief Sets the list of tabulation styles.
     *
     * \param xPageStyleTabulation array containing the tabulation styles
     */
    void SetPageStyleTabulations(const CPageStyleTabulationArray& xPageStyleTabulation);
  private:
    //! Internal use 
    CPageStyleWordData & TypedObject() const
    {
      return (CPageStyleWordData &)Object();
    };
  };

  /*
   *
   */
  inline CPageStyleWord::CPageStyleWord()
  {
  }
  /*
   *
   */
  inline CPageStyleWord::CPageStyleWord(const CPageStyleWord& argPageStyleWord)
    : CObjPtr((CObjPtr &)argPageStyleWord)
  {
  }
  /*
   *
   */
  inline CPageStyleWord::CPageStyleWord(CPageStyleWordData * pObj)
    : CObjPtr((CObj *)pObj)
  {
  }
  /*
   *
   */
  inline CPageStyleWord::~CPageStyleWord()
  {
  }
}
#endif // _CPageStyleWord_h_
