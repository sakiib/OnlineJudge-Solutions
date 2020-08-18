#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    while(t--) {
        LL la=0,lb=1,ma=1,mb=1,ra=1,rb=0;
        LL x=1,y=1;
        string str;
        cin>>str;
        for(int i=0;i<str.size();i++) {
            if(str[i]=='L') {
                x=la+ma; y=lb+mb;
                ra=ma; rb=mb;
                ma=x; mb=y;
            }
            else if(str[i]=='R') {
                x=ra+ma; y=rb+mb;
                la=ma; lb=mb;
                ma=x; mb=y;
            }
        }
        printf("%lld/%lld\n",x,y);
    }
    return 0;
}
