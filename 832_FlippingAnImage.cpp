#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        // Reverse (STL or use Binary Search for sorting)
        for(int i=0; i<image.size(); i++) reverse(image[i].begin(), image[i].end());

        // Invert
        for(int i=0; i<image.size(); i++) {
            for(int j=0; j<image[i].size(); j++) {
                if(image[i][j] == 0) image[i][j] = 1;
                else image[i][j] = 0;
            }
        }
        return image;
    }
};