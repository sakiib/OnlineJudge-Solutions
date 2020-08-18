#include<bits/stdc++.h>
using namespace std;

bool mod(string &s,int m) {
    int res=0;
    for(int i=0;i<s.size();i++) {
        res=((res%m*10%m)%m+(s[i]-'0')%m)%m;
    }
    if(res==0) return true;
    else return false;
}
bool check_leap(string &str) {
    if(mod(str,400)||(mod(str,4)&&!mod(str,100))) return true;
    else return false;
}
bool check_hulu(string &str) {
    if(mod(str,15)) return true;
    else return false;
}
bool check_bulu(string &str) {
    if(mod(str,55)&&check_leap(str)) return true;
    else return false;
}
int main(int argc,char const *argv[]) {
    string str;
    bool start=false;
    while(cin>>str) {
        if(start) printf("\n");
        start=true;
        bool leap=false;
        bool hulu=false;
        bool bulu=false;
        leap=check_leap(str);
        hulu=check_hulu(str);
        bulu=check_bulu(str);
        if(!leap&&!hulu&&!bulu) printf("This is an ordinary year.\n");
        if(leap) printf("This is leap year.\n");
        if(hulu) printf("This is huluculu festival year.\n");
        if(bulu) printf("This is bulukulu festival year.\n");
    }
    return 0;
}
