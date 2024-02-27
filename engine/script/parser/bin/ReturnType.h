#ifndef ENGINE_SCRIPT_PARSER_RETURN_TYPE_H
#define ENGINE_SCRIPT_PARSER_RETURN_TYPE_H

#include "BasicType.h"

namespace engine::script::parser
{
    struct ReturnType : BasicType
    {
        ReturnType(Tokenizer *tokenizer): BasicType(tokenizer) {}
    };
}

#endif
