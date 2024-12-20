//
// Created by Alife Zithu on 12/20/24.
//

#ifndef CAMERA_HPP
#define CAMERA_HPP
#include "geometry.hpp"

namespace core {

class object;

class camera {
public:
    utils::point pos{};
    object *subject = nullptr;
};

} // core

#endif //CAMERA_HPP
