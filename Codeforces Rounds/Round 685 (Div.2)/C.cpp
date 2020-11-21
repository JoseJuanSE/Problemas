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

void solve(){
    int n,k;
    cin>>n>>k;
    str a,b;
    cin>>a>>b;
    vi ca(27,0),cb(27,0);
    for(char i:a)
        ca[int(i)-int('a')]++;
    for(char i:b)
        cb[int(i)-int('a')]++;

    if(ca[int('z')-int('a')]>cb[int('z')-int('a')]){
        cout<<"NO"<<endl;
        return;
    }
    int tota=0,totb=0;
    for(int i=0;i<27;i++){
        tota+=ca[i]/k;
        totb+=cb[i]/k;
        ca[i]%=k;
        cb[i]%=k;
        if(totb>tota){
            cout<<"NO"<<endl;
            return;
        }
        if(ca[i]!=cb[i]){
            cout<<"NO"<<endl;
            return ;
        }
    }
    cout<<"YES"<<endl;
}
int main(){
    int t=1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
