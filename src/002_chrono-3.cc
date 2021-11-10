/** Testcode for CLI-Tetris
 *  steady_clock 사용 (고해상도 말고.)
 *  여전히 현재 시간을 자주 호출하면 문제가 생긴다. - 시간을 호출하는 것이 굉장히 비싼 비용인 것으로 보임
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
long fibonacci(unsigned n) {
    if (n < 2) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int main() {
    auto end = std::chrono::time_point<std::chrono::steady_clock>::max();
    int f = 0;
    double lm = 0;
    // for (int i = 0; i < 7; i++) {
    while (true) {
        // sleep(1);
        auto start = std::chrono::steady_clock::now();
        auto diff = start - end;
        end = start;
        // double t = std::chrono::duration_cast<double>(diff).count();
        std::chrono::duration<double> diff2 = start - end;
        double t = diff2.count();
        if (t < 0) continue;
        if (t > 0) std::cout << "elapsed time: " << t << "s\n";
        lm += t;
        // std::cout << "f(42) = " << fibonacci(42 + i) << '\n';
        f++;
        if (lm > 100) {
            std::cout << "end" << std::endl;
            return 0;
        }
    }

    // 예제 분석
    // for (int i = 0; i < 5; i++) {
    //     auto start = std::chrono::steady_clock::now();
    //     std::cout << "f(42) = " << fibonacci(42 + i) << '\n';
    //     auto end = std::chrono::steady_clock::now();
    //     //std::chrono::duration<double> elapsed_seconds = end - start;
    //     auto elapsed_seconds = end - start;
    //     std::cout << "elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(elapsed_seconds).count() << "s\n";
    // }

    // error : steady_clock은 cstyle과 호환이 안됨
    // auto now = std::chrono::steady_clock::now();
    // std::time_t t = std::chrono::steady_clock::to_time_t(now);
    // std::cout << "현재 시간은 : " << std::put_time(std::localtime(&t), "%F %T %z") << '\n';
}
