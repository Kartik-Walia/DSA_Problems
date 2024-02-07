#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;


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
        // Perform calculations
        while (!dq.empty() && dq.back() < A[j]) dq.pop_back();
        dq.push_back(A[j]);

        // Expand untill we hit window size 
        if(j-i+1 < B) j++;
        
        else if(j-i+1 == B) {
            // Get answer from calculations
            ans.push_back(dq.front());

            // Maintain window size (remove calculations of i)
            if(A[i] == dq.front()) dq.pop_front();
            
            // Slide the window 
            i++; j++;
        }
    }
    
    return ans;
}