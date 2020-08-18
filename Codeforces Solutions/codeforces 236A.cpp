#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=1000010;
const ll mod=1073741824;

int divi[N];

void calc() { //number of divisors
    for(int i=1;i<=N;i++) {
        for(int j=i;j<=N;j+=i) {
            divi[j]++;
        }
    }
}
int main(int argc,char const *argv[]) {
    calc();
    int a,b,c;
    cin>>a>>b>>c;
    ll ans=0;
    for(int i=1;i<=a;i++) {
        for(int j=1;j<=b;j++) {
            for(int k=1;k<=c;k++) {
               ans=(ans%mod+divi[i*j*k]%mod)%mod;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
