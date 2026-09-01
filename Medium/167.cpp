167. Two Sum II - Input Array Is Sorted
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
