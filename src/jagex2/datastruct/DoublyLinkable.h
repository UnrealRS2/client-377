#pragma once

#include "Linkable.h"

namespace jagex2::datastruct {
    struct DoublyLinkable : Linkable {
        DoublyLinkable* next2{nullptr};
        DoublyLinkable* prev2{nullptr};

        void uncache() {
            if (prev2) {
                prev2->next2 = next2;
                next2->prev2 = prev2;
                prev2 = nullptr;
                next2 = nullptr;
            }
        }
    };
}

