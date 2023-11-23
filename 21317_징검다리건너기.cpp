#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 999999;
/*
three jumps
plus 1 (no skip)
plus 2 (1 skip)
plus 3 (2 skips) -> just one time & k energy
*/


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k; cin >> n;
    pair<int, int> energy[21];
    for(int i=1; i<n; i++) {
        int x,y; cin >> x >> y;
        energy[i] = make_pair(x,y);
    }
    cin >> k;

    /*
    dp[i][0]�� �ſ� ū ������ ���� �ʰ� �� ����̴�.
    �� ���� �ΰ��� ��η� i��°���� �� �� �ִµ�
    1. i-1��°���� ���� ���� + i-1��°������ ��
    2. i-2��°���� ū ���� + i-2��°������ ��
    �ΰ��� ��� �߿��� �ּҰ��� �����Ѵ�.


    dp[i][1]�� �ſ� ū ������ i��°�� ���� �� ����̴�.
    �� ��� ���� �ΰ��� ��η� i��°���� �� �� �ִµ�
    1. �ſ� ū ������ �Ἥ(k) i��°�� ������ ���
    2. i��°�� �����ϱ���� �ٸ� ������ �Ἥ ����, �� ���� �ſ� ū ������ ����� ���
    �ΰ��� ��� �߿��� �ּҰ��� �����Ѵ�.

    �� �� 2��°�� �� �ٽ� ����� ���� �ΰ����� �������µ�,
    �̴� dp[i][0]�� ���ϴ� ����� ���� ����� ���̴�.
    1. i-1��°���� ���� ���� + i-1��°������ ��
    2. i-2��°���� ū ���� + i-2��°������ ��
    �ٸ� ���� �� ���� �ſ� ū ������ ����� ����̹Ƿ� dp[?][1]�� ���� �����Ѵ�.
    */

    int dp[21][2];
    for (int i = 0; i <= n; i++) {
        dp[i][0] = MAX;
        dp[i][1] = MAX;
    }

    dp[1][0] = 0;
    dp[2][0] = energy[1].first;
    dp[3][0] = min(energy[1].first + energy[2].first, energy[1].second);
    
    // ū ������ �� �� �ִ� 4��° ���� n���� �ݺ����� �����Ѵ�.
    for(int i=4; i<=n; i++) {
        dp[i][0] = min(energy[i-1].first + dp[i-1][0],
                       energy[i-2].second + dp[i-2][0]);
        //cout << "dp[" << i-3 << "][0]" << dp[i-3][0] << endl;
        dp[i][1] = min(k + dp[i-3][0],
                       min(energy[i-1].first + dp[i-1][1],
                           energy[i-2].second + dp[i-2][1]));
    }

    cout << min(dp[n][0], dp[n][1]);


    return 0;
}