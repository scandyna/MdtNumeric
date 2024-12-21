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
#include "Mdt/Numeric/BasicConversion.h"
#include <limits>

using namespace Mdt::Numeric;


TEST_CASE("int_from_size_t")
{
  SECTION("0")
  {
    REQUIRE( int_from_size_t(0) == 0 );
  }

  SECTION("1")
  {
    REQUIRE( int_from_size_t(1) == 1 );
  }

  SECTION("int max value")
  {
    constexpr std::size_t intMax = std::numeric_limits<int>::max();

    REQUIRE( int_from_size_t(intMax) == intMax );
  }
}

TEST_CASE("int_from_size_t_checked")
{
  SECTION("0")
  {
    REQUIRE( int_from_size_t_checked(0) == 0 );
  }

  SECTION("1")
  {
    REQUIRE( int_from_size_t_checked(1) == 1 );
  }

  SECTION("int max value")
  {
    constexpr std::size_t intMax = std::numeric_limits<int>::max();

    REQUIRE( int_from_size_t_checked(intMax) == intMax );
  }
}

TEST_CASE("size_t_from_int")
{
  SECTION("0")
  {
    REQUIRE( size_t_from_int(0) == 0 );
  }

  SECTION("1")
  {
    REQUIRE( size_t_from_int(1) == 1 );
  }

  SECTION("int max value")
  {
    constexpr std::size_t intMax = std::numeric_limits<int>::max();

    REQUIRE( size_t_from_int(intMax) == intMax );
  }
}

TEST_CASE("int_from_T_longLongInt")
{
  SECTION("0")
  {
    long long int value = 0;

    REQUIRE( int_from_T(value) == 0 );
  }

  SECTION("1")
  {
    long long int value = 1;

    REQUIRE( int_from_T(value) == 1 );
  }

  SECTION("int min value")
  {
    constexpr long long value = std::numeric_limits<int>::min();

    REQUIRE( int_from_T(value) == value );
  }

  SECTION("int max value")
  {
    constexpr long long value = std::numeric_limits<int>::max();

    REQUIRE( int_from_T(value) == value );
  }
}
