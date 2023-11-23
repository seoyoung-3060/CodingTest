#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin >> N;

    int cnt = N / 5;
    int rest = N % 5;
    while(cnt > 0 && rest%2 != 0) {
        rest += 5;
        cnt--;
    }
    
    if(rest%2 == 0) cout << cnt + rest/2 << '\n';
    else cout << -1 << '\n';

    return 0;
}