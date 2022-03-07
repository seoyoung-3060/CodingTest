#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a[10001] = {0,};
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int in;
        scanf("%d",&in);
        a[in]++;
    } //하나하나 다 저장하면 시간초과 -> count함수구현
    for(int i=1; i<=10000; i++){
        for(int j=0; j<a[i]; j++) {
            printf("%d",i);
            printf("\n");
        }
    }//cin cout endl 시간 매우 느림 -> printf,scanf,\n활용!
    return 0;
}