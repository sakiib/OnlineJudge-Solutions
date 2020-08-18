#include<bits/stdc++.h>
using namespace std;

int n;
int ara[100];
const int INF=100000;

int solve(int i,int moov) {
    //cout<<"i - moov : "<<i<<" "<<moov<<endl;
    if(i<0||i>n||moov>n) {cerr<<"in:"; return INF;}
    if(i==n) {cerr<<"out";return moov;}
    int op1=INF,op2=INF;
    op1=solve(i+1,moov+1);
    op2=solve(i+ara[i],moov+1);
    cerr<<min(op1,op2)<<endl;
    return min(op1,op2);
}
int main(int argc,char const *argv[]) {
    int t;
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=0;i<n;i++) {
            cin>>ara[i];
        }
        int ans=solve(0,0);
        if(ans==INF) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}
