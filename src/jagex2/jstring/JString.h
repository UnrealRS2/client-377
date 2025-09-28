//
// Created by tyler on 9/27/2025.
//

#pragma once
#include <cstdint>
#include <string>

namespace jagex2::jstring {
    //ObfuscatedName("LJWIWXSK.a(Ljava/lang/String;)J")
    int64_t to_base37(const std::string& str);
    //ObfuscatedName("LJWIWXSK.a(JI)Ljava/lang/String;")
    std::string from_base37(int64_t username);
    //ObfuscatedName("LJWIWXSK.a(ILjava/lang/String;)J")
    int64_t hash_code(std::string str); // passed by value so we can mutate
    //ObfuscatedName("LJWIWXSK.a(II)Ljava/lang/String;")
    std::string format_ipv4(uint32_t ip);
    //ObfuscatedName("LJWIWXSK.a(Ljava/lang/String;B)Ljava/lang/String;")
    std::string format_name(std::string str);
    //INAUTHENTIC
    void to_sentence_case(std::string& str);
    //ObfuscatedName("LJWIWXSK.b(ILjava/lang/String;)Ljava/lang/String;")
    std::string censor(const std::string& str);
}
