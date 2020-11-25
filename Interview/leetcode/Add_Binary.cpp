//Problem: Add Binary
//link: https://leetcode.com/problems/add-binary/
class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        if(a.size()<b.size())swap(a,b);
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        bool car=0;
        for(int i=0;i<b.size();i++){
            if(a[i]==b[i] and a[i]=='1'){
                if(car)ans+='1';
                else ans+='0';
                car=true;
            }else if(a[i]==b[i] and a[i]=='0'){
                if(car)ans+='1';
                else ans+='0';
                car=false;
            }else{
                if(car)ans+='0';
                else ans+='1';
            }
        }
        for(int i=b.size();i<a.size();i++){
            if(a[i]=='0'){
                if(car){
                    ans+='1';
                    car=false;
                }else{
                    ans+='0';
                }
            }else{
                if(car){
                    ans+='0';
                    car=true;
                }else{
                    ans+='1';
                }
            }
        }
        if(car)ans+='1';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};