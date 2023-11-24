#include <iostream>
using namespace std;

int N, r, c;
int x, y, ans=0;

void Z(int x, int y, int n)
{
    if(x==r && y==c) { //만약 x,y가 r,c와 같다면 찾은것임
        cout << ans << "\n";
        return;
    }
    if(r>=x && r<x+n && c>=y && c<y+n)
    {
        //1사분면 검사
        Z(x, y, n/2);
        //2사분면 검사
        Z(x, y+n/2, n/2);
        //3사분면 검사
        Z(x+n/2, y, n/2);
        //4사분면 검사
        Z(x+n/2, y+n/2, n/2);
    }
    else { //해당 사분면에 존재하지 않다면 탐색한 것으로 간주하고 skip한다.
        ans += n*n; //사분면의 크기만큼 더해줌 (사분면의 길이 = n)
    }
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> r >> c;

    //pow(2,N) : 1 << N (left shift)
    Z(0,0,(1 << N));

    return 0;
}