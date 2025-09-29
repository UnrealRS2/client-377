//
// Created by tyler on 9/29/2025.
//

#include "pixmap.h"
#include "pix2d.h"
#include "../../client_377.h"

namespace jagex2::graphics {
    PixMap::PixMap(const int width, const int height)
        : width(width), height(height), pixels(width * height, 0), image(width, height, pixels)
    {
        bind();
    }

    //ObfuscatedName("ISZGOOMR.a(Z)V")
    void PixMap::bind() const {
        gfx::Pix2D::bind(width, height, const_cast<int*>(pixels.data()));
    }

    //ObfuscatedName("ISZGOOMR.a(IILjava/awt/Graphics;Z)V")
    void PixMap::draw(int x, int y) const {
        if (api::drawCallback) {
            api::drawCallback(image.pixels, x, y);
        }
    }

    //INAUTHENTIC
    void PixMap::clear() {
        std::memset(pixels.data(), 0, pixels.size() * sizeof(int));
    }
}
