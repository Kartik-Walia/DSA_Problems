#include<iostream>
using namespace std;


// ============================================ Approach-I (Recursive) ============================================
class Solution {
public:
    int f(int i, int j1, int j2, int cols, int rows, vector<vector<int>>& grid) {
        // Express everything in terms (i1, j1) [Robot-1] & (i2, j2) [Robot-2]

        // Base case 1 : Out of bounds
        if(j1<0 || j1>=cols || j2<0 || j2>=cols) return -1e8;

        // Base case 2 : Destination reached 
        // Both reach destination at same time coz simultaneous moves to next row 
        // So instead of i1, i2 just write i
        if(i==rows-1) {
            // If both reached to same columns consider once, otherwise consider both
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }


        // Explors all paths (move both robots simultaneously)
        // For 1 movement of robot1, robot2 can have 3 movements i.e. 9 combos of paths
        // No point of storing change of i as it increments by 1 always 
        // Only store change of j as [-1, 0, 1]
        int maxi=0;
        for(int dj1=-1; dj1<=1; dj1++) {
            for(int dj2=-1; dj2<=1; dj2++) {
                // Check if both are currently on same cell 
                if(j1==j2) maxi=max(maxi, grid[i][j1] + f(i+1, j1+dj1, j2+dj2, cols, rows, grid));
                else maxi=max(maxi, grid[i][j1] + grid[i][j2] + f(i+1, j1+dj1, j2+dj2, cols, rows, grid));
            }
        }

        return maxi;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int cols=grid[0].size();
        int rows=grid.size();
        return f(0, 0, cols-1, cols, rows, grid);
    }
};


// ============================================ Approach-II (Memoization) ============================================
class Solution {
public:
    int f(int i, int j1, int j2, int cols, int rows, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp) {
        // Base case 1 : Out of bounds
        if(j1<0 || j1>=cols || j2<0 || j2>=cols) return -1e8;

        // Base case 2 : Destination reached 
        if(i==rows-1) {
            // If both reached to same columns consider once, otherwise consider both
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }


        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];


        // Explors all paths (move both robots simultaneously)
        int maxi=-1e8;
        for(int dj1=-1; dj1<=1; dj1++) {
            for(int dj2=-1; dj2<=1; dj2++) {
                // Check if both are currently on same cell 
                if(j1==j2) maxi=max(maxi, grid[i][j1] + f(i+1, j1+dj1, j2+dj2, cols, rows, grid, dp));
                else maxi=max(maxi, grid[i][j1] + grid[i][j2] + f(i+1, j1+dj1, j2+dj2, cols, rows, grid, dp));
            }
        }

        return dp[i][j1][j2] = maxi;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int cols=grid[0].size();
        int rows=grid.size();
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols,-1)));
        return f(0, 0, cols-1, cols, rows, grid, dp);
    }
};


// ============================================ Approach-III (Tabulation) ============================================
class Solution {
public:    
    int cherryPickup(vector<vector<int>>& grid) {
        int cols=grid[0].size();
        int rows=grid.size();
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols,-1)));
        
        // Base case 2 : Destination reached 
        for(int j1=0; j1<cols; j1++) {
            for(int j2=0; j2<cols; j2++) {
                // If both reached to same columns consider once, otherwise consider both
                if(j1==j2) dp[rows-1][j1][j2] = grid[rows-1][j1];
                else dp[rows-1][j1][j2] = grid[rows-1][j1] + grid[rows-1][j2];
            }
        }

        for(int i=rows-2; i>=0; i--) {
            for(int j1=0; j1<cols; j1++) {
                for(int j2=0; j2<cols; j2++) {
                    int maxi=-1e8;
                    for(int dj1=-1; dj1<=1; dj1++) {
                        for(int dj2=-1; dj2<=1; dj2++) {
                            // Check if both are currently on same cell 
                            if(j1+dj1>=0 && j1+dj1<cols && j2+dj2>=0 && j2+dj2<cols) {
                                if(j1==j2) maxi=max(maxi, grid[i][j1] + dp[i+1][j1+dj1][j2+dj2]);
                                else maxi=max(maxi, grid[i][j1] + grid[i][j2] + dp[i+1][j1+dj1][j2+dj2]);
                            }
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }

        return dp[0][0][cols-1];
    }
};