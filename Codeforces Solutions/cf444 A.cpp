#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(int argc,char const *argv[]) {
    string str;
    cin>>str;
    string s="1000000";
    int idx=0;
    for(int i=0;i<str.size();i++) {
        if(str[i]==s[idx]) {
            idx++;
        }
        if(idx==7) break;
    }
    if(idx==7) puts("yes");
    else puts("no");
    return 0;
}
