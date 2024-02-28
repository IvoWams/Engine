#ifndef ENGINE_SCRIPT_PARSER_PARAMETER_TYPE_H
#define ENGINE_SCRIPT_PARSER_PARAMETER_TYPE_H

#include "BasicType.h"

namespace engine::script::parser
{
    struct ParameterType : BasicType
    {
        ParameterType(Tokenizer *tokenizer): BasicType(tokenizer) {}
    };
}

#endif
