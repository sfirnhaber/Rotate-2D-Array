class Solution {
public:
    
    //swaps contents of the two parameters
    void swap(int& a, int& b) {
        a += b;
        b = a - b;
        a -= b;
    }
    
    void rotate(vector<vector<int>>& matrix) {
        int length = matrix.size() - 1;
        for (int i = 0; i < matrix.size() / 2; i++) {
            //swaps corners
            swap(matrix[i][i], matrix[i][length-i]);
            swap(matrix[i][i], matrix[length-i][length-i]);
            swap(matrix[i][i], matrix[length-i][i]);
            //swaps sides
            if (length % 2 == 0 || i + 1 != matrix.size() / 2) {
                for (int offset = 1 + i; offset < matrix.size() - i - 1; offset++) {
                    swap(matrix[i][offset], matrix[offset][length - i]);
                    swap(matrix[i][offset], matrix[length - i][length - offset]);
                    swap(matrix[i][offset], matrix[length - offset][i]);
                }
            }
        }
    }
};
