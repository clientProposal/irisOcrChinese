/**
 * \file CAttachment.h
 * \brief Interface for IDRS::CAttachment class
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */

#ifndef _CAttachment_h_
#define _CAttachment_h_

#include "TObjPtrArray.h"
#include <CObjPtr.h>
#include <IByteStream.h>
#include <EnumDefinitions.h>

namespace IDRS
{
  class CAttachmentData;
  class idrs_string;
  /**
    * \brief CAttachment represent an attachment to add to an output PDF.
    */
  class IDRSKRN_API CAttachment : public CObjPtr
  {
  public:
    /**
     * \brief Default constructor.
     */
    inline CAttachment ();
    /**
     * \brief Copy constructor.
     *
     * \param argOther The smart pointer to copy.
     */
    inline CAttachment ( const CAttachment & argOther );
    /**
     * \brief Constructor from data.
     *
     * \param pargData The data object to point to.
     */
    inline CAttachment ( CAttachmentData * pargData );
    /**
     * \brief CAttachment constructor that initializes an object with a data object
     *
     * \see CObjPtr and CObj for iDRS SDK smart pointers and data classes
     *
     * \param pObj Pointer to an object representing the data class
     */
    inline CAttachment (CObj* pObj);
    /**
     * \brief Destructor
     */
    inline virtual ~CAttachment ();
    /**
     * \brief Create a CAttachment object from a file path.
     *
     * \param strAttachFileName The name of the file to attach, as it will appear in the output PDF.
     *   A period should be used to separate the base file name from the file extension.
     * \param evAttachmentType The type of the attachment
     * \param strFilePath Path to the file to attach
     * \param bCopyContent If true, the file's content will be copied at object's creation; otherwise it will be
     *   read only during the call to CDocumentWriter::Save().
     */
    static CAttachment Create ( const idrs_string &strAttachFileName, const AttachmentType evAttachmentType,
      const idrs_string &strFilePath, const IDRS_BOOL bCopyContent = IDRS_TRUE );
    /**
     * \brief Create a CAttachment object from a stream.
     *
     * \param strAttachFileName The name of the file to attach, as it will appear in the output PDF.
     *   A period should be used to separate the base file name from the file extension.
     * \param evAttachmentType The type of the attachment
     * \param argStream The content of the file to attach
     * \param bCopyContent If true, the stream's content will be copied at object's creation; otherwise it will be
     *   read only during the call to CDocumentWriter::Save().
     */
    static CAttachment Create ( const idrs_string &strAttachFileName, const AttachmentType evAttachmentType,
      IByteStream & argStream, const IDRS_BOOL bCopyContent = IDRS_TRUE );
  private:
    // For internal use only
    CAttachmentData & TypedObject () const
    {
      return (CAttachmentData &) Object ();
    };
  };

  typedef TObjPtrArray<CAttachment> CAttachmentArray;

  /*
   *
   */
  inline CAttachment::CAttachment ()
  {
  }
  /*
   *
   */
  inline CAttachment::CAttachment ( const CAttachment & argOther )
    : CObjPtr (( CObjPtr & ) argOther )
  {
  }
  /*
   *
   */
  inline CAttachment::CAttachment ( CAttachmentData * pargData )
    : CObjPtr (( CObj * ) pargData )
  {
  }
  /*
   *
   */
  inline CAttachment::CAttachment (CObj* pObj)
    : CObjPtr (pObj)
  {

  }
  /*
   *
   */
  inline CAttachment::~CAttachment ()
  {
  }
}
#endif // _CAttachment_h_
