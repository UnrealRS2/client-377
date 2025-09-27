#pragma once

#include <cstdint>
namespace jagex2::datastruct {
    struct Linkable {
        std::int64_t key{0};
        Linkable* next{nullptr};
        Linkable* prev{nullptr};

        void unlink() {
            if (prev) {
                prev->next = next;
                next->prev = prev;
                prev = nullptr;
                next = nullptr;
            }
        }
    };
}

