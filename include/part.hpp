//
// Created by Alife Zithu on 12/20/24.
//

#ifndef PART_HPP
#define PART_HPP
#include "object.hpp"
#include "glutil.hpp"
#include "geometry.hpp"

namespace core {

class part : public object {
public:
    float transparency = 0;
    utils::point pos{};
    utils::size size{};
    utils::color3 color{};

    explicit part(std::string name, object *parent) : object::object(name, parent) {
    }

    explicit part(std::string name) : object::object(name) {
    }
};

} // core

#endif //PART_H
