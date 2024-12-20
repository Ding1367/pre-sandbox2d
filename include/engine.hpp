//
// Created by Alife Zithu on 12/19/24.
//

#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <GLFW/glfw3.h>

#include "camera.hpp"
#include "ndc_plane.hpp"
#include "object.hpp"

namespace core {

class engine {
    static void onResize(GLFWwindow *win, int width, int height);

    utils::ndc_plane gl_plane{{0, 0}};
public:
    GLFWwindow *win;
    object *world_root;
    camera cam{};

    explicit engine(GLFWwindow *win, object *world_root = get_null_object());

    void render() const;
};

} // core

#endif //ENGINE_HPP
