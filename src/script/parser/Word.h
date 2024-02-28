#ifndef ENGINE_SCRIPT_PARSER_WORD_H
#define ENGINE_SCRIPT_PARSER_WORD_H

#include "AtomicParser.h"
#include "Tokenizer.h"
#include "Token.h"

namespace engine::script::parser
{
    struct Word : AtomicParser
    {
        Word(Tokenizer* _tokenizer) : AtomicParser(_tokenizer){}

        std::string autocontext()
        {
            return "Word";
        }

        Token* parse()
        {
            tokenizer->trim();
            int eow = tokenizer->tokens.find_first_of(",; \t\n");
            if (eow == std::string::npos) {
                eow = tokenizer->left() - 1;
            }
            auto result = new Token(autocontext(), tokenizer->read(eow));
            tokenizer->move(1 + eow);
            return result;
        }
    };
}

#endif