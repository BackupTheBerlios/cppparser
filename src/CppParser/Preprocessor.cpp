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

#include <fstream>
#include <sstream>
#include <boost/wave/cpp_context.hpp>
#include <boost/wave/cpplexer/cpp_lex_iterator.hpp>
#include <boost/wave/cpplexer/cpp_lex_token.hpp>

#include "Preprocessor.h"

std::string Preprocessor::operator()(const std::string& filename)
{
    using namespace boost::wave;

    // The following preprocesses a given input file.
    // Open the file and read it into a string variable
    std::ifstream instream(filename.c_str());
    std::string input
    (
        std::istreambuf_iterator<char>(instream.rdbuf()),
        std::istreambuf_iterator<char>()
    );

    // The template boost::wave::cpplexer::lex_token<> is the
    // token type to be used by the Wave library.
    // This token type is one of the central types throughout
    // the library, because it is a template parameter to some
    // of the public classes and templates and it is returned
    // from the iterators.
    // The template boost::wave::cpplexer::lex_iterator<> is
    // the lexer iterator to use as the token source for the
    // preprocessing engine. In this case this is parametrized
    // with the token type.
    typedef cpplexer::lex_iterator<cpplexer::lex_token<> > lex_iterator_type;
    typedef context<std::string::iterator, lex_iterator_type> context_type;
    context_type ctx(input.begin(), input.end(), filename.c_str());

    ctx.set_language
    (
        language_support
        (
            support_cpp
            | support_option_include_guard_detection
            //| support_option_emit_pragma_directives
            | support_option_long_long
            | support_option_variadics
        )
    );

    // At this point you may want to set the parameters of the
    // preprocessing as include paths and/or predefined macros.
    ctx.add_sysinclude_path("/usr/include");
    ctx.add_sysinclude_path("/usr/include/");
    ctx.add_sysinclude_path("/usr/include/c++/4.3/");
    ctx.add_sysinclude_path("/usr/include/c++/4.3/i486-linux-gnu/");
    ctx.add_sysinclude_path("/usr/include/linux/");
    ctx.add_sysinclude_path("/usr/lib/gcc/i486-linux-gnu/4.3/include/");
    //ctx.add_macro_definition(...);

    // Get the preprocessor iterators and use them to generate
    // the token sequence.
    context_type::iterator_type first = ctx.begin();
    context_type::iterator_type last = ctx.end();


    std::ostringstream preprocessed_output;

    // The input stream is preprocessed for you during iteration
    // over [first, last)
    //try
    {
        for(context_type::iterator_type i = first; i != last; ++i)
        {
            preprocessed_output << (*i).get_value();
        }
    }
    /*catch(const preprocess_exception& e)
    {
        std::cout << e.description() << '\n';
        std::cout << "in " << e.file_name() << ", line " << e.line_no() << ", column " << e.column_no();
    }*/

    return preprocessed_output.str();
}
