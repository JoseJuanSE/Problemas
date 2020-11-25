//problem:  Verifying an Alien Dictionary
//link: https://leetcode.com/problems/verifying-an-alien-dictionary/
class Solution {
public:
    unordered_map<char,int> HT;
    bool esmayor(string &a,string &b){
        for(int i=0;i<min(a.size(),b.size());i++){
            if(HT[a[i]]!=HT[b[i]])return HT[a[i]]>HT[b[i]];
        }
        return a.size()>b.size();
    }
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0;i<order.size();i++)HT[order[i]]=i;
        for(int i=0;i<words.size()-1;i++)
            if(esmayor(words[i],words[i+1]))return false;
        return true;
    }
};