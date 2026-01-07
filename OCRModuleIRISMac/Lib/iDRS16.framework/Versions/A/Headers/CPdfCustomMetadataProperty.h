/**
 * \file CPdfCustomMetadataProperty.h
 * \brief Interface for IDRS::CPdfCustomMetadataProperty class
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */

#ifndef _CPdfCustomMetadataProperty_h_
#define _CPdfCustomMetadataProperty_h_

#include <CObjPtr.h>

namespace IDRS
{
  class CPdfCustomMetadataPropertyData;
  class idrs_string;
  /**
    * \brief CPdfCustomMetadataProperty represents a PDF metadata property composed of a name/value pair.
    */
  class IDRSKRN_API CPdfCustomMetadataProperty : public CObjPtr
  {
  public:
      /**
      * \brief Default constructor.
      */
    inline CPdfCustomMetadataProperty();
    /**
      * \brief Copy constructor.
      *
      * \param argPdfCustomMetadataProperty The smart pointer to copy.
      */
    inline CPdfCustomMetadataProperty( const CPdfCustomMetadataProperty & argPdfCustomMetadataProperty );
    /**
      * \brief Constructor.
      *
      * \param pPdfCustomMetadataPropertyData The object to point to. 
      */
    inline CPdfCustomMetadataProperty( CPdfCustomMetadataPropertyData * pPdfCustomMetadataPropertyData);
    /**
      * \brief Destructor
      */
    virtual inline ~CPdfCustomMetadataProperty();
    /**
      * \brief Create Creates a CPdfCustomMetadataProperty object.
      *
      * \throw CIDRSException if an error occurs.
      *
      * \param strPropertyName The name of the custom metadata property tag
      * \param strPropertyValue The value of the custom metadata property
      */
    static CPdfCustomMetadataProperty Create(const idrs_string& strPropertyName, const idrs_string& strPropertyValue );
    /**
      * \brief Sets the name of the metadata property tag.
      *
      * \param strPropertyName The tag name
      */
    void SetPropertyName(const idrs_string& strPropertyName );
    /**
      * \brief Sets the value of the metadata property.
      *
      * \param strPropertyValue The property value
      */
    void SetPropertyValue(const idrs_string& strPropertyValue );
    /**
      * \brief Gets the name of the metadata property.
      * 
      * \return Property name
      */
    const idrs_string& GetPropertyName() const;
    /**
      * \brief Gets the value of the metadata property.
      *
      * \return Property value
      */
    const idrs_string& GetPropertyValue() const;
  private:
    // For internal use only
    CPdfCustomMetadataPropertyData & TypedObject() const
    {
      return ( CPdfCustomMetadataPropertyData & ) Object();
    }
  };
  /*
   *
   */
  inline CPdfCustomMetadataProperty::CPdfCustomMetadataProperty()
  {
  }
  /*
   *
   */
  inline CPdfCustomMetadataProperty::CPdfCustomMetadataProperty(const CPdfCustomMetadataProperty & argCustomMetadataProperty)
    : CObjPtr((CObjPtr &)argCustomMetadataProperty)
  {
  }
  /*
   *
   */
  inline CPdfCustomMetadataProperty::CPdfCustomMetadataProperty(CPdfCustomMetadataPropertyData * pPdfCustomMetadataPropertyData)
    : CObjPtr((CObj *)pPdfCustomMetadataPropertyData)
  {
  }
  /*
   *
   */
  inline CPdfCustomMetadataProperty::~CPdfCustomMetadataProperty()
  {
  }
}
#endif // _CPdfCustomMetadataProperty_h_
