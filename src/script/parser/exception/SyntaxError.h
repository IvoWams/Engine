#ifndef ENGINE_SCRIPT_PARSER_EXCEPTION_SYNTAX_ERROR_H
#define ENGINE_SCRIPT_PARSER_EXCEPTION_SYNTAX_ERROR_H

#include "Exception.h"

namespace engine::script::parser::exception
{
    struct SyntaxError : Exception
    {
        SyntaxError(std::string message): Exception("Syntax Error: " + message){}
    };
}

#endif