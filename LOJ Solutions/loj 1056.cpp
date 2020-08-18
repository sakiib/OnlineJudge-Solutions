#include<bits/stdc++.h>
using namespace std;

const double PI=acos(-1.0);

int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++) {
        int l,w;
        scanf("%d : %d",&l,&w);

        double len=l*1000.0;
        double lo=0.0000001,hi=len;
        double mid,wid;
        while(hi-lo>=0.0000001) {
        mid=(lo+hi)/2.0;
        wid=mid*(w*1.0/l);
        //cout<<setprecision(5)<<fixed<<mid<<" "<<wid<<endl;

        double dia=sqrt(mid*mid+wid*wid);
        dia*=0.5;

        double angle=acos((dia*dia+dia*dia-wid*wid)/(2.0*dia*dia));
        //cout<<"angle : "<<angle<<endl;
        double an=(angle*PI)/180.0;

        double s=dia*an;

        double res=2.0*s+2.0*mid;
        //cout<<"res : "<<res<<" "<<s<<endl;
        if(res-400.0>0.000001) hi=mid;
        else lo=mid;
        }
        printf("Case %d: %0.12lf %0.12lf\n",tc,lo,wid);
    }
    return 0;
}
