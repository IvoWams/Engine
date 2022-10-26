#ifndef ENGINE_SCRIPT_PARSER_PARAMETER_H
#define ENGINE_SCRIPT_PARSER_PARAMETER_H

#include "AbstractParser.h"
#include "Value.h"

namespace engine::script::parser
{
    struct Parameter : AbstractParser
    {
        std::string key;
        Value *value;

        Parameter(Tokenizer* tokenizer) : AbstractParser(tokenizer)
        {
            value = new Value(tokenizer);
        };

        bool parse()
        {
            tokenizer->trim();
            auto doublepoint = tokenizer->find(":");
            auto eol = tokenizer->find("\n");
            if (eol < doublepoint) {
                return false;
            }
            if (doublepoint == std::string::npos) {
                return false;
            }

            key = tokenizer->read(doublepoint);
            tokenizer->move(doublepoint + 1);

            if (! value->parse()) {
                return false;
            }
            
            // We're technically never "processing" the end of line, this makes sure we do:
            // tokenizer->moveLine();

            return true;
        }
    };
}

#endif
