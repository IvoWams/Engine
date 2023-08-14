#ifndef ENGINE_SCRIPT_PARSER_FUNCTION_DECLARATION_H
#define ENGINE_SCRIPT_PARSER_FUNCTION_DECLARATION_H

#include "AbstractParser.h"
#include <vector>

#include "ReturnType.h"
#include "FunctionName.h"
#include "ParameterDeclarationList.h"

namespace engine::script::parser
{
    struct FunctionDeclaration : AtomicParser
    {
        FunctionDeclaration(Tokenizer *tokenizer) : AtomicParser(tokenizer) {}

        ReturnType returnType { tokenizer };
        FunctionName functionName { tokenizer };
        ParameterDeclarationList parameterDeclarationList { tokenizer };
        // FunctionContent functionContent { tokenizer };

        bool parse()
        {
            // <returnType> <functionName> <parameterDeclaration>
                
            if (! returnType.parse()) return false;
            if (! functionName.parse()) return false;
            if (! parameterDeclarationList.parse()) return false;
            // if (! functionContent.parse()) return false;
        }
    };
}

#endif