//
// Created by tyler on 9/27/2025.
//

#include <vector>
#include <string>
#include <stdexcept>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

/**
 * Java style BigInteger modPow()
 * uses Boost 1.89.0 cpp_int header
 */
std::vector<uint8_t> java_mod_pow(
    const std::vector<uint8_t>& input,
    const std::string& dec_modulus,
    const std::string& dec_exponent)
{
    cpp_int m(dec_modulus);
    cpp_int e(dec_exponent);

    // construct input as unsigned big-endian
    cpp_int x = 0;
    for (uint8_t b : input) {
        x <<= 8;
        x += b;
    }

    // modular exponentiation
    cpp_int y = powm(x, e, m);  // like Java modPow

    // convert back to bytes padded to modulus size
    size_t mod_bytes = msb(m) / 8 + 1;
    std::vector<uint8_t> out(mod_bytes);

    for (size_t i = 0; i < mod_bytes; i++) {
        out[mod_bytes - 1 - i] = static_cast<uint8_t>(y & 0xFF);
        y >>= 8;
    }

    return out;
}
