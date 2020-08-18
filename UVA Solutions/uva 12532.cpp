#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int ara[N];
int tree[4*N];

void build(int node,int b,int e) {
    if(b==e) {
        tree[node]=ara[b];
        return ;
    }
    int left=2*node; int right=2*node+1; int mid=(b+e)/2;
    build(left,b,mid); build(right,mid+1,e);
    tree[node]=tree[right]*tree[left];
}
void update(int node,int b,int e,int pos,int val) {
    if(pos>e||pos<b) return;
    if(b==e&&pos==b) {
        tree[node]=val;
        return;
    }
    int left=(2*node); int right=(2*node+1); int mid=(b+e)/2;
    update(left,b,mid,pos,val); update(right,mid+1,e,pos,val);
    tree[node]=tree[left]*tree[right];
}
int query(int node,int b,int e,int i,int j) {
    if(i>e||j<b) return 1;
    if(i<=b&&j>=e) return tree[node];
    int left=2*node; int right=2*node+1; int mid=(b+e)/2;
    int p1=query(left,b,mid,i,j); int p2=query(right,mid+1,e,i,j);
    return (p1*p2);
}
int main(int argc,char const *argv[]) {
    int n,q;
    while(scanf("%d%d",&n,&q)!=EOF) {
        for(int i=1;i<=n;i++) {
            int val;
            scanf("%d",&val);
            if(val>0) ara[i]=1;
            else if(val<0) ara[i]=-1;
            else ara[i]=0;
        }
        build(1,1,n);
        string ans="";
        for(int i=1;i<=q;i++) {
            string str; cin>>str;
            char ch=str[0]; int pos,val,l,r;
            switch(ch) {
                case 'C': scanf("%d%d",&pos,&val);
                if(val>0) val=1;
                else if(val<0) val=-1;
                else val=0;
                update(1,1,n,pos,val);
                break;
                case 'P': scanf("%d%d",&l,&r);
                int res=query(1,1,n,l,r);
                if(res==1) ans+='+';
                else if(res==-1) ans+='-';
                else ans+='0';
                break;
            }
        }
        cout<<ans<<endl;
        memset(tree,0,sizeof(tree));
    }
    return 0;
}
