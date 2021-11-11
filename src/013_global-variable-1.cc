/**
 * TestCode for CLI-Tetris Project
 * Global Variable을 class의 멤버변수가 참조할 수 있는지?
 * 문제는 없는지? 여부 확인
 */

#include <iostream>

static int A = 100;

class Test {
   private:
    int A;

   public:
    Test(int a) : A(a) {}
    ~Test() {}

    void Print() {
        std::cout << "A is " << ::A << std::endl;
        ++::A;
        std::cout << "now A is " << ::A << std::endl;
        std::cout << "member A is " << A << std::endl;
    }
};

int main() {
    Test class_test(5);

    class_test.Print();

    return 0;
}