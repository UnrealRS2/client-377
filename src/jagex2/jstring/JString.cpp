#include <algorithm>
#include <array>
#include <cctype>
#include <sstream>

namespace jagex2::jstring {
    //ObfuscatedName("LJWIWXSK.e")
    constexpr std::array<char, 37> CHARSET = {
        '_','a','b','c','d','e','f','g','h','i',
        'j','k','l','m','n','o','p','q','r','s',
        't','u','v','w','x','y','z',
        '0','1','2','3','4','5','6','7','8','9'
    };

    //ObfuscatedName("LJWIWXSK.a(Ljava/lang/String;)J")
    int64_t to_base37(const std::string& str) {
        int64_t hash = 0;

        for (size_t i = 0; i < str.size() && i < 12; i++) {
            char c = str[i];
            hash *= 37;

            if (c >= 'A' && c <= 'Z') {
                hash += c + 1 - 'A';
            } else if (c >= 'a' && c <= 'z') {
                hash += c + 1 - 'a';
            } else if (c >= '0' && c <= '9') {
                hash += c + 27 - '0';
            }
        }

        while (hash % 37 == 0 && hash != 0) {
            hash /= 37;
        }

        return hash;
    }

    //ObfuscatedName("LJWIWXSK.a(JI)Ljava/lang/String;")
    std::string from_base37(int64_t username) {
        constexpr int64_t MAX = 6582952005840035281LL; // 37^12
        if (username <= 0 || username >= MAX) {
            return "invalid_name";
        }
        if (username % 37 == 0) {
            return "invalid_name";
        }

        std::string builder(12, '\0');
        int len = 0;

        while (username != 0) {
            int64_t last = username;
            username /= 37;
            builder[11 - len++] = CHARSET[(int)(last - username * 37)];
        }

        return builder.substr(12 - len, len);
    }

    //ObfuscatedName("LJWIWXSK.a(ILjava/lang/String;)J")
    int64_t hash_code(std::string str) {
        // uppercase in-place
        std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {
            return std::toupper(c);
        });

        int64_t hash = 0;
        for (char c : str) {
            hash = hash * 61 + static_cast<int64_t>(c) - 32;
            hash = hash + ((hash >> 56) & 0xffffffffffffffLL);
        }
        return hash;
    }

    //ObfuscatedName("LJWIWXSK.a(II)Ljava/lang/String;")
    std::string format_ipv4(uint32_t ip) {
        std::ostringstream oss;
        oss << ((ip >> 24) & 0xFF) << "."
            << ((ip >> 16) & 0xFF) << "."
            << ((ip >> 8) & 0xFF) << "."
            << (ip & 0xFF);
        return oss.str();
    }

    //ObfuscatedName("LJWIWXSK.a(Ljava/lang/String;B)Ljava/lang/String;")
    std::string format_display_name(std::string str) {
        if (str.empty()) return str;

        for (size_t i = 0; i < str.size(); i++) {
            if (str[i] == '_') {
                str[i] = ' ';
                if (i + 1 < str.size() && std::islower(str[i + 1])) {
                    str[i + 1] = static_cast<char>(str[i + 1] - 'a' + 'A');
                }
            }
        }

        if (std::islower(str[0])) {
            str[0] = static_cast<char>(str[0] - 'a' + 'A');
        }

        return str;
    }

    //INAUTHENTIC
    void to_sentence_case(std::string& str) {
        std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {
            return std::tolower(c);
        });

        bool capitalize = true;
        for (char& c : str) {
            if (capitalize && std::islower(c)) {
                c = static_cast<char>(c - 'a' + 'A');
                capitalize = false;
            }
            if (c == '.' || c == '!') {
                capitalize = true;
            }
        }
    }

    //ObfuscatedName("LJWIWXSK.b(ILjava/lang/String;)Ljava/lang/String;")
    std::string censor(const std::string& str) {
        return std::string(str.size(), '*');
    }

}
