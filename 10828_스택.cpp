#include <iostream>
#include <stack>
using namespace std;

void push(int value);
void pop();
void size();
void empty();
void top();

int N;
int top_v = -1;
int myStack[100000];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    //vector<string> func = {"push", "pop", "size", "empty", "top"};
    //if(find(func.begin(), func.end(), item) != func.end())
    for(int i=0; i<N; i++) {
        stirng com; cin >> com;
        if(com == "push") {
            int x; cin >> x;
            push(x);
        }
        else if(com == "pop") pop();
        else if(com == "size") size();
        else if(com == "empty") empty();
        else if(com == "top") top();
    }

    return 0;
}

/* STL Stack »ç¿ë
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    stack<int> s;
    //vector<string> func = {"push", "pop", "size", "empty", "top"};
    //if(find(func.begin(), func.end(), item) != func.end())
    for(int i=0; i<N; i++) {
        stirng com; cin >> com;
        if(com == "push") {
            int x; cin >> x;
            s.push(x);
        }
        else if(com == "pop") {
            if(s.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << s.top() << '\n';
                st.pop();
            }
        }
        else if(com == "size") cout << (int)s.size() << '\n';
        else if(com == "empty") cout << s.empty() << '\n';
        else if(com == "top") {
            if(s.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << s.top() << '\n';
            }
        }
    }
    return 0;
}
*/

void push(int value) {
    if(top_v >= N-1) return;
    else {
        top_v++;
        myStack[top_v] = value;
    }
}
void pop() {
    if(top_v <= -1) cout << "-1" << "\n";
    else
        cout << myStack[top_v--] << "\n";
}
void size() {
    cout << top_v + 1 << "\n";
}
void empty() {
    if(top_v<=-1) cout << "1" << "\n";
    else cout << "0" << "\n";
}
void top() {
    if(top_v<=-1) cout << "-1" << "\n";
    else cout << myStack[top_v] << "\n";
}