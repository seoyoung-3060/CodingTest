#include <iostream>
using namespace std;
int input[1025][1025];
int dp[1025][1025];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M;



    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            cin >> input[i][j];
            dp[i][j] = input[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }

    cin >> K;
    while(K--) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int result = 0;
        result = dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1];
        cout << result << "\n";
    }

    return 0;
}