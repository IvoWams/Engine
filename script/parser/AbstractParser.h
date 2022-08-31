#ifndef APP_SCRIPT_PARSER_ABSTRACTPARSER_H
#define APP_SCRIPT_PARSER_ABSTRACTPARSER_H

#include "Tokenizer.h"

namespace app::script::parser
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
    };
}

#endif