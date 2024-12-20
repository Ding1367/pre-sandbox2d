//
// Created by Alife Zithu on 12/18/24.
//

#include "../include/ndc_plane.hpp"
#include "../include/geometry.hpp"

namespace core::utils {
    point ndc_point::apply(const ndc_plane plane) const {
        const auto [width, height] = plane.size_;
        return {(x + 1.f) / 2.f * width, (y + 1) / 2 * height};
    }

    point ndc_point::apply(const float width, const float height) const {
        return apply(ndc_plane(width, height));
    }

    ndc_point ndc_plane::at(point p) const {
        return {(2.f * p.x / size_.width - 1.f), (2.f * p.x / size_.height - 1.f)};
    }

    ndc_point ndc_plane::at(const float x, const float y) const {
        return at({x, y});
    }
} // core::utils