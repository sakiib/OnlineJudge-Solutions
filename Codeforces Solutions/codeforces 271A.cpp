#include<bits/stdc++.h>
using namespace std;

string in_st(int y) {
    string ret="";
    while(y!=0) {
        int a=y%10;
        ret+=(a+'0');
        y=y/10;
    }
    reverse(ret.begin(),ret.end());
    //cerr<<ret<<endl;
    return ret;
}
int main(int argc,char const *argv[]) {
    int y;
    cin>>y;
    string ans;
    while(true) {
        y++;
        set<char> S;
        S.clear();
        string str;
        str=in_st(y);
        int n=str.size();
        for(int i=0;i<str.size();i++) {
            S.insert(str[i]);
        }
        if(S.size()==n) {
            ans=str; break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
