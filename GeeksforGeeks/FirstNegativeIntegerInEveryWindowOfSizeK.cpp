#include<iostream>
#include<queue>
using namespace std;


// ======================================================= Approach-I (Brute Force) =======================================================
// vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
//     vector<long long> ans(N-K+1,0);
//     queue<int> q;
    
//     // Processing 1st window 
//     for(int i=0; i<K; i++) {
//         if(A[i] < 0) {
//             ans[0] = A[i];
//             break;
//         }
//     }  
    
//     // Sliding window
//     for(int i=K; i<N; i++) {
//         // Processing each remaining window
//         for(int j=i-K+1; j<=i; j++) {
//             if(A[j] < 0) {
//                 ans[i-K+1] = A[j];
//                 break;
//             }
//         }
//     }
    
//     return ans;
// }


// ===================================================== Approach-II (Sliding Window) =====================================================
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    
    long long int i=0, j=0;
    vector<long long> ans(N-K+1,0);     // For each window of size K there would be 1 output 
    queue<int> q;   // To store indices of negative numbers
    
    while(j < N) {
        // Expand window till we hit window size 
        if(j-i+1 < K) {
            if(A[j] < 0) q.push(j);
            j++;
        }
        
        // Sliding window (maintain window size)
        else if(j-i+1 == K) {
            // Get answer & maintain window size 
            if(A[j] < 0) q.push(j);
            if(!q.empty() && q.front() < i) q.pop();
            if(!q.empty()) ans[i] = A[q.front()];
            
            // Slide the window
            i++; j++;
        }
    }
    
    return ans;
}

