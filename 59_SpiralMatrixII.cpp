#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int> (n,0));

        int num = 1;
        int L=0, R=n, T=0, B=n;

        while(L<R && T<B) {
            // Traversing first row (L to R)
            for(int i=L; i<R; i++) matrix[T][i] = num++;
            T++;

            // Traversing last column (T to B)
            for(int i=T; i<B; i++) matrix[i][R-1] = num++;
            R--;

            if(!(L<R && T<B)) break;    // For Row or Column matrix

            // Traversing last row (R to L)
            for(int i=R-1; i>=L; i--) matrix[B-1][i] = num++;
            B--;

            // Traversing first column (B to T)
            for(int i=B-1; i>=T; i--) matrix[i][L] = num++;
            L++;
        }

        return matrix;
    }
};