#include<bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;

const int inf=1e9; const LL INF=1e18;
const int N=100005; const int MOD=1e9+7;

vector<bool> mark(100005,true);
vector<int> V;

void calc() {
    for(int i=2;i<=N;i++) {
        if(mark[i]) {
            V.push_back(i);
            for(int j=i*i;j<=N;j+=)
        }
    }
}
int main(int argc,char const *argv[]) {
    int n;
    calc();
    while(scanf("%d",&n)) {
        if(n==0) break;
    }
    return 0;
}


