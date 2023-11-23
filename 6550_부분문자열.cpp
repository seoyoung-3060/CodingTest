#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s, t;

    while(cin >> s >> t){

        int check = 0;
        bool isTrue = false;
        for(int i=0; i<t.size(); i++) {
            if(s[check]==t[i]) {
                check++;
            }
            if(check == s.length()) {
                isTrue = true;
                break;
            }
        }
    
        if(isTrue) cout << "Yes" << "\n";
        else cout << "No" << "\n";
    }
    
    return 0;
}