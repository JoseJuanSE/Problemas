#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
void KMP(string &a,string &b){
    vector<int> lps(a.size(),0);
    int beg=0,j=0;
    for(int i=1;i<a.size();i++){
        if(a[beg]==a[i]){beg++;lps[i]=beg;}
        else if(beg!=0){beg = lps[beg-1];i--;}
    }
    vector<int> ans;
    for(int i=0;i<b.size();i++){
        if(a[j]==b[i]){
            j++;
            if(j==a.size()){
                j--;
                ans.push_back(i-a.size()+2);
                bool f = true;
                while(j!=0 and (a[j]!=b[i] or f)){
                    j = lps[j-1];
                    f=false;
                }
                i--;
            }
        }else{
            while(j!=0 and a[j]!=b[i]) j = lps[j-1];
        }
    }
    if(ans.empty())cout<<endl<<"Not Found"<<endl<<endl;
    else{
        cout<<ans.size()<<endl;
        for(int i:ans)cout<<i<<" ";
        cout<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        string a,b;
        cin>>b>>a;
        KMP(a,b);
    }
    
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
#define MU 123
#define ULL unsigned long long
ULL hashe[1000009];
void prehashe(char str[] , int n)
{
    hashe[n] = 0;
    for(int i = n-1 , j = 1 ; i>=0 ; i-- , j++){
        hashe[i] = hashe[i+1]*MU + str[i] - 97;
    }
}
void solve(char text[] , char pattern[] , int p , int t){
    ULL p_hashe = 0 , check , pre = 1;
    for(int i = p-1 ; i>=0 ; i--){
        p_hashe = p_hashe*MU + pattern[i] - 97;
        pre = pre*MU;
    }
    check = p_hashe;
    vector<int> v;
    int flag = 0;
    prehashe(text , t);
    for(int i = 0; i < t - p + 1 ; i++ )
        if(hashe[i] - pre*hashe[i+p] == check){
            flag++;
            v.push_back(i+1);
        }
    if(flag == 0)
        printf("Not Found\n");
    else
    {
        printf("%d\n",flag);
        for(int i = 0 ; i < flag ; i++)
            printf("%d ",v[i]);
        printf("\n");
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char text[1000009] ,  pattern[1000009];
        scanf("%s%s",text , pattern);
        int n , m ;
        n = strlen(text);
        m = strlen(pattern);
        solve(text , pattern , m , n);
    }
    return 0;
}*/