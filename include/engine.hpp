//
// Created by Alife Zithu on 12/19/24.
//

#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <GLFW/glfw3.h>

#include "object.hpp"

namespace core {

class engine {
public:
    GLFWwindow *win;
    object *world_root;

    explicit engine(GLFWwindow *win, object *world_root = get_null_object());
};

} // core

#endif //ENGINE_HPP
