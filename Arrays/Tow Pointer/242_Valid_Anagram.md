# 242. Valid Anagram
  - Easy


Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false

## Step‑by‑Step Approach

in this question first i sort in assending order than start loop from 0 to end of string and compair all character if any one not match than i return 'False' otherwise if loop end i return 'True'.




        class Solution {
        public:
            bool isAnagram(string s, string t) {
                if(s.length() != t.length())
                    return false;
                sort(s.begin(),s.end());
                sort(t.begin(),t.end());

                for(int i=0;i<s.length();i++){
                    if(s[i]!=t[i])
                        return false;
                }

                return true;
            }
        };

