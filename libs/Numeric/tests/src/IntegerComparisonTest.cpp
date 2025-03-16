// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtNumeric
 ** Set of helpers for basic numeric operations.
 **
 ** Copyright (C) 2025-2025 Philippe Steinmann.
 **
 *****************************************************************************************/
#include "catch2/catch.hpp"
#include "Mdt/Numeric/IntegerComparison.h"
#include <limits>
#include <cstdint>

using namespace Mdt::Numeric;


struct int_int
{
  int t;
  int u;
};

struct int8_int
{
  int8_t t;
  int u;
};

struct int_int8
{
  int t;
  int8_t u;
};

struct uint8_int
{
  uint8_t t;
  int u;
};

struct int_uint8
{
  int t;
  uint8_t u;
};


TEMPLATE_TEST_CASE("cmp_less_PositiveIntegers_WorkingWithAllTypes", "", int_int, int8_int, int_int8, uint8_int, int_uint8)
{
  TestType v;

  SECTION("1 is not less than 1")
  {
    v.t = 1;
    v.u = 1;

    CHECK( !cmp_less(v.t, v.u) );
    CHECK( !cmp_less(v.u, v.t) );
  }

  SECTION("0 is less than 1")
  {
    v.t = 0;
    v.u = 1;

    CHECK( cmp_less(v.t, v.u) );
    CHECK( !cmp_less(v.u, v.t) );
  }
}

TEMPLATE_TEST_CASE("cmp_less_Integers_WorkingWithAllSignedTypes", "", int_int, int8_int, int_int8)
{
  TestType v;

  SECTION("-1 is < 0")
  {
    v.t = -1;
    v.u = 0;

    CHECK( cmp_less(v.t, v.u) );
    CHECK( !cmp_less(v.u, v.t) );
  }
}

TEST_CASE("cmp_less_int8_int_limits")
{
  SECTION("int8 min is < 0")
  {
    const int8_t t = std::numeric_limits<int8_t>::min();
    const int u = 0;

    CHECK( cmp_less(t, u) );
    CHECK( !cmp_less(u, t) );
  }

  SECTION("int8 min is < -1")
  {
    const int8_t t = std::numeric_limits<int8_t>::min();
    const int u = -1;

    CHECK( cmp_less(t, u) );
    CHECK( !cmp_less(u, t) );
  }

  SECTION("int8 min is NOT < int min")
  {
    const int8_t t = std::numeric_limits<int8_t>::min();
    const int u = std::numeric_limits<int>::min();

    CHECK( !cmp_less(t, u) );
    CHECK( cmp_less(u, t) );
  }

  SECTION("25 is < int max")
  {
    const int8_t t = 25;
    const int u = std::numeric_limits<int>::max();

    CHECK( cmp_less(t, u) );
    CHECK( !cmp_less(u, t) );
  }

  SECTION("int8 max is < int max")
  {
    const int8_t t = std::numeric_limits<int8_t>::max();
    const int u = std::numeric_limits<int>::max();

    CHECK( cmp_less(t, u) );
    CHECK( !cmp_less(u, t) );
  }
}

TEST_CASE("cmp_less_int_int8_limits")
{
  SECTION("int min is < 0")
  {
    const int t = std::numeric_limits<int>::min();
    const int8_t u = 0;

    CHECK( cmp_less(t, u) );
    CHECK( !cmp_less(u, t) );
  }

  SECTION("int min is < -1")
  {
    const int t = std::numeric_limits<int>::min();
    const int8_t u = -1;

    CHECK( cmp_less(t, u) );
    CHECK( !cmp_less(u, t) );
  }

  SECTION("int min is < int8 min")
  {
    const int t = std::numeric_limits<int>::min();
    const int8_t u = std::numeric_limits<int8_t>::min();

    CHECK( cmp_less(t, u) );
    CHECK( !cmp_less(u, t) );
  }

  SECTION("26 is < int8 max")
  {
    const int t = 26;
    const int8_t u = std::numeric_limits<int8_t>::max();

    CHECK( cmp_less(t, u) );
    CHECK( !cmp_less(u, t) );
  }
}

TEST_CASE("cmp_less_uint8_int_limits")
{
  SECTION("0 is < int max")
  {
    const uint8_t t = 0;
    const int u = std::numeric_limits<int>::max();

    CHECK( cmp_less(t, u) );
    CHECK( !cmp_less(u, t) );
  }

  SECTION("uint8 max is < int max")
  {
    const uint8_t t = std::numeric_limits<uint8_t>::max();
    const int u = std::numeric_limits<int>::max();

    CHECK( cmp_less(t, u) );
    CHECK( !cmp_less(u, t) );
  }
}

TEST_CASE("cmp_less_int_uint8_limits")
{
  SECTION("int min is < 0")
  {
    const int t = std::numeric_limits<int>::min();
    const uint8_t u = 0;

    CHECK( cmp_less(t, u) );
    CHECK( !cmp_less(u, t) );
  }

  SECTION("int min is < 1")
  {
    const int t = std::numeric_limits<int>::min();
    const uint8_t u = 1;

    CHECK( cmp_less(t, u) );
    CHECK( !cmp_less(u, t) );
  }

  SECTION("int min is < uint8 max")
  {
    const int t = std::numeric_limits<int>::min();
    const uint8_t u = std::numeric_limits<uint8_t>::max();

    CHECK( cmp_less(t, u) );
    CHECK( !cmp_less(u, t) );
  }
}

TEST_CASE("cmp_less_int_int8")
{
  REQUIRE(false);
}

TEST_CASE("cmp_less_int_uint8")
{
  REQUIRE(false);
}

TEST_CASE("cmp_less_int_int")
{
  REQUIRE(false);
}

TEST_CASE("cmp_less_size_t_int")
{
  REQUIRE(false);
}

TEST_CASE("cmp_less_int_size_t")
{
  REQUIRE(false);
}
