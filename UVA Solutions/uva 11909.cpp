#include<bits/stdc++.h>
using namespace std;

const double PI=acos(-1.0);

int main(int argc,char const *argv[]) {
    double l,w,h,angle;
    while(scanf("%lf%lf%lf%lf",&l,&w,&h,&angle)!=EOF) {
        angle*=(PI/180.0);
        double tot=l*w*h;
        double len=l*tan(angle);
        //cout<<len<<endl;
        double emp=0.5*l*len;
        emp*=w;
        tot-=emp;
        printf("%0.3f mL\n",tot);
    }
    return 0;
}
