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

int main() {
    std::vector<int> vec = {5, 3, 1, 2, 3, 4};

    /** algorithm header에서 제공하는 find 함수 계열은 컨테이너에서 기본적으로 제공해주는 find 함수보다 느리다. 따라서 컨테이너의 find를 우선적으로 사용해야한다.
     *  algorithm 의 find는 O(n)의 순차탐색일 뿐이다.
     */
    // try 1
    {
        auto result = std::find(vec.begin(), vec.end(), 3);
        std::cout << "3 은 " << std::distance(vec.begin(), result) + 1 << " 번째 원소" << std::endl;
        std::cout << "-----------------------------------------------------------" << std::endl;
    }

    // try 2
    {
        auto current = vec.begin();
        while (true) {
            current = std::find(current, vec.end(), 3);
            if (current == vec.end()) break;
            std::cout << "3 은 " << std::distance(vec.begin(), current) + 1 << " 번째 원소" << std::endl;

            current++;
        }
        std::cout << "-----------------------------------------------------------" << std::endl;
    }

    // try 3
    {
        auto current = vec.begin();
        while (true) {
            current = std::find_if(current, vec.end(),
                                   [](int i) {
                                       return i % 3 == 2;
                                   });

            if (current == vec.end()) break;
            std::cout << "3 으로 나눈 나머지 2원소 : " << *current << "임" << std::endl;

            current++;
        }
    }
}