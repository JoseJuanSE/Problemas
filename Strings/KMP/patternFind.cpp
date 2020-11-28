//Problem : PatternFind
//link: https://www.spoj.com/problems/NAJPF/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
void KMP(string &a,string &b){
    vector<int> lps(a.size(),0);
    int beg=0,j=0;
    for(int i=1;i<a.size();i++){
        if(a[beg]==a[i]){beg++;lps[i]=beg;}
        else if(beg!=0){beg = lps[beg-1];i--;}
    }
    vector<int> ans;
    for(int i=0;i<b.size();i++){
        //cout<<"J: "<<j<<" A: "<<a[j]<<" I: "<<i<<" B: "<<b[i]<<endl;
        if(a[j]==b[i]){
            j++;
            if(j==a.size()){
                j--;
                ans.push_back(i-a.size()+2);
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
    if(ans.empty())cout<<endl<<"Not Found"<<endl<<endl;
    else{
        cout<<ans.size()<<endl;
        for(int i:ans)cout<<i<<" ";
        cout<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        string a,b;
        cin>>b>>a;
        KMP(a,b);
    }
    return 0;
}