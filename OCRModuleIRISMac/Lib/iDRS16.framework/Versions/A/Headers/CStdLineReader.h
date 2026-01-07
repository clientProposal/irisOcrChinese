/**
 * \file CStdLineReader.h
 * \brief Interface to the IDRS::CStdLineReader class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _cstdlinereader_h_
#define _cstdlinereader_h_
#include <ILineReader.h>
namespace IDRS
{
  /**
   * \brief The CStdLineReader class provides a standard implementation for a line reader class that reads the lines in a memory buffer.
   * \ingroup module_core
   *
   * The class is providing a quick and convenient way of accessing a memory buffer that stores the pixels of image or some other data.
   *
   * \see ILineReader
   */
  class IDRSKRN_API CStdLineReader : public ILineReader
  {
    public:
      /**
       * Constructs a CStdLineReader object.
       *
       * Initializes members with the provided values
       *
       * \param pvPixels - buffer containing the image pixels
       * \param ui32LineCount - number of lines of pixels available in the pixels buffer (image height)
       * \param ui32ByteWidth - number of bytes for representing the width in bytes of each line
       */
      inline CStdLineReader ( IDRS_PVOID pvPixels, const IDRS_UINT32 ui32LineCount, const IDRS_UINT32 ui32ByteWidth );
      /**
       * \brief CStdLineReader destructor
       *
       * \note The class doesn't take care of releasing the pixels buffer provided as argument in class constructor
       */
      inline virtual ~CStdLineReader ();
      /**
       * Retrieve a line of pixels from the memory buffer.
       *
       * \pre m_pbPixels != NULL
       * \pre m_ui32ByteWidth != 0
       * \pre ui32Line < m_ui32LineCount
       * \pre pvLine != NULL
       *
       * \param pvLine The buffer where to write the line data.
       * \param ui32Line The 0 based index of the line to retrieve.
       * \param ui32Bytes The number of bytes to retrieve.
       *
       * \note If the number of bytes to be retrieved is greater than the line width in bytes, the number of bytes surpassing the line byte width will be set to 0
       */
      inline virtual void GetLine ( IDRS_PVOID pvLine, const IDRS_UINT32 ui32Line, const IDRS_UINT32 ui32Bytes );
    protected:
      /**
       * The memory buffer (pixels).
       */
      IDRS_PBYTE m_pbPixels;
      /**
       * The number of lines (height) of the image
       */
      IDRS_UINT32 m_ui32LineCount;
      /**
       * The width in bytes of the image in the memory buffer.
       */
      IDRS_UINT32 m_ui32ByteWidth;
  };
  /*
   *
   */
  inline CStdLineReader::CStdLineReader ( IDRS_PVOID pvPixels, const IDRS_UINT32 ui32LineCount, const IDRS_UINT32 ui32ByteWidth )
    : m_pbPixels (( IDRS_PBYTE )pvPixels ), m_ui32LineCount ( ui32LineCount ), m_ui32ByteWidth ( ui32ByteWidth )
  {
  }
  /*
   *
   */
  inline CStdLineReader::~CStdLineReader()
  {
  }
  /*
   *
   */
  inline void CStdLineReader::GetLine ( IDRS_PVOID pvLine, const IDRS_UINT32 ui32Line, const IDRS_UINT32 ui32Bytes )
  {
    /* Preconditions */
    IDRS_ASSERT ( m_pbPixels != NULL );
    IDRS_ASSERT ( m_ui32ByteWidth != 0 );
    IDRS_ASSERT ( ui32Line < m_ui32LineCount );
    IDRS_ASSERT ( pvLine != NULL );
    if ( ui32Bytes <= m_ui32ByteWidth )
    {
      memcpy ( pvLine, m_pbPixels + ui32Line * m_ui32ByteWidth, ui32Bytes );
    }
    else
    {
      memcpy ( pvLine, m_pbPixels + ui32Line * m_ui32ByteWidth, m_ui32ByteWidth );
      memset (( IDRS_PBYTE ) pvLine + m_ui32ByteWidth, 0, ui32Bytes - m_ui32ByteWidth );
    }
  }
} // namespace
#endif /* _cstdlinereader_h_ */
