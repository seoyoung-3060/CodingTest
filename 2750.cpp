#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> num;
    while(n--){
        int temp;
        cin >> temp;
        num.push_back(temp);
    }
    sort(num.begin(), num.end());
    for(auto a : num) cout << a << endl;
}