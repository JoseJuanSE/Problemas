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

int n,maxupd;
vector<string> m;

void solve(){
    cin>>n;
    m.resize(n);
    forn(i,n)
        cin>>m[i];
    vi cub(3,0);
    forn(i,n){
        forn(j,n){
            if(m[i][j]=='X')cub[(i+j)%3]++;
        }
    }
    int ini;
    if(cub[0]<=cub[1] and cub[0]<=cub[2])ini=0;
    if(cub[1]<=cub[0] and cub[1]<=cub[2])ini=1;
    if(cub[2]<=cub[1] and cub[2]<=cub[0])ini=2;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(m[i][j]=='X' and (i+j)%3==ini)m[i][j]='O';
        }
    }
    forn(i,n){
        forn(j,n){
            cout<<m[i][j];
        }    
        cout<<endl;
    }
}
int main(){
    //OJ;
    int t=1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}