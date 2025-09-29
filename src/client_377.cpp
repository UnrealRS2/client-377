#include "client_377.h"

#include <utility>

#include "jagex2/client/Client.h"

extern "C" {

    CLIENT_API void SetPrintCallback(api::PrintCallback callback)
    {
        api::printCallback = std::move(callback);
    }

    CLIENT_API void SetDrawCallback(api::DrawCallback callback)
    {
        api::drawCallback = std::move(callback);
    }

    CLIENT_API void Init()
    {
        auto client = jagex2::client::Client();
        client.init_application(765, 503);
    }
}