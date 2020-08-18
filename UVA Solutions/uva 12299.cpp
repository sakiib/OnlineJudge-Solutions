#include<bits/stdc++.h>
using namespace std;
int ara[100005];
int tree[4*100005],V[100],sz;
char str[100];

void conv() {
    sz=0;
    int len=strlen(str);
    for(int i=0;i<len;i++) {
        int s=0;
        while(isdigit(str[i])&&i<len) {
            s=s*10+str[i]-'0';
            i++;
        }
        if(s) V[sz++]=s;
    }
}
void build(int node,int b,int e) {
    if(b==e) {
        tree[node]=ara[b];
        return;
    }
    int left=2*node; int right=2*node+1; int mid=(b+e)/2;
    build(left,b,mid); build(right,mid+1,e);
    tree[node]=min(tree[left],tree[right]);
}
void update(int node,int b,int e,int pos,int val) {
    if(pos>e||pos<b) return;
    if(b==e&&b==pos) tree[node]=val;
    int left=2*node; int right=2*node+1; int mid=(b+e)/2;
    update(left,b,mid,pos,val); update(right,mid+1,e,pos,val);
    tree[node]=min(tree[left],tree[right]);
}
int query(int node,int b,int e,int i,int j) {
    if(i>e||j<b) return 1000000000;
    if(i<=b&&j>=e) return tree[node];
    int left=2*node; int right=2*node+1; int mid=(b+e)/2;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return min(p1,p2);
}
int main(int argc,char const *argv[]) {
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) {
        scanf("%d",&ara[i]);
    }
    build(1,1,n);
    for(int i=1;i<=q;i++) {
        scanf("%s",str);
        if(str[0]=='q') {
            int ans=query(1,1,n,V[0],V[1]);
            printf("%d\n",ans);
        }
        else {
            int t=ara[V[0]];
            for(int i=0;i<sz;i++) {
                int x=V[i];
                int y=V[(i+1)%sz];
                ara[x]=ara[y];
            }
            ara[V[sz-1]]=t;
            for(int i=0;i<sz;i++) {
                update(1,1,n,V[i],ara[V[i]]);
            }
        }
    }
    return 0;
}
