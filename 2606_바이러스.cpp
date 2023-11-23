#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

bool visited[101];
vector<int> graph[101];
int result = 0;

void DFS(int start)
{
    visited[start] = true;
    for(int i=0; i<graph[start].size(); i++) {
        int next = graph[start][i];
        if(!visited[next]) {
            DFS(next);
            result++;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, network; 
    cin >> N >> network;

    for(int i=0; i<network; i++) {
        int c, v; cin >> c >> v;
        graph[c].push_back(v);
        graph[v].push_back(c);
    }

    DFS(1);

    cout << result << "\n";

    return 0;
}