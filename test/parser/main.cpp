#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "../../script/parser/Document.h"
#include "../../script/parser/Tokenizer.h"

using namespace engine::script::parser;

int main()
{
    std::string filename = "../../script/data/login.ui";
    std::stringstream buffer;
    std::ifstream filereader;
    filereader.open(filename);

    if (! filereader.is_open()) {
        printf("Failed to open %s\n", filename.c_str());
        return 0;
    }

    buffer << filereader.rdbuf();
    std::string data = buffer.str();

    Document document{new Tokenizer(data)};
    auto success = document.parse();

    if (success) {
        printf("Parsing successful!\n");
    }

}