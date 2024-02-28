#ifndef ENGINE_SCRIPT_PARSER_BOOL_H
#define ENGINE_SCRIPT_PARSER_BOOL_H

#include "AtomicParser.h"
#include "exception/ParseException.h"
#include "Tokenizer.h"

using namespace engine::script::parser::exception;

namespace engine::script::parser
{
    struct Bool : AtomicParser
    {
        Bool(Tokenizer* _tokenizer) : AtomicParser(_tokenizer){}

        std::string autocontext()
        {
            return "Bool";
        }

        Token* parse()
        {
            tokenizer->trim();
            int eow = tokenizer->tokens.find_first_of(",; \t\n");
            auto result = new Token(autocontext(), tokenizer->read(eow));
            if (result->value != "true" && result->value != "false") {
                throw ParseException("Boolean needs to be either 'true' or 'false'");
            } else {
                tokenizer->move(1 + eow);
                return result;
            }
        }
    };
}

#endif