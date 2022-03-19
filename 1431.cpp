#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;

bool comp(string a, string b){
    if(a.size()!=b.size()){
        return a.size() < b.size();
    }
    else{
        int as = 0;
        for(int i=0; i<a.size(); i++){
            if('0'<=a[i] && a[i]<='9'){
                as += (a[i]-'0');
            }
        }
        int bs = 0;
        for(int i=0; i<b.size(); i++){
            if('0'<=b[i] && b[i]<='9'){ //isdigit은 쓰지말자..
                bs += (b[i]-'0');
            }
        }
        if(as != bs) return as < bs;
        else return a < b;
    }
}

int main() {
    vector<string> inp;

    cin >> n;
    while(n--){
        string a;
        cin >> a;
        inp.push_back(a);
    }
    sort(inp.begin(), inp.end(), comp);
    for(auto x : inp) cout << x << "\n";
    return 0;
}