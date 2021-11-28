/**
 * 21.11.28
 * array 객체 복사가 완벽한지 test
 * 객체 복사생성 이상 없음
 *
 * 이중 배열 객체의 경우.
 * array 구조 파악
 */

#include <iostream>
#include <array>

using namespace std;

int main() {
    cout << "기준 ======" << endl;
    array<int, 5> arr1 = {1, 2, 3, 4, 5};
    for (auto k : arr1) cout << k << " ";
    cout << endl;

    cout << "객채 복사 생성 ======" << endl;
    array<int, 5> arr2 = arr1;
    for (auto k : arr2) cout << k << " ";
    cout << endl;

    cout << "포인터 객체 생성 ======" << endl;
    array<int, 5>* arr3 = new array{1, 2, 3, 4, 5};
    for (auto k : *arr3) cout << k << " ";
    cout << endl;

    cout << "포인터 객체 복사 생성 ======" << endl;
    array<int, 5> arr4 = *arr3;
    for (auto k : arr4) cout << k << " ";
    cout << endl;

    cout << "원본 포인터 객체 파괴 후======" << endl;
    delete arr3;
    for (auto k : arr4) cout << k << " ";
    cout << endl;

    array<array<int, 3>, 5> darr;
    for (auto i_1 = darr.begin(); i_1 != darr.end(); i_1++) {
        for (auto i_2 = (*i_1).begin(); i_2 != (*i_1).end(); i_2++) {
            *i_2 = 0;
        }
    }

    cout << " double array =====" << endl;
    for (auto i_1 = darr.begin(); i_1 != darr.end(); i_1++) {
        for (auto i_2 = (*i_1).begin(); i_2 != (*i_1).end(); i_2++) {
            cout << *i_2 << " ";
        }
        cout << endl;
    }

    return 0;
}