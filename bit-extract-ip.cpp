#include <iostream>
#include <cstdint>

int main() {
    uint32_t ip = 0xC0A80001; // 這就是 192.168.0.1
    // ↑ 192=0xC0, 168=0xA8, 0=0x00, 1=0x01

    // 【你的任務】用位元運算取出最高 8 位，存進一個變數
    uint32_t first_byte = ip >> 24;

    std::cout << first_byte << std::endl; // 答對的話，應該印出 192
    return 0;
}