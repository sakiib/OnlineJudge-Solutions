#include<bits/stdc++.h>
using namespace std;

const double PI=acos(-1.0);
const double eps=1e-3;

double SQ(double a) {
    return (a*a);
}
int main(int argc,char const *argv[]) {
    int t,tc;
    cin>>t;
    double ox,oy,ax,ay,bx,by;
    for(tc=1;tc<=t;tc++) {
        cin>>ox>>oy>>ax>>ay>>bx>>by;
        double oa=sqrt(SQ(ax-ox)+SQ(ay-oy));
        double ob=sqrt(SQ(bx-ox)+SQ(by-oy));
        double ab=sqrt(SQ(ax-bx)+SQ(ay-by));
        double angle=acos((oa*oa+ob*ob-ab*ab)/(2.0*oa*ob));
        double ans=oa*angle;
        printf("Case %d: %0.8f\n",tc,ans);
    }
    return 0;
}

