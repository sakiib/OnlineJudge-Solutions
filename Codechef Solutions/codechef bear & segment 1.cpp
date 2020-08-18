#include<bits/stdc++.h>
using namespace std;

bool check(string &str) {
    int ind;
    bool found=false;
    for(int i=0;i<str.size();) {
        string ret="";
        if(str[i]=='1') {
            while(str[i]=='1') {
                i++;
                found=true;
                ret+=str[i];
            }
        }
        else i++;
        if(found) {
            ind=i; break;
        }
    }
    if(!found) return false;
    for(int i=ind;i<str.size();i++) {
        if(str[i]=='1') return false;
    }
    return true;
}
int main(int argc,char const *argv[]) {
    int t;
    cin>>t;
    while(t--) {
        string str;
        cin>>str;
        puts(check(str)?"YES":"NO");
    }
    return 0;
}
