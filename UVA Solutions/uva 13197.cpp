#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll cube(ll n) {
    return (n*n*n);
}
int main(int argc,char const *argv[]) {
    ll p,a;
    while(scanf("%lld%lld",&p,&a)==2) {
    vector<ll> V;
    V.clear();
    for(ll i=1;i<a;i++) {
        if(cube(i)%a==p) V.push_back(i);
    }
    if(V.size()==0) {
        if(p==0) printf("0\n");
        else printf("\n");
    }
    else {
        for(int i=0;i<V.size();i++) {
            if(i==0) printf("%lld",V[i]);
            else printf(" %lld",V[i]);
        }
        printf("\n");
     }
   }
    return 0;
}
