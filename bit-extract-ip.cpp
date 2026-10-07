#include <iostream>
#include <cstdint>

int main() {
    unsigned int ip = 0xC0A80001; // 192.168.0.1
    unsigned int first_byte = ip >> 24;
    std::cout << first_byte << '\n';
    return 0;
}