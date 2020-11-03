#include<bits/stdc++.h>
using namespace std;
//name: Don Porfirio
//link: https://omegaup.com/arena/problem/don-porfirio/#problems/don-porfirio
const int MOD = 1000000007;
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
    int siz(int a){return s[FindSet(a)];}
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
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    UFDS s(n);
    vector<tuple<int,int,int> > graph;
    for(int i=0;i<n-1;i++){
        int a,b,w;
        cin>>a>>b>>w;
        graph.push_back({w,a,b});
    }
    sort(graph.begin(),graph.end());
    long long ans=0;
    for(int i=0;i<n-1;i++){
        long long peso=get<0>(graph[i]),aria=get<1>(graph[i]),arib=get<2>(graph[i]);
        ans+=((((peso%MOD)*(s.siz(aria)%MOD))%MOD)*(s.siz(arib)%MOD))%MOD;
        ans%=MOD;
        s.UnionSet(aria,arib);
    }
    cout<<ans<<'\n';
}