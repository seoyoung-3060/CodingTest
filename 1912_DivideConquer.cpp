#include <iostream>
#define INFINITE 100000
#define sync ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

int max(int a, int b) {return (a > b)? a : b;}

int max(int left, int mid, int right) {
   return max(max(left, mid), right);
}

int cross(int arr[], int start, int mid, int end) {
    int temp = 0;
    int leftMax = -INFINITE;
    int rightMax = -INFINITE;
    for(int i=mid; i>=start; i--) {
        temp += arr[i];
        if(temp >= leftMax) leftMax = temp;
    }
    temp = 0;
    for(int i=mid+1; i<=end; i++) {
        temp += arr[i];
        if(temp >= rightMax) rightMax = temp;
    }
    return max(leftMax + rightMax, leftMax, rightMax);
}

int maximum(int arr[], int start, int end) {
    if(start == end) return arr[start]; //size one
    int mid = (start + end) / 2;
    int leftMax = maximum(arr, start, mid);
    int rightMax = maximum(arr, mid+1, end);
    int crossMax = cross(arr, start, mid, end);
    return max(leftMax, crossMax, rightMax);
}

int main() {
    sync;
    int n;
    cin >> n;
    int array[n];
    for(int i=0; i<n; i++) { cin >> array[i]; }
    int result = maximum(array, 0, n-1);
    cout << result << "\n";
    return 0;
}