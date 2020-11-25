//Problem: Product of Array Except Self
//link: https://leetcode.com/problems/product-of-array-except-self/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> right(nums.size(),1),left(nums.size(),1);
        for(int i=0;i<nums.size();i++){
            right[i]*=nums[i];
            if(i-1>=0)right[i]*=right[i-1];
        }
        for(int i=nums.size()-1;i>=0;i--){
            left[i]*=nums[i];
            if(i+1<nums.size())left[i]*=left[i+1];
        }
        for(int i:right)cout<<i<<" ";
        cout<<endl;
        for(int j:left)cout<<j<<" ";
        for(int i=0;i<nums.size();i++){
            nums[i]=1;
            if(i+1<nums.size())nums[i]*=left[i+1];
            if(i-1>=0)nums[i]*=right[i-1];
        }
        return nums;
    }
};