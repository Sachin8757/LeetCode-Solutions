# DAY 12 of 100 Day DSA
## 134. Gas Station

Medium

Companies
There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique.

 

Example 1:

Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
Example 2:

Input: gas = [2,3,4], cost = [3,4,3]
Output: -1
Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.

### Greedy approach 

    class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

            int totalGas = 0;
            int totalCost = 0;

            int tank = 0;
            int start = 0;

            for (int i = 0; i < gas.size(); i++) {

                totalGas += gas[i];
                totalCost += cost[i];

                tank += gas[i] - cost[i];

                if (tank < 0) {
                    start = i + 1;
                    tank = 0;
                }
            }

            if (totalGas < totalCost)
                return -1;

            return start;
        }
    };

### Brute force vs. optimized problem solving

    class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

            int n = gas.size();

            for (int start = 0; start < n; start++) {

                queue<int> q;

                for (int i = start; i < n; i++)
                    q.push(i);

                for (int i = 0; i < start; i++)
                    q.push(i);

                int tank = 0;
                bool possible = true;

                while (!q.empty()) {

                    int station = q.front();
                    q.pop();

                    tank += gas[station];
                    tank -= cost[station];

                    if (tank < 0) {
                        possible = false;
                        break;
                    }
                }

                if (possible)
                    return start;
            }

            return -1;
        }
    };


# DAY 12 of 100 Day DSA
## 88. Merge Sorted Array

Easy

Hint
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.

    class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            for (int j = 0, i = m; j<n; j++,i++){
                nums1[i] = nums2[j];
            }
            sort(nums1.begin(),nums1.end());
        }
    };

## 155. Min Stack

Medium


Hint

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.

void push(int value) pushes the element value onto the stack.

void pop() removes the element on the top of the stack.

int top() gets the top element of the stack.

int getMin() retrieves the minimum element in the stack.

You must implement a solution with O(1) time complexity for each function.

 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation

MinStack minStack = new MinStack();

minStack.push(-2);

minStack.push(0);

minStack.push(-3);

minStack.getMin(); // return -3

minStack.pop();

minStack.top();    // return 0

minStack.getMin(); // return -2


        class MinStack {
        public:
            stack<int>s1;
            stack<int>s2;
            MinStack() {
                
            }
            
            void push(int value) {
                s1.push(value);
                if(s2.empty() || value <= s2.top())
                    s2.push(value);
            }
            
            void pop() {
                if (s1.top() == s2.top()) {
                    s2.pop();
                }

                s1.pop();
            }
            
            int top() {
                return s1.top();
            }
            
            int getMin() {
                return s2.top();
            }
        };

        /**
        * Your MinStack object will be instantiated and called as such:
        * MinStack* obj = new MinStack();
        * obj->push(value);
        * obj->pop();
        * int param_3 = obj->top();
        * int param_4 = obj->getMin();
        */

# DAY 11 of 100 Day DSA
## 1856. Maximum Subarray Min-Product

Medium

Hint
The min-product of an array is equal to the minimum value in the array multiplied by the array's sum.

For example, the array [3,2,5] (minimum value is 2) has a min-product of 2 * (3+2+5) = 2 * 10 = 20.
Given an array of integers nums, return the maximum min-product of any non-empty subarray of nums. Since the answer may be large, return it modulo 109 + 7.

Note that the min-product should be maximized before performing the modulo operation. Testcases are generated such that the maximum min-product without modulo will fit in a 64-bit signed integer.

A subarray is a contiguous part of an array.

Example 1:

Input: nums = [1,2,3,2]
Output: 14
Explanation: The maximum min-product is achieved with the subarray [2,3,2] (minimum value is 2).
2 * (2+3+2) = 2 * 7 = 14.
Example 2:

Input: nums = [2,3,3,1,2]
Output: 18
Explanation: The maximum min-product is achieved with the subarray [3,3] (minimum value is 3).
3 * (3+3) = 3 * 6 = 18.
Example 3:

