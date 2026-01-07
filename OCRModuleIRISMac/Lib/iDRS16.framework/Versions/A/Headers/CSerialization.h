/**
 * \file CSerialization.h
 * \brief Interface for the IDRS::CSerialization class.
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */

#ifndef _CSerialization_h_
#define _CSerialization_h_
#include "idrsstd.h"
#include <CObjPtr.h>
#include "CPageContent.h"
#include "EnumDefinitions.h"
#include "CIDRS.h"

namespace IDRS
{
  class CSerializationData;
  class CPage;
  class IByteStream;
  class idrs_string;

  /**
   * \brief The CSerialization class manages loading and saving of page content for the iDRS.
   *
   */
  class IDRSKRN_API CSerialization : public CObjPtr
  {
  public:
    /**
     * \brief Default constructor.
     */
    CSerialization() = default;
    /**
     * \brief Copy constructor.
     *
     * \param argSerialization The smart pointer to copy.
     */
    inline CSerialization(const CSerialization& argSerialization);
    /**
     * \brief Constructor.
     *
     * \param pSerializationData The object to point to.
     */
    inline CSerialization(CSerializationData* pSerializationData);
    /**
     * \brief Destructor
     */
    inline virtual ~CSerialization() = default;
    /**
     * \brief Create the CSerialization instance.
     *
     * \param argIdrs The iDRS instance
     * \param evSerializationVersion The format to save to
     *
     * \throw CIDRSException if an error occur.
     */
    static CSerialization Create(const CIDRS & argIdrs, const SerializationFormat evSerializationVersion = SerializationFormat::Latest);
    /**
     * \brief LoadPage loads a page from its serialized format.
     *
     * \pre ! IsNull ()
     *
     * \param strFileName The name of the serialized file.
     *
     * \return The loaded page
     */
    CPage LoadPage(const idrs_string &strFileName) const;
    /**
     * \brief LoadPage loads a page from its serialized format.
     *
     * \pre ! IsNull ()
     * \pre ! argPage.IsNull ()
     *
     * \param argStream The input stream
     *
     * \return The loaded page
     */
    CPage LoadPage(IByteStream& argStream) const;
    /**
     * \brief SavePage saves a page object into its serialized format.
     *
     * \pre ! IsNull ()
     * \pre ! argPage.IsNull ()
     *
     * \param argPage The page
     * \param strFileName The name of the file to save to.
     *
     * \remarks For the moment the page's images (source, work, background) are not serialized and should therefore be handled separately by the integrator.
     */
    void SavePage(const CPage& argPage, const idrs_string &strFileName) const;
    /**
     * \brief SavePage saves a page object into its serialized format.
     *
     * \pre ! IsNull ()
     * \pre ! argPage.IsNull ()
     *
     * \param argPage The page
     * \param argStream The output stream to save to.
     *
     * \remarks For the moment the page's images (source, work, background) are not serialized and should therefore be handled separately by the integrator.
     */
    void SavePage(const CPage& argPage, IByteStream& argStream) const;
    /**
     * \brief LoadPageContent loads page content from the given file.
     *
     * \pre ! IsNull ()
     *
     * \param strFileName The name of the file.
     * \return The page content
     */
    CPageContent LoadPageContent(const idrs_string &strFileName) const;
    /**
     * \brief LoadPageContent loads zones from the given stream.
     *
     * \pre ! IsNull ()
     *
     * \param argStream The input stream
     * \return The page content
     */
    CPageContent LoadPageContent(IByteStream& argStream) const;
    /**
     * \brief SavePage saves a page's content into its serialized format.
     *
     * \pre ! IsNull ()
     * \pre ! argPageContent.IsNull ()
     *
     * \param argPageContent The source page content
     * \param strFileName The name of the file.
     */
    void SavePageContent(const CPageContent& argPageContent, const idrs_string &strFileName) const;
    /**
     * \brief SavePage saves a page's content into its serialized format.
     *
     * \pre ! IsNull ()
     * \pre ! argPageContent.IsNull ()
     *
     * \param argPageContent The source page content
     * \param argStream The output stream.
     */
    void SavePageContent(const CPageContent& argPageContent, IByteStream& argStream) const;
    /**
     * \brief Set the serialization format which will be used when saving a page or its content.
     *
     * \remarks It is recommended to use SerializationFormat::Latest, unless very specific constraints on integrator's side (when several components use different iDRS versions for instance).
     *
     * \param evSerializationVersion The format to save to
     */
    void SetFormat(const SerializationFormat evSerializationVersion);
    /**
     * \brief Get the serialization format which will be used when saving a page or its content.
     *
     * \return The format to save to
     */
    SerializationFormat GetFormat() const;
  private:
    // For internal use only
    CSerializationData& TypedObject() const
    {
      return (CSerializationData&)Object();
    };
  };
  /*
   *
   */
  CSerialization::CSerialization(const CSerialization& argSerialization)
    : CObjPtr{ (CObjPtr&)argSerialization }
  {
  }
  /*
   *
   */
  CSerialization::CSerialization(CSerializationData* pSerializationData)
    : CObjPtr{ (CObj*)pSerializationData }
  {
  }
}
#endif /* _CSerialization_h_ */   
