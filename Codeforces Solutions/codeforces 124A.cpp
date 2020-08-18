#include<bits/stdc++.h>
using namespace std;


int solve(int n,int a,int b) {
    int pos1,pos2;
    pos1=a+1;
    pos2=n-b;
    cerr<<pos1<< " " <<pos2<<endl;
    int cnt=0;
    for(int i=1;i<=n;i++) {
        if(i>=pos1&&i>=pos2) cnt++;
    }
    return cnt;
}
int main(int argc,char const *argv[]) {
    int n,a,b,ans;
    cin>>n>>a>>b;
    ans=solve(n,a,b);
    cout<<ans<<endl;
    return 0;
}
