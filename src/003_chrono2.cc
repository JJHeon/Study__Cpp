/**
 * 시스템 시간을 날짜로 변환해주는 방법이 없기 때문에, C library를 빌려서 써야한다.
 */

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>

int main() {
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::cout << "현재 시간은 : " << std::put_time(std::localtime(&t), "%F %T %z") << '\n';
}