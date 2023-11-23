#include <iostream>
#include <queue>
using namespace std;
//그냥 3차원 BFS 문제이다.

//i: N, j:M ,k:H
int dir[6][3] = {{0,1,0}, {0,-1,0}, {-1,0,0}, {1,0,0}, {0,0,1}, {0,0,-1}};
int tomato[100][100][100]; //k,i,j
queue<pair<pair<int, int>, int> > q; //q : <i,j>,k

int M, N, H, days = 0;

//queue elements {i,j},k
void BFS()
{
    while(!q.empty()) {
        days++;
        int size = q.size();
        for(int i=0; i<size; i++) {
            int x=q.front().first.first; //i,N
            int y=q.front().first.second; //j,M
            int z=q.front().second; //k,H
            q.pop();
            //토마토 이웃 검사하기
            for(int j=0; j<6; j++) {
                int nx = x+dir[j][0];
                int ny = y+dir[j][1];
                int nz = z+dir[j][2];

                //토마토가 범위 안이고 0이라면 q에 삽입 후 1처리, 삽입된 토마토는 이웃검사
                if(nx>=0 && nx<N && ny>=0 && ny<M && nz>=0 && nz<H && tomato[nz][nx][ny]==0) {
                    q.push(make_pair(make_pair(nx, ny), nz));
                    tomato[nz][nx][ny] = 1;
                }
            }
        }
    }
    //모든 토마토 탐색 완료


    //안익은 토마토 검사
    for(int k=0; k<H; k++) {
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(tomato[k][i][j]==0) {cout << -1 << "\n"; return;}
            }
        }
    }

    //토마토가 다 익었을때도 돌아서 1빼줌
    cout << days-1 << "\n";
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> H;
    bool all = true;


    for(int k=0; k<H; k++) {
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                cin >> tomato[k][i][j];
                if(tomato[k][i][j]==0) all = false;
                if(tomato[k][i][j]==1) q.push(make_pair(make_pair(i,j),k));
            }
        }
    }

    if(all) { cout << 0 << "\n"; return 0; }
    BFS();

    return 0;
}