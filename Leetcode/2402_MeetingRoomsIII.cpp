#include<iostream>
#include<queue>
using namespace std;


class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // Sort based on start time
        sort(meetings.begin(), meetings.end(), [](const vector<int>& v1, const vector<int>& v2) {
            return v1[0] < v2[0];
        });

        // min Heap for rooms which are currently busy (current_meet_end_time, room_number)
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> Busy;
        // min Heap for rooms which are currently available (room_number)
        priority_queue<int, vector<int>, greater<int>> Available;
        unordered_map<int, int> Freq;   // To store frequency of meetings in each room

        // Initially all rooms are empty
        for(int i=0; i<n; i++) Available.push(i);

        for(auto meet:meetings) {
            int start = meet[0], end = meet[1];

            // Move meetings in Busy room with end time <= start to Available
            while(!Busy.empty() && Busy.top().first <= start) {
                int roomNo = Busy.top().second;
                Busy.pop();
                Available.push(roomNo);
            }

            // In case of multiple available rooms, choose room with lowest room number
            if(Available.size() > 0) {
                int lowestRoomNo = Available.top();
                Available.pop();
                Freq[lowestRoomNo]++;
                Busy.push({end, lowestRoomNo});
            } else {    // No available rooms, wait for Busy room with nearest ending time to get empty
                pair<long long, int> nearestEnding = Busy.top();
                Busy.pop();
                Freq[nearestEnding.second]++;
                long long newEnd = nearestEnding.first + (end - start);
                Busy.push({newEnd, nearestEnding.second});
            }
        }

        // Finding room with maximum meetings
        int maxi = 0;
        for(int i=1; i<n; i++) {
            if(Freq[i] > Freq[maxi]) maxi = i;
        }

        return maxi;
    }
};