Input: nums = [3,1,5,6,4,2]
Output: 60
Explanation: The maximum min-product is achieved with the subarray [5,6,4] (minimum value is 4).
4 * (5+6+4) = 4 * 15 = 60.
### Approch 1 Throw TLE 0(n^2)
    class Solution {
    public:
        int maxSumMinProduct(vector<int>& nums) {
            long long ans = 0;
            int n = nums.size();

            for (int i = 0; i < n; i++) {
                long long sum = 0;
                int min_value = INT_MAX;

                for (int j = i; j < n; j++) {
                    sum += nums[j];
                    min_value = min(min_value, nums[j]);

                    ans = max(ans, sum * min_value);
                }
            }

            return ans % 1000000007;
        }
    };

### Approch 2 optimal 0(n)

    class Solution {
        const int MOD = 1e9 + 7;

    public:
        int maxSumMinProduct(vector<int>& nums) {
            int n = nums.size();

            vector<long long> pre(n);
            for (int i = 0; i < n; i++) {
                if (i == 0)
                    pre[i] = nums[i];
                else
                    pre[i] = pre[i - 1] + nums[i];
            }

            vector<int> pse(n), nse(n);
            stack<int> st;

            // Previous smaller
            for (int i = 0; i < n; i++) {
                while (!st.empty() && nums[st.top()] >= nums[i])
                    st.pop();

                pse[i] = st.empty() ? -1 : st.top();
                st.push(i);
            }

            while (!st.empty())
                st.pop();

            // Next smaller
            for (int i = n - 1; i >= 0; i--) {
                while (!st.empty() && nums[st.top()] >= nums[i])
                    st.pop();

                nse[i] = st.empty() ? n : st.top();
                st.push(i);
            }

            long long maxi = 0;

            for (int i = 0; i < n; i++) {
                long long sum = pre[nse[i] - 1];

                if (pse[i] != -1)
                    sum -= pre[pse[i]];

                long long product = sum * nums[i];

                maxi = max(maxi, product);
            }

            return maxi % MOD;
        }
    };

# DAY 10 of 100 Day DSA
## 3069. Distribute Elements Into Two Arrays I

Easy

Hint
You are given a 1-indexed array of distinct integers nums of length n.

You need to distribute all the elements of nums between two arrays arr1 and arr2 using n operations. In the first operation, append nums[1] to arr1. In the second operation, append nums[2] to arr2. Afterwards, in the ith operation:

If the last element of arr1 is greater than the last element of arr2, append nums[i] to arr1. Otherwise, append nums[i] to arr2.
The array result is formed by concatenating the arrays arr1 and arr2. For example, if arr1 == [1,2,3] and arr2 == [4,5,6], then result = [1,2,3,4,5,6].

Return the array result.

Example 1:

Input: nums = [2,1,3]
Output: [2,3,1]
Explanation: After the first 2 operations, arr1 = [2] and arr2 = [1].
In the 3rd operation, as the last element of arr1 is greater than the last element of arr2 (2 > 1), append nums[3] to arr1.
After 3 operations, arr1 = [2,3] and arr2 = [1].
Hence, the array result formed by concatenation is [2,3,1].
Example 2:

Input: nums = [5,4,3,8]
Output: [5,3,4,8]
Explanation: After the first 2 operations, arr1 = [5] and arr2 = [4].
In the 3rd operation, as the last element of arr1 is greater than the last element of arr2 (5 > 4), append nums[3] to arr1, hence arr1 becomes [5,3].
In the 4th operation, as the last element of arr2 is greater than the last element of arr1 (4 > 3), append nums[4] to arr2, hence arr2 becomes [4,8].
After 4 operations, arr1 = [5,3] and arr2 = [4,8].
Hence, the array result formed by concatenation is [5,3,4,8].
 
Constraints:

3 <= n <= 50
1 <= nums[i] <= 100
All elements in nums are distinct.

Approch 1

    class Solution {
    public:
        vector<int> resultArray(vector<int>& nums) {

            vector<int >first;
            vector<int>second;
            first.push_back(nums[0]);
            second.push_back(nums[1]);

            int i=2;

            while(i<nums.size()){
                if(first.back()>second.back())
                    first.push_back(nums[i]);
                else
                    second.push_back(nums[i]);

                i++;
            }
            vector<int>ans;
            for(int i:first) ans.push_back(i);
            for(int i:second) ans.push_back(i);

            return ans;
            
        }
    };

