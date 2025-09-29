#include "pix2d.h"
#include <cmath>

namespace jagex2::graphics {

    //ObfuscatedName("LFYNQWSZ.m")
    int Pix2D::width = 0;
    //ObfuscatedName("LFYNQWSZ.n")
    int Pix2D::height = 0;
    //ObfuscatedName("LFYNQWSZ.o")
    int Pix2D::top = 0;
    //ObfuscatedName("LFYNQWSZ.p")
    int Pix2D::bottom = 0;
    //ObfuscatedName("LFYNQWSZ.q")
    int Pix2D::left = 0;
    //ObfuscatedName("LFYNQWSZ.r")
    int Pix2D::right = 0;
    //ObfuscatedName("LFYNQWSZ.s")
    int Pix2D::bound_x = 0;
    //ObfuscatedName("LFYNQWSZ.t")
    int Pix2D::center_x = 0;
    //ObfuscatedName("LFYNQWSZ.u")
    int Pix2D::center_y = 0;
    //ObfuscatedName("LFYNQWSZ.l")
    int* Pix2D::pixels = nullptr;

    //ObfuscatedName("LFYNQWSZ.a(ZII[I)V")
    void Pix2D::bind(int w, int h, int* px) {
        width = w;
        height = h;
        pixels = px;
        setClipping(height, width, 0, 0);
    }

    //ObfuscatedName("LFYNQWSZ.a(B)V")
    void Pix2D::resetClipping() {
        left = 0;
        top = 0;
        right = width;
        bottom = height;
        bound_x = right - 1;
        center_x = right / 2;
        center_y = bottom / 2;
    }

    //ObfuscatedName("LFYNQWSZ.a(IIIIZ)V")
    void Pix2D::setClipping(int b, int r, int t, int l) {
        if (l < 0) l = 0;
        if (t < 0) t = 0;
        if (r > width) r = width;
        if (b > height) b = height;

        left = l;
        top = t;
        right = r;
        bottom = b;
        bound_x = right - 1;
        center_x = right / 2;
        center_y = bottom / 2;
    }

    //ObfuscatedName("LFYNQWSZ.a(I)V")
    void Pix2D::clear() {
        if (!pixels) return;
        std::memset(pixels, 0, width * height * sizeof(int));
    }

    //TODO:fillRectTrans

    //ObfuscatedName("LFYNQWSZ.a(IIIBII)V")
    void Pix2D::fillRect(int x, int y, int rgb, int w, int h) {
        if (!pixels) return;

        if (x < left) { w -= left - x; x = left; }
        if (y < top) { h -= top - y; y = top; }
        if (x + w > right) w = right - x;
        if (y + h > bottom) h = bottom - y;

        int pixel = x + y * width;

        for (int col = 0; col < h; col++) {
            int* line = &pixels[pixel + col * width];
            for (int row = 0; row < w; row++) {
                line[row] = rgb;
            }
        }
    }

    //ObfuscatedName("LFYNQWSZ.a(IIIIII)V")
    void Pix2D::drawRect(int x, int y, int rgb, int w, int h) {
        hline(x, y, rgb, w);
        hline(x, y + h - 1, rgb, w);
        vline(x, y, rgb, h);
        vline(x + w - 1, y, rgb, h);
    }

    //TODO:drawRectTrans

    void Pix2D::fillCircle(int x_center, int y_center, int y_radius, int rgb, int alpha) {
        if (!pixels) return;

        int inv_alpha = 256 - alpha;
        int r0 = (rgb >> 16 & 0xff) * alpha;
        int g0 = (rgb >> 8 & 0xff) * alpha;
        int b0 = (rgb & 0xff) * alpha;

        int y_start = std::max(0, y_center - y_radius);
        int y_end = std::min(height - 1, y_center + y_radius);

        for (int y = y_start; y <= y_end; y++) {
            int midpoint = y - y_center;
            int x_radius = static_cast<int>(std::sqrt(y_radius * y_radius - midpoint * midpoint));

            int x_start = std::max(0, x_center - x_radius);
            int x_end = std::min(width - 1, x_center + x_radius);

            int offset = x_start + y * width;
            for (int x = x_start; x <= x_end; x++) {
                int r1 = (pixels[offset] >> 16 & 0xff) * inv_alpha;
                int g1 = (pixels[offset] >> 8 & 0xff) * inv_alpha;
                int b1 = (pixels[offset] & 0xff) * inv_alpha;
                int color = ((r0 + r1) >> 8 << 16) + ((g0 + g1) >> 8 << 8) + ((b0 + b1) >> 8);
                pixels[offset++] = color;
            }
        }
    }

    //ObfuscatedName("LFYNQWSZ.b(IIIIZ)V")
    void Pix2D::hline(int x, int y, int rgb, int w) {
        if (!pixels) return;
        if (y < top || y >= bottom) return;

        if (x < left) { w -= left - x; x = left; }
        if (x + w > right) w = right - x;

        int off = x + y * width;
        for (int i = 0; i < w; i++) {
            pixels[off + i] = rgb;
        }
    }

    //TODO:hlineTrans

    //ObfuscatedName("LFYNQWSZ.a(IIIZI)V")
    void Pix2D::vline(int x, int y, int rgb, int h) {
        if (!pixels) return;
        if (x < left || x >= right) return;

        if (y < top) { h -= top - y; y = top; }
        if (y + h > bottom) h = bottom - y;

        int off = x + y * width;
        for (int i = 0; i < h; i++) {
            pixels[off + i * width] = rgb;
        }
    }

    //TODO:vlineTrans

} // namespace jagex2::gfx
