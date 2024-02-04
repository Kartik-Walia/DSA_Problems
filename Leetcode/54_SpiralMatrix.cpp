#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int L=0, R=matrix[0].size(), T=0, B=matrix.size();
        
        while(T<B && L<R) {
            // Traversing top row (L to R)
            for(int i=L; i<R; i++) ans.push_back(matrix[T][i]);
            T++;

            // Traversing last column (T to B)
            for(int i=T; i<B; i++) ans.push_back(matrix[i][R-1]);
            R--;

            if(!(T<B && L<R)) break;    // For Row or Column matrix

            // Traversing last row (R to L)
            for(int i=R-1; i>=L; i--) ans.push_back(matrix[B-1][i]);
            B--;

            // Traversing first column (B to T)
            for(int i=B-1; i>=T; i--) ans.push_back(matrix[i][L]);
            L++;
        }

        return ans;
    }
};