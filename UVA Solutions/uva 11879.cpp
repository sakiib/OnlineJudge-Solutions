#include<bits/stdc++.h>
using namespace std;

inline bool String_Mod (string &s,int m) {
    int res=0;
    for(int i=0;i<s.size();i++) {
        res=((res%m*10%m)%m+(s[i]-'0')%m)%m;
    }
    if(res==0) return true;
    else return false;
}
int main(int argc,char const *argv[]) {
    string str;
    while(cin>>str) {
        if(str=="0") break;
        if(String_Mod(str,17)) printf("1\n");
        else printf("0\n");
    }
    return 0;
}
