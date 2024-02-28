#ifndef ENGINE_SCRIPT_PARSER_PARSER_H
#define ENGINE_SCRIPT_PARSER_PARSER_H

#include <vector>
#include "Tokenizer.h"
#include "Token.h"
#include "AtomicParser.h"

#include "Bool.h"
#include "Number.h"
#include "String.h"
#include "Word.h"

namespace engine::script::parser
{
    struct Parser
    {

            static void parse(std::vector<Token*>* container, std::string code)
            {
                Tokenizer* tokenizer = new Tokenizer(code);
                std::vector<AtomicParser*> atomicParsers = {
                    new Bool(tokenizer),
                    new Number(tokenizer),
                    new String(tokenizer),
                    new Word(tokenizer)
                };

                Token* token = nullptr;
                
                while(tokenizer->left() > 0) {

                    token = nullptr;

                    for (auto atomicParser : atomicParsers) {

                        try {

                            token = atomicParser->parse();
                            container->push_back(token);

                        } catch (Exception& exception) {
                            // try fallback
                        }

                    }

                    if (token == nullptr) {
                        throw SyntaxError("Unable to parse");
                    }
                }
            }    
    };
}

#endif