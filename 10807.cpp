#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, input, count=0;
    cin >> n;
    vector<int> array;
    while(n--){
        int num=0;
        cin >> num;
        array.push_back(num);
    }
    cin >> input;
    for(int i=0; i<array.size(); i++) {
        if(array[i]==input) count++;
    }
    cout << count;
}