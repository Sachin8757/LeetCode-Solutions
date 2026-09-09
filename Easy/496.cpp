496. Next Greater Element I

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
