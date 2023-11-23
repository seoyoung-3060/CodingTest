#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool checked[20000] = false;
void bfs(int n, vector<vector<int> > edge)
{
    for(int i=1; i<=edge.size(); i++){
        checked[i] = true;
        for(int j=0; j<edge[i].size(); i++) {
            
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> edge;
    int n;
    int answer = 0;

    cin >> n;
    for(int i=0; i<=n; i++) {
        int a,b; cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    

    return 0;
}