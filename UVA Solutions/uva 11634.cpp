#include<bits/stdc++.h>
using namespace std;

int st_int(string &str) {
    int num; stringstream st(str);
    st>>num; return num;
}
string int_st(int num) {
    string res; stringstream convert;
    convert<<num; res=convert.str(); return res;
}
int main(int argc,char const *argv[]) {
    int n;
    int t=1;
    while(scanf("%d",&n)) {
        if(n==0) break;
        map<int,bool> M;
        int ans=0;
        while(!M[n]) {
            M[n]=true;
            ans++;
            n=n*n;
            n/=100;
            n%=10000;
        }
        printf("%d\n",ans);
    }
    return 0;
}
