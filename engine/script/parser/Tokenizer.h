#ifndef ENGINE_SCRIPT_PARSER_TOKENIZER_H
#define ENGINE_SCRIPT_PARSER_TOKENIZER_H

#include <string>
#include <algorithm>

namespace engine::script::parser
{
    struct Tokenizer
    {
        std::string tokens;

        Tokenizer(std::string _tokens)
        {
            tokens = _tokens;
        }

        bool hasTokens()
        {
            trim();
            return tokens.size() > 0;
        }

        std::string read(int bytes)
        {
            return tokens.substr(0, bytes);
        };

        std::string readLine()
        {
            int eol = find("\n");

            if (eol == 0) {
                return "";
            }

            if (eol == std::string::npos) {
                return tokens;
            }

            return read(eol);
        };

        void moveLine()
        {
            int eol = find("\n");
            if (eol == std::string::npos) {
                return;
            }

            move(eol + 1);
        };

        void move(int bytes)
        {
            tokens = tokens.substr(bytes);
        };

        int left()
        {
            return tokens.length();
        };

        int find(std::string needle)
        {
            return tokens.find(needle);
        };

        void trim()
        {
            tokens.erase(
                tokens.begin(),
                std::find_if(
                    tokens.begin(),
                    tokens.end(),
                    [](unsigned char c) {
                        return ! std::isspace(c);
                    }
                )
            );
        }
    };
}

#endif