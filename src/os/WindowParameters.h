#ifndef ENGINE_WINDOW_PARAMETERS_H
#define ENGINE_WINDOW_PARAMETERS_H

#include <map>
#include <string>

using std::map;
using std::string;
using std::make_pair;
using std::format;

namespace engine::os
{
    union Value
    {
        int i_value;
        double d_value;
        float f_value;
        string s_value;

        Value(){}
        Value(const Value& value) : s_value(value.s_value) {}
        ~Value(){}
    };

    enum ValueType
    {
        INT,
        FLOAT,
        DOUBLE,
        STRING
    };

    struct Parameter
    {
        ValueType type;
        Value value;

        Parameter(const string& str)
        {
            type = STRING;
            value.s_value = str;
        }

        Parameter(int i)
        {
            type = INT;
            value.i_value = i;
        }

        Parameter(double d)
        {
            type = DOUBLE;
            value.d_value = d;
        }

        Parameter(float f)
        {
            type = FLOAT;
            value.f_value = f;
        }

        Parameter(){}
        ~Parameter(){}

        const string& print()
        {
            switch (type) {
                case STRING:

                    printf("%s", value.s_value.c_str());
                    break;
                case INT:
                    printf("%d", value.i_value);
                    break;
                case DOUBLE:
                    printf("%0.2f", value.d_value);
                    break;
                case FLOAT:
                    printf("0.2f", value.f_value);
                    break;
                default:
                    printf("Invalid value\n");
            }
        }
    };

    struct WindowParameters : map<string, Parameter>
    {
        void add(const string& name, auto value)
        {
            insert(make_pair(name, Parameter{value}));
        }

        void dump()
        {
            for (auto const& parameter: *this) {
                printf("%s =", parameter.first.c_str())
            }
        }
    };
}

#endif
