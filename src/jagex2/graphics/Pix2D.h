#pragma once

#include "../datastruct/doublylinkable.h"
#include <vector>
#include <memory>

namespace jagex2::gfx {

    struct Pix2D : datastruct::DoublyLinkable {
        //ObfuscatedName("LFYNQWSZ.a(ZII[I)V")
        static void bind(int width, int height, int* pixels);
        //ObfuscatedName("LFYNQWSZ.a(B)V")
        static void resetClipping();
        //ObfuscatedName("LFYNQWSZ.a(IIIIZ)V")
        static void setClipping(int bottom, int right, int top, int left);
        //ObfuscatedName("LFYNQWSZ.a(I)V")
        static void clear();
        //ObfuscatedName("LFYNQWSZ.a(IIIBII)V")
        static void fillRect(int x, int y, int rgb, int w, int h);
        //ObfuscatedName("LFYNQWSZ.a(IIIIII)V")
        static void drawRect(int x, int y, int rgb, int w, int h);
        //ObfuscatedName("LFYNQWSZ.b(IIIIZ)V")
        static void hline(int x, int y, int rgb, int w);
        //ObfuscatedName("LFYNQWSZ.a(IIIZI)V")
        static void vline(int x, int y, int rgb, int h);

        static void fillCircle(int x_center, int y_center, int y_radius, int rgb, int alpha);

    private:
        //ObfuscatedName("LFYNQWSZ.m")
        static int width;
        //ObfuscatedName("LFYNQWSZ.n")
        static int height;
        //ObfuscatedName("LFYNQWSZ.o")
        static int top;
        //ObfuscatedName("LFYNQWSZ.p")
        static int bottom;
        //ObfuscatedName("LFYNQWSZ.q")
        static int left;
        //ObfuscatedName("LFYNQWSZ.r")
        static int right;
        //ObfuscatedName("LFYNQWSZ.s")
        static int bound_x;
        //ObfuscatedName("LFYNQWSZ.t")
        static int center_x;
        //ObfuscatedName("LFYNQWSZ.u")
        static int center_y;
        //ObfuscatedName("LFYNQWSZ.l")
        static int* pixels;
    };

} // namespace jagex2::gfx
