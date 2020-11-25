//problem: Minimum Remove to Make Valid Parentheses
//link: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int state=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==')')state--;
            if(s[i]=='(')state++;
            if(state<0){
                state=0;
                s[i] = '$';
            }
        }
        int j=s.size()-1;
        while(state){
            if(s[j]=='('){
                state--;
                s[j] = '$';
            }
            j--;
        }
        string ans="";
        for(char i:s)
            if(i!='$')ans += i;
        return ans;
    }
};