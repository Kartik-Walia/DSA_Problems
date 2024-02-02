#include<iostream>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> pos;
        int row=matrix.size(), col = matrix[0].size(), cnt=0;
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(matrix[i][j] == 0) {
                    pos.push_back(make_pair(i,j));
                    cnt++;
                }
            }
        }
        for(int i=0; i<cnt; i++) {
            // Row
            for(int r=0; r<row; r++) matrix[r][pos[i].second] = 0;

            // Column
            for(int c=0; c<col; c++) matrix[pos[i].first][c] = 0;
        }
    }
};