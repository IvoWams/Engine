#pragma once

#ifndef ENGINE_HELPER_PARAMETERS_H
#define ENGINE_HELPER_PARAMETERS_H

#include <string>
#include <vector>
#include <iomanip>

using std::vector;
using std::string;
using std::quoted;
using std::format;

namespace engine::helper
{
    union ValueUnion
    {
        string string_value;
        int int_value;
        double double_value;
        float float_value;
        bool bool_value;

        ~ValueUnion() {}

        ValueUnion(const ValueUnion& _value)
        {
            string_value = _value.string_value;
            int_value = _value.int_value;
            double_value = _value.double_value;
            float_value = _value.float_value;
            bool_value = _value.bool_value;
        }

        ValueUnion(const string& _value) : string_value(_value) {}
        ValueUnion(int _value) : int_value(_value) {}
        ValueUnion(double _value) : double_value(_value) {}
        ValueUnion(float _value) : float_value(_value) {}
        ValueUnion(bool _value) : bool_value(_value) {}

        ValueUnion operator=(const ValueUnion& _value)
        {
            string_value = _value.string_value;
            int_value = _value.int_value;
            double_value = _value.double_value;
            float_value = _value.float_value;
            bool_value = _value.bool_value;
        };

        ValueUnion& operator=(const string& _value)
        {
            string_value = _value;
            return *this;
        }

        ValueUnion& operator=(int _value)
        {
            int_value = _value;
            return *this;
        }

        ValueUnion& operator=(float _value)
        {
            float_value = _value;
            return *this;
        }

        ValueUnion& operator=(double _value)
        {
            double_value = _value;
            return *this;
        }

        ValueUnion& operator=(bool _value)
        {
            bool_value = _value;
            return *this;
        }
    };

    enum ValueType
    {
        STRING,
        INT,
        DOUBLE,
        FLOAT,
        BOOL
    };

    struct Value
    {
        ValueType type;
        ValueUnion value;

        // Value(const Value& _value) : value(_value.value) { type = _value.type; }
        Value(const string& _value) : value(_value) { type = STRING; }
        Value(int _value) : value(_value) { type = INT; }
        Value(double _value) : value(_value) { type = DOUBLE; }
        Value(float _value) : value(_value) { type = FLOAT; }
        Value(bool _value) : value(_value) { type = BOOL; }

        Value& operator=(const string& _value)
        {
            type = STRING;
            value = _value;
        }

        std::string dump()
        {
            switch (type) {
                case STRING:
                    return quoted(value.string_value);
                case INT:
                    return format("{}", value.int_value);
                case DOUBLE:
                    return format("{}", value.double_value);
                case FLOAT:
                    return format("{}", value.float_value);
                case BOOL:
                    return value.bool_value ? "true" : "false";
            }
        }
    };

    struct Parameter
    {
        string name;
        Value value;

        Parameter(const string& _name, Value _value) : name(_name), value(_value) {}

        Parameter& operator=(const Parameter& parameter)
        {
            name = parameter.name;
            value = parameter.value;
            
            return *this;
        }

        Parameter& operator=(const Value& _value)
        {
            value = _value;
            return *this;
        }

        std::string dump()
        {
            return format(
                "{} = {}\n",
                quoted(name),
                value.dump()
            );
        }
    };

    struct Parameters : vector<Parameter*>
    {
        std::string dump()
        {
            std::string result = "{\n";

            for (auto parameter: *this) {
                result += format("\t{}\n", parameter->dump());
            }

            result += "}";

            return result;
        }
    };
}

using engine::helper::Parameter;

int main()
{
    Parameter a{"bla", "25"};
    Parameter b{"name", 15};

    b.value = "bla";
    b.value = 12;

    a = b;

    std::string output = b.dump();
    printf("%s\n", output.c_str());
}

#endif 