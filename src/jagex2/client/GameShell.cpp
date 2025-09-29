//
// Created by tyler on 9/28/2025.
//

#include "GameShell.h"

#include <ppltasks.h>
#include <string>

#include <utility>

#include "../io/Protocol.h"


namespace jagex2::client {
    //ObfuscatedName("JWWAIQPI.a(III)V")
    void GameShell::init_application(const int width, const int height) {
        this->canvas_width = width;
        this->canvas_height = height;
        //TODO: setup drawArea
        start_thread([this] { this->run(); });
    }

    //ObfuscatedName("JWWAIQPI.a(Ljava/lang/Runnable;I)V")
    void GameShell::start_thread(std::function<void()> func) {
        std::thread([func = std::move(func)]() {
                        func();
                    }).detach();  // run in background / detach immediately so it won’t block or require join
    }

    //Unobfuscated
    void GameShell::run() {
        if (api::printCallback) {
            std::string message = "UnrealRS2 - Revision " + io::Protocol::REVISION;
            api::printCallback(message.c_str());
        }

        //TODO: Handle frame listeners

        draw_progress(0, "Loading...");
    }

    //ObfuscatedName("JWWAIQPI.a(IZLjava/lang/String;)V")
    void GameShell::draw_progress(const int percent, const std::string& message) {
        std::string line = "[" + std::to_string(percent) + "%] " + message;
        if (api::printCallback)
            api::printCallback(line.c_str());
        //TODO: Capture graphics here
        //TODO: Capture Helvetica font here
        //TODO: fill black here
        //TODO: draw loading box / text
    }
}
