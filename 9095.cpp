#include <iostream>
using namespace std;
int num[11];

int main() {
    int n;
    cin >> n;
    num[0] = 1;
    num[1] = 2;
    num[2] = 4;
    for(int i = 3; i<11; i++)
        num[i] = num[i-1] + num[i-2] + num[i-3];
    
    while(n--){
        int temp;
        cin >> temp;
        cout << num[temp-1] << endl;
    }
    return 0;
}