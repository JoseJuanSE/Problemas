//Problem: Valid Palindrome 2
//link: https://leetcode.com/problems/valid-palindrome-ii/submissions/
class Solution {
public:
    bool validPalindrome(string s) {
        int l=0,r=s.size()-1;
        while(l<r and s[l]==s[r]){
            l++;
            r--;
        }
        int l1=l,r1=r;
        l++;
        while(l<r and s[l]==s[r]){
            l++;
            r--;
        }
        r1--;
        while(l1<r1 and s[l1]==s[r1]){
            l1++;
            r1--;
        }
        return l>=r or l1>=r1;
    }
};