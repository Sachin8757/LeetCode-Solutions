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

