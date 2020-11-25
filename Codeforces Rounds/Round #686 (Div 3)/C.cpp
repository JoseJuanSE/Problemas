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
    int n;
    cin>>n;
    vi arre(n);

    forn(i,n){
        cin>>arre[i];
    }
    vi simp;
    simp.pb(arre[0]);
    forr(i,1,n-1){
        if(simp[simp.size()-1]!=arre[i]){
            simp.push_back(arre[i]);
        }
    }
    //for(int i:simp)cout<<i<<" ";
    //cout<<endl;
    if(simp.size()==1)cout<<0<<endl;
    else{
        unordered_map<int,int> HT;
        int maxi=INT_MAX;
        forr(i,1,simp.size()-2){
            //cout<<simp[i]<<" ";
            HT[simp[i]]++;
        }
        forr(i,1,simp.size()-2){
            maxi = min(maxi,HT[simp[i]]);
        }
        if(HT[simp[0]]==0)cout<<1<<endl;
        else if(HT[simp[simp.size()-1]]==0)cout<<1<<endl;
        else cout<<maxi+1<<endl;
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
