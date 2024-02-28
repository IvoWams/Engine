#ifndef ENGINE_SCRIPT_PARSER_BASIC_TYPE_H
#define ENGINE_SCRIPT_PARSER_BASIC_TYPE_H

#include "AbstractParser.h"

namespace engine::script::parser
{
    struct BasicType : AtomicParser
    {
        std::string type;

        BasicType(Tokenizer *tokenizer) : AtomicParser(tokenizer) {}

        bool parse()
        {
            tokenizer->trim();
            type = tokenizer->readWord();
            
            if (type != "") {
                tokenizer->move(type);
                return true;
            }

            return false;
        }
    };
}

#endif