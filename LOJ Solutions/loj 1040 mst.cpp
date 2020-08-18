#include<bits/stdc++.h>
using namespace std;

struct data {
    int u,v,w;
    bool operator<(const data &q)const {
        return w<q.w;
    }
};
int n;
vector<data> V;
int parent[100];

void makeset(int n) {
    for(int i=1;i<=n;i++) {
        parent[i]=i;
    }
}
int Find(int x) {
    if(parent[x]==x) return x;
    else return parent[x]=Find(parent[x]);
}
void Union(int a,int b) {
    int u=Find(a); int v=Find(b);
    if(u!=v) parent[u]=v;
}
int MST() {
    sort(V.begin(),V.end());
    int cnt=0;
    int val=0,tot=0;
    for(int i=0;i<V.size();i++) {
        //if(cnt==(n-1)) break;
        int u=V[i].u, v=V[i].v, w=V[i].w;
        if(Find(u)!=Find(v)) {
            Union(u,v);
            cnt++;
            val+=w;
        }
    }
    if(cnt!=(n-1)) return -1;
    else return val;
}
int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);

    for(tc=1;tc<=t;tc++) {
        scanf("%d",&n);
        makeset(n);
        int ara[55][55];

        int ans=0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                scanf("%d",&ara[i][j]);
            }
        }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(i==j) {
                    ans+=ara[i][j];
                    continue;
                }
                if(ara[i][j]!=0) {
                    V.push_back({i,j,ara[i][j]});
                    ans+=ara[i][j];
                }
            }
        }
        /*for(auto x: V) {
            printf("u=%d v=%d w=%d\n",x.u,x.v,x.w);
        }*/
       //printf("%d\n",ans);
       int res=MST();
       if(res==-1) printf("Case %d: -1\n",tc);
       else printf("Case %d: %d\n",tc,ans-res);
       V.clear();
    }
    return 0;
}
