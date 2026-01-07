/**
 * \file CMetadataInfo.h
 * \brief Interface for CMetadataInfo class
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */

#ifndef _CMetadataInfo_h_
#define _CMetadataInfo_h_
#include <CObjPtr.h>
#include <idrs.h>
namespace IDRS
{
  class CMetadataInfoData;
  class idrs_string;
  /**
   * \brief CMetadataInfo class is used to contain a document metadata
   *
   * The properties in this class are written to the output document if they are available for the given format, in other words
   * each format has a specific set of supported metadata as shown in the table below:
   *
   *<table>
   *<tr><th>     <th>Author <th>Category <th>Comment <th>Company <th>CreationTime <th>Creator <th>Description <th>Keywords <th>Manager <th>Producer <th>Subject <th>Title
   *<tr><th>Docx <td><center>*</center> <td> <td> <td> <td><center>*</center> <td> <td><center>*</center> <td><center>*</center> <td> <td> <td><center>*</center> <td><center>*</center>
   *<tr><th>Epub <td> <td> <td> <td> <td> <td> <td> <td> <td> <td> <td> <td><center>*</center>
   *<tr><th>Html <td><center>*</center> <td><center>*</center> <td><center>*</center> <td><center>*</center> <td><center>*</center> <td><center>*</center> <td><center>*</center> <td><center>*</center> <td><center>*</center> <td><center>*</center> <td><center>*</center> <td><center>*</center>
   *<tr><th>Odt  <td> <td><center>*</center> <td><center>*</center> <td><center>*</center> <td><center>*</center> <td><center>*</center> <td><center>*</center> <td><center>*</center> <td><center>*</center> <td><center>*</center> <td><center>*</center> <td><center>*</center>
   *<tr><th>Pdf  <td><center>*</center> <td> <td> <td> <td><center>*</center> <td><center>*</center> <td> <td><center>*</center> <td> <td><center>*</center> <td><center>*</center> <td><center>*</center>
   *<tr><th>Pptx <td><center>*</center> <td><center>*</center> <td> <td><center>*</center> <td><center>*</center> <td> <td><center>*</center> <td><center>*</center> <td><center>*</center> <td> <td><center>*</center> <td><center>*</center>
   *<tr><th>Rtf  <td><center>*</center> <td><center>*</center> <td><center>*</center> <td><center>*</center> <td><center>*</center> <td> <td> <td><center>*</center> <td><center>*</center> <td> <td><center>*</center> <td><center>*</center>
   *<tr><th>Xlsx <td><center>*</center> <td><center>*</center> <td> <td><center>*</center> <td><center>*</center> <td> <td><center>*</center> <td><center>*</center> <td><center>*</center> <td> <td><center>*</center> <td><center>*</center>
   *</table>
   *
   */
  class IDRSKRN_API CMetadataInfo : public CObjPtr
  {
    public:
      /**
       * \brief Default constructor.
       */
      inline CMetadataInfo();
      /**
       * \brief copy constructor.
       */
      inline CMetadataInfo(const CMetadataInfo& argMetadataInfo);
      /**
       * \brief constructor from data object.
       */
      inline CMetadataInfo(CMetadataInfoData* pObj);
      /**
       * \brief destructor.
       */
      inline virtual ~CMetadataInfo();
      /**
       * \brief Create is instantiating a new instance of CMetadataInfo and associated data object
       *
       * \return New instance of CMetadataInfo
       */
      static CMetadataInfo Create();
      /**
       * \brief Sets the document title.
       *
       * \param strTitle The title value
       */
      void SetTitle( const idrs_string& strTitle );
      /**
       * \brief Gets the document title.
       *
       * \return The document title value.
       */
      const idrs_string& GetTitle( ) const;
      /**
       * \brief Sets the author of the document.
       *
       * \param strAuthor The author value
       */
      void SetAuthor(const idrs_string& strAuthor );
      /**
       * \brief Gets the author of the document.
       *
       * \return The document author value.
       */
      const idrs_string& GetAuthor( ) const;
      /**
       * \brief Sets the subject of the document.
       *
       * \param strSubject The subject value
       */
      void SetSubject(const idrs_string& strSubject );
      /**
       * \brief Gets the subject of the document.
       *
       * \return The document subject value.
       */
      const idrs_string& GetSubject( ) const;
      /**
       * \brief Sets the document keywords.
       *
       * \param strKeywords The keywords values
       */
      void SetKeywords(const idrs_string& strKeywords );
      /**
       * \brief Gets the document keywords.
       *
       * \return The document keywords value.
       */
      const idrs_string& GetKeywords( ) const;
      /**
       * \brief Sets the creator of the document.
       *
       * \param strCreator The creator name value
       */
      void SetCreator(const idrs_string& strCreator );
      /**
       * \brief Gets the creator of the document.
       *
       * \return The document creator value.
       */
      const idrs_string& GetCreator( ) const;
      /**
       * \brief Sets the producer of the document.
       *
       * \param strProducer The producer value
       */
      void SetProducer(const idrs_string& strProducer );
      /**
       * \brief Gets the procudcer of the document.
       *
       * \return The document producer value.
       */
      const idrs_string& GetProducer( ) const;
      /**
       * \brief Sets the company name.
       *
       * \param strCompany The company name
       */
      void SetCompany(const idrs_string& strCompany );
      /**
       * \brief Gets the company name.
       *
       * \return The company name.
       */
      const idrs_string& GetCompany( ) const;
      /**
       * \brief Sets the manager name.
       *
       * \param strManager The manager name
       */
      void SetManager(const idrs_string& strManager );
      /**
       * \brief Gets the manager name.
       *
       * \return The manager name.
       */
      const idrs_string& GetManager( ) const;
      /**
       * \brief Sets the category of the document.
       *
       * \param strCategory The category value
       */
      void SetCategory(const idrs_string& strCategory );
      /**
       * \brief Gets the category of the document.
       *
       * \return The category value.
       */
      const idrs_string& GetCategory( ) const;
      /**
       * \brief Sets the comments of the document.
       *
       * \param strComment The comments value
       */
      void SetComment(const idrs_string& strComment );
      /**
       * \brief Gets the comments of the document.
       *
       * \return The comments value.
       */
      const idrs_string& GetComment( ) const;
      /**
       * \brief Sets the description of the document.
       *
       * \param strDescription The comments value
       */
      void SetDescription(const idrs_string& strDescription );
      /**
       * \brief Gets the description of the document.
       *
       * \return The description value.
       */
      const idrs_string& GetDescription( ) const;
      /**
       * \brief Sets the creation time of the document.
       *
       * \param strCreationTime The creation time
       * 
       * \note The creation time must be expressed in the ISO format YYYY-MM-DDThh:mm:ssTZD (e.g. 2017-09-23T19:20:30+02:00).
       *  However keyword "Z" will not be accepted as a valid time zone definition; use +00:00 instead. If the given format is invalid,
       *  an IDRS_ERROR_INVALID_ARGS exception will be thrown.
       */
      void SetCreationTime(const idrs_string& strCreationTime );
      /**
       * \brief Gets the creation time of the document.
       *
       * \return The creation time value.
       */
      const idrs_string& GetCreationTime( ) const;

    private:
      /**
       * Internal use only
       */
      inline CMetadataInfoData& TypedObject() const;
  };
  /*
   *
   */
  inline CMetadataInfo::CMetadataInfo()
  {
  }
  /*
   *
   */
  inline CMetadataInfo::CMetadataInfo(const CMetadataInfo& argMetadataInfo)
    : CObjPtr((CObjPtr&)argMetadataInfo)
  {
  }
  /*
   *
   */
  inline CMetadataInfo::CMetadataInfo(CMetadataInfoData* pObj)
    : CObjPtr((CObj*)pObj)
  {
  }
  /*
   *
   */
  inline CMetadataInfo::~CMetadataInfo()
  {
  }
  /*
   *
   */
  inline CMetadataInfoData& CMetadataInfo::TypedObject() const
  {
    return (CMetadataInfoData&)Object();
  }
} // namespace
#endif //_CMetadataInfo_h_
