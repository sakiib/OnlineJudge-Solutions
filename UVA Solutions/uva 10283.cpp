#include<bits/stdc++.h>
using namespace std;

const double PI=acos(-1.0);

int main(int argc,char const *argv[]) {
    double R,n;
    while(scanf("%lf%lf",&R,&n)!=EOF) {
        if(n==1.0) {
            printf("%.10f %.10f %.10f\n",R,0.0,0.0);
        }
        else {
            double theta=180.0/n;
            cerr<<theta<<endl;
            double r=R*(sin(theta*PI/180))/(1+sin(theta*PI/180.0));
            double xR=R-r;
            double tr_area=xR*cos(theta*PI/180.0)*r;
            double s_area=(90-theta)/180.0*PI*r*r;
            double blue=n*(tr_area-s_area);
            double green=PI*R*R-n*PI*r*r-blue;
            printf("%.10f %.10f %.10f\n",r,blue,green);
        }
    }
    return 0;
}
