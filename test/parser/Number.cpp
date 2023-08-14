#include "test/Testbench.h"
#include "engine/script/parser/Word.h"
#include "engine/script/parser/Number.h"

#include <vector>
#include <string>

using namespace test;
using namespace engine::script::parser;

int main()
{
    std::vector<std::string> values = {
        "12.95",
        "-3.50",
        "88",
        "12 and some more"
    };

    std::string empty = "";

    for (std::string i : values) {
        Tokenizer* tokenizer = new Tokenizer(i);
        Number* word = new Number(tokenizer);
        Token* token = word->parse();
        Testbench::assertNotEqual(token->value, empty, "Test we parsed a number " + i);
    }

    values = {
        "no value",
        "bla 20"
    };

    for (std::string i : values) {
        Tokenizer* tokenizer = new Tokenizer(i);
        Number* word = new Number(tokenizer);
        Token* token = word->parse();
        Testbench::assertEqual(token->value, empty, "Test we did not parse a number " + i);
    }    
}
