#include <iostream>
using namespace std;
int main()
{
    int n,k,tw,tv,result=0;
    cin >> n >> k;
    int *w = new int;
    int *v = new int;
    for(int i=0; i<n; i++) {
        cin >> w[i] >> v[i];
    }
    for(int i=0; i<n-1; i++){
        if(w[i] <= k) {
            tw = w[i];
            tv = v[i];
            if(tw <= k){
                for(int j=i+1; j<n; j++){
                    if((tw+w[j])<=k){
                        tw += w[j];
                        tv += v[j];
                    }
                }
            }
        }
        if (tv >= result)
            result = tv;
    }
    cout << result;

    return 0;
}

