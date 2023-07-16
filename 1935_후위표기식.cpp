#include <iostream>
#include <stack>
using namespace std;

int N;
string inp;
int* element;

void input()
{
    cin >> N;;
    cin >> inp;
    element = new int[N];
    for(int i=0; i<N; i++) cin >> element[i];
}

void solution() {
    stack<double> cal;
    for(const auto& i : inp)
    {
        if(i >= 'A' && i <= 'Z') cal.push(element[i - 'A']); //i-'A' == element index(0~N)
        else
        {
            double t1, t2;
            t2 = cal.top(); //첫번째 pop을 두번째 연산자로 정하기
            cal.pop();
            t1 = cal.top(); //두번째 pop을 첫번째 연산자로 정하기
            cal.pop();
            
            switch (i)
            {
            case '*':
                cal.push(t1*t2); //연산된 결과를 다시 push
                break;
            case '+':
                cal.push(t1+t2);
                break;
            case '/':
                cal.push(t1/t2);
                break;
            case '-':
                cal.push(t1-t2);
                break;
            
            default:
                break;
            }
        }
    }
    cout << fixed; //소수점 자리로만 정함
    cout.precision(2); //둘째자리까지만 출력
    cout << cal.top() << "\n"; //연산이 끝나고 가장 마지막 원소가 연산결과.
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solution();

    return 0;
}