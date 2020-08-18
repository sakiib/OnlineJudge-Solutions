#include<bits/stdc++.h>
using namespace std;

struct data {
    int u,v;
    double w;
    bool operator<(const data &q)const {
        return w<q.w;
    }
};

int n;
double r;
int parent[100005];
int a[100005],b[100005];

vector<data> V;

void makeset(int n) {
    for(int i=1;i<=n;i++) {
        parent[i]=i;
    }
}
double dist(int i,int j) {
    int x1=a[i],y1=b[i],x2=a[j],y2=b[j];
    double ret=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    return ret;
}
int Find(int x) {
    if(parent[x]==x) return x;
    else return parent[x]=Find(parent[x]);
}
void Union(int a,int b) {
    int u=Find(a);
    int v=Find(b);
    if(u!=v) parent[u]=v;
}
void MST() {
    sort(V.begin(),V.end());

    int state=0;
    double x=0.0,y=0.0;

    for(int i=0;i<V.size();i++) {
        int u=V[i].u; int v=V[i].v; double w=V[i].w;
        if(Find(u)!=Find(v)) {
        Union(u,v);
        if(w<=r) {
            state++;
            x+=w;//roads
        }
        else y+=w;//railroads
      }
    }
    cout<<setprecision(0)<<fixed<<n-state<<" "<<x<<" "<<y<<endl;
}
int main(int argc,char const *argv[]) {
    int t,tc=1;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        scanf("%d%lf",&n,&r);
        makeset(n);
        for(int i=1;i<=n;i++) {
            scanf("%d%d",&a[i],&b[i]);
        }
        for(int i=1;i<=n;i++) {
            for(int j=i+1;j<=n;j++) {
               V.push_back({i,j,dist(i,j)});
            }
        }
        printf("Case #%d: ",tc);
        MST();
        V.clear();
    }
    return 0;
}
