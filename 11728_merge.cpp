#include <iostream>
#include <algorithm>
#include <vector>
#define sync ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

void mergeArray() {
    int n, m, check_n = 0, check_m = 0;
    cin >> n >> m;
    int arr_a[n], arr_b[m], arr[n+m];
    for(int i=0; i<n; i++) cin >> arr_a[i];
    for(int i=0; i<m; i++) cin >> arr_b[i];
    
    while(check_n + check_m < n + m) {
        if(check_n == n) cout << arr_b[check_m++] << " ";
        else if(check_m == m) cout << arr_a[check_n++] << " ";
        else{
            if (arr_a[check_n] <= arr_b[check_m])
                cout << arr_a[check_n++] << " ";
            
            else
                cout << arr_b[check_m++] << " ";
            
        }
    }
}

int main() {
    sync
    mergeArray();
    return 0;
}