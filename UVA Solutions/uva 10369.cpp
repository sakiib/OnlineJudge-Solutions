#include<bits/stdc++.h>
using namespace std;

struct data {
    int u,v;
    double w;

    bool operator<(const data &q)const {
        return (w<q.w);
    }
};
int n,s,k;
vector<data> V;
int parent[505];

double dist(double x1,double y1,double x2,double y2) {
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
void makeset(int n) {
    for(int i=1;i<=n;i++) parent[i]=i;
}
int Find(int x) {
    return parent[x]==x ? x : parent[x]=Find(parent[x]);
}
void Union(int a,int b) {
    int u=Find(a); int v=Find(b);
    if(u!=v) parent[u]=v;
}
void MST() {
    sort(V.begin(),V.end());
    double mx=0.0;
    int done=0;
    for(int i=0;i<k&&done<(s-n);i++) {
        int u=V[i].u; int v=V[i].v; double w=V[i].w;
        if(Find(u)!=Find(v)) {
            mx=max(mx,w);
            Union(u,v);
            done++;
        }
    }
    cout<<setprecision(2)<<fixed<<mx<<endl;
}
int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++) {
        k=0;
        int a[505],b[505];
        scanf("%d%d",&n,&s);
        for(int i=1;i<=s;i++) {
            scanf("%d%d",&a[i],&b[i]);
        }
       makeset(s);
       for(int i=1;i<=s;i++) {
        for(int j=i+1;j<=s;j++) {
         k++;
         V.push_back({i,j,dist(a[i],b[i],a[j],b[j])});
        }
       }
       MST();
       V.clear();
    }
    return 0;
}
