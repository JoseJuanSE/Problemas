#include<bits/stdc++.h>
using namespace std;
//not solved yet
typedef long long ll;
ll d,k,a;
bool con(ll mid){
    return mid*mid+a*a<=d*d;
}
ll bs(ll ini,ll fin){
    if(fin==ini)
        return ini;
    ll mid = (ini+fin)/2+1;
    if(con(mid))return bs(ini,mid-1);
    return bs(mid,fin);
}
void solve(){
    cin>>d>>k;
    for(ll an=0;an<=d;an++){
        a=an;
        ll al = bs(0,d);
        if((al+an)%2==0){
            cout<<"Utkarsh"<<endl;
            return ;
        }
    }
    cout<<"Ashish"<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
}