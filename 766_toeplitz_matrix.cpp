class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() < 2 || matrix[0].size() < 2)
            return true;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        for(int row = 0; row < rows; row++) {
            int val = matrix[row][0];
            for(int r = row + 1, c = 1; r < rows && c < cols; r++, c++) {
                if (matrix[r][c] != val)
                    return false;
            }
        }
        
        for(int col = 1; col < cols; col++) {
            int val = matrix[0][col];
            for(int r = 1, c = col+1; r < rows && c < cols; r++, c++) {
                if (matrix[r][c] != val)
                    return false;
            }
        }
        
        return true;

    }
};
