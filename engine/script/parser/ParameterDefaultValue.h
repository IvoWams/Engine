#ifndef ENGINE_SCRIPT_PARSER_PARAMETER_DEFAULT_VALUE_H
#define ENGINE_SCRIPT_PARSER_PARAMETER_DEFAULT_VALUE_H

#include "AbstractParser.h"

namespace engine::script::parser
{
    struct ParameterDefaultValue : AbstractParser
    {
        ParameterDefaultValue(Tokenizer *tokenizer) : AbstractParser(tokenizer) {}

        // TODO
        bool parse()
        {
            return true;
        }
    };
}

#endif