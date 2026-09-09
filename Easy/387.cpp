387. First Unique Character in a String

Easy

Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

Example 1:

Input: s = "leetcode"

Output: 0

Explanation:

The character 'l' at index 0 is the first character that does not occur at any other index.

Example 2:

Input: s = "loveleetcode"

Output: 2

Example 3:

Input: s = "aabb"

Output: -1

    class Solution {
    public:
        int firstUniqChar(string s) {

            unordered_map< char ,int> mp;

            for(char ch: s){
                mp[ch]++;
            }

            for(int i=0; i<s.length(); i++){
                if(mp[s[i]]==1)
                    return i;
            }

            return -1;

        }
    };

