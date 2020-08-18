#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    int ara[55];
    for(tc=1;tc<=t;tc++) {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%d",&ara[i]);
        }
        int hi=0,lo=0;
        for(int i=1;i<n;i++) {
            if(ara[i]==ara[i-1]) continue;
            if(ara[i]>ara[i-1]) hi++;
            else lo++;
        }
        printf("Case %d: %d %d\n",tc,hi,lo);
    }
    return 0;
}
