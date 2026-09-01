33. Search in Rotated Sorted Array

Medium

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1

        class Solution {
        private:
            int solve(int st, int ed, int target, vector<int>& nums) {

                if (st > ed)
                    return -1;

                int mid = st + (ed - st) / 2;

                if (nums[mid] == target)
                    return mid;

                // Left half is sorted
                if (nums[st] <= nums[mid]) {

                    if (nums[st] <= target && target < nums[mid]) {
                        return solve(st, mid - 1, target, nums);
                    }
                    else {
                        return solve(mid + 1, ed, target, nums);
                    }
                }

                // Right half is sorted
                else {

                    if (nums[mid] < target && target <= nums[ed]) {
                        return solve(mid + 1, ed, target, nums);
                    }
                    else {
                        return solve(st, mid - 1, target, nums);
                    }
                }
            }

        public:
            int search(vector<int>& nums, int target) {
                return solve(0, nums.size() - 1, target, nums);
            }
        };
 