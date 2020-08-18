#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(int argc,char const *argv[]) {
    string str;
    cin>>str;
    bool a=false;
    int l=0;
    for(int i=0;i<str.size();i++) {
        if(str[i]=='a') {
            a=true; l=i; break;
        }
    }
    int r=0;
    for(int i=str.size()-1;i>=l;i--) {
        if(str[i]=='a') {
            r=i;
            break;
        }
    }
    int op1=(r-l+1);
    int x=0;
    for(int i=str.size()-1;i>=l;i--) {
        if(str[i]=='b') {
            x=i;
            break;
        }
    }
    int bad=0;
    for(int i=l+1;i<x;i++) {
        if(str[i]=='a') bad++;
    }
    int op2=(x-l+1)-bad;
    cout<<max(op1,op2)<<endl;
    return 0;
}

