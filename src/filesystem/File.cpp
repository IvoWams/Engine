#include "File.h"

#include <iostream>
#include <fstream>

engine::filesystem::File(const std::string& _filename)
{
    filename = _filename;
    printf("Creating reader for %s", filename.c_str());
}

Engine::File::FileHandle::~FileHandle()
{
    printf("Destructing reader for %s", filename.c_str());
}

void Engine::File::FileHandle::load()
{
    std::ifstream file(filename, std::ios::binary);
    auto begin = file.tellg();
    file.seekg(0, std::ios::end);
    auto end = file.tellg();
    auto size = end - begin;

    memory = new char[size];

    file.seekg(0);
    file.read(memory, size);
    file.close();
}

}