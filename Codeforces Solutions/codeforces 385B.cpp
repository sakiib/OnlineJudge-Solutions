#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(int argc,char const *argv[]) {
    string str;
    cin>>str;
    int l=str.size();
    if(l<4) {
        cout<<0<<endl;
        return 0;
    }
    ll ans=0;
    int pre=0;
    for(int i=0;i<l-3;i++) {
        if(str[i]=='b'&&str[i+1]=='e'&&str[i+2]=='a'&&str[i+3]=='r') {
            ans+=((l-i-3)*(i-pre+1));
            pre=i+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
