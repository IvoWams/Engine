#ifndef ENGINE_SCRIPT_PARSER_TOKENIZER_H
#define ENGINE_SCRIPT_PARSER_TOKENIZER_H

#include <string>
#include <algorithm>
#include <vector>
#include "exception/SyntaxError.h"

using namespace engine::script::parser::exception;

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
            if (left() >= bytes) {
                return tokens.substr(0, bytes);
            }

            throw SyntaxError("Not enough tokens left");
        };

        std::string readUntil(std::string haystack)
        {
            trim();
            int eow = tokens.find_first_of(haystack);
            std::string out = read(eow);
            move(eow);
        }

        std::string readWord()
        {
            int eow = tokens.find_first_of(",; \t\n");
            if (eow == std::string::npos) {
                return tokens;
            }
            return read(eow);
        }

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
            if (tokens.length() < bytes) {
                return;
            }
            tokens = tokens.substr(bytes);
        };

        void move(std::string bytes)
        {
            if (tokens.length() < bytes.length()) {
                return;
            }
            tokens = tokens.substr(bytes.length());
        }

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

        void expect(std::string value)
        {
            auto seen = read(std::min({value.length(), tokens.length()}));
            if (seen != value) {
                throw SyntaxError("Expected a `" + value + "` but I got `" + seen +"`");
            }
        }

        int getColumn()
        {
            return 0;
        }

        int getRow()
        {
            return 0;
        }

    };
}

#endif