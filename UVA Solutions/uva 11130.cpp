#include<bits/stdc++.h>
using namespace std;

const double PI=acos(-1.0);

int main(int ragc,char const *argv[]) {
    double a,b,v,A,s;
    while(cin>>a>>b>>v>>A>>s) {
        if(a==0.0&&b==0.0&&v==0.0&&A==0.0&&s==0.0) break;
        double ang=A/180.0*PI;
        double tot=s*v*0.5;
        double hor=tot*cos(ang);
        double vert=tot*sin(ang);
        double x=hor/a;
        double y=vert/b;
        printf("%0.0f %0.0f\n",x,y);
    }
    return 0;
}
