14. Longest Common Prefix

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
