#ifndef ENGINE_SCRIPT_PARSER_NUMBER_H
#define ENGINE_SCRIPT_PARSER_NUMBER_H

#include "AtomicParser.h"

namespace engine::script::parser
{
    struct Number : AtomicParser
    {
        Number(Tokenizer* _tokenizer) : AtomicParser(_tokenizer){}

        std::string autocontext()
        {
            return "Number";
        }

        Token* parse()
        {
            tokenizer->trim();
            int eow = tokenizer->tokens.find_first_not_of("1234567890-.");
            if (eow == 0) {
                throw SyntaxError("No numeric characters found");
            }
            
            auto result = new Token(autocontext(), tokenizer->read(eow));
            tokenizer->move(1 + eow);
            return result;
        }
    };
}

#endif