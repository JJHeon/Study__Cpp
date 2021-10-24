/** cpp time library, chrono에 대해서
 *  시간 경과 체크하기
 */
#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>
#include <ctime>

int main() {
    std::chrono::time_point<std::chrono::high_resolution_clock> start = {};

    std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();

    // C++17 이전
    auto diff = end - start;

    auto diff2 = start - end;
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(diff).count() << "us" << std::endl;
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(diff2).count() << "us" << std::endl;

    std::time_t t = std::chrono::high_resolution_clock::to_time_t(start);
    std::cout << "현재 시간은 : " << std::put_time(std::localtime(&t), "%F %T %z") << '\n';
    std::time_t k = std::chrono::high_resolution_clock::to_time_t(end);
    std::cout << "현재 시간은 : " << std::put_time(std::localtime(&k), "%F %T %z") << '\n';
}
