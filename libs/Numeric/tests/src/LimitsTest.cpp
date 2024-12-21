// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtNumeric
 ** Set of helpers for basic numeric operations.
 **
 ** Copyright (C) 2023-2023 Philippe Steinmann.
 **
 *****************************************************************************************/
#include "catch2/catch.hpp"
#include "Mdt/Numeric/Limits.h"
#include <limits>

using namespace Mdt::Numeric;


TEST_CASE("int_canHoldValueOf_size_t")
{
  SECTION("0")
  {
    REQUIRE( int_canHoldValueOf_size_t(0) );
  }

  SECTION("1")
  {
    REQUIRE( int_canHoldValueOf_size_t(1) );
  }

  SECTION("int max")
  {
    constexpr std::size_t intMax = std::numeric_limits<int>::max();

    REQUIRE( int_canHoldValueOf_size_t(intMax) );
  }

  SECTION("int max + 1")
  {
    constexpr std::size_t value = std::numeric_limits<int>::max() + static_cast<std::size_t>(1);

    REQUIRE( !int_canHoldValueOf_size_t(value) );
  }
}

TEST_CASE("int_canHoldValueOf_T_longLongInt")
{
  SECTION("0")
  {
    long long int value = 0;

    REQUIRE( int_canHoldValueOf_T(value) );
  }

  SECTION("1")
  {
    long long int value = 1;

    REQUIRE( int_canHoldValueOf_T(value) );
  }

  SECTION("int min")
  {
    constexpr long long int value = std::numeric_limits<int>::min();

    REQUIRE( int_canHoldValueOf_T(value) );
  }

  SECTION("int max - 1")
  {
    constexpr long long int value = std::numeric_limits<int>::min() - static_cast<long long int>(1);

    REQUIRE( !int_canHoldValueOf_T(value) );
  }

  SECTION("int max")
  {
    constexpr long long int intMax = std::numeric_limits<int>::max();

    REQUIRE( int_canHoldValueOf_T(intMax) );
  }

  SECTION("int max + 1")
  {
    constexpr long long int value = std::numeric_limits<int>::max() + static_cast<long long int>(1);

    REQUIRE( !int_canHoldValueOf_T(value) );
  }
}
