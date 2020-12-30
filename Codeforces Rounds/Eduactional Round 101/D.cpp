#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > ans;
int n,fn,t;
void fill(int x){
    while(n!=1){
        ans.push_back({fn,x});
        if(n%x!=0)n+=x;
        n/=x;
    }
}
void solve(){
    cin>>n;
    fn=n;
    ans.clear();
    for(int i=3;i<n;i++)
        if(i!=8)
            ans.push_back({i,i+1});
    if(n>8){
        fill(8);
        for(int i=0;i<3;i++) ans.push_back({8,2});
    }else
        fill(2);
    cout<<ans.size()<<endl;
    for(auto i:ans)cout<<i.first<<" "<<i.second<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>t;
    while(t--)solve();
    return 0;
}