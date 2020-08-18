#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        int a,b,c,d;
        scanf("%d:%d %d:%d",&a,&b,&c,&d);
        int X1=a*60+b; int Y1=c*60+d;
        int p,q,r,s;
        scanf("%d:%d %d:%d",&p,&q,&r,&s);
        int X2=p*60+q; int Y2=r*60+s;
        if(X1>Y2||X2>Y1) printf("Case %d: Hits Meeting\n",tc);
        else printf("Case %d: Mrs Meeting\n",tc);
    }
    return 0;
}
