#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int &i:arr)cin>>i;
    stack<int> s;
    int maxi=0;
    for(int i=0;i<n;i++){
        if(s.empty() || arr[s.top()]<=arr[i])
            s.push(i);
        else{
            int ind=s.top();
            s.pop();
            while(!s.empty() && arr[ind]>=arr[i]){
                ind=s.top();
                s.pop();
                maxi = max(maxi,arr[ind]*s.empty()?i:(i-ind-1));
            }
        }
    }
    if(!s.empty()){
        int ind=s.top();
        s.pop();
        while(!s.empty() ){
            ind=s.top();
            s.pop();
            maxi = max(maxi,arr[ind]*s.empty()?(n-1):(n-ind-2));
        }
    }
    cout<<maxi<<endl;
    return 0;
}