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
        inline PrintCallback printCallback;
        CLIENT_API void SetPrintCallback(PrintCallback callback);

        using DrawCallback = std::function<void(std::vector<int> pixels, int x, int y)>;
        inline DrawCallback drawCallback;
        CLIENT_API void SetDrawCallback(DrawCallback callback);

        CLIENT_API void Init();
    }
}

