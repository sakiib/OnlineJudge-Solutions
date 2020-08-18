#include<bits/stdc++.h>
using namespace std;

double val[1000100];

void calc() {
    val[0]=0.0;
    for(int i=1;i<=1000000;i++) {
        val[i]+=(val[i-1]+(1.0/i));
    }
}
int main(int argc,char const *argv[]) {
    int t,tc;
    calc();
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {

        int n;
        scanf("%d",&n);
        double ans=0.0;
        if(n<=1000000) printf("Case %d: %.15f\n",tc,val[n]);
        else {
            ans=log(n+0.5)+0.57721566490;
            printf("Case %d: %.15f\n",tc,ans);
        }
    }
    return 0;
}
