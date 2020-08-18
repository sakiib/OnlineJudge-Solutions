#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    double a,b,c;
    while(scanf("%lf%lf%lf",&a,&b,&c)!=EOF) {
        if(a==0.0&&b==0.0&&c==0.0) {
        printf("The radius of the round table is: 0.000\n");
        continue;
        }
        double s=(a+b+c)/2.0;
        double A=sqrt(s*(s-a)*(s-b)*(s-c))*2.0/(a+b+c);
        printf("The radius of the round table is: %0.3f\n",A);
    }
    return 0;
}
