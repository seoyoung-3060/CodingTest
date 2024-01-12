#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
terms
1. 체육복은 앞뒤 번호만 빌려줄 수 있음.
2. 여분이 있는 사람도 잃어버릴 수 있음. 이 경우, 빌려줄 수 없음.
*/

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 3;
    vector<int> lost;
    vector<int> reserve;
    // lost.push_back(2);
    lost.push_back(3);
    // reserve.push_back(1);
    reserve.push_back(1);
    // reserve.push_back(5);

    int answer = 0;

    int res[31];
    fill_n(res, n+1, 0);

    for(auto i : reserve) res[i] += 1;
    for(auto i : lost) res[i] -= 1;

    for(int i=1; i<=n; i++) {
        if(res[i]==-1) {
            if(res[i-1]==1) res[i-1] = res[i] = 0;
            else if(res[i+1] == 1) res[i+1] = res[i] = 0;
        }
    }

    for(int i=1; i<=n; i++) {
        if(res[i] != -1) answer++;
    }



    return 0;
}