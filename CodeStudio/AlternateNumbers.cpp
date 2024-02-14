#include<iostream>
using namespace std;

// ================================================= Approach-I (Brute Force) =================================================
vector<int> alternateNumbers(vector<int>&a) {
    vector<int> pos, neg;
    for(int i:a) {
        if(i>0) pos.push_back(i);
        else neg.push_back(i);
    }

    vector<int> ans;
    for(int i=0; i<a.size(); i++) {
        if(i < pos.size()) ans.push_back(pos[i]);
        if(i < neg.size()) ans.push_back(neg[i]);
    }

    return ans;
}
// TC : O(N) + O(N)
// SC : O(N/2) + O(N/2) + O(N) 


// =============================================== Approach-II (Optimal Approach) ===============================================
vector<int> alternateNumbers(vector<int>&a) {
    vector<int> pos, neg;
    for(int i:a) {
        if(i>0) pos.push_back(i);
        else neg.push_back(i);
    }

    if(pos.size() > neg.size()) {
        for(int i=0; i<neg.size(); i++) {
            a[2*i] = pos[i];
            a[2*i + 1] = neg[i];
        }
        int index = 2*neg.size();
        for(int i=neg.size(); i<pos.size(); i++) a[index++] = pos[i];
    } else {
        for(int i=0; i<pos.size(); i++) {
            a[2*i] = pos[i];
            a[2*i + 1] = neg[i];
        }
        int index = 2*pos.size();
        for(int i=pos.size(); i<neg.size(); i++) a[index++] = neg[i];
    }

    return a;
}
// TC : O(N) + O(N)     [For 2nd O(N), O(min(neg, pos)) + O(leftovers) => Min. -> O(0) + O(N) && Max. -> O(N/2) + O(0) => So in worst Case it's O(N)]
// SC : O(N/2) + O(N/2)