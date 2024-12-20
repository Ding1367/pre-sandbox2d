//
// Created by Alife Zithu on 12/19/24.
//

#include "../include/engine.hpp"

namespace core {
    engine::engine(GLFWwindow* win, object *world_root): win(win) {
        if (world_root != nullptr)
            this->world_root = world_root;
        GLsizei w, h;
        glfwGetWindowSize(win, &w, &h);
        glViewport(0, 0, w, h);
    }
} // core