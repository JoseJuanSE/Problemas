#include<bits/stdc++.h>

#define endl '\n'
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define forr(i,a,b) for (int i = a; i <= b; i++)

using namespace std;

int ma[503][503],n,m,t,c;
char ca[503][503];
int f(int i,int j,int cnum){
    if(i>n or ma[i][j]<cnum)return 0;
    return f(i+1,j,cnum+2)+1;
}
void solve(){
    cin>>n>>m;
    forr(i,1,n)
        forr(j,1,m)
            cin>>ca[i][j],ma[i][j]=(ca[i][j]=='*');
    forr(i,1,n)
        forr(j,2,m)
            ma[i][j] += ma[i][j] != 0? ma[i][j-1]:0;
    forr(i,1,n){
        c=0;
        for(int j=m;j>0;j--){
            if(ca[i][j]!='*'){
                c=0;
            }else{
                c++;
                ma[i][j] = min(c,ma[i][j]);
            }
        }
    }
    forr(i,1,n)
        forr(j,1,m)
            ma[i][j] = ma[i][j]!=0?2*ma[i][j]-1:0;
    int ans=0;
    forr(i,1,n)
        forr(j,1,m)
            ans+= ma[i][j]>0?f(i,j,1):0;
    cout<<ans<<endl;
}
int main(){
    fast
    cin>>t;
    while(t--)
        solve();
    return 0;
}