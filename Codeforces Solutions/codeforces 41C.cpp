#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    string str;
    cin>>str;
    int l=str.size();
    string a="at";
    string d="dot";
    bool done=false;
    for(int i=0;i<str.size();i++) {
        if(str.substr(i,2)==a&&!done) {
            if(i==0||(i+1==l-1)) continue;
            else {str[i]='@',str[i+1]='X'; done=true;}
        }
        if(str.substr(i,3)==d) {
            if(i==0||(i+2==l-1)) continue;
            else str[i]='.',str[i+1]='X',str[i+2]='X';
        }
    }
    //cout<<str<<endl;
    string ans="";
    for(auto c:str) {
        if(c!='X') ans+=c;
    }
    cout<<ans<<endl;
    return 0;
}
