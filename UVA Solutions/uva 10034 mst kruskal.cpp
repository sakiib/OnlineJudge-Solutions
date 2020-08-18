#include<bits/stdc++.h>
using namespace std;

int parent[105];

struct data {
    int u,v;
    double w;
    bool operator<(const data &q)const {
        return (w<q.w);
    }
};
vector<data> V;

void makeset(int n) {
    for(int i=1;i<=n;i++) parent[i]=i;
}
double dist(double x1,double y1,double x2,double y2) {
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int Find(int x) {
    return parent[x]==x ? x : parent[x]=Find(parent[x]);
}
void Union(int a,int b) {
    int u=Find(a);
    int v=Find(b);
    if(u!=v) parent[u]=v;
}
double MST() {
    sort(V.begin(),V.end());
    /*for(int i=0;i<V.size();i++) {
        cout<<V[i].u<<" "<<V[i].v<<" "<<V[i].w<<endl;
    }*/
    double ret=0;
    for(int i=0;i<V.size();i++) {
        int u=V[i].u;
        int v=V[i].v;
        double w=V[i].w;
        if(Find(u)!=Find(v)) {
            ret+=w;
            Union(u,v);
        }
    }
    return ret;
}
int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    bool f=false;
    for(int tc=1;tc<=t;tc++) {
        if(f) printf("\n");
        f=true;
        int n;
        scanf("%d",&n);
        double a[105],b[105];
        for(int i=1;i<=n;i++) {
            cin>>a[i]>>b[i];
        }
        makeset(n);
        for(int i=1;i<=n;i++) {
            for(int j=i+1;j<=n;j++) {
                V.push_back({i,j,dist(a[i],b[i],a[j],b[j])});
            }
        }
        /*for(int i=0;i<V.size();i++) {
            cout<<V[i].u<<" "<<V[i].v<<" "<<V[i].w<<endl;
        }*/
        cout<<setprecision(2)<<fixed<<MST()<<endl;
        V.clear();
    }
    return 0;
}
