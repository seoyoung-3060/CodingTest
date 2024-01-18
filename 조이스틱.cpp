#include <iostream>
#include <string>
using namespace std;

/*
위 : 다음
아래 : 이전 (A면 Z로)
왼쪽 : 왼쪽 (첫번째면 마지막으로)
오른쪽 : 오른쪽 (마지막이면 첫번째로)

조이스틱 최소화로 문자열 만들기
초기상태 - 전부 A

1. 위,아래 조이스틱 최소 : 'A' <-> target 거리 구하기
- min(target-'A', 'Z'-target+1)

2. 왼,오 조이스틱 최소

다시 생각하셈.

*/

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string name; cin >> name;
    int answer = 0;
    int shift = name.size() - 1;

    for(int i=0; i<name.size(); i++) {
        if(name[i] == 'A') {
            int target = i;
            // 'A'로 이루어진 문자열의 길이 구하기
            while(i<name.size() && name[target]=='A') target++;
            int left = i == 0 ? 0 : i - 1; // 찾은 문자열 왼쪽 이동길이
            int right = name.size() - target; // 찾은 문자열 오른쪽 이동길이

            shift = min(shift, left+right+min(left, rigth));
        }
    }
    answer += shift;

    for(auto x : name) {
        answer += min(x-'A', 'Z'-x+1);
    }

    cout << answer << endl;


    return 0;
}