#include<iostream>
#include<queue>
using namespace std;


// ====================================================== Approach-I (Brute Force) ======================================================
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> cnt;    // ele, count
        for(int i:arr) cnt[i]++;
        
        vector<pair<int, int>> count;   // ele, count
        for(auto& entry:cnt) count.push_back(entry);
        sort(count.begin(), count.end(), [](auto& a, auto& b) {
            return a.second < b.second;
        });
        int sum = 0;
        for(auto& it:count) {
            sum += it.second;
            if(sum <= k) {
                it.second = 0;
                if(sum == k) break;
            }
            if(sum > k) break;
        }
        int unique = 0;
        for(auto& it:count) {
            if(it.second != 0) unique++;
        }
        return unique;
    }
};
// TC : O(N) + O(M) + O(MlogM) + O(M) + O(M) => O(N + MlogM)     [M is number of unique elements]
// SC : O(M)    [In worst case O(N) when all elements are unique]


// =================================================== Approach-II (Better Approach) ===================================================
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> count;
        for (int a : arr) count[a]++;

        priority_queue<int, vector<int>, greater<int>> pq;    // Min Heap
        for (auto& entry : count) pq.push(entry.second);

        while (k > 0 && k >= pq.top()) {
            k -= pq.top();
            pq.pop();
        }

        return pq.size();
    }
};
// TC : O(N) + O(MlogM) + O(MlogM) => O(N + MlogM)      [M is number of unique elements]
// SC : O(M)    [In worst case O(N) when all elements are unique]


// ================================================== Approach-III (Optimal Approach) ==================================================
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // Frequency is bounded between 1 and arr.size()  [No number can show up more times than length of array]
        unordered_map<int, int> freq;
        for(int i:arr) freq[i]++;

        vector<int> freqList(arr.size()+1, 0);    // index -> frequency & value -> no. of elements with that frequency [No element can occur with freq as 0]
        for(auto entry:freq) freqList[entry.second]++;

        int res = freq.size();    // Total number of unique elements
        for(int f=1; f<freqList.size(); f++) {
            int remove = freqList[f];   // Tells number of elements with frequency f
            if(k >= f*remove) {    // Removal of all elements of frequency f is possible
                k -= f*remove;
                res -= remove;
            } else {    // Removal of some elements of frequency f is possible
                remove = k/f;
                res -= remove;
                break;
            }
        }

        return res;
    }    
};
// TC : O(N) + O(N) + O(N)
// SC : O(N) + O(N)     [unordered map and vector]