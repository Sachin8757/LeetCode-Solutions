18. 4Sum
Solved
Medium
Topics
premium lock icon
Companies
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109




class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            for(int j = i+1; j<n; j++){
                if(j>i+1 && nums[j]==nums[j-1]){
                    continue;
                }
                int k = j+1;
                int m = n-1;
                while(k<m){
                    long long sum = 0LL+nums[i]+nums[j]+nums[k]+nums[m];
                    if(sum < target) k++;
                    else if(sum > target) m--;
                    else if(sum == target){
                        ans.push_back({nums[i],nums[j],nums[k],nums[m]});
                        k++;
                        m--;
                        while(k<m && nums[k]==nums[k-1]) k++;
                        while(k<m && nums[m]==nums[m+1]) m--;
                    }
                }
            }
        }
        return ans;
    }
};