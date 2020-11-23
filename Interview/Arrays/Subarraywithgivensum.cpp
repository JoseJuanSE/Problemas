#include <bits/stdc++.h>
//link: https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0
using namespace std;
long long arr[10000005];
void solve(){
    long long n,s;
    cin>>n>>s;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int beg=0,end=0;
    long long cs=0;
    while(end<n){
        cs+=arr[end];
        end++;
        while(cs>s){
            cs-=arr[beg];
            beg++;
        }
        if(cs==s){
            cout<<beg+1<<" "<<end<<'\n';
            return ;
        }
    }
    cout<<-1<<'\n';
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
	int t;
	cin>>t;
	while(t--)
        solve();
	return 0;
}