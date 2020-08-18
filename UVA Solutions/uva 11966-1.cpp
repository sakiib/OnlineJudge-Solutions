#include<bits/stdc++.h>
using namespace std;

struct data {
    int idx;
    double x,y;
    data(){}
    data(int idx,double x,double y) {
        this->idx=idx;
        this->x=x;
        this->y=y;
    }
} ara[100005];

int a[100005];

bool sameset(double x1,double y1,double x2,double y2,double temp) {
    double dis=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    if(dis<=temp) return true;
    else return false;
}
void makeset(int n) {
    for(int i=1;i<=n;i++) a[i]=i;
}
int Find(int x) {
    if(a[x]==x) return x;
    return a[x]=Find(a[x]);
}
void Union(int x,int y) {
    int u=Find(x);
    int v=Find(y);
    if(u!=v) a[u]=v;
}
int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        int n;
        scanf("%d",&n);
        makeset(n);
        double dist;
        scanf("%lf",&dist);
        for(int i=1;i<=n;i++) {
           scanf("%lf%lf",&ara[i].x,&ara[i].y);
           ara[i].idx=i;
        }
        int ans=n;
        for(int i=1;i<=n;i++) {
            for(int j=i+1;j<=n;j++) {
                if(sameset(ara[i].x,ara[i].y,ara[j].x,ara[j].y,dist)) {
                if(Find(i)==Find(j)) continue;
                Union(i,j);
                ans--;
                }
            }
        }
        printf("Case %d: %d\n",tc,ans);
    }
    return 0;
}

