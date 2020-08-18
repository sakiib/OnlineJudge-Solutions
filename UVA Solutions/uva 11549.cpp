#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

inline LL st_int(string &str) {
    LL num; stringstream st(str);
    st>>num; return num;
}
inline string int_st(LL num) {
    string res; stringstream convert;
    convert<<num; res=convert.str(); return res;
}
LL first_n(LL k,LL n) {
    string s=int_st(k);
    s=s.substr(0,n);
    LL temp=st_int(s);
    return temp;
}
int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    while(t--) {
        LL n,k;
        scanf("%lld%lld",&n,&k);
        LL mx=first_n(k,n);
        map<int,bool> M;
        while(!M[k]) {
            M[k]=true;
            k=k*k;
            k=first_n(k,n);
            mx=max(mx,k);
        }
        printf("%lld\n",mx);
    }
    return 0;
}
