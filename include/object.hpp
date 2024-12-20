//
// Created by Alife Zithu on 12/16/24.
//

#ifndef OBJECT_HPP
#define OBJECT_HPP
#include <vector>
#include <string>

namespace core {

class object {
public:
    virtual ~object() = default;

    std::string name{};
    std::vector<object *> children{};
    object *parent = nullptr;

    explicit object(std::string name, object *parent) : name(std::move(name)) {
        move(parent);
    }

    explicit object(std::string name) : name(std::move(name)) {
    }

    void move(object *new_parent);
    bool contains(object *other) const;

    bool operator &&(object *other) const {
        return contains(other);
    }

    object &operator &(object *other) {
        other->move(this);
        return *this;
    }
};

object *get_null_object();

} // core

#endif //OBJECT_HPP
