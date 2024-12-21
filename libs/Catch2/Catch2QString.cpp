// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtNumeric
 ** Set of helpers for basic numeric operations.
 **
 ** Copyright (C) 2023-2023 Philippe Steinmann.
 **
 *****************************************************************************************/
#include "Catch2QString.h"
#include <QByteArray>

std::ostream & operator <<(std::ostream & os, const QString & str)
{
  os << str.toLocal8Bit().toStdString();

  return os;
}
