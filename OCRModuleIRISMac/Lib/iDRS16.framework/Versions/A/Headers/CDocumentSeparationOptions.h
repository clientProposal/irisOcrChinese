/**
 * \file CDocumentSeparationOptions.h
 * \brief Interface for CDocumentSeparationOptions class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _CDocumentSeparationOptions_h_
#define _CDocumentSeparationOptions_h_
 
#include "CObjPtr.h"

namespace IDRS
{
  class CDocumentSeparationOptionsData;
  class IDocumentSeparationCallback;

  /**
   * \brief CDocumentSeparationOptions class is used to specify the document separation rules
   *
   * The class allows splitting documents based on rules defined in iDRS.
   * The separation can be either done by size or user defined by means of a custom callback.
   */
  class IDRSKRN_API CDocumentSeparationOptions : public CObjPtr
  {
  public:
    /**
     * \brief CDocumentSeparationOptions default constructor
     *
     * The default split is set to \see DocumentSplitTypeNone. This means that no splitting is activated by default
     */
    inline CDocumentSeparationOptions();
    /**
     * \brief CDocumentSeparationOptions copy constructor
     *
     * \param argOther Object to copy data from
     */
    inline CDocumentSeparationOptions(const CDocumentSeparationOptions & argOther);
    /**
     * \brief CDocumentSeparationOptions constructor used to copy the internal object
     *
     * \param pObj Data object to copy
     */
    inline CDocumentSeparationOptions( CDocumentSeparationOptionsData* pObj);
    /**
     * \brief Create is instantiating a new instance of CDocumentSeparationOptions and associated data object.
     *
     * The separation properties are initially unset, therefore the document separation will be disabled by default.
     *
     * \return New instance of CDocumentSeparationOptions 
     */
    static CDocumentSeparationOptions Create();
    /**
     * \brief Sets the MaxDocumentSize property, which defines the size threshold for the created document(s).
     *
     * Any document created with iDRS SDK is expected to have the size in bytes lower than the threshold value of this property.
     *
     * Setting 0 as the threshold value will disable the separation of documents by size
     *
     * \param uiMaxDocumentSize Threshold value for the document size (in bytes)
     * 
     * \note This property and the MaxDocumentSize are both mutually exclusive; assigning a value to one of them will reset the other.
     */
    void SetMaxDocumentSize( const IDRS_UINT64 uiMaxDocumentSize );
    /**
     * \brief Gets the MaxDocumentSize property value
     *
     * \return The threshold value for document size (in bytes)
     */
    IDRS_UINT64 GetMaxDocumentSize() const;
    /**
     * \brief Sets the document separation callback which allows using an integrator defined custom function.
     *
     * See \see IDocumentSeparationCallback class for more details about expected custom callback method.
     *
     * \param argpDocumentSeparationCallback Integrator custom callback object that decides whether iDRS SDK should trigger a document separation or not.
     * 
     * \note This property and the MaxDocumentSize are both mutually exclusive; assigning a value to one of them will reset the other.
     */
    void SetDocumentSeparationCallback( IDocumentSeparationCallback* argpDocumentSeparationCallback);
    /**
     * \brief GetOutputProgressCallback gets the document separation callback property.       
     *
     * \return The callback pointer
     */
    IDocumentSeparationCallback* GetDocumentSeparationCallback() const;

  private:
    /**
     * Internal use only
     */
    inline CDocumentSeparationOptionsData & TypedObject () const;
  };
  /*
   *
   */
  inline CDocumentSeparationOptions::CDocumentSeparationOptions()
  {
  }
  /*
   *
   */
  inline CDocumentSeparationOptions::CDocumentSeparationOptions(const CDocumentSeparationOptions & argOther)
    : CObjPtr((CObjPtr&)argOther)
  {
  }
  /*
   *
   */
  inline CDocumentSeparationOptions::CDocumentSeparationOptions( CDocumentSeparationOptionsData* pObj)
    : CObjPtr((CObj*)pObj)
  {
  }
  /*
   *
   */
  inline CDocumentSeparationOptionsData &CDocumentSeparationOptions::TypedObject () const
  {
    return (CDocumentSeparationOptionsData&)Object();
  }
}
 
#endif // _CDocumentSeparationOptions_h_
