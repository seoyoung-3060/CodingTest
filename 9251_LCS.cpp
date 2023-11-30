#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string one, two;
    cin >> one >> two;
    int n = one.size();
    int m = two.size();

    int dp[1001][1001] = {0};
    //빈문자열과의 LCS처리를 위해 1부터 시작
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(one[i-1]==two[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[n][m];
    
    return 0;
}