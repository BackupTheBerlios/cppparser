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

#include <cppunit/ui/text/TestRunner.h>
#include "SingleDeclarationTest.h"
#include "SingleFileTest.h"
#include "SinglePreprocessingFileTest.h"

int main(int argc, char **argv)
{
	CppUnit::TextUi::TestRunner runner;

	runner.addTest(SingleDeclarationTest::suite());
	runner.addTest(SingleFileTest::suite());
	//runner.addTest(SinglePreprocessingFileTest::suite()); //takes a very long time
	runner.run();

	return 0;
}

