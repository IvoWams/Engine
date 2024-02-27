#ifndef ENGINE_SCRIPT_PARSER_PARAMETER_DEFAULT_VALUE_H
#define ENGINE_SCRIPT_PARSER_PARAMETER_DEFAULT_VALUE_H

#include "AbstractParser.h"

namespace engine::script::parser
{
    struct ParameterDefaultValue : AtomicParser
    {
        ParameterDefaultValue(Tokenizer *tokenizer) : AtomicParser(tokenizer) {}

        // TODO
        bool parse()
        {
            return true;
        }
    };
}

#endif