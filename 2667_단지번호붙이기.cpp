#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int apart[26][26] = {0};
bool visited[26][26];
int dir[4][2] = {{0,-1}, {0,1}, {-1,0}, {1,0}};
int n;
vector<int> result;
int nums = 0;
void DFS(int x, int y)
{
    for(int i=0; i<4; i++) {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];

        if(nx>=0 && ny>=0 && nx<=n && ny<=n) {
            if(!visited[nx][ny] && apart[nx][ny]==1) {
                visited[nx][ny] = true;
                nums++;
                DFS(nx,ny);
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++) {
        string input;
        cin >> input;
        for(int j=0; j<n; j++) {
            apart[i][j] = input[j]-'0';
        }
    }

    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<n; j++) cout << apart[i][j] << " ";
    //     cout << endl;
    // }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(apart[i][j]==1 && !visited[i][j]) {
                visited[i][j] = true;
                nums++;
                DFS(i, j);
                result.push_back(nums);
                nums = 0;
            }
        }
    }
    
    sort(result.begin(), result.end());
    cout << result.size() << "\n";
    for(auto x : result) cout << x << "\n";
    return 0;
}