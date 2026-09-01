1856. Maximum Subarray Min-Product

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