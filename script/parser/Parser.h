#ifndef APP_SCRIPT_PARSER_PARSER_H
#define APP_SCRIPT_PARSER_PARSER_H

#include <string>
#include <vector>
#include "AbstractParser.h"
#include "Tokenizer.h"

namespace app::script::parser
{
    struct Parser : AbstractParser
    {
            

        void parse(std::string data);

        void parseString(const Tokenizer& tokenizer);
        void parseValue(const Tokenizer& tokenizer);
        void parseInteger(const Tokenizer& tokenizer);
        std::vector<std::string>* parseValue(Tokenizer& tokenizer);
        std::vector<int>* convertToInts(std::vector<std::string>& values);

    };
}


#endif