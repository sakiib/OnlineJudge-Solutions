#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll sum[1000100]={0};
ll ans[1000100]={0};
ll res=0;
int main(int argc,char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll k;
    cin>>k;
    string str;
    cin>>str;
    ans[0]=1LL;
    int n=str.size();
    for(int i=1;i<=n;i++) {
        sum[i]=(sum[i-1]+str[i-1]-'0');
        cerr<<"sum : "<<sum[i]<<endl;
        if(sum[i]-k>=0) {
            res+=ans[sum[i]-k];
            cerr<<"res : "<<res<<endl;
        }
        ans[sum[i]]++;
    }
    cout<<res<<endl;
    return 0;
}
