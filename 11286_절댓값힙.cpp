#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    priority_queue< pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;

    cin >> N;

    while(N--) {
        int x; cin >> x;
        if(x==0) {
            if (pq.empty()) cout << 0 << '\n';
            else
            {
                cout << pq.top().second << '\n';
                pq.pop();
            }
        }
        else {
            pq.push(make_pair(abs(x),x));
        }
    }


    return 0;
}