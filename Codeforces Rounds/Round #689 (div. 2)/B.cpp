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
#define bs(v,f) binary_search(ALL(v),f)
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
char mapa[502][502];
int a1[502][502];
int a2[502][502];
int n,m;
int checktree(int y,int x,int an){
    if(y>=n or an>a1[y][x])return 1;
    return checktree(y+1,x,an+2)+1;
}
void solve(){    
    cin>>n>>m;
    forn(i,n){
        forn(j,m){
            cin>>mapa[i][j];
            a1[i][j]=0;
            a2[i][j]=0;
        }
    }
    forn(i,n){
        forn(j,m){
            if(mapa[i][j]=='*')a1[i][j]++;
            if(j>0 and mapa[i][j-1]=='*')a1[i][j]+=a1[i][j-1];
        }
    }
    forn(i,n){
        for(int j=m-1;j>=0;j--){
            if(mapa[i][j]=='*')a2[i][j]++;
            if(j<m-1 and mapa[i][j+1]=='*')a2[i][j]+=a2[i][j+1];
        }
    }
    forn(i,n){
        forn(j,m){
            if(mapa[i][j]=='*'){
                bool xd= a1[i][j]-1 and a2[i][j]-1;
                a1[i][j]=min(a1[i][j],a2[i][j]);
                if(xd)a1[i][j]++;
            }
            cout<<a1[i][j]<<" ";
        }
        cout<<endl;
    }
    int ans = 0;
    forn(i,n){
        forn(j,m){
            if(a1[i][j]){
                ans += checktree(i,j,1);
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    fast
    int t=1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}