#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    double a,b,c;
    while(scanf("%lf%lf%lf",&a,&b,&c)!=EOF) {
        double s=(a+b+c)/2.0;
        if(s-a<=0.0||s-b<=0.0||s-c<=0.0) {
            cout<<"-1.000"<<endl;
            continue;
        }
        else printf("%0.3lf\n",4/3.0*sqrt(s*(s-a)*(s-b)*(s-c)));
    }
    return 0;
}
