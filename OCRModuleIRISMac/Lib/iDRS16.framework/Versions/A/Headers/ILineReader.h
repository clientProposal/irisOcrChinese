/**
 * \file ILineReader.h
 * \brief Interface to the IDRS::ILineReader class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _ILineReader_h_
#define _ILineReader_h_
#include <CObj.h>
namespace IDRS
{
  /**
   * \brief The ILineReader defines the interface required to provide a custom line reader.
   * \ingroup module_core
   *
   * A line reader object is used to provide image buffers inside iDRS.
   * A common usage for this class is to provide the image raw data for image file format that iDRS SDK is not currently supported or for custom image file formats
   *
   * \see CStdLineReader contains a default implementation of this interface working with memory buffers
   */
  class IDRSKRN_API ILineReader
  {
    public:
      //! Destructor
      inline virtual ~ILineReader () = default;
      /**
       * \brief GetLine retrieves the data for the requested line.
       *
       * The integrator has to override this method to provide the data for the requested line.
       *
       * \param pvLine The buffer where to write the pixels of the line.
       * \param ui32Line The 0 based index of the line to retrieve.
       * \param ui32Bytes The byte width for the line.
       */
      virtual void GetLine ( IDRS_PVOID pvLine, const IDRS_UINT32 ui32Line, const IDRS_UINT32 ui32Bytes ) = 0;
  };
} // namespace
#endif /* _ILineReader_h_ */
