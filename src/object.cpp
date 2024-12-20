//
// Created by Alife Zithu on 12/16/24.
//

#include "object.hpp"

static core::object null_obj("(null)");
static bool null_init = false;

namespace core {
    void object::move(object* new_parent) {
        if (new_parent == nullptr) new_parent = get_null_object();
        if (parent == new_parent) return;
        if (parent != nullptr) {
            const std::vector<object *> parent_children = parent->children;
            parent->children.erase(std::find(parent_children.cbegin(), parent_children.cend(), this));
        }
        parent = new_parent;
        parent->children.push_back(this);
    }

    bool object::contains(object* other) const {
        if (other->parent == this) return true;
        for (const object *child : children) {
            if (child->contains(other)) return true;
        }
        return false;
    }

    object* get_null_object() {
        if (!null_init) {
            null_init = true;
            null_obj = object("(null)");
            null_obj.parent = nullptr;
        }
        return &null_obj;
    }
} // core