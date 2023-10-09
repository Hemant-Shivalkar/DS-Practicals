#include <stdio.h>

int binarySearch(int arr[], int x, int first, int last) {
    if (first > last) {
        return -1;
    }
    int mid = (first + last) / 2;
    if (arr[mid] == x) {
        return mid;
    }
    if (arr[mid] < x) {
        return binarySearch(arr, x, mid+1, last);
    }
    return binarySearch(arr, x, first, mid-1);
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int x = 10;
    int result = binarySearch(arr, x, 0, n-1);
    (result == -1) ? printf("Element is not present in array")
                   : printf("Element is present at index %d", result);
    return 0;
}
