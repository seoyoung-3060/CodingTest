#include <iostream>
using namespace std;

int N = 5;
int arr[] = {8, 5, 3, 1, 6};
int sortedArr[N];

//���� �����ϴ� �Լ�
void merge(int arr[], int left, int mid, int right) {
    /*
    i : ���ĵ� ���� ����Ʈ�� ���� �ε���
    j : ���ĵ� ������ ����Ʈ�� ���� �ε���
    k : ���ĵ� ����Ʈ�� ���� �ε���
    */
    int i, j, k;
    i = left;
    j = mid+1;
    k = left;

    while(i <= mid && j <= right) {
        if(arr[i] <= arr[j]) sortedArr[k++] = arr[i++];
        else sortedArr[k++] = arr[j++];

        if(i>mid) {
            for(int l=j; l<=right; l++) sortedArr[k++] = arr[l];
        }
        else {
            for(int l=i; l<=mid; l++) sortedArr[k++] = arr[l];
        }

        for(int l=left; l<=right; l++) arr[l] = sortedArr[l];
    }
}

// �迭�� ������ �պ��ϴ� �Լ�ȣ��
void mergeSort(int arr[], int left, int right) {
    int mid;

    if(left < right) {
        mid = (left+right) / 2; //�߰� ��ġ ����ؼ� ����Ʈ ���� - Divide
        mergeSort(arr, left, mid); //���� ���� - Conquer
        mergeSort(arr, mid+1, right); //���� ���� - Conquer
        merge(arr, left, mid, right); //���ĵ� 2���� �κ� �迭 �պ� - Combine
    }

}


int main(void) {
    mergeSort(arr, 0, N-1);
}