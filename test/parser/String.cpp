#include "test/Testbench.h"
#include "engine/script/parser/String.h"

#include <vector>
#include <string>

using namespace test;
using namespace engine::script::parser;

int main()
{
    std::vector<std::string> values = {
        "\"Dit is een stuk text tussen quotes en zo like a normal string\"",
        "\"Deze ook maar wat doen we dan met een escaped quote? like \\\" deze ?\"",
        "\"En wat als er nog wat text achteraan komt?\" zoals deze test"
    };

    std::string empty = "";

    for (std::string i : values) {
        Tokenizer* tokenizer = new Tokenizer(i);
        String* word = new String(tokenizer);
        Token* token = word->parse();
        Testbench::assertNotEqual(token->value, empty, "Test we parsed a string " + i);
    }

    values = {
        "\"Hier hebben we een string die niet sluit!",
        "En hier is helemaal geen string te vinden..."
    };

    for (std::string i : values) {
        try {
            Tokenizer* tokenizer = new Tokenizer(i);
            String* word = new String(tokenizer);
            Token* token = word->parse();
            Testbench::assertTrue(false, "Excepted SyntaxError was not thrown");
        } catch (SyntaxError &exception) {
            Testbench::assertTrue(true, "Received expected error for [" + i + "] ("+ exception.message +")");
        }
    }   
}
