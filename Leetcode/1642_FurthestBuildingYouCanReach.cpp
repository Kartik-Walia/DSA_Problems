#include<iostream>
#include<queue>
using namespace std;
// CONCEPT : Minimum Jumps should be done using Bricks & Maximum Jumps should be done using Ladders


// ======================================================== Approach (Max Heap) ========================================================
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;     // Max Heap (To store jumps made using Bricks)
        int i;
        for(i=0; i<heights.size()-1; i++) {
            int curr = heights[i], next = heights[i+1];
            if(curr >= next) continue;    // Next building is at same or lower height than previous building
            int jump = next - curr;
            if(jump <= bricks) {
                bricks -= jump;
                pq.push(jump);
            } else if(ladders > 0) {
                if(pq.size() != 0) {
                    int maxJump = pq.top();
                    if(maxJump > jump) {
                        bricks += maxJump;
                        pq.pop();
                        pq.push(jump);
                        bricks -= jump;
                    }
                }
                ladders--;
            } else {
                break;
            }
        }

        return i;
    }
};
// TC : O(NlogK)    [where K is number of bricks]
// SC : O(K)    [where K is number of bricks]


// =================================================== Alternate Approach (Min Heap) ===================================================
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;    // Min Heap (To store jumps made using Ladders)
        int i;
        for(i=0; i<heights.size()-1; i++) {
            int curr = heights[i], next = heights[i+1];
            if(curr >= next) continue;    // Next building is at same or lower height than previous building
            int jump = next - curr;
            if(ladders > 0) {
                ladders--;
                pq.push(jump);
            } else if(pq.size() != 0) {
                int minJump = pq.top();
                if(minJump < jump) {
                    pq.pop();
                    bricks -= minJump;
                    pq.push(jump);
                } else {
                    if(jump <= bricks) bricks -= jump;
                    else return i;
                }
            } else {
                if(jump <= bricks) bricks -= jump;
                else return i;
            }

            if(bricks < 0) return i;
        }

        return i;
    }
};
// TC : O(NlogK)    [where K is number of ladders]
// SC : O(K)    [where K is number of ladders]