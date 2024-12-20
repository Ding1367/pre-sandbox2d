//
// Created by Alife Zithu on 12/19/24.
//

#include "../include/engine.hpp"

#include "../include/part.hpp"

namespace core {
    void engine::onResize(GLFWwindow *win, const int width, const int height) {
        glViewport(0, 0, width, height);
    }

    engine::engine(GLFWwindow* win, object *world_root) : win(win) {
        if (world_root != nullptr)
            this->world_root = world_root;
        GLsizei w, h;
        glfwGetWindowSize(win, &w, &h);
        glfwSetWindowSizeCallback(win, &onResize);
        glViewport(0, 0, w, h);
        gl_plane = utils::ndc_plane(w, h);
        glfwMakeContextCurrent(win);
        glfwSwapInterval(1);
    }

    void engine::render() const {
        int win_width, win_height;
        glfwGetWindowSize(win, &win_width, &win_height);
        glBegin(GL_QUADS);
        utils::point cam_offset = cam.pos;
        if (object *subject = cam.subject; subject != nullptr) {
            if (const part *pt = dynamic_cast<part *>(subject); pt != nullptr) {
                auto [x, y] = pt->pos;
                auto [width, height] = pt->size;
                cam_offset = {x + width / 2 + cam_offset.x, y + height / 2 + cam_offset.y};
            }
        }
        for (object *obj : world_root->children) {
            const auto p = dynamic_cast<part *>(obj);
            if (p == nullptr) continue;
            const auto [p_x, p_y] = p->pos;
            const utils::point pos = {p_x + cam_offset.x, p_y + cam_offset.y};
            const auto [width, height] = p->size;
            const auto [r, g, b] = p->color;
            const float transparency = p->transparency;
            glColor4f(r, g, b, transparency);
            const auto [x, y] = gl_plane.at(pos);
            const auto [tr_x, tr_y] = gl_plane.at({pos.x + width, pos.y + height});
            glVertex2f(x + 1.f, y + 1.f);
            glVertex2f(tr_x + 1.f, y + 1.f);
            glVertex2f(tr_x + 1.f, tr_y + 1.f);
            glVertex2f(x + 1.f, tr_y + 1.f);
        }
        glEnd();
        glfwSwapBuffers(win);
    }
} // core