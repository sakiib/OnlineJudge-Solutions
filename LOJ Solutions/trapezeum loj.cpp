#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        double a,b,c,d;
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        if(a>c) swap(a,c);
        if(b<d) swap(b,d);
        //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
        double x=(b*b+c*c+a*a-d*d-2.0*c*a)/(2.0*(c-a));
        double h=sqrt(b*b-x*x);
        //cout<<left<<" "<<k<<" "<<x<<" "<<h<<endl;
        double ans=0.5*(a+c)*h;
        printf("Case %d: %f\n",tc,ans);
    }
    return 0;
}
