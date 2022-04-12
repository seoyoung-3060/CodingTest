#include <iostream>
#include <algorithm>
#include <vector>
#define sync ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

void Array() {
    int n, m;
    cin >> n >> m;
    vector<int> array;
    for(int i=0; i<n; i++) {
        int input;
        cin >> input;
        array.push_back(input);
    }
    for(int i=0; i<m; i++) {
        int input;
        cin >> input;
        array.push_back(input);
    }
    sort(array.begin(), array.end());
    for(auto a : array) cout << a << " ";
}

int main() {
    sync;
    Array();
    return 0;
}