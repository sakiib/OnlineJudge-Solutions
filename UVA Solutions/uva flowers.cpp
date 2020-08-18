#include<bits/stdc++.h>
using namespace std;

const double PI=acos(-1.0);
int main(int argc,char const *argv[]) {
    double a,b,c;
    while(scanf("%lf%lf%lf",&a,&b,&c)!=EOF) {
        double s=(a+b+c)/2.0;
        double tria=sqrt(s*(s-a)*(s-b)*(s-c));
        //printf("%0.4f\n",tria);
        double radi=tria*2.0/(a+b+c);
        double red=PI*radi*radi;
        //printf("%0.4f\n",red);
        double purple=tria-red;
        //printf("%0.4f\n",purple);
        double Rad=(a*b*c/(4.0*tria));
        double yellow=PI*Rad*Rad;
        yellow-=tria;
        printf("%0.4f %0.4f %0.4f\n",yellow,purple,red);
    }
    return 0;
}
