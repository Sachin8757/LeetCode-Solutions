42. Trapping Rain Water
Solved
Hard
Topics
premium lock icon
Companies
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105


class Solution {
public:
    int trap(vector<int>& height) {

        int start = 0;
        int end = height.size() - 1;

        int leftMax = 0;
        int rightMax = 0;
        int totalWater = 0;

        while(start < end){

            leftMax = max(leftMax, height[start]);
            rightMax = max(rightMax, height[end]);

            if(leftMax < rightMax){
                totalWater += leftMax - height[start];
                start++;
            }
            else{
                totalWater += rightMax - height[end];
                end--;
            }
        }

        return totalWater;
    }
};