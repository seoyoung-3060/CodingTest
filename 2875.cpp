#include <iostream>
#define sync ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

int teamCount = 0;
void TeamMatch(int n, int m, int k) {
    if( ((n-teamCount*2)+m-teamCount) < k) {
        teamCount--;
        TeamMatch(n, m, k);
    }
    else return;
}

int main() {
    sync;
    int n, m, k;
    cin >> n >> m >> k;
    int a = n/2, b = m;
    while(a != b) {
        if(a > b) a--;
        else b--;
    }
    teamCount = a;
    TeamMatch(n, m, k);

    cout << teamCount << "\n";

    return 0;
}