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
    vector<long long> ans(N-K+1,0);
    queue<int> q;   // To store indices of negative numbers
    
    while(j < N) {
        // Perform calculations
        if(A[j] < 0) q.push(j);
        
        // Expand untill we hit window size 
        if(j-i+1 < K) j++;
        
        else if(j-i+1 == K) {
            // Get answer from calculations & Maintain window size (remove calculations of i)
            if(!q.empty() && q.front() < i) q.pop();
            if(!q.empty()) ans[i] = A[q.front()];
            
            // Slide window
            i++; j++;
        }
    }
    
    return ans;
}