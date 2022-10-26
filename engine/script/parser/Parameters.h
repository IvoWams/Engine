#ifndef ENGINE_SCRIPT_PARSER_PARAMETERS_H
#define ENGINE_SCRIPT_PARSER_PARAMETERS_H

#include "AbstractParser.h"
#include "Parameter.h"

namespace engine::script::parser
{
    struct Parameters : AbstractParser
    {
        std::vector<Parameter*> parameters;

        Parameters(Tokenizer* tokenizer) : AbstractParser(tokenizer) {};

        bool parse()
        {
            while (true) {

                auto parameter = new Parameter(tokenizer);

                if (! parameter->parse()) {
                    delete parameter;
                    return true;
                }

                parameters.push_back(parameter);
            }
        }
    };
}

#endif
