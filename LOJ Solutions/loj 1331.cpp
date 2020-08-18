#include<bits/stdc++.h>
using namespace std;
const double PI=2*acos(-1.0);
int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        double r_1,r_2,r_3;
        scanf("%lf%lf%lf",&r_1,&r_2,&r_3);
        //printf("%lf %lf %lf\n",r_1,r_2,r_3);
        double x=r_1+r_2;
        double y=r_2+r_3;
        double z=r_1+r_3;
        double s=(x+y+z)/2;
        //printf("%lf\n",s);
        double total=sqrt(s*(s-x)*(s-y)*(s-z));
        //printf("%lf\n",total);
        double C=acos((x*x+y*y-z*z)/(2*x*y));
        double B=acos((x*x+z*z-y*y)/(2*x*z));
        double A=acos((y*y+z*z-x*x)/(2*y*z));
        //printf("%f\n",A+B+C);
        double a1=(r_2*r_2*C)/2;
        double a2=(r_3*r_3*A)/2;
        double a3=(r_1*r_1*B)/2;
        double ans=total-a1-a2-a3;
        printf("Case %d: %0.8lf\n",tc,ans);
    }
    return 0;
}
