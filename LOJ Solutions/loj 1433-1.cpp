#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        double ox,oy,ax,ay,bx,by;
        scanf("%lf%lf%lf%lf%lf%lf",&ox,&oy,&ax,&ay,&bx,&by);
        double rad=sqrt((ox-ax)*(ox-ax)+(oy-ay)*(oy-ay));
        double m1=(ay-oy)/(ax-ox);
        double m2=(by-oy)/(bx-ox);
        double val=(m1-m2)/(1.0+m1*m2);
        cout<<val<<endl;
        double angle=atan(val);
        cout<<angle<<endl;
    }
    return 0;
}
