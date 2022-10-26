#ifndef ENGINE_SCRIPT_PARSER_VALUE_H
#define ENGINE_SCRIPT_PARSER_VALUE_H

#include "Tokenizer.h"
#include "AbstractParser.h"
#include <vector>
#include <algorithm>

namespace engine::script::parser
{
    struct Value : AbstractParser
    {
        Value(Tokenizer *tokenizer) : AbstractParser(tokenizer) {};

        std::vector<std::string> values;

        bool parse()
        {
            int eol, nextvalue, min;

            do {
                eol = tokenizer->find("\n");
                nextvalue = tokenizer->find(",");
                min = std::min(eol, nextvalue);
                auto token = tokenizer->read(min);
                values.push_back(token);
                tokenizer->move(min + 1);
            } while (nextvalue < eol);

            return true;
        }
    };
}

#endif