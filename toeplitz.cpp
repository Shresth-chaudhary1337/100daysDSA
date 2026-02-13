/**/
#include<iostream>
#include<vector>

class Solution {
public:
    bool isToeplitzMatrix(std::vector<std::vector<int>>& matrix) {
    
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] != matrix[i - 1][j - 1]) {
                    return false;
                }
            }
        }
        return true;
        
    }
};