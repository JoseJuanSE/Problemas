#include<bits/stdc++.h>
//name: Divide by three, multiply by two
//url: https://codeforces.com/problemset/problem/977/D

#define forn(i,n) for (int i = 0; i < n; i++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<ll> > vvi;

ll arre[105];

void solve(){
    int n;
    cin>>n;
    unordered_map<ll,int> pos;
    forn(i,n){
        cin>>arre[i];
        pos[arre[i]]=i;
    }
    vvi graph(n+1);
    vi ind(n+1,0);
    forn(i,n){
        if(arre[i]%3==0 and pos.find(arre[i]/3) != pos.end()){
            ll a=pos[arre[i]/3];
            graph[i].push_back(a);
            ind[a]++;
        }
        if(pos.find(arre[i]*2) != pos.end()){
            graph[i].push_back(pos[arre[i]*2]);
            ind[pos[arre[i]*2]]++;
        }
    }
    queue<int> bfs;
    forn(i,n){
        if(ind[i]==0){
            bfs.push(i);
        }
    }
    vector<bool> vis(n+2,false);
    while(!bfs.empty()){
        int currp=bfs.front();
        bfs.pop();
        cout<<arre[currp]<<" ";
        vis[currp]=true;
        for(int i:graph[currp]){
            if(!vis[i]){
                vis[i]=true;
                bfs.push(i);
            }
        }
    }
}
int main(){
    solve();
    return 0;
}
