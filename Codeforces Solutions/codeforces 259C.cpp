#include<bits/stdc++.h>
using namespace std;

void solve2(string &str) {
    for(int i=0;i<str.size()-1;i++) {
        cout<<str[i];
    }
    cout<<endl;
    return;
}
void solve1(string &str) {
    string ans="";
    int ind;
    for(int i=0;i<str.size();i++) {
        if(str[i]=='0') {
            ind=i; break;
        }
        else ans+=str[i];
    }
    for(int i=ind+1;i<str.size();i++) {
        ans+=str[i];
    }
    cout<<ans<<endl;
    return;
}
int main(int argc,char const *argv[]) {
    string str;
    cin>>str;
    bool yes=false;
    for(int i=0;i<str.size();i++) {
        if(str[i]=='0') {
            yes=true; break;
        }
    }
    if(yes) solve1(str);
    else solve2(str);
    return 0;
}
