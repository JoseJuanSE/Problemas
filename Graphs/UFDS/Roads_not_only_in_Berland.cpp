#include<bits/stdc++.h>
//problem name: Roads not only in Berland
//link: https://codeforces.com/contest/25/problem/D
using namespace std;
struct UFDS{
    vector<int>p,r;
    int ns;
    UFDS(int n){
        ns=n;
        n++;
        p.assign(n,0);
        r.assign(n,1);
        for(int i=0;i<n;i++)p[i]=i;
    }
    int FindSet(int i){return p[i]==i?i:p[i]=FindSet(p[i]);}
    bool IsSameSet(int i,int j){return FindSet(i)==FindSet(j);}
    int NumSet(){return ns;}
    bool UnionSet(int i,int j){
        int x=FindSet(i),y=FindSet(j);
        if(x==y)
            return false;
        ns--;
        if(r[x]<r[y])
            swap(x,y);
        if(r[x]==r[y])
            r[x]++;
        p[y]=x;
        return true;
    }
};
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    UFDS s(n);
    stack<pair<int,int> > ans;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        if(!s.IsSameSet(x,y)){
            s.UnionSet(x,y);
        }else{
            ans.push({x,y});
        }
    }
    cout<<ans.size()<<"\n";
    int ini=2;
    while(!ans.empty()){
        pair<int,int> cur=ans.top();
        ans.pop();
        cout<<cur.first<<" "<<cur.second<<" ";
        for(int i=ini;i<=n;i++){
            if(!s.IsSameSet(1,i)){
                cout<<1<<" "<<i<<'\n';
                s.UnionSet(1,i);
                ini=i+1;
                break;
            }
        }
    }
    return 0;

}