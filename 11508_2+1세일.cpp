#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    vector<long long> c;

    cin >> N;
    for(int i=0; i<N; i++) {
        int t; cin >> t;
        c.push_back(t);
    }

    sort(c.begin(), c.end(), greater<int> ());
    long long sum = 0;
    for(int i=0; i<N; i++) {
        if(i%3 != 2) sum += c[i];
    }

    cout << sum << "\n";

    return 0;
}