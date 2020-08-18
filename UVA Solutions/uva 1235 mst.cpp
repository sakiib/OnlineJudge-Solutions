#include<bits/stdc++.h>
using namespace std;

string str[1000];

struct data {
    int u,v,w;
    bool operator<(const data &q)const {
        return w<q.w;
    }
};

int parent[100005];
vector<data> V;

void makeset(int n) {
    for(int i=1;i<=n;i++) {
        parent[i]=i;
    }
}
int get_cost(string &a,string &b) {
    int ret=0;
    for(int i=0;i<a.size();i++) {
        int x=a[i]-'0'; int y=b[i]-'0';
        ret+=min(max(x,y)-min(x,y),10+min(x,y)-max(x,y));
    }
    return ret;
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
    int ret=0;
    for(int i=0;i<V.size();i++) {
        int u=V[i].u; int v=V[i].v; int w=V[i].w;
        if(Find(u)!=Find(v)) {
            Union(u,v);
            ret+=w;
        }
    }
    return ret;
}
int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++) {
        int n;
        scanf("%d",&n);
        str[0]="0000";
        map<string,int> M;
        int idx=0;
        for(int i=1;i<=n;i++) {
            cin>>str[i];
            if(M[str[i]]==0) M[str[i]]=++idx;
        }

        makeset(idx);

        int mn=100000;
        for(int i=1;i<=n;i++) {
            mn=min(mn,get_cost(str[0],str[i]));
        }
        for(int i=1;i<=n;i++) {
            for(int j=i+1;j<=n;j++) {
                int w=get_cost(str[i],str[j]);
                V.push_back({M[str[i]],M[str[j]],w});
            }
        }
        int ans=MST();
        printf("%d\n",(ans+mn));
        V.clear();
    }
    return 0;
}
