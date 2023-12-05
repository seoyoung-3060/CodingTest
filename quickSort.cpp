#include <iostream>
using namespace std;

void Swap(int &A, int &B)
{
    int Temp = A;
    A = B;
    B = Temp;
}

void QuickSort(int *arr, int low, int high) {
    int pivot = low; // �� ���� ���� pivot ����
    int left = low + 1; //�ǿ��ʰ� pivot�̹Ƿ� ���� ��� ����= +1
    int right = high;
    
    while(left <= right) {
        while(arr[left] <= arr[pivot] && left <= high) left++;
        while(arr[right] >= arr[pivot] && right > low) right--;

        //�������ٸ� high�� pivot swap
        if(left > right) Swap(arr[right], arr[pivot]);
        else Swap(arr[left], arr[right]); //�ƴ϶�� left, right swap
    }

    //ó�� pivot�� �������� ���Ұ��
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