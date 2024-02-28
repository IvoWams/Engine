#ifndef ENGINE_SCRIPT_PARSER_STRING_H
#define ENGINE_SCRIPT_PARSER_STRING_H

#include "AtomicParser.h"
#include "Tokenizer.h"
#include "Token.h"

namespace engine::script::parser
{
    struct String : AtomicParser
    {
        String(Tokenizer* _tokenizer) : AtomicParser(_tokenizer){}

        std::string autocontext()
        {
            return "String";
        }

        Token* parse()
        {
            tokenizer->trim();
            tokenizer->expect("\"");
            tokenizer->move(1);

            std::string result = "";
            std::string character = "";
            std::string escapee = "";

            // @todo performance improvement
            while (tokenizer->read(1) != "\"" && tokenizer->left() > 0) {

                // @todo expand on escape mechanism
                character = tokenizer->read(1);
                if (character == "\\") {
                    tokenizer->move(1);
                    character = tokenizer->read(1);
                }

                result += character;
                tokenizer->move(1);
            }

            tokenizer->expect("\"");
            tokenizer->move(1);

            return new Token(
                autocontext(),
                result
            );
        }
    };
}

#endif