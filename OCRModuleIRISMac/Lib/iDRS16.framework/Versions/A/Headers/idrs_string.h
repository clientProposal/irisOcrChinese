/**
 * \file idrs_string.h
 * \brief Internal iDRS string class interface and implementation
 *
 * \internal
 *
 * 2023-10-20 - IRIS SDK
 * - iDRS 16.1.0 release
 *
 * \endinternal
 */
#ifndef _idrs_string_h_
#define _idrs_string_h_

#include "idrsstd.h"

namespace IDRS
{
  class idrs_string_data;

  /**
   * \brief Class that handles a string of characters.
   *
   * The idrs_string can hold both UTF-8 and UTF-32 data representations. 
   * When needed, it automatically handles the required conversion. For instance,
   * an UTF-8 string can be assigned to the 'idrs_string' and then seemlessly retrieved as an UTF-32.
   */
  class IDRSKRN_API idrs_string final
  {
  public:

    /*
     * Types definitions
     */

    using utf8_type = char;
    using utf8_reference = utf8_type &;
    using const_utf8_reference = const utf8_type &;

    using utf32_type = char32_t;
    using utf32_reference = utf32_type &;
    using const_utf32_reference = const utf32_type &;

    //! Constant value that represents the end of string indicator in search methods
    static constexpr IDRS_INT npos = -1;

