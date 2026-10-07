#include <iostream>
#include <cstdint>

int main() {
    uint32_t ip = 0xC0A80001; // 192.168.0.1
    uint32_t first_byte = ip >> 24;
    std::cout << first_byte << std::endl;
    return 0;
}