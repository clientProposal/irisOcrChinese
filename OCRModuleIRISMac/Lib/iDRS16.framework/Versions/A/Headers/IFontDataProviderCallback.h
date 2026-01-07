/**
 * \file IFontDataProviderCallback.h
 * Interface for IFontDataProviderCallback class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */

#ifndef _IFontDataProviderCallback_h_
#define _IFontDataProviderCallback_h_

#include <idrs.h>

namespace IDRS
{
  /**
   * \brief IFontDataProviderCallback defines the interface required to supply the fonts to be used by the document output engine.
   */
  class IFontDataProviderCallback
  {
    public:
      //! Destructor
      inline virtual ~IFontDataProviderCallback() = default;
      /**
       * \brief GetFontData extracts the font data and writes it to the supplied memory stream
       *
       * The font data is required for PDF document creation. Currently iDRS SDK is able to work only with true type font outlines.
       * The following font tables are required:
       * - glyf
       * - head
       * - hhea
       * - loca
       * - maxp
       * - cvt
       * - prep
       * - hmtx
       * - fpgm
       *
       * \param strFontPostScriptName Font Postscript name
       * \param strFontFamilyName Font family name
       * \param bBold Boolean flag indicating that bold modifier is applied to the font
       * \param bItalic Boolean flag indicating that italic modifier is applied to the font
       * \param argOutputStream Stream object when the font data should be written
       *
       * \return IDRS_TRUE is the font has been found and the expected data has been extracted, IDRS_FALSE otherwise
       */
      virtual IDRS_BOOL GetFontData(const idrs_string& strFontPostScriptName, const idrs_string& strFontFamilyName,
        const IDRS_BOOL bBold, const IDRS_BOOL bItalic, IByteStream& argOutputStream) = 0;
  };
}

#endif // _IFontDataProviderCallback_h_
