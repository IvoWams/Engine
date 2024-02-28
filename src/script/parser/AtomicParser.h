#ifndef ENGINE_SCRIPT_PARSER_ATOMICPARSER_H
#define ENGINE_SCRIPT_PARSER_ATOMICPARSER_H

#include "Tokenizer.h"
#include "Token.h"

namespace engine::script::parser
{
    struct AtomicParser
    {
        Tokenizer *tokenizer;

        AtomicParser(Tokenizer *_tokenizer)
        {
            tokenizer = _tokenizer;
        }

        virtual Token* parse() = 0;

        std::string getName()
        {
            return autocontext();
        }

        std::string autocontext()
        {
            return typeid(this).name();
        }
    };
}

#endif