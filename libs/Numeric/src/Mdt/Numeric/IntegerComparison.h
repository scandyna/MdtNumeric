// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtNumeric
 ** Set of helpers for basic numeric operations.
 **
 ** Copyright (C) 2025-2025 Philippe Steinmann.
 **
 *****************************************************************************************/
#ifndef MDT_NUMERIC_INTEGER_COMPARISON_H
#define MDT_NUMERIC_INTEGER_COMPARISON_H

#include <type_traits>

namespace Mdt{ namespace Numeric{

  /*! \brief Returns true if t is less than u
   *
   * \pre \a t and \a u must be integer types
   * \sa https://en.cppreference.com/w/cpp/utility/intcmp
   */
  template<typename T, typename U>
  constexpr
  bool cmp_less(T t, U u) noexcept
  {
    static_assert(std::is_integral_v<T>, "Mdt::Numeric::cmp_less(): given value t must be an integral type");
    static_assert(!std::is_same_v<T, bool>, "Mdt::Numeric::cmp_less(): given value t must be an integral type (not bool)");
    static_assert(!std::is_same_v<T, char>, "Mdt::Numeric::cmp_less(): given value t must be an integral type (not char)");
    static_assert(std::is_integral_v<U>, "Mdt::Numeric::cmp_less(): given value u must be an integral type");
    static_assert(!std::is_same_v<U, bool>, "Mdt::Numeric::cmp_less(): given value u must be an integral type (not bool)");
    static_assert(!std::is_same_v<U, char>, "Mdt::Numeric::cmp_less(): given value u must be an integral type (not char)");

    if constexpr(std::is_signed_v<T> == std::is_signed_v<U>){
      return t < u;
    }else if constexpr(std::is_signed_v<T>){
      return t < 0 || std::make_unsigned_t<T>(t) < u;
    }else{
      return u >= 0 && t < std::make_unsigned_t<U>(u);
    }
  }

}} // namespace Mdt{ namespace Numeric{

#endif // #ifndef MDT_NUMERIC_INTEGER_COMPARISON_H