    /**
     * \brief Default constructor
     */
    idrs_string();
    /**
     * \brief Destructor
     */
    ~idrs_string();
    /**
     * \brief Copy constructor from another idrs_string
     *
     * \param argOther String to copy
     */
    idrs_string( const idrs_string &argOther );
    /**
     * \brief Constructor from a null terminated char buffer
     *
     * \param argBuffer Buffer containing the string
     */
    idrs_string( const utf8_type *argBuffer );
    /**
     * \brief Constructor from a char buffer and a size
     *
     * \param argBuffer Buffer containing the string
     * \param uiSize Size of the string to be taken into account
     */
    idrs_string( const utf8_type *argBuffer, const IDRS_UINT uiSize );
    /**
     * \brief Constructor from a null terminated wide char buffer
     *
     * \param argBuffer Buffer containing the string
     */
    idrs_string( const utf32_type *argBuffer );
    /**
     * \brief Constructor from a wide char buffer and a size
     *
     * \param argBuffer Buffer containing the string
     * \param uiSize Size of the string to be taken into account
     */
    idrs_string( const utf32_type *argBuffer, const IDRS_UINT uiSize );
    /**
     * \brief Returns the non-modifiable array of characters
     *
     * \returns Non-modifiable null-terminated utf-8 string.
     */
    const utf8_type *c_str() const;
    /**
     * \brief Returns the non-modifiable array of wide characters
     *
     * \returns Non-modifiable null-terminated utf-32 string.
     */
    const utf32_type *utf32_c_str() const;
    /**
     * \brief Retrieves a reference to the character at the given position
     *
     * \returns reference to the character
     */
    utf8_reference at( const IDRS_UINT uiIndex );
    /**
     * \brief Retrieves a reference to the wide character at the given position
     * 
     * \param uiIndex Position of the requested character
     * \returns reference to the character
     */
    utf32_reference utf32_at( const IDRS_UINT uiIndex );
    /**
     * \brief Retrieves a reference to the character at the given position
     *
     * \param uiIndex Position of the requested character
     * \returns reference to the character
     */
    const_utf8_reference at( const IDRS_UINT uiIndex ) const;
    /**
     * \brief Retrieves a reference to the wide character at the given position
     *
     * \returns reference to the character
     */
    const_utf32_reference utf32_at( const IDRS_UINT uiIndex ) const;
    /**
     * \brief Retrieves a reference to the character at the given position
     *
     * \param uiIndex Position of the requested character
     * \returns reference to the character
     */
    inline utf8_reference operator[]( const IDRS_UINT uiIndex );
    /**
     * \brief Retrieves a reference to the character at the given position
     *
     * \param uiIndex Position of the requested character
     * \returns reference to the character
     */
    inline const_utf8_reference operator[]( const IDRS_UINT uiIndex ) const;
    /**
     * \brief Clear the string content
     */
    void clear() noexcept;
    /**
     * \brief Assignment operator taking an idrs_string
     *
     * \param argOther String to assign
     * \return reference to the current string
     */
    idrs_string &assign( const idrs_string &argOther );
    /**
     * \brief Assignment operator taking a null-terminated buffer of chars
     *
     * \param argBuffer Buffer containing the utf-8 string to assign
     * \return reference to the current string
     */
    inline idrs_string &assign( const utf8_type *argBuffer );
    /**
     * \brief Assignment operator taking a buffer of chars with a size
     *
     * \param argBuffer Buffer containing the utf-8 string to assign
     * \param uiSize Size of the buffer
     * \return reference to the current string
     */
    idrs_string &assign( const utf8_type *argBuffer, const IDRS_UINT uiSize );
    /**
     * \brief Assignment operator taking a null-teminated buffer of wide chars
     *
     * \param argBuffer Buffer containing the utf-32 string to assign
     * \return reference to the current string
     */
    inline idrs_string &assign( const utf32_type *argBuffer );
    /**
     * \brief Assignment operator taking a buffer of wide chars and a size
     *
     * \param argBuffer Buffer containing the utf-32 string to assign
     * \param uiSize Size of the buffer
     * \return reference to the current string
     */
    idrs_string &assign( const utf32_type *argBuffer, const IDRS_UINT uiSize );
    /**
     * \brief Format the string using the sprintf syntax
     * \param strFormat Format string
     * \param ... Format arguments
     *
     * \returns reference to the current formatted string
     */
    static idrs_string format( const idrs_string strFormat, ...);
    /**
     * \brief Assignment operator taking an idrs_string
     *
     * \param argOther String to assign
     * \return reference to the current string
     */
    inline idrs_string &operator=( const idrs_string &argOther );
    /**
     * \brief Assignment operator taking a buffer of chars
     *
     * \param argBuffer Buffer containing the utf-8 string to assign
     * \return reference to the current string*
     */
    inline idrs_string &operator=( const utf8_type *argBuffer );
    /**
     * \brief Assignment operator taking a buffer of widechars
     *
     * \param argBuffer Buffer containing the utf-32 string to assign
     * \return reference to the current string*
     */
    inline idrs_string &operator=( const utf32_type *argBuffer );
    /**
     * \brief Returns the string length in its utf-8 representation
     *
     * \returns length of the string in its utf-8 representation
     */
    IDRS_UINT length() const;
    /**
     * \brief Returns the string length in its utf-32 representation
     *
     * \returns length of the string in its utf-32 representation
     */
    IDRS_UINT utf32_length() const;
    /**
     * \brief Returns the string length in its utf-8 representation
     *
     * \returns length of the string in its utf-8 representation
     */
    inline IDRS_UINT size() const;
    /**
     * \brief Returns the string length in its utf-32 representation
     *
     * \returns length of the string in utf-32
     */
    inline IDRS_UINT utf32_size() const;
    /**
     * \brief Checks wheter the string is empty
     *
     * \return 'IDRS_TRUE' if the string is empty 'IDRS_FALSE' otherwise.
     */
    IDRS_BOOL empty() const;
    /**
     * \brief Compares this string to another one
     *
     * \param argOther Other string to compare to.
     *
     * \retval < 0 This string appears first in lexicographical order
     * \retval > 0 This string appears second in lexicographical order
     * \retval 0 Both strings are equal
     */
    IDRS_INT compare( const idrs_string &argOther ) const;
    /**
     * \brief Checks if this string starts with the given prefix.
     *
     * \param strPrefix Prefix to check for
     *
     * \return 'IDRS_TRUE' if the prefix is found, 'IDRS_FALSE' otherwise.
     */
    IDRS_BOOL starts_with( const idrs_string &strPrefix ) const;
    /**
     * \brief Check if this string ends with the given suffix
     *
     * \param strSuffix Suffix to check for
     *
     * \return 'IDRS_TRUE' if the suffix is found, 'IDRS_FALSE' otherwise.
     */
    IDRS_BOOL ends_with( const idrs_string &strSuffix ) const;
    /**
     * \brief Finds the position of the first occurrence of the given substring
     * 
     * \param strValue The value to search for
     * \param iOffset The index where to start searching
     * 
     * \return If found, the index of the substring. idrs_string::npos otherwise.
     */
    IDRS_INT find( const idrs_string &strValue, const IDRS_INT iOffset = 0 ) const;
    /**
     * \brief Finds the position of the last occurrence of the given substring
     *
     * \param strValue The value to search for
     * \param iOffset The index from the start of the string where to start searching
     *
     * \return If found, the index of the substring. idrs_string::npos otherwise.
     */
    IDRS_INT rfind( const idrs_string &strValue, const IDRS_INT iOffset = npos ) const;
    /**
     * \brief Returns the specified substring 
     *
     * \param iPosition Position of the first character to be taken
     * \param iCount Length of the substring, or idrs_string::npos to get all remaining chars
     * 
     * \return A new string containing the extracted substring.
     */
    idrs_string substr( const IDRS_INT iPosition, const IDRS_INT iCount = npos ) const;
    /**
     * \brief Append a string to the end of this string
     *
     * \param argOther The string to append
     * \return Reference to this string
     */
    idrs_string &append( const idrs_string &argOther );
    /**
     * \brief Concatenation operator taking one idrs_string operand
     * 
     * \param argOther The string to append
     * \return Reference to this string
     */
    inline idrs_string &operator+=( const idrs_string &argOther );
  private:
    //! The internal data object
    idrs_string_data *m_objStringData;
  };
  /*
   *
   */
  inline idrs_string::utf8_reference idrs_string::operator[]( const IDRS_UINT uiIndex )
  {
    return at( uiIndex );
  }
  /*
   *
   */
  inline idrs_string::const_utf8_reference idrs_string::operator[]( const IDRS_UINT uiIndex ) const
  {
    return at( uiIndex );
  }
  /*
   *
   */
  inline idrs_string &idrs_string::assign( const utf8_type *argBuffer )
  {
    return assign( argBuffer, 0 /* auto */ );
  }
  /*
   *
   */
  inline idrs_string &idrs_string::assign( const utf32_type *argBuffer )
  {
    return assign( argBuffer, 0 /* auto */ );
  }
  /*
   *
   */
  inline idrs_string &idrs_string::operator=( const idrs_string &argOther )
  {
    return assign( argOther );
  }
  /*
   *
   */
  inline idrs_string &idrs_string::operator=( const utf8_type *argBuffer )
  {
    return assign( argBuffer, 0 /* auto */ );
  }
  /*
   *
   */
  inline idrs_string &idrs_string::operator=( const utf32_type *argBuffer )
  {
    return assign( argBuffer, 0 /* auto */ );
  }
  /*
   *
   */
  inline IDRS_UINT idrs_string::size() const
  {
    return length();
  }
  /*
   *
   */
  inline IDRS_UINT idrs_string::utf32_size() const
  {
    return utf32_length();
  }
  /*
   *
   */
  inline idrs_string &idrs_string::operator+=( const idrs_string &argOther )
  {
    return append( argOther );
  }

