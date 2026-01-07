/**
 * \file CLineRemoval.h
 * \brief Interface for the IDRS::CLineRemoval class.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _clineremoval_h_
#define _clineremoval_h_
#include <CIDRS.h>
#include <CImageOperation.h>
#include <CPolygon.h>
namespace IDRS
{
  class CLineRemovalData;
  /**
   * \brief The CLineRemoval class provides line removal capabilities.
   * \ingroup module_prepro
   *
   * The class contains algorithms for removing vertical and horizontal lines in an image. <br>
   * The integrator can control various settings in line removal algorithm like:
   * - minimum and maximum line length and thickness of horizontal lines
   * - minimum and maximum line length and thickness of vertical lines
   * - clean noisy pixels adjacent to the line
   * - maximum gap between the lines
   *
   * \req IDRS::Module::Prepro
   *
   * \see Module::Prepro for information about the preprocessing library
   */
  class IDRSKRN_API CLineRemoval : public CImageOperation
  {
    public:
      /**
       * \brief Default constructor.
       */
      inline CLineRemoval ();
      /**
       * \brief Copy constructor.
       *
       * \param argLineRemoval The smart pointer to copy.
       */
      inline CLineRemoval ( const CLineRemoval & argLineRemoval );
      /**
       * \brief Constructor.
       *
       * \param pLineRemovalData The object to point to.
       */
      inline CLineRemoval ( CLineRemovalData * pLineRemovalData );
      /**
       * \brief Destructor
       */
      inline virtual ~CLineRemoval ();
      /**
       * \brief Creates a new CLineRemoval object.
       *
       * \param argIDRS The iDRS
       *
       * \return The newly created CLineRemoval object.
       *
       * \throw CIDRSException if an error occur.
       */
      static CLineRemoval Create ( const CIDRS & argIDRS );
      /**
       * \brief SetHorizontalMinLength sets the minimum length of the horizontal lines to remove.
       *
       * \pre ! IsNull ()
       *
       * \param uiHorizontalMinLength The minimum length of the horizontal lines to remove.
       *
       * \note The default value is IDRS_DFLT_LRM_HORZ_MIN_LENGTH.
       *
       */
      void SetHorizontalMinLength ( const IDRS_UINT uiHorizontalMinLength );
      /**
       * \brief SetHorizontalMaxThickness sets the maximum thickness of the horizontal lines to remove.
       *
       * It is useful to keep vertical lines larger than this parameter. Can be also useful to keep vertical letter strokes
       *
       * \pre ! IsNull ()
       *
       * \param uiHorizontalMaxThickness The maximum thickness of the horizontal lines to remove.
       *
       * \note The default value is IDRS_DFLT_LRM_HORZ_MAX_THICKNESS.
       *
       */
      void SetHorizontalMaxThickness ( const IDRS_UINT uiHorizontalMaxThickness );
      /**
       * \brief SetHorizontalMaxGap sets the maximum horizontal line gap to close.
       *
       * It is useful to remove broken lines.
       *
       * \pre ! IsNull ()
       *
       * \param uiHorizontalMaxGap The maximum horizontal line gap to close.
       *
       * \note The default value is IDRS_DFLT_LRM_HORZ_MAX_GAP.
       *
       */
      void SetHorizontalMaxGap ( const IDRS_UINT uiHorizontalMaxGap );
      /**
       * \brief SetHorizontalDilate sets the dilate parameter that helps the detection of horizontal lines, especially for thin and/or skewed horizontal lines.
       *
       * \pre ! IsNull ()
       *
       * \param uiHorizontalDilate The dilate parameter that helps the detection of horizontal lines.
       *
       * \note The default value is IDRS_DFLT_LRM_HORZ_DILATE.
       *
       */
      void SetHorizontalDilate ( const IDRS_UINT uiHorizontalDilate );
      /**
       * \brief SetHorizontalCleanY sets the parameter for cleaning noisy pixels attached to the horizontal lines.
       *
       * \pre ! IsNull ()
       *
       * \param uiHorizontalCleanY The parameter for cleaning noisy pixels attached to the horizontal lines.
       *
       * \note The default value is IDRS_DFLT_LRM_HORZ_CLEAN_Y.
       *
       */
      void SetHorizontalCleanY ( const IDRS_UINT uiHorizontalCleanY );
      /**
       * \brief SetHorizontalCleanX sets the parameter for cleaning noisy pixels attached to the horizontal lines.
       *
       * \pre ! IsNull ()
       *
       * \param uiHorizontalCleanX The parameter for cleaning noisy pixels attached to the horizontal lines.
       *
       * \note The default value is IDRS_DFLT_LRM_HORZ_CLEAN_X.
       *
       */
      void SetHorizontalCleanX ( const IDRS_UINT uiHorizontalCleanX );
      /**
       * \brief SetVerticalMinLength sets the minimum length of the vertical lines to remove.
       *
       * \pre ! IsNull ()
       *
       * \param uiVerticalMinLength The minimum length of the vertical lines to remove.
       *
       * \note The default value is IDRS_DFLT_LRM_VERT_MIN_LENGTH.
       *
       */
      void SetVerticalMinLength ( const IDRS_UINT uiVerticalMinLength );
      /**
       * \brief SetVerticalMaxThickness sets the maximum thickness of the vertical lines to remove.
       *
       * It is useful to keep horizontal lines larger than this parameter. Can be also useful to keep horizontal letter strokes.
       *
       * \pre ! IsNull ()
       *
       * \param uiVerticalMaxThickness The maximum thickness of the vertical lines to remove.
       *
       * \note The default value is IDRS_DFLT_LRM_VERT_MAX_THICKNESS.
       *
       */
      void SetVerticalMaxThickness ( const IDRS_UINT uiVerticalMaxThickness );
      /**
       * \brief SetVerticalMaxGap sets the maximum vertical line gap to close.
       *
       * It is useful to remove broken lines.
       *
       * \pre ! IsNull ()
       *
       * \param uiVerticalMaxGap The maximum vertical line gap to close.
       *
       * \note The default value is IDRS_DFLT_LRM_VERT_MAX_GAP.
       *
       */
      void SetVerticalMaxGap ( const IDRS_UINT uiVerticalMaxGap );
      /**
       * \brief SetVerticalDilate sets the dilate parameter that helps the detection of vertical lines, especially for thin and/or skewed vertical lines.
       *
       * \pre ! IsNull ()
       *
       * \param uiVerticalDilate The dilate parameter that helps the detection of vertical lines.
       *
       * \note The default value is IDRS_DFLT_LRM_VERT_DILATE.
       *
       */
      void SetVerticalDilate ( const IDRS_UINT uiVerticalDilate );
      /**
       * \brief SetVerticalCleanY sets the parameter for cleaning noisy pixels attached to the vertical lines.
       *
       * \pre ! IsNull ()
       *
       * \param uiVerticalCleanY The parameter for cleaning noisy pixels attached to the vertical lines.
       *
       * \note The default value is IDRS_DFLT_LRM_VERT_CLEAN_Y.
       *
       */
      void SetVerticalCleanY ( const IDRS_UINT uiVerticalCleanY );
      /**
       * \brief SetVerticalCleanX sets the parameter for cleaning noisy pixels attached to the vertical lines.
       *
       * \pre ! IsNull ()
       *
       * \param uiVerticalCleanX The parameter for cleaning noisy pixels attached to the vertical lines.
       *
       * \note The default value is IDRS_DFLT_LRM_VERT_CLEAN_X.
       *
       */
      void SetVerticalCleanX ( const IDRS_UINT uiVerticalCleanX );
      /**
       * \brief RemoveLines removes lines in the given image.
       *
       * The image must be black and white (otherwise an exception with the IDRS_ERROR_INVALID_ARGS code is thrown).
       *
       * \attention Line removal is only available for black and white images.
       *
       * \pre ! IsNull ()
       * \pre ! argImage.IsNull ()
       *
       * \param argImage The image to clean.
       * \param bRemoveHorizontalLines If IDRS_TRUE, the horizontal lines are removed.
       * \param bRemoveVerticalLines If IDRS_TRUE, the vertical lines are removed.
       *
       * \throw CIDRSException if an error occur.
       */
      void RemoveLines ( CImage & argImage, const IDRS_BOOL bRemoveHorizontalLines = IDRS_TRUE,
                         const IDRS_BOOL bRemoveVerticalLines = IDRS_TRUE );
      /**
       * \brief RemoveLines removes lines in a zone of the given image.
       *
       * The image must be black and white (otherwise an exception with the IDRS_ERROR_INVALID_ARGS code is thrown).
       *
       * \attention Line removal is only available for black and white images.
       *
       * \pre ! IsNull ()
       * \pre ! argImage.IsNull ()
       *
       * \param argImage The image to clean.
       * \param rRectangle The rectangle zone to process.
       * \param bRemoveHorizontalLines If IDRS_TRUE, the horizontal lines are removed.
       * \param bRemoveVerticalLines If IDRS_TRUE, the vertical lines are removed.
       *
       * \throw CIDRSException if an error occur.
       */
      void RemoveLines ( CImage & argImage, const IDRS_RECT rRectangle, const IDRS_BOOL bRemoveHorizontalLines = IDRS_TRUE,
                         const IDRS_BOOL bRemoveVerticalLines = IDRS_TRUE );
    private:
      //
      void RemoveLines ( IDRS_PVOID pImage, const IDRS_UINT uiHeight, const IDRS_UINT uiWidth, const IDRS_UINT uiByteWidth,
                         const IDRS_RECT * pRectangle, const IDRS_BOOL bRemoveHorizontalLines, const IDRS_BOOL bRemoveVerticalLines );
      //
      CLineRemovalData & TypedObject () const
      {
        return ( CLineRemovalData & )Object ();
      };
  };
  /*
   *
   */
  inline CLineRemoval::CLineRemoval ()
  {
  }
  /*
   *
   */
  inline CLineRemoval::CLineRemoval ( const CLineRemoval & argLineRemoval )
    : CImageOperation (( CImageOperation & )argLineRemoval )
  {
  }
  /*
   *
   */
  inline CLineRemoval::CLineRemoval ( CLineRemovalData * pLineRemovalData )
    : CImageOperation (( CImageOperationData * )pLineRemovalData )
  {
  }
  /*
   *
   */
  inline CLineRemoval::~CLineRemoval ()
  {
  }
} //namespace
#endif /* _clineremoval_h_ */
