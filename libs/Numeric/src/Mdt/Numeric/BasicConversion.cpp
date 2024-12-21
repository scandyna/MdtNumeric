// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtNumeric
 ** Set of helpers for basic numeric operations.
 **
 ** Copyright (C) 2023-2023 Philippe Steinmann.
 **
 *****************************************************************************************/
#include "BasicConversion.h"
#include <stdexcept>
#include <string>

namespace Mdt{ namespace Numeric{

void throw_int_from_size_t_overflow_error(std::size_t s)
{
  const std::string msg = "int_from_size_t_checked(): cannot convert " + std::to_string(s) + " to int (value is too large)";

  throw std::overflow_error(msg);
}

}} // namespace Mdt{ namespace Numeric{
