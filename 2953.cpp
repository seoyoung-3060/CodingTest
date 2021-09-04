#include <iostream>
using namespace std;

int main()
{
    int input[5];
    int compare, index = 0;
    for (int i = 0; i < 5; i++) {
        int result = 0;
        for(int j=0; j<4; j++){
            cin >> input[i];
            result += input[i];
            if(input[i]==' ') i--;
        }
        input[i] = result;
        if(compare <= input[i]) {
            compare = input[i];
            index = i;
        }
    }
    cout << index+1 << " " << compare;
}