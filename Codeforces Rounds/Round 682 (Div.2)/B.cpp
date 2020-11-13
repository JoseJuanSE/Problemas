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


using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

bool solve(){
    int n,b;
    cin>>n;
    map<int,int> a;
    a.clear();
    bool ans=false;
    forn(i,n){
        cin>>b;
        a[b]++;
        if(a[b]>1)ans=true;
    }
    return ans;
}
int main(){
    int t=1;
    cin>>t;
    while(t--)
        if(solve())
            cout<<"YES"<<endl;
        else 
            cout<<"NO"<<endl;
    return 0;
}