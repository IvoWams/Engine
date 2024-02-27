#ifndef ENGINE_SCRIPT_PARSER_EXCEPTION_EXCEPTION_H
#define ENGINE_SCRIPT_PARSER_EXCEPTION_EXCEPTION_H

#include <exception>
#include <string>

namespace engine::script::parser::exception
{
    struct Exception : public std::exception
    {
        Exception(std::string _message)
        {
            message = _message;
        }

        std::string message;
    };
}

#endif