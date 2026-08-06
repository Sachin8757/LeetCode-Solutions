# 125. Valid Palindrome

- Easy

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.

## Step‑by‑Step Approach
first i check if string is empty so i return 'True' than i create 2 variable for trabling string.

than after i start while loop and traversing string 's' .
if and special character ocur than i continue loop therwise compair if i get any character not match than i return "False" after completing loop i return "True".


        class Solution {
        public:
            bool isPalindrome(string s) {
                if(s.length()==0)
                    return true;
                int i=0,j=s.length()-1;

                while(i<j){
                    if(!isalnum(s[i])){
                        i++;
                        continue;
                    }
                    if(!isalnum(s[j])){
                        j--;
                        continue;
                    }
                    if(tolower(s[i])!=tolower(s[j]))
                        return false;

                    i++;
                    j--;
                }

                return true;
            }
        };



# 167. Two Sum II - Input Array Is Sorted
- Medium

Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers index1 and index2, each incremented by one, as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.

 

Example 1:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
Example 2:

Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
Example 3:

Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].

## Step‑by‑Step Approach
fist i check array size == 0 than i return a empty vector otherwise start traversing.
i create tow variable for travresing .

check if nums[i]and nums[] == target than return the index otherwise return empty array.



        class Solution {
        public:
            vector<int> twoSum(vector<int>& nums, int target) {
                if(nums.size()==0)
                    return { };
                
                int i=0,j=nums.size()-1;

                while(i<j){
                    if(nums[i]+nums[j]==target)
                        return {i+1,j+1};
                    else if(nums[i]+nums[j]<target)
                        i++;
                    else
                        j--;
                }
                return { };
            }
        };


# 217. Contains Duplicate

- Easy

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 

Example 1:

Input: nums = [1,2,3,1]

Output: true

Explanation:

The element 1 occurs at the indices 0 and 3.

Example 2:

Input: nums = [1,2,3,4]

Output: false

Explanation:

All elements are distinct.

Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]

Output: true 

## Step‑by‑Step Approach
First i create a unrodered-set for storing element in this question when any element ocur more than 1 time than return "True" otherwise  return "False".

in storing Time i count which element come more tan 1 time if any come than return "True" other wise "False".




        class Solution {
        public:
            bool containsDuplicate(vector<int>& nums) {
                unordered_set<int>seen;
                for(int num:nums){
                    if(seen.count(num)){
                        return true;
                    }
                    seen.insert(num);
                }

                return false;
            }
        };


# 242. Valid Anagram
  - Easy


Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false

## Step‑by‑Step Approach

in this question first i sort in assending order than start loop from 0 to end of string and compair all character if any one not match than i return 'False' otherwise if loop end i return 'True'.




        class Solution {
        public:
            bool isAnagram(string s, string t) {
                if(s.length() != t.length())
                    return false;
                sort(s.begin(),s.end());
                sort(t.begin(),t.end());

                for(int i=0;i<s.length();i++){
                    if(s[i]!=t[i])
                        return false;
                }

                return true;
            }
        };


# 347. Top K Frequent Elements

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2

Output: [1,2]

Example 2:

Input: nums = [1], k = 1

Output: [1]

Example 3:

Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2

Output: [1,2]

## Step‑by‑Step Approach



        class Solution {
        public:
            vector<int> topKFrequent(vector<int>& nums, int k) {

                unordered_map<int, int> freq;

                // Count frequency of each element
                for (int num : nums) {
                    freq[num]++;
                }

                // Store {frequency, element}
                vector<pair<int, int>> v;

                for (auto it : freq) {
                    v.push_back({it.second, it.first});
                }

                // Sort in descending order of frequency
                sort(v.begin(), v.end(), greater<pair<int, int>>());

                vector<int> ans;

                // Take first k elements
                for (int i = 0; i < k; i++) {
                    ans.push_back(v[i].second);
                }

                return ans;
            }
        };



# 73. Set Matrix Zeroes
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



# 79. Word Search
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


# 15. 3Sum

Medium

Hint
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105

        class Solution {
        public:
            vector<vector<int>> threeSum(vector<int>& nums) {
                sort(nums.begin(), nums.end());
                vector<vector<int>> res;
                int n = nums.size();

                for (int i = 0; i < n - 2; i++) {
                    // Skip duplicate fixed elements
                    if (i > 0 && nums[i] == nums[i - 1])
                        continue;

                    int j = i + 1, k = n - 1;

                    while (j < k) {
                        int sum = nums[i] + nums[j] + nums[k];

                        if (sum == 0) {
                            res.push_back({nums[i], nums[j], nums[k]});
                            j++;
                            k--;

                            // Skip duplicate second elements
                            while (j < k && nums[j] == nums[j - 1])
                                j++;

                        } else if (sum < 0) {
                            j++;
                        } else {
                            k--;
                        }
                    }
                }

                return res;
            }
        };


# 14. Longest Common Prefix

Easy

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".
Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

    class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            if(strs.empty()){
                return "";
            }
            sort(strs.begin(),strs.end());
            string ans="";

            string first=strs.front();
            string second=strs.back();
            int i=0;
            while(first[i]==second[i] && i < first.length() && i < second.length()){
                ans.push_back(first[i]);
                i++;
            }
            return ans;
        }
    };


# 232. Implement Queue using Stacks

Easy

Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
 
Example 1:

Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false


    class MyQueue {

    public:
        stack<int>s;
        MyQueue() {
        
        }
        
        void push(int x) {
            s.push(x);
        }
        
        int pop() {
            return removeBottom(s);
        }
        
        int peek() {
            return getBottom(s);
        }
        
        bool empty() {
            return s.empty();
        }

        private:
        int removeBottom(stack<int>& s) {
            int x = s.top();
            s.pop();

            // Bottom element found
            if (s.empty()) {
                return x;
            }

            int ans = removeBottom(s);
            s.push(x);

            return ans;
        }

        int getBottom(stack<int>& s) {
            int x = s.top();
            s.pop();

            // Bottom element found
            if (s.empty()) {
                s.push(x);      // Restore it
                return x;
            }

            int ans = getBottom(s);
            s.push(x);

            return ans;
        }
    };

# 225. Implement Stack using Queues

Easy

Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.
Notes:

You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.
 

Example 1:

Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]

Explanation
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False

    class MyStack {
        
    public:
        queue<int>q;
        MyStack() {
            
        }
        
        void push(int x) {
            q.push(x);
            int n=q.size();

            for(int i=0;i<n-1;i++){
                q.push(q.front());
                q.pop();
            }
        }
        
        int pop() {
            int num=q.front();
            q.pop();
            return num;
        }
        
        int top() {
            return q.front();
        }
        
        bool empty() {
            return q.empty();
        }
    };