  /*
   * Non-member operators
   */

  /*
   *
   */
  inline idrs_string operator+( const idrs_string &argLeft, const idrs_string &argRight )
  {
    idrs_string objDestination( argLeft );
    objDestination += argRight;
    return objDestination;
  }
  /*
   *
   */
  inline idrs_string operator+( const idrs_string &argLeft, const idrs_string::utf8_type *argRight )
  {
    idrs_string objDestination( argLeft );
    objDestination += argRight;
    return objDestination;
  }
  /*
   *
   */
  inline idrs_string operator+( const idrs_string &argLeft, const idrs_string::utf32_type *argRight )
  {
    idrs_string objDestination( argLeft );
    objDestination += argRight;
    return objDestination;
  }
  /*
   *
   */
  inline idrs_string operator+( const idrs_string::utf8_type *argLeft, const idrs_string &argRight )
  {
    idrs_string objDestination( argLeft );
    objDestination += argRight;
    return objDestination;
  }
  /*
   *
   */
  inline idrs_string operator+( const idrs_string::utf32_type *argLeft, const idrs_string &argRight )
  {
    idrs_string objDestination( argLeft );
    objDestination += argRight;
    return objDestination;
  }
  /*
   * 
   */
  inline IDRS_BOOL operator==( const idrs_string &argLeft, const idrs_string &argRight )
  {
    return argLeft.compare( argRight ) == 0 ? IDRS_TRUE : IDRS_FALSE;
  }
  /*
   *
   */
  inline IDRS_BOOL operator==( const idrs_string &argLeft, const idrs_string::utf8_type *argRight )
  {
    return argLeft.compare( argRight ) == 0 ? IDRS_TRUE : IDRS_FALSE;
  }
  /*
   *
   */
  inline IDRS_BOOL operator==( const idrs_string &argLeft, const idrs_string::utf32_type *argRight )
  {
    return argLeft.compare( argRight ) == 0 ? IDRS_TRUE : IDRS_FALSE;
  }
  /*
   *
   */
  inline IDRS_BOOL operator==( const idrs_string::utf8_type *argLeft, const idrs_string &argRight )
  {
    return argRight.compare( argLeft ) == 0 ? IDRS_TRUE : IDRS_FALSE;
  }
  /*
   *
   */
  inline IDRS_BOOL operator==( const idrs_string::utf32_type *argLeft, const idrs_string &argRight )
  {
    return argRight.compare( argLeft ) == 0 ? IDRS_TRUE : IDRS_FALSE;
  }
  /*
   * 
   */
  inline IDRS_BOOL operator!=( const idrs_string &argLeft, const idrs_string &argRight )
  {
    return argLeft.compare( argRight ) == 0 ? IDRS_FALSE : IDRS_TRUE;
  }
  /*
   *
   */
  inline IDRS_BOOL operator!=( const idrs_string &argLeft, const idrs_string::utf8_type *argRight )
  {
    return argLeft.compare( argRight ) == 0 ? IDRS_FALSE : IDRS_TRUE;
  }
  /*
   *
   */
  inline IDRS_BOOL operator!=( const idrs_string &argLeft, const idrs_string::utf32_type *argRight )
  {
    return argLeft.compare( argRight ) == 0 ? IDRS_FALSE : IDRS_TRUE;
  }
  /*
   *
   */
  inline IDRS_BOOL operator!=( const idrs_string::utf8_type *argLeft, const idrs_string &argRight )
  {
    return argRight.compare( argLeft ) == 0 ? IDRS_FALSE : IDRS_TRUE;
  }
  /*
   *
   */
  inline IDRS_BOOL operator!=( const idrs_string::utf32_type *argLeft, const idrs_string &argRight )
  {
    return argRight.compare( argLeft ) == 0 ? IDRS_FALSE : IDRS_TRUE;
  }
  /*
   *
   */
  inline IDRS_BOOL operator<( const idrs_string &argLeft, const idrs_string &argRight )
  {
    return argLeft.compare( argRight ) < 0 ? IDRS_TRUE : IDRS_FALSE;
  }
  /*
   *
   */
  inline IDRS_BOOL operator<( const idrs_string &argLeft, const idrs_string::utf8_type *argRight )
  {
    return argLeft.compare( argRight ) < 0 ? IDRS_TRUE : IDRS_FALSE;
  }
  /*
   *
   */
  inline IDRS_BOOL operator<( const idrs_string &argLeft, const idrs_string::utf32_type *argRight )
  {
    return argLeft.compare( argRight ) < 0 ? IDRS_TRUE : IDRS_FALSE;
  }
  /*
   *
   */
  inline IDRS_BOOL operator<( const idrs_string::utf8_type *argLeft, const idrs_string &argRight )
  {
    return argRight.compare( argLeft ) > 0 ? IDRS_TRUE : IDRS_FALSE;
  }
  /*
   *
   */
  inline IDRS_BOOL operator<( const idrs_string::utf32_type *argLeft, const idrs_string &argRight )
  {
    return argRight.compare( argLeft ) > 0 ? IDRS_TRUE : IDRS_FALSE;
  }
  /*
   *
   */
  inline IDRS_BOOL operator<=( const idrs_string &argLeft, const idrs_string &argRight )
  {
    return argLeft.compare( argRight ) <= 0 ? IDRS_TRUE : IDRS_FALSE;
  }
  /*
   *
   */
  inline IDRS_BOOL operator<=( const idrs_string &argLeft, const idrs_string::utf8_type *argRight )
  {
    return argLeft.compare( argRight ) <= 0 ? IDRS_TRUE : IDRS_FALSE;
  }
  /*
   *
   */
  inline IDRS_BOOL operator<=( const idrs_string &argLeft, const idrs_string::utf32_type *argRight )
  {
    return argLeft.compare( argRight ) <= 0 ? IDRS_TRUE : IDRS_FALSE;
  }
  /*
   *
   */
  inline IDRS_BOOL operator<=( const idrs_string::utf8_type *argLeft, const idrs_string &argRight )
  {
    return argRight.compare( argLeft ) >= 0 ? IDRS_TRUE : IDRS_FALSE;
  }
  /*
   *
   */
  inline IDRS_BOOL operator<=( const idrs_string::utf32_type *argLeft, const idrs_string &argRight )
  {
    return argRight.compare( argLeft ) >= 0 ? IDRS_TRUE : IDRS_FALSE;
  }
  /*
   *
   */
  inline IDRS_BOOL operator>( const idrs_string &argLeft, const idrs_string &argRight )
  {
    return argLeft.compare( argRight ) > 0 ? IDRS_TRUE : IDRS_FALSE;
  }
  /*
   *
   */
  inline IDRS_BOOL operator>( const idrs_string &argLeft, const idrs_string::utf8_type *argRight )
  {
    return argLeft.compare( argRight ) > 0 ? IDRS_TRUE : IDRS_FALSE;
  }
  /*
   *
   */
  inline IDRS_BOOL operator>( const idrs_string &argLeft, const idrs_string::utf32_type *argRight )
  {
    return argLeft.compare( argRight ) > 0 ? IDRS_TRUE : IDRS_FALSE;
  }
  /*
   *
   */
  inline IDRS_BOOL operator>( const idrs_string::utf8_type *argLeft, const idrs_string &argRight )
  {
    return argRight.compare( argLeft ) < 0 ? IDRS_TRUE : IDRS_FALSE;
  }
  /*
   *
   */
  inline IDRS_BOOL operator>( const idrs_string::utf32_type *argLeft, const idrs_string &argRight )
  {
    return argRight.compare( argLeft ) < 0 ? IDRS_TRUE : IDRS_FALSE;
  }
  /*
   *
   */
  inline IDRS_BOOL operator>=( const idrs_string &argLeft, const idrs_string &argRight )
  {
    return argLeft.compare( argRight ) >= 0 ? IDRS_TRUE : IDRS_FALSE;
  }
  /*
   *
   */
  inline IDRS_BOOL operator>=( const idrs_string &argLeft, const idrs_string::utf8_type *argRight )
  {
    return argLeft.compare( argRight ) >= 0 ? IDRS_TRUE : IDRS_FALSE;
  }
  /*
   *
   */
  inline IDRS_BOOL operator>=( const idrs_string &argLeft, const idrs_string::utf32_type *argRight )
  {
    return argLeft.compare( argRight ) >= 0 ? IDRS_TRUE : IDRS_FALSE;
  }
  /*
   *
   */
  inline IDRS_BOOL operator>=( const idrs_string::utf8_type *argLeft, const idrs_string &argRight )
  {
    return argRight.compare( argLeft ) <= 0 ? IDRS_TRUE : IDRS_FALSE;
  }
  /*
   *
   */
  inline IDRS_BOOL operator>=( const idrs_string::utf32_type *argLeft, const idrs_string &argRight )
  {
    return argRight.compare( argLeft ) <= 0 ? IDRS_TRUE : IDRS_FALSE;
  }

} // IDRS namespace

#endif // _idrs_string_h_
