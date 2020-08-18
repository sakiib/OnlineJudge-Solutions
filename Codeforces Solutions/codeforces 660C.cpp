#include<bits/stdc++.h>
using namespace std;

int dp[300010]={0};
int ara[300010];

int main(int argc,char const *argv[]) {
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
    }
    ara[0]=0;
    for(int i=1;i<=n;i++) {
        dp[i]=dp[i-1];
        if(!ara[i]) dp[i]++;
    }
    int from=-1,to=-1,j=1,temp=0;
    for(int i=1;i<=n;i++) {
        bool found=false;
        while(j<=n&&(dp[j]-dp[i-1])<=k) {
            found=true;
            j++;
        }
        if(found&&(temp<j-i)) {
            from=i;
            to=j-1;
            temp=j-i;
        }
    }
    cout<<temp<<endl;
    for(int i=1;i<=n;i++) {
        if(i>=from&&i<=to) cout<<1<< " ";
        else cout<<ara[i]<< " ";
    }
    return 0;
}
