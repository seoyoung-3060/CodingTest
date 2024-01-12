#include <iostream>
#include <string>
#include <deque>
using namespace std;

/*
k개의 수를 제거했을 때 얻을 수 있는 가장 큰 숫자 구하기
- stack 이용해보기
k가 채워지기전까지 top과 뒷 숫자를 배교 후 top이 더 작으면 pop하기
=> 어차피 앞부분 숫자 작은거 빼는게 가장 큰 숫자를 구하는 것이기 때문에 괜찮을듯ㅇㅇ
*/

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string number = "1231234";
    string answer = "";
    int k = 3;
    int cnt = 0;

    deque<char> s;


    for(int i=0; i<number.size(); i++) {
        char curr = number[i];

        while(!s.empty() && s.back() < curr && k > 0) {
            s.pop_back();
            k--;
        }
        s.push_back(curr);
    }

    while(k--) s.pop_back();

    for(auto x: s) answer += x;

    cout << answer << endl;

    return 0;
}