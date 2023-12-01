#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, m;
int indegree[500001];
int result[500001];
vector<int> v[500001];

void topology()
{
    queue<int> q;
    for(int i=1; i<=n; i++) {
        //진입차수가 0인 과목들을 순차적으로 큐에 넣어주고
        if(indegree[i] == 0) {
            q.push(i);
            //결과값을 1로 해준다.
            result[i] = 1;
        }
    }
    //큐가 빌때까지 반복문을 돌려준다.
    while(!q.empty())
    {
        //큐에서 하나씩 뽑아준다.
        int now = q.front();
        q.pop();

        //해당 과목을 선수과목으로 가지는 과목들을 탐색한다.
        for(int i=0; i<v[now].size(); i++) {
            //차례대로 탐색중
            int next = v[now][i];
            //진입차수를 하나 내려준다.(학기 지남)
            indegree[next] -= 1;
            //만약 진입차수==0이면 선수과목이 존재하지 않으므로 큐에 넣어주고 결과값을 저장한다.
            if(indegree[next]==0) {
                q.push(next);
                result[next] = result[now] + 1;
            }
        }
    }

    //결과값 출력 코드
    for(int i=1; i<=n; i++) cout << result[i] << " ";
} 

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i=0; i<m; i++) {
        int a,b; cin >> a >> b;
        v[a].push_back(b);
        indegree[b]++;
    }

    topology();

    return 0;
}