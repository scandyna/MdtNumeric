// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtNumeric
 ** Set of helpers for basic numeric operations.
 **
 ** Copyright (C) 2023-2023 Philippe Steinmann.
 **
 *****************************************************************************************/
#ifndef MDT_CATCH2_QSTRING_H
#define MDT_CATCH2_QSTRING_H

#include <QString>
#include <ostream>

std::ostream & operator <<(std::ostream & os, const QString & str);

#endif // #ifndef MDT_CATCH2_QSTRING_H
