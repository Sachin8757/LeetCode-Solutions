40. Combination Sum II

Medium

premium lock icon
Companies
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]



class Solution {
public:
    void solve(vector<int>& arr, int target, int start,
               vector<int>& temp, vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = start; i < arr.size(); i++) {

            // Skip duplicate values at the same level
            if (i > start && arr[i] == arr[i - 1])
                continue;

            // Since array is sorted
            if (arr[i] > target)
                break;

            // Include
            temp.push_back(arr[i]);

            // i + 1 because each element can be used only once
            solve(arr, target - arr[i], i + 1, temp, ans);

            // Backtrack
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> temp;

        solve(candidates, target, 0, temp, ans);

        return ans;
    }
};