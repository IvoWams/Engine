#ifndef ENGINE_SCRIPT_PARSER_DOCUMENT_H
#define ENGINE_SCRIPT_PARSER_DOCUMENT_H

#include "AbstractParser.h"
#include "Declaration.h"
#include "Repeatable.h"
#include <vector>

namespace engine::script::parser
{
    struct Document : AbstractParser
    {
        // std::vector<Header*> headers;
        Repeatable<Declaration> *declarations;

        Document(Tokenizer *tokenizer) : AbstractParser(tokenizer) {};

        bool parse()
        {
            // headers = new Repeatable<Header>(tokenizer);
            declarations = new Repeatable<Declaration>(tokenizer);
            declarations->parse();

            return true;
        }
    };
}

#endif
