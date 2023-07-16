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
            t2 = cal.top(); //ù��° pop�� �ι�° �����ڷ� ���ϱ�
            cal.pop();
            t1 = cal.top(); //�ι�° pop�� ù��° �����ڷ� ���ϱ�
            cal.pop();
            
            switch (i)
            {
            case '*':
                cal.push(t1*t2); //����� ����� �ٽ� push
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
    cout << fixed; //�Ҽ��� �ڸ��θ� ����
    cout.precision(2); //��°�ڸ������� ���
    cout << cal.top() << "\n"; //������ ������ ���� ������ ���Ұ� ������.
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