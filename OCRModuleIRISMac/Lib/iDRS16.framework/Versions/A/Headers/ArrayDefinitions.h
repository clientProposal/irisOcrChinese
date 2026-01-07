/**
 * \file ArrayDefinitions.h
 * \brief Interface for ArrayDefinitions class
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#ifndef _ArrayDefinitions_h_
#define _ArrayDefinitions_h_
 
#include <EnumDefinitions.h>
#include <TObjPtrArray.h>
#include "BarcodeType.h"
#include <idrsstd.h>

namespace IDRS
{
  typedef TObjPtrArray<IDRS_POINT> PointArray;
  typedef TObjPtrArray<PageOrientation> PageOrientationArray;
  typedef TObjPtrArray<Language> LanguageArray;
  typedef TObjPtrArray<BarcodeType> BarcodeTypeArray;
  typedef TObjPtrArray<BarcodeCapability> BarcodeCapabilityArray;
  typedef TObjPtrArray<BarcodeEncoding> BarcodeEncodingArray;
  typedef TObjPtrArray<LanguageCandidate> LanguageCandidateArray;
}

#endif // _ArrayDefinitions_h_
