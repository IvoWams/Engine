#ifndef ENGINE_SCRIPT_PARSER_ABSTRACTPARSER_H
#define ENGINE_SCRIPT_PARSER_ABSTRACTPARSER_H

#include "Tokenizer.h"

namespace engine::script::parser
{
    struct AbstractParser
    {
        Tokenizer *tokenizer;

        AbstractParser(Tokenizer *_tokenizer)
        {
            tokenizer = _tokenizer;
        }

        virtual bool parse()
        {
            return false;
        }

        virtual std::string getParserName()
        {
            return "AbstractParser";
        }

        virtual void errorMessage()
        {
            printf(
                "Error parsing %s at column %d, row %d",
                getParserName().c_str(),
                tokenizer->getColumn(),
                tokenizer->getRow()
            );
        }
    };
}

#endif