#include <iostream>
#include <random>

int main() {
    //시드값을 얻기 위함
    std::random_device rd;

    // random_device를 통해 난수 생성 엔진을 초기화
    std::mt19937 gen(rd());

    // 0부터 99까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
    std::uniform_int_distribution<int> dis(0, 99);

    for (int i = 0; i < 5; i++) {
        std::cout << "난수 : " << dis(gen) << std::endl;
    }
}