#include <iostream>
#include <stack>
using namespace std;

void VPS(string inp) {
    stack<char> s;
    for (int i = 0; i < inp.length(); i++)
    {
        if (inp[i] == '(')
            s.push('(');
        else
        {
            if (!s.empty())
                s.pop();
            else {
                cout << "NO" << "\n";
                return;
            }
        }
    }
    if(!s.empty()) {
        cout << "NO" << "\n";
        return;
    }
    cout << "YES" << "\n";
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin >> N;
    for(int i=0; i<N; i++) {
        string inp;
        cin >> inp;
        VPS(inp);
    }
    
    return 0;
}