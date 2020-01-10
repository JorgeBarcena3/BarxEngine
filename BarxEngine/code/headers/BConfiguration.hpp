#pragma once
#include "BtypeDef.hpp"
#include "BVariant.hpp"

class BConfiguration
{
    typedef std::map< std::string, BVariant > Property_List;

    Property_List properties;

public:

    bool add_properties_from_file(const std::string& path);

    // Este método permite añadir nuevas propiedades fácilmente:

    BVariant& operator [] (const std::string& name)
    {
        return properties[name];
    }

    const BVariant& operator [] (std::string name) const
    {
        return NULL;//properties[name];
    }

};

