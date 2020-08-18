#include<bits/stdc++.h>
using namespace std;

const int N=100005;

int dp[N];

int main(int argc,char const *argv[]) {
    string str;
    cin>>str;
    int l=str.size();
    for(int i=1;i<str.size();i++) {
        if(str[i]==str[i-1]) dp[i]=1;
        else dp[i+1]=0;
    }
    dp[0]=0; dp[l]=0;
    for(int i=1;i<=l;i++) {
        dp[i]+=dp[i-1];
    }
    int q;
    cin>>q;
    while(q--) {
        int l,r;
        cin>>l>>r;
        l--,r--;
        cout<<dp[r]-dp[l]<<endl;
    }
    return 0;
}
