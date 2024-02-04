#include<iostream>
using namespace std;

class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>> matrix(m, vector<int> (n, 0));
        int row, col, cnt=0;

        for(int i=0; i<indices.size(); i++) {
            row = indices[i][0];
            col = indices[i][1];

            for(int j=0; j<n; j++) matrix[row][j]++;    // Incrementing Rows
            for(int k=0; k<m; k++) matrix[k][col]++;    // Incrementing Columns
        }

        // Calulating odd-valued cells
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++) if(matrix[i][j] % 2 != 0) cnt++;
        }
        
        return cnt;
    }
};