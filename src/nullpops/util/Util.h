//
// Created by tyler on 9/27/2025.
//

#pragma once
#include <string>
#include <utility>
#include <vector>

namespace nullpops::util {
    std::vector<uint8_t> java_mod_pow(
        const std::vector<uint8_t>& input,
        const std::string& dec_modulus,
        const std::string& dec_exponent);

    struct Framebuffer {
        Framebuffer(int width, int height, std::vector<int> pixels) {
            this->width = width;
            this->height = height;
            this->pixels = std::move(pixels);
        }
        int width;
        int height;
        std::vector<int> pixels; // ARGB or RGBA
    };
}
