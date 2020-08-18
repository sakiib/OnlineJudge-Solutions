#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string str;
    cin>>str;
    string a="heavy";
    string b="metal";
    long long cnt=0,ans=0;
    for(int i=0;i<str.size();i++) {
        if(str.substr(i,5)==a) cnt++;
        if(str.substr(i,5)==b) ans+=cnt;
    }
    cout<<ans<<endl;
    return 0;
}
