#include <iostream>
using namespace std;
int N, M;
int arr[9] = {0,};

void dfs(int start, int depth)
{
    if(depth == M) {
        for(int i=0; i<M; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return; //무지 중요한 부분. Backtracking!!!
    }
    for(int i=start; i<=N; i++) {
        arr[depth] = i;
        dfs(i, depth+1);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    dfs(1,0);

    return 0;
}