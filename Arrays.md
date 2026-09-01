 
# DAY 06 of 100 Day DSA 
## 20. Valid Parentheses
Easy
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

Example 5:

Input: s = "([)]"

Output: false

        class Solution {
        public:
            bool isValid(string s) {
                stack<char>st;
                for(char ch:s){
                    if(ch=='('||ch=='['||ch=='{'){
                        st.push(ch);
                    }else{
                        if(st.empty())
                            return false;
                            
                        char top=st.top();
                        st.pop();
                        if(ch ==')' && top != '(') return false;
                        if(ch ==']' && top != '[') return false;
                        if(ch =='}' && top != '{') return false;


                    }
                }
                return st.empty();
            }
        };

# DAY 05 OF 100 DAY DSA
## 496. Next Greater Element I

Easy
Companies
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

 

Example 1:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
Example 2:

Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.

        class Solution {
        private:

            // Find target in nums2
            int findPosition(vector<int>& nums2, int target, int index) {
                if (index == nums2.size()) {
                    return -1;
                }

                if (nums2[index] == target) {
                    return index;
                }

                return findPosition(nums2, target, index + 1);
            }

            // Find next greater element after index
            int findGreater(vector<int>& nums2, int target, int index) {
                if (index == nums2.size()) {
                    return -1;
                }

                if (nums2[index] > target) {
                    return nums2[index];
                }

                return findGreater(nums2, target, index + 1);
            }

            void solve(vector<int>& nums1, vector<int>& nums2,
                    vector<int>& ans, int index) {

                if (index == nums1.size()) {
                    return;
                }

                int target = nums1[index];

                // Find target position in nums2
                int pos = findPosition(nums2, target, 0);

                // Find next greater element
                int greater = findGreater(nums2, target, pos + 1);

                ans.push_back(greater);

                solve(nums1, nums2, ans, index + 1);
            }

        public:
            vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

                vector<int> ans;

                solve(nums1, nums2, ans, 0);

                return ans;
            }
        };

## 387. First Unique Character in a String

Easy

Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

Example 1:

Input: s = "leetcode"

Output: 0

Explanation:

The character 'l' at index 0 is the first character that does not occur at any other index.

Example 2:

Input: s = "loveleetcode"

Output: 2

Example 3:

Input: s = "aabb"

Output: -1

    class Solution {
    public:
        int firstUniqChar(string s) {

            unordered_map< char ,int> mp;

            for(char ch: s){
                mp[ch]++;
            }

            for(int i=0; i<s.length(); i++){
                if(mp[s[i]]==1)
                    return i;
            }

            return -1;

        }
    };


# DAY 04 OF 100 DAY DSA
 ## 14. Longest Common Prefix

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


## 232. Implement Queue using Stacks

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

## x