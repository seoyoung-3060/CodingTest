#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> people[10001];
vector<int> leaders;

void checking(int check)
{
    if(!people[check].empty()) {
        leaders.push_back(check);
        for(int i=1; i<people[check].size(); i++) {
            checking(people[check][i]);
        }
    }
    else {
        
    }
}

int solution(vector<int> sales, vector<vector<int> > links)
{
    int answer = 0;
    int nums = sales.size();
    for(int i=1; i<=links.size(); i++) {
        people[links[i][0]].push_back(links[i][1]);
    }


    for(int i=1; i<=people.size(); i++) {
        //배열 원소 하나씩 찾아가기
        checking(people[i]);
        
    }
    for(auto x : leaders) cout << x << " ";

    return answer;
}



int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}