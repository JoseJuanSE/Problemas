#include<bits/stdc++.h>
//problem name: CHAIN - Strange Food Chain spoj
//url: https://www.spoj.com/problems/CHAIN/
//not solve still
using namespace std;
bool puedecomer(int a,int b){
    if(a==0 and b==1)return true;
    if(a==1 and b==2)return true;
    if(a==2 and b==0)return true;
    return false;
}
int hascxigcy(int a,int b){
    return a<=b?b-a:(b+3-a);
}
struct UFDS{
    vector<int>p,inv;
    UFDS(int n){
        n++;
        p.assign(n,0);
        inv.assign(n,0);
        for(int i=0;i<n;i++)p[i]=i;
    }
    int FindSet(int i){return p[i]==i?i:FindSet(p[i]);}
    int FindColor(int i){
        if(p[i]==i)return inv[i];
        return (FindColor(p[i])+inv[i])%3;
    }
    bool IsSameSet(int i,int j){return FindSet(i)==FindSet(j);}
    void UnionSet(int i,int j){
        int ci=FindColor(i),cj=ci;
        //cout<<endl<<"*"<<ci<<" "<<cj<<"*\n";
        while(!puedecomer(ci,cj)){
            cj++;
            cj%=3;
            inv[j]++;
        }
        p[j]=i;
    }
};

void solve(){
    int n,m,r=0;
    cin>>n>>m;
    UFDS s(n);
    while(m--){
        int a,x,y;
        cin>>a>>x>>y;
        if(x>n or y>n){
            r++;
            //cout<<"---"<<x<<" "<<y<<endl;
        }else if(a==1){
            int cx=s.FindColor(x),cy=s.FindColor(y);
            if(s.IsSameSet(x,y)){
                if(cx!=cy){
                    r++;
                }
            }
        }else{
            int cx=s.FindColor(x),cy=s.FindColor(y);
            if(s.IsSameSet(x,y)){
                if(cx==cy or !puedecomer(cx,cy)){
                    r++;
                    //cout<<"---"<<x<<" "<<y<<endl;
                }
            }else{
                s.UnionSet(x,y);
            }
        }
    }
    cout<<r<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}/*
1
8 8
2 1 2 
1 2 3
2 3 2
2 3 1
1 1 3
2 5 4
1 1 5
1 1 2 
falsos:
3 , 5, 9.
*/
