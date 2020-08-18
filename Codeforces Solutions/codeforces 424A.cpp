#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    string str;
    cin>>str;
    int u=n/2,d=n/2;
    for(int i=0;i<str.size();i++) {
        if(str[i]=='X') u--;
        else d--;
    }
    int ans=0;
    for(int i=0;i<str.size();i++) {
        if(str[i]=='x') {
            if(u>0) {
               u--;
               str[i]='X';
               ans++;
            }
        }
        else if(str[i]=='X') {
            if(d>0) {
                d--;
                str[i]='x';
                ans++;
            }
        }
    } cout<<ans<<endl<<str<<endl;
    return 0;
}
