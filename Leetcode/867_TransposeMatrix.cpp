#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> transposeMatrix(matrix[0].size(), vector<int> (matrix.size()));
        for(int i=0; i<transposeMatrix.size(); i++) {
            for(int j=0; j<transposeMatrix[0].size(); j++) transposeMatrix[i][j] = matrix[j][i];
        }
        return transposeMatrix;
    }
};