73. Set Matrix Zeroes
Medium

Hint
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

Example 1:

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:

Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 
        class Solution {
        public:
            void setZeroes(vector<vector<int>>& matrix) {
                int m=matrix.size();
                int n=matrix[0].size();
                vector<int>row(m,0);
                vector<int >col(n,0);
                for(int i=0;i<matrix.size();i++){
                    for(int j=0;j<matrix[0].size();j++){
                        if(matrix[i][j]==0){
                            row[i]=1;
                            col[j]=1;
                        }

                    }
                }

                for(int i=0;i<m;i++){
                    for(int j=0;j<n;j++){
                        if(row[i]|| col[j]){
                            matrix[i][j]=0;
                        }
                    }
                }

            }
        };
### approch 2
    class Solution {
    private:
    void markZero(vector<vector<int>>& matrix, int row, int col,
                  vector<int>& rows, vector<int>& cols,
                  int m, int n) {
        // Base case
        if (row == m)
            return;

        if (col == n) {
            markZero(matrix, row + 1, 0, rows, cols, m, n);
            return;
        }

        if (matrix[row][col] == 0) {
            rows[row] = 1;
            cols[col] = 1;
        }

        markZero(matrix, row, col + 1, rows, cols, m, n);
    }

            void fillZero(vector<vector<int>>& matrix, int row, int col,
                        vector<int>& rows, vector<int>& cols,
                        int m, int n) {

                if (row == m)
                    return;

                if (col == n) {
                    fillZero(matrix, row + 1, 0, rows, cols, m, n);
                    return;
                }

                if (rows[row] || cols[col])
                    matrix[row][col] = 0;

                fillZero(matrix, row, col + 1, rows, cols, m, n);
            }

        public:
            void setZeroes(vector<vector<int>>& matrix) {
                int m = matrix.size();
                int n = matrix[0].size();

                vector<int> rows(m, 0);
                vector<int> cols(n, 0);

                markZero(matrix, 0, 0, rows, cols, m, n);
                fillZero(matrix, 0, 0, rows, cols, m, n);
            }
        };
