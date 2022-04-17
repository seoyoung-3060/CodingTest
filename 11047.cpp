#include <iostream>
#define sync ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

int cnt = 0;
void Recursion(int value[],int k, int n) {
    if(k == 0) return;
    if(value[n] <= k) {
        cnt++;
        Recursion(value, k-value[n], n);
    }
    else Recursion(value, k, n-1);
}

void Coin() {
    int n, k;
    cin >> n >> k;
    int value[n];
    for(int i=0; i<n; i++) cin >> value[i];

    Recursion(value, k, n-1);

    cout << cnt << "\n";
}
int main() {
    sync;
    Coin();
    return 0;
}