#include<bits/stdc++.h>
using namespace std;

const int N=100005;

struct segment {
    int zero,one,two,lazy;
    segment () {};
    segment (int _zero,int _one,int _two) {
        zero=_zero, one=_one, two=_two;
        lazy=0;
    }
    void _rotate() {
        swap(one,zero);
        swap(two,zero);
    }
}tree[4*N];

void build(int node,int b,int e) {
    if(b==e) {
        tree[node].zero=1;
        tree[node].one=0;
        tree[node].two=0;
        tree[node].lazy=0;
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node].zero=tree[left].zero+tree[right].zero;
    tree[node].one=0;
    tree[node].two=0;
    tree[node].lazy=0;
}
void Update(int node,int b,int e,int i,int j) {
    if(i>e||j<b) return;
    if(i<=b&j>=e) {
        tree[node].lazy++;
        tree[node]._rotate();
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    Update(left,b,mid,i,j);
    Update(right,mid+1,e,i,j);
    tree[node].zero=tree[left].zero+tree[right].zero;
    tree[node].one=tree[left].one+tree[right].one;
    tree[node].two=tree[left].two+tree[right].two;
    if(tree[node].lazy%3==1) {
       tree[node]._rotate();
    }
    if(tree[node].lazy%3==2) {
        tree[node]._rotate();
        tree[node]._rotate();
    }
}
int Query(int node,int b,int e,int i,int j,int carry=0) {
    if(i>e||j<b) return 0;
    if(i<=b&&e<=j) {
        if(carry%3==1) {
            carry%=3;
            tree[node]._rotate();
        }
        if(carry%3==2) {
            carry%=3;
            tree[node]._rotate();
            tree[node]._rotate();
        }
        return tree[node].zero;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    carry+=tree[node].lazy;
    int p1=Query(left,b,mid,i,j,carry);
    int p2=Query(right,mid+1,e,i,j,carry);
    return (p1+p2);
}
int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        int n,q;
        scanf("%d%d",&n,&q);
        build(1,1,n);
        printf("Case %d:\n",tc);
        while(q--) {
            int op;
            scanf("%d",&op);
            if(op==0) {
                int l,r;
                scanf("%d%d",&l,&r);
                l++,r++;
                Update(1,1,n,l,r);
                for(int i=1;i<=19;i++) {
                    cout<<"Update-> "<<"Node : "<<i<<" one : "<<tree[i].one<<" two : "<<
                    tree[i].two<<" zero : "<<tree[i].zero<<" Lazy : "<<tree[i].lazy<<endl;
                }
            }
            else if(op==1) {
                int l,r;
                scanf("%d%d",&l,&r);
                l++,r++;
                int ans=Query(1,1,n,l,r,0);
                for(int i=1;i<=19;i++) {
                    cout<<"Update-> "<<"Node : "<<i<<" one : "<<tree[i].one<<" two : "<<
                    tree[i].two<<" zero : "<<tree[i].zero<<" Lazy : "<<tree[i].lazy<<endl;
                }
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
