#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    string str;
    cin>>str;
    str+='X';
    set<char> S;
    int mx=0;
    for(int i=0;i<str.size();i++) {
        if(str[i]>='a'&&str[i]<='z') {
            S.insert(str[i]);
        }
        else {
            mx=max(mx,(int)(S.size()));
            S.clear();
        }
    }
    cout<<mx<<endl;
    return 0;
}
