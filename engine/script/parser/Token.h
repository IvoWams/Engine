#ifndef ENGINE_SCRIPT_PARSER_TOKEN_H
#define ENGINE_SCRIPT_PARSER_TOKEN_H

#pragma once

#include <string>

using namespace std;

namespace engine::script::parser
{
    struct Token
    {
        string context;
        string value;

        Token(
            string _context,
            string _value
        ): context(_context), value(_value)
        {}
    };
}

#endif