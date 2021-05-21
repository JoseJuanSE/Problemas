#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,z=0,x=0;
    string s;
    cin>>n>>s;
    for(int i=0;i<n/2;i++)
        if(s[i]!=s[n-1-i])x++;
    for(int i = 0;i<n;i++)if(s[i]=='0')z++;
    if(x==0 and (!(z&1) or z==1))cout<<"BOB"<<endl;
    else if(x == 1 and z == 2)cout<<"DRAW"<<endl;
    else cout<<"ALICE"<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}