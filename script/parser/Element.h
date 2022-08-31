#ifndef APP_SCRIPT_PARSER_ELEMENT_H
#define APP_SCRIPT_PARSER_ELEMENT_H

#include "AbstractParser.h"
#include "Parameters.h"
#include <vector>

namespace app::script::parser
{
    struct Element : AbstractParser
    {
        std::string type;
        std::string id;
        Parameters* parameters;

        Element(Tokenizer* tokenizer) : AbstractParser(tokenizer) {};

        bool parse()
        {
            auto parenthesisOpen = tokenizer->find("(");
            if (parenthesisOpen == std::string::npos) {
                // This seems to be not an element
                return false;
            }
            type = tokenizer->read(parenthesisOpen);
            tokenizer->move(parenthesisOpen + 1);

            auto parenthesisClosed = tokenizer->find(")");
            if (parenthesisClosed == std::string::npos) {
                // Somethings fishy
                return false;
            }
            id = tokenizer->read(parenthesisClosed);
            
            tokenizer->move(parenthesisClosed + 1);
            auto rest = tokenizer->readLine();
            // Ignoring rest of tokens
            tokenizer->moveLine();
            
            parameters = new Parameters(tokenizer);
            return parameters->parse();
        }
    };
}

#endif