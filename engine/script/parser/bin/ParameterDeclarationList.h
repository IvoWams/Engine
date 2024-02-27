#ifndef ENGINE_SCRIPT_PARSER_PARAMETERLIST_H
#define ENGINE_SCRIPT_PARSER_PARAMETERLIST_H

#include "AbstractParser.h"
#include "ParameterDeclaration.h"
#include "Repeatable.h"

namespace engine::script::parser
{
    struct ParameterDeclarationList : AtomicParser
    {
        ParameterDeclarationList(Tokenizer *tokenizer) : AtomicParser(tokenizer) {}

        Repeatable<ParameterDeclaration> parameterDeclarations { tokenizer };

        bool parse()
        {
            // ( <parameter-declaration> { <comma> <parameter-declaration> })

            tokenizer->trim();
            tokenizer->expect("(");
            tokenizer->move(1);
            
            parameterDeclarations.parse();

            tokenizer->trim();
            tokenizer->expect(")");
            tokenizer->move(1);
        }
    };
}

#endif