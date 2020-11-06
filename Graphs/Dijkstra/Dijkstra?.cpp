#include<bits/stdc++.h>
using namespace std;
//name: Dijkstra?
//url: https://codeforces.com/contest/20/problem/C
typedef unsigned long long ll;
const bool operator<(const pair<ll,int> &a,const pair<ll,int> &b){
    return !(a.first<b.first);
}
vector<pair<ll,int> >graph[100005];
vector<ll> mini,pa;
ll n,m;
void path(){
    ll curr=n;
    while(curr!=1){
        pa.push_back(curr);
        for(pair<ll,int> i:graph[curr]){
            if(mini[i.second]==mini[curr]-i.first){
                curr=i.second;
                break;
            }
        }
    }
    pa.push_back(1);
    reverse(pa.begin(),pa.end());
}
void dijkstra(ll a){
    priority_queue<pair<ll,ll>> pq;
    mini.assign(n+1,ULLONG_MAX);
    pq.push({0,a});
    mini[1]=0;
    while(!pq.empty()){
        pair<ll,int> curr= pq.top();
        pq.pop();
        for(pair<ll,int> i:graph[curr.second]){
            if(mini[i.second]>mini[curr.second]+i.first){
                mini[i.second]=mini[curr.second]+i.first;
                pq.push({mini[i.second],i.second});
            }
        }
    }
    path();
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin>>n>>m;

    while(m--){
        ll a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({c,b});
        graph[b].push_back({c,a});
    }
    dijkstra(1);
    if(mini[n]==ULLONG_MAX){
        cout<<-1;
        return 0;
    }
    for(int i=0;i<pa.size();i++)
        cout<<pa[i]<<" ";
    return 0;
}