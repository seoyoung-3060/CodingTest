#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, k; cin >> N >> k;
    queue<int> arr, result;
    for(int i=1; i<=N; i++) arr.push(i);

    cout << "<";

    while(arr.size() > 1) {
        for (int i=0; i<k; i++)
        {
            int temp = arr.front();
            arr.pop();
            if(i==k-1) cout << temp << ", ";
            else arr.push(temp);
        }
    }
    cout << arr.front() << ">\n";

    return 0;
}