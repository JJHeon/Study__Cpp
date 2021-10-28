/** string handling의 모든 것
 *  cppreference 참고.
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <regex>

int main() {
    /** std::string::npos 란?
     *  본래는 const size_type == const size_t 이며 모든 비트가 1인 최대값을 의마하는 unsigned integer type이다. 하지만 signed로 변경하면 -1 이기에, 정수형으로 -1의 값을 가진다.
     *  if문에서 문자열의 끝으로 활용 가능 (e.i if( n == std::string::npos)와 같이)
     */

    /** 삽입 - insert
     *  param은 Iterator, size_t인 pos 가 있음.
     *  기존 문자열을 뒤로 밀어내면서 삽입.
     *  Index 위치, 입력할 string(or char*), 입력할 string의 pos, size 필요.
     *  Iterator로 입력 받을 곳, 입력할 string 각각 지정 가능.
     */
    {
        std::cout << "------------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "삽입 - insert \n-----------------------------------------------------------------------------------------------" << std::endl;
        using namespace std::literals;
        std::string s = "xmplr";

        // insert(size_type index, size_type count, char ch)
        s.insert(0, 1, 'E');
        std::cout << "try 1 : " << s << std::endl;
        //예측 : Emplr
        //정답 : Exmplr

        // insert(size_type index,const char* s)
        s.insert(2, "e");
        std::cout << "try 2 : " << s << std::endl;
        //정답 : Exemplr

        // insert(size_type index, string const& str)
        s.insert(6, "a"s);
        std::cout << "try 3 : " << s << std::endl;
        //정답 : Exemplar

        // insert(size_type index, string const& str,size_type index_str, size_type count)
        s.insert(8, " is an example string."s, 0, 14);
        std::cout << "try 4 : " << s << std::endl;
        //정답 : Exemplar is an example

        // insert(const_iterator posm,char ch)
        s.insert(s.cbegin() + s.find_first_of('n') + 1, ':');
        std::cout << "try 5 : " << s << std::endl;
        //정답 : Exemplar is an: example

        // insert(const_iterator pos, size_type count, char ch)
        s.insert(s.cbegin() + s.find_first_of(':') + 1, 2, '=');
        std::cout << "try 6 : " << s << std::endl;
        //정답 : Exemplar is an:== example

        // insert(const_iterator pos, InputIt first, Input It last)
        {
            std::string seq = " string";
            s.insert(s.begin() + s.find_last_of('e') + 1, std::begin(seq), std::end(seq));
            std::cout << "try 7 : " << s << std::endl;
        }
        //정답 : Exemplar is an:== example string

        // insert(const_iterator pos, std::initializer_last<char>)
        s.insert(s.cbegin() + s.find_first_of('g') + 1, {'.'});
        std::cout << "try 8 : " << s << std::endl;
    }

    /* ----------------------------------------------------------------------------------------------- */
    /** 제거 - erase
     *  param으로 iterator와 size_t로 된 index, count를 받음.
     *  지정된 index를 지우고 앞으로 당긴다.
     *  index만 인자로 받을시, index부터 끝까지 지워버린다.
     */
    {
        std::cout << "------------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "제거 - erase \n-----------------------------------------------------------------------------------------------" << std::endl;

        std::string s = "This is an example";
        std::cout << s << '\n';

        s.erase(0, 5);  // Erase "This "
        std::cout << s << '\n';

        s.erase(std::find(s.begin(), s.end(), ' '));  // Erase ' '
        std::cout << s << '\n';

        s.erase(s.find(' '));  // Trim from ' ' to the end of the string //string.find는 size_t를 return한다. (std::find 는 iterator를 반환한다.) 따라서 std::find와 다르게, 해당 index부터 끝까지 전체를 지워버린다.
        std::cout << s << '\n';
    }

    /* ----------------------------------------------------------------------------------------------- */
    /** 이어 붙이기 - append
     *  param 으로
     *  count, char
     *  string
     *  string, string의 시작 index, string의 count
     *  char*, count
     *  char*,
     *  char*, 끝 범위. (주소로 줄 경우 (iterator와 비슷한 맥락))
     *  이 있음.
     */
    {
        std::cout << "------------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "이어 붙이기 - append \n-----------------------------------------------------------------------------------------------" << std::endl;

        std::basic_string<char> str = "string";
        const char* cptr = "C-string";
        const char carr[] = "Two and one";

        std::string output;

        // 1) Append a char 3 times.
        // Notice, this is the only overload accepting chars.
        output.append(3, '*');
        std::cout << "1) " << output << "\n";

        //  2) Append a whole string
        output.append(str);
        std::cout << "2) " << output << "\n";

        // 3) Append part of a string (last 3 letters, in this case)
        output.append(str, 3, 3);
        std::cout << "3) " << output << "\n";

        // 4) Append part of a C-string
        // Notice, because `append` returns *this, we can chain calls together
        output.append(1, ' ').append(carr, 4);
        std::cout << "4) " << output << "\n";

        // 5) Append a whole C-string
        output.append(cptr);
        std::cout << "5) " << output << "\n";

        // 6) Append range
        output.append(&carr[3], std::end(carr));
        std::cout << "6) " << output << "\n";

        // 7) Append initializer list
        output.append({' ', 'l', 'i', 's', 't'});
        std::cout << "7) " << output << "\n";
    }
    /* ----------------------------------------------------------------------------------------------- */
    /** 문자(문자열) 찾기 - find
     *  reverse version과 char를 위한 _of가 있음. find는 string 객체 용도.
     *  string 객체의 find는 size_t를 반환함.
     *  param으로
     *  char*
     *  char*, pos
     *  char
     *  string, pos
     *  가 있음
     */
    {
        std::cout << "------------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "문자(문자열) 찾기 - find \n-----------------------------------------------------------------------------------------------" << std::endl;

        std::string::size_type n;
        std::string const s = "This is a string";

        // search from beginning of string
        n = s.find("is");
        std::cout << "find result : " << n << " , " << s << std::endl;

        // search from position 5
        n = s.find("is", 5);
        std::cout << "find result : " << n << " , " << s << std::endl;

        // find a single character
        n = s.find('a');
        std::cout << "find result : " << n << " , " << s << std::endl;

        // find a single character
        n = s.find('q');
        std::cout << "find result : " << n << " , " << s << std::endl;   // q가 없기에 n은 말도 안되는 error의 값을 가진다.
        if (n == std::string::npos) std::cout << "false!" << std::endl;  //결과로 false! 실행됨
    }

    /* ----------------------------------------------------------------------------------------------- */
    /** 길이 반환 - length, size
     *  size와 length는 같음.
     *  사용할 타입의 바이트 수를 반환
     */
    {
        std::cout << "------------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "길이 반환 - length,size \n-----------------------------------------------------------------------------------------------" << std::endl;

        std::string s("Exemplar");
        std::cout << "size : " << s.size() << std::endl;
        std::cout << "size from distance? : " << static_cast<std::string::size_type>(std::distance(s.begin(), s.end())) << std::endl;
        std::cout << "length : " << s.length() << std::endl;
        std::cout << "max size ? : " << s.max_size() << std::endl;

        std::u32string a(U"ハロー・ワールド");
        std::cout << "what about u32 : " << a.size() << std::endl;  // 8

        std::u16string b(u"ハロー・ワールド");
        std::cout << "what about u16 : " << b.size() << std::endl;  // 8

        std::string c("ハロー・ワールド");
        std::cout << "normal size: " << c.size() << std::endl;      // 24 //store할 객체에 따라 byte크기가 달라진다.
        std::cout << "normal length: " << c.length() << std::endl;  // 24 //store할 객체에 따라 byte크기가 달라진다.
    }
    /* ----------------------------------------------------------------------------------------------- */
    /** 비교 - compare
     *  C 의 strcmp와 같다. 아스키코드값 비교
     *  특이점으로 operator를 그냥 사용해 비교해도 됨
     *  compare는 사전적으로 비교하고자 하는 문자열보다 앞에 위치했을때, 해당 위치 값을 반환하는데. (-1 이면 1st parm, 1이면 2st parm), 사전 순으로 비교한다.
     *  근데 compare과 oepraotr가 같은것 같음.
     */
    {
        std::cout << "------------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "비교 - compare \n-----------------------------------------------------------------------------------------------" << std::endl;

        using namespace std::literals;
        // 0) operator 사용 비교
        std::string s1 = "Abcdefg"s;  // A의 아스키코드값 : 65, 0x41
        std::string s2 = "abcdefg"s;  // a의 아스키코드값 : 97, 0x61
        std::string s3 = "1bcdefg"s;  // 1의 아스키코드값 : 48, 0x30

        // std::cout << std::boolalpha;
        std::cout << "0) s1 == s2 : " << (s1 == s2) << std::endl;
        std::cout << "0) s1 != s2 : " << (s1 != s2) << std::endl;
        std::cout << "0) s1 > s2 : " << (s1 > s2) << std::endl;             // false  // s1은 s2에 비해 뒤져있다. (a의 아스키코드값이 크다. A: 65, a : 97)  따라서 false
        std::cout << "0) s1 < s2 : " << (s1 < s2) << std::endl;             // true
        std::cout << "0) s1 compare s2 : " << s1.compare(s2) << std::endl;  // result : -1 //s1 < s2 의미
        std::cout << "0) s2 > s3 : " << (s2 > s3) << std::endl;
        std::cout << "0) s2 compare s3 : " << s2.compare(s3) << std::endl;  // result : 1 // s2 > s3 의미
        std::cout << std::noboolalpha;
        // 1) Compare with other string
        {
            int compare_value{
                std::string{"Batman"}.compare(std::string{"Superman"})};
            std::cout << (compare_value < 0 ? "Batman comes before Superman\n" : compare_value > 0 ? "Superman comes before Batman\n"
                                                                                                   : "Superman and Batman are the same.\n");
        }

        // 2) Compare substring with other string
        {
            int compare_value{
                std::string{"Batman"}.compare(3, 3, std::string{"Superman"})};
            std::cout << (compare_value < 0 ? "man comes before Superman\n" : compare_value > 0 ? "Superman comes before man\n"
                                                                                                : "man and Superman are the same.\n");
        }

        // 3) Compare substring with other substring
        {
            std::string a{"Batman"};
            std::string b{"Superman"};

            int compare_value{a.compare(3, 3, b, 5, 3)};

            std::cout << (compare_value < 0 ? "man comes before man\n" : compare_value > 0 ? "man comes before man\n"
                                                                                           : "man and man are the same.\n");
            // Compare substring with other substring
            // defaulting to end of other string
        }

        // 4) Compare with char pointer
        {
            int compare_value{std::string{"Batman"}.compare("Superman")};

            std::cout << (compare_value < 0 ? "Batman comes before Superman\n" : compare_value > 0 ? "Superman comes before Batman\n"
                                                                                                   : "Superman and Batman are the same.\n");
        }

        // 5) Compare substring with char pointer
        {
            int compare_value{std::string{"Batman"}.compare(3, 3, "Superman")};

            std::cout << (compare_value < 0 ? "man comes before Superman\n" : compare_value > 0 ? "Superman comes before man\n"
                                                                                                : "man and Superman are the same.\n");
        }

        // 6) Compare substring with char pointer substring
        {
            int compare_value{std::string{"Batman"}.compare(0, 3, "Superman", 5)};

            std::cout << (compare_value < 0 ? "Bat comes before Super\n" : compare_value > 0 ? "Super comes before Bat\n"
                                                                                             : "Super and Bat are the same.\n");
        }
    }

    /* ----------------------------------------------------------------------------------------------- */
    /** 복사 - copy
     *  copy는 string에서 char[] 로 복사할 때 사용함.
     */
    {
        std::cout << "------------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "복사 - copy \n-----------------------------------------------------------------------------------------------" << std::endl;
        std::string foo("quuuux");
        char bar[7]{};
        foo.copy(bar, sizeof bar);
        std::cout << bar << '\n';
    }
    /* ----------------------------------------------------------------------------------------------- */
    /** 문자열 부분 반환 - substr
     *  문자열의 부분을 복사해 반환한다.
     *  param으로
     *  pos
     *  pos, count
     *  가 있음
     */
    {
        std::cout << "------------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "문자열 부분 반환 - substr \n-----------------------------------------------------------------------------------------------" << std::endl;

        std::string a = "0123456789abcdefghij";
        std::string is_really_copied;

        {
            std::string b = "0123456789abcdefghij";
            // count is npos, returns [pos, size())
            std::string sub1 = b.substr(10);
            std::cout << sub1 << '\n';
            // address 확인
            std::cout << "b address : " << &b << " , " << b.c_str() << std::endl;
            std::cout << "sub1 address : " << &sub1 << " , " << sub1.c_str() << std::endl;

            is_really_copied = sub1;  //부분 string이 객체가 복사되었는지 확인하기 위함
        }
        //복사되었는지?
        std::cout << "is it copied? " << is_really_copied << std::endl;  // result : 복사됨. //b를 참조했지만 b는 소멸했음

        // both pos and pos+count are within bounds, returns [pos, pos+count)
        // 경계선 안쪽까지를 의미
        std::string sub2 = a.substr(5, 3);
        std::cout << sub2 << '\n';

        // pos is within bounds, pos+count is not, returns [pos, size())
        // pos는 경계 안쪽이지만, count가 더 클 경우를 의미. 이 경우는 error 가 아니고 [pos, size()] 까지 처리됨.
        std::string sub4 = a.substr(a.size() - 3, 50);
        // this is effectively equivalent to
        // std::string sub4 = a.substr(17, 3);
        // since a.size() == 20, pos == a.size()-3 == 17, and a.size()-pos == 3

        std::cout << sub4 << '\n';

        // pos가 경계밖으로 나간 경우
        try {
            // pos is out of bounds, throws
            std::string sub5 = a.substr(a.size() + 3, 50);
            std::cout << sub5 << '\n';
        } catch (const std::out_of_range& e) {
            std::cout << "pos exceeds string size\n";
        }
    }

    /* ----------------------------------------------------------------------------------------------- */
    /** 문자열, 숫자로 변환 - stoi, stol, stoll
     *  사용시 cstdlib 내장 함수로 자동 번역된다.
     */
    {
        std::cout << "------------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "문자열, 숫자로 변환 - stoi, stol, stoll \n-----------------------------------------------------------------------------------------------" << std::endl;

        std::string str1 = "45";
        std::string str2 = "3.14159";
        std::string str3 = "31337 with words";
        std::string str4 = "words and 2";

        int myint1 = std::stoi(str1);  // std::strtol(str.c_str(), &ptr, base) 이와 같이 번역됨
        int myint2 = std::stoi(str2);
        int myint3 = std::stoi(str3);

        std::cout << "std::stoi(\"" << str1 << "\") is " << myint1 << '\n';
        std::cout << "std::stoi(\"" << str2 << "\") is " << myint2 << '\n';
        std::cout << "std::stoi(\"" << str3 << "\") is " << myint3 << '\n';
    }

    /* ----------------------------------------------------------------------------------------------- */
    /** token 반환
     *  이 문제는 명쾌하지 않다.
     *  C++ template 기반 하에서 각 Container에 대해서 다양한 type과 Iterator를 가지기 떄문에, 일관성 있는 method 혹은 function이 없다.
     *  따라서 다른 method를 이용해 다양한 방법을 기술한다.
     *  보다 완벽한 Split은 Boost library, Qt, GNU String Utility Function  등이 구현되있다. 표준은 그렇지 못함.
     *  참고
     *  https://stackoverflow.com/questions/53849/how-do-i-tokenize-a-string-in-c
     *  https://plein-de-verite.tistory.com/339
     *  https://www.fluentcpp.com/2017/04/21/how-to-split-a-string-in-c/
     */
    {
        std::cout << "------------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "token 반환 \n-----------------------------------------------------------------------------------------------" << std::endl;
        // Sol 1. getline 이용
        // 단점으로 다수의 delimiter를 쓰지 못한다.
        {
            std::cout << "try 1 ================================================================================ " << std::endl;
            std::string line = "Tokenizing a string with stringstream";
            std::string line2 = "Tokenizing\na\nstring\nwith\nstringstream\n";
            std::string line3 = "Tokenizing\ta\tstring\twith\tstringstream\t";

            std::vector<std::string> words;

            std::istringstream sstream(line);
            std::string word;

            while (std::getline(sstream, word, ' ')) {
                words.push_back(word);
            }
            //만약 word에 token 하나만 빼고 중지하면 무슨일이 일어날까?
            //-> 객체 line에는 주소값 및 value 변동이 없다.
            // sstream의 buf에 남겨져있는데, sstream으로 line을 받은 순간 복사한 것으로 추측됨

            // for (int i = 0; i < static_cast<int>(words.size()); i++) std::cout << words[i] << std::endl;

            for (int i = 0; i < static_cast<int>(words.size()); i++) std::cout << words[i] << std::endl;
        }

        // Sol 2. find() 와 substr() 이용
        {
            std::cout << "try 2 ================================================================================ " << std::endl;
            std::string line = "i am who i am and i have the need to be.";
            std::string delim = " ";
            std::vector<std::string> words{};

            size_t pos = 0;
            while ((pos = line.find(delim)) != std::string::npos) {
                words.push_back(line.substr(0, pos));
                line.erase(0, pos + delim.length());  //찾아서 얻은 만큼을 삭제함
            }

            for (const auto& w : words) {
                std::cout << w << std::endl;
            }
        }

        // Sol 3. strtok() 사용
        // 결론적으로 C style이며, string 객체로부터 꺼내야한다. c_str()은 const char* type을 반환하기에 byte에 복사해 사용하느 것이 권장됨
        // C style이기 때문에, 많이 번거롭다.
        // strtok, strtok_r, strtok_s, 3가지 버전이 존재하는데
        // strtok_r은 표준이 아니며 thread safe하다., strtok_s는 C11 이후에 나온 thread safe version이다.
        // strtok는 thread unsafe하며. c style이며, bufferoverflow 가능성이 존재한다. //thread가 NULL이 담긴 주소값을 변경할 경우.
        {
            std::cout << "try 3-1 ================================================================================ " << std::endl;
            // char str[] = "Little Prince"; //가능

            std::string strs = "Little Prince";
            char* str = (char*)malloc(sizeof(char) * strs.size() + 1);
            strs.copy(str, strs.size());

            char* token;
            char* rest = str;

            while ((token = strtok_r(rest, " ", &rest)) != NULL) {
                printf("%s\n", token);
            }

            free(str);

            // char str2[] = "i am who i am and i have the need to be";
            std::string strs2 = "i am whodd i am and i have the need to be";
            char str2[10];
            memset(str2, 0, sizeof(str2));

            // 위 예제는 동적할당을 통해서 완벽하게 copy해 결과물이 char[] version과 동일한데,
            // string.copy의 2st parm이 복사할 크기이기 때문에, 이 복사할 크기만큼의 char []가 필요하다.
            // 지금은 임의로 10이기 때문에, i am whod 까지만 복사되어 tokenize 된다.
            strs2.copy(str2, sizeof(str2) - 1);  //복사할 크기로 Null-terminated를 생각해야함.

            char* token2;
            std::cout << "try 3-2 ================================================================================ " << std::endl;
            token2 = strtok(str2, " ");
            while (token2 != NULL) {
                printf("%s\n", token2);
                token2 = strtok(NULL, " ");
            }
        }

        // Sol 4. <regex> 정규식 활용
        {
            std::cout << "try 4-1 ================================================================================ " << std::endl;
            std::string str = "Break String a,spaces,and,commas";
            std::regex re(R"([\s|,]+)");

            std::sregex_token_iterator it{str.begin(), str.end(), re, -1};
            std::vector<std::string> tokenized{it, std::sregex_token_iterator{}};

            tokenized.erase(std::remove_if(tokenized.begin(), tokenized.end(),
                                           [](std::string const& s) {
                                               return s.size() == 0;
                                           }),
                            tokenized.end());

            for (std::string token : tokenized) std::cout << token << std::endl;

            std::cout << "try 4-2 ================================================================================ " << std::endl;
            {
                std::string str("version 1.20.300.400");
                std::regex pattern("([0-9]+)\\.([0-9]+)\\.([0-9]+)\\.([0-9]+)");
                {
                    std::sregex_token_iterator begin(str.begin(), str.end(), pattern, {1, 3});  //마지막 parm이 reverse-reference의 인자값으로 보이는데.
                    std::sregex_token_iterator end;
                    std::for_each(begin, end,
                                  [](const std::string& sub) {
                                      std::cout << sub << std::endl;  // 1 300
                                  });
                }
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                {
                    std::string str("version 1.20.300.400");
                    std::regex pattern("([0-9]+)\\.([0-9]+)\\.([0-9]+)\\.([0-9]+)");
                    {
                        std::sregex_token_iterator begin(str.begin(), str.end(), pattern, {2, 4});
                        std::sregex_token_iterator end;
                        std::for_each(begin, end,
                                      [](const std::string& sub) {
                                          std::cout << sub << std::endl;  // 20 400
                                      });
                    }
                }
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                {
                    std::string str("version 1.20.300.400");
                    std::regex pattern("([0-9]+)\\.([0-9]+)\\.([0-9]+)\\.([0-9]+)");
                    {
                        std::sregex_token_iterator begin(str.begin(), str.end(), pattern, 0);
                        std::sregex_token_iterator end;
                        std::for_each(begin, end,
                                      [](const std::string& sub) {
                                          std::cout << sub << std::endl;  // 1.20.300.400
                                      });
                    }
                }
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                {
                    std::string str("version 1.20.300.400 nothing happen");
                    std::regex pattern("([0-9]+)\\.([0-9]+)\\.([0-9]+)\\.([0-9]+)");
                    {
                        std::sregex_token_iterator begin(str.begin(), str.end(), pattern, -1);
                        std::sregex_token_iterator end;
                        std::for_each(begin, end,
                                      [](const std::string& sub) {
                                          std::cout << sub << std::endl;  // version
                                      });
                    }
                }
            }
        }
    }
}