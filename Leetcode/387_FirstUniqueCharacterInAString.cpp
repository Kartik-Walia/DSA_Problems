#include<iostream>
using namespace std;


// ================================================== Approach-I ==================================================
// class Solution {
// public:
//     int firstUniqChar(string s) {
//         unordered_map<char, pair<int, int>> map;    // pair : count, index

//         for(int i=0; i<s.size(); i++) {
//             map[s[i]].first++;
//             map[s[i]].second = i;
//         }

//         int minIndex = INT_MAX;
//         for(int i=0; i<map.size(); i++) {
//             if(map[i].first == 1) {
//                 minIndex = min(minIndex, map[i].second);
//             }
//         }

//         return minIndex == INT_MAX ? -1 : minIndex;
//     }
// };


// ================================================== Approach-II ==================================================
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> map;   // Char, Count_occurence
        for(char ch:s) map[ch]++;

        for(int i=0; i<s.size(); i++) {
            if(map[s[i]] == 1) return i;
        }

        return -1;
    }
};