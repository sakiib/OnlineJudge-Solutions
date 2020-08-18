#include<bits/stdc++.h>
using namespace std;

const double PI=acos(-1.0);

int main(int argc,char const *argv[]) {
    double a,s;
    string str;
    while(cin>>s>>a>>str) {
        if(str=="min") {
            a/=60.0;
        }
        if(a>180.0) a=360.0-a;
        s+=6440.0;
        a*=PI/180.0;
        double ans1=s*a;
        double ans2=s*s+s*s-(cos(a)*2.0*s*s);
        ans2=sqrt(ans2);
        printf("%0.6f %0.6f\n",ans1,ans2);
    }
    return 0;
}
