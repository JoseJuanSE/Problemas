//problem : https://leetcode.com/problems/implement-strstr/
//link: Implement strStr()
class Solution {
public:
    int KMP(string &a,string &b){
        vector<int> pi(a.size(),0);
        int j=0;
        for(int i=1;i<a.size();i++){
            if(a[i]==a[j]){j++;pi[i]=j;}
            else if(j!=0){j=pi[j-1];i--;}
        }
        j=0;
        for(int i=0;i<b.size();i++){
            if(a[j]==b[i]){
                j++;
                if(j==a.size())return i-a.size()+1;
            }else{
                bool f = false;
                while(j!=0 and a[j]!=b[i]){j=pi[j-1];f=true;}
                if(f)i--;
            }
        }
        return -1;
    }
    int strStr(string haystack, string needle) {
        return needle.size()==0?0:KMP(needle,haystack);
    }
};