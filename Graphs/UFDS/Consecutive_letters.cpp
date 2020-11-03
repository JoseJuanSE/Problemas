#include<bits/stdc++.h>
using namespace std;
//not solve still 
//link: https://www.spoj.com/problems/CONSEC/
struct UFDS{
    vector<int>p,s;
    int ns;
    UFDS(int n){
        ns=n;
        n++;
        p.assign(n,0);
        s.assign(n,1);
        for(int i=0;i<n;i++)p[i]=i;
    }
    int FindSet(int i){return p[i]==i?i:p[i]=FindSet(p[i]);}
    bool IsSameSet(int i,int j){return FindSet(i)==FindSet(j);}
    int siz(int x){return s[FindSet(x)];}
    int NumSet(){return ns;}
    bool UnionSet(int i,int j){
        int x=FindSet(i),y=FindSet(j);
        if(x==y)
            return false;
        ns--;
        if(s[x]<s[y])
            swap(x,y);
        p[y]=x;
        s[x]+=s[y];
        return true;
    }
};
void solve(){
    string x,cx;
    cin>>x;
    cx=x;
    UFDS s(x.size());
    int q;
    cin>>q;
    vector<pair<int,int> > vp;
    while(q--){
        int a,b;
        cin>>a>>b;
        vp.push_back({a,b});
        if(a==2)cx[b]='#';
    }
    reverse(vp.begin(),vp.end());
    map<char,int> maximos;
    for(int i=1;i<x.size();i++){
        maximos[cx[i]]=max(maximos[cx[i]],1);
        if(cx[i]==cx[i-1]){
            s.UnionSet(i,i-1);
            maximos[cx[i]]=max(maximos[cx[i]],s.siz(i));
        }
    }
    stack<int> ans;
    for(auto i:vp){
        if(i.first==1){
            ans.push(maximos[x[i.second]]);
        }else{
            if(i.second-1>=0 and x[i.second]==x[i.second-1]){
                s.UnionSet(i.second,i.second-1);
                maximos[x[i.second]]=max(maximos[x[i.second]],s.siz(i.second));
            }
            if(i.second+1<x.size() and x[i.second]==x[i.second+1]){
                s.UnionSet(i.second,i.second+1);
                maximos[x[i.second]]=max(maximos[x[i.second]],s.siz(i.second));
            }
        }
    }
    while(!ans.empty()){
        cout<<ans.top()<<"\n";
        ans.pop();
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        cout
        solve();
    } 
        
    return 0;
}