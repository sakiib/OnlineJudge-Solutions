#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    string str;
    string s="";
    set<string> S;
    while(cin>>str) {
        s="";
        for(int i=0;i<str.size();i++) {
            if((str[i]>='A'&&str[i]<='Z')||(str[i]>='a'&&str[i]<='z')) {
                char x=tolower(str[i]);
                s+=x;
            }
            else {
                if(s!="") { S.insert(s); s="";}
            }
        }
        if(s!="") { S.insert(s); }
    }
    for(auto x:S) {
        cout<<x<<endl;
    }
    S.clear();
    return 0;
}
