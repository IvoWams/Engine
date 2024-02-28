#ifndef ENGINE_SCRIPT_PARSER_EXCEPTION_PARSE_EXCEPTION_H
#define ENGINE_SCRIPT_PARSER_EXCEPTION_PARSE_EXCEPTION_H

#include "Exception.h"

namespace engine::script::parser::exception
{
    struct ParseException : Exception
    {
        ParseException(std::string message): Exception("Unable to parse: " + message){}
    };
}

#endif