// after C++11

#include <iostream>
#include <regex>
#include <vector>

int main() {
    std::vector<std::string> file_names = {"db-123-log.txt", "db-124-log.txt",
                                           "not-db-log.txt", "db-12-log.txt",
                                           "db-12-log.jpg"};

    //std::regex re("db-\\d*-log\\.txt");
    // std::regex re("db-\\d*-log\\.txt", std::regex::grep); //grep의 정규 표현식 문법을 사용하겠다!,(default 인자는 std::ECMAScript)
    std::regex re("db--\\d*-log\\.txt", std::regex::grep | std::regex::icase | std::regex::optimize); //다양한 옵션 적용 가능, 물론 실행 안됨(grep 정규식이 아니기에)
    for (const auto &file_name : file_names) {
        std::cout << file_name << ": " << std::boolalpha << std::regex_match(file_name, re) << std::endl;
    }
}