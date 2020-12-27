//link: https://leetcode.com/problems/ones-and-zeroes/
class Solution {
public:
    vector<pair<int,int> > arr;
    int dp[605][105][105];
    int solve(int i,int z,int o){
        if(z<0 or o<0 or i>arr.size())return INT_MIN;
        if(i == (int)arr.size())return dp[i][z][o]=0;
        if(dp[i][z][o]!=-1)return dp[i][z][o];
        return dp[i][z][o] = max(solve(i+1,z-arr[i].first,o-arr[i].second)+1,solve(i+1,z,o));
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        arr.clear();
        memset(dp,-1,sizeof dp);
        for(int i=0;i<strs.size();i++){
            int ones = 0, zeros = 0;
            for(int j=0;j<strs[i].size();j++){
                if(strs[i][j] == '0')zeros++;
                else ones ++;
            }
            arr.push_back({zeros,ones});
        }
        return solve(0,m,n);
    }
};