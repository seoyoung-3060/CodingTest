#include <iostream>
using namespace std;

void Swap(int &A, int &B)
{
    int Temp = A;
    A = B;
    B = Temp;
}

void QuickSort(int *arr, int low, int high) {
    int pivot = low; // 맨 왼쪽 값을 pivot 설정
    int left = low + 1; //맨왼쪽값 pivot이므로 왼쪽 출발 지점= +1
    int right = high;
    
    while(left <= right) {
        while(arr[left] <= arr[pivot] && left <= high) left++;
        while(arr[right] >= arr[pivot] && right > low) right--;

        //엇갈린다면 high와 pivot swap
        if(left > right) Swap(arr[right], arr[pivot]);
        else Swap(arr[left], arr[right]); //아니라면 left, right swap
    }

    //처음 pivot값 기준으로 분할계산
    QuickSort(arr, low, right-1);
    QuickSort(arr, right+1, high);

}


int main(void) {
    int N = 8;
    int arr[] = {8, 15, 5, 9, 3, 12, 1, 6};

    Quick(0, N-1);

    for(auto a : arr) cout << a << " ";
    return 0;
}