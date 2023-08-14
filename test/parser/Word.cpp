#include "test/Testbench.h"
#include "engine/script/parser/Word.h"

using namespace test;
using namespace engine::script::parser;

int main()
{
    Tokenizer* tokenizer = new Tokenizer("This is a sentence");
    Word* word = new Word(tokenizer);
    Token* token = word->parse();

    Testbench::assertEqual(token->value.c_str(), "This", "Is 'this' the first word");
    token = word->parse();
    Testbench::assertEqual(token->value.c_str(), "is", "Is 'is' the second word");
    token = word->parse();
    Testbench::assertEqual(token->value.c_str(), "a", "Is 'a' the third word");
    token = word->parse();
    Testbench::assertNotEqual(token->value.c_str(), "sointence", "'sointence' is not the last word");
    Testbench::assertEqual(token->value.c_str(), "sentence", "Is 'sentence' the last word");
}
