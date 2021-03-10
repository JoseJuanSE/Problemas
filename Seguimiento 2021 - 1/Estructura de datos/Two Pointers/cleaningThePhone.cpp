#include<bits/stdc++.h>

//--------------definitions-------------
#define endl '\n'
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define ALL(v) v.begin(), v.end()
#define ALLR(v) v.rbegin(), v.rend()
#define UNIQUE(v) (v).resize(unique(ALL(v))-(v).begin())
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i, a, b) for(int i=(int)a;i <= (int)b;i++)
#define forri(i, b, a) for(int i=(int)b; i >= (int)a;i--)
#define bse(v,f) binary_search(ALL(v),f)
#define lb(v,f) lower_bound(ALL(v),f)
#define ub(v,f) upper_bound(ALL(v),f)
#define SZ(x) (int)x.size()
#define pub push_back
#define MOD int(1e9+7)
//--------------definitions-------------

using namespace std;

//--------------DEBUG--------------
#define ts to_string
string ts(char c) { return string(1, c); }
string ts(bool b) { return b ? "true" : "false"; }
string ts(const char* s) { return (string)s; }
string ts(string s) { return s; }
template<class A> string ts(complex<A> c) { 
    stringstream ss; ss << c; return ss.str(); }
string ts(vector<bool> v) { 
    string res = "{"; for(int i = 0; i < (int)(v).size(); ++i) res += char('0' + v[i]);
    res += "}"; return res; }
template<size_t SZ> string ts(bitset<SZ> b) {
    string res = ""; for(int i = 0; i < SZ; ++i) res += char('0' + b[i]);
    return res; }
template<class A, class B> string ts(pair<A,B> p);
template<class T> string ts(T v) { // containers with begin(), end()
    bool fst = 1; string res = "{";
    for (const auto& x: v) {
        if (!fst) res += ", ";
        fst = 0; res += ts(x);
    }
    res += "}"; return res;
}
template<class A, class B> string ts(pair<A,B> p) {
    return "(" + ts(p.fi) + ", " + ts(p.se) + ")"; }

void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
    cerr << ts(h); if (sizeof...(t)) cerr << ", ";
    DBG(t...); }
void EDBG(string names) { names = names; }
template<class H, class... T> void EDBG(string names, H h, T... t) {
    auto pos = names.find(',');
    auto first_name = names.substr(0, pos);
    auto rest = names.substr(pos + 1);
    while(rest.front() == ' '){
        rest = rest.substr(1);
    }
    cerr << "[" << first_name << "]: [" << ts(h) << "]" << "\n";
    EDBG(rest, t...);
}
#ifdef LOCAL
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#define edbg(...) EDBG(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 0
#define edbg(...) 0
#endif
//--------------DEBUG--------------
//--------------DTypes-------------
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> ii;
typedef pair<ii, ll> iii;
typedef vector<ll> vi;
typedef vector<vector<ll> > vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;
//--------------DTypes-------------
void solve(){
    ll n,m,s=0,b;
    cin>>n>>m;
    vi im1,im2,a;
    im1.clear();im2.clear();a.clear();
    //value
    forn(i,n){
        cin>>b;
        s+=b;
        a.push_back(b);
    }
    forn(i,n){
        cin>>b;
        if(b==1){
            im1.push_back(a[i]);
        }else{
            im2.push_back(a[i]);
        }
    }
    if(s<m){
        cout<<-1<<endl;
        return ;
    } 
    s=1e9;
    sort(ALL(im1));
    sort(ALL(im2));
    im1.push_back(0);
    im2.push_back(0);
    reverse(ALL(im1));
    reverse(ALL(im2));
    forr(i,1,im1.size()-1){
        im1[i]+=im1[i-1];
    }
    forr(i,1,im2.size()-1){
        im2[i]+=im2[i-1];
    }
    forn(i,im1.size()){
        ll d = lower_bound(ALL(im2),m-im1[i])-im2.begin();
        if(d<im2.size()){
            ll otro = i+d*2;
            s = min(s,otro);
        }
    }
    if(s==1e9)cout<<-1<<endl;
    else cout<<s<<endl;
}
int main(){
    fast
    ll t=1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
