#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gy,gn;

bool con(ll mid){
    return gy + gn*mid;
}
ll bs(ll ini,ll fin){
    if(fin==ini)
        return ini;
    ll mid = (ini+fin)/2+1;
    if(con(mid)>0)return bs(ini,mid-1);
    return bs(mid,fin);
}
void extenea(ll a,ll b,ll &x,ll &y){
    if(a<b)swap(a,b);
    if(b==0){x=1;y=0;return ;}
    extenea(b,a%b,x,y);
    ll x1=y;
    ll y1=x-(a/b)*y;
    x=x1;y=y1;
}
int main(){
    ll n,c1,c2,n1,n2;
    while(cin>>n){
        bool in=false;
        cin>>c1>>n1>>c2>>n2;
        if(c1>c2){
            in = true;
            swap(c1,c2);
            swap(n1,n2);
        }
        ll g = __gcd(n1,n2);
        if(n % g != 0){
            cout<<"failed"<<endl;
        }else{
            ll x,y,x1,y1;
            extenea(n1,n2,x,y);
            x*=n/g;
            y*=n/g;
            if(n1<n2){
                x*=-1;
                y*=-1;
            }
            gy=y;
            gn=n1;
            ll nn = bs(0,2000000000);
            x1 = x + n2*nn;
            y1 = y + n1*nn;
            if(in)cout<<y1<<" "<<x1<<endl;
            else cout<<x1<<" "<<y1<<endl;
        }
    }
}