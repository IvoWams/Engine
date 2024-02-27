#ifndef TEST_TESTBENCH_H
#define TEST_TESTBENCH_H

#include <stdio.h>
#include <string>
#include <iostream>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define TEST_OK            "OK" 
#define TEST_NOT_OK        "ERROR" 

#define testbench_get_variable_name(val)   test::variableName(val, # val)

namespace test
{
    std::string variableName(auto val, std::string var)
    {
        return var;
    }

    class Testbench
    {
        private:
            static std::string okNotOk(bool okNotOk)
            {
                char buf[20];
                snprintf(
                    buf,
                    40,
                    "%s%s%s",
                    okNotOk ? ANSI_COLOR_GREEN : ANSI_COLOR_RED,
                    okNotOk ? TEST_OK : TEST_NOT_OK,
                    ANSI_COLOR_RESET
                );
                return buf;
            }

            static void message(std::string status, std::string message)
            {
                printf("%s\t%s\n", status.c_str(), message.c_str());
            }

        public:
            static void assertTrue(bool test, std::string name)
            {
                message(okNotOk(test), name);
            }

            static void assertFalse(bool test, std::string name)
            {
                assertTrue(!test, name);
            }

            static void assertEqual(auto test, auto value, std::string name)
            {
                if (typeid(test) != typeid(value)) {
                    message("TYPEERR", name);
                    return;
                }

                std::string type = typeid(test).name();
                std::string a = test;
                std::string b = value;
                
                message(okNotOk(a == b), name + " (\"" + a + "\" <=> \"" + b + "\")");
            }

            static void assertNotEqual(auto test, auto value, std::string name)
            {
                if (typeid(test) != typeid(value)) {
                    message("TYPEERR", name);
                    return;
                }

                std::string type = typeid(test).name();
                std::string a = test;
                std::string b = value;
                
                message(okNotOk(a != b), name + " (\"" + a + "\" <=> \"" + b + "\")");
            }

    };
}

#endif