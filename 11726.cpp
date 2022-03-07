#include <iostream>
using namespace std;
int com(int a, int b){
    if(a == b || b == 0) return 1;
    else return com(a-1, b-1)+com(a-1,b);
    
}
int main() {
    int n,sec,result=0;
    cin >> n;
    for(int i=n/2; i>=0; i--){
        int temp;
        sec = n - i*2;
        temp = com(i+sec, sec);
        result += temp;
    }
    cout << result << endl;
}