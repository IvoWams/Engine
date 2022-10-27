#ifndef ENGINE_SCRIPT_PARSER_PARAMETER_NAME_H
#define ENGINE_SCRIPT_PARSER_PARAMETER_NAME_H

#include "BasicName.h"

namespace engine::script::parser
{
    struct ParameterName : BasicName
    {
        ParameterName(Tokenizer *tokenizer) : BasicName(tokenizer) {}
    };
}

#endif