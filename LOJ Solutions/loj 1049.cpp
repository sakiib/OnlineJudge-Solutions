#include<bits/stdc++.h>
using namespace std;

bool Left[1000];
bool Right[1000];

int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        int n;
        scanf("%d",&n);
        int left_cost=0,right_cost=0;
        memset(Left,false,sizeof(Left));
        memset(Right,false,sizeof(Right));
        for(int i=1;i<=n;i++) {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            if(!Left[a]&&!Right[b]) {
                Left[a]=true; Right[b]=true;
                left_cost+=c;
            }
            else {
                Right[a]=true; Left[b]=true;
                right_cost+=c;
            }
        }
        printf("Case %d: %d\n",tc,min(left_cost,right_cost));
    }
    return 0;
}
