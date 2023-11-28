#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, pair<string,string> > tree;

//root-left-right
void preOrder(const string& node)
{
    //node가 .이면 자식이 없으므로 return
    if(node == ".") return;
    cout << node;

    preOrder(tree[node].first);
    preOrder(tree[node].second);
}

//left-root-right
void inOrder(const string& node)
{
    if(node == ".") return;

    inOrder(tree[node].first);
    cout << node;
    inOrder(tree[node].second);
}

//left-right-root
void postOrder(const string& node)
{
    if(node == ".") return;

    postOrder(tree[node].first);
    postOrder(tree[node].second);
    cout << node;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin >> N;
    for(int i=0; i<N; i++) {
        string root, left, right;
        cin >> root >> left >> right;
        tree[root] = make_pair(left, right);
    }

    preOrder("A");
    cout << "\n";
    inOrder("A");
    cout << "\n";
    postOrder("A");

    return 0;
}