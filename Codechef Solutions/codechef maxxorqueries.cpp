#include <bits/stdc++.h>
using namespace std;

const int mx=3e5+5;
vector <array<int,2>> tree[mx*4];
int ara[mx];
void build (int pos,int L,int R)
{
    array<int,2> A;
    A[0]=A[1]=-1;
    tree[pos].push_back(A);
    int nnode=0;
    for (int j=L;j<=R;j++) {
        int now=0,i=20,x=ara[j];
        int bit[21];
        while (i>=0) {
            bit[i]=x%2;
            x/=2;
            i--;
        }
        for (i=0;i<21;i++) {
            if (tree[pos][now][bit[i]]==-1) {
                tree[pos][now][bit[i]]=++nnode;
                tree[pos].push_back(A);
                ///cout<<nnode<<' '<<tree[pos].size()<<endl;
            }
            now=tree[pos][now][bit[i]];
        }
    }
    if (L==R) return;
    int x=pos*2,mid=(L+R)/2;
    build(x,L,mid);
    build(x+1,mid+1,R);
}
int xormax (int pos,int x)
{///cout<<pos<<endl;
    int bit[21];
    int i=20;
    while (i>=0) {
        bit[i]=x%2;
        x/=2;
        i--;
    }
    int now=0,ans=0;
    for (i=0;i<21;i++) {///cout<<"-------"<<bit[i]<<endl;
        ans=(ans<<1);
        if (tree[pos][now][bit[i]^1]!=-1) {
            ans+=1;
            now=tree[pos][now][bit[i]^1];
        }
        else now=tree[pos][now][bit[i]];
    }
    return ans;
}
int query (int pos,int L,int R,int l,int r,int k)
{
    if (L>r || l>R) return 0;
    if (L>=l && R<=r) return xormax(pos,k);
    int x=pos*2,mid=(L+R)/2,y=0,z=0;
    if (l<=mid) y=query(x,L,mid,l,r,k);
    if (r>mid) z=query(x+1,mid+1,R,l,r,k);
    return max(y,z);
}
int main ()
{
    int n;
    scanf ("%d",&n);
    for (int i=1;i<=n;i++) scanf ("%d",&ara[i]);
    build(1,1,n);
    int l,r,x,q;
    scanf ("%d",&q);
    while (q--) {
        scanf ("%d %d %d",&l,&r,&x);
        int ans=query(1,1,n,l,r,x);
        printf ("%d\n",ans);
    }
    return 0;
}
