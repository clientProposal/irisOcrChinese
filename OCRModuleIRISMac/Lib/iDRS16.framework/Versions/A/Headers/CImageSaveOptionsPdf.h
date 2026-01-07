/**
 * \file CImageSaveOptionsPdf.h
 * \brief Interface for IDRS::CImageSaveOptionsPdf class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */

#ifndef _CImageSaveOptionsPdf_h_
#define _CImageSaveOptionsPdf_h_

#include "CImageSaveOptions.h"

namespace IDRS
{
  class CImageSaveOptionsData;

  /**
   * \brief CImageSaveOptionsPdf contains the options for saving image to pdf file format
   * \ingroup module_image_formats
   *
   *
   */
  class IDRSKRN_API CImageSaveOptionsPdf : public CImageSaveOptions
  {
  public:
      /**
       * \brief Default constructor.
       */
      inline CImageSaveOptionsPdf ();
      /**
       * \brief Copy constructor.
       *
       * \param argImageSaveOptionsPdf The CImageSaveOptionsPdf object to copy.
       */
      inline CImageSaveOptionsPdf ( const CImageSaveOptionsPdf & argImageSaveOptionsPdf );
      /**
       * \brief Constructor.
       *
       * \param pImageSaveOptionsData The object to point to.
       */
      inline CImageSaveOptionsPdf ( const CImageSaveOptionsData* pImageSaveOptionsData );
      /**
       * \brief Destructor
       */
      inline virtual ~CImageSaveOptionsPdf();
      /**
       * \brief Creates a new CImageSaveOptionsPdf object and initializes it's internal data structures
       *
       * \return The newly created object
       */
      static CImageSaveOptionsPdf Create ();
      /**
       * \brief Returns the boolean flag that specify if the image will be appended to an existing file or not
       * 
       * \return IDRS_TRUE if the image will be appended, IDRS_FALSE otherwise 
       * \remark Default value IDRS_TRUE
       */
      IDRS_BOOL GetAppendIfExists() const;
      /**
       * \brief Set the boolean flag that specify if the image will be appended to an existing file or not
       *
       * \param bAppendIfExists New value
       */
      void SetAppendIfExists( const IDRS_BOOL bAppendIfExists );
      /**
       * \brief Get the jpeg compression quality factor.
       *
       * \return The jpeg compression quality factor
       * \remark Default value CompressionQuality::HighQuality
       */
      CompressionQuality GetJpegCompressionQualityFactor () const;
      /**
       * \brief Set the jpeg compression quality factor.
       *
       * \param evJpegCompressionQualityFactor The compression quality factor to set
       */
      void SetJpegCompressionQualityFactor (const CompressionQuality evJpegCompressionQualityFactor );
  private:
      /**
       * \brief Return a CImageSaveOptionsPdfData reference.
       *
       * Internal use only
       */
      inline CImageSaveOptionsData& TypedObject () const
      {
        return (CImageSaveOptionsData& )Object ();
      };
  };
  /*
   *  
   */
  inline CImageSaveOptionsPdf::CImageSaveOptionsPdf ()
  {
  }
  /*
   *  
   */
  inline CImageSaveOptionsPdf::CImageSaveOptionsPdf ( const CImageSaveOptionsPdf & argImageSaveOptionsPdf )
    : CImageSaveOptions(( const CImageSaveOptions & )argImageSaveOptionsPdf)
  {
  }
  /*
   *  
   */
  inline CImageSaveOptionsPdf::CImageSaveOptionsPdf ( const CImageSaveOptionsData* pImageSaveOptionsData)
    : CImageSaveOptions (pImageSaveOptionsData)
  {
  }
  /*
   *  
   */
  inline CImageSaveOptionsPdf::~CImageSaveOptionsPdf ()
  {
  }

}
#endif  // _CImageSaveOptionsPdf_h_
