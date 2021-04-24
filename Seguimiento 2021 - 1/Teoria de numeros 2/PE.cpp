#include<bits/stdc++.h>
using namespace std;
vector<bool> sieve;
vector<long long> p;
long long nprimes;
void si(){
    long long n = 1e6+10000;
    sieve.assign(n+100, true);
    sieve[0] = sieve[1] = false;
    for(long long i=4;i<=n;i+=2){
        sieve[i]=false;
    }
    nprimes++;
    for(long long i=3;i<=n;i+=2){
        if(sieve[i]){
            nprimes++;
            if(i>1001000)return;
            if(i!=3)p.push_back(i);
            if((long long)i*i <= n)
                for(long long j=i*i;j<=n;j+=2*i){
                    sieve[j]=false;
                }
        }
    }
}
long long next10Step(long long x){
    long long p = int(log10(x)+1),ans = 1;
    for(long long i=0;i<p;i++)ans*=10;
    return ans;
}
tuple<long long,long long,long long> extgcd(long long a, long long b){
    if(b == 0){
        if(a > 0) return {a, 1, 0};
        else return {-a, -1, 0};
    }else{
        long long d, x, y; tie(d, x, y) = extgcd(b, a%b);
        return {d, y, x - (a/b)*y};
    }
}
long long inverse(long long a, long long m){
    long long d, x, y; tie(d, x, y) = extgcd(a, m); // en C++11 y anteriores
    if(x < 0) x += m; // x puede ser negativa
    return x;
}
long long get_S(long long p1,long long p2){
    // p2*x congruente con p1 (next10Step(p1))
    long long m = next10Step(p1);
    long long invp2 = inverse(p2,m)*p1;
    invp2%=m;
    if(invp2<0)invp2+=m;
    return p2*invp2;
}
int main(){
    si();
    // p[3] -> 5 primer primo
    //p[0]->5 y p[78495]-> 999983
    cout<<p.size()<<endl;
    cout<<get_S(7,11)<<endl;
    // ans tiene el primer numero que acaba en 5 y es multiplo de 7
    //no se mete en el algorimo debido a que el gcd de 5 y 10 es 5, no 1, como el resto
    unsigned long long ans = 35;
    for(long long i=1;i<=78495;i++){
        long long s = get_S(p[i],p[i+1]);
        if(s%p[i+1]!=0){
            cout<<"PROBLEMAS"<<endl;
            cout<<p[i]<<" "<<p[i+1]<<" "<<s<<endl;
            break;
        }
        ans += s;
    }
    cout<<ans<<endl;
    return 0;
}