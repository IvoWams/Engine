#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "../../engine/script/parser/Document.h"
#include "../../engine/script/parser/Tokenizer.h"

using namespace engine::script::parser;

int main()
{
    /*
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
    */

   std::string script = "ReturnType functionName(ParameterType parameterValue)";

    Document document{new Tokenizer(script)};

    try {
        auto success = document.parse();
        if (success) {
            printf("Parsing successful!\n");
        }
        
    } catch (UnexpectedEndOfFile& e) {
        printf("Unexpected end of file!\n");
    }


}