#include<bits/stdc++.h>
using namespace std;

int fact[1000];

void calc() {
    fact[0]=1;
    for(int i=1;i<=10;i++) {
        fact[i]=fact[i-1]*i;
    }
}
int main(int argc,char const *argv[]) {
    int n,k;
    calc();
    while(scanf("%d%d",&n,&k)) {
        if(n==0&&k==0) break;
        int cnt=0;
        vector<int> V;
        int val=fact[n];
        int sq=sqrt(val);
        for(int i=1;i<=sq;i++) {
            if(val%i==0) {
                V.push_back(i);
                if(val/i!=i) V.push_back(val/i);
            }
        }
        int ans=0;
        for(int i=0;i<V.size();i++) {
            if(V[i]%k==0) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
