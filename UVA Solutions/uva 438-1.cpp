#include<bits/stdc++.h>
using namespace std;

const double PI=acos(-1.0);

int main(int argc,char const *argv[]) {
    double x1,x2,y1,y2,z1,z2;
    while(scanf("%lf%lf%lf%lf%lf%lf",&x1,&x2,&y1,&y2,&z1,&z2)!=EOF) {
    double xy=sqrt(pow(x1-y1,2.0)+pow(x2-y2,2.0));
    double yz=sqrt(pow(y1-z1,2.0)+pow(y2-z2,2.0));
    double zx=sqrt(pow(x1-z1,2.0)+pow(x2-z2,2.0));
    double s=(xy+yz+zx)/2.0;
    double A=sqrt(s*(s-xy)*(s-yz)*(s-zx));
    double D=(xy*yz*zx)/(2.0*A);
    double perimeter=PI*D;
    printf("%0.2f\n",perimeter);
    }
    return 0;
}
