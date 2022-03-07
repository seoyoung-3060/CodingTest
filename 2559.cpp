#include <iostream>
using namespace std;
#define MAX 100001
int main(){
    int N,K,maximum = 0;
    int array[MAX], result[MAX];
    cin >> N >> K;
    for(int i=0; i<N; i++) cin >> array[i];
    int sum = 0;
    for(int i=0; i<K; i++){
        sum += array[i];
    }
    result[0] = sum - array[0];
    maximum = sum;
    sum = 0;
    for(int i=0; i<N - K; i++){
        sum = result[i] + array[i+K];
        result[i+1] = sum - array[i+1];
        maximum = max(maximum, sum);
        sum = 0;
    }
    cout << maximum << endl;
    return 0;
}