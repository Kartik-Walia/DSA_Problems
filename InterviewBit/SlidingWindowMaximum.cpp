#include<iostream>
using namespace std;


#include<deque>
#include<algorithm>
vector<int> slidingMaximum(const vector<int> &A, int B) {
    
    int i=0, j=0;
    vector<int> ans;
    deque<int> dq;    // To store max values 
    
    // Edge case
    if(B == 1) return A;
    
    // Edge case
    if(B > A.size()) {
        int maxele = INT_MIN;
        for(auto ele:A) maxele = (ele > maxele) ? ele : maxele;
        ans.push_back(maxele);
        return ans;
    }
    
    while(j < A.size()) {
        
        // Expand window till we hit window size 
        if(j-i+1 < B) {
            while(!dq.empty() && dq.back() < A[j]) dq.pop_back();
            dq.push_back(A[j]);
            j++;
        }
        
        // Sliding window (maintain window size)
        else if(j-i+1 == B) {
            // Get answer & maintain window size 
            while(!dq.empty() && dq.back() < A[j]) dq.pop_back();
            dq.push_back(A[j]);
            ans.push_back(dq.front());
            if(dq.front() == A[i]) dq.pop_front();  // Maintain window size
            
            // Slide the window 
            i++; j++;
        }
    }
    
    return ans;
}