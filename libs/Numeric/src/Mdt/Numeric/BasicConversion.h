// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtNumeric
 ** Set of helpers for basic numeric operations.
 **
 ** Copyright (C) 2023-2023 Philippe Steinmann.
 **
 *****************************************************************************************/
#ifndef MDT_NUMERIC_BASIC_CONVERSION_H
#define MDT_NUMERIC_BASIC_CONVERSION_H

#include "Mdt/Numeric/Limits.h"
#include "mdt_numeric_export.h"
#include <cstdint>
#include <cstddef>
#include <cassert>

namespace Mdt{ namespace Numeric{

  /*! \brief Get an int from a given value of type std::size_t
   *
   * \pre An int must be able to hold given value
   * \sa int_canHoldValueOf_size_t()
   * \sa int_from_size_t_checked()
   */
  inline
  constexpr
  int int_from_size_t(std::size_t s) noexcept
  {
    assert( int_canHoldValueOf_size_t(s) );

    return static_cast<int>(s);
  }

  /*! \brief Throw an std::overflow_error
   */
  MDT_NUMERIC_EXPORT
  void throw_int_from_size_t_overflow_error(std::size_t s);

  /*! \brief Get an int from a given value of type std::size_t
   *
   * \exception std::overflow_error
   * \sa int_canHoldValueOf_size_t()
   * \sa int_from_size_t()
   */
  inline
  int int_from_size_t_checked(std::size_t s)
  {
    if( !int_canHoldValueOf_size_t(s) ){
      throw_int_from_size_t_overflow_error(s);
    }

    return int_from_size_t(s);
  }

  /*! \brief Get a std::size_t from a value of type int
   *
   * \pre Given value must be >= 0
   */
  inline
  constexpr
  std::size_t size_t_from_int(int i) noexcept
  {
    assert( i >= 0 );

    return static_cast<std::size_t>(i);
  }

  /*! \brief Get an int from a given value of type T
   *
   * \pre An int must be able to hold given value
   * \sa int_canHoldValueOf_T()
   */
  template<typename T>
  constexpr
  int int_from_T(T value) noexcept
  {
    assert( int_canHoldValueOf_T(value) );

    return static_cast<int>(value);
  }

}} // namespace Mdt{ namespace Numeric{

#endif // #ifndef MDT_NUMERIC_BASIC_CONVERSION_H
