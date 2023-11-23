#include <iostream>
#include <set>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tot_N;
    cin >> tot_N;

    multiset<int> ms;


    while(tot_N--)
    {
        ms.clear();
        int test_N; cin >> test_N;
        for(int i=0; i<test_N; i++)
        {
            char com; cin >> com;
            if(com=='I')
            {
                int temp; cin >> temp;
                ms.insert(temp);

            }
            else
            {
                int ver; cin >> ver;
                if(!ms.empty()){
                    if (ver == 1)
                    {
                        auto max_iter = ms.end();
                        max_iter--;
                        ms.erase(max_iter);
                    }
                    else if (ver == -1)
                    {
                        ms.erase(ms.begin());
                    }
                }
            }
        }
        if(ms.empty()) cout << "EMPTY" << '\n';
        else {
            auto end_iter = ms.end();
            end_iter--;
            cout << *end_iter << ' ' << *ms.begin() << '\n';
        }
    }

    return 0;
}