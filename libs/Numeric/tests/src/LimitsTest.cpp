// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtNumeric
 ** Set of helpers for basic numeric operations.
 **
 ** Copyright (C) 2023-2025 Philippe Steinmann.
 **
 *****************************************************************************************/
#include "catch2/catch.hpp"
#include "Mdt/Numeric/Limits.h"
#include <limits>
#include <cstdint>
#include <cstddef>

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

  SECTION("int min - 1")
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

TEST_CASE("int_canHoldValueOf_T_size_t")
{
  SECTION("0")
  {
    std::size_t value = 0;

    REQUIRE( int_canHoldValueOf_T(value) );
  }

  SECTION("1")
  {
    std::size_t value = 1;

    REQUIRE( int_canHoldValueOf_T(value) );
  }

  SECTION("int max")
  {
    std::size_t intMax = std::numeric_limits<int>::max();

    REQUIRE( int_canHoldValueOf_T(intMax) );
  }

  SECTION("int max + 1")
  {
    std::size_t value = std::numeric_limits<int>::max() + static_cast<std::size_t>(1);

    REQUIRE( !int_canHoldValueOf_T(value) );
  }
}

TEST_CASE("T_canHoldValueOf_int_int8")
{
  SECTION("0")
  {
    const int value = 0;

    CHECK( T_canHoldValueOf_int<int8_t>(value) );
  }

  SECTION("1")
  {
    const int value = 1;

    CHECK( T_canHoldValueOf_int<int8_t>(value) );
  }

  SECTION("int8 max")
  {
    const int value = std::numeric_limits<int8_t>::max();

    CHECK( T_canHoldValueOf_int<int8_t>(value) );
  }

  SECTION("int8 max + 1")
  {
    const int value = std::numeric_limits<int8_t>::max() + 1;

    CHECK( !T_canHoldValueOf_int<int8_t>(value) );
  }

  SECTION("int max")
  {
    const int value = std::numeric_limits<int>::max();

    CHECK( !T_canHoldValueOf_int<int8_t>(value) );
  }

  SECTION("-1")
  {
    const int value = -1;

    CHECK( T_canHoldValueOf_int<int8_t>(value) );
  }

  SECTION("int8 min")
  {
    const int value = std::numeric_limits<int8_t>::min();

    CHECK( T_canHoldValueOf_int<int8_t>(value) );
  }

  SECTION("int8 min - 1")
  {
    const int value = std::numeric_limits<int8_t>::min() - 1;

    CHECK( !T_canHoldValueOf_int<int8_t>(value) );
  }

  SECTION("int min")
  {
    const int value = std::numeric_limits<int>::min();

    CHECK( !T_canHoldValueOf_int<int8_t>(value) );
  }
}

TEST_CASE("T_canHoldValueOf_int_uint8")
{
  SECTION("0")
  {
    const int value = 0;

    CHECK( T_canHoldValueOf_int<uint8_t>(value) );
  }

  SECTION("1")
  {
    const int value = 1;

    CHECK( T_canHoldValueOf_int<uint8_t>(value) );
  }

  SECTION("uint8 max")
  {
    const int value = std::numeric_limits<uint8_t>::max();

    CHECK( T_canHoldValueOf_int<uint8_t>(value) );
  }

  SECTION("uint8 max + 1")
  {
    const int value = std::numeric_limits<uint8_t>::max() + 1;

    CHECK( !T_canHoldValueOf_int<uint8_t>(value) );
  }

  SECTION("int max")
  {
    const int value = std::numeric_limits<int>::max();

    CHECK( !T_canHoldValueOf_int<uint8_t>(value) );
  }

  SECTION("-1")
  {
    const int value = -1;

    CHECK( !T_canHoldValueOf_int<uint8_t>(value) );
  }
}

TEST_CASE("T_canHoldValueOf_int_int")
{
  SECTION("0")
  {
    const int value = 0;

    CHECK( T_canHoldValueOf_int<int>(value) );
  }

  SECTION("1")
  {
    const int value = 1;

    CHECK( T_canHoldValueOf_int<int>(value) );
  }

  SECTION("int max")
  {
    const int value = std::numeric_limits<int>::max();

    CHECK( T_canHoldValueOf_int<int>(value) );
  }

  SECTION("-1")
  {
    const int value = -1;

    CHECK( T_canHoldValueOf_int<int>(value) );
  }

  SECTION("int min")
  {
    const int value = std::numeric_limits<int>::min();

    CHECK( T_canHoldValueOf_int<int>(value) );
  }
}

TEST_CASE("T_canHoldValueOf_int_size_t")
{
  SECTION("0")
  {
    const int value = 0;

    CHECK( T_canHoldValueOf_int<std::size_t>(value) );
  }

  SECTION("1")
  {
    const int value = 1;

    CHECK( T_canHoldValueOf_int<std::size_t>(value) );
  }

  SECTION("int max")
  {
    const int value = std::numeric_limits<int>::max();

    CHECK( T_canHoldValueOf_int<std::size_t>(value) );
  }

  SECTION("-1")
  {
    const int value = -1;

    CHECK( !T_canHoldValueOf_int<std::size_t>(value) );
  }

  SECTION("int min")
  {
    const int value = std::numeric_limits<int>::min();

    CHECK( !T_canHoldValueOf_int<std::size_t>(value) );
  }
}


int addIfPossible(int a, int b)
{
  if( canAdd(a, b) ){
    return a + b;
  }
  return 0;
}

TEST_CASE("canAdd_int_int")
{
  const int intMax = std::numeric_limits<int>::max();
  const int intJustBelowHalfMax = intMax / 2;
  const int intMin = std::numeric_limits<int>::min();

  SECTION("only check if we can add")
  {
    CHECK( canAdd(0, 0) );
    CHECK( canAdd(1, 0) );
    CHECK( canAdd(0, 1) );
    CHECK( canAdd(-1, 1) );
    CHECK( canAdd(1, -1) );
    CHECK( canAdd(intMax, 0) );
    CHECK( !canAdd(intMax, 1) );
    CHECK( canAdd(intMin, 1) );
    CHECK( !canAdd(intMin, -1) );
    CHECK( canAdd(0, intMax) );
    CHECK( !canAdd(1, intMax) );
    CHECK( canAdd(1, intMin) );
    CHECK( !canAdd(-1, intMin) );
  }

  // Mistakes should be catched by UBSan
  SECTION("check and add if possible")
  {
    CHECK( addIfPossible(intMax, 0) == intMax );
    CHECK( addIfPossible(intMax, 1) == 0 );
    CHECK( addIfPossible(intMin, -1) == 0 );
    CHECK( addIfPossible(intJustBelowHalfMax, intJustBelowHalfMax) == (intMax - 1) );
    CHECK( addIfPossible(0, intMax) == intMax );
    CHECK( addIfPossible(1, intMax) == 0 );
    CHECK( addIfPossible(-1, intMin) == 0 );
  }
}
