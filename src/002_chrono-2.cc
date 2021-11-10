/** Testcode for CLI-Tetris
 *  mile, nano, micro sconed의 단위 확인을 위함
 *  확인 결과 자주 읽어올 경우 무언가 시간이 맞지 않는다.
 */
#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>

extern "C" {
#include <ncurses.h>
#include <unistd.h>
}

int main() {
    std::chrono::time_point<std::chrono::high_resolution_clock> past = std::chrono::time_point<std::chrono::high_resolution_clock>::max();

    volatile int64_t tmp = 0;
    while (true) {
        // usleep(1);
        std::chrono::time_point<std::chrono::high_resolution_clock> present = std::chrono::high_resolution_clock::now();
        auto diff = present - past;
        past = present;

        int64_t k1 = std::chrono::duration_cast<std::chrono::nanoseconds>(diff).count();
        int64_t k2 = std::chrono::duration_cast<std::chrono::microseconds>(diff).count();
        int64_t k3 = std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();
        int64_t k4 = std::chrono::duration_cast<std::chrono::seconds>(diff).count();
        if (k3 < 0) continue;
        tmp += k3;

        if (k3 != 0) {
            // std::cout << "---------------------------------" << std::endl;
            // std::cout << "k1 : " << k1 << std::endl;
            // std::cout << "k2 : " << k2 << std::endl;
            std::cout << "k3 : " << k3 << std::endl;
            //  std::cout << "k4 : " << k4 << std::endl;
            std::cout << tmp << std::endl;
        }

        if (tmp >= 50) {
            std::cout << "end" << std::endl;
            return 0;
        }

        // std::time_t time1 = std::chrono::high_resolution_clock::to_time_t(present);
        // std::time_t time2 = std::chrono::high_resolution_clock::to_time_t(past);
    }
}
