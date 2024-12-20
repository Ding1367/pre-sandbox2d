//
// Created by Alife Zithu on 12/19/24.
//

#include "../include/engine.hpp"

#include "../include/part.hpp"

namespace core {
    engine::engine(GLFWwindow* win, object *world_root) : win(win) {
        if (world_root != nullptr)
            this->world_root = world_root;
        GLsizei w, h;
        glfwGetWindowSize(win, &w, &h);
        glViewport(0, 0, w, h);
        gl_plane = utils::ndc_plane(w, h);
        glfwMakeContextCurrent(win);
        glfwSwapInterval(1);
    }

    void engine::render() const {
        glBegin(GL_QUADS);
        for (object *obj : world_root->children) {
            auto p = dynamic_cast<part *>(obj);
            if (p == nullptr) continue;
            const utils::point pos = p->pos;
            const auto [width, height] = p->size;
            const auto [r, g, b] = p->color;
            const float transparency = p->transparency;
            glColor4f(r, g, b, transparency);
            const auto [x, y] = gl_plane.at(pos);
            const auto [t_width, t_height] = gl_plane.at({width, height});
            glVertex2f(x, y);
            glVertex2f(x + t_width, y);
            glVertex2f(x + t_width, y - t_height);
            glVertex2f(x, y - t_height);
        }
        glEnd();
        glfwSwapBuffers(win);
    }
} // core