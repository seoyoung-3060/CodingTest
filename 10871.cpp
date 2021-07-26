#include <iostream>
int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(nullptr);
    int N,X;
    int *A = new int[N];
    std::cin >> N >> X;
    for(int i=0; i<N; i++) {
        std::cin >> A[i]; 
    }
    for(int i=0; i<N; i++) {
        if(A[i]<X)
            std::cout << A[i] << ' ';
    }
    delete[] A;
}