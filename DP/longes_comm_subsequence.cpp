//link: https://leetcode.com/problems/longest-common-subsequence/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[text2.size()+2][text1.size()+2];
        for(int i=0;i<=text2.size();i++){
            for(int j=0;j<=text1.size();j++){
                if(i==0 || j==0)dp[i][j]=0;
                else if(text1[j-1]==text2[i-1]) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }   
        }
        return dp[text2.size()][text1.size()];
    }
};