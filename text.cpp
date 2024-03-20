//SEARCH IN ROTATED SORTED ARRAY
#include <iostream>

// We know pivot would be always on Line 2
int getPivot(int arr[], int n){
    int str = 0, end = n-1; 

    while (str < end){
        int mid = str+(end-str)/2;
    
        if (arr[mid] >= arr[0]){       // mid on Line 1
            str = mid+1;
        }
        else{       // mid on Line 2
            end = mid;
        }
    }

    return str;
}

int searchinRotatedSorted(int arr[], int n, int target){
    int pivot = getPivot(arr, n);

    return arr[pivot-1];
}


int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro";

    return 0;
}