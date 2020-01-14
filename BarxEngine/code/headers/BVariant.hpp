// This is free code released into the public domain.
// Drafted by Ángel on April 2017.
// Use it at your own risk. It might have bugs.
// angel.rodriguez@esne.edu

// File: BVariant.hpp
// Author: Jorge Bárcena Lumbreras

// © Copyright (C) 2019  Jorge Bárcena Lumbreras

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
//

#pragma once

#include <string>

using std::string;
using std::to_string;

class BVariant
{
    enum Type
    {
        BOOL, INT, FLOAT, STRING
    }
    type;

    union
    {
        bool       bool_value;
        int         int_value;
        float     float_value;
        string* string_value;
    }
    value;

public:
 
    BVariant()
    {   
        type = BOOL;
        value.bool_value = false;
    }

    BVariant(bool initializer)
    {
        type = BOOL;
        value.bool_value = initializer;
    }

    BVariant(int initializer)
    {
        type = INT;
        value.int_value = initializer;
    }

    BVariant(float initializer)
    {
        type = FLOAT;
        value.float_value = initializer;
    }

    BVariant(const string& initializer)
    {
        type = STRING;
        value.string_value = new string(initializer);
    }

    ~BVariant()
    {
        release();
    }

private:

    void release()
    {
        if (type == STRING)
        {
            delete value.string_value;
        }
    }

public:

    Type get_type() const
    {
        return type;
    }

    bool is_bool() const
    {
        return type == BOOL;
    }

    bool is_int() const
    {
        return type == INT;
    }

    bool is_float() const
    {
        return type == FLOAT;
    }

    bool is_string() const
    {
        return type == STRING;
    }

    // ...

public:

    // En algunos casos el compilador podrá determinar el valor de type en tiempo de compilación
    // y evitará la sentencia switch:

    bool as_bool() const
    {
        switch (type)
        {
        case BOOL:    return  value.bool_value;
        case INT:     return  value.int_value != 0;
        case FLOAT:   return  value.float_value != 0.f;
        case STRING:  return *value.string_value == "true" ? true : false;
        }

        return false;
    }

    int as_int() const
    {
        switch (type)
        {
        case BOOL:    return value.bool_value ? 1 : 0;
        case INT:     return value.int_value;
        case FLOAT:   return int(value.float_value);
        case STRING:  return strtol(value.string_value->c_str(), nullptr, 10);
        }

        return 0;
    }

    string as_string() const
    {
        switch (type)
        {
        case BOOL:    return  value.bool_value == true ? "true" : "false";
        case INT:     return  to_string(value.int_value);
        case FLOAT:   return  to_string(value.float_value);
        case STRING:  return *value.string_value;
        }

        return string();
    }

public:

    // ...

    BVariant& operator = (const BVariant& other)
    {
        if (this != &other)
        {
            release();

            this->type = other.type;
            this->value = other.value;
        }

        return *this;
    }

    BVariant& operator = (int new_value)
    {
        release();

        type = INT;
        value.int_value = new_value;

        return *this;
    }

    // ...

    operator int() const
    {
        return this->as_int();
    }

    operator string () const
    {
        return this->as_string();
    }

    // ...

};


