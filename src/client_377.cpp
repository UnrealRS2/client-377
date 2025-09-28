#include "client_377.h"

#include "jagex2/client/Client.h"
#include "jagex2/io/Protocol.h"

extern "C" {

    CLIENT_API void SetPrintCallback(api::PrintCallback callback)
    {
        api::gPrintCallback = callback;
    }

    CLIENT_API void Init()
    {
        auto client = jagex2::client::Client();
        client.init_application(765, 503);
    }
}