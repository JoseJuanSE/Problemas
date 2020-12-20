#include<bits/stdc++.h>
//Problem: Problemas con el horario
//Link: https://matcomgrader.com/problem/9245/problemas-con-el-horario/
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int ans[1000005];
    for(int i=0;i<10005;i++)ans[i]=0;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        ans[a]++;
        ans[b+1]--;
    }
    
    for(int)
}