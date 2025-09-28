#pragma once
#include <functional>
#include <string>

#ifdef CLIENT_API_EXPORTS
#define CLIENT_API __declspec(dllexport)
#else
#define CLIENT_API __declspec(dllimport)
#endif



extern "C" {
    namespace api {
        using PrintCallback = std::function<void(const char*)>;
        inline PrintCallback gPrintCallback;

        CLIENT_API void SetPrintCallback(PrintCallback callback);
        CLIENT_API void Init();
    }
}

