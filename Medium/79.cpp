79. Word Search
Solved
Medium
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false


        class Solution {
            private:
            bool solve(vector<vector<char>>& board, string word,int k, int i,int j){
                if(k ==word.size())
                    return true;
                int m = board.size();
                int n = board[0].size();
                if(i<0 || i>= m || j<0 || j>=n||board[i][j]!=word[k]){
                    return false;
                }
                
                char temp=board[i][j];
                board[i][j]='#';

                // Try all four directions
                bool found =
                    solve(board, word, k + 1, i, j + 1) ||
                    solve(board, word, k + 1, i, j - 1) ||
                    solve(board, word, k + 1, i + 1, j) ||
                    solve(board, word, k + 1, i - 1, j);

                // Restore the cell (backtracking)
                board[i][j] = temp;

                return found;
            }
        public:
            bool exist(vector<vector<char>>& board, string word) {
                int m=board.size();
                int n=board[0].size();
                for(int i=0;i<m;i++){
                    for(int j=0;j<n;j++){
                        if(solve(board,word,0,i,j))
                            return true;
                    }
                }

                return false;
            }
        };

