#include <iostream>
#include <memory>

class A {
    int* data;

   public:
    A() {
        std::cout << "자원을 획득함!" << std::endl;
        data = new int[100];
    }

    void some() { std::cout << "일반 포인터와 동일하게 사용가능!" << std::endl; }
    ~A() {
        std::cout << "자원을 해제함!" << std::endl;
        delete[] data;
    }

    void do_sth(int a) {
        std::cout << "무언가를 한다!" << std::endl;
        data[0] = a;
    }
};

void do_something() {
    std::unique_ptr<A> pa(new A());
    std::cout << "pa : ";
    pa->some();

    // std::unique_ptr<A> pb = pa;

    std::unique_ptr<A> pb = std::move(pa);
    std::cout << "pb : ";
    pb->some();

    std::cout << "after move constructor, pa : " << pa.get() << std::endl;
    std::cout << "after move constructor, pb : " << pb.get() << std::endl;

    std::cout << "now pa.get() return what nullptr ?";
    if (pa.get() == nullptr)
        std::cout << " yes\n";
    else
        std::cout << " no\n";
}

void do_something2(std::unique_ptr<A>& ptr) { ptr->do_sth(3); }

void do_something3(A* ptr) { ptr->do_sth(3); }

int main() {
    /* 1 =========================================== */
    // do_something();

    /* 2 =========================================== */

    std::unique_ptr<A> pa(new A());
    //컴파일 가능, 하지만 권장되지 않는 방식.
    // do_something2(pa);

    //옳바른 방식
    do_something3(pa.get());
}