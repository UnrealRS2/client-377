#pragma once

//#include "platform.h"
#include <vector>

#include "../../nullpops/util/Util.h"

namespace jagex2::graphics {

    class PixMap {
    public:
        PixMap(int width, int height);

        // Non-copyable, but movable
        PixMap(const PixMap&) = delete;
        PixMap& operator=(const PixMap&) = delete;
        PixMap(PixMap&&) noexcept = default;
        PixMap& operator=(PixMap&&) noexcept = default;

        //ObfuscatedName("ISZGOOMR.a(Z)V")
        void bind() const;
        //ObfuscatedName("ISZGOOMR.a(IILjava/awt/Graphics;Z)V")
        void draw(int x, int y) const;
        //INAUTHENTIC
        void clear();

        [[nodiscard]] int getWidth() const noexcept { return width; }
        [[nodiscard]] int getHeight() const noexcept { return height; }
        [[nodiscard]] nullpops::util::Framebuffer getImage() const noexcept { return image; }
        [[nodiscard]] const std::vector<int>& getPixels() const noexcept { return pixels; }
        [[nodiscard]] std::vector<int>& getPixels() noexcept { return pixels; }

    private:
        //ObfuscatedName("ISZGOOMR.c")
        int width;
        //ObfuscatedName("ISZGOOMR.d")
        int height;
        //ObfuscatedName("ISZGOOMR.b")
        std::vector<int> pixels;
        //ObfuscatedName("ISZGOOMR.g")
        nullpops::util::Framebuffer image;
    };

} // namespace jagex2::gfx
