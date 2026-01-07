/**
 * \file CPdfUpdateParams.h
 * \brief Interface for CPdfUpdateParams class
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _cpdfupdateparams_h_
#define _cpdfupdateparams_h_
#include <CObjPtr.h>
#include <CPdfCompressionOptions.h>
namespace IDRS
{
    class CPdfUpdateParamsData;

    /**
     * \brief The CPdfUpdateParams class manages the parameters for PDF update operations.
     */
    class IDRSKRN_API CPdfUpdateParams : public CObjPtr
    {
      public:
        /**
         * \brief Default constructor.
         */
        inline CPdfUpdateParams();
        /**
         * \brief constructor.
         */
        inline CPdfUpdateParams(CPdfUpdateParamsData* pObjPdfUpdateParamsData);
        /**
         * \brief Copy constructor
         *
         * \param objPdfUpdateParams Object to copy (shallow copy)
         */
        inline CPdfUpdateParams(const CPdfUpdateParams& objPdfUpdateParams);
        /**
         * \brief Destructor
         */
        inline virtual ~CPdfUpdateParams();
        /**
         * \brief The Create method creates a CPdfUpdateParams object with default configuration (do not embed signature fonts, and use
         * default pdf image compression parameters).
         *
         * \return The newly created CPdfUpdateParams object.
         *
         */
        static CPdfUpdateParams Create();
        /**
         * \brief The Create method creates a CPdfUpdateParams object.
         *
         * \param bEmbedSignatureFonts embed signature fonts flag value.
         * \param argPdfSignatureCompressionOptions Signature compression options object.
         *
         * \return The newly created CPdfUpdateParams object.
         *
         */
        static CPdfUpdateParams Create(const IDRS_BOOL bEmbedSignatureFonts, const CPdfCompressionOptions& argPdfSignatureCompressionOptions);
        /**
         * \brief Get the font Embed Signature Fonts flag's value.
         *
         * \retval IDRS_TRUE if the signature font embedding flag is set
         * \retval IDRS_FALSE otherwise
         */
        IDRS_BOOL GetEmbedSignatureFonts() const;
        /**
         * \brief Set the font embedding flag's value.
         *
         * \param bEmbedSignatureFonts value to set to the font embedding flag.
         */
        void SetEmbedSignatureFonts(const IDRS_BOOL bEmbedSignatureFonts);
        /**
         * \brief Get the signature image compression attribute object.
         *
         * \return the signature image compression parameters object.
         */
        CPdfCompressionOptions GetSignatureCompressionOptions() const;
        /**
         * \brief Set the signature image compression parameters to use.
         *
         * \param argPdfSignatureCompressionOptions The signature compression parameters to use.
         */
        void SetSignatureCompressionOptions(const CPdfCompressionOptions& argPdfSignatureCompressionOptions);

    private:
      //! Private use only
      CPdfUpdateParamsData& TypedObject() const
      {
        return (CPdfUpdateParamsData&)Object();
      };
    };
    /*
     *
     */
    inline CPdfUpdateParams::CPdfUpdateParams()
    {
    }
    /*
     *
     */
    inline CPdfUpdateParams::~CPdfUpdateParams()
    {
    }
    /*
     *
     */
    inline CPdfUpdateParams::CPdfUpdateParams(CPdfUpdateParamsData* pObjPdfUpdateParamsData)
      : CObjPtr((CObj*)pObjPdfUpdateParamsData)
    {
    }
    /*
     *
     */
    inline CPdfUpdateParams::CPdfUpdateParams(const CPdfUpdateParams& objPdfUpdateParams)
      : CObjPtr((CObjPtr&)objPdfUpdateParams)
    {
    }
} // namespace IDRS

#endif //_cpdfupdateparams_h_
