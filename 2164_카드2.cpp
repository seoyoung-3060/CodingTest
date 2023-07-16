#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //1~N ������� ī��, ���� ������ pop => Queue
    queue<int> card;
    int N; cin >> N;
    for(int i=1; i<=N; i++) card.push(i);

    while(card.size() > 1) { //card ���� ���������� �ݺ�
        card.pop();
        int temp = card.front();
        card.pop();
        card.push(temp);
    }

    cout << card.front() << "\n";

    return 0;
}