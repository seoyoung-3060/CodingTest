#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
/*
for a in max time
    if class a.start time >= max time
        change max time to a.end time
    else
        plus max time
*/
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int, vector<int>, greater<int> > classes;

    int N; cin >> N;
    vector<pair<int, int> > temp;


    for(int i=0; i<N; i++){
        int s,t; cin >> s >> t;
        temp.push_back(make_pair(s,t));
    }
    sort(temp.begin(), temp.end());
    classes.push(temp[0].second);

    for(int i=1; i<N; i++)
    {
        if(temp[i].first >= classes.top()) {
            classes.pop();
            classes.push(temp[i].second);
        }
        else classes.push(temp[i].second);
    }
    cout << classes.size() << '\n';

    return 0;
}