#include <iostream>
using namespace std;
int main()
{
    int A,B,te[3];
    cin >> A;
    cin >> B;
    te[0] = B%10;
    te[1] = (B%100)/10;
    te[2] = B/100;
    for(int i=0; i<3; i++) {
        cout << te[i] * A << endl;
    }
    cout << A*B;
    return 0;
}