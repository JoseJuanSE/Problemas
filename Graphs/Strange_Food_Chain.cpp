#include<bits/stdc++.h>
//status: not solved yet
//https://www.spoj.com/problems/CHAIN/
using namespace std;
struct UFDS{
    vector<int>p,r,c;
    int ns;
    UFDS(int n){
        ns=n;
        n++;
        p.assign(n,0);
        r.assign(n,1);
        c.assign(n,1)
        for(int i=0;i<n;i++)p[i]=i;
    }
    int FindSet(int i){return p[i]==i?i:p[i]=FindSet(p[i]);}
    bool IsSameSet(int i,int j){return FindSet(i)==FindSet(j);}
    int NumSet(){return ns;}
    bool UnionSet(int i,int j){
        //invertir color de una componente si es necesario
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
void solve(){
    int n,w;
    cin>>n>>w;
    int wrong=0;
    UFDS uf(n);
    while(w--){
        int a,b,c;
        cin>>a>>b>>c;
        if(b>n or c>n)wrong++;
        else if(b==c)wrong++;
        else{
            if(a==1){

            }
            else{
                if(uf.IsSameSet(b,c))
            }
        }
    }
    cout<<wrong<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}