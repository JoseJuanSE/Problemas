#include<bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define ALL(v) v.begin(), v.end()
#define ALLR(v) v.rbegin(), v.rend()
#define deb cout<<"HOLA\n";
#define UNIQUE(v) (v).resize(unique(ALL(v))-(v).begin())
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define bse(v,f) binary_search(ALL(v),f)
#define lb(v,f) lower_bound(ALL(v),f)
#define ub(v,f) upper_bound(ALL(v),f)
#define pb push_back
#define MOD int(1e9)+7;

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;
int com(int x){
    
}
void solve(){
    int n,m,k;
    //m -> range size
    //k -> max - min <= k
    cin>>n>>m>>k;
    vi a(n);
    forn(i,n)cin>>a[i];
    sort(ALL(a));
    ll ans = 0;
    int ini=0,fin=k-1;
    while(fin<n){
        if(a[fin]-a[ini]<=k){
            fin++;
        }else{
            ans+=com(fin-ini+1);
        }
    }
    cout<<ans%MOD;
}
int main(){
    fast
    int t=1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
