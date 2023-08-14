#include "test/Testbench.h"
#include "engine/script/parser/Parser.h"
#include <vector>

using namespace test;
using namespace engine::script::parser;

int main()
{
    std::vector<Token*> tokens;

    printf("Starting\n");

    Parser::parse(&tokens, "Het is een begin, want we hebben 25 en \"strings\" en zo");
    int count = 0;

    for (auto token : tokens) {
        printf(
            "%d. %s: %s\n",
            count++,
            token->context.c_str(),
            token->value.c_str()
        );
    }
}
