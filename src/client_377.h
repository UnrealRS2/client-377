// MyClientWrapper.h
#pragma once

#ifdef CLIENT_API_EXPORTS
#define CLIENT_API __declspec(dllexport)
#else
#define CLIENT_API __declspec(dllimport)
#endif

extern "C" {

    typedef void (*PrintCallback)(const char* message);

    CLIENT_API void SetPrintCallback(PrintCallback callback);
    CLIENT_API void Init();
}

