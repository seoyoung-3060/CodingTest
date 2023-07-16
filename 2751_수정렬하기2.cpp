#include <iostream>
#include <algorithm>
using namespace std;


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    int arr[N];

    for(int i=0; i<N; i++) cin >> arr[i];
    
    sort(arr, arr+N);

    for(auto x : arr) cout << x << "\n";

    return 0;
}