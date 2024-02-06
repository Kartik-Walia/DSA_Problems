#include<iostream>
#include<deque>
using namespace std;


class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        int i=0, j=0;
        vector<int> ans;
        deque<int> dq;
        
        while(j < n) {
            // Expand window till we hit window size 
            if(j-i+1 < k) {
                while(!dq.empty() && dq.back() < arr[j]) dq.pop_back();
                dq.push_back(arr[j]);
                j++;
            }
            
            // Sliding window (maintain window size)
            else if(j-i+1 == k) {
                // Get answer & maintain window size 
                while(!dq.empty() && dq.back() < arr[j]) dq.pop_back();
                dq.push_back(arr[j]);
                ans.push_back(dq.front());
                if(dq.front() == arr[i]) dq.pop_front();    // Maintain window size
                
                // Slide window
                i++; j++;
            }
        }
        
        return ans;
    }
};