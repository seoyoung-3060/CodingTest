#include <iostream>
using namespace std;

int N = 5;
int arr[] = {8, 5, 3, 1, 6};
int sortedArr[N];

//실제 정렬하는 함수
void merge(int arr[], int left, int mid, int right) {
    /*
    i : 정렬된 왼쪽 리스트에 대한 인덱스
    j : 정렬된 오른쪽 리스트에 대한 인덱스
    k : 정렬될 리스트에 대한 인덱스
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

// 배열을 나누고 합병하는 함수호출
void mergeSort(int arr[], int left, int right) {
    int mid;

    if(left < right) {
        mid = (left+right) / 2; //중간 위치 계산해서 리스트 분할 - Divide
        mergeSort(arr, left, mid); //앞쪽 정렬 - Conquer
        mergeSort(arr, mid+1, right); //뒤쪽 정렬 - Conquer
        merge(arr, left, mid, right); //정렬된 2개의 부분 배열 합병 - Combine
    }

}


int main(void) {
    mergeSort(arr, 0, N-1);
}