#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<vector<int> > train(N, vector<int>(21,0));
    for(int i=0; i<M; i++) {
        int c, j, k; cin >> c;
        switch (c)
        {
        case 1:
            cin >> j >> k;
            if(j<-0|| j>=N || k<0 || k>=21) continue;
            if(train[j][k]==0) train[j][k] = 1;
            break;
        case 2:
            cin >> j >> k;
            if(j<-0|| j>=N || k<0 || k>=21) continue;
            if(train[j][k]==1) train[j][k] = 0;
            break;
        case 3:
            cin >> j;
            for(int p=19; p>=0; p--) {
                train[j][p+1] = train[j][p];
            }
            train[j][0] = 0;
            break;
        case 4:
            cin >> j;
            for(int p=1; p<21; p++) {
                train[j][p-1] = train[j][p];
            }
            train[j][20] = 0;
            break;
        default:
            break;
        }  
    }

    vector<vector<int> > unique_train;

    for(const vector<int>& v : train) {
        if(find(unique_train.begin(), unique_train.end(), v)== unique_train.end())
            unique_train.push_back(v);
    }

    cout << unique_train.size() << "\n";
    return 0;
}