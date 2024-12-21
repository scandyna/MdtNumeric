// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtNumeric
 ** Set of helpers for basic numeric operations.
 **
 ** Copyright (C) 2023-2023 Philippe Steinmann.
 **
 *****************************************************************************************/
#ifndef MDT_NUMERIC_LIMITS_H
#define MDT_NUMERIC_LIMITS_H

#include <cstdint>
#include <cstddef>
#include <limits>

namespace Mdt{ namespace Numeric{

  /*! \brief Check if an int can represent given value of type std::size_t
   */
  inline
  constexpr
  bool int_canHoldValueOf_size_t(std::size_t s) noexcept
  {
    return s <= std::numeric_limits<int>::max();
  }

  /*! \brief Check if an int can represent given value of type T
   */
  template<typename T>
  constexpr
  bool int_canHoldValueOf_T(T value) noexcept
  {
    return ( value >= std::numeric_limits<int>::min() ) && ( value <= std::numeric_limits<int>::max() );
  }

}} // namespace Mdt{ namespace Numeric{

#endif // #ifndef MDT_NUMERIC_LIMITS_H
