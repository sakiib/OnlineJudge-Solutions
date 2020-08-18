#include<bits/stdc++.h>
using namespace std;
const int sz=100005+50005;
int ara[sz];
int tree[4*sz];
int tot;

void update(int node,int b,int e,int pos) {
    if(pos>e||pos<b) return;
    if(b==e&&b==pos) {
        tree[node]=1;
        return;
    }
    int left=2*node; int right=2*node+1; int mid=(b+e)/2;
    update(left,b,mid,pos);
    update(right,mid+1,e,pos);
    tree[node]=tree[left]+tree[right];
}
int query(int node,int b,int e,int pos) {
    //if(pos>e||pos<b) return -1;
    if(b==e) {
        tree[node]=0;
        return ara[b];
    }
    int left=2*node; int right=2*node+1; int mid=(b+e)/2;
    int p1=query(left,b,mid,pos);
    int p2=query(right,mid+1,e,pos);
    tree[node]=tree[left]+tree[right];
    //if(p1==-1) return p2;
    //if(p2==-1) return p1;
}
int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        int n,q;
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++) {
            scanf("%d",&ara[i]);
            update(1,1,sz,i);
        }
        tot=n;
        int pos;
        printf("Case %d:\n",tc);
        while(q--) {
            char str[3];
            scanf("%s",str);
            scanf("%d",&pos);
            printf("tree[1] %d\n",tree[1]);
            if(str[0]=='c') {
                if(tree[1]<pos) {
                    printf("none\n");
                    continue;
                }
                int ans=query(1,1,sz,pos);
                printf("%d\n",ans);
            }
            else if(str[0]=='a') {
                ara[++tot]=pos;
                update(1,1,sz,tot);
            }
        }
    }
    return 0;
}
