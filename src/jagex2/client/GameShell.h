//
// Created by tyler on 9/28/2025.
//
#pragma once
#include <functional>
#include <iostream>
#include <boost/container/container_fwd.hpp>

#include "../../nullpops/util/Runnable.h"
#include "../../client_377.h"

namespace jagex2::client {
    struct GameShell {
        //ObfuscatedName("JWWAIQPI.l")
        int canvas_width;
        //ObfuscatedName("JWWAIQPI.m")
        int canvas_height;

        //ObfuscatedName("JWWAIQPI.a(III)V")
        void init_application(int width, int height);
        //ObfuscatedName("JWWAIQPI.a(Ljava/lang/Runnable;I)V")
        static void start_thread(std::function<void()> func);
        //Unobfuscated
        void run();
        //ObfuscatedName("JWWAIQPI.a(IZLjava/lang/String;)V")
        void draw_progress(int percent, const std::string& message);

    };
}
