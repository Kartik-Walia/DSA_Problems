#include<iostream>
using namespace std;


class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // Edge case
        if(K == 1) {
            sort(Arr.begin(), Arr.end());
            long s = Arr[N-1];
            return s;
        }
        
        // Processing 1st Window
        long sum=0;
        for(int i=0; i<K; i++) sum += Arr[i];
        long maxSum = sum;

        // Sliding window
        for(int j=K; j<N; j++) {
            sum = sum -Arr[j-K] + Arr[j];
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};