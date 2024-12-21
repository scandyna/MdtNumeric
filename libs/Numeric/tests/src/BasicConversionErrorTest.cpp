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


TEST_CASE("int_from_size_t_checked")
{
  SECTION("int max + 1")
  {
    constexpr std::size_t value = std::numeric_limits<int>::max() + static_cast<std::size_t>(1);

    REQUIRE_THROWS_AS( int_from_size_t_checked(value), std::overflow_error );
  }
}
