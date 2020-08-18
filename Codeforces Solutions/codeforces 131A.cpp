#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    string str;
    cin>>str;

    bool nope=false;
    bool small=false;

    for(int i=0;i<str.size();i++) {
        if(str[i]>='a'&&str[i]<='z') {
            nope=true; break;
        }
    }
    if(!nope) {
        for(int i=0;i<str.size();i++) {
            str[i]+=32;
        }
        cout<<str<<endl;
        return 0;
    }
    for(int i=1;i<str.size();i++) {
        if(str[i]>='a'&&str[i]<='z') {
            small=true; break;
        }
    }
    if(str[0]>='a'&&str[0]<='z'&&!small) {
            str[0]-=32;
        for(int i=1;i<str.size();i++) {
            str[i]+=32;
        }
        cout<<str<<endl;
        return 0;
    }
    cout<<str<<endl;
    return 0;
}

