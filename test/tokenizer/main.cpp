#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <filesystem>
#include <unistd.h>
#include "engine/script/parser/Tokenizer.h"

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

    auto tokenizer = new Tokenizer(data);
    tokenizer->moveLine();
    auto firstline = tokenizer->readLine();
    
    printf("First line: [%s]\n", firstline.c_str());
}