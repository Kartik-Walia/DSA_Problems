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
    vector<long long> ans(N-K+1,0);
    queue<int> q;   // To store indices of negative nos.
    
    // Processing 1st window 
    for(int i=0; i<K; i++) {
        if(A[i] < 0) q.push(i);
    }
    if(!q.empty()) ans[0] = A[q.front()];
    
    // Sliding window (i-K+1 to i)
    for(int i=K; i<N; i++) {
        if(A[i] < 0) q.push(i);
        if(!q.empty() && q.front() < i-K+1) q.pop();
        if(!q.empty()) ans[i-K+1] = A[q.front()];
    }
    
    return ans;
}