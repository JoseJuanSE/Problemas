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

vl s;
vl a;
ll n,m,x;
set<ll>ps;

void divi(ll ini,ll fin){
    ll ss;
    if(ini!=0)ss=s[fin]-s[ini-1];
    else ss=s[fin];
    ps.insert(ss);

    if(a[ini]==a[fin]){
        return;
    }
    
    x = (a[fin]+a[ini])/2;
    ll pos = upper_bound(a.begin()+ini,a.begin()+fin,x)-a.begin();
    divi(ini,pos-1);
    divi(pos,fin);
}
void solve(){
    cin>>n>>m;
    a.assign(n,0);
    forn(i,n)cin>>a[i];
    sort(ALL(a));
    s.assign(n,0);
    s[0]=a[0];
    forr(i,1,n-1){
        s[i]+=a[i]+s[i-1];
    }
    ps.clear();
    divi(0,n-1);
    forn(i,m){
        int x;
        cin>>x;
        if(ps.find(x)!=ps.end()){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
}
int main(){
    fast
    int t=1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
