#include <iostream>
using namespace std;
int main(){
    int index=1, L, P, V;
    while(true){
        cin >> L >> P >> V;
        if(!L && !P && !V) break;
        int ans = (V/P)*L + min(V%P, L);
        cout << "Case " << index << ": " << ans << endl;
        index++;
    }
    return 0;
}