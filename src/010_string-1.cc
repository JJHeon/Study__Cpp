#include <iostream>
#include <typeinfo>
#include <string>

#include <codecvt>  // codecvt_utf8 //C++17 부터 deprecated. 또한 Visual Studio에서만 가능.
#include <locale>   //wstring_convert

// literal operator는 C++14에 추가되었다. 별도로 정의하는 operator에 대해서이고 L과 같은 경우는 기존에 존재했으며 u8, u, U는 C++11에서 추가되었다.
using namespace std::literals;  // literal operator 사용 위해서는 필수.

int main() {
    // after C++14, literal operator(리터럴연산자)
    // std::string operator"" s(const char* str, std::size_t len);
    //"hello"s -[compile]-> operator""s("hello", 5);
    auto s1 = "hello"s;

    std::cout << "s1 : " << s1 << " | "
              << "type : " << typeid(s1).name() << " | "
              << "1 길이 : " << s1.size() << std::endl;
    std::cout << "-------------------------------------------------------------------------" << std::endl;

    // TYPE : narrow multibyte string literal, C++ 기본 문자열 정의는 const char*
    std::string strc = "const char*";
    std::cout << "strc : "
              << " | "
              << "type : " << typeid(strc).name() << std::endl;

    // TYPE : narrow multibyte string literal, string oeprator인 ""s가 있음.
    std::string strs = "string"s;
    std::cout << "strs : " << strs << " | "
              << "type : " << typeid(strs).name() << std::endl;

    // TYPE : wide string literal, L"..." type은 const wchar_t[N]
    std::wstring strw = L"wstring";
    std::wcout << "strw : " << strw << " | "
               << "type : " << typeid(strw).name() << std::endl;
    // TYPE : utf-8 encoded string literal, after c++20 사용가능, u8"..." type은 const char8_t[N]
    // std::u8string utru8 = u8"u8string";

    // TYPE : utf-16 encoded string literal, u"..."type은 const char16_t[N]
    std::u16string stru16 = u"u16string";
    // std::cout<<"stru16 : " << stru16 << " | " << "type : " << typeid(stru16).name() << std::endl; //error, std::cout를 사용할 수 없음

    // TYPE : utf-32 encoded string literal, U"..."type은 const char32_t[N]
    std::u32string stru32 = U"u32string";
    // std::cout<<"stru32 : " << stru32 << " | " << "type : " << typeid(stru32).name() << std::endl; //error, std::cout를 사용할 수 없음

    // C++11ㅔ 추가된 Raw String literal
    //"()안에 들어온 문자는 모두 그대로 char 배열 안에 들어감
    std::string strr = R"(asdfasdf 이 안에는 어떤 것들이 와도 ￦￦ 이런 것도 되고 #define hasldfjalskdfj \n\n <-- Escape ㅏㄴ해도 됨)";
    std::cout << strr << std::endl;

    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::string ex = "Now default : good thing is always happen!";
    std::string ep{"Examplar of new string cration"};
    std::cout << ex << std::endl;
    std::cout << ep << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;

    std::string s = "xmplr";

    // insert(size_type index, size_type count, char ch)
    s.insert(0, 1, 'E');
    std::cout << "try 1 : " << s << std::endl;
    //예측 : Emplr
    //정답 : Exmplr

    // insert(size_type index,const char* s)
    s.insert(2, "e");
    std::cout << "try 2 : " << s << std::endl;
    //예측 : Emelr
    //정답 : Exemplr

    // insert(size_type index, string const& str)
    s.insert(6, "a"s);
    std::cout << "try 3 : " << s << std::endl;
    //예측 : Emeplr a
    //정답 : Exemplar

    // insert(size_type index, string const& str,size_type index_str, size_type count)
    s.insert(8, " is an example string."s, 0, 14);
    std::cout << "try 4 : " << s << std::endl;
    //예측 : Emeplr a is an example string.
    //정답 : Exemplar is an example

    // insert(const_iterator posm,char ch)
    s.insert(s.cbegin() + s.find_first_of('n') + 1, ':');
    std::cout << "try 5 : " << s << std::endl;
    //예측 : Emeplr a is an example string.
    //정답 : Exemplar is an: example

    // insert(const_iterator pos, size_type count, char ch)
    s.insert(s.cbegin() + s.find_first_of(':') + 1, 2, '=');
    std::cout << "try 6 : " << s << std::endl;
    //예측 : Emeplr a is an:==ample string.
    //정답 : Exemplar is an:== example

    // insert(const_iterator pos, InputIt first, Input It last)
    {
        std::string seq = " string";
        s.insert(s.begin() + s.find_last_of('e') + 1, std::begin(seq), std::end(seq));
        std::cout << "try 7 : " << s << std::endl;
    }
    //예측 : Emestringplr a is an:==ample string.
    //정답 : Exemplar is an:== example string

    // insert(const_iterator pos, std::initializer_last<char>)
    s.insert(s.cbegin() + s.find_first_of('g') + 1, {'.'});
    std::cout << "try 8 : " << s << std::endl;
    //정답 : Exempler is an:== example string.
    std::cout << "----------------------------------------------------------------------------" << std::endl;
}