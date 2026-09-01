347. Top K Frequent Elements

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

