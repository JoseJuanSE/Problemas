#include<bits/stdc++.h>
using namespace std;
int next10Step(int x){
    int p = int(log10(x)+1),ans = 1;
    for(int i=0;i<p;i++)ans*=10;
    return ans;
}
int main(){
    for(int i=1;i<=1000;i++){
        cout<<i<<" ---> "<<next10Step(i)<<endl;
    }
}