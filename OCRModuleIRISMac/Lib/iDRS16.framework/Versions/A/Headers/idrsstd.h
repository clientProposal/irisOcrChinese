/**
 * \file idrsstd.h
 * \brief This file declares iDRS standard data types and the associated basic operators.
 * 
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
 
#include <idrskrn.h>
 
#ifndef _idrsstd_h_
#define _idrsstd_h_
#ifdef IDRS_OS_WIN
#else /* IDRS_OS_WIN */
  #if defined( IDRS_OS_MACINTOSH ) || defined( IDRS_OS_IOS )
  #else /* IDRS_OS_MACINTOSH */
    #ifdef IDRS_OS_LINUX
    #else /* IDRS_OS_SOLARIS_GCC */
      #ifdef IDRS_OS_ANDROID
      #else /* IDRS_OS_ANDROID */    
        #error Unsupported OS    
      #endif /* IDRS_OS_LINUX */
    #endif /* IDRS_OS_ANDROID */
  #endif /* IDRS_OS_MACINTOSH || IDRS_OS_IOS */
#endif /* IDRS_OS_WIN */
#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <stdlib.h>
#include <idrserr.h>
namespace IDRS
{
  /** \brief A byte. */
  typedef unsigned char IDRS_BYTE;
  /** \brief Pointer to a byte. */
  typedef IDRS_BYTE * IDRS_PBYTE;
  /** \brief A signed char. */
  typedef char IDRS_CHAR;
  /** \brief An unsigned char. */
  typedef unsigned char IDRS_UCHAR;
  /** \brief An UTF-32 unicode character. */
  typedef char32_t IDRS_WCHAR32;
  /** \brief A signed integer. */
  typedef int IDRS_INT;
  /** \brief An unsigned integer. */
  typedef unsigned int IDRS_UINT;
  /** \brief An unsigned integer on 32 bits. */
  typedef unsigned int IDRS_UINT32;
  /** \brief An signed 64 bit value */
  typedef long long IDRS_INT64;
  /** \brief An unsigned 64 bit value */
  typedef unsigned long long IDRS_UINT64;
  /** \brief A double float value. */
  typedef double IDRS_DOUBLE;
  /** \brief A Boolean value. */
  typedef IDRS_INT IDRS_BOOL;
  /** \brief false. */
  #define IDRS_FALSE 0
  /** \brief true. */
  #define IDRS_TRUE  1
  /** \brief A void pointer. */
  typedef void * IDRS_PVOID;
  /** \brief A constant void pointer. */
  typedef const void * IDRS_CPVOID;


  /** \brief The maximum lenth for a path. */
  #define IDRS_MAX_PATH 260

  /**
   * \brief Structure that defines the upper-left and lower-right corners of a rectangle.
   */
  typedef struct
  {
    //! Top border of the rectangle. Must have a lower value than the bottom.
    IDRS_INT iTop;
    //! Left border of the rectangle. Must have a lower value than the right.
    IDRS_INT iLeft;
    //! Bottom border of the rectangle. Must have a higher value than the top.
    IDRS_INT iBottom;
    //! Right border of the rectangle. Must have a higher value than the left.
    IDRS_INT iRight;
  } IDRS_RECT;
  /**
   * \brief Structure defines the coordinates of a point in iDRS
   */
  typedef struct
  {
    //! X-axis coordinate.
    IDRS_INT iX;
    //! Y-axis coordinate.
    IDRS_INT iY;
  } IDRS_POINT;
  /**
   * \brief Structure defines a color with Red, Green and Blue components
   */
  typedef struct
  {
    /** \brief The blue component. */
    IDRS_UCHAR ucBlue;
    /** \brief The green component. */
    IDRS_UCHAR ucGreen;
    /** \brief The red component. */
    IDRS_UCHAR ucRed;
  } IDRS_COLOR;
} // namespace

#endif /* _idrsstd_h_ */
