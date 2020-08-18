#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll fact[100000];
bool flag;
ll n;
bool used[20];

void calc() {
    fact[0]=1LL;
    fact[1]=1LL;
    for(ll i=1;i<=20;i++) {
        fact[i]=i*fact[i-1];
    }
}
int main(int argc,char const *argv[]) {
    calc();
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        scanf("%lld",&n);
        vector<ll> V;
        V.clear();
        for(ll i=20;i>=0;i--) {
            if(fact[i]<=n) {
                n-=fact[i];
                V.push_back(i);
            }
        }
        reverse(V.begin(),V.end());
        if(n!=0) printf("Case %d: impossible\n",tc);
        else {
            printf("Case %d: ",tc);
            for(int i=0;i<V.size();i++) {
                if(!i) printf("%d!",V[i]);
                else printf("+%d!",V[i]);
            }
            cout<<endl;
        }
    }
    return 0;
}
