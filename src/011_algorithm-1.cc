#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

template <typename Iter>
void print(Iter begin, Iter end) {
    while (begin != end) {
        std::cout << "[" << *begin << "]";
        begin++;
    }

    std::cout << std::endl;
}

struct is_odd {
    bool operator()(const int& i) { return i % 2 == 1; }
};

bool odd(const int& i) { return i % 2 == 1; }

int main() {
    std::vector<int> vec = {5, 3, 1, 2, 3, 4};

    std::cout << "첨 vec 상태 ---" << std::endl;
    print(vec.begin(), vec.end());

    std::cout << " ------------------------------------------------------- " << std::endl;
    std::cout << "벡터에서 값이 3인 원소 제거 ---" << std::endl;
    vec.erase(std::remove(vec.begin(), vec.end(), 3), vec.end());
    print(vec.begin(), vec.end());

    std::cout << " ------------------------------------------------------- " << std::endl;
    std::cout << "홀수 원소 제거 --- " << std::endl;
    // try 1
    // vec.erase(std::remove_if(vec.begin(), vec.end(), is_odd()), vec.end());

    // try 2
    // vec.erase(std::remove_if(vec.begin(), vec.end(), odd), vec.end());

    // try 3
    vec.erase(
        std::remove_if(vec.begin(), vec.end(),
                       [](int i) -> bool {
                           return i % 2 == 1;
                       }),
        vec.end());
    print(vec.begin(), vec.end());

    std::cout << " ------------------------------------------------------- " << std::endl;
    std::cout << "벡터 홀수 원소 최대 3개 제거 --- " << std::endl;
    std::vector<int> vec2 = {5, 3, 1, 2, 3, 4};
    int num_erased = 0;
    vec2.erase(
        std::remove_if(vec2.begin(), vec2.end(),
                       [&num_erased](int i) {
                           if (num_erased >= 3)
                               return false;
                           else if (i % 2 == 1) {
                               num_erased++;
                               return true;
                           }
                           return false;
                       }),
        vec2.end());
    print(vec2.begin(), vec2.end());
}
