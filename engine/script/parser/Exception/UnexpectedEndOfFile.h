#ifndef ENGINE_SCRIPT_PARSER_EXCEPTION_PARSER_EXCEPTION_H
#define ENGINE_SCRIPT_PARSER_EXCEPTION_PARSER_EXCEPTION_H

#include <iostream>
#include "../Tokenizer.h"

namespace engine::script::parser::exception
{
    struct UnexpectedEndOfFile : public std::exception
    {
        UnexpectedEndOfFile(engine::script::parser::Tokenizer *tokenizer) : std::exception("Unexpected en of file") {}
    };
}

#endif
