#pragma once
#include <cstdint>

namespace jagex2::datastruct {
    struct Linkable {
        //ObfuscatedName("ZUOIJLRD.a")
        std::int64_t key{0};
        //ObfuscatedName("ZUOIJLRD.b")
        Linkable* next{nullptr};
        //ObfuscatedName("ZUOIJLRD.c")
        Linkable* prev{nullptr};

        //ObfuscatedName("ZUOIJLRD.a()V")
        inline void unlink() {
            if (prev) {
                prev->next = next;
                next->prev = prev;
                prev = nullptr;
                next = nullptr;
            }
        }
    };
}

