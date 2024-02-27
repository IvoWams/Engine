#ifndef ENGINE_SCRIPT_PARSER_DECLARATION_H
#define ENGINE_SCRIPT_PARSER_DECLARATION_H

#include "AbstractParser.h"
#include "FunctionDeclaration.h"
#include <vector>

namespace engine::script::parser
{
    struct Declaration : AtomicParser
    {
        Declaration(Tokenizer *tokenizer) : AtomicParser(tokenizer) {}

        bool parse()
        {
            tokenizer->trim();
            auto firstWord = tokenizer->readWord();
            if (firstWord == "class") {
                
                return true;
            }

            else {
                FunctionDeclaration functionDeclaration { tokenizer };                
                return functionDeclaration.parse();
            }

            return false;
        }
    };
}

#endif