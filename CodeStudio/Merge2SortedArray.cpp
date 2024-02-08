#include<iostream>
using namespace std;


// ======================================================= Approach-I (Brute Force) =======================================================
#include<set>
vector<int> sortedArray(vector<int> a, vector<int> b) {
    set<int> st;    // Set stores unique values only and that too in ascending order
    vector<int> ans;

    for(int i:a) st.insert(i);
    for(int i:b) st.insert(i);

    for(auto it:st) ans.push_back(it);

    return ans;
}
// TC : O(nlogn) + O(mlogm) + O(n+m)
// SC : O(n+m) + O(n+m)    [1st is for Set & 2nd is used to return the ans, not using 2nd to solve the problem]


// ==================================================== Approach-II (Optimal Approach) ====================================================
vector<int> sortedArray(vector<int> a, vector<int> b) {
    int i=0, j=0;   // 2 pointers
    int last=-1;   // To store last value pushed in ans for avoiding duplicates
    vector<int> ans;
    
    while(i<a.size() && j<b.size()) {
        if(a[i] > b[j]) {
            if(b[j] != last) {
                ans.push_back(b[j]);
                last = b[j];
            }
            j++;
        }
        else {
            if(a[i] != last) {
                ans.push_back(a[i]);
                last = a[i];
            }
            i++;
            if(a[i] == b[j]) j++;
        }
    }

    // 2nd array got exhausted
    while(i<a.size()) {
        if (a[i] != last) {
            last = a[i];
            ans.push_back(a[i]);
        }
        i++;
    }

    // 1st array got exhausted
    while(j<b.size()) {
        if (b[j] != last) {
            last = b[j];
            ans.push_back(b[j++]);
        }
        j++;
    }

    return ans;
}
// TC : O(n+m)
// SC : O(n+m) for returning ans, not for solving [For algorithm it's O(1)]