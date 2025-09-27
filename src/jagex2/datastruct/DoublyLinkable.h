#pragma once
#include "Linkable.h"

namespace jagex2::datastruct {
    struct DoublyLinkable : Linkable {
        //ObfuscatedName("DPPNUUMQ.e")
        DoublyLinkable* next2{nullptr};
        //ObfuscatedName("DPPNUUMQ.f")
        DoublyLinkable* prev2{nullptr};

        //ObfuscatedName("DPPNUUMQ.b()V")
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

