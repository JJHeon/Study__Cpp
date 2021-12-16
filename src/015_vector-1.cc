/**
 * 21.12.07
 * 2-vector의 erase 시. 상태 확인 위함
 */

#include <iostream>
#include <vector>

using namespace std;

void Print(vector<vector<int>>& target) {
    for (auto line = target.begin(); line != target.end(); ++line) {
        for (auto column = (*line).begin(); column != (*line).end(); ++column) {
            cout << *column << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> vec;
    vec.push_back(vector<int>(10, 1));
    vec.push_back(vector<int>(10, 2));
    vec.push_back(vector<int>(10, 3));
    vec.push_back(vector<int>(10, 4));
    vec.push_back(vector<int>(10, 5));
    vec.push_back(vector<int>(10, 6));
    vec.push_back(vector<int>(10, 7));
    vec.push_back(vector<int>(10, 8));
    vec.push_back(vector<int>(10, 9));
    vec.push_back(vector<int>(10, 10));

    std::cout << "First Init " << std::endl;
    Print(vec);

    std::cout << "ereae, 2, 5, 7" << endl;
    vec.erase(vec.begin() + 2);
    vec.erase(vec.begin() + 5);
    vec.erase(vec.begin() + 7);
    Print(vec);

    return 0;
}