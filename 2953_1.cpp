#include <iostream>
using namespace std;

int main()
{
    int input[5][4];
    int index, result = 0;
    for (int i = 0; i < 5; i++) {
        for(int j=0; j<4; j++){
            cin >> input[i][j];
        } 
    }
    for (int i = 0; i < 5; i++) {
        int compare = 0;
        for (int j = 0; j < 4; j++) {
            compare += input[i][j];
        }
        if(result <= compare){
            result = compare;
            index = i;
        }
    }
    cout << index+1 << " " << result;
}