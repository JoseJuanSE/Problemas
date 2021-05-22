#include<bits/stdc++.h>
#define MOD ll(1e9)
#define endl "\n"

using namespace std;

typedef long long ll;
typedef vector<vector<ll> > vii;
typedef vector<ll> vi;

vii mat_mult(vii &a,vii &b){
    assert(a[0].size() == b.size());
    vii ans (a.size(),vi(b[0].size(),0));
    for(ll i=0;i<a.size();i++)
        for(ll j=0;j<b[0].size();j++)
            for(ll k=0;k<a[0].size();k++)
                ans[i][j] = (ans[i][j] + a[i][k]*b[k][j]%MOD)%MOD;
    return ans;
}

void solve(){
    ll k,n;
    cin>>k;
    vii matriz (k,vi(k,0));
    vi ini(k,0);
    for(ll i=k-1;i>=0;i--) // initial values
        cin>>ini[i];
    for(ll i=0;i<k;i++) // transitional values
        cin>>matriz[0][i];
    for(ll i=1;i<k;i++)
            matriz[i][i-1]=1;
    cin>>n;
    if(n<=k){
        cout<<ini[k-n]<<endl;
        return ;
    }
    n-=k;
    vii fin (k,vi(k,0));
    for(ll i=0;i<k;i++)fin[i][i] = 1;
    while(n){
        if(n&1)fin = mat_mult(fin,matriz);
        matriz = mat_mult(matriz,matriz);
        n>>=1;
    }
    ll answer = 0;
    for(ll i=0;i<k;i++)
        answer = (answer + (fin[0][i]*ini[i])%MOD)%MOD;
    cout<<answer<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll t=1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}