#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a[10001] = {0,};
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int in;
        cin >> in;
        a[in]++;
    }
    for(int i=1; i<=10000; i++){
        for(int j=0; j<a[i]; j++) cout << i << endl;
    }
    return 0;
}