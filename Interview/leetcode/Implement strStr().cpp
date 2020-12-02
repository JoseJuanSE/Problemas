//problem : https://leetcode.com/problems/implement-strstr/
//link: Implement strStr()
class Solution {
public:
    int KMP(string &a,string &b){
        vector<int> lps(a.size(),0);
        int beg=0,j=0;
        for(int i=1;i<a.size();i++){
            if(a[beg]==a[i]){beg++;lps[i]=beg;}
            else if(beg!=0){beg = lps[beg-1];i--;}
        }
        for(int i=0;i<b.size();i++){
            if(a[j]==b[i]){
                j++;
                if(j==a.size()){
                    j--;
                    return i-a.size()+1;
                    bool f = true;
                    while(j!=0 and (a[j]!=b[i] or f)){
                        j = lps[j-1];
                        f=false;
                    }
                    i--;
                }
            }else{
                bool f = false;
                while(j!=0 and a[j]!=b[i]){ j = lps[j-1];f=true;}
                if(f)i--;
            }
        }
        return -1;
    }
    int strStr(string haystack, string needle) {
        return needle.size()==0?0:KMP(needle,haystack);
    }
};