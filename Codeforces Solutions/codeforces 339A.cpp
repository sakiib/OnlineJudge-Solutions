#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    string str;
    cin>>str;
    string s="";
    for(auto c : str) {
        if(c!='+') s+=c;
    }
    sort(s.begin(),s.end());
    for(int i=0;i<s.size();i++) {
        cout<<s[i];
        if(i!=s.size()-1) cout<<'+';
    }
    return 0;
}
