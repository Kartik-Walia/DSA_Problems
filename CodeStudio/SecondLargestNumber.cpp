#include<iostream>
using namespace std;


// ===================================================== Approach-I (Brute Force) =====================================================
vector<int> getSecondOrderElements(int n, vector<int> a) {
    sort(a.begin(), a.end());
    int L = a[n-1], S=a[0];
    vector<int> ans;

    // Get 2nd largest element
    for(int i=n-2; i>=0; i--) {
        if(a[i] != L) {
            ans.push_back(a[i]);
            break;
        }
    }

    // Get 2nd smallest element
    for(int i=1; i<n; i++) {
        if(a[i] != S) {
            ans.push_back(a[i]);
            break;
        }
    }

    return ans;
}
// TC : O(NlogN + N)


// ===================================================== Approach-II (Better Approach) =====================================================
vector<int> getSecondOrderElements(int n, vector<int> a) {
    int L=INT_MIN, S=INT_MAX, SL=INT_MIN, SS=INT_MAX;
    vector<int> ans;

    // Get largest & smallest elements
    for(int i:a) {
        L = i > L ? i : L;
        S = i < S ? i : S;
    }

    // Get 2nd largest & smallest elements
    for(int i:a) {
        if(i > SL && i != L) SL=i;
        if(i < SS && i != S) SS=i;
    }

    ans.push_back(SL);
    ans.push_back(SS);

    return ans;
}
// TC : O(N + N)


// ===================================================== Approach-III (Optimal Approach) =====================================================
vector<int> getSecondOrderElements(int n, vector<int> a) {
    int L=a[0], SL=INT_MIN;
    int S=a[0], SS=INT_MAX;
    for(int i:a) {
        // Get 2nd Largest element 
        if(i>L) {
            SL = L;
            L = i;
        } else if(i<L && i>SL) {
            SL = i;
        } 
        
        // Get 2nd Smallest element 
        if(i<S) {
            SS = S;
            S = i;
        } else if(i>S && i<SS) {
            SS = i;
        } 
    }

    return {SL, SS};
}

// TC : O(N)