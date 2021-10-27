#include <iostream>
#include <regex>

int main() {
    // try 1
    {
        std::string html = R"(
        <div class="social-login">
          <div class="small-comment">다음으로 로그인 </div>
          <div>
            <i class="xi-facebook-official fb-login"></i>
            <i class="xi-google-plus goog-login"></i>
          </div>
        </div>
        <div class="manual">
          <div class="small-comment">
            또는 직접 입력하세요 (댓글 수정시 비밀번호가 필요합니다)
          </div>
          <input name="name" id="name" placeholder="이름">
          <input name="password" id="password" type="password" placeholder="비밀번호">
        </div>
        <div id="adding-comment" class="sk-fading-circle">
          <div class="sk-circle1 sk-circle">a</div>
          <div class="sk-circle2 sk-circle">b</div>
          <div class="sk-circle3 sk-circle">asd</div>
          <div class="sk-circle4 sk-circle">asdfasf</div>
          <div class="sk-circle5 sk-circle">123</div>
          <div class="sk-circle6 sk-circle">aax</div>
          <div class="sk-circle7 sk-circle">sxz</div>
        </div>
  )";
        std::regex re(R"(<div class="sk[\w -]*">\w*</div>)");
        std::smatch match;
        // regex-2와 다르게 한개의 string에서 종합적으로 search하고 있음을 알 수 있다.
        while (std::regex_search(html, match, re)) {
            std::cout << match.str() << std::endl;
            html = match.suffix();  // std::sub_match 객체 리턴, 검색된 패턴 뒤부터 문자열 끝까지 가르키는 sub_match 객체를 리턴함
            // sub_match class는 string으로 변환 가능한 캐스팅연산자가 있다.
        }
    }
    std::cout << "-------------------------------------------------------------------" << std::endl;
    // try 2
    {
        std::string html = R"(
        <div class="social-login">
          <div class="small-comment">다음으로 로그인 </div>
          <div>
            <i class="xi-facebook-official fb-login"></i>
            <i class="xi-google-plus goog-login"></i>
          </div>
        </div>
        <div class="manual">
          <div class="small-comment">
            또는 직접 입력하세요 (댓글 수정시 비밀번호가 필요합니다)
          </div>
          <input name="name" id="name" placeholder="이름">
          <input name="password" id="password" type="password" placeholder="비밀번호">
        </div>
        <div id="adding-comment" class="sk-fading-circle">
          <div class="sk-circle1 sk-circle">a</div>
          <div class="sk-circle2 sk-circle">b</div>
          <div class="sk-circle3 sk-circle">asd</div>
          <div class="sk-circle4 sk-circle">asdfasf</div>
          <div class="sk-circle5 sk-circle">123</div>
          <div class="sk-circle6 sk-circle">aax</div>
          <div class="sk-circle7 sk-circle">sxz</div>
        </div>
  )";
        std::regex re(R"(<div class="sk[\w -]*">\w*</div>)");
        std::smatch match;

        auto start = std::sregex_iterator(html.begin(), html.end(), re);
        auto end = std::sregex_iterator();

        while (start != end) {
            std::cout << start->str() << std::endl;
            ++start;
        }
    }
    std::cout << "-------------------------------------------------------------------" << std::endl;

    // try another,replace
    {
        std::string html = R"(
        <div class="social-login">
          <div class="small-comment">다음으로 로그인 </div>
          <div>
            <i class="xi-facebook-official fb-login"></i>
            <i class="xi-google-plus goog-login"></i>
          </div>
        </div>
        <div class="manual">
          <div class="small-comment">
            또는 직접 입력하세요 (댓글 수정시 비밀번호가 필요합니다)
          </div>
          <input name="name" id="name" placeholder="이름">
          <input name="password" id="password" type="password" placeholder="비밀번호">
        </div>
        <div id="adding-comment" class="sk-fading-circle">
          <div class="sk-circle1 sk-circle">a</div>
          <div class="sk-circle2 sk-circle">b</div>
          <div class="sk-circle3 sk-circle">asd</div>
          <div class="sk-circle4 sk-circle">asdfasf</div>
          <div class="sk-circle5 sk-circle">123</div>
          <div class="sk-circle6 sk-circle">aax</div>
          <div class="sk-circle7 sk-circle">sxz</div>
        </div>
  )";
        std::regex re(R"r(sk-circle(\d))r");  // r()r 이란 구분자 있음 안에 () 넣기위해.
        std::smatch match;

        std::string modified_html = std::regex_replace(html, re, "$1-sk-circle");
        std::cout << modified_html;
    }
}