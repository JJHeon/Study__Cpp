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

struct User {
    std::string name;
    int level;

    User(std::string name, int level) : name(name), level(level) {}
    bool operator==(const User& user) const {
        if (name == user.name && level == user.level) return true;
        return false;
    }
};

class Party {
    std::vector<User> users;

   public:
    bool add_user(std::string name, int level) {
        User new_user(name, level);
        if (std::find(users.begin(), users.end(), new_user) != users.end()) {
            return false;
        }

        users.push_back(new_user);
        return true;
    }
    //파티원 모두 랩 15 이상여야 던전 입장가능
    bool can_join_dungeon() {
        // all_of는 모든 원소들이 조건을 충족해야 true 반환
        return std::all_of(users.begin(), users.end(),
                           [](User& user) {
                               return user.level >= 15;
                           });
    }

    //파티원 중 한명이라도 19랩 이상일 경우 특별 아이템 사용 가능
    bool can_use_special_item() {
        // any_of 는 모든 원소들 중, 하나라도 충족하는 것이 있으면 true 반환
        return std::any_of(users.begin(), users.end(),
                           [](User& users) {
                               return users.level >= 19;
                           });
    }
};

int main() {
    Party party;
    party.add_user("철수", 15);
    party.add_user("영희", 18);
    party.add_user("민수", 12);
    party.add_user("수빈", 19);

    std::cout << std::boolalpha;
    std::cout << "던전 입장 가능 ? " << party.can_join_dungeon() << std::endl;
    std::cout << "특별 아이템 사용 가능? " << party.can_use_special_item() << std::endl;
}