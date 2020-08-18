#include<bits/stdc++.h>
using namespace std;

 int ara[10][10];

 int happiness(string &str) {
     int ans=0;
     ans+=ara[str[0]-'0'][str[1]-'0'];
     ans+=ara[str[1]-'0'][str[0]-'0'];
     ans+=ara[str[1]-'0'][str[2]-'0'];
     ans+=ara[str[2]-'0'][str[1]-'0'];
     ans+=ara[str[2]-'0'][str[3]-'0'];
     ans+=ara[str[3]-'0'][str[2]-'0'];
     ans+=ara[str[3]-'0'][str[4]-'0'];
     ans+=ara[str[4]-'0'][str[3]-'0'];
     ans+=ara[str[2]-'0'][str[3]-'0'];
     ans+=ara[str[3]-'0'][str[2]-'0'];
     ans+=ara[str[3]-'0'][str[4]-'0'];
     ans+=ara[str[4]-'0'][str[3]-'0'];
     //cerr<<ans<<endl;
     return ans;
 }
int main(int argc,char const *argv[]) {
    string str="12345";
    for(int i=1;i<=5;i++) {
        for(int j=1;j<=5;j++) {
            cin>>ara[i][j];
        }
    }
    int t=120,val=0,mx=0;
    while(t--) {
        //cout<<str<<endl;
        val=happiness(str);
        mx=max(mx,val);
        next_permutation(str.begin(),str.end());
        //cerr<<str<<endl;
    }
    cout<<mx<<endl;
    return 0;
}
