// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtNumeric
 ** Set of helpers for basic numeric operations.
 **
 ** Copyright (C) 2024-2024 Philippe Steinmann.
 **
 *****************************************************************************************/
#include <Mdt/Numeric/BasicConversion.h>
#include <iostream>

int main()
{
  const int value = Mdt::Numeric::int_from_size_t_checked(26);

  std::cout << "value: " << value << std::endl;

  return 0;
}
