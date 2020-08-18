#include<bits/stdc++.h>
using namespace std;

char str[100005];

struct segment {
    int prop;
    segment (){prop=0;}
    segment(int _prop) {
        prop=_prop;
    }
}tree[4*100005];

void build(int node,int b,int e) {
    if(b==e) {
        tree[node].prop=0;
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node].prop=0;
}
void Update(int node,int b,int e,int i,int j) {
    if(i>e||j<b) return;
    if(i<=b&&e<=j) {
        tree[node].prop++;
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    Update(left,b,mid,i,j);
    Update(right,mid+1,e,i,j);
}
int Query(int node,int b,int e,int pos) {
    if(pos>e||pos<b) return 0;
    if(b==e) {
        return tree[node].prop;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    int p1=Query(left,b,mid,pos);
    int p2=Query(right,mid+1,e,pos);
    return (p1+p2+tree[node].prop);
}
int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        scanf("%s",str);
        int n=strlen(str);
        build(1,1,n);
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",tc);
        while(q--) {
           char ch;
           scanf(" %c",&ch);
           if(ch=='I') {
            int l,r;
            scanf("%d%d",&l,&r);
            Update(1,1,n,l,r);
           }
           else if(ch=='Q') {
            int pos;
            scanf("%d",&pos);
            int ans=Query(1,1,n,pos);
            if(ans%2==0) printf("%c\n",str[pos-1]);
            else {
                if(str[pos-1]=='1') printf("0\n");
                else printf("1\n");
            }
           }
        }
    }
    return 0;
}
