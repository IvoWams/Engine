#ifndef ENGINE_SCRIPT_PARSER_FUNCTION_NAME_H
#define ENGINE_SCRIPT_PARSER_FUNCTION_NAME_H

#include "BasicName.h"

namespace engine::script::parser
{
    struct FunctionName : BasicName
    {
        FunctionName(Tokenizer *tokenizer) : BasicName(tokenizer) {}
    };
}

#endif