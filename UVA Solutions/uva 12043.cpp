#include<bits/stdc++.h>
using namespace std;

typedef long long int LL;

LL nod[100010];
LL sod[100010];

void calc() {
     for(int i=1;i<=100000;i++) {
        for(int j=i;j<=100000;j+=i) {
            nod[j]++;
            sod[j]+=i;
        }
    }
}
int main(int argc,char const *argv[]) {
    calc();
    int t;
    scanf("%d",&t);
    while(t--) {
        int a,b,k;
        scanf("%d%d%d",&a,&b,&k);
        LL x=0,y=0;
        for(int i=a;i<=b;i++) {
            if(i%k==0) {
                x+=nod[i];
                y+=sod[i];
            }
        }
        printf("%lld %lld\n",x,y);
    }
    return 0;
}