Approch 2

    class Solution {
    public:
        vector<int> resultArray(vector<int>& nums) {

            vector<int >first;
            vector<int>second;
            first.push_back(nums[0]);
            second.push_back(nums[1]);

            int n=nums.size();

            for(int i=2;i<n;i++){
                if(first.back()>second.back())
                    first.push_back(nums[i]);
                else
                    second.push_back(nums[i]);
            }
            
            for(int i:second) first.push_back(i);

            return first;
            
        }
    };

## 503. Next Greater Element II

Medium

Companies
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

Example 1:

Input: nums = [1,2,1]

Output: [2,-1,2]

Explanation: The first 1's next greater number is 2; 

The number 2 can't find next greater number. 

The second 1's next greater number needs to search circularly, which is also 2.
Example 2:

Input: nums = [1,2,3,4,3]

Output: [2,3,4,-1,4]

Approch 1

    class Solution {
    public:
        vector<int> nextGreaterElements(vector<int>& nums) {
            int n=nums.size();

            vector<int>ans(n,-1);

            for(int i=0;i<n;i++){
                int j=i+1;
                while(j!=i){
                    if(j>=n){
                        j=0;
                    }
                    if(nums[j]>nums[i]){
                        ans[i]=nums[j];
                        break;
                    }

                    j++;
                    if(j>=n){
                        j=0;
                    }
                }
            }
            return ans;
        }
    };

Approch 2

    class Solution {
    public:
        vector<int> nextGreaterElements(vector<int>& nums) {
            int n=nums.size();
            stack<int> st;
            vector<int> ans(n,-1);
            for(int i=0;i<2*n;i++){
                int curr=i%n;
                int element=nums[curr];
                while(!st.empty() && element>nums[st.top()]){
                    ans[st.top()]=element;
                    st.pop();
                }
                st.push(curr);
            }
            return ans;
        }
    };


# DAY 09 of 100 Day DSA
## 2073. Time Needed to Buy Tickets
Easy

Hint
There are n people in a line queuing to buy tickets, where the 0th person is at the front of the line and the (n - 1)th person is at the back of the line.

You are given a 0-indexed integer array tickets of length n where the number of tickets that the ith person would like to buy is tickets[i].

Each person takes exactly 1 second to buy a ticket. A person can only buy 1 ticket at a time and has to go back to the end of the line (which happens instantaneously) in order to buy more tickets. If a person does not have any tickets left to buy, the person will leave the line.

Return the time taken for the person initially at position k (0-indexed) to finish buying tickets.

Example 1:
Input: tickets = [2,3,2], k = 2

Output: 6

Explanation:

The queue starts as [2,3,2], where the kth person is underlined.
After the person at the front has bought a ticket, the queue becomes [3,2,1] at 1 second.
Continuing this process, the queue becomes [2,1,2] at 2 seconds.
Continuing this process, the queue becomes [1,2,1] at 3 seconds.
Continuing this process, the queue becomes [2,1] at 4 seconds. Note: the person at the front left the queue.
Continuing this process, the queue becomes [1,1] at 5 seconds.
Continuing this process, the queue becomes [1] at 6 seconds. The kth person has bought all their tickets, so return 6.
Example 2:

Input: tickets = [5,1,1,1], k = 0

Output: 8

Explanation:

The queue starts as [5,1,1,1], where the kth person is underlined.
After the person at the front has bought a ticket, the queue becomes [1,1,1,4] at 1 second.
Continuing this process for 3 seconds, the queue becomes [4] at 4 seconds.
Continuing this process for 4 seconds, the queue becomes [] at 8 seconds. The kth person has bought all their tickets, so return 8.

    class Solution {
    public:
        int timeRequiredToBuy(vector<int>& tickets, int k) {
        int anstime=0;
        queue<int>q1;
        queue<int>q2;

        for(int i=0;i<tickets.size();i++){

            if(i==k){
                q1.push(tickets[i]);
                q2.push(1);
            }else{
                q1.push(tickets[i]);
                q2.push(0);
            }
        }
            int tempnum=tickets[k];
        while(!q1.empty()&& tempnum>0){
            int num=q1.front();
            q1.pop();
            if(q2.front()==1){
                tempnum--;
            }
            int num2=q2.front();
            q2.pop();

            num=num-1;
            if(num>0){
                q1.push(num);
                q2.push(num2);

            }
            anstime++;

        }

        return anstime;
        }
    };

