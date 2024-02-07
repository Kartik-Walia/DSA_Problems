#include<iostream>
using namespace std;

int largestElement(vector<int> &arr, int n) {
    int max = INT_MIN;
    for(int i:arr) max = i>max ? i : max;
    return max;
}