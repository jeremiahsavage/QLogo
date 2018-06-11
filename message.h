#ifndef MESSAGE_H
#define MESSAGE_H

//===-- qlogo/message.h - Message class definition -------*- C++ -*-===//
//
// This file is part of QLogo.
//
// QLogo is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// QLogo is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with QLogo.  If not, see <http://www.gnu.org/licenses/>.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declarations of the Message functions, which are the
/// mechanism that assembles and disassembles messages passed between the
/// Kernel and MainWindow.
///
//===----------------------------------------------------------------------===//
#include <QString>

enum MessageCommandChar : char {
    C_CONSOLE_PRINT_STRING,
    C_CONSOLE_SET_TEXT_SIZE,
    C_CONSOLE_SET_CURSOR_POS,
    C_CONSOLE_SET_TEXT_COLOR,
    C_CONSOLE_CLEAR_TEXT,
    C_CONSOLE_SET_FONT,
    C_CONSOLE_REQUEST_CHARACTER,
    C_CONSOLE_REQUEST_LINE,
    C_CONSOLE_REQUEST_CURSOR_POS,
    C_CANVAS_SET_TURTLE_POS
};

/// Create a printable string from a message.
const QString consolePrintStringFromMessage(const QByteArray message);

/// Create a C_CONSOLE_PRINT_STRING message from a QString.
///
/// The format of the message is:
///  * int length (as reported by QString::size)
///  * QChar* data (as returned by QString::constData)
const QByteArray messageFromConsolePrintString(const QString str);

/// Retrieve double from a C_CONSOLE_SET_TEXT_SIZE message.
double consoleSetTextSizeFromMessage(const QByteArray message);

/// Create a C_CONSOLE_SET_TEXT_SIZE message from a double.
///
/// The format of the message is:
///  * double size
const QByteArray messageFromConsoleSetTextSize(double size);

#endif // MESSAGE_H