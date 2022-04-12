#include <iostream>
#define sync ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

void func() {
    int n;
    long binary[90];
    binary[0] = 1;
    binary[1] = 1;
    cin >> n;
    for(int i=2; i<n; i++) binary[i] = binary[i-1] + binary[i-2];

    cout << binary[n-1] << "\n";
}

int main() {
    func();
    return 0;
}