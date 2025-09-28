//
// Created by tyler on 9/27/2025.
//

#pragma once
#include <string>

#include "GameShell.h"
#include "../../def.h"

namespace jagex2::client {
    struct Client : GameShell {
        //INAUTHENTIC
        int revision = REVISION;
        //ObfuscatedName("client.sc")
        int node_id = NODE_ID;
        //ObfuscatedName("client.tc")
        int port_offset = PORT_OFFSET;
        //ObfuscatedName("client.uc")
        bool members = MEMBERS;
        //ObfuscatedName("client.vc")
        bool low_memory = LOW_MEMORY;
        //ObfuscatedName("client.Wj")
        std::string modulus = RSA_MODULUS;
        //ObfuscatedName("client.N")
        std::string exponent = RSA_EXPONENT;
        //ObfuscatedName("client.fk")
        int loop_cycle;

        //TODO:Verify
        std::string socket_ip;
    };
}
