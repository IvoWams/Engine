#ifndef ENGINE_SCRIPT_PARSER_BASIC_NAME_H
#define ENGINE_SCRIPT_PARSER_BASIC_NAME_H

#include "AbstractParser.h"

namespace engine::script::parser
{
    struct BasicName : AbstractParser
    {
        std::string name;

        BasicName(Tokenizer *tokenizer) : AbstractParser(tokenizer) {}

        bool parse()
        {
            tokenizer->trim();
            name = tokenizer->readWord();
            
            if (name != "") {
                tokenizer->move(name);
                return true;
            }

            return false;
        }
    };
}

#endif