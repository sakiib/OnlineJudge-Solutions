#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool divisible(string &str,ll d) {
    if(d<0) d*=-1;
    ll sum=0;
    for(int i=0;i<str.size();i++) {
        if(str[i]=='-') continue;
        sum=(sum*10+(str[i]-'0'))%d;
    }
    if(!sum) return true;
    return false;
}
int main(int argc,char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,tc;
    cin>>t;
    for(tc=1;tc<=t;tc++) {
        string str;
        cin>>str;
        ll d;
        cin>>d;
        if(divisible(str,d)) printf("Case %d: divisible\n",tc);
        else printf("Case %d: not divisible\n",tc);
    }
    return 0;
}
