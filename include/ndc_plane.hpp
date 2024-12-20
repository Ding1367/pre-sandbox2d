//
// Created by Alife Zithu on 12/18/24.
//

#ifndef NDC_PLANE_HPP
#define NDC_PLANE_HPP
#include "geometry.hpp"

namespace core::utils {

class ndc_plane;
struct point;

class ndc_point {
public:
    float x, y;

    [[nodiscard]] point apply(ndc_plane plane) const;
    [[nodiscard]] point apply(float width, float height) const;

};

class ndc_plane {
public:
    size size_{};

    explicit ndc_plane(const size size) : size_(size) {

    }

    ndc_plane(const float width, const float height) : size_({width, height}) {

    }

    [[nodiscard]] ndc_point at(point p) const;
    [[nodiscard]] ndc_point at(float x, float y) const;

};

} // core::utils

#endif //NDC_PLANE_HPP
