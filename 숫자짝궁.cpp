#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string X, string Y)
{
    string answer = "";
    vector<int> num(10,0);
    vector<char> result;

    for(int i=0; i<X.size(); i++) {
        num[X[i]-'0']++;
    }
    for(int i=0; i<Y.size(); i++) {
        if(--num[Y[i]-'0'] >= 0) result.push_back(Y[i]);
    }
    sort(result.begin(), result.end(), greater<char>());
    if(result.empty()) return "-1";
    for (int i=0; i<result.size(); i++) {
        answer += result[i];
    }
    if(answer[0]=='0') return "0";
    return answer;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input1, input2;
    cin >> input1 >> input2;
    cout << solution(input1, input2);

    return 0;
}