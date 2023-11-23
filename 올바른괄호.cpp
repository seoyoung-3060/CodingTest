#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(void)
{
    int answer = 0;
    map<int, int> m;
    vector<vector<int> > jobs;
    vector<int> a,b,c;
    a.push_back(0);
    a.push_back(3);
    b.push_back(1);
    b.push_back(9);
    c.push_back(2);
    c.push_back(6);
    jobs.push_back(a);
    jobs.push_back(b);
    jobs.push_back(c);

    for (int i = 0; i < jobs.size(); i++)
    {
        m.insert(make_pair(jobs[i][0], jobs[i][1]));
    }
    auto i = m.begin();
    answer += i->second;
    for (i; i != m.end(); ++i)
    {
        auto p_i = i--;
        auto n_i = i++;
        
        if ((p_i)->second <= i->first && i->second <= (n_i)->second)
        {
            cout << (n_i)->second << " " << i->second << endl;
            answer += (i->second + (answer - i->first));
        }
        else if (i->second > (n_i)->second)
        {
            answer += ((n_i)->second + (answer - (n_i)->first));
            answer += (i->second - i->first);
            i++;
        }
    }
    answer = answer / jobs.size();
    return 0;
}

