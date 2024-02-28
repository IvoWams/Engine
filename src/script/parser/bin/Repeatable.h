#ifndef ENGINE_SCRIPT_PARSER_REPEATABLE_H
#define ENGINE_SCRIPT_PARSER_REPEATABLE_H

#include "AbstractParser.h"
#include <vector>

namespace engine::script::parser
{
    template<class T>
    struct Repeatable : AtomicParser
    {
        std::vector<T*> list;

        Repeatable(Tokenizer *tokenizer) : AtomicParser(tokenizer) {
            // static_assert(std::is_base_class_of<AbstractParser, T>::value, "Repeatable parser needs to be of type AbstractParser");
        }

        bool parse()
        {
            while(true) {

                AtomicParser *item = new T(tokenizer);
                if (item->parse()) {
                    list.push_back(item)
                } else {
                    // delete item;
                    return ! list.empty();
                }
            }
        }
    };
}

#endif
