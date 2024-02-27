#ifndef ENGINE_SCRIPT_PARSER_PARAMETER_DECLARATION_H
#define ENGINE_SCRIPT_PARSER_PARAMETER_DECLARATION_H

#include "AbstractParser.h"
#include "ParameterType.h"
#include "ParameterName.h"
#include "ParameterDefaultValue.h"

namespace engine::script::parser
{
    struct ParameterDeclaration : AtomicParser
    {
        ParameterDeclaration(Tokenizer *tokenizer) : AtomicParser(tokenizer) {}

        ParameterType parameterType { tokenizer };
        ParameterName parameterName { tokenizer };
        ParameterDefaultValue parameterDefaultValue { tokenizer };

        bool parse()
        {
            tokenizer->trim();

            if (! parameterType.parse()) return false;
            if (! parameterName.parse()) return false;
            if (! parameterDefaultValue.parse()) return false;

            return true;
        }
    };
}

#endif