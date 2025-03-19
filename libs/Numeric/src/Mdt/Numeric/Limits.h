// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtNumeric
 ** Set of helpers for basic numeric operations.
 **
 ** Copyright (C) 2023-2025 Philippe Steinmann.
 **
 *****************************************************************************************/
#ifndef MDT_NUMERIC_LIMITS_H
#define MDT_NUMERIC_LIMITS_H

#include <cstdint>
#include <cstddef>
#include <limits>
#include <type_traits>

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
   *
   * \pre \a value must be an integral type
   */
  template<typename T>
  constexpr
  bool int_canHoldValueOf_T(T value) noexcept
  {
    static_assert(std::is_integral_v<T>, "Mdt::Numeric::int_canHoldValueOf_T(T value): given value must be an integral type");

    if constexpr(std::is_unsigned_v<T>){
      // value can't be < 0
      return value <= std::numeric_limits<int>::max();
    }else{
      return ( value >= std::numeric_limits<int>::min() ) && ( value <= std::numeric_limits<int>::max() );
    }
  }

  /*! \brief Check if given int value can be represented for an integer of type T
   *
   * \pre \a T must be an integral type
   */
  template<typename T>
  constexpr
  bool T_canHoldValueOf_int(int value) noexcept
  {
    static_assert(std::is_integral_v<T>, "Mdt::Numeric::T_canHoldValueOf_int(T value): given value must be an integral type");

    if constexpr(std::is_unsigned_v<T>){
      return (value >= 0 ) && ( std::make_unsigned_t<int>(value) <= std::numeric_limits<T>::max() );
    }else{
      return ( value >= std::numeric_limits<T>::min() ) && ( value <= std::numeric_limits<T>::max() );
    }
  }

  /*! \brief Check if integers \a a and \a b can be added
   *
   * Returns true if \a a and \a b can be added without an overflow
   *
   * \sa https://github.com/cplusplus/papers/issues/393
   */
  inline
  constexpr
  bool canAdd(int a, int b) noexcept
  {
    if( (b > 0) && (a > std::numeric_limits<int>::max() - b) ){
      return false;
    }
    if( (b < 0) && (a < std::numeric_limits<int>::min() - b) ){
      return false;
    }
    return true;
  }

}} // namespace Mdt{ namespace Numeric{

#endif // #ifndef MDT_NUMERIC_LIMITS_H
