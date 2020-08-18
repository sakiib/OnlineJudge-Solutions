#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int ara[10];
    cin>>ara[1]>>ara[2]>>ara[3]>>ara[4];
    string str;
    cin>>str;
    int ans=0;
    for(auto &i : str) {
        ans+=ara[i-'0'];
    }
    cout<<ans<<endl;
}
