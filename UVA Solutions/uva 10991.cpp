#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    while(t--) {
        double r1,r2,r3;
        scanf("%lf%lf%lf",&r1,&r2,&r3);
        double a=r1+r2;
        double b=r2+r3;
        double c=r1+r3;
        double s=(a+b+c)/2.0;
        double tri=sqrt(s*(s-a)*(s-b)*(s-c));
        double C=acos((a*a+b*b-c*c)/(2.0*a*b));
        double A=acos((b*b+c*c-a*a)/(2.0*b*c));
        double B=acos((c*c+a*a-b*b)/(2.0*a*c));
        double ans=tri-(r1*r1*B+r2*r2*C+r3*r3*A)/2.0;
        printf("%0.6lf\n",ans);
    }
    return 0;
}
