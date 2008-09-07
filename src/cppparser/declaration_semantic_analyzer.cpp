/*
CppParser - Standard C++ programming language parsing library
Copyright © 2008  Florian Goujeon

This file is part of CppParser.

CppParser is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, version 3 of the License.

CppParser is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with CppParser.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include "grammar.h"
#include "program_tree/class_.h"
#include "program_tree/union_.h"

#include "declaration_semantic_analyzer.h"

namespace cppparser
{

using namespace program_tree;

std::shared_ptr<program>
declaration_semantic_analyzer::analyze()
{
    std::shared_ptr<program> new_program(new program());

    return new_program;
}

}
