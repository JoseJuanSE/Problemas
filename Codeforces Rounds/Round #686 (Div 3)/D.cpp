#include<bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define ALL(v) v.begin(), v.end()
#define ALLR(v) v.rbegin(), v.rend()
#define deb cout<<"HOLA\n";
#define UNIQUE(v) (v).resize(unique(ALL(v))-(v).begin())
#define forn(i,n) for (ll i = 0; i < n; i++)
#define forr(i,a,b) for (ll i = a; i <= b; i++)
#define bse(v,f) binary_search(ALL(v),f)
#define lb(v,f) lower_bound(ALL(v),f)
#define ub(v,f) upper_bound(ALL(v),f)
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ll> iii;
typedef vector<ll> vi;
typedef vector<vector<ll> > vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

vector<ll> factors(ll n){
    vector<ll> primes;
    while(n%2==0){
        primes.push_back(2);
        n/=2;
    }
    for(ll i=3;i*i<=n;i+=2){
        while(n%i==0){
            primes.push_back(i);
            n/=i;
        }
    }
    if(n!=1)primes.push_back(n);
    return primes;
}
void solve(){
    ll n;
    cin>>n;
    vector<ll> primes = factors(n);
    unordered_map<ll,ll> HT;
    ll p,maxi=INT_MIN;
    
    for(ll i:primes){
        HT[i]++;
        if(HT[i]>maxi){
            maxi=HT[i];
            p=i;
        }
    }
    cout<<maxi<<endl;
    for(ll i=0;i<maxi-1;i++){
        cout<<p<<" ";
    }
    n=1;
    for(ll i:primes){
        if(i!=p)n*=i;
    }
    cout<<n*p<<endl;
}
int main(){
    ll t=1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
