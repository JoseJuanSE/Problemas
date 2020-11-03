#include<bits/stdc++.h>
//name: Frined Circle
//url : https://www.spoj.com/problems/FRNDCIRC/
using namespace std;
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
    int NumSet(){return ns;}
    int sof(int x){return s[FindSet(x)];}
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
    int n;
    cin>>n;
    UFDS s(n+1);
    map<string,int> m;
    int p=1;
    for(int i=0;i<n;i++){
        string a,b;
        cin>>a>>b;
        if(m[a]==0){
            m[a]=p;
            p++;
        }
        if(m[b]==0){
            m[b]=p;
            p++;
        }
        s.UnionSet(m[a],m[b]);
        cout<<s.sof(m[a])<<'\n';
    }
}
int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
}