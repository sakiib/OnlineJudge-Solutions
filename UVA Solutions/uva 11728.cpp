#include<bits/stdc++.h>
using namespace std;

int ara[100010];
map<int,int> M;

void calc() {
    for(int i=1;i<=100000;i++) {
        for(int j=i;j<=100000;j+=i) {
            ara[j]+=i;
        }
    }
    for(int i=1;i<=100000;i++) {
        M[ara[i]]=i;
    }
}
int main(int argc,char const *argv[]) {
    int sum;
    calc();
    int tc=1;
    while(scanf("%d",&sum)) {
        if(sum==0) break;
        if(M[sum]==0) printf("Case %d: -1\n",tc);
        else printf("Case %d: %d\n",tc,M[sum]);
        tc++;
    }
    return 0;
}
