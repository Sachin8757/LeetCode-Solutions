# 125. Valid Palindrome

- Easy

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.

## Step‑by‑Step Approach
first i check if string is empty so i return 'True' than i create 2 variable for trabling string.

than after i start while loop and traversing string 's' .
if and special character ocur than i continue loop therwise compair if i get any character not match than i return "False" after completing loop i return "True".


        class Solution {
        public:
            bool isPalindrome(string s) {
                if(s.length()==0)
                    return true;
                int i=0,j=s.length()-1;

                while(i<j){
                    if(!isalnum(s[i])){
                        i++;
                        continue;
                    }
                    if(!isalnum(s[j])){
                        j--;
                        continue;
                    }
                    if(tolower(s[i])!=tolower(s[j]))
                        return false;

                    i++;
                    j--;
                }

                return true;
            }
        };