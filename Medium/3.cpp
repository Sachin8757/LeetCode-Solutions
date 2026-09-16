// 3. Longest Substring Without Repeating Characters
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given a string s, find the length of the longest substring without duplicate characters.

 

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


// Method 1 // this throw TLE 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() ==1) return 1;
        int lenght =0;
        for(int i=0;i<s.length();i++){
            unordered_map<char,int> mp;
            int currlen=0;
            for(int j=i;j<s.length();j++){

                if(mp.find(s[j])!=mp.end()){
                    break;
                }
                mp[s[j]]++;
                currlen++;
                lenght =max(lenght,currlen);
            }
        }
        return lenght;
    }
};


// method 2 optimal 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char, int> mp;

        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.length(); right++) {

            if (mp.find(s[right]) != mp.end()) {
                left = max(left, mp[s[right]] + 1);
            }

            mp[s[right]] = right;

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};