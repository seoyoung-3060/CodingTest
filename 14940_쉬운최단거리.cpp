#include <iostream>
#include <queue>
using namespace std;
int n, m, r, c;
int graph[1001][1001] = {0,};
int visited[1001][1001] = {0,};

int dir_n[4] = {-1,1,0,0};
int dir_m[4] = {0,0,-1,1};

void bfs(int x, int y)
{
    queue<pair<int, int> >q;
    q.push(make_pair(x,y));
    visited[x][y] = 1;

    while(!q.empty())
    {
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int dx = nx + dir_n[i];
            int dy = ny + dir_m[i];

            if(dx >= 0 && dx < n && dy >= 0 && dy < m)
            {
                if(visited[dx][dy]==0 && graph[dx][dy]!=0)
                {
                    visited[dx][dy] = visited[nx][ny] + 1;
                    q.push(make_pair(dx, dy));
                }
            } 
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;


    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> graph[i][j];
            if(graph[i][j] == 2) {
                r = i; c = j;
            }
        }
    }

    bfs(r, c);

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(graph[i][j] == 0) cout << 0 << " ";
            else cout << visited[i][j] - 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}