#ifndef APP_SCRIPT_PARSER_DOCUMENT_H
#define APP_SCRIPT_PARSER_DOCUMENT_H

#include "AbstractParser.h"
#include "Element.h"
#include <vector>

namespace app::script::parser
{
    struct Document : AbstractParser
    {
        std::vector<Element*> elements;

        Document(Tokenizer *tokenizer) : AbstractParser(tokenizer) {};

        bool parse()
        {
            while (tokenizer->hasTokens()) {

                tokenizer->trim();

                auto comment = tokenizer->find("//");
                if (comment == 0) {
                    tokenizer->moveLine();
                    continue;
                }


                auto element = new Element(tokenizer);
                element->parse() ? elements.push_back(element) : delete element;

                
                // auto function = new Function(tokenizer);
                // function->parse() ? functions.push_back(function) : delete function;

            }

            if (elements.size() == 0) {
                // Where can we store error messages ?
                return false;
            }

            return true;
        }
    };
}

#endif