#include <iostream>
using namespace std;

int w[101];
int v[101];
int dp[101][100001];

int solution(int n, int k)
{
    int max_value = 0;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=k; j++) {
            if(j-w[i] >= 0) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    max_value = dp[n][k];

    return max_value;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    for(int i=1; i<=n; i++) {
        int a, b; cin >> a >> b;
        w[i] = a; v[i] = b;
    }
    
    cout << solution(n, k) << "\n";

    return 0;
}