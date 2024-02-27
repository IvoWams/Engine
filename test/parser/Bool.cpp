#include "test/Testbench.h"
#include "engine/script/parser/Bool.h"

#include <vector>
#include <string>

using namespace test;
using namespace engine::script::parser;

int main()
{
    std::vector<std::string> values = {
        "true",
        "false"
    };

    std::string empty = "";

    for (std::string i : values) {
        Tokenizer* tokenizer = new Tokenizer(i);
        Bool* word = new Bool(tokenizer);
        Token* token = word->parse();
        Testbench::assertNotEqual(token->value, empty, "Test we parsed a bool " + i);
    }

    values = {
        "no value",
        "bla 20"
    };

    for (std::string i : values) {
        try {
            Tokenizer* tokenizer = new Tokenizer(i);
            Bool* word = new Bool(tokenizer);
            Token* token = word->parse();
            Testbench::assertTrue(false, "Excepted ParseException was not throws");
        } catch (ParseException &exception) {
            Testbench::assertTrue(true, exception.message);
        }
    }    
}
