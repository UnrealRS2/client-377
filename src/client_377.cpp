#include "client_377.h"

#include <iostream>

#include "jagex2/io/protocol.h"

static PrintCallback gPrintCallback = nullptr;

extern "C" {

    CLIENT_API void SetPrintCallback(PrintCallback callback)
    {
        gPrintCallback = callback;
    }

    CLIENT_API void Init()
    {
        if (gPrintCallback) {
            const std::string message = "UnrealRS2 - Revision " + jagex2::io::Protocol::REVISION;
            gPrintCallback(message.c_str());
        }
    }
}