## Reverse first K of a Queue
Solved
Difficulty: EasyAccuracy: 81.28%Submissions: 197K+Points: 2
Given an integer k and a queue of integers, we need to reverse the order of the first k elements of the queue, leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.

enqueue(x) : Add an item x to rear of queue
dequeue() : Remove an item from front of queue
size() : Returns number of elements in queue.
front() : Finds front item.
Note: 

The above operations represent the general processings.
In-built functions of the respective languages can be used to solve the problem.
If the size of queue is smaller than the given k , then return the original queue.
Examples:

Input: q = [1, 2, 3, 4, 5], k = 3
Output: [3, 2, 1, 4, 5]
Explanation: After reversing the first 3 elements from the given queue the resultant queue will be [3, 2, 1, 4, 5]
Input: q = [4, 3, 2, 1], k = 4
Output: [1, 2, 3, 4] 
Explanation: After reversing the first 4 elements from the given queue the resultant queue will be [1, 2, 3, 4]

Approch 1

    class Solution {
    public:
        queue<int> reverseFirstK(queue<int> q, int k) {
            
        if(k > q.size() || k <= 0)
        return q;
        vector<int> nums;

        while(!q.empty()){
            nums.push_back(q.front());
            q.pop();
        }

        int i = 0;
        int j = k - 1;

        while(i < j){
            int num = nums[i];
            nums[i] = nums[j];
            nums[j] = num;

            i++;
            j--;
        }

        for(int i = 0; i < nums.size(); i++){
            q.push(nums[i]);
        }

        return q;
        }
    };

Approch 2

    class Solution {
    public:
        queue<int> reverseFirstK(queue<int> q, int k) {
            
            if(k > q.size() || k <= 0)
                return q;
            
            stack<int> st;
            
            // Put first k elements into stack
            for(int i = 0; i < k; i++){
                st.push(q.front());
                q.pop();
            }
            
            // Put reversed first k elements back
            while(!st.empty()){
                q.push(st.top());
                st.pop();
            }
            
            // Move remaining elements to the back
            int remaining = q.size() - k;
            
            while(remaining--){
                q.push(q.front());
                q.pop();
            }
            
            return q;
        }
    };

# DAY 08 of 100 Day DSA
## Today is Practice day

# DAY 07 of 100 Day DSA 

## 136. Single Number

Easy

Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,1]

Output: 1

Example 2:

Input: nums = [4,1,2,1,2]

Output: 4

Example 3:

Input: nums = [1]

Output: 1

    class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            // unordered_map<int,int>mp;
            // for(int i:nums){
            //     mp[i]++;
            // }

            // for(auto i:mp){
            //     if(i.second==1)
            //         return i.first;
            // }
            // return -1;

            int ans = 0;
            for (int num : nums) {
                ans ^= num;
            }
            return ans;
        }
    };

## 169. Majority Element

Easy

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2

    class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            int n=nums.size();
            return nums[n/2];
        }
    };

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

## 225. Implement Stack using Queues

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

# DAY 03 OF 100 DAY DSA
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



## 73. Set Matrix Zeroes
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



## 79. Word Search
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


## 15. 3Sum

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


# DAY 02 OF 100 DAY DSA
## 217. Contains Duplicate

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

### Step‑by‑Step Approach
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


## 242. Valid Anagram
  - Easy


Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false

### Step‑by‑Step Approach

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

# DAY 01 OF 100 DAY DSA
## 125. Valid Palindrome

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

### Step‑by‑Step Approach
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



## 167. Two Sum II - Input Array Is Sorted
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

### Step‑by‑Step Approach
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







