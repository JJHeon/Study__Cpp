/** 알아두면 좋을 것들
 * 1. 소멸자에서는 exception을 던지지 말 것, C++11부터 소멸자는 noexcept
 * 2. 생성자에서는 exception이 생길 경우 소멸자가 호출되지 않으므로 주의. 예를 들어 멤버 변수들 중에 heap allocation을 하는 포인터가 여러개 있는데
 *    생성자가 메모리 할당에 실패한다면  exception을 던지기 전에 지금까지 할당한 메모리들을 해제해야 함
 * 3. exception은 아무거나 던질 수 있으나, 여러 유용한 함수들 (std::nested_exception 등)과 호환이 되기 위해서는 던지는 exception은 모두 std::exception을 상속하게 하는 것이 바람직
 * 4. 템플릿으로 정의되는 class으ㅐㅣ 경우 instatiate되기 전까지는 어떤 exception을 던질 지 알 수 없으므로 catch 블록에서 모든 exception을 고려해야함
 */

#include <iostream>
#include <string>
#include <stdexcept>

int func(int c) {
    if (c == 1) {
        throw 10;
    } else if (c == 2) {
        throw std::string("hi!");
    } else if (c == 3) {
        throw 'a';
    } else if (c == 4) {
        throw "hello!";
    } else if (c == 5) {
        throw std::runtime_error("error");
    }

    return 0;
}

int main() {
    int c;
    std::cin >> c;

    try {
        func(c);
    } catch (char x) {
        std::cout << "Char : " << x << std::endl;
    } catch (int x) {
        std::cout << "Int : " << x << std::endl;
    } catch (std::string& s) {
        std::cout << "String : " << s << std::endl;
    } catch (const char* s) {
        std::cout << "String literal : " << s << std::endl;
    } catch (...) {
        std::cout << "Default Catch!" << std::endl;
    }
}