//Problem: Longest Increasing Subsequence
//Link: https://leetcode.com/problems/longest-increasing-subsequence/
class Solution {
public:
    vector<int> top,size;

    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0)return 0;
        top.clear();
        size.clear();
        top.push_back(nums[0]);
        size.push_back(1);
        
        for(int i=1;i<nums.size();i++){
            bool nins=true;
            int j = upper_bound(top.begin(),top.end(),nums[i])-top.begin();
            if(j==top.size() and top[j-1]==nums[i])j--;
            while(j-1>=0 and top[j-1]==nums[i])j--;
            if(j<top.size() and nums[i]<=top[j]){
                top[j]=nums[i];
                size[j]++;
                nins=false;
            }
            if(nins){
                top.push_back(nums[i]);
                size.push_back(1);
            }   
            cout<<endl;
        }
        return top.size();
    }
};