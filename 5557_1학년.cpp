#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int nums[101];
    int n; cin >> n;
    
    //n까지의 숫자 입력받음
    for(int i=1; i<=n; i++) {
        cin >> nums[i];
    }
    int result_N = nums[n];

    //n 최대 101개, 0~20까지 범위이므로 + 숫자범위 long long
    long long dp[101][21] = {0};
    //첫번째 값은 들어가있음
    dp[1][nums[1]] = 1;
    //i=2부터 n-1까지 j 0~20숫자 돌면서 이전값에대한 j가 없다면 패스
    for(int i=2; i<=n-1; i++) {
        for(int j=0; j<=20; j++) {
            if(dp[i-1][j]==0) continue;
            //값이 존재한다면 이전까지의 경우의 수와 함께 더해줌.
            if(j+nums[i] <= 20) dp[i][j+nums[i]] += dp[i-1][j];
            if(j-nums[i] >= 0) dp[i][j-nums[i]] += dp[i-1][j];
        }
    }
    cout << dp[n-1][result_N] << "\n";

    return 0;
}
