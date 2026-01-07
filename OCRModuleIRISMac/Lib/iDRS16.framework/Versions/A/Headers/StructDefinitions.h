/**
 * \file StructDefinitions.h
 * \brief Source file grouping struct definitions for iDRS SDK.
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _StructDefinitions_h_
#define _StructDefinitions_h_

#include "idrsstd.h"
#include "Language.h"

namespace IDRS
{
  //! Structure containing the padding information for a page
  struct PaddingInfo
  {
    //! Padding left
    IDRS_INT iLeft;
    //! Padding top
    IDRS_INT iTop;
    //! Padding right
    IDRS_INT iRight;
    //! Padding bottom
    IDRS_INT iBottom;
  };

  //! Structure containing the margins for a page element
  struct MarginInfo
  {
    //! Left margin
    IDRS_INT iMarginLeft;
    //! Top margin
    IDRS_INT iMarginTop;
    //! Right margin
    IDRS_INT iMarginRight;
    //! Bottom margin
    IDRS_INT iMarginBottom;
  };

  /**
   * \brief The PerspectiveCorners structure contains the four corners of a quadrilateral that represent the area of the document that has been photographed.
   * \ingroup module_prepro_camera_image
   */
  struct PerspectiveCorners
  {
    //! The top-left corner
    IDRS_POINT stTopLeft;
    //! The top-right corner
    IDRS_POINT stTopRight;
    //! The bottom-right corner
    IDRS_POINT stBottomRight;
    //! The bottom-left corner
    IDRS_POINT stBottomLeft;
  } ;

  /**
   * \brief Fine representation of a skew angle.
   */
  struct SkewInfo
  {
    //! X-axis component
    IDRS_INT X;
    //! Y-axis component
    IDRS_INT Y;
  };

  /**
   * \brief Structure containing the language candidates that are found during page analysis
   */
  struct LanguageCandidate
  {
    //! Language candidate
    Language evLanguage;
    //! Confidence level for the language detection.
    //! Range is 0 to 100, where 100 mean high confidence
    IDRS_UINT uiConfidenceLevel;
  };

  /**
   * \brief Structure that manages advanced barcode recognition parameters.
   *
   * It let the integrator specify advanced parameters for a specific barcode type:
   * - minimum and maximum number of symbols.
   *
   * \see group_idrs_barcodes The iDRS barcodes types.
   * \see group_idrs_dflt_barcode The default barcode parameters.
   */
  struct BarcodeAdvancedParameters
  {
    /** \brief The minimum barcode length (number of symbols), 0 for automatic. */
    IDRS_UINT uiMinLength;
    /** \brief The maximum barcode length (number of symbols), 0 for automatic. */
    IDRS_UINT uiMaxLength;
  };
}

#endif // _StructDefinitions_h_
