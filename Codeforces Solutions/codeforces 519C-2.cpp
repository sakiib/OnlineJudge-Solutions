#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
map<pair<LL,LL>,LL > M;

LL solve(LL n,LL m) {
    if(n<=0||m<=0) return 0;
    if(M[{n,m}]!=0) return M[{n,m}];
    LL op1=0,op2=0;
    if(n>=1&&m>=2)  op1=solve(n-1,m-2)+1;
    if(n>=2&&m>=1)  op2=solve(n-2,m-1)+1;
    return M[{n,m}]=max(op1,op2);
}
int main(int argc,char const *argv[]) {
    LL n,m;
    cin>>n>>m;
    cout<<solve(n,m)<<endl;
    return 0;
}
